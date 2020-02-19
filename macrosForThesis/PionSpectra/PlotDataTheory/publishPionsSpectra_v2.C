#include "/home/justin/mythesis/thesis_style.h"
using namespace style;

void publishPionsSpectra_v2()
{
  gStyle->SetOptStat(0);
  gStyle->SetLineWidth(6);
  
  TFile *f = TFile::Open("publishPions.root");
  TH1D * pim_sn108 = (TH1D *)f->Get("pim_sn108");
  TH1D * pip_sn108 = (TH1D *)f->Get("pip_sn108");

  TH1D * pim_sn132 = (TH1D *)f->Get("pim_sn132");
  TH1D * pip_sn132 = (TH1D *)f->Get("pip_sn132");

  TH1D *singleRatio_sn132 = (TH1D *)f->Get("singleRatio_sn132");
  TH1D *singleRatio_sn108 = (TH1D *)f->Get("singleRatio_sn108");

  TH1D *doubleRatio = (TH1D *)f->Get("doubleRatio");


  make(pim_sn108);
  make(pim_sn132);
  make(pip_sn108);
  make(pip_sn132);
  make(singleRatio_sn108);
  make(singleRatio_sn132);
  make(doubleRatio);

  gStyle->SetLineWidth(6);

  int pim_marker = 20;
  int pip_marker = 20;
  int singlesn132 = 20;
  int singlesn108 = 20;
  int doubler = 20; 

  gStyle->SetEndErrorSize(0);

  //style
  int lineS132pim = 1; 
  int lineS132pip = 1;

  int lineS108pim = 7;
  int lineS108pip = 7;



  int markS132pim = 20;
  int markS108pim = 24;  

  int markS132pip = 21;
  int markS108pip = 25;  

  //color
  int lineC132pim = kRed -4; 
  int lineC108pim = kBlue -7;

  int lineC132pip = kRed - 4;
  int lineC108pip = kBlue - 7;

  int markC132pim = kRed - 4;
  int markC108pim = kBlue- 7;  

  int markC132pip = kRed - 4;
  int markC108pip = kBlue - 7;  

  //size
  int markSz132pim = 2; //marker size
  int markSz108pim = 2; //marker size 

  int markSz132pip = 2; //marker size
  int markSz108pip = 2; //marker size 

  //  TLegend *leg = new TLegend(.2,.2,.55,.5);
  TLegend *leg = new TLegend(.65,.65,.8,.95);
  //  leg->SetHeader("#pi^{-}");
  leg->AddEntry(pim_sn132,"","elp");
  leg->AddEntry(pim_sn108,"","elp");

  TLegend *leg_2 = new TLegend(.7,.65,.9,.95);
  //  leg_2->SetHeader("#pi^{+}");
  //  leg_2->AddEntry(pip_sn132,"Sn132 + Sn124","elp");
  //  leg_2->AddEntry(pip_sn108,"Sn108 + Sn112","elp");
  leg_2->AddEntry(pip_sn132,"","elp");
  leg_2->AddEntry(pip_sn108,"","elp");


  TPaveText *t = new TPaveText(.75,.65,.9,.95,"NDC");
   t->AddText("{}^{132}Sn + {}^{108}Sn"); ((TText*)t->GetListOfLines()->Last())->SetTextColor(markC132pip);
   t->AddText("{}^{108}Sn + {}^{112}Sn");  ((TText*)t->GetListOfLines()->Last())->SetTextColor(markC108pim);
   t->SetFillStyle(0);
   t->SetBorderSize(0);
   
  TLatex latex;
  latex.SetTextSize(.05);
  latex.SetTextAlign(12);
  
  //  TCanvas *cvs = new TCanvas("c1","c1",1080,1920);
  TCanvas *cvs = stdcvs();
  cvs->SetLeftMargin(.14);
  gStyle->SetLineWidth(6);
  cvs->SetFrameLineWidth(6);
  cvs->SetLogy();

  pim_sn132->GetYaxis()->SetTitle("dN/^{}dE (MeV^{-1})");
  pim_sn132->GetYaxis()->CenterTitle();
  pim_sn132->GetYaxis()->SetTitleOffset(1.1);
  pim_sn132->GetXaxis()->SetTitle("T_{#scale[.6]{COM}} (MeV)");
  pim_sn132->GetXaxis()->CenterTitle();
  
  pim_sn132->GetYaxis()->SetRangeUser(1e-6,2e-2);
  pim_sn132->SetLineWidth(5);
  pim_sn132->SetLineStyle(lineS132pim);
  pim_sn132->SetLineColor(lineC132pim);
  pim_sn132->SetMarkerStyle(markS132pim);
  pim_sn132->SetMarkerSize(markSz132pim);
  pim_sn132->SetMarkerColor(markC132pim);
  pim_sn132->SetLineWidth(6);
  pim_sn132->Draw("E1");

  pim_sn108->SetLineWidth(6);
  pim_sn108->SetLineStyle(lineS108pim);
  pim_sn108->SetLineColor(lineC108pim);
  pim_sn108->SetMarkerStyle(markS108pim);
  pim_sn108->SetMarkerSize(markSz108pim);
  pim_sn108->SetMarkerColor(markC108pim);
  pim_sn108->Draw("same E1");

  leg->SetBorderSize(0);
  leg->SetFillStyle(0);
  leg->Draw("same");
  latex.DrawLatex(198.,5.3e-4,"#pi^{-}");
  latex.DrawLatex(218.,5.5e-4,"#pi^{+}");
  t->Draw("same");
  //  leg_2->AddEntry(pip_sn132,"{}^{132}Sn +{}^{124}Sn","elp");
  //  leg_2->AddEntry(pip_sn108,"{}^{108}Sn +{}^{112}Sn","elp");
  
  pip_sn132->GetYaxis()->SetTitle("d^2N/dEd#Omega");
  pip_sn132->GetYaxis()->CenterTitle();
  pip_sn132->GetXaxis()->SetTitle("T_{#scale[.6]{COM}} (MeV)");
  pip_sn132->GetXaxis()->CenterTitle();

  pip_sn132->Scale(1e-1);
  pip_sn108->Scale(1e-1);

  //  pip_sn132->Scale(1./5);
  //  pip_sn108->Scale(1./5);

  //  pip_sn132->GetYaxis()->SetRangeUser(1e-5,3e-3);
  pip_sn132->SetLineWidth(5);
  pip_sn132->SetLineStyle(lineS132pip);
  pip_sn132->SetLineColor(lineC132pip);
  pip_sn132->SetMarkerStyle(markS132pip);
  pip_sn132->SetMarkerSize(markSz132pip);
  pip_sn132->SetMarkerColor(markC132pip);
  pip_sn132->SetLineWidth(6);
  pip_sn132->Draw("same E1");

  pip_sn108->SetLineWidth(5);
  pip_sn108->SetLineStyle(lineS108pip);
  pip_sn108->SetLineColor(lineC108pip);
  pip_sn108->SetMarkerStyle(markS108pip);
  pip_sn108->SetMarkerSize(markSz108pip);
  pip_sn108->SetMarkerColor(markC108pip);
  pip_sn108->SetLineWidth(6);
  pip_sn108->Draw("same E1");

  leg_2->SetBorderSize(0);
  leg_2->SetFillStyle(0);
  leg_2->Draw("same");

  cvs->SaveAs("pionSpectra.png");


}
