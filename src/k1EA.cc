#include "G4Event.hh"
#include "G4SDManager.hh"
#include "G4HCofThisEvent.hh"
#include "G4UnitsTable.hh"

#include "k1EA.hh"
#include "k1RA.hh"
#include "HistoManager.hh"


k1EA::k1EA(k1RA* ra,HistoManager* histo)
 : G4UserEventAction(),_edep_HCID(-1),_histo(histo),_charge_HCID(-1),_runAction(ra)
{}


k1EA::~k1EA()
{}

phantomHC*  k1EA::GetphantomHitsCollection(G4int hcID,const G4Event* event) const
{
  auto hitsCollection = static_cast<phantomHC*>(event->GetHCofThisEvent()->GetHC(hcID));
  
  if ( ! hitsCollection ) 
  {
    G4ExceptionDescription msg;
    msg << "Cannot access hitsCollection ID " << hcID; 
    G4Exception("B4cEventAction::GetHitsCollection()","MyCode0003", FatalException, msg);
  }         

  return hitsCollection;
}  
chamberHC*  k1EA::GetchamberHitsCollection(G4int hcID,const G4Event* event) const
{
  auto hitsCollection = static_cast<chamberHC*>(event->GetHCofThisEvent()->GetHC(hcID));
  
  if ( ! hitsCollection ) 
  {
    G4ExceptionDescription msg;
    msg << "Cannot access hitsCollection ID " << hcID; 
    G4Exception("B4cEventAction::GetHitsCollection()","MyCode0003", FatalException, msg);
  }         

  return hitsCollection;
} 

void k1EA::BeginOfEventAction(const G4Event* event)
{
  G4int evtNb = event->GetEventID();
  if (evtNb%100000 == 0) 
    G4cout << "\n---> Begin of event: " << evtNb << G4endl;
 
}

void k1EA::EndOfEventAction(const G4Event* event)
{  
//       // Get hits collections IDs (only once)
  if ( _edep_HCID == -1 ) 
  {
    _edep_HCID 
      = G4SDManager::GetSDMpointer()->GetCollectionID("edep");
    // _charge_HCID
      // = G4SDManager::GetSDMpointer()->GetCollectionID("charge");
  }
  
// // Get HCs object
auto _phantomHC = GetphantomHitsCollection(_edep_HCID, event);
// // auto _chamberHC = GetchamberHitsCollection(_charge_HCID,event);

// // HCs object lenght
auto phantomHC_lenght = _phantomHC->entries();
// // auto chamberHC_lenght = _chamberHC->entries();


//fill edep_curve
for(size_t i=0;i<phantomHC_lenght;i++)
{
  auto _hit = (*_phantomHC)[i];
  _histo->Fill_Histogram_ALLPHOTONS(_hit->Get_Histogram_ALLPHOTONS_Energy());
  _histo->Fill_Histogram_SCATTERED_PHOTONS(_hit->Get_Histogram_SCATTERED_Energy());
  _histo->Fill_Histogram_ELECTRONS(_hit->Get_Histogram_ELECTRONS_Energy());

}

//charge
// G4double sum=0;
// for(size_t i=0;i<chamberHC_lenght;i++)
// {
//   auto _hit = (*_chamberHC)[i];
//   sum+=_hit->GetCharge();
// }
// _runAction->SumCharge(sum);
}  
