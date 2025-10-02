#ifndef USER_ACTION_INITIALIZATION_HH
#define USER_ACTION_INITIALIZATION_HH

#include "G4VUserActionInitialization.hh"
#include "SensitiveDetector.hh"

class UserActionInitialization : public G4VUserActionInitialization {
public:
    UserActionInitialization();
    ~UserActionInitialization() override;
    void Build() const override;

};

#endif
