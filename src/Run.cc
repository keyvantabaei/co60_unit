#include "HistoManager.hh"
#include "G4Run.hh"
#include "Run.hh"
#include "G4DataVector.hh"
#include "G4SystemOfUnits.hh"

Run::Run():G4Run()
{
  for ( auto& d : dose ) { 
    d = 0.; 
  }
}
Run::~Run(){}
void Run::Merge(const G4Run* run)
{
  const Run* localRun = static_cast<const Run*>(run);
  for(int i=0; i<(int)dose.size(); i++) dose[i] += localRun->dose[i];
  G4Run::Merge(run);
}

void Run::EndOfRun()
{

}
void Run::AddData(G4double d,G4double i)
{
d=d/gray;
dose[i]=dose[i]+d;
}
