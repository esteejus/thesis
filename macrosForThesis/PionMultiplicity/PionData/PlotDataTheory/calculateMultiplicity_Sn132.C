

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


void calculateMultiplicity_Sn132()
{
  TFile *f = TFile::Open("../rootfiles/publishPions.root");
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
