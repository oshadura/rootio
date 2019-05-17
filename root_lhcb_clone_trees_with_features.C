void root_lhcb_clone_trees_with_features(){
   TFile *oldfile = new TFile("lhcb_B2ppKK2011_md_noPIDstrip.root");
   TTree *oldtree = (TTree*)oldfile->Get("TupleB2ppKK/DecayTree");
   TTree *oldtree1 = (TTree*)oldfile->Get("TupleB2ppKPi/DecayTree");
   TTree *oldtree2 = (TTree*)oldfile->Get("TupleB2ppPiPi/DecayTree");
   TFile *newfile = new TFile("copy_lhcb_file.root","recreate");
   Long64_t nentries = oldtree->GetEntries();
   Long64_t nentries1 = oldtree1->GetEntries();
   Long64_t nentries2 = oldtree2->GetEntries();
   //LZ4 -> 404
   newfile->SetCompressionLevel(404);
   // Experimental features, please uncoment next line to test -> kGenerateOffsetMap
   // ROOT::TIOFeatures features;
   //features.Set(ROOT::Experimental::EIOFeatures::kGenerateOffsetMap);
   TTree *newtree = new TTree();
   TTree *newtree1 = new TTree();
   TTree *newtree2 = new TTree();
   //newtree->SetIOFeatures(features);
   //newtree1->SetIOFeatures(features);
   //newtree2->SetIOFeatures(features);
   //bool feature = settings.Test(ROOT::Experimental::EIOFeatures::kGenerateOffsetMap);
   //if !(feature)
   //{
    // return 0;
   //}
   newtree = oldtree->CloneTree();
   newtree1 = oldtree1->CloneTree();
   newtree2 = oldtree2->CloneTree();
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
   delete oldfile;
   delete newfile;
}
