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

	G4double theta_min = 0.0; // Ángulo mínimo en radianes
	G4double theta_max = std::atan(2.0 / 1.5); // Ángulo máximo según la geometría

	G4double phi_min = 0.0; // Ángulo azimutal mínimo
	G4double phi_max = CLHEP::twopi; // Ángulo azimutal máximo

	// Generar ángulos dentro de los rangos especificados
	G4double cosTheta = std::cos(theta_min) + (std::cos(theta_max) - std::cos(theta_min)) * G4UniformRand();
	G4double theta = std::acos(cosTheta); // Convertir a radianes
	G4double phi = phi_min + (phi_max - phi_min) * G4UniformRand();

	// Convertir a coordenadas cartesianas
	G4double sinTheta = std::sqrt(1. - cosTheta * cosTheta);
	G4double ux = sinTheta * std::cos(phi);
	G4double uy = sinTheta * std::sin(phi);
	G4double uz = cosTheta;

  	fParticleGun->SetParticleMomentumDirection(G4ThreeVector(ux,uy, uz));

	G4cout << "Momentum direction: " << G4ThreeVector(ux, uy, uz) << G4endl;

	G4ThreeVector pos(0., 0., -1.5*m);
	G4ThreeVector mom(0., 0., 1.);

	fParticleGun->SetParticlePosition(pos);
	//fParticleGun->SetParticleMomentumDirection(mom);

	G4double E_min = 500. * MeV;
	G4double E_max = 10. * GeV;

	// Genera una energía aleatoria con distribución E^-2
	G4double E_gamma = GenerateEnergyWithPowerLaw(E_min, E_max, -2.0);

	E_gamma = 10. * GeV;

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