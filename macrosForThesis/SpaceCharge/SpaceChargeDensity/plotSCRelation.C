#include "/home/justin/mythesis/thesis_style.h"
using namespace style;

void plotSCRelation()
{
  gStyle->SetOptStat(0);
  int sn132_c = kRed - 4;
  int sn108_c = kBlue - 4;
  int sn112_c = kGreen - 4;
  int sn124_c = kCyan - 4;


  TF1 *l_132 = new TF1("l_132","[0] + [1]*x",0,13);
  TF1 *l_124 = new TF1("l_124","[0] + [1]*x",0,12);
  TF1 *l_112 = new TF1("l_112","[0] + [1]*x",0,13);
  TF1 *l_108 = new TF1("l_108","[0] + [1]*x",0,13);  


 TLegend *leg = new TLegend(.7,.2,.9,.4);
  leg->AddEntry(l_132,"{}^{132}Sn","l");
  leg->AddEntry(l_124,"{}^{124}Sn","l");
  leg->AddEntry(l_112,"{}^{112}Sn","l");
  leg->AddEntry(l_108,"{}^{108}Sn","l");
    
  TCanvas *c2 = new TCanvas("c2","c2",1500,900);
  c2->SetRightMargin(.1);
  c2->SetLeftMargin(.15);
  c2->SetTopMargin(.1);
  c2->SetBottomMargin(.15);
  c2->SetFrameLineWidth(5);
  gStyle->SetLineWidth(5);
  gPad->SetLineWidth(5);

  l_132->SetLineColor(sn132_c);
  l_108->SetLineColor(sn108_c);
  l_112->SetLineColor(sn112_c);
  l_124->SetLineColor(sn124_c);

  l_132->SetLineWidth(10);
  l_108->SetLineWidth(10);
  l_112->SetLineWidth(10);
  l_124->SetLineWidth(10);

  l_132->SetLineStyle(10);
  l_108->SetLineStyle(10);
  l_112->SetLineStyle(10);
  l_124->SetLineStyle(10);

  l_108->SetParameters(-1.066,2.939e-1);
  l_132->SetParameters(1.344,2.79e-1);
  l_124->SetParameters(2.546,0);
  l_112->SetParameters(-.4394,2.9655e-1);

  l_132->Draw();
  l_132->GetXaxis()->CenterTitle();
  l_132->GetYaxis()->CenterTitle();

  l_132->GetXaxis()->SetLabelSize(.06);
  l_132->GetYaxis()->SetLabelSize(.06);

  l_132->GetXaxis()->SetTitleOffset(1.1);
  l_132->GetYaxis()->SetTitleOffset(1.);

  l_132->GetXaxis()->SetTitleSize(.06);
  l_132->GetYaxis()->SetTitleSize(.06);

  l_132->SetTitle("");
  l_132->GetYaxis()->SetTitle("#sigma   (x10^{-8} C/m^{2})");
  l_132->GetXaxis()->SetTitle("Beam Rate (kHz)");
  
  l_132->GetYaxis()->SetRangeUser(0,5);
  l_132->GetXaxis()->SetRangeUser(8,13);
  l_132->Draw("");
  l_108->Draw("same L");
  l_112->Draw("same L");
  l_124->Draw("same L");
  
  leg->SetBorderSize(0);
  leg->SetFillColorAlpha(0,0);
  leg->Draw();

  c2->SaveAs("sc_beamrate.png");
	     

}
