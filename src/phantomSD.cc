#include "phantomSD.hh"


#include "G4VSensitiveDetector.hh"
#include "G4HCofThisEvent.hh"
#include "G4SDManager.hh"
#include "G4SystemOfUnits.hh"
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"
#include "k1DC.hh"
#include "G4RunManager.hh"
#include "G4ThreeVector.hh"
#include "G4HCofThisEvent.hh"
#include "G4Step.hh"
#include "G4ThreeVector.hh"
#include "G4SDManager.hh"
#include "G4ios.hh"
#include "Run.hh"
#include "G4Gamma.hh"
#include "G4Electron.hh"

phantomSD::phantomSD(const G4String& name,const G4String& HCname):
G4VSensitiveDetector(name),
_phantomHC(NULL)
{
collectionName.insert(HCname);

}

phantomSD::~phantomSD(){}

void phantomSD::Initialize(G4HCofThisEvent* hc)
{
_phantomHC = new phantomHC(SensitiveDetectorName,collectionName[0]);
G4int hcID = G4SDManager::GetSDMpointer()->GetCollectionID(collectionName[0]);
hc->AddHitsCollection(hcID,_phantomHC);
}
G4bool phantomSD::ProcessHits(G4Step* step,G4TouchableHistory*)
{
  //scattered and all photons

    if(step->GetTrack()->GetDefinition() == G4Gamma::Gamma())
    {
     auto hc = new phantomHit();
    G4double energy=step->GetPreStepPoint()->GetKineticEnergy()/keV;
    hc->Set_Histogram_ALLPHOTONS_Energy(energy);
    if(energy!=1330 && energy!=1170){hc->Set_Histogram_SCATTERED_Energy(energy);}
        _phantomHC->insert(hc);

    //count 
//     Run* run = static_cast<Run*>(G4RunManager::GetRunManager()->GetNonConstCurrentRun());
//     if(energy!=1330 && energy!=1170){    run->CountPhoton((G4double)0,(G4double)1);
// }
// else{ run->CountPhoton((G4double)1,(G4double)0);}
    }
    else if(step->GetTrack()->GetDefinition() == G4Electron::Electron())
    {
            auto hc = new phantomHit();
    G4double energy=step->GetPreStepPoint()->GetKineticEnergy()/keV;
            hc->Set_Histogram_ELECTRONS_Energy(energy);
            _phantomHC->insert(hc);


    }

//pdd

//     auto edep = step->GetTotalEnergyDeposit()/MeV;

//     // auto e = step->Get
//     if (edep==0.) return false;
//     G4ThreeVector pos = step->GetPreStepPoint()->GetPosition();

//     const G4VTouchable* touchable = step->GetPreStepPoint()->GetTouchable();
//     G4int ix =touchable->GetReplicaNumber(2);
//     G4int iy =touchable->GetReplicaNumber(1);
//     G4int iz =touchable->GetReplicaNumber(0);

// if(ix==49 || ix==50 && iy==49 ||iy==50){
//     // G4cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> replica :"<<iz<<G4endl;
//     auto mass =touchable->GetVolume(0)->GetLogicalVolume()->GetMass()/kg;

//     G4double dose=edep/mass;

//     // RUN

//     Run* run = static_cast<Run*>(G4RunManager::GetRunManager()->GetNonConstCurrentRun());
//     run->AddData(dose,(G4double)iz);

// }











//end pdd
    // Run* run = static_cast<Run*>(G4RunManager::GetRunManager()->GetNonConstCurrentRun());
    // run->AddData(step->GetPreStepPoint()->GetKineticEnergy());
    
// else if()
// {
//     auto hc = new phantomHit();
//     G4double energy=step->GetPreStepPoint()->GetKineticEnergy()/keV;
//     _phantomHC->insert(hc);
// }
 // auto charge = step->GetTrack()->GetDefinition()->GetPDGCharge();
    // auto edep = step->GetTotalEnergyDeposit()/MeV;
    // const G4VTouchable* touchable = step->GetPreStepPoint()->GetTouchable();

    // auto e = step->Get
    // G4int iz =touchable->GetReplicaNumber(0);
    // if (edep==0.) return false;
    // if(iz!=9)return false;
    // if(iz!=8)return false;
    // G4ThreeVector pos = step->GetPreStepPoint()->GetPosition();

    // G4int iy =touchable->GetReplicaNumber(2);

    // auto massy =touchable->GetVolume(2)->GetLogicalVolume()->GetMass()/kg;
    // auto massx =touchable->GetVolume(1)->GetLogicalVolume()->GetMass()/kg;
    // auto mass =touchable->GetVolume(0)->GetLogicalVolume()->GetMass()/kg;

    // G4cout<<"------------------------------------------------>> Mass X :"<<massx <<"----------->> Dose :"<<edep/massx<<G4endl;
    // G4cout<<"------------------------------------------------>> Mass Y :"<<massy <<"----------->> Dose :"<<edep/massy<<G4endl;
    // G4cout<<"------------------------------------------------>> Mass Z :"<<massz <<"----------->> Dose :"<<edep/massz<<G4endl;


    // G4double dose=/edep/mass;

    // RUN

    // Run* run = static_cast<Run*>(G4RunManager::GetRunManager()->GetNonConstCurrentRun());
    // run->AddData(dose,(G4double)iy);

    //end RUN
    
    //HIT

    // auto hc = new phantomHit();
    // hc->Set_CopyNo_Dose_tuple(std::make_tuple(iz,dose));
    // _phantomHC->insert(hc);

    //end HIT
return true;

}
void phantomSD::EndOfEvent(G4HCofThisEvent*)
{
}