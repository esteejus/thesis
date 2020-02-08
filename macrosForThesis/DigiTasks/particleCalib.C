#include "/home/justin/mythesis/thesis_style.h"

using namespace style;

auto me = 0.5109989461;                                                                                
auto mp = 938.2720813;                                                                                 
auto mn = 939.565346;                                                                                  
auto md = 1875.612762;                                                                                 
auto mt = 2808.921112;                                                                                 
auto mhe3 = 2808.39132;                                                                                
auto mal = 3727.379378;

void particleCalib()
{
  double max = 2000;
  
  TF1 *p_const = new TF1("p_const","TMath::Exp([0])",0,max);
  p_const->SetParameter(0,-.17377);

  TF1 *p_lin = new TF1("p_lin","TMath::Exp([0] + [1]*x)",0,max);
  p_lin->SetParameters(-.05823,-1.78728e-4);

  TF1 *p_lin_new = new TF1("p_lin_new","[0] + [1]*x",0,max);
  p_lin_new->SetParameters(0.861124,-9.88284e-05);

  TF1 *d_lin = new TF1("d_lin","TMath::Exp([0] + [1]*x)",0,max);
  d_lin->SetParameters(-.0487855,-1.68159e-4);

  TF1 *d_lin_2 = new TF1("d_lin_2","[0] + [1]*x",0,max);
  d_lin_2->SetParameters(0.920522,-0.000133518);

  TF1 *t_lin = new TF1("t_lin","TMath::Exp([0] + [1]*x)",0,max);
  t_lin->SetParameters(-.0715918,-1.20368e-4);

  TF1 *t_lin_new = new TF1("t_lin_new","[0] + [1]*x",0,max);
  t_lin_new->SetParameters(0.911872,-0.000109902);

  TF1 *he3_lin = new TF1("he3_lin","TMath::Exp([0] + [1]*x)",0,max);
  he3_lin->SetParameters(-.0486119,-1.137e-4);

  TF1 *he3_lin_new = new TF1("he3_lin_new","[0] + [1]*x",0,max);
  he3_lin_new->SetParameters(0.964982,-0.000137747);

  TF1 *he4_lin = new TF1("he4_lin","TMath::Exp([0] + [1]*x)",0,max);
  he4_lin->SetParameters(-.0628344,-1.05124e-4);

  TF1 *he4_lin_new = new TF1("he4_lin_new","[0] + [1]*x",0,max);
  he4_lin_new->SetParameters(0.964982,-0.000137747);

  p_lin->SetLineColor(kRed);
  d_lin->SetLineColor(kRed-4);
  t_lin->SetLineColor(kRed-7);  
  he3_lin->SetLineColor(kRed-9);
  he4_lin->SetLineColor(kRed-10);
  
  p_lin->SetLineStyle(1);
  d_lin->SetLineStyle(2);
  t_lin->SetLineStyle(3);  
  he3_lin->SetLineStyle(4);
  he4_lin->SetLineStyle(5);

  TCanvas *c1 = style::stdcvs();
  p_lin->SetTitle("");

  style::make(p_lin);
  style::make(d_lin);
  style::make(t_lin);
  style::make(he3_lin);
  style::make(he4_lin);

  p_lin->GetXaxis()->SetTitle("Momentum/q");
  p_lin->GetYaxis()->SetTitle("dEdx_{MC}/dEdx_{Data}");

  p_lin->SetLineWidth(5); 
  d_lin->SetLineWidth(5);
  t_lin->SetLineWidth(5);
  he3_lin->SetLineWidth(5);
  he4_lin->SetLineWidth(5);
	  
  p_lin->Draw();
  p_lin_new->Draw("same");
  d_lin->Draw("same");
  d_lin_2->Draw("same");
  t_lin->Draw("same");
  t_lin_new->Draw("same");
  he3_lin->Draw("same");
  he3_lin_new->Draw("same");
  he4_lin->Draw("same");
  he4_lin_new->Draw("same");

  TLegend *leg = new TLegend(.2,.2,.5,.5);
  leg->AddEntry(p_lin,"proton","l");
  leg->AddEntry(d_lin,"deuteron","l");
  leg->AddEntry(t_lin,"triton","l");
  leg->AddEntry(he3_lin,"{}^{3}He","l");
  leg->AddEntry(he4_lin,"{}^{4}He","l");
  leg->SetBorderSize(0);
  leg->Draw();
  

	
}
