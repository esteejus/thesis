#include "/home/justin/mythesis/thesis_style.h"

using namespace style;

void plotBeamPID()
{
  gStyle->SetOptStat(0);
  gStyle->SetFrameLineWidth(10);
  
  TFile *f = TFile::Open("beampid.root");
  TH2D *sn132 = (TH2D *)f->Get("sn132");
  TH2D *sn124 = (TH2D *)f->Get("sn124");
  TH2D *sn112 = (TH2D *)f->Get("sn112");
  TH2D *sn108 = (TH2D *)f->Get("sn108");

  make(sn132); 
  make(sn124);
  make(sn108);
  make(sn112);
  
  sn132->SetTitle("");
  sn124->SetTitle("");
  sn112->SetTitle("");
  sn108->SetTitle("");
  

  sn132->GetXaxis()->SetTitle("
  sn124->
  sn112->
  sn108->




  double botMar = .2;
  
  //  TCanvas *cvs = new TCanvas("c1","c1",1500,700);
  TCanvas *cvs = new TCanvas("c1","c1",3000,1400);

  cvs->SetBottomMargin(.2);
  cvs->SetLeftMargin(.2);
  cvs->SetRightMargin(.2);
  //  cvs->SetTopMargin(.08);
  
  cvs->Divide(2,1,0,0);
  cvs->cd(1)->SetLeftMargin(.2);
  cvs->cd(1)->SetTopMargin(.1);
  cvs->cd(1)->SetBottomMargin(botMar);

  cvs->cd(1);
  cvs->cd(1)->SetLogz();
  sn132->Draw("col");

  cvs->cd(2);
  cvs->cd(2)->SetLogz();
  cvs->cd(2)->SetRightMargin(.15);
  cvs->cd(2)->SetTopMargin(.1);
  cvs->cd(2)->SetBottomMargin(botMar);
  sn124->GetXaxis()->SetRangeUser(2.36,2.7);
  sn124->Draw("colz");


}
