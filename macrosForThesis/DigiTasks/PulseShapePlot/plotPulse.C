#include "/home/justin/mythesis/thesis_style.h"

using namespace style;

void plotPulse()
{

  TFile *f = TFile::Open("pulses.root");
  TF1 *sat = (TF1 *)f->Get("sat");
  TF1 *not_sat = (TF1 *)f->Get("not_sat");  

  TH1D *sat_b = (TH1D *)f->Get("sat_b");
  TH1D *not_sat_b = (TH1D *)f->Get("not_sat_b");  


  style::make(sat);
  style::make(not_sat);

  style::make(sat_b);
  style::make(not_sat_b);
 
  TCanvas *c1 = style::stdcvs();
  sat->SetLineWidth(6);
  not_sat->SetLineWidth(6);
  not_sat->SetLineStyle(9);

  sat_b->SetLineWidth(6);
  not_sat_b->SetLineWidth(6);
  not_sat_b->SetLineStyle(9);

  TLegend *leg = new TLegend(.45,.5,.92,.9);
  leg->AddEntry(sat,"Saturated Signal","L");
  leg->AddEntry(sat_b,"Saturated Signal Pole Zero","L");
  leg->AddEntry(not_sat,"Normal Signal","L");
  leg->AddEntry(not_sat_b,"Normal Signal Pole Zero","L");
  leg->SetBorderSize(0);
  leg->SetFillColor(0);
  
  sat->SetNpx(10000);
  not_sat->SetNpx(10000);  

  sat->SetTitle("");
  sat->GetYaxis()->SetTitle("ADC");
  sat->GetXaxis()->SetTitle("Time bucket (Tb)");
  not_sat->GetYaxis()->SetTitle("ADC");
  not_sat->GetXaxis()->SetTitle("Time bucket (Tb)");

  not_sat->GetYaxis()->SetLabelSize(.06);
  sat->GetYaxis()->SetLabelSize(.06);
  not_sat->GetXaxis()->SetLabelSize(.06);
  sat->GetXaxis()->SetLabelSize(.06);

  not_sat->GetYaxis()->SetTitleSize(.06);
  sat->GetYaxis()->SetTitleSize(.06);
  not_sat->GetXaxis()->SetTitleSize(.06);
  sat->GetXaxis()->SetTitleSize(.06);
  
  sat->GetYaxis()->SetTitleOffset(.9);
  
  sat->GetXaxis()->CenterTitle();
  sat->GetYaxis()->CenterTitle();


  //  not_sat->GetXaxis()->SetRangeUser(0,60);
  not_sat_b->GetXaxis()->SetRangeUser(0,40);
 
  sat->GetXaxis()->SetRangeUser(0,100);
  sat->Draw();
  not_sat->Draw("same");
  sat_b->Draw("same L");
  not_sat_b->Draw("same L");
  leg->Draw();

  c1->SaveAs("pulseshape.jpg");
  c1->SaveAs("pulseshape.png");  
  
}
