#include "/home/justin/mythesis/thesis_style.h"

using namespace style;

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

void publishSingleSumAll()
{
  TFile *pBUU_soft_no_f = TFile::Open("/home/justin/Homework/pBUU/K210EM100/input_for_esym.info/pBUUSoft_r-1.root");
  TGraphErrors *pBUU_soft_no_132 = (TGraphErrors *) pBUU_soft_no_f->Get("piRatio132");
  TGraphErrors *pBUU_soft_no_108 = (TGraphErrors *) pBUU_soft_no_f->Get("piRatio108");
  
  TFile *pBUU_stiff_no_f = TFile::Open("/home/justin/Homework/pBUU/K210EM100/input_for_esym.info/pBUUStiff_r-1.root");
  TGraphErrors *pBUU_stiff_no_132 = (TGraphErrors *) pBUU_stiff_no_f->Get("piRatio132");
  TGraphErrors *pBUU_stiff_no_108 = (TGraphErrors *) pBUU_stiff_no_f->Get("piRatio108");
  
  TFile *amdJAM55_f = TFile::Open("/home/justin/Homework/AMDJAM/highStat/input_for_esym.info/AMDJAML55new_r-1.root");
  TGraphErrors *amdJAM55_132 = (TGraphErrors *) amdJAM55_f->Get("piRatio132");
  TGraphErrors *amdJAM55_108 = (TGraphErrors *) amdJAM55_f->Get("piRatio108");
  
  TFile *amdJAM152_f = TFile::Open("/home/justin/Homework/AMDJAM/highStat/input_for_esym.info/AMDJAML152new_r-1.root");
  TGraphErrors *amdJAM152_132 = (TGraphErrors *) amdJAM152_f->Get("piRatio132");
  TGraphErrors *amdJAM152_108 = (TGraphErrors *) amdJAM152_f->Get("piRatio108");

  TFile *urQMD_46_f = TFile::Open("/home/justin/Homework/UrQMD/input_for_esym.info/UrQMDL46_r-1.root");
  TGraphErrors *urQMD_46_132 = (TGraphErrors *) urQMD_46_f->Get("piRatio132");
  TGraphErrors *urQMD_46_108 = (TGraphErrors *) urQMD_46_f->Get("piRatio108");
  
  TFile *urQMD_104_f = TFile::Open("/home/justin/Homework/UrQMD/input_for_esym.info/UrQMDL104_r-1.root");
  TGraphErrors *urQMD_104_132 = (TGraphErrors *) urQMD_104_f->Get("piRatio132");
  TGraphErrors *urQMD_104_108 = (TGraphErrors *) urQMD_104_f->Get("piRatio108");
  

  TFile *imQMD_05_f = TFile::Open("/home/justin/Homework/IQMD-BNU/input_for_esym.info/IQMD-BNUg05_r-1.root");
  TGraphErrors *imQMD_05_132 = (TGraphErrors *) imQMD_05_f->Get("piRatio132");
  TGraphErrors *imQMD_05_108 = (TGraphErrors *) imQMD_05_f->Get("piRatio108");
  
  TFile *imQMD_20_f = TFile::Open("/home/justin/Homework/IQMD-BNU/input_for_esym.info/IQMD-BNUg20_r-1.root");
  TGraphErrors *imQMD_20_132 = (TGraphErrors *) imQMD_20_f->Get("piRatio132");
  TGraphErrors *imQMD_20_108 = (TGraphErrors *) imQMD_20_f->Get("piRatio108");

  TFile *tuQMD_05_f = TFile::Open("/home/justin/Homework/TuQMD/new-highStat/input_for_esym.info/TuQMDg05_r-1.root");
  TGraphErrors *tuQMD_05_132 = (TGraphErrors *) tuQMD_05_f->Get("piRatio132");
  TGraphErrors *tuQMD_05_108 = (TGraphErrors *) tuQMD_05_f->Get("piRatio108");
  
  TFile *tuQMD_20_f = TFile::Open("/home/justin/Homework/TuQMD/new-highStat/input_for_esym.info/TuQMDg20_r-1.root");
  TGraphErrors *tuQMD_20_132 = (TGraphErrors *) tuQMD_20_f->Get("piRatio132");
  TGraphErrors *tuQMD_20_108 = (TGraphErrors *) tuQMD_20_f->Get("piRatio108");

  TFile *xbuu_f = TFile::Open("/home/justin/Homework/xBUU/old/input_for_esym.info/xBUU_r-1.root");
  TGraphErrors *xbuu_132 = (TGraphErrors *) xbuu_f->Get("piRatio132");
  TGraphErrors *xbuu_108 = (TGraphErrors *) xbuu_f->Get("piRatio108");
  
  TFile *xbuu120_f = TFile::Open("/home/justin/Homework/xBUU/new/input_for_esym.info/xBUU_skyrmeL120_r-1.root");
  TGraphErrors *xbuu120_132 = (TGraphErrors *) xbuu120_f->Get("piRatio132");
  TGraphErrors *xbuu120_108 = (TGraphErrors *) xbuu120_f->Get("piRatio108");
  
  auto xbuu_132_sum = CombineGraph(xbuu_132,xbuu120_132);
  auto tuQMD_132_sum = CombineGraph(tuQMD_05_132,tuQMD_20_132);
  auto imQMD_132_sum = CombineGraph(imQMD_05_132,imQMD_20_132);
  auto urQMD_132_sum = CombineGraph(urQMD_46_132,urQMD_104_132);
  auto amdJAM_132_sum = CombineGraph(amdJAM55_132,amdJAM152_132);
  auto pBUU_132_sum = CombineGraph(pBUU_stiff_no_132,pBUU_soft_no_132);

  auto xbuu_108_sum = CombineGraph(xbuu_108,xbuu120_108);
  auto tuQMD_108_sum = CombineGraph(tuQMD_05_108,tuQMD_20_108);
  auto imQMD_108_sum = CombineGraph(imQMD_05_108,imQMD_20_108);
  auto urQMD_108_sum = CombineGraph(urQMD_46_108,urQMD_104_108);
  auto amdJAM_108_sum = CombineGraph(amdJAM55_108,amdJAM152_108);
  auto pBUU_108_sum = CombineGraph(pBUU_stiff_no_108,pBUU_soft_no_108);

  TFile *f = TFile::Open("/home/justin/mythesis/macrosForThesis/PionSpectra/rootfiles/publishPions_sm.root");
  TH1D *singleRatio_sn132 = (TH1D *)f->Get("singleRatio_sn132");
  TH1D *singleRatio_sn108 = (TH1D *)f->Get("singleRatio_sn108");

  make(singleRatio_sn108);
  make(singleRatio_sn132);

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
  leg->AddEntry(singleRatio_sn132,"{}^{132}Sn +{}^{124}Sn","lpe");

  TCanvas *cvs = style::stdcvs();
  cvs->Divide(2,1,0,0);
  
  singleRatio_sn132->GetYaxis()->SetRangeUser(.95,15);
  singleRatio_sn132->GetYaxis()->SetTitle("#pi^{-}/#pi^{+}");
  singleRatio_sn132->GetYaxis()->CenterTitle();
  singleRatio_sn132->GetXaxis()->SetTitle("E_{#scale[.6]{COM}} (MeV)");
  singleRatio_sn132->GetXaxis()->CenterTitle();
  
  singleRatio_sn132->SetLineWidth(5);
  singleRatio_sn132->SetLineStyle(lineS132);
  singleRatio_sn132->SetLineColor(lineC132);
  singleRatio_sn132->SetMarkerStyle(markS132);
  singleRatio_sn132->SetMarkerSize(markSz132);
  singleRatio_sn132->SetMarkerColor(markC132);
  //  singleRatio_sn132->Draw("L E1");
  //singleRatio_sn132->DrawCopy("same hist L");
  
  singleRatio_sn108->SetLineWidth(5);
  singleRatio_sn108->SetLineStyle(lineS108);
  singleRatio_sn108->SetLineColor(lineC108);
  singleRatio_sn108->SetMarkerStyle(markS108);
  singleRatio_sn108->SetMarkerSize(markSz108);
  singleRatio_sn108->SetMarkerColor(markC108);
  //  singleRatio_sn108->Draw("same E1");
  //  singleRatio_sn108->DrawCopy("same hist L");
  leg->SetBorderSize(0);

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
  
  tuQMD_132_sum->SetFillColorAlpha(tuQMD_Soft_fc,.5);
  tuQMD_132_sum->SetFillStyle(tuQMD_Soft_fs);
  tuQMD_132_sum->SetMarkerColor(tuQMD_Soft_mc);
  tuQMD_132_sum->SetMarkerSize(tuQMD_Soft_msz);
  tuQMD_132_sum->SetMarkerStyle(tuQMD_Soft_ms);
  tuQMD_132_sum->SetLineStyle(tuQMD_Soft_ls);
  tuQMD_132_sum->SetLineColor(tuQMD_Soft_mc);
  tuQMD_132_sum->SetLineWidth(tuQMD_Soft_lw);

  xbuu_132_sum->SetFillColorAlpha(xBUU_Soft_fc,.5);
  xbuu_132_sum->SetFillStyle(xBUU_Soft_fs);
  xbuu_132_sum->SetMarkerColor(xBUU_Soft_mc);
  xbuu_132_sum->SetMarkerStyle(xBUU_Soft_ms);
  xbuu_132_sum->SetMarkerSize(xBUU_Soft_msz);
  xbuu_132_sum->SetLineStyle(xBUU_Soft_ls);
  xbuu_132_sum->SetLineColor(xBUU_Soft_mc);
  xbuu_132_sum->SetLineWidth(xBUU_Soft_lw);

  urQMD_132_sum->SetFillColorAlpha(urQMD_Soft_fc,.5);
  urQMD_132_sum->SetFillStyle(urQMD_Soft_fs);
  urQMD_132_sum->SetMarkerStyle(urQMD_Soft_ms);
  urQMD_132_sum->SetMarkerColor(urQMD_Soft_mc);
  urQMD_132_sum->SetMarkerSize(urQMD_Soft_msz);
  urQMD_132_sum->SetLineStyle(urQMD_Soft_ls);
  urQMD_132_sum->SetLineWidth(urQMD_Soft_lw);
  urQMD_132_sum->SetLineColor(urQMD_Soft_mc);

  imQMD_132_sum->SetFillColorAlpha(imQMD_Soft_fc,.5);
  imQMD_132_sum->SetFillStyle(imQMD_Soft_fs);
  imQMD_132_sum->SetMarkerStyle(imQMD_Soft_ms);
  imQMD_132_sum->SetMarkerColor(imQMD_Soft_mc);
  imQMD_132_sum->SetMarkerSize(imQMD_Soft_msz);
  imQMD_132_sum->SetLineStyle(imQMD_Soft_ls);
  imQMD_132_sum->SetLineWidth(imQMD_Soft_lw);
  imQMD_132_sum->SetLineColor(imQMD_Soft_mc);

  amdJAM_132_sum->SetFillColorAlpha(amdSoft_fc,.5);
  amdJAM_132_sum->SetFillStyle(amdSoft_fs);
  amdJAM_132_sum->SetMarkerStyle(amdSoft_ms);
  amdJAM_132_sum->SetMarkerColor(amdSoft_mc);
  amdJAM_132_sum->SetMarkerSize(amdSoft_msz);
  amdJAM_132_sum->SetLineStyle(amdSoft_ls);
  amdJAM_132_sum->SetLineColor(amdSoft_mc);
  amdJAM_132_sum->SetLineWidth(amdSoft_lw);

  pBUU_132_sum->SetFillColorAlpha(pBUUSoft_fc,.5);
  pBUU_132_sum->SetFillStyle(pBUUSoft_fs);
  pBUU_132_sum->SetMarkerStyle(pBUUSoft_ms);
  pBUU_132_sum->SetMarkerColor(pBUUSoft_mc);
  pBUU_132_sum->SetMarkerSize(pBUUSoft_msz);
  pBUU_132_sum->SetLineStyle(pBUUSoft_ls);
  pBUU_132_sum->SetLineColor(pBUUSoft_mc);
  pBUU_132_sum->SetLineWidth(pBUUSoft_lw);






  tuQMD_108_sum->SetFillColorAlpha(tuQMD_Soft_fc,.5);
  tuQMD_108_sum->SetFillStyle(tuQMD_Soft_fs);
  tuQMD_108_sum->SetMarkerColor(tuQMD_Soft_mc);
  tuQMD_108_sum->SetMarkerSize(tuQMD_Soft_msz);
  tuQMD_108_sum->SetMarkerStyle(tuQMD_Soft_ms);
  tuQMD_108_sum->SetLineStyle(tuQMD_Soft_ls);
  tuQMD_108_sum->SetLineColor(tuQMD_Soft_mc);
  tuQMD_108_sum->SetLineWidth(tuQMD_Soft_lw);

  xbuu_108_sum->SetFillColorAlpha(xBUU_Soft_fc,.5);
  xbuu_108_sum->SetFillStyle(xBUU_Soft_fs);
  xbuu_108_sum->SetMarkerColor(xBUU_Soft_mc);
  xbuu_108_sum->SetMarkerStyle(xBUU_Soft_ms);
  xbuu_108_sum->SetMarkerSize(xBUU_Soft_msz);
  xbuu_108_sum->SetLineStyle(xBUU_Soft_ls);
  xbuu_108_sum->SetLineColor(xBUU_Soft_mc);
  xbuu_108_sum->SetLineWidth(xBUU_Soft_lw);

  urQMD_108_sum->SetFillColorAlpha(urQMD_Soft_fc,.5);
  urQMD_108_sum->SetFillStyle(urQMD_Soft_fs);
  urQMD_108_sum->SetMarkerStyle(urQMD_Soft_ms);
  urQMD_108_sum->SetMarkerColor(urQMD_Soft_mc);
  urQMD_108_sum->SetMarkerSize(urQMD_Soft_msz);
  urQMD_108_sum->SetLineStyle(urQMD_Soft_ls);
  urQMD_108_sum->SetLineWidth(urQMD_Soft_lw);
  urQMD_108_sum->SetLineColor(urQMD_Soft_mc);

  imQMD_108_sum->SetFillColorAlpha(imQMD_Soft_fc,.5);
  imQMD_108_sum->SetFillStyle(imQMD_Soft_fs);
  imQMD_108_sum->SetMarkerStyle(imQMD_Soft_ms);
  imQMD_108_sum->SetMarkerColor(imQMD_Soft_mc);
  imQMD_108_sum->SetMarkerSize(imQMD_Soft_msz);
  imQMD_108_sum->SetLineStyle(imQMD_Soft_ls);
  imQMD_108_sum->SetLineWidth(imQMD_Soft_lw);
  imQMD_108_sum->SetLineColor(imQMD_Soft_mc);

  amdJAM_108_sum->SetFillColorAlpha(amdSoft_fc,.5);
  amdJAM_108_sum->SetFillStyle(amdSoft_fs);
  amdJAM_108_sum->SetMarkerStyle(amdSoft_ms);
  amdJAM_108_sum->SetMarkerColor(amdSoft_mc);
  amdJAM_108_sum->SetMarkerSize(amdSoft_msz);
  amdJAM_108_sum->SetLineStyle(amdSoft_ls);
  amdJAM_108_sum->SetLineColor(amdSoft_mc);
  amdJAM_108_sum->SetLineWidth(amdSoft_lw);

  pBUU_108_sum->SetFillColorAlpha(pBUUSoft_fc,.5);
  pBUU_108_sum->SetFillStyle(pBUUSoft_fs);
  pBUU_108_sum->SetMarkerStyle(pBUUSoft_ms);
  pBUU_108_sum->SetMarkerColor(pBUUSoft_mc);
  pBUU_108_sum->SetMarkerSize(pBUUSoft_msz);
  pBUU_108_sum->SetLineStyle(pBUUSoft_ls);
  pBUU_108_sum->SetLineColor(pBUUSoft_mc);
  pBUU_108_sum->SetLineWidth(pBUUSoft_lw);

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

  TLegend *leg_soft = new TLegend(.67,.56,.97,.85);
  leg_soft->AddEntry(tuQMD_132_sum,"TuQMD","FL");
  //  leg_soft->AddEntry(urQMD_132_sum,"urQMD","FL");
  leg_soft->AddEntry(imQMD_132_sum,"ImQMD","FL");
  leg_soft->AddEntry(xbuu_132_sum,"#chiBUU","FL");
  leg_soft->AddEntry(amdJAM_132_sum,"AMD + JAM","FL");
  leg_soft->AddEntry(pBUU_132_sum,"pBUU","FL");

  leg_soft->SetBorderSize(0);
  leg_soft->SetFillStyle(0);
  //  leg_soft->Draw();
  //  p_soft->Draw();
  //  p_stiff->Draw();
  
  TLegend *leg_stiff = new TLegend(.41,.55,.66,.85);
  leg_stiff->AddEntry(singleRatio_sn132,"{}^{132}Sn +{}^{124}Sn","lpe");

  leg_stiff->SetFillStyle(0);
  leg_stiff->SetBorderSize(0);

  singleRatio_sn132->GetXaxis()->SetNdivisions(505);
  cvs->cd(1);
  cvs->cd(1)->SetFillColorAlpha(kWhite,.0);
  cvs->cd(1)->SetLogy();
  singleRatio_sn132->Draw("L E1");
  pBUU_132_sum->Draw("same  LE3 ");
  imQMD_132_sum->Draw("same  LE3");
  xbuu_132_sum->Draw("same  LE3 ");
  tuQMD_132_sum->Draw("same  LE3");
  amdJAM_132_sum->Draw("same  LE3 ");
  //  urQMD_132_sum->Draw("same  LE3");
  singleRatio_sn132->DrawCopy("same L E1");  
  leg_soft->Draw();
  leg_stiff->Draw();

  cvs->cd(2);
  cvs->cd(2)->SetLogy();
  singleRatio_sn108->GetXaxis()->SetNdivisions(505);
  singleRatio_sn108->GetXaxis()->SetRangeUser(-.5,240);
  singleRatio_sn108->Draw("L Y+ E1");
  pBUU_108_sum->Draw("same  LE3 ");
  imQMD_108_sum->Draw("same  LE3");
  xbuu_108_sum->Draw("same  LE3 ");
  tuQMD_108_sum->Draw("same  LE3");
  amdJAM_108_sum->Draw("same  LE3 ");
  //  urQMD_108_sum->Draw("same  LE3");
  singleRatio_sn108->DrawCopy("same L E1");  
  leg_soft->Draw();
  leg_stiff->Draw();



  cvs->SaveAs("singleRatioAllSum.png");

}

