#ifndef GEOMETRY_HH
#define GEOMETRY_HH

#include "G4VUserDetectorConstruction.hh"
#include "G4LogicalVolume.hh"
#include "G4VPhysicalVolume.hh"

class Geometry : public G4VUserDetectorConstruction {
public:
    Geometry();
    ~Geometry() override;
    G4VPhysicalVolume* Construct() override;
};

#endif