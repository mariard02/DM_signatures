#include "RunAction.hh"

// Constructor
RunAction::RunAction():
		G4UserRunAction(),
		_TotalEnergyDeposit(0.)
{
    RunOutputFile.open("./PMT.txt");
    RunOutputFile << "Energy (eV) \t Time (ns) \t Scintillator ID \t Event ID \t Particle ID \n";
    RunOutputFile.flush();

    TotalEnergyFile.open("./eventenergy.txt");
    TotalEnergyFile << "Event \t Gamma ray energy (eV) \n";
}

// Destructor
RunAction::~RunAction() {
    if (RunOutputFile.is_open()) {
        RunOutputFile.close();
    }
}

// At the beginning of the run, the total energy deposit is 0
void RunAction::BeginOfRunAction(const G4Run* run)
{
	_TotalEnergyDeposit = 0.0;
}

// We add a certain number to the total energy deposit
void RunAction::AddTotalEnergyDeposit(G4double energy) {
    _TotalEnergyDeposit += energy;
}

// At the end of the run, we write in the output file the total energy deposit that we have preoviously calculated
void RunAction::EndOfRunAction(const G4Run* run)
{
	 RunOutputFile.close();
     TotalEnergyFile.close();
}
