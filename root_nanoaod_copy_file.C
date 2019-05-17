
void root_nanoaod_copy_file(){
   TFile *oldfile = new TFile("nano-TTLHE-2017-09-04-uncompressed.root");
   TTree *oldtree = (TTree*)oldfile->Get("Events");
   TFile *newfile = new TFile("nanoad_copy_file.root","recreate");
   // LZ4 -> 404
   newfile->SetCompressionAlgorithm(4);
   newfile->SetCompressionLevel(4);
   Long64_t nentries = oldtree->GetEntries();
   fprintf(stderr,"Total created %lld\n",nentries);
   TTree *newtree = oldtree->CopyTree("");
   newfile->Write();
   newfile->Close();
}
