#include "/home/justin/mythesis/thesis_style.h"

using namespace style;

void publishdEdxSigma()
{
  TFile *f = TFile::Open("mc_dedx.root");
  TGraph *sigma_mc = (TGraph *)f->Get("sigma_g");  
  TGraph *mean_mc = (TGraph *)f->Get("mean_g");  

  TFile *g = TFile::Open("data_dedx.root");
  TGraph *sigma_d = (TGraph *)g->Get("sigma_g");  
  TGraph *mean_d = (TGraph *)g->Get("mean_g");
  
  sigma_d->GetYaxis()->SetTitle("dE/dx arb. units");
  sigma_d->GetXaxis()->SetTitle("Momentum MeV/c");  
  mean_d->GetYaxis()->SetTitle("dE/dx arb. units");
  mean_d->GetXaxis()->SetTitle("Momentum MeV/c");  
  
  TCanvas *cvs = style::stdcvs();
  make(sigma_d);
  make(sigma_mc);
  make(mean_d);
  make(mean_mc);
  
  sigma_d->SetLineColor(2);
  sigma_mc->SetLineColor(4);
  mean_d->SetLineColor(2);
  mean_mc->SetLineColor(4);

  sigma_d->SetLineStyle(9);
  sigma_mc->SetLineStyle(9);

  mean_d->SetLineStyle(10);
  mean_mc->SetLineStyle(10);

  sigma_d->SetMarkerStyle(34);
  sigma_mc->SetMarkerStyle(34);
  sigma_d->SetMarkerSize(5);
  sigma_mc->SetMarkerSize(5);
  sigma_d->SetMarkerColor(2);
  sigma_mc->SetMarkerColor(4);

  mean_d->SetMarkerStyle(33);
  mean_mc->SetMarkerStyle(33);
  mean_d->SetMarkerSize(5);
  mean_mc->SetMarkerSize(5);
  mean_d->SetMarkerColor(2);
  mean_mc->SetMarkerColor(4);

  sigma_d->GetXaxis()->SetRangeUser(48,400);
  sigma_d->GetYaxis()->SetRangeUser(0,100);
 
  //  mean_d->GetXaxis()->SetRangeUser(48,400);
  //  mean_d->GetYaxis()->SetRangeUser(1,40);

  sigma_d->Draw("APE");
  sigma_mc->Draw("same P");

  mean_d->Draw("same PO");
  mean_mc->Draw("same PO");
    
  auto leg = new TLegend(.3,.6,.9,.9);
  leg->AddEntry(sigma_d,"Data #sigma","p");
  leg->AddEntry(mean_d,"Data <dE/dx>","p");
  leg->AddEntry(sigma_mc,"MC #sigma","p");
  leg->AddEntry(mean_mc,"MC <dE/dx>","p");
  leg->SetBorderSize(0);
  leg->Draw("same");
  //  cvs->SetLogx();
  //  cvs->SetLogy();
  cvs->SaveAs("dedxSigmacompare.png");
  cvs->SaveAs("dedxSigmacompare.jpg");

}

