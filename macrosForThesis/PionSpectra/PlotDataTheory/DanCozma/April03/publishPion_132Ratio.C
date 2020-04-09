
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

  sim1_g->SetLineColor(kRed);
  sim2_g->SetLineColor(kRed);
  sim3_g->SetLineColor(kRed);
  sim4_g->SetLineColor(kRed);
  sim5_g->SetLineColor(kRed);
  sim6_g->SetLineColor(kRed);
  sim7_g->SetLineColor(kRed);
  sim8_g->SetLineColor(kRed);
  sim9_g->SetLineColor(kRed);
  
  sim1_g->SetFillColorAlpha(kRed,.4);
  sim2_g->SetFillColorAlpha(kRed,.4);
  sim3_g->SetFillColorAlpha(kRed,.4);
  sim4_g->SetFillColorAlpha(kRed,.4);
  sim5_g->SetFillColorAlpha(kRed,.4);
  sim6_g->SetFillColorAlpha(kRed,.4);
  sim7_g->SetFillColorAlpha(kRed,.4);
  sim8_g->SetFillColorAlpha(kRed,.4);
  sim9_g->SetFillColorAlpha(kRed,.4);

  sim1_g->SetLineStyle(1);
  sim2_g->SetLineStyle(2);
  sim3_g->SetLineStyle(3);
  sim4_g->SetLineStyle(4);
  sim5_g->SetLineStyle(5);
  sim6_g->SetLineStyle(6);
  sim6_g->SetLineStyle(7);
  sim7_g->SetLineStyle(8);
  sim8_g->SetLineStyle(9);
  sim9_g->SetLineStyle(10);

  //  TF1 *fit = new TF1("fit","[0] + [1]*x + [2]*x*x + [3]*pow(x,3) + [4]*pow(x,4) + [5]*pow(x,5) + [6]*pow(x,6)",0,300);
  //  fit->SetParameters(1,1,1,1,1,1,1);
  TF1 *fit = new TF1("fit","[0]*TMath::Exp([1]*x + [2]*pow(x,2.5))",0,300);
  fit->SetParameters(12,-1e-2,-1e-6);

  singleRatio_sn132->GetYaxis()->SetRangeUser(.5,20);
  singleRatio_sn132->GetXaxis()->SetRangeUser(0,300);
  singleRatio_sn132->Draw();

  sim4_g->Draw("same E3");
  /*
  sim5_g->Fit(fit);
  sim5_g->Draw("same E3");

  sim3_g->Draw("same E3");
  sim4_g->Draw("same E3");
  sim5_g->Draw("same E3");
  sim6_g->Draw("same E3");

  sim7_g->Draw("same E3");
  */
  sim8_g->Draw("same E3");
  sim9_g->Draw("same E3");


  singleRatio_sn132->DrawCopy("same E1");

  cvs->SetLogy();
  //  cvs->SetLogx();
  cvs->SaveAs("singleRatio_sn132_boot.png");




}
