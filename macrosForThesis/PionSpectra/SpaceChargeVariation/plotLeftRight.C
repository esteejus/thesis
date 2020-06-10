#include "/home/justin/mythesis/thesis_style.h"

using namespace style;

void plotLeftRight()
{
  gStyle->SetOptStat(0);
  gStyle->SetFrameLineWidth(5);

  
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

  pim_108_L->GetXaxis()->SetRangeUser(0,290);
  pim_108_R->GetXaxis()->SetRangeUser(0,290);
  pim_132_L->GetXaxis()->SetRangeUser(0,290);
  pim_132_R->GetXaxis()->SetRangeUser(0,290);

  pim_108_L->GetXaxis()->SetRangeUser(0,290);
  pim_108_R->GetXaxis()->SetRangeUser(0,290);
  pim_132_L->GetXaxis()->SetRangeUser(0,290);
  pim_132_R->GetXaxis()->SetRangeUser(0,290);


  double lw = 5;

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

  TCanvas *c1 = new TCanvas("c1","c1",3000,1200);

  //  TCanvas *c1 = stdcvs();

  c1->SetFrameLineWidth(5);
  gPad->SetLineWidth(5);  
  gStyle->SetLineWidth(5);

  c1->Divide(2,1,0,0);
  c1->cd(1)->SetLeftMargin(.15);
  c1->cd(1)->SetTopMargin(.05);
  c1->cd(2)->SetTopMargin(.05);
  c1->cd(1)->SetBottomMargin(.2);
  c1->cd(2)->SetBottomMargin(.2);
  
  c1->SetLogy();
  c1->cd(1);
  c1->cd(1)->SetLogy();
  pim_132_L->GetYaxis()->SetRangeUser(8e-6,2e-2);
  /*
  pim_132_L->Draw("hist L");
  pip_132_L->Draw("same hist L");
  pim_132_R->Draw("same  hist L");  
  pip_132_R->Draw("same hist L");  
  */





  pim_132_L_no->GetYaxis()->SetRangeUser(8e-6,2e-2);
  pim_132_L_no->Draw("E");
  pip_132_L_no->Draw("same E");
  pim_132_R_no->Draw("same E");  
  pip_132_R_no->Draw("same E");  

  pim_132_L_no->Fit(bolt_pim,"","",30,300);
  bolt_pim->SetLineColor(kBlue - 4);
  bolt_pim->SetLineWidth(4);
  bolt_pim->DrawCopy("same");
  
  pim_132_R_no->Fit(bolt_pim,"","",30,300);
  bolt_pim->SetLineColor(kGreen - 4);
  bolt_pim->SetLineWidth(4);
  bolt_pim->DrawCopy("same");

  pip_132_L_no->Fit(bolt_pip,"","",60,300);
  bolt_pip->SetLineColor(kBlue - 4);
  bolt_pip->SetLineWidth(4);
  bolt_pip->DrawCopy("same");
  
  pip_132_R_no->Fit(bolt_pip,"","",60,300);
  bolt_pip->SetLineColor(kGreen - 4);
  bolt_pip->SetLineWidth(4);
  bolt_pip->DrawCopy("same");

  /*
  pim_132_L_no->Draw("hist L");
  pip_132_L_no->Draw("same hist L");
  pim_132_R_no->Draw("same  hist L");  
  pip_132_R_no->Draw("same hist L");  
  */
  latex.DrawLatex(.25,.65,"#pi^{+} #scale[.8]{x 10^{-1}}");
  latex.DrawLatex(.4,.8,"#pi^{-}");
  leg->Draw();
  //  c1->SaveAs("sn132_noSC.png");


  c1->cd(2);
  c1->cd(2)->SetLogy();

  pim_132_L->GetYaxis()->SetTitleOffset(1.1);
  pim_132_L->Draw("E");
  pip_132_L->Draw("same E");
  pim_132_R->Draw("same E");  
  pip_132_R->Draw("same E");  

  pim_132_L->Fit(bolt_pim,"","",30,300);
  bolt_pim->SetLineColor(kBlue - 4);
  bolt_pim->SetLineWidth(4);
  bolt_pim->DrawCopy("same");
  
  pim_132_R->Fit(bolt_pim,"","",30,300);
  bolt_pim->SetLineColor(kGreen - 4);
  bolt_pim->SetLineWidth(4);
  bolt_pim->DrawCopy("same");

  pip_132_L->Fit(bolt_pip,"","",60,300);
  bolt_pip->SetLineColor(kBlue - 4);
  bolt_pip->SetLineWidth(4);
  bolt_pip->DrawCopy("same");
  
  pip_132_R->Fit(bolt_pip,"","",60,300);
  bolt_pip->SetLineColor(kGreen - 4);
  bolt_pip->SetLineWidth(4);
  bolt_pip->DrawCopy("same");


  latex.DrawLatex(.37,.65,"#pi^{+} #scale[.8]{x 10^{-1}}");
  latex.DrawLatex(.48,.8,"#pi^{-}");
  leg->Draw();

  c1->SaveAs("sn132_SC.png");
  

  c1->cd(1);
  pim_108_L_no->GetYaxis()->SetRangeUser(8e-6,2e-2);

  /*
  pim_108_L_no->Draw("hist L");
  pip_108_L_no->Draw("same hist L");
  pim_108_R_no->Draw("same  hist L");  
  pip_108_R_no->Draw("same hist L");  
  */


  pim_108_L_no->GetYaxis()->SetTitleOffset(1.1);
  pim_108_L_no->Draw("");
  pip_108_L_no->Draw("same");
  pim_108_R_no->Draw("same");  
  pip_108_R_no->Draw("same");  


  pim_108_L_no->Fit(bolt_pim,"","",30,300);
  bolt_pim->SetLineColor(kBlue - 4);
  bolt_pim->SetLineWidth(4);
  bolt_pim->DrawCopy("same");
  
  pim_108_R_no->Fit(bolt_pim,"","",30,300);
  bolt_pim->SetLineColor(kGreen - 4);
  bolt_pim->SetLineWidth(4);
  bolt_pim->DrawCopy("same");

  pip_108_L_no->Fit(bolt_pip,"","",60,300);
  bolt_pip->SetLineColor(kBlue - 4);
  bolt_pip->SetLineWidth(4);
  bolt_pip->DrawCopy("same");
  
  pip_108_R_no->Fit(bolt_pip,"","",60,300);
  bolt_pip->SetLineColor(kGreen - 4);
  bolt_pip->SetLineWidth(4);
  bolt_pip->DrawCopy("same");

  
  latex.DrawLatex(.37,.65,"#pi^{+} #scale[.8]{x 10^{-1}}");
  latex.DrawLatex(.48,.8,"#pi^{-}");
  leg->Draw();


  c1->cd(2);
  c1->cd(2)->SetLogy();
  pim_108_L->GetYaxis()->SetRangeUser(8e-6,2e-2);
  pim_108_L->Draw("hist L");
  pip_108_L->Draw("same hist L");
  pim_108_R->Draw("same  hist L");  
  pip_108_R->Draw("same hist L");  

  pim_108_L->Draw("E");
  pip_108_L->Draw("same E");
  pim_108_R->Draw("same E");  
  pip_108_R->Draw("same E");  

  pim_108_L->Fit(bolt_pim,"","",30,300);
  bolt_pim->SetLineColor(kBlue - 4);
  bolt_pim->SetLineWidth(4);
  bolt_pim->DrawCopy("same");
  
  pim_108_R->Fit(bolt_pim,"","",30,300);
  bolt_pim->SetLineColor(kGreen - 4);
  bolt_pim->SetLineWidth(4);
  bolt_pim->DrawCopy("same");

  pip_108_L->Fit(bolt_pip,"","",60,300);
  bolt_pip->SetLineColor(kBlue - 4);
  bolt_pip->SetLineWidth(4);
  bolt_pip->DrawCopy("same");
  
  pip_108_R->Fit(bolt_pip,"","",60,300);
  bolt_pip->SetLineColor(kGreen - 4);
  bolt_pip->SetLineWidth(4);
  bolt_pip->DrawCopy("same");


  latex.DrawLatex(.25,.65,"#pi^{+} #scale[.8]{x 10^{-1}}");
  latex.DrawLatex(.4,.8,"#pi^{-}");
  leg->Draw();

  c1->SaveAs("sn108_SC.png");

  
  cout<<"pim "<<pim_108_L_no->Integral()/pim_108_R_no->Integral()<<endl;
  cout<<"pip "<<pip_108_L_no->Integral()/pip_108_R_no->Integral()<<endl;

}
