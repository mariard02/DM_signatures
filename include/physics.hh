#ifndef PHYSICS_HH
#define PHYSICS_HH

#include "G4VModularPhysicsList.hh"
#include "G4EmStandardPhysics.hh"
#include "G4OpticalPhysics.hh"
#include "G4DecayPhysics.hh"
#include "G4HadronPhysicsFTFP_BERT.hh"

#include "G4ProcessManager.hh"
#include "G4Gamma.hh"

#include "G4EmLivermorePhysics.hh"
#include "G4EmLivermorePolarizedPhysics.hh"
#include "G4EmPenelopePhysics.hh"

#include "G4Decay.hh"
#include "G4HadronDElasticPhysics.hh"
#include "G4HadronElasticPhysics.hh"
#include "G4HadronElasticPhysicsHP.hh"
#include "G4HadronPhysicsQGSP_BIC_HP.hh"
#include "G4IonBinaryCascadePhysics.hh"
#include "G4IonFluctuations.hh"
#include "G4IonParametrisedLossModel.hh"
#include "G4LossTableManager.hh"
#include "G4ProcessManager.hh"
#include "G4RadioactiveDecayPhysics.hh"
#include "G4StepLimiter.hh"
#include "G4SystemOfUnits.hh"
#include "G4UnitsTable.hh"



class MyPhysicsList : public G4VModularPhysicsList
{
public:
	MyPhysicsList();
	~MyPhysicsList();

};

#endif