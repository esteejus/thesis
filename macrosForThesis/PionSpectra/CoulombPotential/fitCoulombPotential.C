

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

  double r132 = 2.4;
  double r108 = 1.5;

  cout<<"Sn132 ratio "<<r132<<endl;
  cout<<"Sn108 ratio "<<r108<<endl;

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

  //  TF1 *fcn = new TF1("fcn","[0]*TMath::Exp(-2*[1]/[2])*(x + [1])/(x - [1])*TMath::Sqrt( (pow(x + [1],2) - pow([3],2))/(pow(x - [1],2) - pow([3],2)) )",100,300);
  TF1 *fcn = new TF1("fcn","[0]*TMath::Exp(-2*[1]/[2])*(x + [3] + [1])/(x + [3] - [1])*TMath::Sqrt( (pow(x + [3] + [1],2) - pow([3],2))/(pow(x + [3] - [1],2) - pow([3],2)) )",30,300);

  //  TF1 *fcn = new TF1("fcn","[0]*(1 + 2*[1]*( [2]/(pow(x + [2],2) - pow([2],2)) - 1/[3]))",20,300);
  
  fcn->SetParameters(r132,5,45,pi_mass);

  singleRatio_sn132->Draw();
  cout<<fcn->Eval(200)<<endl;
  fcn->Draw("same");


}
