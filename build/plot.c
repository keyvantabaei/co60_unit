#include <TTree.h>
#include <TFile.h>
#include <TH1D.h>

void plot() 
{         


  TFile* r1 = new TFile("/home/k1/k1-Files/Programing/Geant4-workshop/reports/5/modular physicslist/30*30 compare to 10*10 ssd80/1010result.root");
  TFile* r2 = new TFile("/home/k1/k1-Files/Programing/Geant4-workshop/reports/5/modular physicslist/30*30 compare to 10*10 ssd80/3535result.root");             
   
      
      
      

  TCanvas* c1 = new TCanvas("c1", "  ");

   
   
  TH1D* hist1 = (TH1D*)r1->Get("APH");
  TH1D* hist2 = (TH1D*)r2->Get("APH");

  


        
    hist4->Draw();
    hist4->SetLineColor(kBlue);
    hist4->SetLineWidth(2);
    
    hist5->Draw("SAME");
    hist5->SetLineColor(kRed);
    hist5->SetLineWidth(2);
    

    
   hist4->SetTitle("Scattered Photon Energy Spectrom Per 50 keV ; Energy (keV) ; Photons");
  
   
   auto legend = new TLegend(0.1,0.7,0.48,0.9);
   legend->SetHeader("","C"); // option "C" allows to center the header
   legend->AddEntry(hist1,"5x5   field size ","l");
   legend->AddEntry(hist2,"7x7   field size ","l");

   legend->Draw();

  c1->cd();
  c1->Update(); 


 


 
}

