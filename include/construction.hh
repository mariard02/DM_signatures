#ifndef CONSTRUCTION_HH
#define CONSTRUCTION_HH

#include "G4VUserDetectorConstruction.hh"
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"
#include "G4Box.hh"
#include "G4PVPlacement.hh"
#include "G4NistManager.hh"
#include "G4VSensitiveDetector.hh"

#include "G4RotationMatrix.hh"

#include "G4SystemOfUnits.hh"

#include "detector.hh"

#include "G4HadronPhysicsFTFP_BERT.hh"
#include "G4OpticalSurface.hh"
#include "G4LogicalBorderSurface.hh"

#include "G4LogicalSkinSurface.hh"

class MyDetectorConstruction : public G4VUserDetectorConstruction
{
public:
	MyDetectorConstruction();
	~MyDetectorConstruction();

	virtual G4VPhysicalVolume *Construct();

	G4LogicalVolume *logicLog;
	virtual void ConstructSDandField();

private:
	
	

	G4int              NbOfLayers;
	G4int              NbOfColumns;
	G4double           LayerThickness;          
	G4double           CalorThickness;
	G4double		LayerGap;
	G4double		ColumnGap;
	G4double           LogWidth;          
	G4double           LogLength; 


};

#endif