

void pionRatioData()
{
  gStyle->SetEndErrorSize(10);
  
  double global_e[7] = {.27,.4,.6,.8,1,1.2,1.5};
  //  double global_r[7] = {4.22,2.96,2.3,2.04,1.92,1.78,1.65}; //b < 3fm
  double global_r[7] = {4.74,2.96,2.3,2.04,1.92,1.78,1.65};
  double global_x[7] = {0,0,0,0,0,0,0};
  double global_y[7] = {.1,.15,.11,.11,.1,.09,.08};
  
  double my_e[6] = {.4,.6,.8,1,1.2,1.5};
  double my_r[6] = {2.96,2.3,2.04,1.92,1.78,1.65};
  double my_x[6] = {0,0,0,0,0,0};
  double my_y[6] = {.15,.11,.11,.1,.09,.08};
  
  TGraphErrors *globaldata = new TGraphErrors(7,global_e,global_r,global_x,global_y);
  TGraphErrors *mydata = new TGraphErrors(6,my_e,my_r,my_x,my_y);

  //  double pip_m = .1235;
  //  double pim_m = .626;

  //  double pip_m = .12; //as of 06/10/19
  //  double pim_m = .59; //as of 06/10/19

  //  double pim_m = .6968; //as of 08/30/19
  //  double pip_m = .1486;  //as of 08/30/19

  //  double pim_m = .6968; //as of 08/30/19
  //  double pip_m = .1486;  //as of 08/30/19

  TGraphErrors *tpc = new TGraphErrors(1);
  //  tpc->SetPoint(1,.27,4.22); //previous b < 3fm
  tpc->SetPoint(1,.27,4.74); //b_o < .15
  tpc->SetPointError(1,0,.1);
  tpc->SetMarkerColor(kRed - 4);
  tpc->SetMarkerStyle(20);
  tpc->SetLineWidth(4);
  tpc->SetMarkerSize(3);

  TF1 *fit_global = new TF1("fit","[0] + [1]/(x - [2])",0,3);
  //  fit_global->SetParameters(1.318,5.0268e-1,9.56644e-2); //b < 3fm
  fit_global->SetParameters(1.386,4.109e-1,1.473e-1); //b_o < .15

  TF1 *fit_my = new TF1("fit","[0] + [1]/x",0,2);
  fit_my->SetParameters(1.1973,6.8879e-1);// b < 3fm
  //  fit_my->SetParameters(1.09,.929);
  fit_my->SetLineWidth(4);
  fit_my->SetLineStyle(6);

  //  globaldata->Fit(fit_global);
  
  TCanvas *c1 = new TCanvas("c1","c1",1000,800);
  gStyle->SetLineWidth(4);
  c1->SetFrameLineWidth(4);
  //  c1->SetLogy();
  c1->SetTopMargin(.05);
  c1->SetLeftMargin(.15);
  c1->SetRightMargin(.06);
  c1->SetBottomMargin(.15);
  
  globaldata->SetMarkerColor(4);
  globaldata->SetMarkerStyle(21);
  globaldata->SetMarkerSize(2.);
  globaldata->GetYaxis()->SetTitle("#pi^{-}/#pi^{+}");
  globaldata->GetYaxis()->CenterTitle();
  globaldata->GetXaxis()->SetTitle("E (AGeV)");
  globaldata->GetXaxis()->CenterTitle();
  globaldata->SetTitle("");
  globaldata->GetXaxis()->SetTitleSize(.06);
  globaldata->GetYaxis()->SetTitleSize(.06);
  globaldata->GetXaxis()->SetTitleOffset(1);
  globaldata->GetYaxis()->SetTitleOffset(1.1);

  globaldata->GetXaxis()->SetLabelSize(.06);
  globaldata->GetYaxis()->SetLabelSize(.06);
  
  globaldata->GetYaxis()->SetRangeUser(1.2,6);
  globaldata->GetXaxis()->SetLimits(0,1.6);
  globaldata->SetLineWidth(3);
  //  globaldata->Draw("AP E ");

  mydata->GetYaxis()->SetTitle("#pi^{-}/#pi^{+}");
  mydata->GetYaxis()->CenterTitle();
  mydata->GetXaxis()->SetTitle("E (AGeV)");
  mydata->GetXaxis()->CenterTitle();
  mydata->SetTitle("");
  mydata->GetXaxis()->SetTitleSize(.06);
  mydata->GetYaxis()->SetTitleSize(.06);
  mydata->GetXaxis()->SetTitleOffset(1);
  mydata->GetYaxis()->SetTitleOffset(1.1);

  mydata->GetXaxis()->SetLabelSize(.06);
  mydata->GetYaxis()->SetLabelSize(.06);
  

  mydata->GetYaxis()->SetRangeUser(1.2,5.2);
  mydata->GetXaxis()->SetLimits(.2,1.6);
  mydata->SetMarkerStyle(21);
  mydata->SetMarkerColor(kBlue - 4); 
  mydata->SetMarkerSize(3);   
  mydata->SetLineWidth(4);
  mydata->Draw("AP");

  fit_global->SetLineColor(kGray + 3);
  fit_global->SetLineStyle(10);
  fit_global->SetLineWidth(6);
  fit_global->Draw("same");
  fit_my->Draw("same");
  mydata->Draw("same P");
  tpc->Draw("same PO");
  
  auto leg = new TLegend(.42,.55,.89,.9,"","NDC");
  //  leg->AddEntry(globaldata,"N/Z = 1.56  W. Reisdorf et al.","ep");
  //  leg->AddEntry(fit_global,"Au + Au Reisdorf et al. fit", "l");
  leg->SetFillStyle(0);
  leg->AddEntry(tpc,"#splitline{{}^{132}Sn +{}^{124}Sn S#piRIT}{scaled to N/Z=1.493}","p");
  leg->AddEntry(mydata,"FOPI","p");
  leg->AddEntry(fit_global,"Global Fit to Data.","l");
  leg->AddEntry(fit_my,"Fit to FOPI Data.","l");
  leg->SetBorderSize(0);
  leg->Draw("same");

  c1->SaveAs("fopi_pionratio_comp.png");


}
