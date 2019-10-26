
struct particle{
  double x;
  double y;
  double z;
  bool coll;

};

void UpdateZstep(vector<particle> &a)
{
  double dz = .5;
  for( auto &part : a)
    part.z += dz;
}


void checkCollision(vector<particle> &a, vector<particle> &b)
{
  double dr = 1; //fm which is ~30mb
  
  for( auto &part1 : a)
    {
      for( auto &part2 : b)
	{
	  double r = sqrt(pow(part1.x - part2.x,2) + pow(part1.y - part2.y,2) + pow(part1.z - part2.z,2));
	  if(r < dr )
	    {
	      part1.coll = true;
	      part2.coll = true;
	    }
	}
    }
      
}

vector<double> getColl(vector<particle> a, int idx )
{
  vector<double> out;
  for( auto &part : a)
    {
      if(part.coll)
	{
	  if(idx == 0)
	    out.push_back(part.x);
	  else if(idx == 1)
	    out.push_back(part.y);
	  else if(idx == 2)
	    out.push_back(part.z);
	}
    }

  return out;
}

vector<double> getNColl(vector<particle> a, int idx)
{
  vector<double> out;
  for( auto &part : a)
    {
      if(!part.coll)
	{
	  if(idx == 0)
	    out.push_back(part.x);
	  else if(idx == 1)
	    out.push_back(part.y);
	  else if(idx == 2)
	    out.push_back(part.z);
	}
    }

  return out;
}

int getApart(vector<particle> &a, vector<particle> &b)
{
  int apart = 0;
  
  for( auto &part1 : a)
    {
      if(part1.coll)
	apart++;
    }
  for( auto &part2 : b)
    {
      if(part2.coll)
	apart++;
    }

  return apart;  
}

void getApart()
{
  double tar_a = 132;
  double tar_z = 50;

  double proj_a = 124;
  double proj_z = 50;

  double b = 4; //impact parameter 
  
  TF1 *tar_radius = new TF1("tar_radius","pow(x,2)/(1 + TMath::Exp((x-[0])/[1]))",0,15);
  TF1 *proj_radius = new TF1("proj_radius","pow(x,2)/(1 + TMath::Exp((x-[0])/[1]))",0,15);

  double tar_adiff = (.446 + .072*(tar_a-tar_z)/tar_z + .449 + .071*(tar_z/(tar_a-tar_z)))/2;
  double proj_adiff = (.446 + .072*(proj_a-proj_z)/proj_z + .449 + .071*(proj_z/(proj_a-proj_z)))/2;

  double tar_R = (1.322*pow(tar_z,1./3) + .007*(tar_a-tar_z) + .022 + .953*pow(tar_a-tar_z,1./3) + .015*tar_z + .774)/2;
  double proj_R = (1.322*pow(proj_z,1./3) + .007*(proj_a-proj_z) + .022 + .953*pow(proj_a-proj_z,1./3) + .015*proj_z + .774)/2;

  tar_radius -> SetParameters(tar_R,tar_adiff);
  proj_radius -> SetParameters(proj_R,proj_adiff);

  TRandom3 *ran = new TRandom3(12345);

  double start_tar = 2*tar_R + 10;
  
  vector<particle> target, proj;
  for(int i = 0; i < tar_a; i++)
    {
      double theta = acos(2*ran->Uniform() - 1);
      double phi = ran->Uniform(0,2*TMath::Pi());
      double r   = tar_radius->GetRandom();
      particle part;
      part.x = r*cos(phi)*sin(theta) + b;
      part.y = r*sin(phi)*sin(theta);
      part.z = r*cos(theta) - start_tar;
      part.coll = false;
      target.push_back(part);
    }

  for(int i = 0; i < proj_a; i++)
    {
      double theta = acos(2*ran->Uniform() - 1);
      double phi = ran->Uniform(0,2*TMath::Pi());
      double r   = proj_radius->GetRandom();
      particle part;
      part.x = r*cos(phi)*sin(theta);
      part.y = r*sin(phi)*sin(theta);
      part.z = r*cos(theta);
      part.coll = false;
      proj.push_back(part);
    }

  for(int i =0; i < 80; i++)
    {
      UpdateZstep(target);
      checkCollision(target,proj);
    }
  cout<<"Apart "<<getApart(target,proj)<<endl;

  TGraph *tar_coll  = new TGraph(getColl(target,0).size(),getColl(target,0).data(),getColl(target,2).data());
  TGraph *tar_ncoll = new TGraph(getNColl(target,0).size(),getNColl(target,0).data(),getNColl(target,2).data());

  TGraph *proj_coll  = new TGraph(getColl(proj,0).size(),getColl(proj,0).data(),getColl(proj,2).data());
  TGraph *proj_ncoll = new TGraph(getNColl(proj,0).size(),getNColl(proj,0).data(),getNColl(proj,2).data());

  tar_coll->SetMarkerStyle(20);
  tar_ncoll->SetMarkerStyle(20);
  tar_coll->SetMarkerSize(2);  
  tar_ncoll->SetMarkerSize(2);  
  tar_coll->SetMarkerColor(2);  
  tar_ncoll->SetMarkerColor(kRed - 10);  

  proj_coll->SetMarkerStyle(20);
  proj_ncoll->SetMarkerStyle(20);
  proj_coll->SetMarkerSize(2);  
  proj_ncoll->SetMarkerSize(2);  
  proj_coll->SetMarkerColor(4);  
  proj_ncoll->SetMarkerColor(kBlue - 10);  


  TH1D *test = new TH1D("test","test",20,-20,20);
  test->GetYaxis()->SetRangeUser(-30,30);

  test->Draw();
  tar_coll->Draw("same PO");
  proj_coll->Draw("same PO");
  tar_ncoll->Draw("same PO");
  proj_ncoll->Draw("same PO");

}
