#ifndef DETECTOR_HH
#define DETECTOR_HH 

#include "G4VSensitiveDetector.hh"

class MySensitiveDetector : public G4VSensitiveDetector
{
public:
	MySensitiveDetector(G4String);
	~MySensitiveDetector();
	virtual G4bool ProcessHits(G4Step *, G4TouchableHistory *);

	G4LogicalVolume *logicLog;
private:
	
	std::ofstream OutputFile;
};

#endif