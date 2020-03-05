
#include "/home/justin/mythesis/thesis_style.h"

using namespace style;

void publishPion_108Ratio()
{
  TFile *pBUU_soft_no_f = TFile::Open("/home/justin/Homework/pBUU/K210EM100/input_for_esym.info/pBUUSoft_r-1.root");
  TGraphErrors *pBUU_soft_no_DR = (TGraphErrors *) pBUU_soft_no_f->Get("piRatio108");

  TFile *pBUU_stiff_no_f = TFile::Open("/home/justin/Homework/pBUU/K210EM100/input_for_esym.info/pBUUStiff_r-1.root");
  TGraphErrors *pBUU_stiff_no_DR = (TGraphErrors *) pBUU_stiff_no_f->Get("piRatio108");

  /*
 TFile *pBUU_soft_no_f = TFile::Open("/home/justin/Homework/pBUU/K265EM070/input_for_esym.info/pBUUSoft_r-1.root");
  TGraphErrors *pBUU_soft_no_DR = (TGraphErrors *) pBUU_soft_no_f->Get("piRatio108");

TFile *pBUU_stiff_no_f = TFile::Open("/home/justin/Homework/pBUU/K265EM070/input_for_esym.info/pBUUStiff_r-1.root");
  TGraphErrors *pBUU_stiff_no_DR = (TGraphErrors *) pBUU_stiff_no_f->Get("piRatio108");
  */

  TFile *amdJAM55_f = TFile::Open("/home/justin/Homework/AMDJAM/highStat/input_for_esym.info/AMDJAML55new_r-1.root");
  TGraphErrors *amdJAM55_DR = (TGraphErrors *) amdJAM55_f->Get("piRatio108");

  TFile *amdJAM152_f = TFile::Open("/home/justin/Homework/AMDJAM/highStat/input_for_esym.info/AMDJAML152new_r-1.root");
  TGraphErrors *amdJAM152_DR = (TGraphErrors *) amdJAM152_f->Get("piRatio108");


  TFile *urQMD_46_f = TFile::Open("/home/justin/Homework/UrQMD/input_for_esym.info/UrQMDL46_r-1.root");
  TGraphErrors *urQMD_46_DR = (TGraphErrors *) urQMD_46_f->Get("piRatio108");

  TFile *urQMD_104_f = TFile::Open("/home/justin/Homework/UrQMD/input_for_esym.info/UrQMDL104_r-1.root");
  TGraphErrors *urQMD_104_DR = (TGraphErrors *) urQMD_104_f->Get("piRatio108");


  TFile *imQMD_05_f = TFile::Open("/home/justin/Homework/IQMD-BNU/input_for_esym.info/IQMD-BNUg05_r-1.root");
  TGraphErrors *imQMD_05_DR = (TGraphErrors *) imQMD_05_f->Get("piRatio108");

  TFile *imQMD_20_f = TFile::Open("/home/justin/Homework/IQMD-BNU/input_for_esym.info/IQMD-BNUg20_r-1.root");
  TGraphErrors *imQMD_20_DR = (TGraphErrors *) imQMD_20_f->Get("piRatio108");



  TFile *tuQMD_05_f = TFile::Open("/home/justin/Homework/TuQMD/new-highStat/input_for_esym.info/TuQMDg05_r-1.root");
  TGraphErrors *tuQMD_05_DR = (TGraphErrors *) tuQMD_05_f->Get("piRatio108");

  TFile *tuQMD_20_f = TFile::Open("/home/justin/Homework/TuQMD/new-highStat/input_for_esym.info/TuQMDg20_r-1.root");
  TGraphErrors *tuQMD_20_DR = (TGraphErrors *) tuQMD_20_f->Get("piRatio108");


  TFile *xbuu_f = TFile::Open("/home/justin/Homework/xBUU/old/input_for_esym.info/xBUU_r-1.root");
  TGraphErrors *xbuu_DR = (TGraphErrors *) xbuu_f->Get("piRatio108");

  TFile *xbuu120_f = TFile::Open("/home/justin/Homework/xBUU/new/input_for_esym.info/xBUU_skyrmeL120_r-1.root");
  TGraphErrors *xbuu120_DR = (TGraphErrors *) xbuu120_f->Get("piRatio108");


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
  
  singleRatio_sn108->GetYaxis()->SetRangeUser(0,15);
  singleRatio_sn108->GetYaxis()->SetTitle("#pi^{-}/#pi^{+}");
  singleRatio_sn108->GetYaxis()->CenterTitle();
  singleRatio_sn108->GetXaxis()->SetTitle("T_{#scale[.6]{CM}} (MeV)");
  singleRatio_sn108->GetXaxis()->CenterTitle();
  
  singleRatio_sn108->SetLineWidth(5);
  singleRatio_sn108->SetLineStyle(lineS108);
  singleRatio_sn108->SetLineColor(lineC108);
  singleRatio_sn108->SetMarkerStyle(markS108);
  singleRatio_sn108->SetMarkerSize(markSz108);
  singleRatio_sn108->SetMarkerColor(markC108);
  
  singleRatio_sn108->SetLineWidth(5);
  singleRatio_sn108->SetLineStyle(lineS108);
  singleRatio_sn108->SetLineColor(lineC108);
  singleRatio_sn108->SetMarkerStyle(markS108);
  singleRatio_sn108->SetMarkerSize(markSz108);
  singleRatio_sn108->SetMarkerColor(markC108);

  singleRatio_sn108->GetYaxis()->SetTitle("#pi^{-}/#pi^{+}");
  singleRatio_sn108->GetYaxis()->CenterTitle();
  singleRatio_sn108->GetXaxis()->SetTitle("T_{#scale[.6]{CM}} (MeV)");
  singleRatio_sn108->GetXaxis()->CenterTitle();

  singleRatio_sn108->GetYaxis()->SetRangeUser(.4,12);
  singleRatio_sn108->SetLineWidth(5);
  singleRatio_sn108->SetLineStyle(1);
  singleRatio_sn108->SetLineColor(1);
  singleRatio_sn108->SetMarkerStyle(21);
  singleRatio_sn108->SetMarkerSize(3);
  singleRatio_sn108->SetMarkerColor(1);
 
  int tuQMD_Soft_mc = kBlue - 7;
  int tuQMD_Soft_fc = kBlue - 7;
  int tuQMD_Soft_fs = 1;
  int tuQMD_Soft_ms = 24;
  int tuQMD_Soft_msz = 3;
  int tuQMD_Soft_ls = 10;
  int tuQMD_Soft_lw = 5;
  
  int tuQMD_Stiff_mc = kRed - 7;
  int tuQMD_Stiff_fc = kRed - 7;
  int tuQMD_Stiff_fs = 1;
  int tuQMD_Stiff_ms = 20;
  int tuQMD_Stiff_msz = 3;
  int tuQMD_Stiff_ls = 1;
  int tuQMD_Stiff_lw = 5;
  
  int xBUU_Soft_mc = kBlue - 9;
  int xBUU_Soft_fc = kBlue - 9;
  int xBUU_Soft_fs = 1;
  int xBUU_Soft_ms = 28;
  int xBUU_Soft_msz = 3;
  int xBUU_Soft_lw = 5;
  int xBUU_Soft_ls = 10;
  
  int xBUU_Stiff_mc = kRed - 9;
  int xBUU_Stiff_fc = kRed - 9;
  int xBUU_Stiff_fs = 1;
  int xBUU_Stiff_ms = 34;
  int xBUU_Stiff_msz = 3;
  int xBUU_Stiff_lw = 5;
  int xBUU_Stiff_ls = 1;
 
  int urQMD_Soft_mc = kBlue;
  int urQMD_Soft_fc = kBlue;
  int urQMD_Soft_fs = 1;
  int urQMD_Soft_ms = 26;
  int urQMD_Soft_msz = 3;
  int urQMD_Soft_lw = 5;
  int urQMD_Soft_ls = 10;
  
  int urQMD_Stiff_mc = kRed;
  int urQMD_Stiff_fc = kRed;
  int urQMD_Stiff_ms = 22;
  int urQMD_Stiff_fs = 1;
  int urQMD_Stiff_msz = 3;
  int urQMD_Stiff_lw = 5;
  int urQMD_Stiff_ls = 1;

  int amdSoft_mc = kBlue - 4;
  int amdSoft_fc = kBlue - 4;
  int amdSoft_fs = 1;
  int amdSoft_ms = 30;
  int amdSoft_msz = 3;
  int amdSoft_lw = 5;
  int amdSoft_ls = 10;
  
  int amdStiff_mc = kRed - 4;
  int amdStiff_fc = kRed - 4;
  int amdStiff_fs = 3018;
  int amdStiff_ms = 29;
  int amdStiff_msz = 3;
  int amdStiff_lw = 5;
  int amdStiff_ls = 1;

  int pBUUSoft_mc = kBlue - 10;
  int pBUUSoft_fc = kBlue - 10;
  int pBUUSoft_fs = 3017;
  int pBUUSoft_ms = 32;
  int pBUUSoft_msz = 3;
  int pBUUSoft_lw = 5;
  int pBUUSoft_ls = 10;
  
  int pBUUStiff_mc = kRed - 10;
  int pBUUStiff_fc = kRed - 10;
  int pBUUStiff_fs = 3018;
  int pBUUStiff_ms = 23;
  int pBUUStiff_msz = 3;
  int pBUUStiff_lw = 5;
  int pBUUStiff_ls = 1;


  tuQMD_05_DR->SetFillColorAlpha(tuQMD_Soft_fc,.75);
  tuQMD_05_DR->SetFillStyle(tuQMD_Soft_fs);
  tuQMD_05_DR->SetMarkerColor(tuQMD_Soft_mc);
  tuQMD_05_DR->SetMarkerSize(tuQMD_Soft_msz);
  tuQMD_05_DR->SetMarkerStyle(tuQMD_Soft_ms);
  tuQMD_05_DR->SetLineStyle(tuQMD_Soft_ls);
  tuQMD_05_DR->SetLineColor(tuQMD_Soft_mc);
  tuQMD_05_DR->SetLineWidth(tuQMD_Soft_lw);

  tuQMD_20_DR->SetFillColorAlpha(tuQMD_Stiff_fc,.5);
  tuQMD_20_DR->SetFillStyle(tuQMD_Stiff_fs);
  tuQMD_20_DR->SetMarkerColor(tuQMD_Stiff_mc);
  tuQMD_20_DR->SetMarkerSize(tuQMD_Stiff_msz);
  tuQMD_20_DR->SetMarkerStyle(tuQMD_Stiff_ms);
  tuQMD_20_DR->SetLineStyle(tuQMD_Stiff_ls);
  tuQMD_20_DR->SetLineColor(tuQMD_Stiff_mc);
  tuQMD_20_DR->SetLineWidth(tuQMD_Stiff_lw);

  xbuu_DR->SetFillColorAlpha(xBUU_Soft_fc,.75);
  xbuu_DR->SetFillStyle(xBUU_Soft_fs);
  xbuu_DR->SetMarkerColor(xBUU_Soft_mc);
  xbuu_DR->SetMarkerStyle(xBUU_Soft_ms);
  xbuu_DR->SetMarkerSize(xBUU_Soft_msz);
  xbuu_DR->SetLineStyle(xBUU_Soft_ls);
  xbuu_DR->SetLineColor(xBUU_Soft_mc);
  xbuu_DR->SetLineWidth(xBUU_Soft_lw);

  xbuu120_DR->SetFillColorAlpha(xBUU_Stiff_fc,.5);
  xbuu120_DR->SetFillStyle(xBUU_Stiff_fs);
  xbuu120_DR->SetMarkerColor(xBUU_Stiff_mc);
  xbuu120_DR->SetMarkerStyle(xBUU_Stiff_ms);
  xbuu120_DR->SetMarkerSize(xBUU_Stiff_msz);
  xbuu120_DR->SetLineStyle(xBUU_Stiff_ls);
  xbuu120_DR->SetLineColor(xBUU_Stiff_mc);
  xbuu120_DR->SetLineWidth(xBUU_Stiff_lw);

  urQMD_46_DR->SetFillColorAlpha(urQMD_Soft_fc,.75);
  urQMD_46_DR->SetFillStyle(urQMD_Soft_fs);
  urQMD_46_DR->SetMarkerStyle(urQMD_Soft_ms);
  urQMD_46_DR->SetMarkerColor(urQMD_Soft_mc);
  urQMD_46_DR->SetMarkerSize(urQMD_Soft_msz);
  urQMD_46_DR->SetLineStyle(urQMD_Soft_ls);
  urQMD_46_DR->SetLineWidth(urQMD_Soft_lw);
  urQMD_46_DR->SetLineColor(urQMD_Soft_mc);

  urQMD_104_DR->SetFillColorAlpha(urQMD_Stiff_fc,.5);
  urQMD_104_DR->SetFillStyle(urQMD_Stiff_fs);
  urQMD_104_DR->SetMarkerStyle(urQMD_Stiff_ms);
  urQMD_104_DR->SetMarkerColor(urQMD_Stiff_mc);
  urQMD_104_DR->SetMarkerSize(urQMD_Stiff_msz);
  urQMD_104_DR->SetLineStyle(urQMD_Stiff_ls);
  urQMD_104_DR->SetLineWidth(urQMD_Stiff_lw);
  urQMD_104_DR->SetLineColor(urQMD_Stiff_mc);

  amdJAM55_DR->SetFillColorAlpha(amdSoft_fc,.75);
  amdJAM55_DR->SetFillStyle(amdSoft_fs);
  amdJAM55_DR->SetMarkerStyle(amdSoft_ms);
  amdJAM55_DR->SetMarkerColor(amdSoft_mc);
  amdJAM55_DR->SetMarkerSize(amdSoft_msz);
  amdJAM55_DR->SetLineStyle(amdSoft_ls);
  amdJAM55_DR->SetLineColor(amdSoft_mc);
  amdJAM55_DR->SetLineWidth(amdSoft_lw);

  amdJAM152_DR->SetFillColorAlpha(amdStiff_fc,.75);
  amdJAM152_DR->SetFillStyle(amdStiff_fs);
  amdJAM152_DR->SetMarkerStyle(amdStiff_ms);
  amdJAM152_DR->SetMarkerColor(amdStiff_mc);
  amdJAM152_DR->SetMarkerSize(amdStiff_msz);
  amdJAM152_DR->SetLineStyle(amdStiff_ls);
  amdJAM152_DR->SetLineColor(amdStiff_mc);
  amdJAM152_DR->SetLineWidth(amdStiff_lw);

  pBUU_soft_no_DR->SetFillColorAlpha(pBUUSoft_fc,.75);
  pBUU_soft_no_DR->SetFillStyle(pBUUSoft_fs);
  pBUU_soft_no_DR->SetMarkerStyle(pBUUSoft_ms);
  pBUU_soft_no_DR->SetMarkerColor(pBUUSoft_mc);
  pBUU_soft_no_DR->SetMarkerSize(pBUUSoft_msz);
  pBUU_soft_no_DR->SetLineStyle(pBUUSoft_ls);
  pBUU_soft_no_DR->SetLineColor(pBUUSoft_mc);
  pBUU_soft_no_DR->SetLineWidth(pBUUSoft_lw);

  pBUU_stiff_no_DR->SetFillColorAlpha(pBUUStiff_fc,.75);
  pBUU_stiff_no_DR->SetFillStyle(pBUUStiff_fs);
  pBUU_stiff_no_DR->SetMarkerStyle(pBUUStiff_ms);
  pBUU_stiff_no_DR->SetMarkerColor(pBUUStiff_mc);
  pBUU_stiff_no_DR->SetMarkerSize(pBUUStiff_msz);
  pBUU_stiff_no_DR->SetLineStyle(pBUUStiff_ls);
  pBUU_stiff_no_DR->SetLineColor(pBUUStiff_mc);
  pBUU_stiff_no_DR->SetLineWidth(pBUUStiff_lw);

  /*
    tuQMD_05_DR->Draw("same  LPO");
  xbuu_DR->Draw("same  LPO ");
  urQMD_46_DR->Draw("same  LPO");
  amdJAM55_DR->Draw("same  LPO ");
  pBUU_soft_no_DR->Draw("same  LPO ");


  pBUU_stiff_no_DR->Draw("same  LPO ");
  amdJAM152_DR->Draw("same  LPO ");
  urQMD_104_DR->Draw("same  LPO");
  xbuu120_DR->Draw("same  LPO");
  tuQMD_20_DR->Draw("same   LPO");

  tuQMD_05_DR->Draw("same  LPO");
  tuQMD_20_DR->Draw("same   LPO");
  xbuu_DR->Draw("same  LPO ");
  xbuu120_DR->Draw("same  LPO");
  urQMD_46_DR->Draw("same  LPO");
  urQMD_104_DR->Draw("same  LPO");
  amdJAM55_DR->Draw("same  LPO ");
  amdJAM152_DR->Draw("same  LPO ");
  pBUU_soft_no_DR->Draw("same  LPO ");
  pBUU_stiff_no_DR->Draw("same  LPO ");
  */

  /*
  double x[9] = {0,15,45,75,105,145,205,270,300};
  double y[9] = {50,22.6858,5.88988,3.11959,2.35538,2.1039,1.72789,1.51432,1.51432};
  double  xe[9] = {0,0,0,0,0,0,0,0,0};
  double  yel[9] = {44,16.6858,1.46488,1.09459,0.930383,0.678901,0.452894,0.53932,.53932};
  double  yeh[9] = {100,19.3142,1.38512,1.15541,0.869617,0.671099,0.447106,0.51068,.51068};
  TGraphAsymmErrors *boot_stiff = new TGraphAsymmErrors(9,x,y,xe,xe,yel,yeh);
  */

  double x[8] = {15,45,75,105,145,205,270,300};
  double y[8] = {13.3028,3.11978,1.47576,1.06175,0.920857,0.734321,0.706048,.706};
  double  xe[8] = {0,0,0,0,0,0,0,0};
  double  yel[8] = {11.3028,0.794781,0.50076,0.386746,0.245857,0.209321,0.331048,.33};
  double  yeh[8] = {16.6972,0.855219,0.54924,0.363254,0.354143,0.240679,0.268952,.26};
  TGraphAsymmErrors *boot_stiff = new TGraphAsymmErrors(8,x,y,xe,xe,yel,yeh);

  double x_soft[8] = {15,45,75,105,145,205,270,300};
  double y_soft[8] = {11.7306,3.16996,1.53014,1.10651,0.948678,0.762941,0.696651,.69};
  double  xe_soft[8] = {0,0,0,0,0,0,0,0};
  double  yel_soft[8] = {9.73065,0.844962,0.405141,0.431514,0.273678,0.237941,0.321651,.32};
  double  yeh_soft[8] = {14.2694,0.955038,0.494859,0.318486,0.326322,0.212059,0.278349,.27};
  TGraphAsymmErrors *boot_soft = new TGraphAsymmErrors(8,x_soft,y_soft,xe_soft,xe_soft,yel_soft,yeh_soft);

 for(int i = 0; i < 8; i++)
   {
     yeh_soft[i] += y_soft[i];
     yel_soft[i] = y_soft[i] - yel_soft[i];

     yeh[i] += y[i];
     yel[i] = y[i] - yel[i];
   }

 TGraph *soft_upper = new TGraph(8,x_soft,yeh_soft);
 soft_upper->SetLineStyle(2);
 soft_upper->SetLineColorAlpha(4,.75);
 soft_upper->SetLineWidth(4);

 TGraph *soft_lower = new TGraph(8,x_soft,yel_soft);
 soft_lower->SetLineStyle(2);
 soft_lower->SetLineColorAlpha(4,.75);
 soft_lower->SetLineWidth(4);

 TGraph *stiff_upper = new TGraph(8,x,yeh);
 stiff_upper->SetLineStyle(2);
 stiff_upper->SetLineColorAlpha(2,.75);
 stiff_upper->SetLineWidth(4);

 TGraph *stiff_lower = new TGraph(8,x,yel);
 stiff_lower->SetLineStyle(2);
 stiff_lower->SetLineColorAlpha(2,.75);
 stiff_lower->SetLineWidth(4);

  boot_stiff->SetLineStyle(10);
  boot_stiff->SetLineColor(2);  
  boot_stiff->SetLineWidth(4);
  
  boot_soft->SetLineStyle(10);
  boot_soft->SetLineColor(4);  
  boot_soft->SetLineWidth(4);

  TPaveText *p_soft = new TPaveText(5,4.2,80,4.5);
  p_soft->AddText("Theoretical Error");
  //  p_soft->SetTextColor(kBlue);
  p_soft->SetFillStyle(0);
  p_soft->SetBorderSize(0);

  TLegend *leg_soft = new TLegend(.15,.65,.4,.85);
  leg_soft->AddEntry(boot_soft,"Soft Theories","FL");
  leg_soft->AddEntry(boot_stiff,"Stiff Theories","FL");
  leg_soft->SetBorderSize(0);
  leg_soft->SetFillStyle(0);
  leg_soft->Draw();
  p_soft->Draw();

  TLegend *leg_stiff = new TLegend(.4,.75,.6,.85);
  leg_stiff->AddEntry(singleRatio_sn108,"Data","PLE");
  leg_stiff->SetFillStyle(0);
  leg_stiff->SetBorderSize(0);
  leg_stiff->Draw();
  
  boot_stiff->SetFillColorAlpha(kRed,.2);
  singleRatio_sn108->SetNdivisions(505);
  singleRatio_sn108->Draw("E1");
  boot_stiff->GetXaxis()->SetRangeUser(0,240);
  boot_stiff->GetYaxis()->SetRangeUser(.9,40);
  boot_stiff->Draw("CO E3");
  
  boot_soft->SetFillColorAlpha(kBlue,.2);
  boot_soft->Draw("same CO E3");
  soft_upper->Draw("C");
  soft_lower->Draw("C");
  
  stiff_upper->Draw("C");
  stiff_lower->Draw("C");

  singleRatio_sn108->DrawCopy("same E1");

  cvs->SetLogy();
  cvs->SaveAs("singleRatio_sn108_boot.png");




}
