

bool myfunction (double i,double j) { return (i<j); }

//void plot_lowvshigh_cocktail(int split_no, int nsplits)
void plot_lowvshigh_cocktail()
{

  TRandom3 *ran = new TRandom3(12345);
  Int_t nbins = 500;
    double p1 = 0;
    double p2 = 5000;
    double dedx1 = 0;
    double dedx2 = 10000;

  gStyle -> SetPadBottomMargin(0.10);
  gStyle -> SetPadLeftMargin(0.11);
  gStyle -> SetPadRightMargin(0.12);
  //  gStyle -> SetTitleFontSize(0.06);
  //  gStyle -> SetOptStat(0);

  bool desat = false;

  auto tree = new TChain("cbmsim");

  for(int i=0;i<=15;++i){
    TString filename = Form("run3211_s%d.reco.develop.1751.c162884.root",i);
    filename = "/mnt/spirit/analysis/estee/SpiRITROOT.develop/macros/data/"+filename;
    tree -> AddFile(filename);
  }

  for(int i=0;i<=22;++i){
    TString filename = Form("run3203_s%d.reco.develop.1751.c162884.root",i);
    filename = "/mnt/spirit/analysis/estee/SpiRITROOT.develop/macros/data/"+filename;
    tree -> AddFile(filename);
  }

  for(int i=0;i<=29;++i){
    TString filename = Form("run3202_s%d.reco.develop.1751.c162884.root",i);
    filename = "/mnt/spirit/analysis/estee/SpiRITROOT.develop/macros/data/"+filename;
    tree -> AddFile(filename);
  }

  for(int i=0;i<=21;++i){
    TString filename = Form("run3196_s%d.reco.develop.1751.c162884.root",i);
    filename = "/mnt/spirit/analysis/estee/SpiRITROOT.develop/macros/data/"+filename;
    tree -> AddFile(filename);
  }

  for(int i=0;i<=20;++i){
    TString filename = Form("run3195_s%d.reco.develop.1751.c162884.root",i);
    filename = "/mnt/spirit/analysis/estee/SpiRITROOT.develop/macros/data/"+filename;
    tree -> AddFile(filename);
  }
  for(int i=0;i<=14;++i){
    TString filename = Form("run3194_s%d.reco.develop.1751.c162884.root",i);
    filename = "/mnt/spirit/analysis/estee/SpiRITROOT.develop/macros/data/"+filename;
    tree -> AddFile(filename);
  }
  for(int i=0;i<=39;++i){
    TString filename = Form("run3193_s%d.reco.develop.1751.c162884.root",i);
    filename = "/mnt/spirit/analysis/estee/SpiRITROOT.develop/macros/data/"+filename;
    tree -> AddFile(filename);
  }
  for(int i=0;i<=22;++i){
    TString filename = Form("run3191_s%d.reco.develop.1751.c162884.root",i);
    filename = "/mnt/spirit/analysis/estee/SpiRITROOT.develop/macros/data/"+filename;
    tree -> AddFile(filename);
  }
  for(int i=0;i<=21;++i){
    TString filename = Form("run3187_s%d.reco.develop.1751.c162884.root",i);
    filename = "/mnt/spirit/analysis/estee/SpiRITROOT.develop/macros/data/"+filename;
    tree -> AddFile(filename);
  }

  TCutG *reg1;
  TCutG *reg2;
  TCutG *reg3;
  TCutG *reg4;
  TFile *cutfile = new TFile("dedxcompare_cuts.root");
  cutfile -> GetObject("reg1",reg1);
  cutfile -> GetObject("reg2",reg2);
  cutfile -> GetObject("reg3",reg3);
  cutfile -> GetObject("reg4",reg4);

  TFile *g = new TFile("dedxcutg.root");
  TCutG *dedxcut;
  g -> GetObject("mycutg",dedxcut);
  
  auto res = new TH1D("res","res",2000,-1000,1000);

    auto histPID_reg1 = new TH2D("histPID_reg1",";p/Z (MeV/Z); dEdx (ADC/mm)",1000,p1,p2,10000,dedx1,dedx2);
    auto histPID_reg2 = new TH2D("histPID_reg2",";p/Z (MeV/Z); dEdx (ADC/mm)",1000,p1,p2,10000,dedx1,dedx2);
    auto histPID_reg3 = new TH2D("histPID_reg3",";p/Z (MeV/Z); dEdx (ADC/mm)",1000,p1,p2,10000,dedx1,dedx2);  //  if(p_cut->IsInside(p,dedx))
    auto histPID_reg4 = new TH2D("histPID_reg4",";p/Z (MeV/Z); dEdx (ADC/mm)",1000,p1,p2,10000,dedx1,dedx2);
    auto histPID_reg = new TH2D("histPID_reg",";p/Z (MeV/Z); dEdx (ADC/mm)",1000,p1,p2,10000,dedx1,dedx2);
    
  TClonesArray *trackArray = nullptr;
  TClonesArray *clusterArray = nullptr;
  TClonesArray *vertexArray = nullptr;
  
  tree -> SetBranchAddress("STRecoTrack", &trackArray);
  tree -> SetBranchAddress("STHitCluster", &clusterArray);
  tree -> SetBranchAddress("STVertex", &vertexArray);
  
  auto lowanode = new TH1D("lowanode","Low anode",500,0,1000);
  auto anode = new TH1D("anode","other anode",500,0,1000);
  auto length_dist = new TH1D("lenght dist ","length dist", 130,0,130);
  
  double dedx_h = 350;
  double bgamma_l = .1;
  double bgamma_h = 1.4;
  int bgamma_p = 20;
  int dedx_p = 200;
  double scale_z = 1.15;//1.15
  double bg_scale = 1;


  auto dedx_compare = new TH2D("dedxcompare","",4000,-10,10000,4000,-10,10000);
  auto histPID = new TH2D("histPID",";p/Z (MeV/Z); dEdx (ADC/mm)",1000,p1,p2,10000,dedx1,dedx2);
  auto histPID_lowanode = new TH2D("histPID_lowanode",";p/Z (MeV/Z); dEdx (ADC/mm)",1000,p1,p2,10000,dedx1,dedx2);
  histPID -> SetTitle("All events");
  histPID -> SetTitleSize(0.04,"xy");
  histPID -> SetTitleOffset(1.4,"y");
  histPID -> SetTitleOffset(1.1,"x");
  histPID -> GetXaxis() -> CenterTitle();
  histPID -> GetYaxis() -> CenterTitle();
  
  Int_t feventID = -1;
  Int_t ftrackID = -1;
  Int_t fpid = -1;
  Double_t fp = -999;
  Double_t fdedx = -999;

  
  auto pidTest = new STPIDTest();
    
  Int_t nEvents = tree -> GetEntries();
  cout<<nEvents<<endl;
 
  
  for (Int_t iEvent = 0; iEvent < nEvents ; ++iEvent)
  {
    double ndf = 0;
    
    if (iEvent % 500 == 0)
      cout << "Event " << iEvent << endl;

    tree -> GetEntry(iEvent);

    Int_t nTracks = trackArray -> GetEntries();

    if(nTracks != 1)
      continue;
    
    for (auto iTrack = 0; iTrack < nTracks; ++iTrack) {
      auto track = (STRecoTrack *) trackArray -> At(iTrack);
      auto pid = track -> GetPID();
      
      //      if (selectPID != STPID::kNon && pid != selectPID) continue;

      auto dedxArray = track -> GetdEdxPointArray();
      //      if (dedxArray -> size() < 20) continue;//20

      length_dist -> Fill(dedxArray -> size());

      auto q = track -> GetCharge();
      auto p =  track -> GetMomentum().Mag()/q;
      auto dedx = track -> GetdEdxWithCut(0,0.7);

      auto mom = track->GetMomentum();
      ndf = track -> GetNumRowClusters() + track -> GetNumLayerClusters();

      double theta = mom.Theta() * TMath::RadToDeg();
      double phi = mom.Phi() * TMath::RadToDeg();

      //      cout<<"Track "<<iTrack<<" ndf "<<ndf<<" dedx "<<dedx<<" mom "<<p<<endl;
      if( !(ndf > 20) )
	continue;
      
	auto clusterIDarray = track -> GetClusterIDArray();
	auto numClusters = clusterIDarray -> size();

	vector <double> l_clust; 
	vector <double> high_clust; 
	vector <double> mid_clust; 
	for (auto iCluster = 0; iCluster < numClusters; iCluster++) {
	  auto cluster = (STHitCluster *) clusterArray -> At(clusterIDarray -> at(iCluster));
	  auto charge = cluster -> GetCharge();
	  auto length = cluster -> GetLength();
	  double dedx_v = charge/length;
          TVector3 cluster_pos = cluster->GetPosition();
	  int layer = (cluster_pos.Z()-6)/12.;

	  
	  //	  if((layer>=91 && layer<=98) || layer>=108){
	  if( layer>=91 && layer<=98 ){
	    l_clust.push_back(dedx_v);
	    lowanode -> Fill(dedx_v);
	  }
	  else if( layer > 98 && layer < 108)
	    mid_clust.push_back(dedx_v);
	  else if( layer <= 90 && layer >= 83 )
	    high_clust.push_back(dedx_v);
	}//cluster

	std::sort(high_clust.begin(),high_clust.end(),myfunction);
	std::sort(l_clust.begin(),l_clust.end(),myfunction);
	int h_vec = .7*high_clust.size();
	int p_vec = .7*l_clust.size();

	high_clust.erase(high_clust.begin()+h_vec,high_clust.end());
	l_clust.erase(l_clust.begin()+p_vec,l_clust.end());

	if(l_clust.size()< 5 && high_clust.size() < 5)
	    {
	      continue;
	    }


	/*	double mean_h = 0.;
	vector<int> high_clust_idx;
	for(int iElem = 0; iElem < high_clust.size(); ++iElem)
	  high_clust_idx.push_back(iElem);

	for(int iElem = 0; iElem < l_clust.size(); ++iElem)
	  {
	    int rand_idx = ran->Integer(high_clust_idx.size());
	    high_clust_idx.erase(high_clust_idx.begin()+rand_idx);
	    mean_h += high_clust.at(rand_idx);
	  }
	mean_h = mean_h/l_clust.size();
*/

	double mean_h = 0.;
	for(int iElem = 0; iElem < high_clust.size(); ++iElem)
	    mean_h += high_clust.at(iElem);
	mean_h = mean_h/high_clust.size();

	double mean = 0.;
	for(int iElem = 0; iElem < l_clust.size(); ++iElem)
	    mean += l_clust.at(iElem);
	mean = mean/l_clust.size();

	if(mean_h <30 )
	  continue;
	
	//if(mid_clust.size()< 7)
	//	if(mean > 1500)
	//	if(iTrack == 13 && iEvent == 42)
	//	  cout<<iEvent<<" "<<iTrack<<"mean "<<mean<<" mean_h "<<mean_h<<" "<<ndf<<" mean ary "<<l_clust.size()<<endl;
	dedx_compare -> Fill(mean,mean_h);//(x,y)
	histPID_lowanode ->Fill(p,mean);
	histPID -> Fill(p, dedx);
	double res_v = mean-dedx;//mean is low gain
	res -> Fill(res_v);
	/*
	if(reg1->IsInside(mean,dedx))
	  histPID_reg1->Fill(p,dedx);
	else if(reg2->IsInside(mean,dedx))
	  histPID_reg2->Fill(p,dedx);
	else if(reg3->IsInside(mean,dedx))
	  histPID_reg3->Fill(p,dedx);
	else if(reg4->IsInside(mean,dedx))
	  histPID_reg4->Fill(p,dedx);
	else
	  histPID_reg->Fill(p,dedx);
	*/
	if(reg1->IsInside(mean,dedx))
	  histPID_reg1->Fill(p,mean);
	else if(reg2->IsInside(mean,dedx))
	  histPID_reg2->Fill(p,mean);
	else if(reg3->IsInside(mean,dedx))
	  histPID_reg3->Fill(p,mean);
	else if(reg4->IsInside(mean,dedx))
	  histPID_reg4->Fill(p,mean);
	else
	  histPID_reg->Fill(p,dedx);
	    
    }//track
  }//event
  
  TFile *output = new TFile("lowvshigh_nodesat_cocktail.root","RECREATE");
  
  auto compare = new TCanvas("comapre","",1);
  compare->SetLogz();
  //  compare->SetLogy();
  //  compare->SetLogx();
  dedx_compare -> GetYaxis() -> SetRangeUser(0,2000);
  dedx_compare -> GetXaxis() -> SetRangeUser(0,2000);
  dedx_compare -> GetYaxis() -> SetTitle("dE/dx High Gain" );
  dedx_compare -> GetXaxis() -> SetTitle("dE/dx Low gain" );
  dedx_compare -> GetXaxis() -> SetTitleSize(.06);;
  dedx_compare -> GetYaxis() -> SetTitleSize(.06);
  dedx_compare -> GetXaxis() -> SetTitleOffset(.7);;
  dedx_compare -> GetYaxis() -> SetTitleOffset(.85);
  dedx_compare -> GetXaxis() -> SetLabelSize(.04);;
  dedx_compare -> GetYaxis() -> SetLabelSize(.04);;
  dedx_compare -> GetXaxis() -> CenterTitle();
  dedx_compare -> GetYaxis() -> CenterTitle();
  dedx_compare -> Draw("colz");
  compare->SaveAs("lowvshigh.png");

  auto pid = new TCanvas("pid","",1);
    histPID->Draw("colz");
  auto pid_2 = new TCanvas("pid_2","",1);
    histPID_lowanode->Draw("colz");

    auto pid_reg = new TCanvas("pid_reg","",1);

    histPID_reg1->SetMarkerSize(.1);
    histPID_reg2->SetMarkerSize(.1);
    histPID_reg3->SetMarkerSize(.1);
    histPID_reg4->SetMarkerSize(.1);

    histPID_reg1->SetMarkerStyle(20);
    histPID_reg2->SetMarkerStyle(20);
    histPID_reg3->SetMarkerStyle(20);
    histPID_reg4->SetMarkerStyle(20);

    histPID_reg2->SetMarkerColor(2);
    histPID_reg3->SetMarkerColor(3);
    histPID_reg4->SetMarkerColor(4);
    histPID_reg->Draw("colz");
    histPID_reg1->Draw("same");
    histPID_reg2->Draw("same");
    histPID_reg3->Draw("same");
    histPID_reg4->Draw("same");
	    
    histPID_reg->Write();
    histPID_reg1->Write();
    histPID_reg2->Write();
    histPID_reg3->Write();
    histPID_reg4->Write();
    histPID->Write();
    histPID_lowanode->Write();
    dedx_compare->Write();

    auto res_c = new TCanvas("res_c","",1);
    res -> Draw();
    res -> Write();
    res_c -> SaveAs("residue.png");
}

