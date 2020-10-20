#include "/home/justin/mythesis/thesis_style.h"

using namespace style;

TGraphErrors * Divide(TGraphErrors *a, TGraphErrors *b)
{
  int a_num = a->GetN();
  int b_num = b->GetN();

  double x[a_num], y[a_num], ey[a_num], ex[a_num];

  if(a_num != b_num)
    cout<<"Graph points NOT EQUAL!!!"<<endl;

  for(int i = 0; i < a_num; i++)
    {
      double xx,y_a,y_b;
      a->GetPoint(i,xx,y_a);
      b->GetPoint(i,xx,y_b);

     double ey_a = a->GetErrorY(i);
     double ey_b = b->GetErrorY(i);
      
      x[i] = xx;
      y[i] = y_a/y_b;
      ex[i] = 0;
      ey[i] = (y_a/y_b)*sqrt( pow(ey_a/y_a,2) + pow(ey_b/y_b,2)) ;
    }

  return (new TGraphErrors(a_num,x,y,ex,ey));
}


TGraphErrors * CombineGraph(TGraphErrors *a, TGraphErrors *b, double scale = 1)
{
  int a_num = a->GetN();
  int b_num = b->GetN();

  double x[a_num], y[a_num], ey[a_num], ex[a_num];

  if(a_num != b_num)
    cout<<"Graph points NOT EQUAL!!!"<<endl;

  for(int i = 0; i < a_num; i++)
    {
      double xx,y_a,y_b;
      a->GetPoint(i,xx,y_a);
      b->GetPoint(i,xx,y_b);
      y_a *= scale;
      y_b *= scale;

      x[i] = xx;
      y[i] = (y_a + y_b)/2.;
      ex[i] = 0;
      ey[i] = abs(y[i] - y_a);
    }

  return (new TGraphErrors(a_num,x,y,ex,ey));
}

