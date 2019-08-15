void decompress(const char *filename){
  int nb = 0;
  TStopwatch timer;
  timer.Start();
  TFile *hfile = new TFile(filename);
  auto tree = (TTree*)hfile->Get("canSort");
  auto nentries = (int)tree->GetEntries();
  for (int ev = 0; ev < nentries; ++ev) {
    nb += tree->GetEntry(ev);
  }
  timer.Stop();
  Float_t mbytes = 0.000001*nb;
  Double_t rtime = timer.RealTime();
  Double_t ctime = timer.CpuTime();
  printf("You read %f Mbytes/Realtime seconds\n",mbytes/rtime);
  printf("You read %f Mbytes/Cputime seconds\n",mbytes/ctime);
  hfile->Close();
}
