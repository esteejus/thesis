#include "/home/justin/mythesis/thesis_style.h"
using namespace style;

void plotResidual()
{
  gStyle->SetOptStat(0);

 vector<double> sn108_res = {-0.04,0.25,0.18,-0.11,0.2,-0.2,-0.23,0.25,-0.1,0.01,-0.17,0.2,0.53,-0.23,0.28,-0.02,-0.26,0.06,0.15,0.17,-0.13,0.06,-0.59,-0.06,-0.27,0.44,0.16,0.21,-0.06,0.26,0.19,-0.02,0.02,0.3,0.2,0.2,-0.18,0.22,-0.13,0.05,0.12,0.05,-0.01,-0.31,0.05,-0.09,0.11,-0.19,-0.01,-0.01,-0.3,-0.14,-0.56,-0.04,-0.05,-0.39,-0.12,0};

  vector<double> sn132_res = {-0.15,-0.12,-0.42,-0.26,-0.09,0.09,-0.16,-0.17,-0.22,0.04,0.25,-0.08,-0.1,0.15,-0.02,-0.12,0.1,0.11,-0.02,0.06,0.4,-0.01,0.07,-0.01,0.08,0.1,-0.21,0.09,0.23,-0.37,-0.42,-0.16,-0.13,0.03,0.1,0.06,-0.14,-0.11,0.1,-0.28,0.07,0.12,0.32,0.13,-0.07,-0.02,0.26,-0.27,0.22,0.36,-0.64,-0.11,-0.24,0.07,0,0.15,0.13,-0.07,0,-0.04,0.22,-0.01,-0.04,0.12,0.27,0.23,-0.3,-0.07,0.08,-0.08,0.05,-0.35,0.02,-0.05,0.31,-0.13};

  vector<double> sn124_res = {0.05,0.07,-0.14,-0.2,0.16,-0.02,-0.26,0.11,-0.12,-0.04,0.01,-0.36,-0.22,0.14,0.13,-0.05,0.15,-0.18,-0.11,-0.43,-0.14,-0.13,-0.04,0.14,-0.18,-0.05,-0.02,-0.08,-0.3,-0.36,-0.01,0.35,0.01,0.48,0.14,0.32,0,0.19,0.03,0.4,0.36,0.22,-0.09,0.3,-0.09,0.2,0.24,0.33,-0.08,0.07,0.2,-0.15,0.18,-0.21,0.05,-0.03,-0.01,0.1,0.1,-0.45,-0.08,0.04,-0.34,0.02,-0.3,-0.31,-0.04};

  vector<double> sn112_res = {-0.32,-0.19,-0.03,-0.21,0.18,-0.19,-0.49,-0.09,0.15,0,-0.07,0.14,0.05,-0.9,-0.15,0.26,0.63,-0.06,-0.29,0.18,-0.02,0.07,0.39,0.33,0.14,0.31,0.14,0.1,0.13,0.2,0.08,0.3,0.47,0.29,0.29,-0.27,-0.08,-0.15,0.06,-0.24,-0.21,-0.25,0.04,-0.04,-0.18,-0.27,0.13,-0.14,-0.37,-0.04,-0.38,0.43,0.08,-0.32,0.17,0.11,0.15,0.01};

  
  int sn132_c = kRed - 4;
  int sn108_c = kBlue - 4;
  int sn112_c = kGreen - 4;
  int sn124_c = kCyan - 4;
  
  TH1D *sn132sc_h = new TH1D("sn132sc_h","",20,-1,1);
  TH1D *sn108sc_h = new TH1D("sn108sc_h","",20,-1,1);
  TH1D *sn112sc_h = new TH1D("sn112sc_h","",20,-1,1);
  TH1D *sn124sc_h = new TH1D("sn124sc_h","",20,-1,1);
  TH1D *all = new TH1D("all","",20,-1,1);


  for(int i = 0; i < sn132_res.size(); i++)
    {
      sn132sc_h->Fill(sn132_res.at(i));
      all->Fill(sn132_res.at(i));
    }

  for(int i = 0; i < sn124_res.size(); i++)
    {
      sn124sc_h->Fill(sn124_res.at(i));
      all->Fill(sn124_res.at(i));
    }

  for(int i = 0; i < sn108_res.size(); i++)
    {
      sn108sc_h->Fill(sn108_res.at(i));
      all->Fill(sn108_res.at(i));
    }

  for(int i = 0; i < sn112_res.size(); i++)
    {
      sn112sc_h->Fill(sn112_res.at(i));
      all->Fill(sn112_res.at(i));
    }

  THStack *stack = new THStack("stack","; #Delta V_{LR};# of Runs");

  sn108sc_h->GetXaxis()->SetTitle("#sigma Sheet Density (x10^{-8} C/m^2)");
  sn108sc_h->GetYaxis()->SetTitle("# of Runs");  
  sn108sc_h->GetXaxis()->CenterTitle();
  sn108sc_h->GetYaxis()->CenterTitle();

  sn132sc_h->GetXaxis()->SetTitle("#sigma Sheet Density (x10^{-8} C/m^2)");
  sn132sc_h->GetYaxis()->SetTitle("# of Runs");  
  sn132sc_h->GetXaxis()->CenterTitle();
  sn132sc_h->GetYaxis()->CenterTitle();

  sn124sc_h->GetXaxis()->SetTitle("#sigma Sheet Density (x10^{-8} C/m^2)");
  sn124sc_h->GetYaxis()->SetTitle("# of Runs");  
  sn124sc_h->GetXaxis()->CenterTitle();
  sn124sc_h->GetYaxis()->CenterTitle();

  sn112sc_h->GetXaxis()->SetTitle("#sigma Sheet Density (x10^{-8} C/m^2)");
  sn112sc_h->GetYaxis()->SetTitle("# of Runs");  
  sn112sc_h->GetXaxis()->CenterTitle();
  sn112sc_h->GetYaxis()->CenterTitle();

  
  sn108sc_h->SetFillColor(sn108_c);
  sn112sc_h->SetFillColor(sn112_c);
  sn124sc_h->SetFillColor(sn124_c);
  sn132sc_h->SetFillColor(sn132_c);


  stack->Add(sn108sc_h);
  stack->Add(sn112sc_h);
  stack->Add(sn124sc_h);
  stack->Add(sn132sc_h);

  TF1 *gaus = new TF1("gaus","[0]*TMath::Gaus(x,[1],[2])",-1,1);
  gaus->SetParameters(47.53,1.998e-3,2.14e-1);

  all->Fit("gaus");

  TCanvas *c1 = new TCanvas("c1","c1",2000,1200);
  c1->SetRightMargin(.2);
  c1->SetLeftMargin(.2);
  c1->SetTopMargin(.05);
  c1->SetBottomMargin(.2);
  
  double xdim = .75;
  double eps = 0;

  TLegend *leg = new TLegend(.7,.55,.9,.85);
  leg->AddEntry(sn132sc_h,"{}^{132}Sn","f");
  leg->AddEntry(sn124sc_h,"{}^{124}Sn","f");
  leg->AddEntry(sn112sc_h,"{}^{112}Sn","f");
  leg->AddEntry(sn108sc_h,"{}^{108}Sn","f");
  
  TCanvas *c2 = new TCanvas("c2","c2",1500,900);
  c2->SetRightMargin(.1);
  c2->SetLeftMargin(.1);
  c2->SetTopMargin(.1);
  c2->SetBottomMargin(.15);
  c2->SetFrameLineWidth(5);
  gStyle->SetLineWidth(5);
  gPad->SetLineWidth(5);

  stack->Draw();
  stack->GetXaxis()->CenterTitle();
  stack->GetYaxis()->CenterTitle();

  stack->GetXaxis()->SetLabelSize(.06);
  stack->GetYaxis()->SetLabelSize(.06);

  stack->GetXaxis()->SetTitleOffset(1.1);
  stack->GetYaxis()->SetTitleOffset(.8);

  stack->GetXaxis()->SetTitleSize(.06);
  stack->GetYaxis()->SetTitleSize(.06);

  stack->Draw();
  gaus->SetLineColor(1);
  gaus->SetLineWidth(4);
  gaus->Draw("same");
  
  leg->SetBorderSize(0);
  leg->SetFillColorAlpha(0,0);
  leg->Draw();

  c2->SaveAs("VLRresidual.png");


}
