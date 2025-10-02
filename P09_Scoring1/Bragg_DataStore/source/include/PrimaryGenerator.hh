#ifndef PRIMARYGENERATOR_HH
#define PRIMARYGENERATOR_HH

#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4ParticleGun.hh"

class PrimaryGenerator : public G4VUserPrimaryGeneratorAction {
public:
    PrimaryGenerator();
    virtual ~PrimaryGenerator();
    virtual void GeneratePrimaries(G4Event* event) override;

private:
    G4ParticleGun* particleGun;
};

#endif