#include "DataStore.hh"

DataStore::DataStore() {}

DataStore::~DataStore() {}

void DataStore::InitializeMap() {
    myMap.clear();
}

std::map<G4int, G4double> DataStore::GetMap() {
    return myMap;
}

void DataStore::FillMap(G4int copyNo, G4double energy) {
    myMap[copyNo] += energy;
}