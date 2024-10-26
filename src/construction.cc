#include "construction.hh"

MyDetectorConstruction::MyDetectorConstruction()
{}

MyDetectorConstruction::~MyDetectorConstruction()
{}

G4VPhysicalVolume *MyDetectorConstruction::Construct()
{
	// CREATE THE WORLD
	G4NistManager *nist = G4NistManager::Instance();

	// World material: air
	G4Material* worldMaterial = nist->FindOrBuildMaterial("G4_AIR");

	G4MaterialPropertiesTable* MPT_air = new G4MaterialPropertiesTable();
	MPT_air->AddConstProperty("RINDEX", 1., true);
	worldMaterial->SetMaterialPropertiesTable(MPT_air);

  	G4Box *solidworld = new G4Box("solidworld", 2*m, 2*m, 2*m);
	G4LogicalVolume *logicworld = new G4LogicalVolume(solidworld, worldMaterial, "logicWorld");
	G4VPhysicalVolume *physworld  = new G4PVPlacement(0, G4ThreeVector(0., 0., 0.), logicworld, "physworld", 0, false, 0., true);

	// CREATE THE SCINTILLATORS
	// Define the geometry
	LayerThickness = 19.9*mm;
	LogWidth = 26.7*mm;
	LogLength = 326*mm;
	NbOfLayers = 8;       
	NbOfColumns = 12;    
	LayerGap = 1.45*mm;
	ColumnGap = 1.14*mm;

	// Define the material of the Scintillation bars
	G4Element* elI = new G4Element("Iodine", "I",  53., 126.9*g/mole);
	G4Element* elCs= new G4Element("Cesium", "Cs", 55., 132.9*g/mole);

	G4Material *CsIMaterial = new G4Material("CsI", 4.51*g/cm3, 2);
	CsIMaterial->AddElement(elI, .5);
	CsIMaterial->AddElement(elCs,.5);

	// Add the physical propierties of the scintillating material
	std::vector<G4double> energy     = {2.034*eV, 3.*eV, 4.136*eV};
	std::vector<G4double> rindex     = {1.58, 1.58, 1.58};
	std::vector<G4double> absorption = {400.*cm, 400.*cm, 400.0*cm};
	
	G4MaterialPropertiesTable* MPT = new G4MaterialPropertiesTable();
	
	// property independent of energy
	MPT->AddConstProperty("SCINTILLATIONYIELD", 9200./MeV);
	
	// properties that depend on energy
	MPT->AddProperty("RINDEX", energy, rindex);
	MPT->AddProperty("ABSLENGTH", energy, absorption);
	
	
	const G4int NUMENTRIES = 13;
	G4double Scnt_PP[NUMENTRIES] = { 2.39*eV, 2.43*eV, 2.48*eV, 2.53*eV, 2.58*eV, 2.64*eV, 2.70*eV, 2.76*eV, 2.82*eV, 2.89*eV, 2.95*eV, 3.03*eV, 3.10*eV};
	G4double Scnt_FAST[NUMENTRIES] = {0.02, 0.05, 0.10, 0.20, 0.35, 0.50, 0.65, 0.85, 1.00, 0.85, 0.65, 0.35, 0.10};
	MPT->AddProperty("SCINTILLATIONCOMPONENT1", Scnt_PP, Scnt_FAST, NUMENTRIES); // We only consider the fast component
	MPT->AddConstProperty("RESOLUTIONSCALE", 2.0);
	MPT->AddConstProperty("SCINTILLATIONTIMECONSTANT1", 3.3*ns); 
	CsIMaterial->SetMaterialPropertiesTable(MPT);

	// Define the solid and logical volume
	G4Box *solidLog = new G4Box("solidLog", LogWidth/2., LogLength/2., LayerThickness/2.);  
	G4LogicalVolume *logicLog = new G4LogicalVolume(solidLog, CsIMaterial, "logicLog");

	G4RotationMatrix* rotateMatrix = new G4RotationMatrix();
	rotateMatrix -> rotateZ(90.0*deg);

	// Create the physical volumes to construct the geometry
	double Xpos=0., Ypos=0., Zpos=0.;  

	for(int i=0;i<NbOfLayers;i+=2)
     {													 
     for(int j=0;j<NbOfColumns;++j)																		 
       {
	Xpos = -((NbOfColumns-1)/2)*(LogWidth+ColumnGap) + j*(LogWidth+ColumnGap);
	Ypos = 0.;
	Zpos = -((NbOfLayers-1)/2)*(LayerThickness+LayerGap) + i*(LayerThickness+LayerGap);
    G4VPhysicalVolume *physiLog = new G4PVPlacement(0, G4ThreeVector(Xpos, Ypos, Zpos),
    				     logicLog, "Layer", logicworld, false, 100*i+j);
     
	Xpos = 0.;
	Ypos = -((NbOfColumns-1)/2)*(LogWidth+ColumnGap) + j*(LogWidth+ColumnGap);
	Zpos = -((NbOfLayers-1)/2)*(LayerThickness+LayerGap) + (i+1)*(LayerThickness+LayerGap);
    physiLog = new G4PVPlacement(rotateMatrix, G4ThreeVector(Xpos, Ypos, Zpos),
    				     logicLog, "Layer", logicworld, false, 100*(i+1)+j);
	}
      }      

  	return physworld;
}

void MyDetectorConstruction::ConstructSDandField()
{

}
