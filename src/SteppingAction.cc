#include "SteppingAction.hh"
#include "G4Step.hh"
#include "G4OpticalPhoton.hh"
#include "G4VProcess.hh"
#include "G4SystemOfUnits.hh"
#include "CLHEP/Units/PhysicalConstants.h" 
#include <string>
#include <cmath> // For M_PI


SteppingAction::SteppingAction()
{
	// Open a file to save the energies of the photons
	_StepOutputFile1.open("./PMT.txt", std::ofstream::out | std::ofstream::app);
    
}

// Create destructor
SteppingAction::~SteppingAction()
{}

void SteppingAction::UserSteppingAction(const G4Step* step)
{
	// Define what we do at each step
	auto track = step->GetTrack();

    //track->SetTrackStatus(fStopAndKill);

    auto particle = track->GetParticleDefinition();
    auto volume = track->GetVolume();
    G4StepPoint *preStepPoint = step->GetPreStepPoint();
    G4StepPoint *postStepPoint = step->GetPostStepPoint();

    _StepOutputFile1.flush();

    // Check if the particle is an optical photon AND if it is in the scintillator

    if (preStepPoint->GetPhysicalVolume()->GetName() == "Layer" && 
         (track->GetDefinition() == G4OpticalPhoton::Definition())
        ) {

            G4int trackID = track -> GetTrackID();

            G4double photonEnergy = track->GetKineticEnergy();
            G4double photonTime = track->GetGlobalTime();
            G4int scintillatorID = preStepPoint->GetTouchableHandle()->GetCopyNumber();
            
            _StepOutputFile1 << photonEnergy / eV << "\t" << photonTime / ns << "\t" << scintillatorID << "\t" << eventID << "\t" << trackID << "\n";

            _StepOutputFile1.flush();

            track->SetTrackStatus(fStopAndKill);

    } 
}


