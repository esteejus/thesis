
void fitGaus()
{
  //  TFile *f = TFile::Open("mcpim_DBhist.root");
  //  TH2D *hist = (TH2D *)f->Get("histPID");
  TFile *f = TFile::Open("pimfile_merge.root");
  TH2D *hist = (TH2D *)f->Get("pid");

  hist->RebinX(20);
  //  double start_bin = -7.5;
  //  int bin = hist->GetXaxis()->FindBin(start_bin);
  TF1 *g = new TF1("g","[0]*TMath::Gaus(x,[1],[2],true)",-3,10);

  TH1D *mom_dist = hist->ProjectionX();

  vector<double> x_vec,mean_vec,sigma_vec;
  vector<double> error_m_x, error_s_x, error_m_y, error_s_y;

  TCanvas *c1 = new TCanvas("c1","c1",1);
  int bin_low = 0;
  int bin_max = hist->GetNbinsX();
  cout<<"Bin max "<<bin_max<<endl;
  //  for(int i = 1; i <= bin_max; i++)
  for(int i = bin_max; i > 0; i--)
    {
      TH1D *slice_h = hist->ProjectionY("py",i,i);

      //      if(i == 45)
      //      if(i==28)
	g->SetParameters(slice_h->GetEntries(),slice_h->GetMean(),slice_h->GetStdDev());

      slice_h->Fit(g,"q");
      cout<<"bin "<<i<<"Mean value "<<-hist->GetXaxis()->GetBinCenter(i)<<endl;
      x_vec.push_back(hist->GetXaxis()->GetBinCenter(i));
      mean_vec.push_back(g->GetParameter(1));
      sigma_vec.push_back(g->GetParameter(2));
      //      slice_h->GetXaxis()->SetRangeUser(0,200);
      //      slice_h->Draw();
      //      c1->WaitPrimitive();      
    }
  
  for(int i = 0; i <x_vec.size(); i++)
    cout<<x_vec.at(i)<<" "<<mean_vec.at(i)<<" "<<sigma_vec.at(i)<<endl;
  
  TGraphErrors *mean_g = new TGraphErrors(x_vec.size(),x_vec.data(),mean_vec.data());
  TGraphErrors *sigma_g = new TGraphErrors(x_vec.size(),x_vec.data(),sigma_vec.data());  
  mean_g->SetName("mean_g");
  sigma_g->SetName("sigma_g");  

  sigma_g->SetMarkerStyle(20);
  sigma_g->SetMarkerSize(2);
  sigma_g->GetYaxis()->SetRangeUser(-20,300);
  sigma_g->SetTitle("sigma");

  sigma_g->SetMarkerStyle(20);
  sigma_g->SetMarkerSize(2);
  sigma_g->Draw("APO");
  //  sigma_g->Fit("pol3","","",-510,-50);
  
  TCanvas *c2 = new TCanvas("c2","c2",1);
  mean_g->SetTitle("mean");
  mean_g->SetMarkerStyle(20);
  mean_g->SetMarkerSize(2);
  mean_g->GetYaxis()->SetRangeUser(0,400);
  mean_g->Draw("APO");
  //  mean_g->Fit("pol8","","",-500,-43);

  cout<<"Mean "<<mean_g->Eval(-82.5)<<endl;
  cout<<"Sigma "<<sigma_g->Eval(-82.5)<<endl;

  TFile *out = new TFile("mc_dedx.root","RECREATE");
  mean_g->Write();
  sigma_g->Write();
  
  
}
