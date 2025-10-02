#ifndef SENSITIVE_DETECTOR_HH
#define SENSITIVE_DETECTOR_HH

#include "G4VSensitiveDetector.hh"
#include <map>

class SensitiveDetector : public G4VSensitiveDetector {
public:
    SensitiveDetector(const G4String& name);
    ~SensitiveDetector() override;
    void Initialize(G4HCofThisEvent* hce) override;
    G4bool ProcessHits(G4Step* step, G4TouchableHistory* history) override;
    void EndOfEvent(G4HCofThisEvent* hce) override;

private:
    std::map<G4int, G4double> energyMap;
};

#endif
