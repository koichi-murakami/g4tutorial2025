#include "Geometry.hh"
#include "G4Box.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4PVReplica.hh"
#include "G4Material.hh"
#include "G4NistManager.hh"
#include "G4SystemOfUnits.hh"
#include "G4SDManager.hh"
#include "SensitiveDetector.hh"

Geometry::Geometry() = default;
Geometry::~Geometry() = default;

G4VPhysicalVolume* Geometry::Construct() {
    G4NistManager* nist = G4NistManager::Instance();

    // World
    G4Material* air = nist->FindOrBuildMaterial("G4_AIR");
    G4Box* worldBox = new G4Box("World", 0.5 * m, 0.5 * m, 0.5 * m);
    G4LogicalVolume* worldLogic = new G4LogicalVolume(worldBox, air, "World");
    G4VPhysicalVolume* worldPhys = new G4PVPlacement(nullptr, {}, worldLogic, "World", nullptr, false, 0);

    // Water Phantom  not bad
    G4Material* water = nist->FindOrBuildMaterial("G4_WATER");
    G4Box* phantomBox = new G4Box("Phantom", 15 * cm, 15 * cm, 15 * cm);
    G4LogicalVolume* phantomLogic = new G4LogicalVolume(phantomBox, water, "Phantom");
    new G4PVPlacement(nullptr, {}, phantomLogic, "Phantom", worldLogic, false, 0);

    // Slices   good
    G4Box* sliceBox = new G4Box("Slice", 15 * cm, 15 * cm, 0.5 * mm);
    G4LogicalVolume* sliceLogic = new G4LogicalVolume(sliceBox, water, "Slice");
    new G4PVReplica("Slices", sliceLogic, phantomLogic, kZAxis, 300, 1 * mm);


 // Assign sensitive detector
    G4SDManager* sdManager = G4SDManager::GetSDMpointer();
    SensitiveDetector* sd = new SensitiveDetector("WaterPhantom");
    sdManager->AddNewDetector(sd);
    sliceLogic->SetSensitiveDetector(sd);
    return worldPhys;
}
