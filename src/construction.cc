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
