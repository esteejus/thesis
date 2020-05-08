



void plotTransparency_5T()
{

  //Spring Commision .5T magnetic field

  
  vector<double> data_v =   {-170.98, -164.98, -145.9, -136.54, -127.16, -119.14, -114.9, -110.06, -90.5, -79.6, -53.86, -39.34};
  vector<double> data_trans =   {1, 0.999794, 0.998232, 0.995282, 0.980169, 0.954406, 0.942936, 0.932959, 0.910684, 0.901025, 0.873159, 0.844473};
  vector<double> data_v_err = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
  //  vector<double> data_trans_err = {0.033, 0.034, 0.047, 0.025, 0.029, 0.0327, 0.0303, 0.031, 0.029, 0.037, 0.0302, 0.073, 0.0348};
  vector<double> data_trans_err = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};


  vector<double> garf_v =    {-180, -170, -160, -152.33, -142.55, -132.76, -124.38, -114.84, -103.27, -94.48, 0, 10, 20};
  vector<double> garf_trans =    {0.9975, 0.99525, 0.99375, 0.9945, 0.9855, 0.97975, 0.96725, 0.95275, 0.93275, 0.929, 0.67025, 0.574,0};
  vector<double> garf_v_err =  { .0, .0, .0, .0, .0, .0, .0, .0, .0, .0, .0, .0, .0};
  vector<double> garf_trans_err =  {.02, .02, .02, .02, .02, .02, .02, .02, .02, .02, .02, .02, .02};

  TGraphErrors *data_avg = new TGraphErrors(data_v.size(),data_v.data(),data_trans.data(),data_v_err.data(),data_trans_err.data());
  TGraphErrors *garf_avg = new TGraphErrors(garf_v.size(),garf_v.data(),garf_trans.data(),garf_v_err.data(),garf_trans_err.data());


  data_avg->SetMarkerColor(2);

  data_avg->SetMarkerStyle(20);
  garf_avg->SetMarkerStyle(20);

  data_avg->SetMarkerSize(1.5);
  garf_avg->SetMarkerSize(1.5);

  garf_avg->GetXaxis()->SetRangeUser(-200,-40);
  garf_avg->GetYaxis()->SetRangeUser(.8,1.05);

  garf_avg->Draw("APO");
  data_avg->Draw("same PO");

}
