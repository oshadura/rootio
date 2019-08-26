void perftree(){
  TFile* rfile = TFile::Open("nanoad_ttjet_404.root");
  TTree* rtree = (TTree*)rfile->Get("Events");
  Long64_t nentries = rtree->GetEntries();
  TTreePerfStats ps("ioperf",rtree);
  std::cout << "Total Entries: " << nentries << std::endl;
  for (Long64_t i=0; i<nentries ; i++){
    if (i%100 == 0 ){
      std::cout << "... Processed " << i << " entries ..." << std::endl;
    }
    rtree->GetEntry(i);
  }
  ps.SaveAs("perf_404.root");
  ps.Print();
}
