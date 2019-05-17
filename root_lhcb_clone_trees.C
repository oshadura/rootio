void root_lhcb_clone_trees(){
   TFile *oldfile = new TFile("lhcb_B2ppKK2011_md_noPIDstrip.root");
   TTree *oldtree = (TTree*)oldfile->Get("TupleB2ppKK/DecayTree");
   TTree *oldtree1 = (TTree*)oldfile->Get("TupleB2ppKPi/DecayTree");
   TTree *oldtree2 = (TTree*)oldfile->Get("TupleB2ppPiPi/DecayTree");
   TFile *newfile = new TFile("copy_lhcb_file.root","recreate");
   // LZ4 -> 404
   newfile->SetCompressionLevel(404);
   Long64_t nentries = oldtree->GetEntries();
   fprintf(stderr,"Total created %lld\n",nentries);
   Long64_t nentries1 = oldtree1->GetEntries();
   fprintf(stderr,"Total created %lld\n",nentries1);
   Long64_t nentries2 = oldtree2->GetEntries();
   fprintf(stderr,"Total created %lld\n",nentries2);
   TTree *newtree = oldtree->CloneTree();
   TTree *newtree1 = oldtree1->CloneTree();
   TTree *newtree2 = oldtree2->CloneTree();
   for (Long64_t i = 0;i < nentries; ++i) {
      oldtree->GetEntry(i);
      newtree->Fill();
   }
   for (Long64_t i = 0;i < nentries1; ++i) {
      oldtree1->GetEntry(i);
      newtree1->Fill();
   }
   for (Long64_t i = 0;i < nentries2; ++i) {
      oldtree2->GetEntry(i);
      newtree2->Fill();
   }
   newtree->Print();
   newtree1->Print();
   newtree2->Print();
   newfile->Write();
}
