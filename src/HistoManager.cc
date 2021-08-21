#include "HistoManager.hh"
#include <TTree.h>
#include <TH1D.h>
#include <TFile.h>
//there is another way to include following header .
#include <CLHEP/Units/SystemOfUnits.h>
HistoManager::HistoManager():rootfile(0)
{
  _Ntuple1=0;
  _z=0;
  _edep=0;
  _histo_all_photons=0;
  _histo_scattered_photons=0;
  _histo_electrons=0;
}

HistoManager::~HistoManager(){if(rootfile)delete rootfile;}

void HistoManager::Save()
{
    if(!rootfile)return;
    rootfile->Write();
    rootfile->Close();
}

void HistoManager::Book()
{
  //G4cout<<"File is opened"<<G4endl;
rootfile = new TFile("result.root","RECREATE");
_histo_all_photons = new TH1D("APH", "All Photons (keV)", 50, 0., 1500);
_histo_scattered_photons = new TH1D("SPH", "Scattered Photons (keV)", 50, 0., 1500);
_histo_electrons = new TH1D("E", "Electrons (keV)", 50, 0., 1500);

_Ntuple1 = new TTree("Ntuple1", "Edep");
_Ntuple1->Branch("Z", &_z, "Z/D");
_Ntuple1->Branch("edep", &_edep, "edep/D");
}


void HistoManager::Fill(std::tuple<G4double,G4double>  pos_edep)
{
if(std::get<1>(pos_edep)!=0)
{
  _z=std::get<0>(pos_edep);
  _edep=std::get<1>(pos_edep);
  _Ntuple1->Fill();
}

}

void HistoManager::Fill_Histogram_ALLPHOTONS( G4double e)
{
      // G4cout<<"------------------------------------------->>"<<e<<G4endl;

  _histo_all_photons->Fill(e);
}

void HistoManager::Fill_Histogram_SCATTERED_PHOTONS( G4double e)
{
      // G4cout<<"------------------------------------------->>"<<e<<G4endl;

  _histo_scattered_photons->Fill(e);
}
void HistoManager::Fill_Histogram_ELECTRONS( G4double e)
{
      // G4cout<<"------------------------------------------->>"<<e<<G4endl;

  _histo_electrons->Fill(e);
}
