#ifndef HistoManager_h
#define HistoManager_h 1

#include "globals.hh"

class TFile;
class TTree;
class TH1D;

class HistoManager
{
public:
 HistoManager();
~HistoManager();

void Book();
void Save();
void Draw();
void Fill(std::tuple<G4double,G4double>);
void Fill_Histogram_ALLPHOTONS(G4double energy);
void Fill_Histogram_SCATTERED_PHOTONS(G4double energy);
void Fill_Histogram_ELECTRONS(G4double energy);

private:
G4double _z;
G4double _edep;
G4double _histo_energy;
TTree*   _Ntuple1;  
TH1D* _histo_all_photons;  
TH1D* _histo_scattered_photons;  
TH1D* _histo_electrons;  
TFile* rootfile;
};
#endif