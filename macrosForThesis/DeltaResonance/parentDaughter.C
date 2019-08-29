
auto mpi = 139.57018;
auto mp = 938.2720813;

double bisect(TF1 f)
{
  double min = f.Eval(0);
  double max = f.GetMaximum();

  double minx = 0;
  double maxx = f.GetMaximumX();

  double midp = (maxx - minx)/2. + minx;
  double fc = f.Eval(midp);
 
  for(int i = 0; i < 1e3; i++)
    {
      if(fc <= 0)
	{
	  minx = midp;
	  min = fc;
	}
      else
	{
	  maxx = midp;
	  max = fc;
	}

      midp = (maxx - minx)/2. + minx;
      fc = f.Eval(midp);
      //      cout<<"Min "<<min<<" "<<max<<endl;
      //      cout<<"min x "<<minx<<" "<<maxx<<endl;
      //      cout<<"mid p "<<midp<<" "<<fc<<endl;
   }
  if(abs(midp - min) < 1e-3)
    midp = min;   

  if(midp > 0)
    return midp;
  else if(f.Eval(0) > 0 )// no minimum
    return 0;
 
  return fc;
}

double NewtonsMethod(TF1 f)
{
  
  double min = f.GetMinimum();
  double max = f.GetMaximum();

  double minx = f.GetMinimumX();
  double maxx = f.GetMaximumX();

  double xn = bisect(f);
  double xprev = 0;
 
  for(int i = 0; i < 1e2; i++)
    {
      double fp = f.Derivative(xn);
      double fn = f.Eval(xn);
      xprev = xn;
      xn = xn - fn/fp;
    }

  if(xn > 0)
    return xn;
  else if(xn < 1e-3 && min < 0)
    {
      cout<<"Newtons failed "<<endl;
      return -999999999999;
    }
  else
    return 0;
  
}

double pf_fcn(double *x,double *par)
{
  double s = par[0];
  double mdelta = par[1];
  double pf = x[0];
  
  double edelta = sqrt(pow(mdelta,2) + pow(pf,2));
  double en = sqrt(pow(mp,2) + pow(pf,2));

  return ( edelta + en - s);
}

double q_fcn(double *x,double *par)
{
  double mr = par[0];
  double q = x[0];

  double epi = sqrt(pow(mpi,2) + pow(q,2));
  double en = sqrt(pow(mp,2) + pow(q,2));
  return ( epi + en - mr);
}

double Getq(double mr)
{
 TF1 fcn_q("rmass",q_fcn,0,5000,1);
 fcn_q.SetParameter(0,mr);
 double minval = fcn_q.GetMinimum();
 double maxval = fcn_q.GetMaximum();

 // cout<<"q "<<minval<<" "<<maxval<<endl;
 //cout<<"max "<<maxval<<endl;
 
 if(minval < 0 && maxval > 0)
   return bisect(fcn_q);
   //   return NewtonsMethod(fcn_q);
 else
   {
     //    cout<<"Maybe out of range?? "<<endl;
     return 0;
   }
}

double Getpf(double s, double mr)
{
 TF1 fcn_pf("rmass",pf_fcn,0,5000,2);
 fcn_pf.SetParameters(s,mr);
 double minval = fcn_pf.GetMinimum();
 double maxval = fcn_pf.GetMaximum();
 
 if(minval < 0 && maxval > 0)
   return bisect(fcn_pf);
 else
   {
     //     cout<<"Maybe out of range?? "<<endl;
     return 0;
   }

}

double Getgamma(double mr)
{
  double q = Getq(mr);
  return (.47*pow(q,3)/(pow(mpi,2) + .6*pow(q,2)));
}


double mr_fcn(double *x , double *par)
{
  double norm = par[1];
  double mr = x[0];
  double mr0 = 1232;
  double pf = Getpf(par[0],mr);
  double gamma = Getgamma(mr);
  //  cout<<"Mr "<<mr<<" "<<pf<<" "<<gamma<<endl;

  return norm*( pf * mr * gamma)/( pow((pow(mr,2) - pow(mr0,2)),2) + pow(mr0*gamma,2) );
}

double boltz_mr(double *x, double *par)
{
  //p^2 * P(mr) * exp(- sqrt(p^2 + mr^2)/T) dp
  double mr = par[0];
  //  cout<<mr<<endl;
  double mrr[1] = {mr};
  double p = x[0];
  double s = sqrt(pow(mr,2) + pow(p,2)) + sqrt(pow(mp,2) + pow(p,2));
  double param[2] = {s,1.};
  double P_mr = mr_fcn(mrr,param);
  double T = par[1];
  //  cout<<"T "<<T<<endl;
  return pow(p,2)*P_mr*exp(-sqrt(pow(mr,2) + pow(p,2))/T);
}


double GetS(double labE)
{
  return sqrt(2*pow(mp,2) + 2*(labE + mp)*mp);
}

void parentDaughter()
{
  TCanvas *c1 = new TCanvas("c1","c1");
  TF1 *stpc = new TF1("stpc",boltz_mr,0,5000,2);
  //  stpc->SetParameter(0,1100);
  stpc->SetNpx(1000);

  int np = 1000;
  double minmass = 600;
  double maxmass = 2000;
  double mass_step = (maxmass-minmass)/np;

  //  TFile *f = new TFile("output_Boltz.root","RECREATE");
  TFile *f = new TFile("output_Boltz.root","UPDATE");  

  TGraph *boltzavg = new TGraph(np);
  for(int i = 0; i < np; i++)
    {
      double mr = mass_step*i + minmass;
      double temp = 110;
      stpc->SetParameters(mr,temp);
      double inte = stpc->Integral(0,5000);
      //      cout<<i<<" "<<inte<<endl;
      double coeff = 1;
      boltzavg->SetPoint(i,mr,inte/coeff);
    }
  cout<<"SetCoeff "<<boltzavg->Integral()<<endl;
  boltzavg->Draw("ALO");
 //  cout<<stpc->GetMaximum()<<endl;
  // stpc->SetParameter(1,1./stpc->GetMaximum());
  //  stpc->Draw();
  //  auto boltzh = boltzavg->GetHistogram();
  //  boltzh->Scale(1./boltzh->Integral());
  //  boltzh->Draw();
  //  boltzavg->SetName("boltz_30");
  //  boltzavg->Write();
  auto toTF1 = [boltzavg](double *x, double *par){return boltzavg->Eval(x[0]);};

  TF1 *boltz = new TF1("boltz",toTF1,0,4000,0);
  
  //  auto boltz = boltzavg->GetHistogram();
  TH1D *piondist = new TH1D("pionhist","pion energy dist",2000,0,10000);
  TF1 *delta_e_dist = new TF1("delta_e_dist","TMath::Exp(-x/100)",0,1000);
  TF1 *mass = new TF1("mass","[0]/2/( pow([0],2)/4  + pow(x-[1],2))",0,3000);
  mass->SetParameters(117,1232);
  int nevents = 4e5;
  for(int i = 0; i < nevents; i++)
    {
      double mr = mass->GetRandom();//boltz->GetRandom();
      //      double delta_e = delta_e_dist->GetRandom();
      cout<<"mass "<<mr<<endl;
      double epion = (pow(mr,2) - pow(mpi,2) + pow(mp,2))/(2*mr);
      //      double epion = (pow(mr,2) - pow(mp,2) + pow(mpi,2))/(2*mr);
      piondist->Fill(epion);
    }

  piondist->Draw();

}
