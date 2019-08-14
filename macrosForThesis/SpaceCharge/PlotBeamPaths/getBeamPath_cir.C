

void getBeamPath()
{
  string line;
  ifstream file("_132Sn_BeamTrack.data");
  vector<double>xx,yy,zz;
  while(getline(file,line))
    {
      stringstream sstring(line);
      double x,y,z;
      sstring >> x >> y >> z;
      xx.push_back(x/10.);
      yy.push_back(y/10.);
      zz.push_back(z/10.); //convert to cm
      //      cout<<x<<" "<<y<<" "<<z<<endl;
    }

  TGraph *beam = new TGraph(xx.size(), zz.data(),xx.data());
  beam->GetYaxis()->SetRangeUser(-43.2,43.2);
  beam->Draw("ALO");

  TF1 *beampath = new TF1("beampath","[0] + [1]*x + [2]*pow(x,2)",0,130); 
  //  TF1 *beampath = new TF1("beampath","[0] + [1]*x + [2]*pow(x,2)",0,130); 
  beampath->SetParameters(-0.0685578,-0.046186, -0.000395632);
  //  beampath->SetParameters(-0.685578,-0.046186,-3.95632e-05);
  //  beam->Fit(beampath);
  beampath->Draw("same");

   auto chi2Function = [&](const Double_t *par) {
      //minimisation function computing the sum of squares of residuals
      // looping at the beampathaph points
      Int_t np = beam->GetN();
      Double_t f = 0;
      Double_t *x = beam->GetX();
      Double_t *y = beam->GetY();
      for (Int_t i=0;i<np;i++) {
         Double_t u = x[i] - par[0];
         Double_t v = y[i] - par[1];
         Double_t dr = par[2] - std::sqrt(u*u+v*v);
         f += dr*dr;
      }
      return f;
   };
   // wrap chi2 funciton in a function object for the fit
   // 3 is the number of fit parameters (size of array par)
   ROOT::Math::Functor fcn(chi2Function,3);
   ROOT::Fit::Fitter  fitter;
   double pStart[3] = {0,0,1};
   fitter.SetFCN(fcn, pStart);
   fitter.Config().ParSettings(0).SetName("x0");
   fitter.Config().ParSettings(1).SetName("y0");
   fitter.Config().ParSettings(2).SetName("R");
   // do the fit 
   bool ok = fitter.FitFCN();
   if (!ok) {
      Error("line3Dfit","Line3D Fit failed");
   }   
   const ROOT::Fit::FitResult & result = fitter.Result();
   result.Print(std::cout);
   //Draw the circle on top of the points
   TArc *arc = new TArc(result.Parameter(0),result.Parameter(1),result.Parameter(2));
   arc->SetLineColor(kRed);
   arc->SetLineWidth(4);
   arc->Draw();




}
