#include "physics.hh"

MyPhysicsList::MyPhysicsList()
{
	RegisterPhysics(new G4HadronPhysicsFTFP_BERT());
	RegisterPhysics (new G4EmStandardPhysics());
	RegisterPhysics(new G4OpticalPhysics());
	RegisterPhysics (new G4DecayPhysics());
	RegisterPhysics (new G4EmExtraPhysics());
};

MyPhysicsList::~MyPhysicsList(){}; 

void MyPhysicsList::SetCuts()
{

    G4double cutValue = 0.001 * CLHEP::mm;  

    SetCutValue(cutValue, "gamma");  // Corte para fotones
    SetCutValue(cutValue, "e-");     // Corte para electrones
    SetCutValue(cutValue, "e+");     // Corte para positrones

    // Opcional: imprimir los cortes para verificar
    G4cout << "Energy cuts implemented for gamma, e-, e+ : " << cutValue << " mm" << G4endl;
}

