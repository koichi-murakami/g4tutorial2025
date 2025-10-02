#ifndef PRIMARY_GENERATOR_HH
#define PRIMARY_GENERATOR_HH

#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4ParticleGun.hh"

class PrimaryGenerator : public G4VUserPrimaryGeneratorAction {
public:
    PrimaryGenerator();
    ~PrimaryGenerator() override;
    void GeneratePrimaries(G4Event* event) override;

private:
    G4ParticleGun* particleGun;
};

#endif