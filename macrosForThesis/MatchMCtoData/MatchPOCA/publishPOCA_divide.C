#include "/home/justin/mythesis/thesis_style.h"

using namespace style;

void publishPOCA_divide()
{
  gStyle->SetErrorX(0);

  TFile *f = TFile::Open("../angles_poca.root");
  TH1D *mc_p = (TH1D *)f->Get("poca_mc_p");
  TH1D *data_p = (TH1D *)f->Get("poca_p");

  TH1D *mc_d = (TH1D *)f->Get("poca_mc_d");
  TH1D *data_d = (TH1D *)f->Get("poca_d");

  TH1D *mc_t = (TH1D *)f->Get("poca_mc_t");
  TH1D *data_t = (TH1D *)f->Get("poca_t");

  TH1D *mc_he3 = (TH1D *)f->Get("poca_mc_he3");
  TH1D *data_he3 = (TH1D *)f->Get("poca_he3");

  TH1D *mc_he4 = (TH1D *)f->Get("poca_mc_he4");
  TH1D *data_he4 = (TH1D *)f->Get("poca_he4");

  data_p->GetYaxis()->SetTitle("Probability");
  data_p->GetXaxis()->SetTitle("Dist. to Vertex [mm]");

  //  data_p->GetYaxis()->SetMaxDigits(2);
  //  mc_p->GetYaxis()->SetMaxDigits(2);
  
  TCanvas *cvs = style::stdcvs();
  make(data_p);
  make(mc_p);
  make(data_d);
  make(mc_d);
  make(data_t);
  make(mc_t);
  make(data_he3);
  make(mc_he3);
  make(data_he4);
  make(mc_he4);

  data_p->SetLineColor(kBlue);
  mc_p->SetLineColor(kRed);

  data_d->SetLineColor(kBlue - 4);
  mc_d->SetLineColor(kRed - 4);

  data_t->SetLineColor(kBlue - 7);
  mc_t->SetLineColor(kRed - 7);

  data_he3->SetLineColor(kBlue - 9);
  mc_he3->SetLineColor(kRed - 9);

  data_he4->SetLineColor(kBlue - 10);
  mc_he4->SetLineColor(kRed - 10);


  double scale_p = 6.25;
  double scale_d = 6.25;
  double scale_t = 6.25;
  double scale_he3 = 6.25;
  double scale_he4 = 6.25;

  //  data_p = (TH1D *)data_p->Rebin(20,"data_p",xbins_h);
  //  mc_p = (TH1D *)mc_p->Rebin(20,"mc_p",xbins_l);
  //  data_p->RebinX(4);
  //  mc_p->RebinX(4);

  //  data_d->RebinX(4);
  //  mc_d->RebinX(4);

  //  data_he4->RebinX(4);
  //  mc_he4->RebinX(4);

  data_p->Scale(1./data_p->Integral());
  mc_p->Scale(1./mc_p->Integral());

  data_d->Scale(1./data_d->Integral());
  mc_d->Scale(1./mc_d->Integral());

  data_t->Scale(1./data_t->Integral());
  mc_t->Scale(1./mc_t->Integral());

  data_he3->Scale(1./data_he3->Integral());
  mc_he3->Scale(1./mc_he3->Integral());

  data_he4->Scale(1./data_he4->Integral());
  mc_he4->Scale(1./mc_he4->Integral());

  //  data_p->Fit(polya_h);
  //mc_p->Fit(polya_l);

  TH1 *cuml_p = data_p->GetCumulative();
  TH1 *cuml_d = data_d->GetCumulative();
  TH1 *cuml_t = data_t->GetCumulative();
  TH1 *cuml_he3 = data_he3->GetCumulative();
  TH1 *cuml_he4 = data_he4->GetCumulative();
	
  TH1 *cuml_mc_p = mc_p->GetCumulative();
  TH1 *cuml_mc_d = mc_d->GetCumulative();
  TH1 *cuml_mc_t = mc_t->GetCumulative();
  TH1 *cuml_mc_he3 = mc_he3->GetCumulative();
  TH1 *cuml_mc_he4 = mc_he4->GetCumulative();

  cuml_p->SetLineStyle(5);
  cuml_d->SetLineStyle(5);
  cuml_t->SetLineStyle(5);
  cuml_he3->SetLineStyle(5);
  cuml_he4->SetLineStyle(5);

  cuml_p->SetLineWidth(5);
  cuml_d->SetLineWidth(5);
  cuml_t->SetLineWidth(5);
  cuml_he3->SetLineWidth(5);
  cuml_he4->SetLineWidth(5);

  cuml_mc_p->SetLineStyle(5);
  cuml_mc_d->SetLineStyle(5);
  cuml_mc_t->SetLineStyle(5);
  cuml_mc_he3->SetLineStyle(5);
  cuml_mc_he4->SetLineStyle(5);
	  
  cuml_mc_p->SetLineWidth(5);
  cuml_mc_d->SetLineWidth(5);
  cuml_mc_t->SetLineWidth(5);
  cuml_mc_he3->SetLineWidth(5);
  cuml_mc_he4->SetLineWidth(5);

  data_p->Scale(scale_p/data_p->Integral());
  mc_p->Scale(scale_p/mc_p->Integral());

  data_d->Scale(scale_d/data_d->Integral());
  mc_d->Scale(scale_d/mc_d->Integral());

  data_t->Scale(scale_t/data_t->Integral());
  mc_t->Scale(scale_t/mc_t->Integral());

  data_he3->Scale(scale_he3/data_he3->Integral());
  mc_he3->Scale(scale_he3/mc_he3->Integral());

  data_he4->Scale(scale_he4/data_he4->Integral());
  mc_he4->Scale(scale_he4/mc_he4->Integral());

  bool logy = false;
  double xmax = 30;
  
  cvs->Divide(2,3,0,0);

  cvs->cd(1);
  if(logy)
    cvs->cd(1)->SetLogy();
  data_p->GetXaxis()->SetRangeUser(0,xmax);
  data_p->GetYaxis()->SetRangeUser(0,1.05);
  data_p->Draw("");
  cuml_p->Draw("c same");
  cuml_mc_p->Draw("c same");
  mc_p->Draw("same");

  cvs->cd(2);
  if(logy)
    cvs->cd(2)->SetLogy();
  data_d->GetXaxis()->SetRangeUser(0,xmax);
  data_d->GetYaxis()->SetRangeUser(0,1.05);
  data_d->Draw();
  cuml_d->Draw("c same");
  cuml_mc_d->Draw("c same");
  mc_d->Draw("same");

  cvs->cd(3);
  if(logy)
    cvs->cd(3)->SetLogy();
  data_t->GetXaxis()->SetRangeUser(0,xmax);
  cuml_t->Draw("same");
  cuml_mc_t->Draw("c same");
  data_t->Draw("c same");
  mc_t->Draw("same");

  cvs->cd(4);
  if(logy)
    cvs->cd(4)->SetLogy();
  data_he3->GetXaxis()->SetRangeUser(0,xmax);
  cuml_he3->Draw("same");
  cuml_mc_he3->Draw("c same");
  data_he3->Draw("c same");
  mc_he3->Draw("same");

  cvs->cd(5);
  if(logy)
    cvs->cd(5)->SetLogy();
  data_he4->GetXaxis()->SetRangeUser(0,xmax);
  cuml_he4->Draw("same");
  cuml_mc_he4->Draw("c same");
  data_he4->Draw("c same");
  mc_he4->Draw("same");

  data_p->SetMarkerStyle(20);
  mc_p->SetMarkerStyle(20);

  data_d->SetMarkerStyle(21);
  mc_d->SetMarkerStyle(21);

  data_t->SetMarkerStyle(25);
  mc_t->SetMarkerStyle(25);

  data_he3->SetMarkerStyle(24);
  mc_he3->SetMarkerStyle(24);

  data_he4->SetMarkerStyle(23);
  mc_he4->SetMarkerStyle(23);

  data_p->SetMarkerSize(2);
  mc_p->SetMarkerSize(2);
  data_d->SetMarkerSize(2);
  mc_d->SetMarkerSize(2);
  data_he3->SetMarkerSize(2);
  mc_he3->SetMarkerSize(2);
  data_he4->SetMarkerSize(2);
  mc_he4->SetMarkerSize(2);

  data_p->SetMarkerColor(kBlue);
  mc_p->SetMarkerColor(kRed);
  
  data_d->SetMarkerColor(kBlue - 4);
  mc_d->SetMarkerColor(kRed - 4);

  data_t->SetMarkerColor(kBlue - 7);
  mc_t->SetMarkerColor(kRed - 7);

  data_he3->SetMarkerColor(kBlue - 9);
  mc_he3->SetMarkerColor(kRed - 9);

  data_he4->SetMarkerColor(kBlue - 10);
  mc_he4->SetMarkerColor(kRed - 10);

  /*
  auto leg = new TLegend(.3,.2,.7,.5);
  leg->AddEntry(data_p,"Data p","pe");
  leg->AddEntry(mc_p,"MC p","pe");
  leg->AddEntry(data_d,"Data d","pe");
  leg->AddEntry(mc_d,"MC d","pe");
  leg->AddEntry(data_t,"Data t","pe");
  leg->AddEntry(mc_t,"MC t","pe");
  leg->AddEntry(data_he3,"Data 3He","pe");
  leg->AddEntry(mc_he3,"MC 3He","pe");
  leg->AddEntry(data_he4,"Data 4He","pe");
  leg->AddEntry(mc_he4,"MC 4He","pe");
  leg->SetBorderSize(0);
*/

  auto leg = new TLegend(.2,.2,.35,.4);
  leg->AddEntry(data_p,"p","pe");
  leg->AddEntry(data_d,"d","pe");
  leg->AddEntry(data_t,"t","pe");
  leg->AddEntry(data_he3,"{}^{3}He","pe");
  leg->AddEntry(data_he4,"{}^{4}He","pe");
  leg->SetBorderSize(0);
  leg->SetHeader("Data");
  
  auto leg2 = new TLegend(.3,.2,.4,.4);
  leg2->AddEntry(mc_p,"p","pe");
  leg2->AddEntry(mc_d,"d","pe");
  leg2->AddEntry(mc_t,"t","pe");
  leg2->AddEntry(mc_he3,"{}^{3}He","pe");
  leg2->AddEntry(mc_he4,"{}^{4}He","pe");
  leg2->SetBorderSize(0);
  leg2->SetHeader("MC");

  leg->Draw("same");
  leg2->Draw("same");
  cvs->SetLogx();
  //  cvs->SetLogy();
  cvs->SaveAs("numcluster.png");


}

