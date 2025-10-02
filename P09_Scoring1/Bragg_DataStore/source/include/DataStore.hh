#ifndef DATASTORE_HH
#define DATASTORE_HH

#include <map>
#include "globals.hh"

class DataStore {
public:
    DataStore();
    ~DataStore();
    void InitializeMap();
    std::map<G4int, G4double> GetMap();
    void FillMap(G4int copyNo, G4double energy);

private:
    std::map<G4int, G4double> myMap;
};

#endif