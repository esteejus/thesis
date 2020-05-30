#include "/home/justin/mythesis/thesis_style.h"

using namespace style;

void plotFullEfficiencyEx()
{

  double phi[4] = {25, 158, 212, 320}; // for pim cuts

  TLine *l1 = new TLine(0,phi[0],90,phi[0]);
  l1->SetLineColor(2);
  l1->SetLineStyle(10);
  l1->SetLineWidth(4);

  TLine *l2 = new TLine(0,phi[1],90,phi[1]);
  l2->SetLineColor(2);
  l2->SetLineStyle(10);
  l2->SetLineWidth(4);

  TLine *l3 = new TLine(0,phi[2],90,phi[2]);
  l3->SetLineColor(2);
  l3->SetLineStyle(10);
  l3->SetLineWidth(4);  

  TLine *l4 = new TLine(0,phi[3],90,phi[3]);
  l4->SetLineColor(2);
  l4->SetLineStyle(10);
  l4->SetLineWidth(4);

  TFile *f = TFile::Open("EfficiencyPlot.root");
  TH2D *mom_200 = (TH2D* )f->Get("mom_200");
  TH2D *mom_400 = (TH2D* )f->Get("mom_400");

  make(mom_200);
  make(mom_400);


  TCanvas *cvs = stdcvs();
  cvs->SetRightMargin(.2);
  mom_200->SetTitle("");
  mom_200->GetXaxis()->SetTitle("#theta_{Lab}");
  mom_200->GetYaxis()->SetTitle("#phi");
  mom_200->GetZaxis()->SetTitle("Efficiency");
  mom_200->GetZaxis()->CenterTitle();
  mom_200->GetXaxis()->SetRangeUser(0,90);
  mom_200->GetZaxis()->SetRangeUser(0,1.);
  mom_200->Draw("colz");
  l1->Draw();
  l2->Draw();
  l3->Draw();
  l4->Draw();
  cvs->SaveAs("mom_200_efficiency.png");


  mom_400->SetTitle("");
  mom_400->GetXaxis()->SetTitle("#theta_{Lab}");
  mom_400->GetYaxis()->SetTitle("#phi");
  mom_400->GetZaxis()->SetTitle("Efficiency");
  mom_400->GetZaxis()->CenterTitle();
  mom_400->GetXaxis()->SetRangeUser(0,90);
  mom_400->GetZaxis()->SetRangeUser(0,1.);
  mom_400->Draw("colz");
  l1->Draw();
  l2->Draw();
  l3->Draw();
  l4->Draw();
  cvs->SaveAs("mom_400_efficiency.png");

  
}
