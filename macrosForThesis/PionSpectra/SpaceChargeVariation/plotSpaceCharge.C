

void plotSpaceCharge()
{

  TFile *sn108_nom = TFile::Open("analysis-Sn108-nominal_Ratio.root");
  TFile *sn108_minus = TFile::Open("analysis-Sn108-minus_Ratio.root");
  TFile *sn108_plus = TFile::Open("analysis-Sn108-plus_Ratio.root");

  TFile *sn132_nom = TFile::Open("analysis-Sn132-nominal_new_Ratio.root");
  //  TFile *sn132_nom = TFile::Open("analysis-Sn132-nominal_Ratio.root");
  TFile *sn132_minus = TFile::Open("analysis-Sn132-minus_new_Ratio.root");
  TFile *sn132_plus = TFile::Open("analysis-Sn132-plus_new_Ratio.root");

  TH1D *pim_108_nom = (TH1D *)sn108_nom->Get("pimkecm_ec");
  TH1D *pip_108_nom = (TH1D *)sn108_nom->Get("pipkecm_ec");
  TH1D *pim_108_minus = (TH1D *)sn108_minus->Get("pimkecm_ec");
  TH1D *pip_108_minus = (TH1D *)sn108_minus->Get("pipkecm_ec");
  TH1D *pim_108_plus = (TH1D *)sn108_plus->Get("pimkecm_ec");
  TH1D *pip_108_plus = (TH1D *)sn108_plus->Get("pipkecm_ec");

  TH1D *pim_132_nom = (TH1D *)sn132_nom->Get("pimkecm_ec");
  TH1D *pip_132_nom = (TH1D *)sn132_nom->Get("pipkecm_ec");
  TH1D *pim_132_minus = (TH1D *)sn132_minus->Get("pimkecm_ec");
  TH1D *pip_132_minus = (TH1D *)sn132_minus->Get("pipkecm_ec");
  TH1D *pim_132_plus = (TH1D *)sn132_plus->Get("pimkecm_ec");
  TH1D *pip_132_plus = (TH1D *)sn132_plus->Get("pipkecm_ec");

  //  pim_132_nom->Divide(pip_132_nom);
  //  pim_132_minus->Divide(pip_132_minus);
  //  pim_132_plus->Divide(pip_132_plus);

  pim_108_nom->Divide(pip_108_nom);
  pim_108_minus->Divide(pip_108_minus);
  pim_108_plus->Divide(pip_108_plus);

  pim_132_nom->SetLineColor(1);
  pim_132_minus->SetLineColor(4);
  pim_132_plus->SetLineColor(2);
  
  pim_108_nom->SetLineColor(1);
  pim_108_minus->SetLineColor(4);
  pim_108_plus->SetLineColor(2);

  TCanvas *c1 = new TCanvas("c1","c1",1);
  pim_132_nom->Draw("hist ");
  pim_132_minus->Draw("same hist ");
  pim_132_plus->Draw("same hist ");
  
}
