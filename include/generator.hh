#ifndef GENERATOR_HH
#define GENERATOR_HH

#include "G4VUserPrimaryGeneratorAction.hh"

#include "G4ParticleGun.hh"
#include "G4SystemOfUnits.hh"
#include "G4ParticleTable.hh"
#include <string>
#include <fstream>

class MyPrimaryGenerator : public G4VUserPrimaryGeneratorAction
{
public:
	MyPrimaryGenerator();
	~MyPrimaryGenerator();

	virtual void GeneratePrimaries(G4Event*);

private:
	G4ParticleGun *fParticleGun;
	G4double GenerateEnergyWithPowerLaw(G4double E_min, G4double E_max, G4double alpha);
	std::ofstream TotalEnergyFile;
};

#endif