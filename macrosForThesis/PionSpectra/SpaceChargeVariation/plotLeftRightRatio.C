#include "/home/justin/mythesis/thesis_style.h"

using namespace style;

void plotLeftRightRatio()
{
  gStyle->SetOptStat(0);
  
  TFile *sn108_sc = TFile::Open("analysis-Sn108-nominal_LR.root");
  TFile *sn132_sc = TFile::Open("analysis-Sn132-nominal_LR.root");
  //  TFile *sn132_sc = TFile::Open("analysis-Sn132-sn132_1_2_LR.root");
  
  TFile *sn108_nosc = TFile::Open("analysis-Sn108-noSC.root");
  TFile *sn132_nosc = TFile::Open("analysis-Sn132-noSC.root");

  TH1D *pim_108_L = (TH1D *)sn108_sc->Get("pimkecm_ec_L");
  TH1D *pim_108_R = (TH1D *)sn108_sc->Get("pimkecm_ec_R");
  TH1D *pip_108_L = (TH1D *)sn108_sc->Get("pipkecm_ec_L");
  TH1D *pip_108_R = (TH1D *)sn108_sc->Get("pipkecm_ec_R");
  
  TH1D *pim_132_L = (TH1D *)sn132_sc->Get("pimkecm_ec_L");
  TH1D *pim_132_R = (TH1D *)sn132_sc->Get("pimkecm_ec_R");
  TH1D *pip_132_L = (TH1D *)sn132_sc->Get("pipkecm_ec_L");
  TH1D *pip_132_R = (TH1D *)sn132_sc->Get("pipkecm_ec_R");

  TH1D *pim_108_L_no = (TH1D *)sn108_nosc->Get("pimkecm_ec_L");
  TH1D *pim_108_R_no = (TH1D *)sn108_nosc->Get("pimkecm_ec_R");
  TH1D *pip_108_L_no = (TH1D *)sn108_nosc->Get("pipkecm_ec_L");
  TH1D *pip_108_R_no = (TH1D *)sn108_nosc->Get("pipkecm_ec_R");
  
  TH1D *pim_132_L_no = (TH1D *)sn132_nosc->Get("pimkecm_ec_L");
  TH1D *pim_132_R_no = (TH1D *)sn132_nosc->Get("pimkecm_ec_R");
  TH1D *pip_132_L_no = (TH1D *)sn132_nosc->Get("pipkecm_ec_L");
  TH1D *pip_132_R_no = (TH1D *)sn132_nosc->Get("pipkecm_ec_R");


  pim_108_L->Scale(1./pim_108_L->Integral(),"width");
  pim_108_R->Scale(1./pim_108_R->Integral(),"width");
  pip_108_L->Scale(1./pip_108_L->Integral(),"width");
  pip_108_R->Scale(1./pip_108_R->Integral(),"width");

  pim_132_L->Scale(1./pim_132_L->Integral(),"width");
  pim_132_R->Scale(1./pim_132_R->Integral(),"width");
  pip_132_L->Scale(1./pip_132_L->Integral(),"width");
  pip_132_R->Scale(1./pip_132_R->Integral(),"width");

  pim_108_L_no->Scale(1./pim_108_L_no->Integral(),"width");
  pim_108_R_no->Scale(1./pim_108_R_no->Integral(),"width");
  pip_108_L_no->Scale(1./pip_108_L_no->Integral(),"width");
  pip_108_R_no->Scale(1./pip_108_R_no->Integral(),"width");

  pim_132_L_no->Scale(1./pim_132_L_no->Integral(),"width");
  pim_132_R_no->Scale(1./pim_132_R_no->Integral(),"width");
  pip_132_L_no->Scale(1./pip_132_L_no->Integral(),"width");
  pip_132_R_no->Scale(1./pip_132_R_no->Integral(),"width");


  /*
  pim_108_L->Scale(1.,"width");
  pim_108_R->Scale(1.,"width");
  pip_108_L->Scale(1.,"width");
  pip_108_R->Scale(1.,"width");

  pim_132_L->Scale(1.,"width");
  pim_132_R->Scale(1.,"width");
  pip_132_L->Scale(1.,"width");
  pip_132_R->Scale(1.,"width");

  pim_108_L_no->Scale(1.,"width");
  pim_108_R_no->Scale(1.,"width");
  pip_108_L_no->Scale(1.,"width");
  pip_108_R_no->Scale(1.,"width");

  pim_132_L_no->Scale(1.,"width");
  pim_132_R_no->Scale(1.,"width");
  pip_132_L_no->Scale(1.,"width");
  pip_132_R_no->Scale(1.,"width");
  */

  pim_132_L->GetYaxis()->SetTitle("Yield");
  pim_132_L->GetXaxis()->SetTitle("T_{CM}");
  make(pim_132_L);
  make(pim_132_R);

  pip_132_L->GetYaxis()->SetTitle("Yield");
  pip_132_L->GetXaxis()->SetTitle("T_{CM}");
  make(pip_132_L);
  make(pip_132_R);

  pim_108_L->GetYaxis()->SetTitle("Yield");
  pim_108_L->GetXaxis()->SetTitle("T_{CM}");
  make(pim_108_L);
  make(pim_108_R);

  pip_108_L->GetYaxis()->SetTitle("Yield");
  pip_108_L->GetXaxis()->SetTitle("T_{CM}");
  make(pip_108_L);
  make(pip_108_R);

  pim_132_L_no->GetYaxis()->SetTitle("Yield");
  pim_132_L_no->GetXaxis()->SetTitle("T_{CM}");
  make(pim_132_L_no);
  make(pim_132_R_no);

  pip_132_L_no->GetYaxis()->SetTitle("Yield");
  pip_132_L_no->GetXaxis()->SetTitle("T_{CM}");
  make(pip_132_L_no);
  make(pip_132_R_no);

  pim_108_L_no->GetYaxis()->SetTitle("Yield");
  pim_108_L_no->GetXaxis()->SetTitle("T_{CM}");
  make(pim_108_L_no);
  make(pim_108_R_no);

  pip_108_L_no->GetYaxis()->SetTitle("Yield");
  pip_108_L_no->GetXaxis()->SetTitle("T_{CM}");
  make(pip_108_L_no);
  make(pip_108_R_no);




  double lw = 10;

  pip_132_L->Scale(1e-1);
  pip_132_R->Scale(1e-1);
  pip_108_L->Scale(1e-1);
  pip_108_R->Scale(1e-1);
  
  pip_132_L_no->Scale(1e-1);
  pip_132_R_no->Scale(1e-1);
  pip_108_L_no->Scale(1e-1);
  pip_108_R_no->Scale(1e-1);

  pim_132_L->SetLineColor(kBlue-3);
  pim_108_L->SetLineColor(kBlue-3);
  pim_132_R->SetLineColor(kGreen-3);
  pim_108_R->SetLineColor(kGreen-3);

  pip_132_L->SetLineColor(kBlue-3);
  pip_108_L->SetLineColor(kBlue-3);
  pip_132_R->SetLineColor(kGreen-3);
  pip_108_R->SetLineColor(kGreen-3);
  
  pim_132_L->SetLineStyle(10);
  pim_108_L->SetLineStyle(10);
  pim_132_R->SetLineStyle(6);
  pim_108_R->SetLineStyle(6);

  pip_132_L->SetLineStyle(10);
  pip_108_L->SetLineStyle(10);
  pip_132_R->SetLineStyle(6);
  pip_108_R->SetLineStyle(6);

  pim_132_L->SetLineWidth(lw);
  pim_108_L->SetLineWidth(lw);
  pim_132_R->SetLineWidth(lw);
  pim_108_R->SetLineWidth(lw);

  pip_132_L->SetLineWidth(lw);
  pip_108_L->SetLineWidth(lw);
  pip_132_R->SetLineWidth(lw);
  pip_108_R->SetLineWidth(lw);

  pim_132_L_no->SetLineColor(kBlue-3);
  pim_108_L_no->SetLineColor(kBlue-3);
  pim_132_R_no->SetLineColor(kGreen-3);
  pim_108_R_no->SetLineColor(kGreen-3);

  pip_132_L_no->SetLineColor(kBlue-3);
  pip_108_L_no->SetLineColor(kBlue-3);
  pip_132_R_no->SetLineColor(kGreen-3);
  pip_108_R_no->SetLineColor(kGreen-3);
  
  pim_132_L_no->SetLineStyle(10);
  pim_108_L_no->SetLineStyle(10);
  pim_132_R_no->SetLineStyle(6);
  pim_108_R_no->SetLineStyle(6);

  pip_132_L_no->SetLineStyle(10);
  pip_108_L_no->SetLineStyle(10);
  pip_132_R_no->SetLineStyle(6);
  pip_108_R_no->SetLineStyle(6);

  pim_132_L_no->SetLineWidth(lw);
  pim_108_L_no->SetLineWidth(lw);
  pim_132_R_no->SetLineWidth(lw);
  pim_108_R_no->SetLineWidth(lw);

  pip_132_L_no->SetLineWidth(lw);
  pip_108_L_no->SetLineWidth(lw);
  pip_132_R_no->SetLineWidth(lw);
  pip_108_R_no->SetLineWidth(lw);

  pim_132_L->SetTitle("");
  pim_108_L->SetTitle("");
  pim_132_L_no->SetTitle("");
  pim_108_L_no->SetTitle("");


  TLegend *leg = new TLegend(.6,.7,.9,.9);
  leg->AddEntry(pim_132_L,"Left","l");
  leg->AddEntry(pim_132_R,"Right","l");
  leg->SetBorderSize(0);
  leg->SetFillColorAlpha(0,0);

  TLatex latex;
  latex.SetTextSize(.06);
  latex.SetNDC(true);
  

  TF1 *bolt_pim = new TF1("bolt_pim","[0]*(x-[1])*TMath::Exp(-x/[2])",30,500);
  bolt_pim->SetParameters(1,1,10);

  TF1 *bolt_pip = new TF1("bolt_pip","[0]*(x-[1])*TMath::Exp(-x/[2])",60,500);
  bolt_pip->SetParameters(1,1,10);


  //  TCanvas *c2 = new TCanvas("c2","c2",1);
  TCanvas *c2 = stdcvs("c2");

  auto pim_132_L_no_cp = (TH1D *) pim_132_L_no->Clone();
  auto pim_108_L_no_cp = (TH1D *) pim_108_L_no->Clone();
  auto pip_132_L_no_cp = (TH1D *) pip_132_L_no->Clone();
  auto pip_108_L_no_cp = (TH1D *) pip_108_L_no->Clone();

  auto pim_132_R_no_cp = (TH1D *) pim_132_R_no->Clone();
  auto pim_108_R_no_cp = (TH1D *) pim_108_R_no->Clone();
  auto pip_132_R_no_cp = (TH1D *) pip_132_R_no->Clone();
  auto pip_108_R_no_cp = (TH1D *) pip_108_R_no->Clone();

  pim_132_L_no_cp->GetYaxis()->SetTitle("Y_{L}/Y_{R}");
  pip_132_L_no_cp->GetYaxis()->SetTitle("Y_{L}/Y_{R}");
  pim_108_L_no_cp->GetYaxis()->SetTitle("Y_{L}/Y_{R}");
  pip_108_L_no_cp->GetYaxis()->SetTitle("Y_{L}/Y_{R}");


  TLegend *leg2 = new TLegend(.6,.7,.9,.9);
  leg2->AddEntry(pim_132_L_no_cp,"#pi^{-}","l");
  leg2->AddEntry(pip_132_R_no_cp,"#pi^{+}","l");
  leg2->SetBorderSize(0);
  leg2->SetFillColorAlpha(0,0);
  
  make(pim_132_L_no_cp);
  make(pim_108_L_no_cp);
  make(pim_132_R_no_cp);
  make(pim_108_R_no_cp);

  pim_132_L_no_cp->Divide(pim_132_R_no_cp);
  pip_132_L_no_cp->Divide(pip_132_R_no_cp);
  pim_132_L_no_cp->GetYaxis()->SetRangeUser(0,2);
  pim_132_L_no_cp->SetLineColor(kBlue -3);
  pip_132_L_no_cp->SetLineColor(kGreen -3);
  pim_132_L_no_cp->Draw();
  pip_132_L_no_cp->Draw("same");
  leg2->Draw();
  c2->SaveAs("ratioLR_132_no.png");

  pim_108_L_no_cp->Divide(pim_108_R_no_cp);
  pip_108_L_no_cp->Divide(pip_108_R_no_cp);
  pim_108_L_no_cp->GetYaxis()->SetRangeUser(0,2);
  pim_108_L_no_cp->SetLineColor(kBlue -3);
  pip_108_L_no_cp->SetLineColor(kGreen -3);
  pim_108_L_no_cp->Draw();
  pip_108_L_no_cp->Draw("same");
  leg2->Draw();
  c2->SaveAs("ratioLR_108_no.png");


 auto pim_132_L_cp = (TH1D *) pim_132_L->Clone();
 auto pim_108_L_cp = (TH1D *) pim_108_L->Clone();
 auto pip_132_L_cp = (TH1D *) pip_132_L->Clone();
 auto pip_108_L_cp = (TH1D *) pip_108_L->Clone();


 auto pim_132_R_cp = (TH1D *) pim_132_R->Clone();
 auto pim_108_R_cp = (TH1D *) pim_108_R->Clone();
 auto pip_132_R_cp = (TH1D *) pip_132_R->Clone();
 auto pip_108_R_cp = (TH1D *) pip_108_R->Clone();



 pim_132_L_cp->GetYaxis()->SetTitle("Y_{L}/Y_{R}");
 pip_132_L_cp->GetYaxis()->SetTitle("Y_{L}/Y_{R}");
 pim_108_L_cp->GetYaxis()->SetTitle("Y_{L}/Y_{R}");
 pip_108_L_cp->GetYaxis()->SetTitle("Y_{L}/Y_{R}");

  pim_132_L_cp->Divide(pim_132_R_cp);
  pip_132_L_cp->Divide(pip_132_R_cp);
  pim_132_L_cp->GetYaxis()->SetRangeUser(0,2);
  pim_132_L_cp->SetLineColor(kBlue -3);
  pip_132_L_cp->SetLineColor(kGreen -3);
  pim_132_L_cp->Draw();
  pip_132_L_cp->Draw("same");
  leg2->Draw();
  c2->SaveAs("ratioLR_132.png");

  pim_108_L_cp->Divide(pim_108_R_cp);
  pip_108_L_cp->Divide(pip_108_R_cp);
  pim_108_L_cp->GetYaxis()->SetRangeUser(0,2);
  pim_108_L_cp->SetLineColor(kBlue -3);
  pip_108_L_cp->SetLineColor(kGreen -3);
  pim_108_L_cp->Draw();
  pip_108_L_cp->Draw("same");
  leg2->Draw();
  c2->SaveAs("ratioLR_108.png");


}
