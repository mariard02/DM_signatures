#include "generator.hh"
#include "Randomize.hh"
#include <string>

MyPrimaryGenerator::MyPrimaryGenerator()
{
	fParticleGun = new G4ParticleGun(1);
	TotalEnergyFile.open("./eventenergy.txt");
}

MyPrimaryGenerator::~MyPrimaryGenerator()
{
	delete fParticleGun;
}

void MyPrimaryGenerator::GeneratePrimaries(G4Event *anEvent)
{
	G4ParticleTable *particleTable = G4ParticleTable::GetParticleTable();
	G4ParticleDefinition *particle = particleTable->FindParticle("gamma");

	G4ThreeVector pos(0., 0., -1.5*m);
	G4ThreeVector mom(0., 0., 1.);

	fParticleGun->SetParticlePosition(pos);
	fParticleGun->SetParticleMomentumDirection(mom);

	G4double E_min = 300. * MeV;
	G4double E_max = 1000. * MeV;

	
	// Genera una energía aleatoria con distribución E^-2
	G4double E_gamma = GenerateEnergyWithPowerLaw(E_min, E_max, -2.0);

	G4cout << E_gamma << " \n";
	//TotalEnergyFile.flush();

	fParticleGun->SetParticleEnergy(E_gamma);

	fParticleGun->SetParticleDefinition(particle);

	fParticleGun->GeneratePrimaryVertex(anEvent);
}

G4double MyPrimaryGenerator::GenerateEnergyWithPowerLaw(G4double E_min, G4double E_max, G4double alpha)
{
    // Genera una energía con una distribución de ley de potencia E^alpha
    G4double r = G4UniformRand();
    return std::pow((std::pow(E_max, alpha + 1) - std::pow(E_min, alpha + 1)) * r + std::pow(E_min, alpha + 1), 1.0 / (alpha + 1));
}