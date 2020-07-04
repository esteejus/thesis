

void plotMultiplicity()
{

  vector<int> low_mult_132  = {46,48,50,52,54,56,58,60,65,75};
  vector<double> bavg = {4.12,3.647,3.13,2.598,2.068,1.57,1.13,.68,.2};
  vector<double> totalEvents = {159986,156061,142277,119505,91459,62634,37692,30809,2936};


  TF1 *pip_fcn = new TF1("pip_fcn","[0]*TMath::Exp(-x/[1])",0,5);
  TF1 *pim_fcn = new TF1("pim_fcn","[0]*TMath::Exp(-x/[1])",0,5);
  pip_fcn->SetParameters(1,1.);
  pim_fcn->SetParameters(1,1.);

  double pip_c = 6.15;
  double pim_c = 6.05;

  TFile *f = TFile::Open("analysis-mult-Sn132-merge.root");

  TH1D * pipkecm[low_mult_132.size()-1];
  TH1D * pimkecm[low_mult_132.size()-1];
  TGraph *pip_mult = new TGraph(low_mult_132.size()-1);
  TGraph *pim_mult = new TGraph(low_mult_132.size()-1);

  for(int i = 0; i < low_mult_132.size()-1; i++)
    {
      TString pimname = Form("pimkecm_ec20_dpoca20_132mult%d_flatPhiCut",low_mult_132.at(i));
      TString pipname = Form("pipkecm_ec20_dpoca20_132mult%d_flatPhiCut",low_mult_132.at(i));

      pipkecm[i] = (TH1D *)f->Get(pipname);
      pimkecm[i] = (TH1D *)f->Get(pimname);

      pipkecm[i]->Scale(pip_c/totalEvents.at(i));
      pimkecm[i]->Scale(pim_c/totalEvents.at(i));
      
      pip_mult->SetPoint(i,bavg.at(i),pipkecm[i]->Integral());
      pim_mult->SetPoint(i,bavg.at(i),pimkecm[i]->Integral());
    }

  pip_mult->Fit(pip_fcn);  
  pim_mult->Fit(pim_fcn,"","",.5,5);  

  pip_mult->SetMarkerStyle(20);
  pip_mult->SetMarkerSize(2);
  pip_mult->SetMarkerColor(kRed-4);
  
  pim_mult->SetMarkerStyle(20);
  pim_mult->SetMarkerSize(2);
  pim_mult->SetMarkerColor(kBlue-4);
  

  TCanvas *c1 = new TCanvas("c1","c1",1);
  c1->SetLogy();
  
  pim_mult->GetYaxis()->SetRangeUser(.05,2);
  pim_mult->Draw("APO");
  pip_mult->Draw("same PO");

}
