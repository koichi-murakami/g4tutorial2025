#include "Geometry.hh"
#include "SensitiveDetector.hh"
#include "UserActionInitialization.hh"

#include "G4RunManager.hh"
#include "G4UImanager.hh"
#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"
#include "QGSP_BERT.hh"

int main(int argc, char** argv) {

    auto* runManager = new G4RunManager();

    runManager->SetUserInitialization(new Geometry());
    runManager->SetUserInitialization(new QGSP_BERT());
    runManager->SetUserInitialization(new UserActionInitialization());
    runManager->Initialize();

    auto* visManager = new G4VisExecutive();
    visManager->Initialize();

    auto* uiExecutive = new G4UIExecutive(argc, argv);
    G4UImanager*  uiManager = G4UImanager::GetUIpointer();
    uiManager->ApplyCommand( "/control/execute GlobalSetup.mac" );
    uiExecutive->SessionStart();

    delete uiExecutive;
    delete visManager;
    delete runManager;

    return 0;
}
