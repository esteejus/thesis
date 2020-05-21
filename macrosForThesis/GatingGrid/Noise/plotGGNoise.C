#include "/home/justin/mythesis/thesis_style.h"

using namespace style;

void plotGGNoise()
{

  TFile *raw = TFile::Open("adc_raw.root");
  TFile *corr = TFile::Open("adc_corr.root");  
  TFile *mean = TFile::Open("meannoise.root");  


  TH1D *adcraw = (TH1D *)raw->Get("rawdist");
  TH1D *adcorr = (TH1D *)corr->Get("adcdist");
  TH1D *meanfcn = (TH1D *)mean->Get("mean");

  meanfcn->SetLineWidth(3);
  meanfcn->SetLineColor(kRed - 4);

  adcraw->SetTitle("");
  adcorr->SetTitle("");

  TLegend *leg = new TLegend(.5,.65,.8,.8);
  leg->AddEntry(meanfcn,"Mean Value","l");
  leg->SetBorderSize(0);
  
  TCanvas *c1 = new TCanvas("c1","c1",1000,800);
  c1->SetTopMargin(.15);
  c1->SetBottomMargin(.18);
  c1->SetRightMargin(.05);
  c1->SetLeftMargin(.12);

  c1->Divide(1,2,0,0);


   
  //  adcraw->GetXaxis()->SetTitle("V_{avg} (V)");
  //  adcraw->GetXaxis()->CenterTitle();
  adcraw->GetYaxis()->SetTitle("Raw ADC");
  adcraw->GetYaxis()->CenterTitle();

  adcraw->GetXaxis()->SetTitleSize(.08);
  adcraw->GetYaxis()->SetTitleSize(.08);
  
  adcraw->GetXaxis()->SetLabelSize(.05);
  adcraw->GetYaxis()->SetLabelSize(.05);
  adcraw->GetXaxis()->SetTitleOffset(.6);
  adcraw->GetYaxis()->SetTitleOffset(.6);

  adcorr->GetXaxis()->SetTitle("Time Bucket");
  adcorr->GetXaxis()->CenterTitle();

  adcorr->GetYaxis()->SetTitle("Subtracted ADC");
  adcorr->GetYaxis()->CenterTitle();

  adcorr->GetXaxis()->SetTitleSize(.08);
  adcorr->GetYaxis()->SetTitleSize(.08);
  
  adcorr->GetXaxis()->SetLabelSize(.05);
  adcorr->GetYaxis()->SetLabelSize(.05);
  adcorr->GetXaxis()->SetTitleOffset(.8);
  adcorr->GetYaxis()->SetTitleOffset(.6);

  adcorr->GetYaxis()->SetNdivisions(508);
  adcraw->GetYaxis()->SetNdivisions(508);
  
  c1->cd(1);
  adcraw->GetXaxis()->SetRangeUser(0,155);
  adcraw->GetYaxis()->SetRangeUser(3550,4050);
  adcraw->GetZaxis()->SetRangeUser(4,150);
  adcraw->Draw("colz");
  meanfcn->Draw("same HIST");
  leg->Draw();
  
  c1->cd(2);
  adcorr->GetXaxis()->SetRangeUser(0,155);
  adcorr->GetYaxis()->SetRangeUser(-250,250);
  adcorr->GetZaxis()->SetRangeUser(4,150);
  adcorr->Draw("colz");


}
