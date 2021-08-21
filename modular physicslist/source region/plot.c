#include <TTree.h>
#include <TFile.h>
#include <TH1D.h>

void plot() 
{         


  TFile* r1 = new TFile("/home/k1/k1-Files/Programing/Geant4-workshop/reports/5/modular physicslist/source region/result.root");

   
      
      
      TTree *electron_source = new TTree("ntuple","data from ascii file");
      Long64_t Lelectron_source = electron_source->ReadFile("electron-source.csv","x:y");
      electron_source->SetMarkerStyle(26);
      electron_source->SetLineColor(kBlack);
      electron_source->SetLineWidth(2);




      TTree *Sphoton_source = new TTree("ntuple","data from ascii file");
      Long64_t LSphoton_source = Sphoton_source->ReadFile("scatteredphoton-source.csv","x:y");
      Sphoton_source->SetMarkerStyle(26);
      Sphoton_source->SetLineColor(kBlack);
      Sphoton_source->SetLineWidth(2);


      TTree *Aphoton_source = new TTree("ntuple","data from ascii file");
      Long64_t LAphoton_source = Aphoton_source->ReadFile("allphoton-source.csv","x:y");
      Aphoton_source->SetMarkerStyle(26);
      Aphoton_source->SetLineColor(kBlack);
      Aphoton_source->SetLineWidth(2);
          
          

  TCanvas* c1 = new TCanvas("c1", "  ");

   c1->Divide(2,2);
   
  TH1D* hist3 = (TH1D*)r1->Get("APH");
  TH1D* hist2 = (TH1D*)r1->Get("SPH");
  TH1D* hist1 = (TH1D*)r1->Get("E");
  

c1->cd(1);
        
    hist1->SetLineColor(kBlack);
    hist1->SetMarkerStyle(24);
    hist1->SetLineWidth(2);
    hist1->Draw("");
    hist1->SetTitle("Electron Energy Spectrom Per 50 keV ; Energy (keV) ; Electrons");
    electron_source->Draw("y:x","","same LP");

    auto legend = new TLegend(0.1,0.7,0.48,0.9);
    legend->SetHeader("","C");
    legend->AddEntry(electron_source,"Mohan 1987" );
    legend->SetBorderSize(0);
    legend->Draw();


    c1->cd(2);
    Sphoton_source->Draw("y:x","","LP");
    TH2F *htemp = (TH2F*)c1->cd(2)->GetPrimitive("htemp"); 
    htemp->SetTitle("Scattered Photon Energy Spectrom Per 50 keV ; Energy (keV) ; Photons");
    hist2->SetLineColor(kBlack);
    hist2->SetMarkerStyle(24);
    hist2->SetLineWidth(2);
    hist2->Draw("same");


    auto legend2 = new TLegend(0.1,0.7,0.48,0.9);
    legend2->SetHeader("","C"); 
    legend2->AddEntry(Sphoton_source,"Mohan 1987" );
    legend2->SetBorderSize(0);
    legend2->Draw();

    gPad->Update() ;

    c1->cd(3);
    hist3->SetLineColor(kBlack);
    hist3->SetLineWidth(2);
    hist3->Draw();
    hist3->SetTitle("All Photon Energy Spectrom Per 50 keV ; Energy (keV) ; Photons");
    Aphoton_source->Draw("y:x","","same LP");

   
    auto legend3 = new TLegend(0.1,0.7,0.48,0.9);
    legend3->SetHeader("","C"); 
    legend3->AddEntry(Aphoton_source,"Mohan 1987" );
    legend3->SetBorderSize(0);
    legend3->Draw();
    gPad->Update() ;




 


 
}

