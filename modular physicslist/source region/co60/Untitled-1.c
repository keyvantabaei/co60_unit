
   TTree *secondscatter = new TTree("ntuple","data from ascii file");
      Long64_t Lsecondscatter = secondscatter->ReadFile("secondscatter.csv","x:y");


   TTree *multiplescatter = new TTree("ntuple","data from ascii file");
      Long64_t Lmultiplescatter = multiplescatter->ReadFile("multiplescatter.csv","x:y");


   TTree *brem = new TTree("ntuple","data from ascii file");
      Long64_t Lbrem = brem->ReadFile("brem.csv","x:y");
total->SetMarkerStyle(26);
primary->SetMarkerStyle(26);
firstscatter->SetMarkerStyle(26)

_Primary->SetLineColor(kBlack);
_First->SetLineColor(kBlack);
_Second->SetLineColor(kBlack);

primary->Draw("y:x","","PA");
