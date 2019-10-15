//this simulates the expected background due to the pi zero decay
//deay is mainly through dalitz decay
//pi0 -> e-e+y y is gamma ray
//We assume the pi zero spectra is similar to the pi- and pi+ spectra
//pi zero spectra can be taken to be the sum of pi- and pi+ as an approximation
//betaCOM is around -.36;


//simulates the dalitz plot of a 3 body decay
//of the system M -> p1 + p2 + p3
//in our case pi0 -> y + e- + e+

auto mpi = 134.977; //mass of decaying particle M  (pi zero)
auto me = .51099; //mass of electron
auto my = 0; //mass of gamma ray
auto total = pow(mpi,2) + 2*pow(me,2) + pow(my,2);
auto b_com = .36;

double mom_conserve(double beta, double p_y, double p_ep, double p_em)
{
  return p_ep * TMath::Cos(beta) + sqrt(pow(p_em,2) - pow(p_ep * sin(beta),2)) - p_y;
}

void pizero_eBkg()
{
  TFile *file = TFile::Open("DataFile_Theta_merge.root");
  TH3D *pim_data_nec = (TH3D *)file->Get("pim_data_nec");
  TH3D *pip_data_nec = (TH3D *)file->Get("pip_data_nec");
  TH3D *pim_data = (TH3D *)file->Get("pim_data_cm");
  TH3D *pip_data = (TH3D *)file->Get("pip_data_cm");

  auto pim_spectra = (TH1D *)pim_data->ProjectionZ();
  auto pip_spectra = (TH1D *)pip_data->ProjectionZ();
  
  auto pi_zero = (TH1D *)pip_spectra->Clone();
  //  pi_zero->Add(pim_spectra);//pip_spectra now becomes pi zero estimate

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

  //  vector<double> bins = {-700,-600,-580,-560,-540,-520,-500,-480,-460,-440,-420,-400,-380,-360,-340,-320,-300,-280,-260,-240,-220,-200,-180,-160,-140,-120,-100,-95,-90,-85,-80,-78,-76,-74,-72,-70,-68,-66,-64,-62,-60,-58,-56,-54,-52,-50,-48,-46,-44,-42,-40,-38,-36,-34,-32,-30,0};

  //  TH1D *ep_lab = new TH1D("ep_lab","e+ mom in Lab ",bins.size()+1, bins.data());
  //  TH1D *em_lab = new TH1D("em_lab","e- mom in Lab ",bins.size()+1, bins.data());

  TH1D *ep_lab = new TH1D("ep_lab","e+ mom in Lab ",1000,0,1000);
  TH1D *em_lab = new TH1D("em_lab","e- mom in Lab ",1000,0,1000);
  TH2D *em_lab_angles = new TH2D("em_lab_angles","e- lab angles ",40,0,90,40,0,360);
  TH2D *ep_lab_angles = new TH2D("ep_lab_angles","e+ lab angles ",40,0,90,40,0,360);
  
  TH2D *em_com_angles = new TH2D("em_com_angles","e- com angles ",40,0,90,40,0,360);
  TH2D *ep_com_angles = new TH2D("ep_com_angles","e+ com angles ",40,0,90,40,0,360);

  int nEvents = 1e6;
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
      
      //      dalitz_p->Fill(s3,s1);

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

      //Several effects of the decay
      //Must boost along the gamma direction which we choose to be along pi_zero momentum
      //Also gamma and ep em may decay opposite to what picture shows half time forward half backward
      //Also the decay happens in a plane but the orientation of the plane is random
      //Can use Rotate(phi,TVector3) around arbitrary vector
      //Momentum spectra of pi_zero is determined by COM momentum spectra (we estimate from pip pim)
      //Beam COM system boosts to final lab frame
      
      //Coordinates in Rest frame of pi zero
      //      double cos_ep_b = (pow(mpi,2)/2 - mpi*Eem - pow(me,2) -Ey*Eep)/(-p_y*p_ep);// old bad def
      //      double cos_em_b = (pow(mpi,2)/2 - mpi*Eep - pow(me,2) -Eem*Ey)/(-p_em*p_y);// old bad def

      double cos_ep = (Ey*Eep + mpi*Eem - pow(mpi,2)/2)/(p_y*p_ep);
      double cos_em = (Ey*Eem + mpi*Eep - pow(mpi,2)/2)/(p_y*p_em);

      double angle_ep = TMath::Pi() - TMath::ACos(cos_ep);
      double angle_em = TMath::Pi() - TMath::ACos(cos_em);
 
      //Testing to see if energy and momentum conservation are met
      double t_energy = Ey + Eep + Eem;
      double sin_em = p_em * sin(angle_em);
      double sin_ep = p_ep * sin(angle_ep);
      double cos_e = p_em * TMath::Cos(angle_em) + p_ep *TMath::Cos(angle_ep);
      //

      //Sample isotropic distribution in COM frame of system
      double phi   = ran->Uniform(0,2*TMath::Pi());
      double theta = TMath::ACos(2*ran->Uniform() - 1);

      double p_pi = pi_zero->GetRandom();//momentum of pi zero in COM system
      double x_p = p_pi * cos(phi)*sin(theta);
      double y_p = p_pi * sin(phi)*sin(theta);
      double z_p = p_pi * cos(theta);
      double beta_pi = p_pi/sqrt(pow(p_pi,2) + pow(mpi,2));

      //      TVector3 pi_z_axis(1,0,0);
      TVector3 pi_z_axis(x_p,y_p,z_p);
      pi_z_axis = pi_z_axis.Unit();

      auto rotationAxis  = pi_z_axis.Cross(TVector3(0,0,1));// vector orthagonal to COM z axis & pizero
      auto rotationAngle = pi_z_axis.Angle(TVector3(0,0,1)); //angle between z_axis and pizero

      //      cout<<"Rotation angle "<<rotationAngle<<endl;
      //      rotationAxis.Print();

      //Define decay in the x-z plane
      //Angles above are angles w.r.t. the z-axis.
      /*
	Y pointing out
              x
              ^
              -
              -
              - - - - - -> z

       */

      TLorentzVector ep_vec;
      TLorentzVector em_vec;

      ep_vec.SetXYZM(p_ep*sin(angle_ep), 0, p_ep*cos(angle_ep), me);
      em_vec.SetXYZM(p_em*sin(angle_em), 0, p_em*cos(angle_em), me);

      //Half of the time the gamma ray may decay forward or backwards
      //There should be no preference to the direction of the emission forward and backward

      if(ran->Uniform() < .5)
	{
	  ep_vec.SetXYZM(-ep_vec.Px(), -ep_vec.Py(), -ep_vec.Pz(), me);
	  em_vec.SetXYZM(-em_vec.Px(), -em_vec.Py(), -em_vec.Pz(), me);
	}


      //      cout<<"before "<<endl;
      //      ep_vec.Print();

      //Boost first in z axis for conviencinece
      ep_vec.Boost(0,0,beta_pi);
      em_vec.Boost(0,0,beta_pi);

      //Rotate the plane at an arbitary angle
      //Symmetry around pi_zero axis
      ep_vec.Rotate(ran->Uniform(0,2*TMath::Pi()),TVector3(0,0,1));
      em_vec.Rotate(ran->Uniform(0,2*TMath::Pi()),TVector3(0,0,1));
		    
      //Rotate to the angle of the pi zero momentum
      ep_vec.Rotate(-rotationAngle,rotationAxis); //we define rotation axis as pi_zero x z-axis
      em_vec.Rotate(-rotationAngle,rotationAxis); //ROOT defines angle as counter-clockwise

      //      cout<<"check ep "<<Eep<<" now "<<ep_vec.E()<<endl;
      //      cout<<"check em "<<Eem<<" now "<<em_vec.E()<<endl;

      ep_vec.Boost(0,0,b_com);
      em_vec.Boost(0,0,b_com);
      
      //      cout<<"after "<<endl;
      //      ep_vec.Print();
      //      cout<<endl<<endl;
      //n      ep_lab->Fill(ran->Gaus(ep_vec.P(),ep_vec.P()*.05));
      //      em_lab->Fill(ran->Gaus(em_vec.P(),em_vec.P()*.05));

      TVector3 ep_ll = ep_vec.Vect();
      TVector3 em_ll = em_vec.Vect();      

      double phiL_ep = ep_ll.Phi()*TMath::RadToDeg();
      double phiL_em = em_ll.Phi()*TMath::RadToDeg();
      if(phiL_em < 0)
	phiL_em += 360;

      if(phiL_ep < 0)
	phiL_ep += 360;

      double thetaL_ep = ep_ll.Theta()*TMath::RadToDeg();
      double thetaL_em = em_ll.Theta()*TMath::RadToDeg();

      ep_lab_angles->Fill(thetaL_ep,phiL_ep);
      em_lab_angles->Fill(thetaL_em,phiL_em);
 
      //    if(thetaL_ep < 70 && ((phiL_ep > 150 && phiL_ep < 210) || (phiL_ep <30 || phiL_ep >330)))
	ep_lab->Fill(ep_vec.P());      
	//      if(thetaL_em < 70 && ((phiL_em > 150 && phiL_em < 210) || (phiL_em <30 || phiL_em >330)))
	em_lab->Fill(em_vec.P());      

    }

  cout<<"% of events NaN "<<100.*numNan/nEvents<<endl;

  //  dalitz_p->Draw("colz");
  ep_lab->SetLineColor(2);
  ep_lab->Draw();
  em_lab->Draw("same");  

  TCanvas *c2 = new TCanvas("c2","c2",1);
  ep_lab_angles->Draw("colz");
  
  TFile *out = new TFile("electronbkg.root","RECREATE");
  ep_lab->Write();
  em_lab->Write();
  out->Close();
  

}
