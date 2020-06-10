

void fitCoulombPotential()
{
 TFile *f = TFile::Open("/home/justin/mythesis/macrosForThesis/PionSpectra/rootfiles/publishPions_sm.root");
  TH1D *singleRatio_sn132 = (TH1D *)f->Get("singleRatio_sn132");
  TH1D *singleRatio_sn108 = (TH1D *)f->Get("singleRatio_sn108");

 TFile *g = TFile::Open("/home/justin/mythesis/macrosForThesis/PionSpectra/rootfiles/publishPions.root");
  TH1D *pip_132 = (TH1D *)g->Get("pip_sn132");
  TH1D *pim_132 = (TH1D *)g->Get("pim_sn132");
  TH1D *pip_108 = (TH1D *)g->Get("pip_sn108");
  TH1D *pim_108 = (TH1D *)g->Get("pim_sn108");

  double s132_n = 132 + 124 - 100;
  double s132_p = 100;

  double s108_n = 108 + 112 - 100;
  double s108_p = 100;

  /*
  double r132 = (5*pow(s132_n,2) + s132_n*s132_p)/(5*pow(s132_p,2) + s132_n*s132_p);
  double r108 = (5*pow(s108_n,2) + s108_n*s108_p)/(5*pow(s108_p,2) + s108_n*s108_p);
  */

  //r132 from N/Z  2.09
  //r108 from N/Z  1.36

  //Data driven
  double r132 = 4.83;
  double r108 = 2.04;

  cout<<"Sn132 ratio "<<r132<<endl;
  cout<<"Sn108 ratio "<<r108<<endl;

  double coul_factor = 6 * 100 * 1.44/5; //fm * MeV
  double pi_mass = 139.57;
  double sn132_temp = 0;
  double sn108_temp = 0;
  
  /*
  TF1 *blz = new TF1("blz","[0]*(x + [3] - [1])*TMath::Exp(-(x + [3])/[2])",0,300);
  blz->SetParameters(100,10,30);
  blz->FixParameter(3,pi_mass);
  */
  TF1 *blz = new TF1("blz","[0]*TMath::Exp(-(x + [1])/[2])",0,300);
  blz->SetParameter(0,1000);
  blz->SetParameter(2,20);
  blz->FixParameter(1,pi_mass);

  pip_132->Fit(blz,"","",100,300);
  sn132_temp += blz->GetParameter(2);
  pim_132->Fit(blz,"","",75,300);
  sn132_temp += blz->GetParameter(2);
  sn132_temp /= 2;

  pip_108->Fit(blz,"","",100,300);
  sn108_temp += blz->GetParameter(2);
  pim_108->Fit(blz,"","",75,300);
  sn108_temp += blz->GetParameter(2);
  sn108_temp /= 2;

  /*
  pim_132->Fit(blz,"","",20,300);
  sn132_temp += blz->GetParameter(2);
  sn132_temp /= 2;

  pip_108->Fit(blz,"","",50,300);
  sn108_temp += blz->GetParameter(2);
  pip_132->Fit(blz,"","",50,300);
  sn108_temp += blz->GetParameter(2);
  sn108_temp /= 2;

  cout<<"Sn132 avg. "<<sn132_temp<<endl;
  cout<<"Sn108 avg. "<<sn108_temp<<endl;
  */
  /*
  pip_132->Fit(blz);
  pim_132->Fit(blz);
  pip_108->Fit(blz);
  pim_108->Fit(blz);
  */

  cout<<"Sn132 avg. "<<sn132_temp<<endl;
  cout<<"Sn108 avg. "<<sn108_temp<<endl;

  //Total E
  //  TF1 *fcn = new TF1("fcn","[0]*TMath::Exp(-2*[1]/[2])*(x + [1])/(x - [1])*TMath::Sqrt( (pow(x + [1],2) - pow([3],2))/(pow(x - [1],2) - pow([3],2)) )",100,300);


  //K.E.
  //  TF1 *fcn = new TF1("fcn","[0]*TMath::Exp(-2*[1]/[2])*(x + [3] + [1])/(x + [3] - [1])*TMath::Sqrt( (pow(x + [3] + [1],2) - pow([3],2))/(pow(x + [3] - [1],2) - pow([3],2)) )",30,300);

  //Solve root
 
  TF1 *fcn = new TF1("fcn","[0] - [1]*TMath::Exp(-2*x/[3])*([2] + [4] + x)/([2] + [4] - x)*TMath::Sqrt( (pow([2] + [4] + x,2) - pow([4],2))/(pow([2] + [4] - x,2) - pow([4],2)) )",0,70);

  //  fcn->SetParameters(r132,20,30,pi_mass);
  //experimental ratio,guess ratio, KE, temp, mass
  int np = singleRatio_sn132->GetNbinsX();
  TGraph *coulomb = new TGraph(np);
  TGraph *radius = new TGraph(np);
  for(int i = 1; i <= np; i++)
    {
      double ratio = singleRatio_sn132->GetBinContent(i);
      double ke = singleRatio_sn132->GetBinCenter(i);

      fcn->SetParameters(ratio,r132,ke,sn132_temp,pi_mass);
      if(i == 2)
      fcn->SetParameters(ratio-1,r132,ke,sn132_temp,pi_mass);
      //      if(i == 2)
      //	{
	  cout<<ke<<" "<<ratio<<" "<<fcn->GetX(0)<<endl;
	  //	  fcn->Draw();
	  //	}
    coulomb->SetPoint(i-1,ke,fcn->GetX(0));
    radius->SetPoint(i-1,ke,coul_factor/fcn->GetX(0));
    }
  
  //for plotting
  //  fcn->SetParameters(r132,15,sn132_temp,pi_mass);
  coulomb->SetMarkerStyle(20);
  coulomb->SetMarkerSize(2);
  coulomb->SetMarkerColor(kBlue);
  coulomb->Draw("APO");
  radius->SetMarkerStyle(22);
  radius->SetMarkerSize(2);
  radius->SetMarkerColor(kGreen);
  radius->Draw("same APO Y+");
  //  singleRatio_sn132->Draw();
  //  cout<<fcn->Eval(200)<<endl;
  //  fcn->Draw("same");


}
