#include "G4RunManager.hh"
#include "G4UImanager.hh"
#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"
#include "G4PhysListFactory.hh"
#include "Geometry.hh"
#include "DataStore.hh"
#include "UserActionInitialization.hh"

int main(int argc, char** argv) {
    // Instantiate UI Executive
    G4UIExecutive* ui = new G4UIExecutive(argc, argv);

    // DataStore instance
    DataStore* dataStore = new DataStore();

    // RunManager
    G4RunManager* runManager = new G4RunManager();

    // Physics list
    G4PhysListFactory factory;
    G4VModularPhysicsList* physicsList = factory.GetReferencePhysList("FTFP_BERT");
    runManager->SetUserInitialization(physicsList);

    // Set user-defined initialization classes
    Geometry* geometry = new Geometry();
    geometry->SetDataStore(dataStore);
    runManager->SetUserInitialization(geometry);
    runManager->SetUserInitialization(new UserActionInitialization(dataStore));

    // Initialize G4 kernel
    runManager->Initialize();

    // Visualization manager
    G4VisManager* visManager = new G4VisExecutive();
    visManager->Initialize();

    // UI manager
    G4UImanager* UImanager = G4UImanager::GetUIpointer();
    UImanager->ApplyCommand("/control/execute GlobalSetup.mac");

    // Start UI session
    ui->SessionStart();

    // Clean up
    delete visManager;
    delete runManager;
    delete ui;
    delete dataStore;

    return 0;
}
