#include "Geometry.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4PVReplica.hh"
#include "G4SDManager.hh"
#include "G4SystemOfUnits.hh"
#include "SensitiveDetector.hh"
#include "DataStore.hh"

Geometry::Geometry() : G4VUserDetectorConstruction(), dataStore(nullptr) {}

Geometry::~Geometry() {}

void Geometry::SetDataStore(DataStore* ds) {
    dataStore = ds;
}

G4VPhysicalVolume* Geometry::Construct() {
    // Get materials
    G4NistManager* nist = G4NistManager::Instance();
    G4Material* air = nist->FindOrBuildMaterial("G4_AIR");
    G4Material* water = nist->FindOrBuildMaterial("G4_WATER");

    // World
    G4double world_size = 1.0 * m;
    G4Box* solidWorld = new G4Box("World", world_size / 2, world_size / 2, world_size / 2);
    G4LogicalVolume* logicWorld = new G4LogicalVolume(solidWorld, air, "World");
    G4VPhysicalVolume* physWorld = new G4PVPlacement(nullptr, G4ThreeVector(), logicWorld, "World", nullptr, false, 0, true);

    // Water phantom
    G4double phantom_size = 30.0 * cm;
    G4Box* solidPhantom = new G4Box("Phantom", phantom_size / 2, phantom_size / 2, phantom_size / 2);
    G4LogicalVolume* logicPhantom = new G4LogicalVolume(solidPhantom, water, "Phantom");
    new G4PVPlacement(nullptr, G4ThreeVector(), logicPhantom, "Phantom", logicWorld, false, 0, true);

    // Slices
    G4double slice_thickness = 1.0 * mm;
    G4Box* solidSlice = new G4Box("Slice", phantom_size / 2, phantom_size / 2, slice_thickness / 2);
    G4LogicalVolume* logicSlice = new G4LogicalVolume(solidSlice, water, "Slice");
    new G4PVReplica("PhantomSlice", logicSlice, logicPhantom, kZAxis, 300, slice_thickness);

    // Sensitive detector
    SensitiveDetector* sd = new SensitiveDetector("WaterPhantom", dataStore);
    G4SDManager::GetSDMpointer()->AddNewDetector(sd);
    logicSlice->SetSensitiveDetector(sd);

    return physWorld;
}