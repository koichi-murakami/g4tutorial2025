#include "UserActionInitialization.hh"
#include "RunAction.hh"
#include "PrimaryGenerator.hh"

UserActionInitialization::UserActionInitialization(DataStore* ds) : G4VUserActionInitialization(), dataStore(ds) {}

UserActionInitialization::~UserActionInitialization() {}

void UserActionInitialization::Build() const {
    SetUserAction(new RunAction(dataStore));
    SetUserAction(new PrimaryGenerator());
}