
#include "/home/justin/mythesis/thesis_style.h"

void publishAnodeCalibration()
{
  TF1 *satline = new TF1("satline","[0]",0,60);
  satline->SetParameter(0,390);
  satline->SetLineWidth(10);
  satline->SetLineStyle(10);
  satline->SetLineColor(4);
  
  TF1 *line = new TF1("line","[0]*x",0,40);
  line->SetParameter(0,9.8);
  line->SetLineWidth(10);
  
  TFile *f = TFile::Open("mergelowhigh.root");
  TH2D *compare = (TH2D *)f->Get("dedxcompare");
  TCanvas *c1 = style::stdcvs();
  c1->SetLogz();
  compare->RebinY(4);
  style::make(compare);

  //  TLegend *leg = new TLegend(.15,.78,.6,.93,"","NDC");
  TLegend *leg = new TLegend(.6,.2,.95,.4,"","NDC");
  leg->SetBorderSize(0);
  leg->SetFillStyle(0);
  leg->AddEntry(line,"Linear calibration","l");
  leg->AddEntry(satline,"High gain saturation","l");

  //  leg->AddEntry(line,"#splitline{Low to High gain}{linear calibration}","l");

  compare->GetXaxis()->SetRangeUser(0,60);
  compare->GetYaxis()->SetRangeUser(0,500);
  compare->GetZaxis()->SetRangeUser(4,500);

  compare->Draw("col");
  line->Draw("same");
  satline->Draw("same");
  leg->Draw("same");
  c1->SaveAs("highlowcal.png");
}
