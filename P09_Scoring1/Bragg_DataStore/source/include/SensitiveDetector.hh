#ifndef SENSITIVEDETECTOR_HH
#define SENSITIVEDETECTOR_HH

#include "G4VSensitiveDetector.hh"
#include "globals.hh"
#include "G4Step.hh"
#include "DataStore.hh"

class SensitiveDetector : public G4VSensitiveDetector {
public:
    SensitiveDetector(const G4String& name, DataStore* ds);
    virtual ~SensitiveDetector();
    virtual void Initialize(G4HCofThisEvent* hce) override;
    virtual G4bool ProcessHits(G4Step* step, G4TouchableHistory* history) override;
    virtual void EndOfEvent(G4HCofThisEvent* hce) override;

private:
    DataStore* dataStore;
};

#endif
