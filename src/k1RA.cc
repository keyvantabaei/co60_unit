
#include "k1RA.hh"
#include "k1DC.hh"
#include "HistoManager.hh"
#include "G4Run.hh"
#include "G4RunManager.hh"
#include "G4AccumulableManager.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"

G4Run* k1RA::GenerateRun()
{ 
  _run = new Run();
  return _run;
}
k1RA::k1RA(HistoManager* histo): G4UserRunAction(),_histo(histo)
{  

}


k1RA::~k1RA()
{ }


void k1RA::BeginOfRunAction(const G4Run* run)
{ 
  G4cout << "### Run " << run->GetRunID() << " start." << G4endl;
  _histo->Book();

    // reset accumulables to their initial values
  G4AccumulableManager* accumulableManager = G4AccumulableManager::Instance();
  accumulableManager->Reset();

  //inform the runManager to save random number seed
  G4RunManager::GetRunManager()->SetRandomNumberStore(false);
}


void k1RA::EndOfRunAction(const G4Run* run)
{
  G4int nofEvents = run->GetNumberOfEvent();
  if (nofEvents == 0) return;

  // Merge accumulables 
  // G4AccumulableManager* accumulableManager = G4AccumulableManager::Instance();
  // accumulableManager->Merge();

// G4UnitDefinition::PrintUnitsTable();


// RUN
// Run* _run = static_cast<Run*>(G4RunManager::GetRunManager()->GetNonConstCurrentRun());
// auto doses=_run->GetDose();

// auto data=_run->GetCountedPhotons();
// G4cout<<"------------------------------------->> Primary :"<<std::get<0>(data)<<G4endl;
// G4cout<<"------------------------------------->> Scattered :"<<std::get<1>(data)<<G4endl;
// G4cout<<"------------------------------------->> ALL :"<<std::get<2>(data)<<G4endl;


// G4double D;
// for(int i=0;i<100;i++)
// {
// D=doses[i];
// G4cout<<"X =  "<<i<<G4endl;
// G4cout<<"Dose =   "<<D<<G4endl;
// _histo->Fill(std::make_tuple((G4double)(i),D));
// }

// G4double seg_no=doses.lenght();
// for(G4int i=1;i<=seg_no;i--)
// {
//     G4double dose=0;
//     volume_percent=i/seg_no;
//     for(j=i-1;j<seg_no;j++)
//     {
//         dose+=doses[j];
//     }
// }
// copy number of geometry =  iy*Nx*Ny+ix*Nz+iz





Run* _run = static_cast<Run*>(G4RunManager::GetRunManager()->GetNonConstCurrentRun());
auto doses=_run->GetDose();

G4double max=0;
for(int i=0;i<25;i++)
{
if(doses[i]>max)
max=doses[i];
}
//G4cout<<"Max is :"<<max<<G4cout;
G4double pdd;
for(int i=0;i<100;i++)
{
pdd=doses[i]/max;
pdd=100*pdd;
G4cout<<"DOSES :"<<doses[i]<<"    z :"<<i+1<<G4endl;
_histo->Fill(std::make_tuple((G4double)(i+1),pdd));
}











     _histo->Save();
     G4cout<<"Ntuple has been saved !"<<G4endl;

//end RUN

}
