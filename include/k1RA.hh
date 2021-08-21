#ifndef k1RA_h
#define k1RA_h 1

#include "G4UserRunAction.hh"
#include "G4Accumulable.hh"
#include "Run.hh"

class HistoManager;
class Run;

class k1RA : public G4UserRunAction
{
  public:
    k1RA(HistoManager* histo);
    virtual ~k1RA();
    
    virtual void BeginOfRunAction(const G4Run*);
    virtual void   EndOfRunAction(const G4Run*);
    virtual G4Run* GenerateRun();
private:
    HistoManager* _histo;
    Run* _run;  
    };


#endif
