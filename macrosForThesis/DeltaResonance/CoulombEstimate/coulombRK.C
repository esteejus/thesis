
TVector3 force_fcn(TVector3 pos, int charge)
{
  TVector3 force = pos; //defined from origin
  double r = pos.Mag();
  force.Unit();

  double coeff = charge *1e4/pow(r,2);
  force *= coeff;

  return force;
}


vector<TVector3> RKStepper(TVector3 init_pos, TVector3 init_mom, int charge)
{
  vector<TVector3> xpos;
  vector<TVector3> mom_v;
  double h = .01; //time step
  double tn = 0; 
  TVector3 mom = init_mom; //initial momentum
  TVector3 pos = init_pos;
  int count = 0;
  while(count < 1e5)
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

  return xpos;
}



void coulombRK()
{

  TVector3 pos(100,100,100);
  auto force = force_fcn(pos,-1);
  cout<<force.X()<<" "<<force.Y()<<" "<<force.Z()<<endl;

  auto vec = RKStepper(pos,TVector3(-100,-1,0),-1);

  cout<<  vec.size()<<endl;


  TGraph *g = new TGraph(vec.size());
  int counter = 1;
  for(auto p : vec)
    {
      g->SetPoint(counter,p.X(),p.Y());
      counter++;
    }

  g->Draw("ALO");
  
}

