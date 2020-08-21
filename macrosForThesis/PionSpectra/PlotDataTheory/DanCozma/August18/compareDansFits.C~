#include "/home/justin/mythesis/thesis_style.h"

using namespace style;

void publishPion_132Ratio()
{
  TFile *f = TFile::Open("/home/justin/mythesis/macrosForThesis/PionSpectra/rootfiles/publishPions_sm.root");
  TH1D *singleRatio_sn132 = (TH1D *)f->Get("singleRatio_sn132");
  TH1D *singleRatio_sn108 = (TH1D *)f->Get("singleRatio_sn108");

  TH1D *doubleRatio = (TH1D *)f->Get("doubleRatio");

  make(singleRatio_sn108);
  make(singleRatio_sn132);
  make(doubleRatio);

  gStyle->SetEndErrorSize(0);

  //style
  int lineS132 = 1; 
  int lineS108 = 7;

  int markS132 = 21;
  int markS108 = 25;  

  //color
  int lineC132 = kRed ; 
  int lineC108 = kRed - 7;

  int markC132 = kRed ;
  int markC108 = kRed - 7;  

  //size
  int markSz132 = 2; //marker size
  int markSz108 = 2; //marker size 

  //  TLegend *leg = new TLegend(.2,.2,.55,.5);
  TLegend *leg = new TLegend(.3,.5,.8,.8);
  leg->AddEntry(singleRatio_sn132,"{}^{132}Sn +{}^{124}Sn","lpe");
  leg->AddEntry(singleRatio_sn108,"{}^{108}Sn +{}^{112}Sn","lpe");

  /*  TLegend *leg_2 = new TLegend(.75,.75,.95,.9);
  leg_2->SetHeader("{}^{108}Sn +{}^{112}Sn");
  leg_2->AddEntry(pim_sn108,"#pi^{-}","lpe");
  leg_2->AddEntry(pip_sn108,"#pi^{+} (x10^{-1} )","lpe");
  */

  TCanvas *cvs = style::stdcvs();
  //  cvs->SetLogy();
  //  singleRatio_sn132->GetYaxis()->SetRangeUser(.5,20);
  
  singleRatio_sn132->GetYaxis()->SetRangeUser(0,15);
  singleRatio_sn132->GetYaxis()->SetTitle("#pi^{-}/#pi^{+}");
  singleRatio_sn132->GetYaxis()->CenterTitle();
  singleRatio_sn132->GetXaxis()->SetTitle("T_{#scale[.6]{CM}} (MeV)");
  singleRatio_sn132->GetXaxis()->CenterTitle();
  
  singleRatio_sn132->SetLineWidth(5);
  singleRatio_sn132->SetLineStyle(lineS132);
  singleRatio_sn132->SetLineColor(lineC132);
  singleRatio_sn132->SetMarkerStyle(markS132);
  singleRatio_sn132->SetMarkerSize(markSz132);
  singleRatio_sn132->SetMarkerColor(markC132);
  
  singleRatio_sn132->GetYaxis()->SetTitle("#pi^{-}/#pi^{+}");
  singleRatio_sn132->GetYaxis()->CenterTitle();
  singleRatio_sn132->GetXaxis()->SetTitle("T_{#scale[.6]{CM}} (MeV)");
  singleRatio_sn132->GetXaxis()->CenterTitle();

  singleRatio_sn132->GetYaxis()->SetRangeUser(1,14);
  singleRatio_sn132->SetLineWidth(5);
  singleRatio_sn132->SetLineStyle(1);
  singleRatio_sn132->SetLineColor(1);
  singleRatio_sn132->SetMarkerStyle(21);
  singleRatio_sn132->SetMarkerSize(3);
  singleRatio_sn132->SetMarkerColor(1);
 
  /*  
  int pBUUStiff_mc = kRed - 10;
  int pBUUStiff_fc = kRed - 10;
  int pBUUStiff_fs = 3018;
  int pBUUStiff_ms = 23;
  int pBUUStiff_msz = 3;
  int pBUUStiff_lw = 5;
  int pBUUStiff_ls = 1;

  pBUU_stiff_no_DR->SetFillColorAlpha(pBUUStiff_fc,.75);
  pBUU_stiff_no_DR->SetFillStyle(pBUUStiff_fs);
  pBUU_stiff_no_DR->SetMarkerStyle(pBUUStiff_ms);
  pBUU_stiff_no_DR->SetMarkerColor(pBUUStiff_mc);
  pBUU_stiff_no_DR->SetMarkerSize(pBUUStiff_msz);
  pBUU_stiff_no_DR->SetLineStyle(pBUUStiff_ls);
  pBUU_stiff_no_DR->SetLineColor(pBUUStiff_mc);
  pBUU_stiff_no_DR->SetLineWidth(pBUUStiff_lw);
  */



  vector<double> sim1_fit_px = {  285.881506,251.0998827,187.3693473,137.3000213,100.5199445,77.03844923,50.81524637,28.11100149,12.06138012};
  vector<double> sim1_fit_py = {  0.7482802664,0.8396646683,1.281125567,2.110758638,3.282952952,4.506911428,6.522725689,9.216242126,11.77313837};

  vector<double> sim2_fit_px = {282.71851,260.0595936,240.9136359,215.8996374,175.6299328,115.3930247,82.52519731,63.34857615,15.9856282,32.03524957,47.30095456,12.46267065};
  vector<double> sim2_fit_py = {0.9838141425,1.002890058,1.042158691,1.152710485,1.486718509,2.657796648,3.958970246,5.130690395,10.341784,8.095750036,6.460393665,10.9026279};


   vector<double> sim3_fit_px = { 286.903397,267.7767705,236.5381026,197.8628946,172.8508959,134.5376493,120.8511092,86.43011412,42.6087884,12.47466937};
  vector<double> sim3_fit_py = {  2.203962346,1.992589245,1.836418494,1.881035484,2.050822996,2.582327692,2.870006018,3.997167706,6.681199585,10};


  vector<double> sim4_fit_px = {  286.5647664,276.4105162,249.8493494,227.1877666,148.228189,105.9920275,65.70099189,47.70357828,12.09670968};
  vector<double> sim4_fit_py = {  1.515545616,1.493873469,1.479597817,1.537532169,2.257509055,3.205083351,4.82025428,5.925538065,9.128170504};


  vector<double> sim5_fit_px = {  286.9407263,247.8895584,167.3894785,133.7643985,96.60969497,73.52882359,12.49000107};
  vector<double> sim5_fit_py = {  1.684381518,1.55236679,1.945326268,2.437757824,3.378897796,4.316317947,8.954544089};


  vector<double> sim6_fit_px = {  287.3340177,266.2469337,230.6993921,200.2199765,173.2495201,130.6320659,98.17019518,42.61745414,12.48666809};
  vector<double> sim6_fit_py = {1.652342992,1.57488752,1.582466802,1.708817432,1.936009059,2.569959542,3.427916654,6.276948794,9.172100606};


  vector<double> sim7_fit_px = {  287.3006879,265.834311,231.8646011,174.040769,137.684647,109.1370254,88.79652837,63.36657423,33.62707978,12.10270904};
  vector<double> sim7_fit_py = {2.100649085,1.845256415,1.660295034,1.801488081,2.203962346,2.775155638,3.395159031,4.506911428,6.554116865,8.742147877};


  vector<double> sim8_fit_px = {  287.2666916,265.018398,241.2029384,204.0988961,155.6460644,121.6370254,89.5731122,69.23661476,30.90137052,12.51399851};
  vector<double> sim8_fit_py = {2.683439953,2.368536939,2.162040903,2.080575006,2.323485132,2.775155638,3.511200136,4.17366863,6.157555306,7.533227768};



  vector<double> sim9_fit_px = {286.4787756,244.7118974,191.9828552,143.9133159,102.859695,57.09790956,41.05762052,26.97312287,12.49600043};
  vector<double> sim9_fit_py = {2.815415796,2.268373511,2.182900992,2.569959542,3.378897796,5.155382282,6.157555306,7.214653924,8.575863977};


  TGraph *sim1_fitg = new TGraph(sim1_fit_px.size(),sim1_fit_px.data(),sim1_fit_py.data());
  TGraph *sim2_fitg = new TGraph(sim2_fit_px.size(),sim2_fit_px.data(),sim2_fit_py.data());
  TGraph *sim3_fitg = new TGraph(sim3_fit_px.size(),sim3_fit_px.data(),sim3_fit_py.data());
  TGraph *sim4_fitg = new TGraph(sim4_fit_px.size(),sim4_fit_px.data(),sim4_fit_py.data());
  TGraph *sim5_fitg = new TGraph(sim5_fit_px.size(),sim5_fit_px.data(),sim5_fit_py.data());
  TGraph *sim6_fitg = new TGraph(sim6_fit_px.size(),sim6_fit_px.data(),sim6_fit_py.data());
  TGraph *sim7_fitg = new TGraph(sim7_fit_px.size(),sim7_fit_px.data(),sim7_fit_py.data());
  TGraph *sim8_fitg = new TGraph(sim8_fit_px.size(),sim8_fit_px.data(),sim8_fit_py.data());
  TGraph *sim9_fitg = new TGraph(sim9_fit_px.size(),sim9_fit_px.data(),sim9_fit_py.data());  


  double xerr[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
  double x[12] = {12.5,37.5,62.5,87.5,112.5,137.5,162.5,187.5,212.5,237.5,262.5,287.5};

  double sim1[12] = {11.6454432,8.420336788,5.430365297,3.852546917,2.712811694,2.007462687,1.635437882,1.265486726,1.182795699,0.86440678,0.84375,0.75};
  double sim1_err[12] = {0.428241894,0.226531545,0.141133858,0.112087578,0.093102731,0.086610439,0.093541176,0.091933316,0.11801047,0.116785925,0.155850612,0.202488344};

  double sim2[12] = {10.595238,8.185254,5.347687,3.44023,2.461832,1.931684,1.569549,1.355491,1.350282,1.055556,0.983871,1.069767};
  double sim2_err[12] = {0.363509,0.216424,0.134438,0.093219,0.080542,0.081967,0.0869,0.095925,0.133742,0.131127,0.177367,0.22686};

  double sim3[12] = {9.665628,8.006927,5.045261,3.887065,2.886099,2.281414,2.140271,2.060484,1.57485,1.734177,2.821429,1.8};
  double sim3_err[12] = { 0.326409,0.213139,0.127537,0.111452,0.100104,0.09886,0.123081,0.159248,0.155637,0.244844,0.620387,0.50192};
  
  double sim4[12] = { 8.852342159,7.41375,4.874328679,3.589873418,2.885948905,2.359459459,2.078651685,1.939163498,1.67721519,1.689655172,1.161290323,1.615384615};
  double sim4_err[12] = { 0.296589912,0.197656505,0.123925133,0.101866887,0.101168184,0.10386981,0.119552039,0.147358677,0.168371335,0.228396833,0.201117446,0.40302471};
  
  double sim5[12] = { 8.90943,7.014177,4.54016,3.636574,3.094107,2.268638,1.957774,1.744186,1.649718,1.709302,1.653061,1.555556};
  double sim5_err[12] = { 0.287188,0.175045,0.108668,0.098399,0.105133,0.09745,0.105401,0.12599,0.157701,0.231904,0.299063,0.383635};
  
  double sim6[12] = { 9.079143,7.036688,4.859782,3.734206,2.869057,2.349879,2.194672,1.784053,1.856209,1.653061,1.622951,1.482759};
  double sim6_err[12] = { 0.291435,0.171834,0.115783,0.099933,0.092941,0.097662,0.119459,0.128251,0.185931,0.211394,0.264052,0.356217};
  
  double sim7[12] = { 8.6,6.507373,4.563223,3.406533,2.891772,2.19893,1.93211,1.88961,1.47619,1.294643,1.238806,2.681818};
  double sim7_err[12] = { 0.259112,0.149906,0.104508,0.086767,0.091232,0.086696,0.102006,0.133066,0.139085,0.16323,0.205041,0.66981};
  
  double sim8[12] = { 8.345303867,7.008561644,4.683812405,3.757772021,3.123352166,2.599722992,2.603365385,2.321888412,2.172661871,1.8875,2.041666667,3.1875};
  double sim8_err[12] = { 0.268627307,0.178858211,0.115466134,0.107458322,0.110131174,0.113390646,0.149870654,0.182178904,0.223751284,0.260840296,0.359544102,0.913221688};
  
  double sim9[12] = { 7.395983,6.127168,4.302024,3.382022,3.000765,2.515901,2.508621,2.388693,2.182432,1.508929,2.081633,3.041667};
  double sim9_err[12] = { 0.211548,0.139092,0.09586,0.087246,0.096069,0.102149,0.137771,0.168945,0.216791,0.183706,0.362829,0.715546};

  TGraphErrors *sim1_g = new TGraphErrors(12,x,sim1,xerr,sim1_err);
  TGraphErrors *sim2_g = new TGraphErrors(12,x,sim2,xerr,sim2_err);
  TGraphErrors *sim3_g = new TGraphErrors(12,x,sim3,xerr,sim3_err);
  TGraphErrors *sim4_g = new TGraphErrors(12,x,sim4,xerr,sim4_err);
  TGraphErrors *sim5_g = new TGraphErrors(12,x,sim5,xerr,sim5_err);
  TGraphErrors *sim6_g = new TGraphErrors(12,x,sim6,xerr,sim6_err);
  TGraphErrors *sim7_g = new TGraphErrors(12,x,sim7,xerr,sim7_err);
  TGraphErrors *sim8_g = new TGraphErrors(12,x,sim8,xerr,sim8_err);
  TGraphErrors *sim9_g = new TGraphErrors(12,x,sim9,xerr,sim9_err);

  int sim1_c = kBlue;
  int sim1_ls = 1;

  int sim2_c = kBlue;
  int sim2_ls = 2;

  int sim3_c = kRed;
  int sim3_ls = 1;

  int sim4_c = kRed;
  int sim4_ls = 4;

  int sim5_c = kRed;
  int sim5_ls = 4;

  int sim6_c = kRed;
  int sim6_ls = 4;

  int sim7_c = kRed;
  int sim7_ls = 4;

  int sim8_c = kGreen;
  int sim8_ls = 1;

  int sim9_c = kGreen;
  int sim9_ls = 6;

  sim1_g->SetLineColor(sim1_c);
  sim2_g->SetLineColor(sim2_c);
  sim3_g->SetLineColor(sim3_c);
  sim4_g->SetLineColor(sim4_c);
  sim5_g->SetLineColor(sim5_c);
  sim6_g->SetLineColor(sim6_c);
  sim7_g->SetLineColor(sim7_c);
  sim8_g->SetLineColor(sim8_c);
  sim9_g->SetLineColor(sim9_c);
  
  sim1_g->SetFillColorAlpha(kRed,.4);
  sim2_g->SetFillColorAlpha(kRed,.4);
  sim3_g->SetFillColorAlpha(kRed,.4);
  sim4_g->SetFillColorAlpha(kRed,.4);
  sim5_g->SetFillColorAlpha(kRed,.4);
  sim6_g->SetFillColorAlpha(kRed,.4);
  sim7_g->SetFillColorAlpha(kRed,.4);
  sim8_g->SetFillColorAlpha(kRed,.4);
  sim9_g->SetFillColorAlpha(kRed,.4);

  sim1_g->SetLineStyle(sim1_ls);
  sim2_g->SetLineStyle(sim2_ls);
  sim3_g->SetLineStyle(sim3_ls);
  sim4_g->SetLineStyle(sim4_ls);
  sim5_g->SetLineStyle(sim5_ls);
  sim6_g->SetLineStyle(sim6_ls);
  sim7_g->SetLineStyle(sim7_ls);
  sim8_g->SetLineStyle(sim8_ls);
  sim9_g->SetLineStyle(sim9_ls);

  sim1_g->SetLineWidth(6);
  sim2_g->SetLineWidth(6);
  sim3_g->SetLineWidth(6);
  sim4_g->SetLineWidth(6);
  sim5_g->SetLineWidth(6);
  sim6_g->SetLineWidth(6);
  sim6_g->SetLineWidth(6);
  sim7_g->SetLineWidth(6);
  sim8_g->SetLineWidth(6);
  sim9_g->SetLineWidth(6);

  //  TF1 *fit = new TF1("fit","[0] + [1]*x + [2]*x*x + [3]*pow(x,3) + [4]*pow(x,4) + [5]*pow(x,5) + [6]*pow(x,6)",0,300);
  //  fit->SetParameters(1,1,1,1,1,1,1);
  TF1 *fit = new TF1("fit","[0]*TMath::Exp([1]*x + [2]*pow(x,2.5))",0,300);
  fit->SetParameters(12,-1e-2,-1e-6);

  singleRatio_sn132->GetYaxis()->SetRangeUser(.5,20);
  singleRatio_sn132->GetXaxis()->SetRangeUser(0,300);
  singleRatio_sn132->Draw();

  cvs->SetLogy();

  sim1_g->GetYaxis()->SetRangeUser(.5,20);
  sim1_g->SetTitle("Sim 1");
  sim1_g->Draw("ALE");
  sim1_fitg->Fit(fit);
  auto sim1_fit = (TF1 *)fit->Clone();
  sim1_fit->SetLineWidth(3);
  sim1_fit->SetLineColor(2);
  sim1_fit->SetLineStyle(sim1_ls);
  sim1_fit->Draw("same");
  cvs->SaveAs("sim1_fit.png");

  sim2_g->GetYaxis()->SetRangeUser(.5,20);
  sim2_g->SetTitle("Sim 2");
  sim2_g->Draw("ALE");
  sim2_fitg->Fit(fit);
  auto sim2_fit = (TF1 *)fit->Clone();
  sim2_fit->SetLineWidth(3);
  sim2_fit->SetLineColor(2);
  sim2_fit->SetLineStyle(sim2_ls);
  sim2_fit->Draw("same");
  cvs->SaveAs("sim2_fit.png");

  sim3_g->GetYaxis()->SetRangeUser(.5,20);
  sim3_g->SetTitle("Sim 3");
  sim3_g->Draw("ALE");
  sim3_fitg->Fit(fit);
  auto sim3_fit = (TF1 *)fit->Clone();
  sim3_fit->SetLineWidth(3);
  sim3_fit->SetLineColor(2);
  sim3_fit->SetLineStyle(sim3_ls);
  sim3_fit->Draw("same");
  cvs->SaveAs("sim3_fit.png");

  sim4_g->GetYaxis()->SetRangeUser(.5,20);
  sim4_g->SetTitle("Sim 4");
  sim4_g->Draw("ALE");
  sim4_fitg->Fit(fit);
  auto sim4_fit = (TF1 *)fit->Clone();
  sim4_fit->SetLineWidth(3);
  sim4_fit->SetLineColor(2);
  sim4_fit->SetLineStyle(sim4_ls);
  sim4_fit->Draw("same");
  cvs->SaveAs("sim4_fit.png");


  sim5_g->GetYaxis()->SetRangeUser(.5,20);
  sim5_g->SetTitle("Sim 5");
  sim5_g->Draw("ALE");
  sim5_fitg->Fit(fit);
  auto sim5_fit = (TF1 *)fit->Clone();
  sim5_fit->SetLineWidth(3);
  sim5_fit->SetLineColor(2);
  sim5_fit->SetLineStyle(sim5_ls);
  sim5_fit->Draw("same");
  cvs->SaveAs("sim5_fit.png");
  

  sim6_g->GetYaxis()->SetRangeUser(.5,20);
  sim6_g->SetTitle("Sim 6");
  sim6_g->Draw("ALE");
  sim6_fitg->Fit(fit);
  auto sim6_fit = (TF1 *)fit->Clone();
  sim6_fit->SetLineWidth(3);
  sim6_fit->SetLineColor(2);
  sim6_fit->SetLineStyle(sim6_ls);
  sim6_fit->Draw("same");
  cvs->SaveAs("sim6_fit.png");
  
  sim7_g->GetYaxis()->SetRangeUser(.5,20);
  sim7_g->SetTitle("Sim 7");
  sim7_g->Draw("ALE");
  sim7_fitg->Fit(fit);
  auto sim7_fit = (TF1 *)fit->Clone();
  sim7_fit->SetLineWidth(3);
  sim7_fit->SetLineColor(2);
  sim7_fit->SetLineStyle(sim7_ls);
  sim7_fit->Draw("same");
  cvs->SaveAs("sim7_fit.png");

  sim8_g->GetYaxis()->SetRangeUser(.5,20);
  sim8_g->SetTitle("Sim 8");
  sim8_g->Draw("ALE");
  sim8_fitg->Fit(fit);
  auto sim8_fit = (TF1 *)fit->Clone();
  sim8_fit->SetLineWidth(3);
  sim8_fit->SetLineColor(2);
  sim8_fit->SetLineStyle(sim8_ls);
  sim8_fit->Draw("same");
  cvs->SaveAs("sim8_fit.png");

    
  sim9_g->GetYaxis()->SetRangeUser(.5,20);
  sim9_g->SetTitle("Sim 9");
  sim9_g->Draw("ALE");
  sim9_fitg->Fit(fit);
  auto sim9_fit = (TF1 *)fit->Clone();
  sim9_fit->SetLineWidth(3);
  sim9_fit->SetLineColor(2);
  sim9_fit->SetLineStyle(sim9_ls);
  sim9_fit->Draw("same");
  cvs->SaveAs("sim9_fit.png");


  sim1_fit->GetYaxis()->SetRangeUser(.5,20);
  sim1_fit->Draw("L");
  sim2_fit->Draw("same L");
  sim3_fit->Draw("same L");
  sim4_fit->Draw("same L");
  sim5_fit->Draw("same L");
  sim6_fit->Draw("same L");
  sim7_fit->Draw("same L");
  sim8_fit->Draw("same L");
  sim9_fit->Draw("same L");
  cvs->SetLogy();
  singleRatio_sn132->DrawCopy("same E1");
  cvs->SaveAs("allfits.png");
  
  /*
  singleRatio_sn132->DrawCopy("same E1");
  cvs->SetLogy();
  //  cvs->SetLogx();
  cvs->SaveAs("singleRatio_sn132_boot.png");

  */


}
