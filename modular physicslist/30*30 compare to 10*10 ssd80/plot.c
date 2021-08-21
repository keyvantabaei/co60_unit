#include <TTree.h>
#include <TFile.h>
#include <TH1D.h>

void plot() 
{         


  TFile* r1 = new TFile("/home/k1/k1-Files/Programing/Geant4-workshop/reports/5/modular physicslist/30*30 compare to 10*10 ssd80/1010result.root");
  TFile* r2 = new TFile("/home/k1/k1-Files/Programing/Geant4-workshop/reports/5/modular physicslist/30*30 compare to 10*10 ssd80/3535result.root");             
   
      
      TTree *p3535 = new TTree("ntuple","data from ascii file");
      Long64_t LAphoton_source = p3535->ReadFile("scatteredphoton-ssd80-3535-0-10cm.csv","x:y");
      p3535->SetMarkerStyle(26);
      p3535->SetLineColor(kBlack);
      p3535->SetLineWidth(2);
          
      TTree *p1010 = new TTree("ntuple","data from ascii file");
      Long64_t Lp2020 = p1010->ReadFile("scatteredphoton-ssd80-1010-0-10cm.csv","x:y");
      p1010->SetMarkerStyle(24);
      p1010->SetLineColor(kBlack);
      p1010->SetLineWidth(2);
      

  TCanvas* c1 = new TCanvas("c1", "  ");

   
   
  TH1D* hist1 = (TH1D*)r1->Get("SPH");
  TH1D* hist2 = (TH1D*)r2->Get("SPH");

  


        

    p1010->Draw("y:x",""," LP");
    TH2F *htemp = (TH2F*)c1->GetPrimitive("htemp"); 
    htemp->SetTitle("Scattered Photon Energy Spectrom Per 50 keV ; Energy (keV) ; Photons");
    p3535->Draw("y:x","","same LP");

    hist1->Draw("same PH");
    hist1->SetMarkerStyle(20);
    hist1->SetLineColor(kBlack);
    hist1->SetLineWidth(2);
    
    hist2->Draw("SAME PH");
    hist2->SetMarkerStyle(22);
    hist2->SetLineColor(kBlack);
    hist2->SetLineWidth(2);

   auto legend = new TLegend(0.1,0.7,0.48,0.9);
   legend->SetHeader("","C"); // option "C" allows to center the header
   legend->AddEntry(p1010,"Mohan 1987 10x10 cm^{2}_{}");
   legend->AddEntry(p3535,"Mohan 1987 35x35 cm^{2}_{}");
   legend->AddEntry(hist1,"10x10 cm^{2}_{}");
   legend->AddEntry(hist2,"35x35 cm^{2}_{}");
   legend->SetBorderSize(0);
   legend->Draw();

  c1->cd();
  c1->Update(); 


 


 
}

