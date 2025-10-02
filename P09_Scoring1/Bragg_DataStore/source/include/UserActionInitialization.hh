#ifndef USERACTIONINITIALIZATION_HH
#define USERACTIONINITIALIZATION_HH

#include "G4VUserActionInitialization.hh"
#include "DataStore.hh"

class UserActionInitialization : public G4VUserActionInitialization {
public:
    UserActionInitialization(DataStore* ds);
    virtual ~UserActionInitialization();
    virtual void Build() const override;

private:
    DataStore* dataStore;
};

#endif