#include "PrimaryGenerator.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
#include "G4SystemOfUnits.hh"

PrimaryGenerator::PrimaryGenerator() {
    G4int n_particle = 1;
    particleGun = new G4ParticleGun(n_particle);

    // Default particle
    G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
    G4ParticleDefinition* particle = particleTable->FindParticle("proton");
    particleGun->SetParticleDefinition(particle);
    particleGun->SetParticleEnergy(100 * MeV);
    particleGun->SetParticlePosition(G4ThreeVector(0., 0., -15 * cm));
    particleGun->SetParticleMomentumDirection(G4ThreeVector(0., 0., 1.));
}

PrimaryGenerator::~PrimaryGenerator() {
    delete particleGun;
}

void PrimaryGenerator::GeneratePrimaries(G4Event* event) {
    particleGun->GeneratePrimaryVertex(event);
}