

void plotLitData_Scaled()
{
  gStyle->SetEndErrorSize(10);

  /*
  double au_au_energy[8] = {.27,.409,.600,.799,1.00,1.2,1.5};
  double au_au_ma[8]     = {.004195,.0157,.0430,.0795,.11848,.1631,.22834};
  
  double au_au_x[8]     = {0,0,0,0,0,0,0};
  double au_au_y[8]     = {.002,.002,.004,.007,.01,.015,.03};
  */

  double au_au_energy[7] = {.409,.600,.799,1.00,1.2,1.5};
  double au_au_ma[7]     = {.0157,.0430,.0795,.11848,.1631,.22834};
  
  double au_au_x[7]     = {0,0,0,0,0,0};
  double au_au_y[7]     = {.002,.004,.007,.01,.015,.03};

  //  double pim = 1.1738;
  //  double pip = .2188;

  //  double pim = .626; //as of 06/02/19
  //  double pip = .1235;  //as of 06/02/19

  //  double pim = .59; //as of 06/10/19
  //  double pip = .12;  //as of 06/10/19

  double pim = .6968; //as of 08/30/19
  double pip = .1486;  //as of 08/30/19

  //  double apart = 230;  // 3.45 fm b value MC estimated glauber model
  //  double apart = 244.7;  //0 fm b value MC estimated glauber model
  double apart = 245.48;  //2.42 fm b value MC estimated glauber model
  //  double t_pion = 1.5*(pim + pip)/apart;//we use geometric mean now

  double error_apart = 13;

  auto pimData132 = pim;
  auto pimData132Err = 0.00364318;
  auto pipData132 = pip;
  auto pipData132Err = 0.00170804;

  auto piTotalData132 = pimData132 + pipData132 + TMath::Sqrt(pimData132*pipData132); 
  auto piTotalData132Err = TMath::Sqrt(TMath::Power(pimData132Err, 2) + TMath::Power(pipData132Err, 2) + TMath::Power(TMath::Sqrt(pimData132*pipData132)/2.*(TMath::Power(pimData132Err/pimData132, 2) + TMath::Power(pipData132Err/pipData132, 2)), 2));

  cout<<piTotalData132<<endl;
  double t_pion = piTotalData132/apart;
  double error = t_pion * sqrt( pow(piTotalData132Err/piTotalData132,2) + pow( error_apart/apart,2));
  
 cout<<"error "<<error<<endl;
  double au_apart = 394 *.9;
  double tau     = .86;
  double scale_f = pow(256/au_apart,tau-1);

  cout<<"Scale "<<scale_f<<endl;
  //  for(int i = 0; i < 6; i++)
  //    au_au_ma[i] *= scale_f;
  
  TGraphErrors *tpc = new TGraphErrors(1);
  tpc->SetPoint(1,.27,t_pion/scale_f);
  tpc->SetPointError(1,0,error);
  tpc->SetMarkerColor(2);
  tpc->SetMarkerStyle(20);
  tpc->SetMarkerSize(3.);
  tpc->SetLineWidth(3);
  tpc->SetLineColor(1);

  cout<<t_pion/scale_f<<endl;
  
  TGraphErrors *litdata = new TGraphErrors(7,au_au_energy,au_au_ma,au_au_x,au_au_y);
  litdata->SetLineColor(1);
  
  TF1 *fit = new TF1("fit","TMath::Exp([0] + [1]/x + [2]/pow(x,2))",0,2);
  fit->SetParameters(-.654307,-1.9530607,.20315227);

  //  TF1 *fit_2 = new TF1("fit_2","TMath::Exp([0] + [1]/x + [2]/pow(x,2))",0,2);
  //  fit_2->SetParameters(-.5405,-2.1372,.265309);
  /*
  TF1 *fit_2 = new TF1("fit_2","[0] + [1]*(x-.126) + [2]*pow(x-.126,2) + [3]*pow(x-.126,3) + [4]*pow(x-.126,4)",0,2.);
  fit_2->FixParameter(0,0);
  fit_2->SetParameter(1,5.50109e-02);
  fit_2->SetParameter(2,-3.67649e-02);
  fit_2->SetParameter(3,1.85264e-01);
  fit_2->SetParameter(4,-9.30942e-02);
  */


  TF1 *fit_2 = new TF1("fit_2","[0] + [1]*(x-.126) + [2]*pow(x-.126,2)",.126,2.);
  fit_2->SetParameter(0,-1.855e-4);
  fit_2->SetParameter(1,3.475e-2);
  fit_2->SetParameter(2,1.07405e-1);

  TF1 *fit_paper = new TF1("fit_paper","[0]*(x-.126) + [1]*pow(x-.126,2) + [2]*pow(x-.126,3) + [3]*pow(x-.126,4)",.24,2.);
  fit_paper->SetParameter(0,-1.773e-2);
  fit_paper->SetParameter(1,3.102e-1);
  fit_paper->SetParameter(2,-1.952e-1);
  fit_paper->SetParameter(3,4.88e-2);

  TF1 *fit_paper_refit = new TF1("fit_paper_refit","[0]*(x-.126) + [1]*pow(x-.126,2) + [2]*pow(x-.126,3) + [3]*pow(x-.126,4)",.2,2.);
  fit_paper_refit->SetParameter(0,-8.71957e-03);
  fit_paper_refit->SetParameter(1,2.68111e-01);
  fit_paper_refit->SetParameter(2,-1.38854e-01);
  fit_paper_refit->SetParameter(3,2.63057e-02);

  //  litdata->Fit(fit_2);
    
  //linear
  //  TF1 *fit_2 = new TF1("fit_2","TMath::Exp([0] + [1]/x)",0,.7);
  //  fit_2->SetParameters(-1.4,-1.15);
  //  cout<<"Fit "<<  fit_2->Eval(.27)<<endl;

  TCanvas *c1 = new TCanvas("c1","c1",1000,800);
  gStyle->SetLineWidth(4);
  c1->SetFrameLineWidth(4);
  c1->SetLogy();
  c1->SetTopMargin(.05);
  c1->SetLeftMargin(.15);
  c1->SetRightMargin(.06);
  c1->SetBottomMargin(.15);
  
  litdata->SetMarkerColor(4);
  litdata->SetMarkerStyle(21);
  litdata->SetMarkerSize(2.);
  litdata->GetYaxis()->SetTitle("M(#pi)/A_{part}");
  litdata->GetYaxis()->CenterTitle();
  litdata->GetXaxis()->SetTitle("E (AGeV)");
  litdata->GetXaxis()->CenterTitle();
  litdata->SetTitle("");
  litdata->GetXaxis()->SetTitleSize(.06);
  litdata->GetYaxis()->SetTitleSize(.06);
  litdata->GetXaxis()->SetTitleOffset(1);
  litdata->GetYaxis()->SetTitleOffset(1.1);

  litdata->GetXaxis()->SetLabelSize(.06);
  litdata->GetYaxis()->SetLabelSize(.06);
  
  litdata->GetYaxis()->SetRangeUser(1e-3,3e-1);
  litdata->GetXaxis()->SetLimits(0,1.6);
  litdata->SetLineWidth(3);
  litdata->Draw("AP E ");


  fit_paper->SetLineColor(4);
  fit_paper->SetLineStyle(9);
  fit_paper->SetLineWidth(5);
  fit_paper->Draw("same");
  fit_paper_refit->SetLineColor(2);
  fit_paper_refit->SetLineStyle(1);
  fit_paper_refit->SetLineWidth(7);
  //  fit_paper_refit->Draw("same");
  //  fit_2->Draw("same");
  litdata->Draw("same P E ");
  tpc->Draw("same PO");
  auto leg = new TLegend(.38,.19,.89,.5,"","NDC");
  leg->AddEntry(litdata,"{}^{197}Au +{}^{197}Au  FOPI","p");
  leg->AddEntry(fit_paper,"FOPI fit", "l");
  leg->AddEntry(tpc,"#splitline{ {}^{132}Sn +{}^{124}Sn S#piRIT TPC}{  corrected to N/Z=1.49} ","p");
  //  leg->AddEntry(fit_paper_refit,"Global fit","l");
  leg->SetBorderSize(0);
  leg->Draw("same");

}
