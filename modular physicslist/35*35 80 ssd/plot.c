#include <TTree.h>
#include <TFile.h>
#include <TH1D.h>

void plot() 
{         


  TFile* r1 = new TFile("/home/k1/k1-Files/Programing/Geant4-workshop/reports/5/modular physicslist/35*35 80 ssd/result.root");

   
      
      
      

  TCanvas* c1 = new TCanvas("c1", "  ");

c1->Divide(2,1);


      TTree *Aphoton_source = new TTree("ntuple","data from ascii file");
      Long64_t LAphoton_source = Aphoton_source->ReadFile("allphoton-ss803535-0-175.csv","x:y");
      Aphoton_source->SetMarkerStyle(26);
      Aphoton_source->SetLineColor(kBlack);
      Aphoton_source->SetLineWidth(2);
          
      TTree *Sphoton_source = new TTree("ntuple","data from ascii file");
      Long64_t LSphoton_source = Sphoton_source->ReadFile("scatteredphoton-ssd03535-0-175.csv","x:y");
      Sphoton_source->SetMarkerStyle(26);
      Sphoton_source->SetLineColor(kBlack);
      Sphoton_source->SetLineWidth(2);
          
   
   
  TH1D* hist3 = (TH1D*)r1->Get("APH");
  TH1D* hist2 = (TH1D*)r1->Get("SPH");
  TH1D* hist1 = (TH1D*)r1->Get("E");
  

// 
        c1->cd(1);
    hist3->Draw("");
    // TH2F *htemp2 = (TH2F*)c1->GetPrimitive("htemp"); 
    hist3->SetTitle("All Photon Energy Spectrom Per 50 keV ; Energy (keV) ; Photons");
    hist3->SetLineColor(kBlack);
    hist3->SetLineWidth(2);
    Aphoton_source->Draw("y:x","","sameLP");
   auto legend = new TLegend(0.1,0.7,0.48,0.9);
   legend->SetHeader("","C"); // option "C" allows to center the header
   legend->AddEntry(Aphoton_source,"Mohan 1987");
   legend->SetBorderSize(0);
   legend->Draw();
    // hist1->Draw();
    // hist1->SetLineColor(kBlue);
    // hist1->SetLineWidth(2);
    // hist1->SetTitle("Electron Energy Spectrom Per 50 keV ; Energy (keV) ; Electron");
        // c1->cd(2);
    
    // hist2->Draw();
    // hist2->SetLineColor(kRed);
    // hist2->SetLineWidth(2);
    // hist2->SetTitle("Scattered Photon Energy Spectrom Per 50 keV ; Energy (keV) ; Photon");

        c1->cd(2);
    Sphoton_source->Draw("y:x","","LP");
    TH2F *htemp = (TH2F*)c1->cd(2)->GetPrimitive("htemp"); 
    htemp->SetTitle("Scattered Photon Energy Spectrom Per 50 keV ; Energy (keV) ; Photons");
    hist2->Draw("same");
    hist2->SetLineColor(kBlack);
    hist2->SetLineWidth(2);
    auto legend3 = new TLegend(0.1,0.7,0.48,0.9);
    legend3->SetHeader("","C"); // option "C" allows to center the header
    legend3->AddEntry(Sphoton_source,"Mohan 1987");
    legend3->SetBorderSize(0);
    legend3->Draw();
    gPad->Update() ;
    // hist2->SetTitle("ALL Photon Energy Spectrom Per 50 keV ; Energy (keV) ; Photons");
    // hist2->SetTitle("Scattered Photon Energy Spectrom Per 50 keV ; Energy (keV) ; Photon");



  
   




 


 
}

