

void plotLeftRight()
{

  TFile *sn108_sc = TFile::Open("analysis-Sn108-nominal_LR.root");
  TFile *sn132_sc = TFile::Open("analysis-Sn132-nominal_LR.root");

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

  pim_132_L->SetLineWidth(4);
  pim_108_L->SetLineWidth(4);
  pim_132_R->SetLineWidth(4);
  pim_108_R->SetLineWidth(4);

  pip_132_L->SetLineWidth(4);
  pip_108_L->SetLineWidth(4);
  pip_132_R->SetLineWidth(4);
  pip_108_R->SetLineWidth(4);

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

  pim_132_L_no->SetLineWidth(4);
  pim_108_L_no->SetLineWidth(4);
  pim_132_R_no->SetLineWidth(4);
  pim_108_R_no->SetLineWidth(4);

  pip_132_L_no->SetLineWidth(4);
  pip_108_L_no->SetLineWidth(4);
  pip_132_R_no->SetLineWidth(4);
  pip_108_R_no->SetLineWidth(4);


  TCanvas *c1 = new TCanvas("c1","c1",1);
  c1->SetLogy();
  pim_132_L->GetYaxis()->SetRangeUser(8e-6,2e-2);
  pim_132_L->Draw("hist L");
  pip_132_L->Draw("same hist L");
  pim_132_R->Draw("same  hist L");  
  pip_132_R->Draw("same hist L");  

  c1->SaveAs("sn132_SC.png");
  
  pim_108_L->GetYaxis()->SetRangeUser(8e-6,2e-2);
  pim_108_L->Draw("hist L");
  pip_108_L->Draw("same hist L");
  pim_108_R->Draw("same  hist L");  
  pip_108_R->Draw("same hist L");  
  c1->SaveAs("sn108_SC.png");
  
  pim_132_L_no->GetYaxis()->SetRangeUser(8e-6,2e-2);
  pim_132_L_no->Draw("hist L");
  pip_132_L_no->Draw("same hist L");
  pim_132_R_no->Draw("same  hist L");  
  pip_132_R_no->Draw("same hist L");  
  c1->SaveAs("sn132_noSC.png");

  pim_108_L_no->GetYaxis()->SetRangeUser(8e-6,2e-2);
  pim_108_L_no->Draw("hist L");
  pip_108_L_no->Draw("same hist L");
  pim_108_R_no->Draw("same  hist L");  
  pip_108_R_no->Draw("same hist L");  
  c1->SaveAs("sn108_noSC.png");
  
}
