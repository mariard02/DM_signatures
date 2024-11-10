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
	std::vector<G4double> energyAir     = {2.034*eV, 3.*eV, 4.136*eV};
	std::vector<G4double> rindexAir     = {1., 1., 1.};
	MPT_air ->AddProperty("RINDEX", energyAir, rindexAir);
	worldMaterial->SetMaterialPropertiesTable(MPT_air);

  G4Box *solidworld = new G4Box("solidworld", 2.*m, 2.*m, 2.*m);
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
	CsIMaterial->AddElement(elCs, .5);

	// Añadir propiedades ópticas y de centelleo de CsI(Tl)
	std::vector<G4double> energy = {1.77142857, 1.82352941, 1.87878788, 1.9375, 2.0, 2.06666667, 2.13793103, 2.21428571, 2.2962963, 2.38461538, 2.48, 2.58333333, 2.69565217, 2.81818182, 2.95238095, 3.1}; 
	std::vector<G4double> rindex = {1.78, 1.78, 1.78, 1.78, 1.78, 1.78, 1.78, 1.78, 1.78, 1.78, 1.78, 1.78, 1.78, 1.78, 1.78, 1.78};
	std::vector<G4double> absorption = {100*cm, 100*cm, 100*cm, 100*cm, 100*cm, 100*cm, 100*cm, 100*cm, 100*cm, 100*cm, 100*cm, 100*cm, 100*cm, 100*cm, 100*cm, 100*cm};
	std::vector<G4double> Scnt_FAST = {0.03, 0.05, 0.1, 0.15, 0.2, 0.25, 0.3, 0.4, 0.5, 0.7, 0.9, 1.0, 0.7, 0.45, 0.2, 0.05};

	G4MaterialPropertiesTable* MPT = new G4MaterialPropertiesTable();
	MPT->AddConstProperty("SCINTILLATIONYIELD", 54000./MeV); // Rendimiento de CsI(Tl)
	MPT->AddProperty("RINDEX", energy, rindex);
	MPT->AddProperty("ABSLENGTH", energy, absorption);
	MPT->AddProperty("SCINTILLATIONCOMPONENT1", energy, Scnt_FAST);
	MPT->AddConstProperty("RESOLUTIONSCALE", 1.5);
	MPT->AddConstProperty("SCINTILLATIONTIMECONSTANT1", 1000.*ns); // Decaimiento de CsI(Tl)

	CsIMaterial->SetMaterialPropertiesTable(MPT);

	// Define the solid and logical volume
	G4Box *solidLog = new G4Box("solidLog", LogWidth/2., LogLength/2., LayerThickness/2.);  
	logicLog = new G4LogicalVolume(solidLog, CsIMaterial, "logicLog");

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
    				     logicLog, "Layer", logicworld, false, 10*i+j, true);
     
		Xpos = 0.;
		Ypos = -((NbOfColumns-1)/2)*(LogWidth+ColumnGap) + j*(LogWidth+ColumnGap);
		Zpos = -((NbOfLayers-1)/2)*(LayerThickness+LayerGap) + (i+1)*(LayerThickness+LayerGap);

    physiLog = new G4PVPlacement(rotateMatrix, G4ThreeVector(Xpos, Ypos, Zpos),
    				     logicLog, "Layer", logicworld, false, 1000*(i)+100*j, true);

  	G4OpticalSurface* opAirScintillator = new G4OpticalSurface("AirScintillator");
		opAirScintillator -> SetType(dielectric_metal);
		opAirScintillator -> SetFinish(polished);
		opAirScintillator -> SetModel(glisur);
		opAirScintillator -> SetPolish(1.);

		G4MaterialPropertiesTable* OpSurfaceProperty = new G4MaterialPropertiesTable();

		std::vector<G4double> pp = {2.038*eV, 8.*MeV};
		std::vector<G4double> reflectivity = {1., 1.};
		std::vector<G4double> transmittance = {0., 0.};
		//std::vector<G4double> efficiency = {0.1, 0.1};

		OpSurfaceProperty -> AddProperty("REFLECTIVITY", pp, reflectivity);
		OpSurfaceProperty->AddProperty("TRANSMITTANCE", pp, transmittance);
		//OpSurfaceProperty -> AddProperty("EFFICIENCY", pp, efficiency);

		opAirScintillator -> SetMaterialPropertiesTable(OpSurfaceProperty);

		G4LogicalSkinSurface* airScintillator =
			new G4LogicalSkinSurface("AirScintillator", logicLog, opAirScintillator);

		//G4LogicalBorderSurface* AirScintillator = new G4LogicalBorderSurface("AirScintillator", physiLog, physworld, opAirScintillator);

		}
  }      

	// CREATE THE TRACKER
	G4Material *Si = new G4Material("Silicon", 14., 28.0855*g/mole, 2.33*g/cm3);  // Silicon: z=14, a=28.0855 g/mole, density=2.33 g/cm3
	//G4Material *W = new G4Material("Tungsten", 74., 183.84*g/mole, 19.3*g/cm3);   // Tungsten: z=74, a=183.84 g/mole, density=19.3 g/cm3
	G4Material *W = nist->FindOrBuildMaterial("G4_W");
	G4Material* Vacuum = new G4Material("Galactic", 1., 1.008*g/mole, CLHEP::universe_mean_density,
                                    kStateGas, 2.73*kelvin, 3.e-18*pascal);

	// Silicon Tracker Configuration
	G4double trackerThickness = 0.3 * mm; ;     // Thickness of silicon layer
	G4double tungstenThickness = 0.105 * mm;
	G4double tungstenThicknessThick =  2.52 / 2 * mm;    // Thickness of tungsten layer
	G4double trackerWidth = 10*cm;          // Width and length of each tracker layer
	G4double trackerLength = 10*cm;

	G4int numTrackerLayers = 12;            // Number of silicon layers
	G4double layerSpacing = 1.0 * mm;          // Spacing between layers

	G4double trackerZPosition = -15*cm; 

	// Define the solid shapes for silicon and tungsten layers
	G4Box* solidTrackerLayer = new G4Box("solidTrackerLayer", trackerWidth/2, trackerLength/2, trackerThickness/2);
	G4Box* solidTungstenLayer = new G4Box("solidTungstenLayer", trackerWidth/2, trackerLength/2, tungstenThickness/2);

	// Define logical volumes for silicon and tungsten layers
	G4LogicalVolume* logicTrackerLayer = new G4LogicalVolume(solidTrackerLayer, Si, "logicTrackerLayer");
	G4LogicalVolume* logicTungstenLayer = new G4LogicalVolume(solidTungstenLayer, W, "logicTungstenLayer");

	// Place each tracker and tungsten layer along the Z-axis
	for (G4int i = 0; i < numTrackerLayers; ++i) {
		G4double zPos = -((numTrackerLayers - 1) * layerSpacing) / 2 + i * layerSpacing + trackerZPosition;

		// Place the silicon layer
		new G4PVPlacement(0, G4ThreeVector(0, 0, zPos), logicTrackerLayer, "physTrackerLayer", logicworld, false, i, true);

		// Place the tungsten layer (between silicon layers)
		if (i < numTrackerLayers - 1) { // Ensure tungsten layers are one less than silicon layers
			G4double tungstenZPos = zPos + trackerThickness / 2 + tungstenThickness / 2;
			new G4PVPlacement(0, G4ThreeVector(0, 0, tungstenZPos), logicTungstenLayer, "physTungstenLayer", logicworld, false, i, true);
		}
	}

	G4Box* solidTungstenLayerThick = new G4Box("solidTungstenLayerThick", trackerWidth/2, trackerLength/2, tungstenThicknessThick/2);
	G4LogicalVolume* logicTungstenLayerThick = new G4LogicalVolume(solidTungstenLayerThick, W, "logicTungstenLayerThick");

	G4double zPosThick = -((numTrackerLayers - 1) * layerSpacing) / 2 + numTrackerLayers * layerSpacing + trackerZPosition;
	new G4PVPlacement(0, G4ThreeVector(0, 0, zPosThick), logicTungstenLayerThick, "physTungstenLayerThick", logicworld, false, 0, true);

	G4cout << *( G4Material::GetMaterialTable() ) << G4endl;

  return physworld;
}
