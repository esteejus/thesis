

/*
TH1D * calculateUpError(TH1D *h)
{
  TH1D *copy = (TH1D *)h->Clone();

  for(int i = 1; i <= h->GetNbinsX(); i++)
    copy->SetBinContent(i,h->GetBinErrorUp(i) + copy->GetBinContent(i));

  return copy;
}
*/

double UpError(TH1D *h)
{
  TH1D *copy = (TH1D *)h->Clone();

  for(int i = 1; i <= h->GetNbinsX(); i++)
    copy->SetBinContent(i,h->GetBinErrorUp(i) + copy->GetBinContent(i));


  return (copy->Integral("width") - h->Integral("width"));
}

double LowError(TH1D *h)
{
  TH1D *copy = (TH1D *)h->Clone();

  for(int i = 1; i <= h->GetNbinsX(); i++)
    copy->SetBinContent(i,copy->GetBinContent(i) - h->GetBinErrorUp(i));

  return ( h->Integral("width") - copy->Integral("width") );
}


void calculateMultiplicityCutVar_Sn132()
{

 vector<int> clust_cut   =  {26,24,22,18,16,14,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20};
  vector<double> poca_cut =  {20,20,20,20,20,20,14,16,18,22,24,26,20,20,20,20,20,20,20,20,20,20,20,20};
  vector<int> mult_132    =  {51,51,51,51,51,51,51,51,51,51,51,51,65,60,55,45,40,35,51,51,51,51,51,51};
  vector<int> mult_108    =  {50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,65,60,55,45,40,35};


  for(int iCut = 0; iCut < clust_cut.size(); iCut++)
    {
      TString pimkecm_ec_A_name = Form("pimkecm_ec_A_nc%d_dpoca%.0f_132mult%d_108mult%d_flatPhiCut", clust_cut.at(iCut), poca_cut.at(iCut), mult_132.at(iCut), mult_108.at(iCut));
      TString pipkecm_ec_A_name = Form("pipkecm_ec_A_nc%d_dpoca%.0f_132mult%d_108mult%d_flatPhiCut", clust_cut.at(iCut), poca_cut.at(iCut), mult_132.at(iCut), mult_108.at(iCut));
      pimkecm_ec_A[iCut] = new TH1D(pimkecm_ec_A_name,pimkecm_ec_A_name,15,kebins);
      pipkecm_ec_A[iCut] = new TH1D(pipkecm_ec_A_name,pipkecm_ec_A_name,15,kebins);
      
      TString pimkecm_ec_err_A_name = Form("pimkecm_ec_err_A_nc%d_dpoca%.0f_132mult%d_108mult%d_flatPhiCut", clust_cut.at(iCut), poca_cut.at(iCut), mult_132.at(iCut), mult_108.at(iCut));
      TString pipkecm_ec_err_A_name = Form("pipkecm_ec_err_A_nc%d_dpoca%.0f_132mult%d_108mult%d_flatPhiCut", clust_cut.at(iCut), poca_cut.at(iCut), mult_132.at(iCut), mult_108.at(iCut));
      pimkecm_ec_err_A[iCut] = new TH1D(pimkecm_ec_err_A_name,pimkecm_ec_err_A_name,15,kebins);
      pipkecm_ec_err_A[iCut] = new TH1D(pipkecm_ec_err_A_name,pipkecm_ec_err_A_name,15,kebins);

      pimkecm_ec_A[iCut] -> Sumw2();
      pipkecm_ec_A[iCut] -> Sumw2();
      pimkecm_ec_err_A[iCut] -> Sumw2();
      pipkecm_ec_err_A[iCut] -> Sumw2();

    }



  
  TFile *f = TFile::Open("../rootfiles/analysis-cutVar-spectra-Sn132.root");
  TH1D * pim_sn132 = (TH1D *)f->Get("pim_sn132");
  TH1D * pip_sn132 = (TH1D *)f->Get("pip_sn132");

  TH1D * pim_sn108 = (TH1D *)f->Get("pim_sn108");
  TH1D * pip_sn108 = (TH1D *)f->Get("pip_sn108");


  cout<<"Sn132 "<<endl;
  cout << "pi- "<< ","<< pim_sn132->Integral("width") << ","<< UpError(pim_sn132) << "," << LowError(pim_sn132)<<endl;
  cout << "pi+ "<< ","<< pip_sn132->Integral("width") << ","<< UpError(pip_sn132) << "," << LowError(pip_sn132)<<endl;

  cout<<"Sn108 "<<endl;
  cout << "pi- "<< ","<< pim_sn108->Integral("width") << ","<< UpError(pim_sn108) << "," << LowError(pim_sn108)<<endl;
  cout << "pi+ "<< ","<< pip_sn108->Integral("width") << ","<< UpError(pip_sn108) << "," << LowError(pip_sn108)<<endl;



}
