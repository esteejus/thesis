#include "/home/justin/mythesis/thesis_style.h"

using namespace style;

void plotEfficiency()
{

  TFile *f = TFile::Open("EfficiencyPlot.root");
  TH2D *pim_132 = (TH2D* )f->Get("efficiency_132_pim");
  TH2D *pip_132 = (TH2D* )f->Get("efficiency_132_pip");
  TH2D *pim_108 = (TH2D* )f->Get("efficiency_108_pim");
  TH2D *pip_108 = (TH2D* )f->Get("efficiency_108_pip");


  make(pim_132);
  make(pip_132);
  make(pim_108);
  make(pip_108);

  TCanvas *cvs = stdcvs();
  cvs->SetRightMargin(.2);
  pim_132->SetTitle("");
  pim_132->GetYaxis()->SetTitle("#theta_{Lab}");
  pim_132->GetXaxis()->SetTitle("p_{Lab}");
  pim_132->GetZaxis()->SetTitle("Efficiency");
  pim_132->GetZaxis()->CenterTitle();
  pim_132->GetXaxis()->SetRangeUser(50,550);
  pim_132->GetYaxis()->SetRangeUser(0,70);
  pim_132->GetZaxis()->SetRangeUser(0,1.);
  pim_132->Draw("colz");
  cvs->SaveAs("pim_132_efficiency.png");

  pim_108->SetTitle("");
  pim_108->GetYaxis()->SetTitle("#theta_{Lab}");
  pim_108->GetXaxis()->SetTitle("p_{Lab}");
  pim_108->GetZaxis()->SetTitle("Efficiency");
  pim_108->GetZaxis()->CenterTitle();
  pim_108->GetXaxis()->SetRangeUser(50,550);
  pim_108->GetYaxis()->SetRangeUser(0,70);
  pim_108->GetZaxis()->SetRangeUser(0,1.);
  pim_108->Draw("colz");
  cvs->SaveAs("pim_108_efficiency.png");


  pip_132->SetTitle("");
  pip_132->GetYaxis()->SetTitle("#theta_{Lab}");
  pip_132->GetXaxis()->SetTitle("p_{Lab}");
  pip_132->GetZaxis()->SetTitle("Efficiency");
  pip_132->GetZaxis()->CenterTitle();
  pip_132->GetXaxis()->SetRangeUser(50,550);
  pip_132->GetYaxis()->SetRangeUser(0,70);
  pip_132->GetZaxis()->SetRangeUser(0,1.);
  pip_132->Draw("colz");
  cvs->SaveAs("pip_132_efficiency.png");

  pip_108->SetTitle("");
  pip_108->GetYaxis()->SetTitle("#theta_{Lab}");
  pip_108->GetXaxis()->SetTitle("p_{Lab}");
  pip_108->GetZaxis()->SetTitle("Efficiency");
  pip_108->GetZaxis()->CenterTitle();
  pip_108->GetXaxis()->SetRangeUser(50,550);
  pip_108->GetYaxis()->SetRangeUser(0,70);
  pip_108->GetZaxis()->SetRangeUser(0,1.);
  pip_108->Draw("colz");
  cvs->SaveAs("pip_108_efficiency.png");


}
