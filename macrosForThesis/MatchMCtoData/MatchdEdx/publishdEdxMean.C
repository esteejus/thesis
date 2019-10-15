#include "/home/justin/mythesis/thesis_style.h"

using namespace style;

void publishdEdx()
{
  TFile *f = TFile::Open("mc_dedx.root");
  TGraph *mean_mc = (TGraph *)f->Get("mean_g");
  TGraph *sigma_mc = (TGraph *)f->Get("sigma_g");  

  TFile *g = TFile::Open("data_dedx.root");
  TGraph *mean_d = (TGraph *)g->Get("mean_g");
  TGraph *sigma_d = (TGraph *)g->Get("sigma_g");  

  mean_d->GetYaxis()->SetTitle("dE/dx arb. units");
  mean_d->GetXaxis()->SetTitle("Momentum MeV/c");  
  
  TCanvas *cvs = style::stdcvs();
  make(mean_d);
  make(mean_mc);
  make(sigma_d);
  make(sigma_mc);
  
  mean_d->SetLineColor(2);
  mean_mc->SetLineColor(4);
  sigma_d->SetLineColor(2);
  sigma_mc->SetLineColor(4);

  mean_d->GetXaxis()->SetRangeUser(40,400);
  mean_d->GetYaxis()->SetRangeUser(10,300);

  mean_d->SetMarkerStyle(20);
  mean_mc->SetMarkerStyle(20);
  mean_d->SetMarkerSize(5);
  mean_mc->SetMarkerSize(5);
  mean_d->SetMarkerColor(2);
  mean_mc->SetMarkerColor(4);
  
  mean_d->Draw("APO");
  mean_mc->Draw("same PO");

  auto leg = new TLegend(.5,.6,.7,.5);
  leg->AddEntry(mean_d,"Data","le");
  leg->AddEntry(mean_mc,"MC","le");
  leg->SetBorderSize(0);
  leg->Draw("same");
  cvs->SetLogx();
  cvs->SetLogy();
  cvs->SaveAs("dedxcompare.png");
  cvs->SaveAs("dedxcompare.jpg");

}

