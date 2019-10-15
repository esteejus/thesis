

void fitGaus()
{
  TFile *f = TFile::Open("MChistPID_eline_newBins.root");
  TH2D *hist = (TH2D *)f->Get("histPIDLog");
  //  hist->Rebin(5);
  //  double start_bin = -7.5;
  //  int bin = hist->GetXaxis()->FindBin(start_bin);
  TF1 *g = new TF1("g","[0]*TMath::Gaus(x,[1],[2],true)",-3,10);

  TH1D *mom_dist = hist->ProjectionX();

  vector<double> lnx_vec, x_vec,mean_vec,sigma_vec, lnmean_vec;

  int bin_low = 5;
  int bin_max = 50;
  for(int i = bin_low; i <= bin_max; i++)
    {
      TH1D *slice = hist->ProjectionY("py",i,i);
      g->SetParameters(slice->GetEntries(),slice->GetMean(),slice->GetStdDev());

      slice->Fit(g,"q");
      //  slice->Draw();
      //  cout<<hist->GetXaxis()->GetBinCenter(i)<<" "<<g->GetParameter(1)<<endl;
      
      if(bin_low == i)
	continue;
      
      if(g->GetParameter(2) < 0)
	continue;
      
      lnx_vec.push_back(log(hist->GetXaxis()->GetBinCenter(i)));
      x_vec.push_back(hist->GetXaxis()->GetBinCenter(i));
      mean_vec.push_back(g->GetParameter(1));
      sigma_vec.push_back(g->GetParameter(2));
      lnmean_vec.push_back(log(g->GetParameter(2)));

    }

  vector<double> data_x     = { -72.5, -67.5, -62.5, -57.5, - 52.5, -47.5, -42.5, -37.5, -32.5};
  vector<double> data_sigma = { .12926, .1155, .1129, .12988, .135, .139, .1428, .14845, .1687};
  vector<double> data_mean  = { -1.006, -1.129, -1.284, -1.44, -1.627, -1.831, -2.067, -2.309, -2.584};
  
  TGraph *data_mean_g = new TGraph(data_x.size(), data_x.data(),data_mean.data());
  TGraph *data_sigma_g = new TGraph(data_x.size(), data_x.data(),data_sigma.data());
  
  TGraph *mean_g = new TGraph(x_vec.size(),x_vec.data(),mean_vec.data());
  TGraph *sigma_g = new TGraph(x_vec.size(),x_vec.data(),sigma_vec.data());  

  data_mean_g ->SetMarkerStyle(20);
  data_mean_g ->SetMarkerSize(2);
  data_mean_g ->SetMarkerColor(4);
  
  data_sigma_g ->SetMarkerStyle(20);
  data_sigma_g ->SetMarkerSize(2);
  data_sigma_g ->SetMarkerColor(4);

  sigma_g->SetMarkerStyle(20);
  sigma_g->SetMarkerSize(2);
  sigma_g->GetYaxis()->SetRangeUser(0,.2);


  sigma_g->SetMarkerStyle(20);
  sigma_g->SetMarkerSize(2);
  sigma_g->Draw("APO");
  sigma_g->Fit("pol3","","",-510,-50);
  data_sigma_g->Draw("same PO");
  
  TCanvas *c2 = new TCanvas("c2","c2",1);
  mean_g->SetMarkerStyle(20);
  mean_g->SetMarkerSize(2);
  mean_g->GetYaxis()->SetRangeUser(-3.5,1);
  mean_g->Draw("APO");
  mean_g->Fit("pol8","","",-500,-43);
  data_mean_g->Draw("same PO");

  cout<<"Mean "<<mean_g->Eval(-82.5)<<endl;
  cout<<"Sigma "<<sigma_g->Eval(-82.5)<<endl;

  
}
