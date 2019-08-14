void perf_tree(){ 
  TFile* rfile = TFile::Open("test.root");
  TTree* rtree = (TTree*)rfile->Get("Events");
  Long64_t nentries = rtree->GetEntries();
  TFile* wfile = TFile::Open("copytree.root","RECREATE");
  TTree* wtree = rtree->CloneTree(0); 
  TTreePerfStats* ioperf = new TTreePerfStats("Events", wtree);
  for(Long64_t i; i<nentries; ++i){
      rtree->GetEntry(i);
      wtree->Fill();
  }
  wtree->Write();
  ioperf->Print();
  wfile->Close();
  rfile->Close();
}
