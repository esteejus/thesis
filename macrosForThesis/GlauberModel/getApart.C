
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

  double b = 0; //impact parameter 
  
  TF1 *tar_radius = new TF1("tar_radius","pow(x,2)/(1 + TMath::Exp((x-[0])/[1]))",0,15);
  TF1 *proj_radius = new TF1("proj_radius","pow(x,2)/(1 + TMath::Exp((x-[0])/[1]))",0,15);

  double tar_adiff = (.446 + .072*(tar_a-tar_z)/tar_z + .449 + .071*(tar_z/(tar_a-tar_z)))/2;
  double proj_adiff = (.446 + .072*(proj_a-proj_z)/proj_z + .449 + .071*(proj_z/(proj_a-proj_z)))/2;

  double tar_R = (1.322*pow(tar_z,1./3) + .007*(tar_a-tar_z) + .022 + .953*pow(tar_a-tar_z,1./3) + .015*tar_z + .774)/2;
  double proj_R = (1.322*pow(proj_z,1./3) + .007*(proj_a-proj_z) + .022 + .953*pow(proj_a-proj_z,1./3) + .015*proj_z + .774)/2;

  tar_radius -> SetParameters(tar_R,tar_adiff);
  proj_radius -> SetParameters(proj_R,proj_adiff);

  //  TRandom3 *ran = new TRandom3(12345);
  TRandom3 *ran = new TRandom3(0);
  double start_tar = 2*tar_R + 10;
  
  int mc = 1e2;
  double apart = 0;

  for(int iMC = 0; iMC < mc; iMC++)
    {

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
      apart += getApart(target,proj);
    }
  
  cout<<"Apart "<<apart/mc<<endl;

}
