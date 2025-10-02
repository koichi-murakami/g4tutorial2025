#include "PrimaryGenerator.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4SystemOfUnits.hh"

PrimaryGenerator::PrimaryGenerator() {
    G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
    G4ParticleDefinition* proton = particleTable->FindParticle("proton");
    particleGun = new G4ParticleGun(proton, 1);
    particleGun->SetParticleEnergy(100 * MeV);
    particleGun->SetParticlePosition(G4ThreeVector(0, 0, -20 * cm));
    particleGun->SetParticleMomentumDirection(G4ThreeVector(0, 0, 1));
}

PrimaryGenerator::~PrimaryGenerator() {
    delete particleGun;
}

void PrimaryGenerator::GeneratePrimaries(G4Event* event) {
    particleGun->GeneratePrimaryVertex(event);
}