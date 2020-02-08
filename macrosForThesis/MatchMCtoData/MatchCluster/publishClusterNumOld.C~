#include "/home/justin/mythesis/thesis_style.h"

using namespace style;

void publishClusterNum()
{
  TFile *f = TFile::Open("mcpim_DBhist.root");
  TH1D *mc = (TH1D *)f->Get("ndf_dist");
  TH1D *data = (TH1D *)f->Get("ndf_data");
  mc->GetYaxis()->SetTitle("Probability");
  mc->GetXaxis()->SetTitle("# of Clusters");
  data->GetYaxis()->SetTitle("Probability");
  data->GetXaxis()->SetTitle("# of Clusters");

  data->GetYaxis()->SetMaxDigits(2);
  mc->GetYaxis()->SetMaxDigits(2);
  
  TCanvas *cvs = style::stdcvs();
  make(data);
  make(mc);
  
  data->SetLineColor(2);
  mc->SetLineColor(4);
  //  data = (TH1D *)data->Rebin(20,"data",xbins_h);
  //  mc = (TH1D *)mc->Rebin(20,"mc",xbins_l);
  //  data->Scale(1./data->Integral(),"width");
  //  mc->Scale(1./mc->Integral(),"width");

  //  data->Fit(polya_h);
  //mc->Fit(polya_l);

  data->GetXaxis()->SetRangeUser(0,130);
  //  data->GetYaxis()->SetRangeUser(.01,6e-3);
  data->Draw("hist");
  mc->Draw("same hist");

  data->SetMarkerStyle(20);
  mc->SetMarkerStyle(20);
  data->SetMarkerSize(5);
  mc->SetMarkerSize(5);
  data->SetMarkerColor(2);
  mc->SetMarkerColor(4);
  
  auto leg = new TLegend(.3,.2,.7,.5);
  leg->AddEntry(data,"Data","le");
  leg->AddEntry(mc,"MC","le");
  leg->SetBorderSize(0);
  leg->Draw("same");
  cvs->SetLogy();
  cvs->SaveAs("numcluster.png");
  cvs->SaveAs("numcluster.jpg");

}

