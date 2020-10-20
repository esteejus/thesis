#include "/home/justin/mythesis/thesis_style.h"

using namespace style;

void compareDansFits()
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




  double xerr[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  double x[20] = { 5, 15,	25,	35,	45,	55,	65,	75,	85,	95,	105,	115,	125,	135,	145,	155,	170,	190,	220,	270};


  double sim1[7] = {10.09371158,6.84010152,4.0375712,2.77918759,1.78251907,1.16497761,0.86025};
  double sim1_err[7] = {0.10280281,0.05552378,0.03501827,0.03037082,0.02258307,0.02433308,0.0428092};


  double sim2[7] = {  8.89731124,6.09395013,3.82599407,2.79684523,1.96308812,1.34364821,1.04662379};
  double sim2_err[7] = {  0.09332674,0.05172375,0.03560619,0.03347287,0.02745047,0.0320423,0.05873373};


  double sim3[7] = {8.94316997,6.11982396,4.00191219,3.02769045,2.16886821,1.62485392,1.1752988};
  double sim3_err[7] = {0.09605,0.0538117,0.03901276,0.03836745,0.03212224,0.04074131,0.07136874};


  double sim4[7] = {8.92854629,6.23817778,3.99154433,3.00938673,2.2859809,1.71789302,1.30832196};
  double sim4_err[7] = {0.08834301,0.04941208,0.03413084,0.03277797,0.02868281,0.03554059,0.06421134};


  double sim5[7] = {8.0981977,5.76255956,3.88704642,3.10848369,2.44380898,1.91307524,1.58958333};
  double sim5_err[7] = {0.08259763,0.04829899,0.03618655,0.03776566,0.03465093,0.04508382,0.0925370};


  double sim6[7] = {8.03355886,5.68820834,4.05834922,3.31636232,2.61368241,2.03982477,1.82173913};
  double sim6_err[7] = {0.08081772,0.04779994,0.03871201,0.04159434,0.03827397,0.04963645,0.10567781};

 double sim7[7] = { 7.99444183,5.78792863,3.99729013,3.19164641,2.67354491,2.18159066,2.01494768};
 double sim7_err[7] = { 0.07500963,0.0441796,0.03347236,0.03402926,0.03307978,0.04393653,0.09525417};

 double sim8[7] = {8.21572248,5.84008489,4.08977248,3.4652381,2.88561633,2.3756487,2.29596413};
 double sim8_err[7] = {0.0857599,0.0498929,0.03875936,0.04289701,0.04173644,0.05652494,0.13015737};

 double sim9[7] = {  7.42420632,5.43922455,3.96732456,3.50131464,2.98390342,2.68223028,2.45363409};
 double sim9_err[7] = {  0.07285886,0.04554561,0.03786236,0.044364,0.04457608,0.06681299,0.14567225};

  

  TGraphErrors *sim1_g = new TGraphErrors(7,x,sim1,xerr,sim1_err);
  TGraphErrors *sim2_g = new TGraphErrors(7,x,sim2,xerr,sim2_err);
  TGraphErrors *sim3_g = new TGraphErrors(7,x,sim3,xerr,sim3_err);
  TGraphErrors *sim4_g = new TGraphErrors(7,x,sim4,xerr,sim4_err);
  TGraphErrors *sim5_g = new TGraphErrors(7,x,sim5,xerr,sim5_err);
  TGraphErrors *sim6_g = new TGraphErrors(7,x,sim6,xerr,sim6_err);
  TGraphErrors *sim7_g = new TGraphErrors(7,x,sim7,xerr,sim7_err);
  TGraphErrors *sim8_g = new TGraphErrors(7,x,sim8,xerr,sim8_err);
  TGraphErrors *sim9_g = new TGraphErrors(7,x,sim9,xerr,sim9_err);

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
  TF1 *fit = new TF1("fit","[0]*TMath::Exp([1]*x + [2]*pow(x,2.5))",0,275);
  fit->SetParameters(12,-1e-2,-1e-6);

  singleRatio_sn132->GetYaxis()->SetRangeUser(.5,20);
  singleRatio_sn132->GetXaxis()->SetRangeUser(0,300);
  singleRatio_sn132->Draw();

  cvs->SetLogy();

  TH1D *junk = new TH1D("junk","",1,0,300);

  junk->GetYaxis()->SetRangeUser(.5,20);
  //  sim1_g->GetXaxis()->SetRangeUser(0,300);
  //  sim1_g->GetYaxis()->SetRangeUser(.5,20);
  sim1_g->SetTitle("Sim 1");
  junk->Draw();
  sim1_g->Draw("same LE");
  sim1_fitg->Fit(fit,"","",15,275);
  auto sim1_fit = (TF1 *)fit->Clone();
  sim1_fit->SetLineWidth(3);
  sim1_fit->SetLineColor(2);
  sim1_fit->SetLineStyle(sim1_ls);
  sim1_fit->Draw("same");
  cvs->SaveAs("sim1_fit.png");

  sim2_g->GetYaxis()->SetRangeUser(.5,20);
  sim2_g->SetTitle("Sim 2");
  sim2_g->Draw("ALE");
  sim2_fitg->Fit(fit,"","",15,275);
  auto sim2_fit = (TF1 *)fit->Clone();
  sim2_fit->SetLineWidth(3);
  sim2_fit->SetLineColor(2);
  sim2_fit->SetLineStyle(sim2_ls);
  sim2_fit->Draw("same");
  cvs->SaveAs("sim2_fit.png");

  sim3_g->GetYaxis()->SetRangeUser(.5,20);
  sim3_g->SetTitle("Sim 3");
  sim3_g->Draw("ALE");
  sim3_fitg->Fit(fit,"","",15,275);
  auto sim3_fit = (TF1 *)fit->Clone();
  sim3_fit->SetLineWidth(3);
  sim3_fit->SetLineColor(2);
  sim3_fit->SetLineStyle(sim3_ls);
  sim3_fit->Draw("same");
  cvs->SaveAs("sim3_fit.png");

  sim4_g->GetYaxis()->SetRangeUser(.5,20);
  sim4_g->SetTitle("Sim 4");
  sim4_g->Draw("ALE");
  sim4_fitg->Fit(fit,"","",15,275);
  auto sim4_fit = (TF1 *)fit->Clone();
  sim4_fit->SetLineWidth(3);
  sim4_fit->SetLineColor(2);
  sim4_fit->SetLineStyle(sim4_ls);
  sim4_fit->Draw("same");
  cvs->SaveAs("sim4_fit.png");


  sim5_g->GetYaxis()->SetRangeUser(.5,20);
  sim5_g->SetTitle("Sim 5");
  sim5_g->Draw("ALE");
  sim5_fitg->Fit(fit,"","",15,275);
  auto sim5_fit = (TF1 *)fit->Clone();
  sim5_fit->SetLineWidth(3);
  sim5_fit->SetLineColor(2);
  sim5_fit->SetLineStyle(sim5_ls);
  sim5_fit->Draw("same");
  cvs->SaveAs("sim5_fit.png");
  

  sim6_g->GetYaxis()->SetRangeUser(.5,20);
  sim6_g->SetTitle("Sim 6");
  sim6_g->Draw("ALE");
  sim6_fitg->Fit(fit,"","",15,275);
  auto sim6_fit = (TF1 *)fit->Clone();
  sim6_fit->SetLineWidth(3);
  sim6_fit->SetLineColor(2);
  sim6_fit->SetLineStyle(sim6_ls);
  sim6_fit->Draw("same");
  cvs->SaveAs("sim6_fit.png");
  
  sim7_g->GetYaxis()->SetRangeUser(.5,20);
  sim7_g->SetTitle("Sim 7");
  sim7_g->Draw("ALE");
  sim7_fitg->Fit(fit,"","",15,275);
  auto sim7_fit = (TF1 *)fit->Clone();
  sim7_fit->SetLineWidth(3);
  sim7_fit->SetLineColor(2);
  sim7_fit->SetLineStyle(sim7_ls);
  sim7_fit->Draw("same");
  cvs->SaveAs("sim7_fit.png");

  sim8_g->GetYaxis()->SetRangeUser(.5,20);
  sim8_g->SetTitle("Sim 8");
  sim8_g->Draw("ALE");
  sim8_fitg->Fit(fit,"","",15,275);
  auto sim8_fit = (TF1 *)fit->Clone();
  sim8_fit->SetLineWidth(3);
  sim8_fit->SetLineColor(2);
  sim8_fit->SetLineStyle(sim8_ls);
  sim8_fit->Draw("same");
  cvs->SaveAs("sim8_fit.png");

    
  sim9_g->GetYaxis()->SetRangeUser(.5,20);
  sim9_g->SetTitle("Sim 9");
  sim9_g->Draw("ALE");
  sim9_fitg->Fit(fit,"","",15,275);
  auto sim9_fit = (TF1 *)fit->Clone();
  sim9_fit->SetLineWidth(3);
  sim9_fit->SetLineColor(2);
  sim9_fit->SetLineStyle(sim9_ls);
  sim9_fit->Draw("same");
  cvs->SaveAs("sim9_fit.png");


  junk->Draw();
  sim1_fit->GetYaxis()->SetRangeUser(.5,20);
  sim1_fit->Draw("same L");
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
