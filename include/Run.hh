#ifndef Run_h
#define Run_h 1

#include "G4Run.hh"
#include "G4DataVector.hh"
#include <array>


class Run : public G4Run
{
    public:
    Run();
    virtual ~Run();
    virtual void Merge(const G4Run*);
    void EndOfRun();
    void AddData(G4double,G4double);
    void CountPhoton(G4double p,G4double s){primary+=p;scaterred+=s;all=primary+scaterred;}
    std::tuple<G4double,G4double,G4double> GetCountedPhotons(){return std::make_tuple(primary,scaterred,all);}
    std::array<G4double,200> GetDose(){return dose;}
    private:
    std::array<G4double,200>  dose;
    G4double primary;
    G4double scaterred;
    G4double all;
};

#endif