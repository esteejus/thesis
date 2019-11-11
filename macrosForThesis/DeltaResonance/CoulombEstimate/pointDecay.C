//Simulates the effect of as static couloumb force on the invariant mass spectra
//Assume wood saxon distribution of protons
//
double tar_a = 132;
double tar_z = 50;

TF1 *tar_radius = new TF1("tar_radius","[2]*pow(x,2)/(1 + TMath::Exp((x-[0])/[1]))",0,15);
//  TF1 *tar_radius = new TF1("tar_radius","1./(1 + TMath::Exp((x-[0])/[1]))",0,15);
double tar_adiff = (.446 + .072*(tar_a-tar_z)/tar_z + .449 + .071*(tar_z/(tar_a-tar_z)))/2;
double tar_R = (1.322*pow(tar_z,1./3) + .007*(tar_a-tar_z) + .022 + .953*pow(tar_a-tar_z,1./3) + .015*tar_z + .774)/2;

//tar_radius -> SetParameters(tar_R,tar_adiff,0.063596078); //normalized to z=50
//  double scale = 4*TMath::Pi()*tar_radius->Integral(0,20); //
// cout<<scale<<endl;


TVector3 force_fcn(TVector3 pos, int charge)
{
  double r = pos.Mag();
  //pos units in fm and center of nucleus at 0,0,0
  TVector3 force = pos;
  force.Unit();
  
  double charge_enc = 0;
  if(r > 4)
    charge_enc = 50;
  else
    charge_enc = 4*TMath::Pi()*tar_radius->Integral(0,r);//charge enclosed
  //  cout<<"charge enc "<<charge_enc<<endl;
  double coeff = 1.44*charge*charge_enc/pow(r,2);
  force *= coeff;
  cout<<force.X()<<" "<<force.Y()<<" "<<force.Z()<<endl;
  return force;
}


vector<TVector3> RKStepper(TVector3 init_pos, TVector3 init_mom, int charge)
{
  vector<TVector3> xpos;
  vector<TVector3> mom_v;
  double h = 1; //time step
  double tn = 0; 
  TVector3 mom = init_mom; //initial momentum
  TVector3 pos = init_pos;
  int count = 0;
  while(count < 1e6)
    {
     auto k1 = force_fcn(pos,charge);

      TVector3 y2 = mom;
      y2 *= h/2;
      y2 += pos;

      auto k2 = force_fcn(y2,charge);
      
      TVector3 y3 = k1;
      y3 *= pow(h,2)/4;
      y3 += y2;

      auto k3 = force_fcn(y3,charge);
      
      TVector3 y4 = k2;
      y4 *= .5;
      y4 += mom;
      y4 *= h;
      y4 += pos;

      auto k4 = force_fcn(y4,charge);

      TVector3 x3 = k1 + k2 + k3;
      x3 *= pow(h,2)/6;
      TVector3 x2 = mom;
      x2 *= h;
      
      k2 *= 2;
      k3 *= 2;
      TVector3 mom_d = k1 + k2 + k3 + k4;
      mom_d *= h/6;
      
      pos = pos + x2 + x3;
      mom = mom + mom_d;
      tn += h;
      xpos.push_back(pos);      
      mom_v.push_back(mom);      
      count++;
    }

  return mom_v;
}

 /*
TVector3 RKStepper(TVector3 init_pos, TVector3 init_mom, int charge)
{
  double h = 1; //time step
  double tn = 0; 
  TVector3 mom = init_mom; //initial momentum
  TVector3 pos = init_pos;
  int count = 0;
  while(count < 1e6)
    {
     auto k1 = force_fcn(pos,charge);

      TVector3 y2 = mom;
      y2 *= h/2;
      y2 += pos;

      auto k2 = force_fcn(y2,charge);
      
      TVector3 y3 = k1;
      y3 *= pow(h,2)/4;
      y3 += y2;

      auto k3 = force_fcn(y3,charge);
      
      TVector3 y4 = k2;
      y4 *= .5;
      y4 += mom;
      y4 *= h;
      y4 += pos;

      auto k4 = force_fcn(y4,charge);

      TVector3 x3 = k1 + k2 + k3;
      x3 *= pow(h,2)/6;
      TVector3 x2 = mom;
      x2 *= h;
      
      k2 *= 2;
      k3 *= 2;
      TVector3 mom_d = k1 + k2 + k3 + k4;
      mom_d *= h/6;
      
      pos = pos + x2 + x3;
      mom = mom + mom_d;
      tn += h;
      count++;
    }

  return mom;
}
 */

void pointDecay()
{
  tar_radius -> SetParameters(tar_R,tar_adiff,0.063596078); //normalized to z=50
  double pi_m = 140;
  double nuc_m = 938;
  double m_delta = 1150;

  double pi_e = (pow(m_delta,2) + pow(pi_m,2) - pow(nuc_m,2))/(2*m_delta);
  double p_e = (pow(m_delta,2) + pow(nuc_m,2) - pow(pi_m,2))/(2*m_delta);
    
  double pi_p = sqrt(pow(pi_e,2) - pow(pi_m,2)); //COM
  double p_p =  sqrt(pow(p_e,2) - pow(nuc_m,2));// COM

  TRandom3 *ran = new TRandom3(1234);
  double theta = acos(2*ran->Uniform()-1);
  double phi   = ran->Uniform(0,2*TMath::Pi());

  double theta_c = TMath::Pi() - theta;
  double phi_c = TMath::Pi() + phi;


  TLorentzVector pion,proton;
  if(ran->Uniform() < .5)
    {
      pion.SetPxPyPzE(pi_p*sin(theta)*cos(phi),pi_p*sin(theta)*sin(phi),pi_p*cos(theta),pi_e);
      proton.SetPxPyPzE(p_p*sin(theta_c)*cos(phi_c),p_p*sin(theta_c)*sin(phi_c),p_p*cos(theta_c),p_e);
    }
  else
    {
      pion.SetPxPyPzE(pi_p*sin(theta_c)*cos(phi_c),pi_p*sin(theta_c)*sin(phi_c),pi_p*cos(theta_c),pi_e);
      proton.SetPxPyPzE(p_p*sin(theta)*cos(phi),p_p*sin(theta)*sin(phi),p_p*cos(theta),p_e);
    }


  //pion and proton are back to back delta assumed to have no momenta
  TVector3 pos(5,0,0);
  TVector3 mom_pi = pion.Vect();
  TVector3 mom_p(0,0,0);
//  TVector3 mom_p  = proton.Vect();

//  auto mom_pif = RKStepper(pos,mom_pi,-1);
  //  auto mom_pf = RKStepper(pos,mom_p,1);
  //  cout<<mom_p.Mag()<<" "<<mom_pf.Mag()<<endl;

  cout<<mom_pi.X()<<" "<<mom_pi.Y()<<endl;
 auto vec = RKStepper(pos,mom_p,1);
 cout<<  vec.size()<<endl;

  TGraph *g = new TGraph(vec.size());
  int counter = 1;
  for(auto p : vec)
    {
      g->SetPoint(counter,counter,p.Mag());
      counter++;
    }

  g->Draw("APO");


}
