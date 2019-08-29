//simulates the dalitz plot of a 3 body decay
//of the system M -> p1 + p2 + p3
//in our case pi0 -> y + e- + e+

auto mpi = 140; //mass of decaying particle M  (pi zero)
auto me = .511; //mass of electron
auto my = 0; //mass of gamma ray
auto total = pow(mpi,2) + 2*pow(me,2) + pow(my,2);

double mom_conserve(double beta, double p_y, double p_ep, double p_em)
{
  return p_ep * TMath::Cos(beta) + sqrt(pow(p_em,2) - pow(p_ep * sin(beta),2)) - p_y;
}

void dalitzDecay()
{

  //invariant mass vector:
  // s.X() = s23 = (pM - py) ^2
  // s.Y() = s13 = (pM - pe-)^2
  // s.Z() = s12 = (pM - pe+)^2
  //In COM of decaying particle where P(M) = 0 vector
  //s1 = s23 = M^2 - m1^2 - 2*M*E1
  //s2 = s13 = M^2 - m2^2 - 2*M*E2
  //s3 = s12 = M^2 - m3^2 - 2*M*E3
  int numNan = 0;

  TH2D *dalitz_p = new TH2D("dalitz_p","Dalitz plot",100,0,20000,100,0,20000);

  int nEvents = 1e5;
  TRandom3 *ran = new TRandom3(12345);
  
  for(int iEvent = 0; iEvent < nEvents; iEvent++)
    {
      double s1 = ran->Uniform(.0001,20000);
      double s2 = ran->Uniform(.0001,20000);
      double s3 = total - s1 - s2; //conservation theorem

      //Energies in rest frame of pi zero
      double Ey  = (pow(mpi,2) + pow(my,2) - s1)/( 2*mpi); 
      double Eem = (pow(mpi,2) + pow(me,2) - s2)/( 2*mpi);
      double Eep = (pow(mpi,2) + pow(me,2) - s3)/( 2*mpi);

      double s_t = s1 + s2 + s3;

      //solution is only valid if s3 > 0;
      if(s3 <= 1e-4)
	continue;
      
      dalitz_p->Fill(s3,s1);

      double p_y  = Ey;
      double p_em = sqrt(pow(Eem,2) - pow(me,2));
      double p_ep = sqrt(pow(Eep,2) - pow(me,2));

      if(isnan(p_ep) || isnan(p_em))
	{
	  numNan++;
	  continue;
	}

      /*
	angle definitions
alpha + beta = angle_y

                      - ep
                  -
             -    beta
gamma ----- - - - - 
	   -   alpha
	     -
	       -  em
      */

      double cos_ep = (pow(mpi,2)/2 - mpi*Eem - pow(me,2) -Ey*Eep)/(-p_y*p_ep);
      double cos_em = (pow(mpi,2)/2 - mpi*Eep - pow(me,2) -Eem*Ey)/(-p_em*p_y);

      double angle_ep = TMath::Pi() - TMath::ACos(cos_ep);
      double angle_em = TMath::Pi() - TMath::ACos(cos_em);
 
      //Testing to see if energy and momentum conservation are met
      double t_energy = Ey + Eep + Eem;
      double sin_em = p_em * sin(angle_em);
      double sin_ep = p_ep * sin(angle_ep);
      double cos_e = p_em * TMath::Cos(angle_em) + p_ep *TMath::Cos(angle_ep);

      //      cout<<"py "<<p_y<<" "<<p_ep<<" "<<p_em<<endl;
	  

      if(abs(t_energy - mpi) < 5)
	{
	  //	  cout<<"Energy conservation met! "<<endl;
	  //	  cout<<t_energy<<" "<<mpi<<endl;
	}
      else
	cout<<"Energy Failed! "<<endl;
      
      if(abs(sin_em - sin_ep) < 5)
	{
	  //	  cout<<"Y mom conservation met! "<<endl;
	  //	  cout<<sin_em<<" "<<sin_ep<<endl;
	}
      else
	{
	  cout<<"Y mom conservation failed! "<<endl;
	  cout<<"here is why "<<sin_em<<" "<<sin_ep<<" "<<sin_em-sin_ep<<endl;
	  cout<<"y-ep angle "<<angle_ep*TMath::RadToDeg()<<" y-em angle "<<angle_em*TMath::RadToDeg()<<endl;      
	}
      if(abs(cos_e - p_y) < 5)
	{
 //	cout<<"X mom conservation met! "<<endl;
	}
      else
	{
	  cout<<"X mom conservation failed! "<<endl;
	  cout<<"Here is why "<<cos_e<<" py "<<p_y<<" diff "<<cos_e - p_y<<endl;
	  cout<<"y-ep angle "<<angle_ep*TMath::RadToDeg()<<" y-em angle "<<angle_em*TMath::RadToDeg()<<endl;      
	  cout<<"y-ep angle "<<cos_ep<<" y-em angle "<<cos_em<<endl;      
	  cout<<"py "<<p_y<<" "<<p_ep<<" "<<p_em<<endl;
	}
      

    }

  cout<<"% of events NaN "<<100.*numNan/nEvents<<endl;

  dalitz_p->Draw("colz");


}
