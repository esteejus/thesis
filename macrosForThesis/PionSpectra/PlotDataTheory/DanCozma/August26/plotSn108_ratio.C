


void plotSn108_ratio()
{
  TF1 *fit = new TF1("fit","[0]*TMath::Exp([1]*x + [2]*pow(x,[3]))",0,275);
  fit->SetParameters(12,-1e-2,-1e-6,2);


  vector<double> x = {  5.00,15.00,25.00,35.00,45.00,55.00,65.00,75.00,85.00,95.00,105.00,115.00,125.00,135.00,145.00,155.00,170.00,190.00,220.00,270.00};
  vector<double> ex = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  

  vector<double> sim1_y = { 5.14,4.26,3.99,3.28,2.67,2.19,1.89,1.60,1.46,1.19,1.21,1.09,1.04,0.97,0.94,0.86,0.78,0.76,0.64,0.64};
  vector<double> sim1_ey = {   0.17,0.11,0.10,0.07,0.06,0.05,0.04,0.04,0.04,0.03,0.04,0.04,0.04,0.04,0.04,0.04,0.03,0.04,0.04,0.05};


  vector<double> sim2_y = {   5.14,4.36,3.92,3.20,2.77,2.21,1.81,1.54,1.34,1.32,1.16,1.04,1.00,0.85,0.83,0.77,0.76,0.66,0.60,0.59};
  vector<double> sim2_ey = {   0.17,0.12,0.09,0.07,0.06,0.05,0.04,0.04,0.03,0.04,0.03,0.03,0.04,0.03,0.04,0.04,0.03,0.03,0.03,0.05};


  vector<double> sim3_y = {   5.36,4.48,4.13,3.49,2.83,2.27,1.87,1.66,1.41,1.32,1.09,1.07,1.00,0.87,0.76,0.76,0.70,0.63,0.55,0.45};
  vector<double> sim3_ey = {   0.19,0.12,0.10,0.08,0.06,0.05,0.04,0.04,0.04,0.04,0.03,0.03,0.04,0.03,0.03,0.04,0.03,0.03,0.03,0.03};


  vector<double> sim4_y = {   5.12,4.45,3.61,3.03,2.54,2.08,1.81,1.56,1.42,1.33,1.28,1.16,1.05,1.02,1.02,0.87,0.89,0.73,0.81,0.75};
  vector<double> sim4_ey = {   0.16,0.11,0.08,0.06,0.05,0.04,0.04,0.04,0.04,0.04,0.04,0.04,0.04,0.04,0.05,0.04,0.04,0.04,0.04,0.06};


  vector<double> sim5_y = {   5.51,4.42,3.89,3.24,2.64,2.23,1.85,1.68,1.46,1.33,1.22,1.15,1.10,0.99,0.92,0.88,0.83,0.76,0.69,0.63};
  vector<double> sim5_ey = {   0.18,0.12,0.09,0.07,0.06,0.05,0.04,0.04,0.04,0.04,0.04,0.04,0.04,0.04,0.04,0.04,0.03,0.04,0.04,0.05};


  vector<double> sim6_y = {   5.05,4.40,3.88,3.45,2.76,2.28,1.87,1.68,1.48,1.36,1.16,1.12,1.06,0.93,0.93,0.87,0.77,0.76,0.69,0.51};
  vector<double> sim6_ey = {   0.17,0.12,0.09,0.08,0.06,0.05,0.04,0.04,0.04,0.04,0.03,0.04,0.04,0.04,0.04,0.04,0.03,0.04,0.03,0.04};


  vector<double> sim7_y = {   4.96,4.14,3.63,2.99,2.42,2.03,1.64,1.60,1.44,1.34,1.27,1.16,1.12,1.09,1.03,0.95,0.99,0.81,0.88,0.75};
  vector<double> sim7_ey = {   0.14,0.10,0.08,0.06,0.05,0.04,0.03,0.04,0.04,0.04,0.04,0.04,0.04,0.04,0.05,0.05,0.04,0.04,0.05,0.05};


  vector<double> sim8_y = {   5.15,4.24,3.86,3.28,2.61,2.13,1.81,1.67,1.47,1.38,1.30,1.26,1.12,1.07,0.99,0.96,0.86,0.81,0.68,0.67};
  vector<double> sim8_ey = {   0.16,0.11,0.09,0.07,0.05,0.04,0.04,0.04,0.04,0.04,0.04,0.04,0.04,0.04,0.04,0.05,0.03,0.04,0.03,0.05};


  vector<double> sim9_y = {  5.29,4.56,3.93,3.47,2.73,2.23,1.91,1.70,1.50,1.37,1.28,1.17,1.11,1.02,0.98,0.98,0.88,0.78,0.77,0.65};
  vector<double> sim9_ey = {  0.17,0.12,0.09,0.08,0.06,0.05,0.04,0.04,0.04,0.04,0.04,0.04,0.04,0.04,0.04,0.05,0.03,0.04,0.04,0.05};

  TGraphErrors *sim1_g = new TGraphErrors(x.size(),x.data(),sim1_y.data(),ex.data(),sim1_ey.data() );
  TGraphErrors *sim2_g = new TGraphErrors(x.size(),x.data(),sim2_y.data(),ex.data(),sim2_ey.data() );
  TGraphErrors *sim3_g = new TGraphErrors(x.size(),x.data(),sim3_y.data(),ex.data(),sim3_ey.data() );
  TGraphErrors *sim4_g = new TGraphErrors(x.size(),x.data(),sim4_y.data(),ex.data(),sim4_ey.data() );
  TGraphErrors *sim5_g = new TGraphErrors(x.size(),x.data(),sim5_y.data(),ex.data(),sim5_ey.data() );
  TGraphErrors *sim6_g = new TGraphErrors(x.size(),x.data(),sim6_y.data(),ex.data(),sim6_ey.data() );
  TGraphErrors *sim7_g = new TGraphErrors(x.size(),x.data(),sim7_y.data(),ex.data(),sim7_ey.data() );
  TGraphErrors *sim8_g = new TGraphErrors(x.size(),x.data(),sim8_y.data(),ex.data(),sim8_ey.data() );
  TGraphErrors *sim9_g = new TGraphErrors(x.size(),x.data(),sim9_y.data(),ex.data(),sim9_ey.data() );



  vector<double> data_y =  {  23.4888, 8.6887,4.34753,2.76607,2.60899,1.89009,1.6304,1.532,1.10392,1.08344,0.995657,1.00412,0.868022,0.894415,1.03925,0.870165,0.757309,0.765577,0.766622,0.716863};
    vector<double> data_ey = {3.27496,0.684094,0.260045,0.143699,0.138771,0.0974017,0.0883946,0.0895834,0.0665976,0.0708663,0.0724168,0.0797,	0.0801722,0.0940123,0.121998,0.110063,0.080438,0.112337, 0.114436,0.197775};
  TGraphErrors *data = new TGraphErrors(x.size(),x.data(),data_y.data(),ex.data(),data_ey.data() );
  data->SetMarkerSize(2);
  data->SetMarkerStyle(22);
  

  sim1_g->SetLineWidth(4);
  sim2_g->SetLineWidth(4);
  sim3_g->SetLineWidth(4);
  sim4_g->SetLineWidth(4);
  sim5_g->SetLineWidth(4);
  sim6_g->SetLineWidth(4);
  sim7_g->SetLineWidth(4);
  sim8_g->SetLineWidth(4);
  sim9_g->SetLineWidth(4);
	  
  sim1_g->SetLineColor(kGreen);
  sim2_g->SetLineColor(kGreen);
  sim3_g->SetLineColor(kGreen);
  sim4_g->SetLineColor(kBlue);
  sim5_g->SetLineColor(kBlue);
  sim6_g->SetLineColor(kBlue);
  sim7_g->SetLineColor(kRed);
  sim8_g->SetLineColor(kRed);
  sim9_g->SetLineColor(kRed);

  sim1_g->SetLineStyle(1);
  sim2_g->SetLineStyle(2);
  sim3_g->SetLineStyle(4);
  sim4_g->SetLineStyle(1);
  sim5_g->SetLineStyle(2);
  sim6_g->SetLineStyle(4);
  sim7_g->SetLineStyle(1);
  sim8_g->SetLineStyle(2);
  sim9_g->SetLineStyle(4);

  TCanvas *c1 = new TCanvas("c1","c1",1);
  c1->SetLogy();
  sim1_g->GetYaxis()->SetRangeUser(.5,20);
  
  //  sim1_g->Draw("ALO");
  sim1_g->Fit(fit);
 auto sim1_fit = (TF1 *)fit->Clone();
  
 // sim2_g->Draw("A LO");
  sim2_g->Fit(fit);
  auto sim2_fit = (TF1 *)fit->Clone();


  //   sim3_g->Draw("same LO");
  sim3_g->Fit(fit);
  auto sim3_fit = (TF1 *)fit->Clone();


  //   sim4_g->Draw("same LO");
  sim4_g->Fit(fit);
  auto sim4_fit = (TF1 *)fit->Clone();


  //  sim5_g->Draw("same LO");
  sim5_g->Fit(fit);
  auto sim5_fit = (TF1 *)fit->Clone();


  //   sim6_g->Draw("ALO");
  sim6_g->Fit(fit);
  auto sim6_fit = (TF1 *)fit->Clone();


  //   sim7_g->Draw("ALO");
  sim7_g->Fit(fit);
  auto sim7_fit = (TF1 *)fit->Clone();

  //  sim8_g->Draw("ALO");
  sim8_g->Fit(fit);
  auto sim8_fit = (TF1 *)fit->Clone();


  //  sim9_g->Draw("ALO");
  sim9_g->Fit(fit);
  auto sim9_fit = (TF1 *)fit->Clone();


  sim1_fit->SetLineWidth(4);
  sim2_fit->SetLineWidth(4);
  sim3_fit->SetLineWidth(4);
  sim4_fit->SetLineWidth(4);
  sim5_fit->SetLineWidth(4);
  sim6_fit->SetLineWidth(4);
  sim7_fit->SetLineWidth(4);
  sim8_fit->SetLineWidth(4);
  sim9_fit->SetLineWidth(4);
	  
  sim1_fit->SetLineColor(kGreen);
  sim2_fit->SetLineColor(kGreen);
  sim3_fit->SetLineColor(kGreen);
  sim4_fit->SetLineColor(kBlue);
  sim5_fit->SetLineColor(kBlue);
  sim6_fit->SetLineColor(kBlue);
  sim7_fit->SetLineColor(kRed);
  sim8_fit->SetLineColor(kRed);
  sim9_fit->SetLineColor(kRed);

  sim1_fit->SetLineStyle(1);
  sim2_fit->SetLineStyle(2);
  sim3_fit->SetLineStyle(4);
  sim4_fit->SetLineStyle(1);
  sim5_fit->SetLineStyle(2);
  sim6_fit->SetLineStyle(4);
  sim7_fit->SetLineStyle(1);
  sim8_fit->SetLineStyle(2);
  sim9_fit->SetLineStyle(4);

  data->GetYaxis()->SetRangeUser(.4,8);

  data->Draw("APO");
  sim1_fit->Draw("same LO"); 
  sim2_fit->Draw("same LO"); 
  sim3_fit->Draw("same LO");
  sim4_fit->Draw("same LO");
  sim5_fit->Draw("same LO");
  sim6_fit->Draw("same LO");
  sim7_fit->Draw("same LO");
  sim8_fit->Draw("same LO");
  sim9_fit->Draw("same LO");

  data->Draw("same PO");

}
