#include "RunAction.hh"
#include "G4Run.hh"
#include <fstream>

RunAction::RunAction(DataStore* ds) : G4UserRunAction(), dataStore(ds) {}

RunAction::~RunAction() {}

void RunAction::BeginOfRunAction(const G4Run*) {
    dataStore->InitializeMap();
}

void RunAction::EndOfRunAction(const G4Run*) {
    std::map<G4int, G4double> myMap = dataStore->GetMap();
    std::ofstream outFile("Bragg.csv");
    outFile << "copyNo, energy\n";
    for (const auto& entry : myMap) {
        outFile << entry.first << ", " << entry.second << "\n";
    }
    outFile.close();
}