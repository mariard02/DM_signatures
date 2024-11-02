#include "detector.hh"
#include <string>

MySensitiveDetector::MySensitiveDetector(G4String name) : G4VSensitiveDetector(name)
{
	OutputFile.open("./step_output.txt", std::ofstream::out | std::ofstream::trunc);
    OutputFile << "Energy (eV)\tTime (ns)\tScnitillator\n";
    OutputFile.flush();
}

MySensitiveDetector::~MySensitiveDetector()
{}

G4bool MySensitiveDetector::ProcessHits(G4Step *aStep, G4TouchableHistory *ROhist)
{	
	G4Track *track = aStep->GetTrack();

    // Stops the photon tracking after it enters the detector
    track->SetTrackStatus(fStopAndKill);

    // Obtain pre and post step
    G4StepPoint *preStepPoint = aStep->GetPreStepPoint();
    G4StepPoint *postStepPoint = aStep->GetPostStepPoint();
    
    // Obtain the kinetic energy of the photon
    G4double photonEnergy = preStepPoint->GetKineticEnergy();

    G4double photonTime = preStepPoint->GetGlobalTime();

    //const G4VTouchable *touchable = aStep->GetPreStepPoint()->GetTouchable();

	//G4int copyNo = touchable->GetCopyNumber();

    //OutputFile << photonEnergy/ CLHEP::eV << "\t" << photonTime << "\t" << copyNo << "\n";

    return true;
}