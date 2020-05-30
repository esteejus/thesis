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
  

  TCanvas *cvs = new TCanvas("c1","c1",1500,700);
  //  auto cvs = stdcvs();
  cvs->SetRightMargin(.08);
  cvs->SetLeftMargin(.08);
  cvs->cd(1)->SetLeftMargin(.08);
  cvs->cd(1)->SetBottomMargin(.1);
  cvs->Divide(2,1,0,0);
  cvs->cd(1)->SetTopMargin(.05);
  cvs->cd(1);
  cvs->cd(1)->SetLogz();
  sn132->Draw("col");

  cvs->cd(2);
  cvs->cd(2)->SetBottomMargin(.1);
  cvs->cd(2)->SetLogz();
  cvs->cd(2)->SetTopMargin(.05);
  cvs->cd(2)->SetRightMargin(.1);
  sn124->GetXaxis()->SetRangeUser(2.36,2.7);
  sn124->Draw("colz");


}
