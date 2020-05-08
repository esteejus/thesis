



void plotTransparency_vdiff()
{

  //Spring Commision .5T magnetic field


  vector<double> data_v_0 = {0,5,10,12,14,16};
  vector<double> data_trans_0 = {1,0.887756,0.49,0.342272698,0.203693,0.094557};

  vector<double> garf_v_0 = {0,5,10,12,14,16,18,20};
  vector<double> garf_trans_0 =  {1,0.853,0.47,0.3205,0.182,0.0955,0.039,0};


  vector<double> data_v_5 = {0,5,10,15,20,25,30,35,40,45};
  vector<double> data_trans_5 =  {1,0.955218,0.90509,0.796871,0.664226,0.536177,0.400595,0.243647,0.097689,0.06899};

  vector<double> garf_v_5 = {0,5,10,15,20,25,30,35,40,45,50,55};
  vector<double> garf_trans_5 = {0.998,0.96125,0.9165,0.815,0.69275,0.554,0.36675,0.17975,0.06525,0.0235,0.007,0.002};



  TGraphErrors *data_0 = new TGraphErrors(data_v_0.size(),data_v_0.data(),data_trans_0.data());
  TGraphErrors *garf_0 = new TGraphErrors(garf_v_0.size(),garf_v_0.data(),garf_trans_0.data());

  TGraphErrors *data_5 = new TGraphErrors(data_v_5.size(),data_v_5.data(),data_trans_5.data());
  TGraphErrors *garf_5 = new TGraphErrors(garf_v_5.size(),garf_v_5.data(),garf_trans_5.data());


  data_0->SetMarkerColor(2);
  data_5->SetMarkerColor(2);
  
  data_0->SetMarkerStyle(20);
  garf_0->SetMarkerStyle(20);

  data_5->SetMarkerStyle(22);
  garf_5->SetMarkerStyle(22);

  data_0->SetMarkerSize(1.);
  garf_0->SetMarkerSize(1.);

  data_5->SetMarkerSize(1.);
  garf_5->SetMarkerSize(1.);

  //  garf_5->GetXaxis()->SetRangeUser(-200,-40);
  //  garf_5->GetYaxis()->SetRangeUser(.8,1.05);

  garf_5->Draw("APO");
  data_5->Draw("same PO");

  garf_0->Draw("same PO");
  data_0->Draw("same PO");

}
