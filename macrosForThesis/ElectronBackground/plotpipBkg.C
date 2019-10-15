
void plotpipBkg()
{
  //  TFile *f = TFile::Open("data.root");
  //  TH1D *data = (TH1D *)f->Get("data");
  
  TFile *m = TFile::Open("MChistPID_ep_newBin.root");
  TH2D *pid = (TH2D *)m->Get("histPIDLog");
  auto mc = pid->ProjectionX();

  vector<double> bins = {40,60,62,64,66,68,70,72,74,76,78,80,82,84,86,88,90,92,94,96,98,100,102,104,106,108,110,112,116,120,124,128};
  
  vector<double> counts = {57.2325,56.671,50.1775,52.5155,50.471,56.7945,51.942,48.4285,56.2485,59.8715,39.3344,45.64655,53.3265,54.042,54.35,40.4222,45.58955,44.79085,44.9633,48.83245,48.9515,50.7965,44.70755,43.54125,42.15, 45.21,31.98,42.72,35.59,32.48,34.74,22};

  //  vector<double> counts = {57.2325,56.671,50.1775,52.5155,50.471,56.7945,51.942,48.4285,56.2485,59.8715,39.3344,45.64655,53.3265,54.042,54.35,40.4222,45.58955,44.79085,44.9633,48.83245,48.9515,50.7965,44.70755,43.54125,49.47665,60.0325,69.695,50.62225,36.4035,39.39875,27.35875,40.11925};

  //  vector<double> counts = {165.508,201.849,212.804,269.342,213.14,248.459,213.508,210.374,220.89,216.526,202.761,205.096,221.826,177.13,180.191,198.889,190.988,185.62};

  //  vector<double> bins = {40,60,62,64,66,68,70,72,74,76,78,80,82,84,86,88,90,92,94,96,98,100,102,104,106,108,110,112,116,120,124,128};

  //  vector<double> counts =  {57.2325,56.671,50.1775,52.5155,50.471,56.7945,51.942,48.4285,56.2485,59.8715,39.3344,45.64655,53.3265,54.042,54.35,40.4222,45.58955,44.79085,44.9633,48.83245,48.9515,50.7965,44.70755,43.54125,49.47665,60.0325,69.695,50.62225,36.4035,39.39875,27.35875,40.11925};

  //  vector<double> counts = {277.3305,477.513,381.4005,359.7745,373.4145,357.7665,397.8325,409.8405,356.5685,374.5395,267.12,290.3515,281.2065,323.189,271.7935,232.276,196.334,160.4055,193.13,162.38,167.6515,171.4145,140.5485,103.9975,132.4455,122.962,108.3605,120.99525,90.39325,74.15975,75.83675,81.27};

    cout<<bins.size()<<" "<<counts.size()<<endl;

  TH1D *data = new TH1D("data","data",bins.size()-1,bins.data());
  //  TH1D *data = new TH1D("data","data",40,-200,0);
  for(int i = 1; i <= counts.size(); i++)
    {
      //      int bin = data->GetXaxis()->FindBin(x_vec.at(i-1));
      //      cout<<bin<<endl;
      data->SetBinContent(i,counts.at(i-1));
      cout<<bins.at(i-1)<<" "<<counts.at(i-1)<<endl;
    }

  int bin_l_d = data->GetXaxis()->FindBin(60);
  int bin_h_d = data->GetXaxis()->FindBin(120);

  int bin_l_m = mc->GetXaxis()->FindBin(60);
  int bin_h_m = mc->GetXaxis()->FindBin(120);

  cout<<"data "<<bin_l_d<<" "<<bin_h_d<<endl;
  cout<<bin_l_m<<" "<<bin_h_m<<endl;
  cout<<data->Integral(bin_l_d,bin_h_d)<<endl;
  cout<<  mc->Integral(bin_l_m,bin_h_m)<<endl;
  mc->Scale(1.,"width");
  mc->Scale(data->Integral(bin_l_d,bin_h_d)/mc->Integral(bin_l_m,bin_h_m));

  data->SetMarkerColor(4);
  mc->SetLineColor(2);
  
  mc->GetXaxis()->SetRangeUser(0,500);
  mc->Draw();
  data->Draw("same E");


}
