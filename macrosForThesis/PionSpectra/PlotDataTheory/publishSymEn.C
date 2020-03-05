#include "/home/justin/mythesis/thesis_style.h"

using namespace style;

void publishSymEn()
{
  TFile *pBUU_soft_no_f = TFile::Open("/home/justin/Homework/pBUU/K210EM100/input_for_esym.info/pBUUSoft_r-1.root");
  TF1 *pBUU_soft_no_DR = (TF1 *) pBUU_soft_no_f->Get("Srho");

  TFile *pBUU_stiff_no_f = TFile::Open("/home/justin/Homework/pBUU/K210EM100/input_for_esym.info/pBUUStiff_r-1.root");
  TF1 *pBUU_stiff_no_DR = (TF1 *) pBUU_stiff_no_f->Get("Srho");

  TFile *amdJAM55_f = TFile::Open("/home/justin/Homework/AMDJAM/highStat/input_for_esym.info/AMDJAML55new_r-1.root");
  TF1 *amdJAM55_DR = (TF1 *) amdJAM55_f->Get("Srho");

  TFile *amdJAM152_f = TFile::Open("/home/justin/Homework/AMDJAM/highStat/input_for_esym.info/AMDJAML152new_r-1.root");
  TF1 *amdJAM152_DR = (TF1 *) amdJAM152_f->Get("Srho");


  TFile *urQMD_46_f = TFile::Open("/home/justin/Homework/UrQMD/input_for_esym.info/UrQMDL46_r-1.root");
  TF1 *urQMD_46_DR = (TF1 *) urQMD_46_f->Get("Srho");

  TFile *urQMD_104_f = TFile::Open("/home/justin/Homework/UrQMD/input_for_esym.info/UrQMDL104_r-1.root");
  TF1 *urQMD_104_DR = (TF1 *) urQMD_104_f->Get("Srho");


  TFile *imQMD_05_f = TFile::Open("/home/justin/Homework/IQMD-BNU/input_for_esym.info/IQMD-BNUg05_r-1.root");
  TF1 *imQMD_05_DR = (TF1 *) imQMD_05_f->Get("Srho");

  TFile *imQMD_20_f = TFile::Open("/home/justin/Homework/IQMD-BNU/input_for_esym.info/IQMD-BNUg20_r-1.root");
  TF1 *imQMD_20_DR = (TF1 *) imQMD_20_f->Get("Srho");



  TFile *tuQMD_05_f = TFile::Open("/home/justin/Homework/TuQMD/new-highStat/input_for_esym.info/TuQMDg05_r-1.root");
  TF1 *tuQMD_05_DR = (TF1 *) tuQMD_05_f->Get("Srho");

  TFile *tuQMD_20_f = TFile::Open("/home/justin/Homework/TuQMD/new-highStat/input_for_esym.info/TuQMDg20_r-1.root");
  TF1 *tuQMD_20_DR = (TF1 *) tuQMD_20_f->Get("Srho");


  TFile *xbuu_f = TFile::Open("/home/justin/Homework/xBUU/old/input_for_esym.info/xBUU_r-1.root");
  TF1 *xbuu_DR = (TF1 *) xbuu_f->Get("Srho");

  /*
  TFile *xbuu120_f = TFile::Open("/home/justin/Homework/xBUU/new/input_for_esym.info/xBUU_skyrmeL120_r-1.root");
  TF1 *xbuu120_DR = (TF1 *) xbuu120_f->Get("Srho");
  */
  //  gStyle->SetEndErrorSize(0);

  //  TLegend *leg = new TLegend(.2,.2,.55,.5);
  TCanvas *cvs = style::stdcvs();
  //  TCanvas *cvs = new TCanvas("c1","c1",1);
  
  int tuQMD_Soft_mc = kOrange - 4;
  int tuQMD_Soft_ms = 24;
  int tuQMD_Soft_msz = 3;
  int tuQMD_Soft_ls = 10;
  int tuQMD_Soft_lw = 10;
  
  int xBUU_Soft_mc = kBlue - 4;
  int xBUU_Soft_ms = 28;
  int xBUU_Soft_msz = 3;
  int xBUU_Soft_lw = 10;
  int xBUU_Soft_ls = 10;
  
  int urQMD_Soft_mc = kGreen - 4;
  int urQMD_Soft_ms = 26;
  int urQMD_Soft_msz = 3;
  int urQMD_Soft_lw = 10;
  int urQMD_Soft_ls = 10;

  int imQMD_Soft_mc = kCyan - 4;
  int imQMD_Soft_ms = 26;
  int imQMD_Soft_msz = 3;
  int imQMD_Soft_lw = 10;
  int imQMD_Soft_ls = 10;

  int amdSoft_mc = kMagenta - 4;
  int amdSoft_ms = 30;
  int amdSoft_msz = 3;
  int amdSoft_lw = 10;
  int amdSoft_ls = 10;

  int pBUUSoft_mc = kRed - 4;
  int pBUUSoft_ms = 32;
  int pBUUSoft_msz = 3;
  int pBUUSoft_lw = 10;
  int pBUUSoft_ls = 10;


  int tuQMD_Stiff_mc = kOrange;
  int tuQMD_Stiff_ms = 24;
  int tuQMD_Stiff_msz = 3;
  int tuQMD_Stiff_ls = 1;
  int tuQMD_Stiff_lw = 10;
  
  int xBUU_Stiff_mc = kBlue;
  int xBUU_Stiff_ms = 28;
  int xBUU_Stiff_msz = 3;
  int xBUU_Stiff_lw = 10;
  int xBUU_Stiff_ls = 1;
  
  int urQMD_Stiff_mc = kGreen;
  int urQMD_Stiff_ms = 26;
  int urQMD_Stiff_msz = 3;
  int urQMD_Stiff_lw = 10;
  int urQMD_Stiff_ls = 1;

  int imQMD_Stiff_mc = kCyan;
  int imQMD_Stiff_ms = 26;
  int imQMD_Stiff_msz = 3;
  int imQMD_Stiff_lw = 10;
  int imQMD_Stiff_ls = 1;

  int amdStiff_mc = kMagenta;
  int amdStiff_ms = 30;
  int amdStiff_msz = 3;
  int amdStiff_lw = 10;
  int amdStiff_ls = 1;

  int pBUUStiff_mc = kRed;
  int pBUUStiff_ms = 32;
  int pBUUStiff_msz = 3;
  int pBUUStiff_lw = 10;
  int pBUUStiff_ls = 1;

  
  tuQMD_05_DR->SetLineStyle(tuQMD_Soft_ls);
  tuQMD_05_DR->SetLineColor(tuQMD_Soft_mc);
  tuQMD_05_DR->SetLineWidth(tuQMD_Soft_lw);

  tuQMD_20_DR->SetLineStyle(tuQMD_Stiff_ls);
  tuQMD_20_DR->SetLineColor(tuQMD_Stiff_mc);
  tuQMD_20_DR->SetLineWidth(tuQMD_Stiff_lw);

  xbuu_DR->SetLineStyle(xBUU_Soft_ls);
  xbuu_DR->SetLineColor(xBUU_Soft_mc);
  xbuu_DR->SetLineWidth(xBUU_Soft_lw);

  amdJAM55_DR->SetLineStyle(amdSoft_ls);
  amdJAM55_DR->SetLineColor(amdSoft_mc);
  amdJAM55_DR->SetLineWidth(amdSoft_lw);

  amdJAM152_DR->SetLineStyle(amdStiff_ls);
  amdJAM152_DR->SetLineColor(amdStiff_mc);
  amdJAM152_DR->SetLineWidth(amdStiff_lw);

  pBUU_soft_no_DR->SetFillColorAlpha(0,0);
  pBUU_soft_no_DR->SetLineStyle(2);
  pBUU_soft_no_DR->SetLineColor(pBUUSoft_mc);
  pBUU_soft_no_DR->SetLineWidth(pBUUSoft_lw);

  pBUU_stiff_no_DR->SetFillColorAlpha(0,0);
  pBUU_stiff_no_DR->SetLineStyle(pBUUStiff_ls);
  pBUU_stiff_no_DR->SetLineColor(pBUUStiff_mc);
  pBUU_stiff_no_DR->SetLineWidth(pBUUStiff_lw);

  /*
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

  TLegend *leg_soft = new TLegend(.3,.6,.45,.9);
  leg_soft->AddEntry(tuQMD_05_DR,"TuQMD","L");
  leg_soft->AddEntry(xbuu_DR,"#chiBUU","L");
  leg_soft->AddEntry(amdJAM55_DR,"AMD + JAM","L");
  leg_soft->AddEntry(pBUU_soft_no_DR,"pBUU","L");
  leg_soft->SetBorderSize(0);
  leg_soft->SetFillStyle(0);

  TLegend *leg_stiff = new TLegend(.15,.6,.3,.9);
  leg_stiff->AddEntry(tuQMD_20_DR,"TuQMD","L");
  //  leg_stiff->AddEntry(xbuu120_DR,"#chiBUU","L");
  leg_stiff->AddEntry(amdJAM152_DR,"AMD + JAM","L");
  leg_stiff->AddEntry(pBUU_stiff_no_DR,"pBUU","L");
  leg_stiff->SetBorderSize(0);
  leg_stiff->SetFillStyle(0);
  
  pBUU_stiff_no_DR->GetXaxis()->SetRangeUser(0,3);
  pBUU_stiff_no_DR->GetYaxis()->SetRangeUser(0,150);
  pBUU_stiff_no_DR->SetTitle("");
  pBUU_stiff_no_DR->GetXaxis()->SetTitle("#rho/#rho_{o}");
  pBUU_stiff_no_DR->GetYaxis()->SetTitle("S_{energy}");
  pBUU_stiff_no_DR->GetXaxis()->CenterTitle();
  pBUU_stiff_no_DR->GetYaxis()->CenterTitle();

  */

  pBUU_stiff_no_DR->Draw("");
  pBUU_soft_no_DR->SetLineStyle(4);
  pBUU_soft_no_DR->Draw("same");

  
  tuQMD_05_DR->Draw("same L");
  tuQMD_20_DR->Draw("same L");

  xbuu_DR->Draw("same L");
  //  xbuu120_DR->Draw("same  L");

  amdJAM55_DR->Draw("same L");
  amdJAM152_DR->Draw("same  L ");

  //  leg_soft->Draw();
  //  leg_stiff->Draw();
  
  cvs->SaveAs("SymEnergy.png");

}
