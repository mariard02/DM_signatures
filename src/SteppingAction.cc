#include "SteppingAction.hh"
#include "G4Step.hh"
#include "G4OpticalPhoton.hh"
#include "G4VProcess.hh"
#include "G4SystemOfUnits.hh"
#include "CLHEP/Units/PhysicalConstants.h" 
#include <string>
#include "G4Gamma.hh"
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

    if (preStepPoint->GetPhysicalVolume()->GetName() == "Layer")
         {

            G4int scintillatorID = preStepPoint->GetTouchableHandle()->GetCopyNumber();
            //G4double energyDeposited = track -> GetKineticEnergy();

            G4double energy = step->GetTotalEnergyDeposit();
        
        // Acumular energía en el centelleador correspondiente
        if (energy > 0) {
            energyDepositedMap[scintillatorID] += energy;
        }

            //track->SetTrackStatus(fStopAndKill);

    } 

}


void SteppingAction::EndOfEventAction()
{
    // Guardar la energía total depositada en cada centelleador en el archivo
    for (const auto& entry : energyDepositedMap) {
        G4int scintillatorID = entry.first;
        G4double totalEnergyDeposited = entry.second;
        
        _StepOutputFile1 << scintillatorID << "\t" << totalEnergyDeposited / CLHEP::MeV   <<  "\t" << eventID << "\n";

        _StepOutputFile1.flush();
    }

    // Limpiar el mapa para el próximo evento
    energyDepositedMap.clear();
    
    _StepOutputFile1.flush();
}

