#include "/home/justin/mythesis/thesis_style.h"

using namespace style;

void publishPionRatios()
{

  TFile *f = TFile::Open("publishPions_multcomp_2.root");
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
  singleRatio_sn132->GetXaxis()->SetTitle("T_{#scale[.6]{COM}} (MeV)");
  singleRatio_sn132->GetXaxis()->CenterTitle();
  
  singleRatio_sn132->SetLineWidth(5);
  singleRatio_sn132->SetLineStyle(lineS132);
  singleRatio_sn132->SetLineColor(lineC132);
  singleRatio_sn132->SetMarkerStyle(markS132);
  singleRatio_sn132->SetMarkerSize(markSz132);
  singleRatio_sn132->SetMarkerColor(markC132);
  singleRatio_sn132->Draw("L E1");
  //singleRatio_sn132->DrawCopy("same hist L");
  
  singleRatio_sn108->SetLineWidth(5);
  singleRatio_sn108->SetLineStyle(lineS108);
  singleRatio_sn108->SetLineColor(lineC108);
  singleRatio_sn108->SetMarkerStyle(markS108);
  singleRatio_sn108->SetMarkerSize(markSz108);
  singleRatio_sn108->SetMarkerColor(markC108);
  singleRatio_sn108->Draw("same E1");
  //  singleRatio_sn108->DrawCopy("same hist L");
  leg->SetBorderSize(0);
  leg->Draw("same");
  
  cvs->SaveAs("singleRatio.png");

  TCanvas *cvs_2 = style::stdcvs("cvs_2");
  doubleRatio->GetYaxis()->SetTitle("Double Ratio");
  doubleRatio->GetYaxis()->CenterTitle();
  doubleRatio->GetXaxis()->SetTitle("T_{#scale[.6]{COM}} (MeV)");
  doubleRatio->GetXaxis()->CenterTitle();

  doubleRatio->GetYaxis()->SetRangeUser(0,5);
  doubleRatio->SetLineWidth(5);
  doubleRatio->SetLineStyle(1);
  doubleRatio->SetLineColor(4);
  doubleRatio->SetMarkerStyle(21);
  doubleRatio->SetMarkerSize(3);
  doubleRatio->SetMarkerColor(4);
  doubleRatio->Draw("E1");
  //  doubleRatio->DrawCopy("same hist C");

  cvs_2->SaveAs("doubleRatio.png");




}
