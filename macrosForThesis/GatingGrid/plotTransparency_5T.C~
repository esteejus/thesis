



void plotTransparency()
{

  //Fall 2015 0T magnetic field

  /*
  vector<double> xgarf = {20,10,0,-10,-20,-30,-41.07,-56.23,-70.11,-83.1,-94.48,-103.27,-114.8,-124.38,-132.76};
  vector<double> xdata = {-41.07,-56.23,-70.11,-83.1,-94.48,-103.27,-114.8,-124.38,-132.76,-142.54,-152.33};

  vector<double> ydata = {.6778,.8042,.8664,.9159,.9507,.9727,1.001,1.008,1.014,.99926,.99926};
  vector<double> ygarf = {0,.124,.236,.374,.4845,.583,.7,.8185,.877,.9405,.9668,.9855,.996,1,1};
  */


  vector<double> data_v = {-142.54, -132.76, -124.38, -114.8, -103.27, -94.48, -83.1, -70.11, -56.23, -41.07};
  vector<double> data_trans = {0.999267, 1.014835,1.008425,1.001099,0.972711,0.950733,0.915934,0.866484,0.804212, 0.677839};

  vector<double> garf_v =  {-132.76,-124.38,-114.8, -103.27, -94.48, -83.1, -70.11, -56.23, -41.07, -30, -20, -10, 0, 10, 20};
  vector<double> garf_trans =  {1, 1, 0.996, 0.9855, 0.968, 0.9405, 0.877, 0.8185, 0.7, 0.583, 0.4845, 0.374, 0.236, 0.124, 0};
  vector<double> garf_v_err =  {.0 ,.0 , .0 , .0 , .0, .0, .0, .0, .0, .0, .0, .0, .0, .0, .0};
  vector<double> garf_trans_err =  {.03 ,.03 , .03 , .03 , .03, .03, .03, .03, .03, .03, .03, .03, .03, .03, .03};

  TGraph *data_avg = new TGraph(data_v.size(),data_v.data(),data_trans.data());
  TGraphErrors *garf_avg = new TGraphErrors(garf_v.size(),garf_v.data(),garf_trans.data(),garf_v_err.data(),garf_trans_err.data());


  data_avg->SetMarkerColor(2);

  data_avg->SetMarkerStyle(20);
  garf_avg->SetMarkerStyle(20);

  data_avg->SetMarkerSize(1.5);
  garf_avg->SetMarkerSize(1.5);

  //  garf_avg->GetXaxis()->SetRangeUser(-150,-20);
  garf_avg->Draw("APO");
  data_avg->Draw("same PO");

}
