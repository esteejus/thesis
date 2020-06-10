

void plotLitData()
{
  double au_au_energy[6] = {.409,.600,.799,1.00,1.2,1.5};
  double au_au_ma[6]     = {.0157,.0430,.0795,.11848,.1631,.22834};
  
  double au_au_x[6]     = {0,0,0,0,0,0};
  double au_au_y[6]     = {.002,.004,.007,.01,.015,.03};

  double pim = 1.1738;
  double pip = .2188;

  //  double apart = 230;  // 3.45 fm b value MC estimated glauber model
  double apart = 256;  //0 fm b value MC estimated glauber model
  //  double apart = 245.48;  //2.42 fm b value MC estimated glauber model
  double t_pion = 1.5*(pim + pip)/apart;
  cout<<t_pion<<endl;
  double error_pion = .1;
  double error_apart = 13;

  double error = 1.5 * (pim + pip)/apart * sqrt( pow(error_pion/(pim+pip),2) + pow( error_apart/apart,2));
  
  cout<<"Error is "<<error<<endl;
  
  TGraphErrors *tpc = new TGraphErrors(1);
  tpc->SetPoint(1,.27,t_pion);
  tpc->SetPointError(1,0,error);
  tpc->SetMarkerColor(3);
  tpc->SetMarkerStyle(20);
  tpc->SetMarkerSize(2.);
  tpc->SetLineWidth(2);
  tpc->SetLineColor(1);
  
  TGraphErrors *litdata = new TGraphErrors(6,au_au_energy,au_au_ma,au_au_x,au_au_y);
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

  TF1 *fit_paper = new TF1("fit_paper","[0]*(x-.126) + [1]*pow(x-.126,2) + [2]*pow(x-.126,3) + [3]*pow(x-.126,4)",.4,2.);
  fit_paper->SetParameter(0,-1.773e-2);
  fit_paper->SetParameter(1,3.102e-1);
  fit_paper->SetParameter(2,-1.952e-1);
  fit_paper->SetParameter(3,4.88e-2);

  TF1 *fit_paper_refit = new TF1("fit_paper_refit","[0]*(x-.126) + [1]*pow(x-.126,2) + [2]*pow(x-.126,3) + [3]*pow(x-.126,4)",.126,2.);
  fit_paper_refit->SetParameter(0,4.142e-2);
  fit_paper_refit->SetParameter(1,2.8175e-2);
  fit_paper_refit->SetParameter(2,1.8e-1);
  fit_paper_refit->SetParameter(3,-9.8835e-2);

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

  tpc->Draw("same PO");
  fit_paper->SetLineColor(4);
  fit_paper->SetLineStyle(2);
  fit_paper->SetLineWidth(3);
  fit_paper->Draw("same");
  fit_paper_refit->SetLineColor(2);
  fit_paper_refit->SetLineStyle(1);
  fit_paper_refit->SetLineWidth(3);
  fit_paper_refit->Draw("same");
  //  fit_2->Draw("same");

  auto leg = new TLegend(.38,.19,.89,.5,"","NDC");
  leg->AddEntry(litdata,"Au + Au  W. Reisdorf et al.","ep");
  leg->AddEntry(fit_paper,"Au + Au Reisdorf et al. fit", "l");
  leg->AddEntry(tpc,"{}^{132} Sn +{}^{108} Sn S#piRIT TPC","ep");
  leg->AddEntry(fit_paper_refit,"Global fit","l");
  leg->SetBorderSize(0);
  leg->Draw("same");

}
