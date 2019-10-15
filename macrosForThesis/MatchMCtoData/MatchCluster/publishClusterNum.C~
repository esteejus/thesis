#include "/home/justin/mythesis/thesis_style.h"

using namespace style;

void publishGasGain()
{
 TF1 * polya_l = new TF1("polya_l","(1/[0])*(pow([1],[1])/TMath::Gamma([1]))*pow(x/[0],[1]-1)*exp(-[1]*(x/[0]))",0,1200);
 //  poyla_l->FixParameter(0,1024.);
 polya_l->SetParameter(0,150.04);
 polya_l->SetParameter(1,1.504);

 TF1 * polya_h = new TF1("polya_h","(1/[0])*(pow([1],[1])/TMath::Gamma([1]))*pow(x/[0],[1]-1)*exp(-[1]*(x/[0]))",0,5000);
 polya_h->SetParameter(0,903.9);
 polya_h->SetParameter(1,1.468);
  
  TFile *lowf = TFile::Open("aval_merge_1214V.root");
  TFile *highf = TFile::Open("aval_merge_1460V.root");

  Double_t xbins_l[21] = {};
  Double_t xbins_h[21] = {};
  double lowstep = (log(1500) - log(2))/21.;
  double highstep = (log(6000) - log(2))/21.;
  for(int i = 0; i <= 21; i++)
    {
      double edge = exp(log(2) + i*lowstep);
      xbins_l[i] = round(edge);

      edge = exp(log(2) + i*highstep);
      xbins_h[i] = round(edge);

    }

  TH1D *lowg = (TH1D *)lowf->Get("gain");
  TH1D *highg = (TH1D *)highf->Get("gain");
  lowg->GetYaxis()->SetTitle("Probability");
  lowg->GetXaxis()->SetTitle("# of e^{-}");
  highg->GetYaxis()->SetTitle("Probability");
  highg->GetXaxis()->SetTitle("# of e^{-}");

  highg->GetYaxis()->SetMaxDigits(2);
  lowg->GetYaxis()->SetMaxDigits(2);
  
  TCanvas *cvs = style::stdcvs();
  make(highg);
  make(lowg);
  
  highg->SetLineColor(2);
  lowg->SetLineColor(4);
  highg = (TH1D *)highg->Rebin(20,"highg",xbins_h);
  lowg = (TH1D *)lowg->Rebin(20,"lowg",xbins_l);
  highg->Scale(1./highg->Integral(),"width");
  lowg->Scale(1./lowg->Integral(),"width");

  //  highg->Fit(polya_h);
  //lowg->Fit(polya_l);
  polya_h->SetLineColor(kOrange + 1);
  polya_l->SetLineColor(kOrange + 1);
 

  highg->GetXaxis()->SetRangeUser(0,5000);
  highg->GetYaxis()->SetRangeUser(.01,6e-3);
  highg->Draw();
  lowg->Draw("same");

  polya_h->SetLineWidth(10);
  polya_l->SetLineWidth(10);
  polya_h->Draw("same");
  polya_l->Draw("same");   

  highg->SetMarkerStyle(20);
  lowg->SetMarkerStyle(20);
  highg->SetMarkerSize(5);
  lowg->SetMarkerSize(5);
  highg->SetMarkerColor(2);
  lowg->SetMarkerColor(4);
  
  auto leg = new TLegend(.5,.55,.9,.9);
  leg->AddEntry(highg,"1470 V MC","pe");
  leg->AddEntry(lowg,"1214 V MC","pe");
  leg->AddEntry(polya_h,"Polya Fit","l");
  leg->SetBorderSize(0);
  leg->Draw("same");
  cvs->SetLogy();
  cvs->SaveAs("gain.png");
  cvs->SaveAs("gain.jpg");

}

