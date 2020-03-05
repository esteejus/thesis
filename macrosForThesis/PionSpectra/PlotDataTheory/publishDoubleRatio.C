#include "/home/justin/mythesis/thesis_style.h"

using namespace style;

void publishDoubleRatio()
{
  TFile *pBUU_soft_no_f = TFile::Open("/home/justin/Homework/pBUU/K210EM100/input_for_esym.info/pBUUSoft_r-1.root");
  TGraphErrors *pBUU_soft_no_DR = (TGraphErrors *) pBUU_soft_no_f->Get("doubleRatio");

  TFile *pBUU_stiff_no_f = TFile::Open("/home/justin/Homework/pBUU/K210EM100/input_for_esym.info/pBUUStiff_r-1.root");
  TGraphErrors *pBUU_stiff_no_DR = (TGraphErrors *) pBUU_stiff_no_f->Get("doubleRatio");

  /*
 TFile *pBUU_soft_no_f = TFile::Open("/home/justin/Homework/pBUU/K265EM070/input_for_esym.info/pBUUSoft_r-1.root");
  TGraphErrors *pBUU_soft_no_DR = (TGraphErrors *) pBUU_soft_no_f->Get("doubleRatio");

TFile *pBUU_stiff_no_f = TFile::Open("/home/justin/Homework/pBUU/K265EM070/input_for_esym.info/pBUUStiff_r-1.root");
  TGraphErrors *pBUU_stiff_no_DR = (TGraphErrors *) pBUU_stiff_no_f->Get("doubleRatio");
  */

  TFile *amdJAM55_f = TFile::Open("/home/justin/Homework/AMDJAM/highStat/input_for_esym.info/AMDJAML55new_r-1.root");
  TGraphErrors *amdJAM55_DR = (TGraphErrors *) amdJAM55_f->Get("doubleRatio");

  TFile *amdJAM152_f = TFile::Open("/home/justin/Homework/AMDJAM/highStat/input_for_esym.info/AMDJAML152new_r-1.root");
  TGraphErrors *amdJAM152_DR = (TGraphErrors *) amdJAM152_f->Get("doubleRatio");


  TFile *urQMD_46_f = TFile::Open("/home/justin/Homework/UrQMD/input_for_esym.info/UrQMDL46_r-1.root");
  TGraphErrors *urQMD_46_DR = (TGraphErrors *) urQMD_46_f->Get("doubleRatio");

  TFile *urQMD_104_f = TFile::Open("/home/justin/Homework/UrQMD/input_for_esym.info/UrQMDL104_r-1.root");
  TGraphErrors *urQMD_104_DR = (TGraphErrors *) urQMD_104_f->Get("doubleRatio");


  TFile *imQMD_05_f = TFile::Open("/home/justin/Homework/IQMD-BNU/input_for_esym.info/IQMD-BNUg05_r-1.root");
  TGraphErrors *imQMD_05_DR = (TGraphErrors *) imQMD_05_f->Get("doubleRatio");

  TFile *imQMD_20_f = TFile::Open("/home/justin/Homework/IQMD-BNU/input_for_esym.info/IQMD-BNUg20_r-1.root");
  TGraphErrors *imQMD_20_DR = (TGraphErrors *) imQMD_20_f->Get("doubleRatio");



  TFile *tuQMD_05_f = TFile::Open("/home/justin/Homework/TuQMD/new-highStat/input_for_esym.info/TuQMDg05_r-1.root");
  TGraphErrors *tuQMD_05_DR = (TGraphErrors *) tuQMD_05_f->Get("doubleRatio");

  TFile *tuQMD_20_f = TFile::Open("/home/justin/Homework/TuQMD/new-highStat/input_for_esym.info/TuQMDg20_r-1.root");
  TGraphErrors *tuQMD_20_DR = (TGraphErrors *) tuQMD_20_f->Get("doubleRatio");


  TFile *xbuu_f = TFile::Open("/home/justin/Homework/xBUU/old/input_for_esym.info/xBUU_r-1.root");
  TGraphErrors *xbuu_DR = (TGraphErrors *) xbuu_f->Get("doubleRatio");

  TFile *xbuu120_f = TFile::Open("/home/justin/Homework/xBUU/new/input_for_esym.info/xBUU_skyrmeL120_r-1.root");
  TGraphErrors *xbuu120_DR = (TGraphErrors *) xbuu120_f->Get("doubleRatio");


  TFile *f = TFile::Open("/home/justin/mythesis/macrosForThesis/PionSpectra/rootfiles/publishPions_sm.root");
  TH1D *doubleRatio = (TH1D *)f->Get("doubleRatio");

  make(doubleRatio);

  gStyle->SetEndErrorSize(0);

  TCanvas *cvs_2 = style::stdcvs("cvs_2");
  doubleRatio->GetYaxis()->SetTitle("Double Ratio");
  doubleRatio->GetYaxis()->CenterTitle();
  doubleRatio->GetXaxis()->SetTitle("T_{#scale[.6]{COM}} (MeV)");
  doubleRatio->GetXaxis()->CenterTitle();

  doubleRatio->GetYaxis()->SetRangeUser(1.1,4);
  doubleRatio->SetLineWidth(5);
  doubleRatio->SetLineStyle(1);
  doubleRatio->SetLineColor(1);
  doubleRatio->SetMarkerStyle(21);
  doubleRatio->SetMarkerSize(3);
  doubleRatio->SetMarkerColor(1);
  //  doubleRatio->Draw("E1");
 
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
  int tuQMD_Stiff_ls = 10;
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
  int xBUU_Stiff_ls = 10;
 
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
  int urQMD_Stiff_ls = 10;

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
  int amdStiff_ls = 10;

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
  int pBUUStiff_ls = 10;


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

  TPaveText *p_soft = new TPaveText(0,3.7,60,4);
  p_soft->AddText("Soft");
  p_soft->SetTextColor(kBlue);
  p_soft->SetFillStyle(0);
  p_soft->SetBorderSize(0);
  
  TPaveText *p_stiff = new TPaveText(60,3.7,120,4);
  p_stiff->AddText("Stiff");
  p_stiff->SetTextColor(kRed);
  p_stiff->SetFillStyle(0);
  p_stiff->SetBorderSize(0);

  TLegend *leg_soft = new TLegend(.15,.7,.4,.85);
  //  leg_soft->AddEntry(pBUU_soft_no_DR,"pBUU","lpe");
  leg_soft->AddEntry(xbuu_DR,"#chiBUU","lpe");
  leg_soft->AddEntry(tuQMD_05_DR,"TuQMD","lpe");
  //  leg_soft->AddEntry(amdJAM55_DR,"AMD+JAM","lpe");
  //  leg_soft->AddEntry(urQMD_46_DR,"urQMD","lpe");

  leg_soft->SetBorderSize(0);
  leg_soft->SetFillStyle(0);
  leg_soft->Draw();
  p_soft->Draw();
  p_stiff->Draw();
  
  TLegend *leg_stiff = new TLegend(.35,.7,.6,.85);
  //  leg_stiff->AddEntry(pBUU_stiff_no_DR,"pBUU","lpe");
  leg_stiff->AddEntry(xbuu120_DR,"#chiBUU","lpe");
  leg_stiff->AddEntry(tuQMD_20_DR,"TuQMD","lpe");
  //  leg_stiff->AddEntry(amdJAM152_DR,"AMD+JAM","lpe");
  //  leg_stiff->AddEntry(urQMD_104_DR,"urQMD","lpe");

  leg_stiff->SetFillStyle(0);
  leg_stiff->SetBorderSize(0);

  //  cvs_2->cd(1);
  doubleRatio->Draw("E1");
  //  pBUU_stiff_no_DR->Draw("same  LPO ");
  //  amdJAM152_DR->Draw("same  LPO ");
  //  urQMD_104_DR->Draw("same  LPO");
  xbuu120_DR->Draw("same  LPO");
  tuQMD_20_DR->Draw("same   LPO");
  p_stiff->Draw();
  
  leg_stiff->Draw();
  //  doubleRatio->DrawCopy("same E1");
  //  cvs_2->SaveAs("doubleRatio_stiff.png");

  //  cvs_2->cd(2);
  //  doubleRatio->Draw("E1");
  tuQMD_05_DR->Draw("same  LPO");
  xbuu_DR->Draw("same  LPO ");
  //  urQMD_46_DR->Draw("same  LPO");
  //  amdJAM55_DR->Draw("same  LPO ");
  //  pBUU_soft_no_DR->Draw("same  LPO ");
  leg_soft->Draw();
  p_soft->Draw();
  
  doubleRatio->DrawCopy("same E1");
  cvs_2->SaveAs("doubleRatio_pannel.png");

}