void publishIsoScale_pip()
{
  gStyle->SetLineWidth(8);

  TFile *pBUU_soft_no_f_132 = TFile::Open("/home/justin/Homework/pBUU/K210EM100/input_for_esym.info/pBUUSoft_r-1.root");
  TGraphErrors *pBUU_soft_no_pim_132 = (TGraphErrors *) pBUU_soft_no_f_132->Get("pim132");
  TGraphErrors *pBUU_soft_no_pip_132 = (TGraphErrors *) pBUU_soft_no_f_132->Get("pip132");
  TGraphErrors *pBUU_soft_no_pim_108 = (TGraphErrors *) pBUU_soft_no_f_132->Get("pim108");
  TGraphErrors *pBUU_soft_no_pip_108 = (TGraphErrors *) pBUU_soft_no_f_132->Get("pip108");
  auto pBUU_soft_pim = Divide(pBUU_soft_no_pim_132,pBUU_soft_no_pim_108);
  auto pBUU_soft_pip = Divide(pBUU_soft_no_pip_132,pBUU_soft_no_pip_108);


  TFile *pBUU_stiff_no_f_132 = TFile::Open("/home/justin/Homework/pBUU/K210EM100/input_for_esym.info/pBUUStiff_r-1.root");
  TGraphErrors *pBUU_stiff_no_pim_132 = (TGraphErrors *) pBUU_stiff_no_f_132->Get("pim132");
  TGraphErrors *pBUU_stiff_no_pip_132 = (TGraphErrors *) pBUU_stiff_no_f_132->Get("pip132");
  TGraphErrors *pBUU_stiff_no_pim_108 = (TGraphErrors *) pBUU_stiff_no_f_132->Get("pim108");
  TGraphErrors *pBUU_stiff_no_pip_108 = (TGraphErrors *) pBUU_stiff_no_f_132->Get("pip108");
  auto pBUU_stiff_pim = Divide(pBUU_stiff_no_pim_132,pBUU_stiff_no_pim_108);
  auto pBUU_stiff_pip = Divide(pBUU_stiff_no_pip_132,pBUU_stiff_no_pip_108);
 
 
  TFile *amdJAM55_f_132 = TFile::Open("/home/justin/Homework/AMDJAM/highStat/input_for_esym.info/AMDJAML55new_r-1.root");
  TGraphErrors *amdJAM55_pim_132 = (TGraphErrors *) amdJAM55_f_132->Get("pim132");
  TGraphErrors *amdJAM55_pip_132 = (TGraphErrors *) amdJAM55_f_132->Get("pip132");
  TGraphErrors *amdJAM55_pim_108 = (TGraphErrors *) amdJAM55_f_132->Get("pim108");
  TGraphErrors *amdJAM55_pip_108 = (TGraphErrors *) amdJAM55_f_132->Get("pip108");
  auto amdJAM55_pim = Divide(amdJAM55_pim_132,amdJAM55_pim_108);
  auto amdJAM55_pip = Divide(amdJAM55_pip_132,amdJAM55_pip_108);

  
  TFile *amdJAM152_f_132 = TFile::Open("/home/justin/Homework/AMDJAM/highStat/input_for_esym.info/AMDJAML152new_r-1.root");
  TGraphErrors *amdJAM152_pim_132 = (TGraphErrors *) amdJAM152_f_132->Get("pim132");
  TGraphErrors *amdJAM152_pip_132 = (TGraphErrors *) amdJAM152_f_132->Get("pip132");
  TGraphErrors *amdJAM152_pim_108 = (TGraphErrors *) amdJAM152_f_132->Get("pim108");
  TGraphErrors *amdJAM152_pip_108 = (TGraphErrors *) amdJAM152_f_132->Get("pip108");
  auto amdJAM152_pim = Divide(amdJAM152_pim_132,amdJAM152_pim_108);
  auto amdJAM152_pip = Divide(amdJAM152_pip_132,amdJAM152_pip_108);

  TFile *urQMD_46_f_132 = TFile::Open("/home/justin/Homework/UrQMD/input_for_esym.info/UrQMDL46_r-1.root");
  TGraphErrors *urQMD_46_pim_132 = (TGraphErrors *) urQMD_46_f_132->Get("pim132");
  TGraphErrors *urQMD_46_pip_132 = (TGraphErrors *) urQMD_46_f_132->Get("pip132");
  TGraphErrors *urQMD_46_pim_108 = (TGraphErrors *) urQMD_46_f_132->Get("pim108");
  TGraphErrors *urQMD_46_pip_108 = (TGraphErrors *) urQMD_46_f_132->Get("pip108");
  auto urQMD_46_pim = Divide(urQMD_46_pim_132,urQMD_46_pim_108);
  auto urQMD_46_pip = Divide(urQMD_46_pip_132,urQMD_46_pip_108);
  
  
  TFile *urQMD_104_f_132 = TFile::Open("/home/justin/Homework/UrQMD/input_for_esym.info/UrQMDL104_r-1.root");
  TGraphErrors *urQMD_104_pim_132 = (TGraphErrors *) urQMD_104_f_132->Get("pim132"); 
  TGraphErrors *urQMD_104_pip_132 = (TGraphErrors *) urQMD_104_f_132->Get("pip132"); 
  TGraphErrors *urQMD_104_pim_108 = (TGraphErrors *) urQMD_104_f_132->Get("pim108"); 
  TGraphErrors *urQMD_104_pip_108 = (TGraphErrors *) urQMD_104_f_132->Get("pip108"); 
  auto urQMD_104_pim = Divide(urQMD_104_pim_132,urQMD_104_pim_108);
  auto urQMD_104_pip = Divide(urQMD_104_pip_132,urQMD_104_pip_108);

  TFile *imQMD_05_f_132 = TFile::Open("/home/justin/Homework/IQMD-BNU/input_for_esym.info/IQMD-BNUg05_r-1.root");
  TGraphErrors *imQMD_05_pim_132 = (TGraphErrors *) imQMD_05_f_132->Get("pim132");
  TGraphErrors *imQMD_05_pip_132 = (TGraphErrors *) imQMD_05_f_132->Get("pip132");
  TGraphErrors *imQMD_05_pim_108 = (TGraphErrors *) imQMD_05_f_132->Get("pim108");
  TGraphErrors *imQMD_05_pip_108 = (TGraphErrors *) imQMD_05_f_132->Get("pip108");
  auto imQMD_05_pip = Divide(imQMD_05_pip_132,imQMD_05_pip_108);
  auto imQMD_05_pim = Divide(imQMD_05_pim_132,imQMD_05_pim_108);

  
  TFile *imQMD_20_f_132 = TFile::Open("/home/justin/Homework/IQMD-BNU/input_for_esym.info/IQMD-BNUg20_r-1.root");
  TGraphErrors *imQMD_20_pim_132 = (TGraphErrors *) imQMD_20_f_132->Get("pim132");
  TGraphErrors *imQMD_20_pip_132 = (TGraphErrors *) imQMD_20_f_132->Get("pip132");
  TGraphErrors *imQMD_20_pim_108 = (TGraphErrors *) imQMD_20_f_132->Get("pim108");
  TGraphErrors *imQMD_20_pip_108 = (TGraphErrors *) imQMD_20_f_132->Get("pip108");
  auto imQMD_20_pip = Divide(imQMD_20_pip_132,imQMD_20_pip_108);
  auto imQMD_20_pim = Divide(imQMD_20_pim_132,imQMD_20_pim_108);


  TFile *tuQMD_05_f_132 = TFile::Open("/home/justin/Homework/TuQMD/new-highStat/input_for_esym.info/TuQMDg05_r-1.root");
  TGraphErrors *tuQMD_05_pim_132 = (TGraphErrors *) tuQMD_05_f_132->Get("pim132");
  TGraphErrors *tuQMD_05_pip_132 = (TGraphErrors *) tuQMD_05_f_132->Get("pip132");
  TGraphErrors *tuQMD_05_pim_108 = (TGraphErrors *) tuQMD_05_f_132->Get("pim108");
  TGraphErrors *tuQMD_05_pip_108 = (TGraphErrors *) tuQMD_05_f_132->Get("pip108");
  auto tuQMD_05_pim = Divide(tuQMD_05_pim_132,tuQMD_05_pim_108); 
  auto tuQMD_05_pip = Divide(tuQMD_05_pip_132,tuQMD_05_pip_108); 

  TFile *tuQMD_20_f_132 = TFile::Open("/home/justin/Homework/TuQMD/new-highStat/input_for_esym.info/TuQMDg20_r-1.root");
  TGraphErrors *tuQMD_20_pim_132 = (TGraphErrors *) tuQMD_20_f_132->Get("pim132");
  TGraphErrors *tuQMD_20_pip_132 = (TGraphErrors *) tuQMD_20_f_132->Get("pip132");
  TGraphErrors *tuQMD_20_pim_108 = (TGraphErrors *) tuQMD_20_f_132->Get("pim108");
  TGraphErrors *tuQMD_20_pip_108 = (TGraphErrors *) tuQMD_20_f_132->Get("pip108");
  auto tuQMD_20_pim = Divide(tuQMD_20_pim_132,tuQMD_20_pim_108); 
  auto tuQMD_20_pip = Divide(tuQMD_20_pip_132,tuQMD_20_pip_108); 
  

  TFile *xbuu_f = TFile::Open("/home/justin/Homework/xBUU/old/input_for_esym.info/xBUU_r-1.root");
  TGraphErrors *xbuu_pim_132 = (TGraphErrors *) xbuu_f->Get("pim132");
  TGraphErrors *xbuu_pip_132 = (TGraphErrors *) xbuu_f->Get("pip132");
  TGraphErrors *xbuu_pim_108 = (TGraphErrors *) xbuu_f->Get("pim108");
  TGraphErrors *xbuu_pip_108 = (TGraphErrors *) xbuu_f->Get("pip108");
  auto xbuu_pim = Divide(xbuu_pim_132,xbuu_pim_108);
  auto xbuu_pip = Divide(xbuu_pip_132,xbuu_pip_108);


  TFile *xbuu120_f = TFile::Open("/home/justin/Homework/xBUU/new/input_for_esym.info/xBUU_skyrmeL120_r-1.root");
  TGraphErrors *xbuu120_pim_132 = (TGraphErrors *) xbuu120_f->Get("pim132");
  TGraphErrors *xbuu120_pip_132 = (TGraphErrors *) xbuu120_f->Get("pip132");
  TGraphErrors *xbuu120_pim_108 = (TGraphErrors *) xbuu120_f->Get("pim108");
  TGraphErrors *xbuu120_pip_108 = (TGraphErrors *) xbuu120_f->Get("pip108");

  auto xbuu120_pim = Divide(xbuu120_pim_132,xbuu120_pim_108);
  auto xbuu120_pip = Divide(xbuu120_pip_132,xbuu120_pip_108);

  auto imQMD_sum_pim = CombineGraph(imQMD_05_pim,imQMD_20_pim);
  auto imQMD_sum_pip = CombineGraph(imQMD_05_pip,imQMD_20_pip);

  auto tuQMD_sum_pim = CombineGraph(tuQMD_05_pim,tuQMD_20_pim);
  auto tuQMD_sum_pip = CombineGraph(tuQMD_05_pip,tuQMD_20_pip);
 
  auto xbuu_sum_pim = CombineGraph(xbuu_pim, xbuu120_pim);
  auto xbuu_sum_pip = CombineGraph(xbuu_pip, xbuu120_pip);

  auto urQMD_sum_pim = CombineGraph(urQMD_46_pim,urQMD_104_pim);
  auto urQMD_sum_pip = CombineGraph(urQMD_46_pip,urQMD_104_pip);
  
  auto amdJAM_sum_pim = CombineGraph(amdJAM55_pim,amdJAM152_pim);
  auto amdJAM_sum_pip = CombineGraph(amdJAM55_pip,amdJAM152_pip);
  
  auto pBUU_sum_pim = CombineGraph(pBUU_stiff_pim,pBUU_soft_pim);
  auto pBUU_sum_pip = CombineGraph(pBUU_stiff_pip,pBUU_soft_pip);
  

  //  TFile *f = TFile::Open("/home/justin/mythesis/macrosForThesis/PionSpectra/rootfiles/publishPions_sm.root");
  TFile *f = TFile::Open("/home/justin/mythesis/macrosForThesis/PionSpectra/rootfiles/publishPions_08_26_2020.root");
  
  TH1D *pim_sn132 = (TH1D *)f->Get("pim_sn132");
  TH1D *pip_sn132 = (TH1D *)f->Get("pip_sn132");
  TH1D *pim_sn108 = (TH1D *)f->Get("pim_sn108");
  TH1D *pip_sn108 = (TH1D *)f->Get("pip_sn108");

  make(pim_sn132);
  make(pip_sn132);
  make(pim_sn108);
  make(pip_sn108);

  pim_sn132->Divide(pim_sn108);
  pip_sn132->Divide(pip_sn108);

  gStyle->SetEndErrorSize(0);

  //style
  int lineS132 = 1; 
  int lineS108 = 1;

  int markS132 = 21;
  int markS108 = 21;  

  //color
  int lineC132 = 1; 
  int lineC108 = 1;

  int markC132 = 1;
  int markC108 = 1;  

  //size
  int markSz132 = 2; //marker size
  int markSz108 = 2; //marker size 

  //  TLegend *leg = new TLegend(.2,.2,.55,.5);
  TLegend *leg = new TLegend(.3,.5,.8,.8);
  leg->AddEntry(pip_sn132,"#pi^{+}","lpe");

  TCanvas *cvs = style::stdcvs();
  //  cvs->SetLogy();
  //  singleRatio_sn132->GetYaxis()->SetRangeUser(.5,20);
  
  pip_sn132->GetYaxis()->SetRangeUser(.1,1.2);
  pip_sn132->GetYaxis()->SetTitle("#pi^{+}_{132}/#pi^{+}_{108}");
  pip_sn132->GetYaxis()->CenterTitle();
  pip_sn132->GetXaxis()->SetTitle("E_{#scale[.6]{COM}} (MeV)");
  pip_sn132->GetXaxis()->CenterTitle();
  
  pip_sn132->SetLineWidth(5);
  pip_sn132->SetLineStyle(lineS132);
  pip_sn132->SetLineColor(lineC132);
  pip_sn132->SetMarkerStyle(markS132);
  pip_sn132->SetMarkerSize(markSz132);
  pip_sn132->SetMarkerColor(markC132);
  //  pip_sn132->Draw("L E1");
  //pip_sn132->DrawCopy("same hist L");
  
  pip_sn108->SetLineWidth(5);
  pip_sn108->SetLineStyle(lineS108);
  pip_sn108->SetLineColor(lineC108);
  pip_sn108->SetMarkerStyle(markS108);
  pip_sn108->SetMarkerSize(markSz108);
  pip_sn108->SetMarkerColor(markC108);
  //  pip_sn108->Draw("same E1");
  //  pip_sn108->DrawCopy("same hist L");
  leg->SetBorderSize(0);
  leg->Draw("same");
  
  cvs->SaveAs("pip.png");


  int tuQMD_Soft_mc = kOrange - 0;
  int tuQMD_Soft_fc = kOrange - 0;
  int tuQMD_Soft_fs = 1;
  int tuQMD_Soft_ms = 24;
  int tuQMD_Soft_msz = 3;
  int tuQMD_Soft_ls = 4;
  int tuQMD_Soft_lw = 10;
  
  int xBUU_Soft_mc = kBlue - 4;
  int xBUU_Soft_fc = kBlue - 4;
  int xBUU_Soft_fs = 1;
  int xBUU_Soft_ms = 28;
  int xBUU_Soft_msz = 3;
  int xBUU_Soft_lw = 10;
  int xBUU_Soft_ls = 1;
  
  int urQMD_Soft_mc = kGreen - 7;
  int urQMD_Soft_fc = kGreen - 7;
  int urQMD_Soft_fs = 1;
  int urQMD_Soft_ms = 26;
  int urQMD_Soft_msz = 3;
  int urQMD_Soft_lw = 10;
  int urQMD_Soft_ls = 7;

  int imQMD_Soft_mc = kCyan;
  int imQMD_Soft_fc = kCyan;
  int imQMD_Soft_fs = 1;
  int imQMD_Soft_ms = 26;
  int imQMD_Soft_msz = 3;
  int imQMD_Soft_lw = 10;
  int imQMD_Soft_ls = 7;

  int amdSoft_mc = kMagenta - 9;
  int amdSoft_fc = kMagenta - 9;
  int amdSoft_fs = 1;
  int amdSoft_ms = 30;
  int amdSoft_msz = 3;
  int amdSoft_lw = 10;
  int amdSoft_ls = 9;

  int pBUUSoft_mc = kRed - 7;
  int pBUUSoft_fc = kRed - 7;
  int pBUUSoft_fs = 1;
  int pBUUSoft_ms = 32;
  int pBUUSoft_msz = 3;
  int pBUUSoft_lw = 10;
  int pBUUSoft_ls = 10;
  

  tuQMD_sum_pip->SetFillColorAlpha(tuQMD_Soft_fc,.5);
  tuQMD_sum_pip->SetFillStyle(tuQMD_Soft_fs);
  tuQMD_sum_pip->SetMarkerColor(tuQMD_Soft_mc);
  tuQMD_sum_pip->SetMarkerSize(tuQMD_Soft_msz);
  tuQMD_sum_pip->SetMarkerStyle(tuQMD_Soft_ms);
  tuQMD_sum_pip->SetLineStyle(tuQMD_Soft_ls);
  tuQMD_sum_pip->SetLineColor(tuQMD_Soft_mc);
  tuQMD_sum_pip->SetLineWidth(tuQMD_Soft_lw);

  xbuu_sum_pip->SetFillColorAlpha(xBUU_Soft_fc,.5);
  xbuu_sum_pip->SetFillStyle(xBUU_Soft_fs);
  xbuu_sum_pip->SetMarkerColor(xBUU_Soft_mc);
  xbuu_sum_pip->SetMarkerStyle(xBUU_Soft_ms);
  xbuu_sum_pip->SetMarkerSize(xBUU_Soft_msz);
  xbuu_sum_pip->SetLineStyle(xBUU_Soft_ls);
  xbuu_sum_pip->SetLineColor(xBUU_Soft_mc);
  xbuu_sum_pip->SetLineWidth(xBUU_Soft_lw);

  urQMD_sum_pip->SetFillColorAlpha(urQMD_Soft_fc,.5);
  urQMD_sum_pip->SetFillStyle(urQMD_Soft_fs);
  urQMD_sum_pip->SetMarkerStyle(urQMD_Soft_ms);
  urQMD_sum_pip->SetMarkerColor(urQMD_Soft_mc);
  urQMD_sum_pip->SetMarkerSize(urQMD_Soft_msz);
  urQMD_sum_pip->SetLineStyle(urQMD_Soft_ls);
  urQMD_sum_pip->SetLineWidth(urQMD_Soft_lw);
  urQMD_sum_pip->SetLineColor(urQMD_Soft_mc);

  imQMD_sum_pip->SetFillColorAlpha(imQMD_Soft_fc,.5);
  imQMD_sum_pip->SetFillStyle(imQMD_Soft_fs);
  imQMD_sum_pip->SetMarkerStyle(imQMD_Soft_ms);
  imQMD_sum_pip->SetMarkerColor(imQMD_Soft_mc);
  imQMD_sum_pip->SetMarkerSize(imQMD_Soft_msz);
  imQMD_sum_pip->SetLineStyle(imQMD_Soft_ls);
  imQMD_sum_pip->SetLineWidth(imQMD_Soft_lw);
  imQMD_sum_pip->SetLineColor(imQMD_Soft_mc);

  amdJAM_sum_pip->SetFillColorAlpha(amdSoft_fc,.5);
  amdJAM_sum_pip->SetFillStyle(amdSoft_fs);
  amdJAM_sum_pip->SetMarkerStyle(amdSoft_ms);
  amdJAM_sum_pip->SetMarkerColor(amdSoft_mc);
  amdJAM_sum_pip->SetMarkerSize(amdSoft_msz);
  amdJAM_sum_pip->SetLineStyle(amdSoft_ls);
  amdJAM_sum_pip->SetLineColor(amdSoft_mc);
  amdJAM_sum_pip->SetLineWidth(amdSoft_lw);

  pBUU_sum_pip->SetFillColorAlpha(pBUUSoft_fc,.5);
  pBUU_sum_pip->SetFillStyle(pBUUSoft_fs);
  pBUU_sum_pip->SetMarkerStyle(pBUUSoft_ms);
  pBUU_sum_pip->SetMarkerColor(pBUUSoft_mc);
  pBUU_sum_pip->SetMarkerSize(pBUUSoft_msz);
  pBUU_sum_pip->SetLineStyle(pBUUSoft_ls);
  pBUU_sum_pip->SetLineColor(pBUUSoft_mc);
  pBUU_sum_pip->SetLineWidth(pBUUSoft_lw);

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

  TLegend *leg_soft = new TLegend(.67,.2,.97,.45);
  leg_soft->AddEntry(tuQMD_sum_pip,"TuQMD","FL");
  leg_soft->AddEntry(urQMD_sum_pip,"urQMD","FL");
  leg_soft->AddEntry(imQMD_sum_pip,"IQMD-BNU","FL");
  leg_soft->AddEntry(xbuu_sum_pip,"#chiBUU","FL");
  leg_soft->AddEntry(amdJAM_sum_pip,"AMD + JAM","FL");
  leg_soft->AddEntry(pBUU_sum_pip,"pBUU","FL");

  leg_soft->SetBorderSize(0);
  leg_soft->SetFillStyle(0);
  leg_soft->Draw();
  //  p_soft->Draw();
  //  p_stiff->Draw();
  
  TLegend *leg_stiff = new TLegend(.41,.25,.66,.35);
  leg_stiff->AddEntry(pip_sn132,"Data","lpe");

  leg_stiff->SetFillStyle(0);
  leg_stiff->SetBorderSize(0);

  pip_sn132->GetXaxis()->SetNdivisions(505);
  pip_sn132->Draw("L E1");
 
  pBUU_sum_pip->Draw("same  LE3 ");
  imQMD_sum_pip->Draw("same  LE3");
  xbuu_sum_pip->Draw("same  LE3 ");
  tuQMD_sum_pip->Draw("same  LE3");
  amdJAM_sum_pip->Draw("same  LE3 ");
  urQMD_sum_pip->Draw("same  LE3");
 
  pip_sn132->DrawCopy("same L E1");  

  for(int i = 1; i <= pip_sn132->GetNbinsX(); i++)
    cout<<pip_sn132->GetBinCenter(i)<<",";
  cout<<endl;

  for(int i = 1; i <= pip_sn132->GetNbinsX(); i++)
    cout<<pip_sn132->GetBinContent(i)<<",";
  cout<<endl;
  
  leg_soft->Draw();
  leg_stiff->Draw();
  cvs->SaveAs("pip_132_sum.png");




}

