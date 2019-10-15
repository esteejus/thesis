

void isotropic()
{
  TRandom3 *ran = new TRandom3(12345);
  TH1D *angles = new TH1D("angles","angles",90,0,90);

  int nMC = 1e6;

  TF1 *theta = new TF1("theta","[0] + [1]*x + [2]*pow(x,2) + [3]*pow(x,3) + [4]*pow(x,4)",0,90);
  theta->SetParameters(-29.4261,427.701,-1.66007,-0.0734422,0.000540305);
  		       
  TF1 *mom = new TF1("mom","[0] + [1]*x + [2]*pow(x,2) + [3]*pow(x,3) + [4]*pow(x,4) + [5]*pow(x,5) + [6]*pow(x,6) + [7]*pow(x,7) + [8]*pow(x,8) + [9]*pow(x,9)",34,550);
  mom->SetParameters(1325.43,-106.233,2.85887,-0.0313853,0.000185054,-6.54095e-07,1.43438e-09,-1.91671e-12,1.43189e-15,-4.58979e-19);

  for(int i = 0; i < nMC; i++)
    {
      double phi = ran->Uniform(0,2*TMath::Pi());
      double theta = acos(2*ran->Uniform() -1);
      double p = mom->GetRandom();
      cout<<"input "<<theta*TMath::RadToDeg()<<endl;
      TLorentzVector vec;
      vec.SetXYZM(p*cos(phi)*sin(theta),p*sin(phi)*sin(theta),p*cos(theta),140.);
      vec.Boost(0,0,.36);
      angles->Fill(vec.Theta()*TMath::RadToDeg());
      cout<<vec.Theta()*TMath::RadToDeg()<<endl;
    }

  angles->Draw();
  

}
