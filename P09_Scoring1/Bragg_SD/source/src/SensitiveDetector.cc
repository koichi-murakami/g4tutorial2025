#include "SensitiveDetector.hh"
#include "G4Step.hh"
#include "G4TouchableHistory.hh"

SensitiveDetector::SensitiveDetector(const G4String& name) 
    : G4VSensitiveDetector(name) {}

SensitiveDetector::~SensitiveDetector() = default;



G4bool SensitiveDetector::ProcessHits(G4Step* step, G4TouchableHistory*) {
    G4double edep = step->GetTotalEnergyDeposit();
    if (edep > 0) {
        G4int copyNo = step->GetPreStepPoint()->GetTouchable()->GetCopyNumber();
        energyMap[copyNo] += edep;
    }
    return true;
}


void SensitiveDetector::Initialize(G4HCofThisEvent*) {
// at every event the map is cleared
	energyMap.clear();
}

void SensitiveDetector::EndOfEvent(G4HCofThisEvent*) {
// only to see energyMap
  for (const auto& pair: energyMap){
	G4cout << "copyNo : " << pair.first << " eDep " << pair.second << G4endl;
	}
}



