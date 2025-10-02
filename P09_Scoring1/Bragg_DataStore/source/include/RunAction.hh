#ifndef RUNACTION_HH
#define RUNACTION_HH

#include "G4UserRunAction.hh"
#include "DataStore.hh"

class RunAction : public G4UserRunAction {
public:
    RunAction(DataStore* ds);
    virtual ~RunAction();
    virtual void BeginOfRunAction(const G4Run*) override;
    virtual void EndOfRunAction(const G4Run*) override;

private:
    DataStore* dataStore;
};

#endif