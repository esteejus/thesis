



void plotTransparency_vdiff()
{

  //Spring Commision .5T magnetic field


  vector<double> data_v_0 = {0,5,10,12,14,16};
  vector<double> data_trans_0 = {1,0.887756,0.49,0.342272698,0.203693,0.094557};

  vector<double> garf_v_0 = {0,5,10,12,14,16,18,20};
  vector<double> garf_trans_0 =  {1,0.853,0.47,0.3205,0.182,0.0955,0.039,0};


  vector<double> data_v_5 = {0,5,10,15,20,25,30,35,40,45};
  vector<double> data_trans_5 =  {1,0.955218,0.90509,0.796871,0.664226,0.536177,0.400595,0.243647,0.097689,0.06899};

  vector<double> garf_v_5 = {0,5,10,15,20,25,30,35,40,45,50,55};
  vector<double> garf_trans_5 = {0.998,0.96125,0.9165,0.815,0.69275,0.554,0.36675,0.17975,0.06525,0.0235,0.007,0.002};



  TGraphErrors *data_0 = new TGraphErrors(data_v_0.size(),data_v_0.data(),data_trans_0.data());
  TGraphErrors *garf_0 = new TGraphErrors(garf_v_0.size(),garf_v_0.data(),garf_trans_0.data());

  TGraphErrors *data_5 = new TGraphErrors(data_v_5.size(),data_v_5.data(),data_trans_5.data());
  TGraphErrors *garf_5 = new TGraphErrors(garf_v_5.size(),garf_v_5.data(),garf_trans_5.data());



  TCanvas *c1 = new TCanvas("c1","c1",1000,800);
  c1->SetTopMargin(.05);
  c1->SetBottomMargin(.12);
  c1->SetRightMargin(.05);
  c1->SetLeftMargin(.12);

  gPad->SetFrameLineWidth(10);
  gStyle->SetLineWidth(10);
    
  garf_5->GetXaxis()->SetTitle("#DeltaV (V)");
  garf_5->GetXaxis()->CenterTitle();
  garf_5->GetYaxis()->SetTitle("e^{-} Transparency (%)");
  garf_5->GetYaxis()->CenterTitle();

  garf_5->GetXaxis()->SetTitleSize(.05);
  garf_5->GetYaxis()->SetTitleSize(.05);
  
  garf_5->GetXaxis()->SetLabelSize(.05);
  garf_5->GetYaxis()->SetLabelSize(.05);
  garf_5->GetXaxis()->SetTitleOffset(1.1);
  garf_5->GetYaxis()->SetTitleOffset(1.1);

  data_0->SetMarkerColor(kBlue - 4);
  data_5->SetMarkerColor(kGreen - 4);
  
  garf_0->SetMarkerColor(kBlue - 4);
  garf_5->SetMarkerColor(kGreen - 4);
  
  data_0->SetLineColor(kBlue - 4);
  data_5->SetLineColor(kGreen - 4);
  garf_0->SetLineColor(kBlue - 4);
  garf_5->SetLineColor(kGreen - 4);

  data_0->SetLineWidth(6);
  data_5->SetLineWidth(6);

  garf_0->SetLineWidth(10);
  garf_5->SetLineWidth(10);

  garf_0->SetLineStyle(10);
  garf_5->SetLineStyle(10);


  data_0->SetMarkerStyle(24);
  garf_0->SetMarkerStyle(24);

  data_5->SetMarkerStyle(32);
  garf_5->SetMarkerStyle(32);

  data_0->SetMarkerSize(3.);
  garf_0->SetMarkerSize(2.);

  data_5->SetMarkerSize(3.);
  garf_5->SetMarkerSize(2.);

  //  garf_5->GetXaxis()->SetRangeUser(-200,-40);
  //  garf_5->GetYaxis()->SetRangeUser(.8,1.05);

  garf_5->SetTitle("");

  TLegend *leg = new TLegend(.4,.6,.75,.9);
  leg->AddEntry(garf_0,"Garfield sim. B = 0","l");
  leg->AddEntry(garf_5,"Garfield sim. B = 0.5","l");
  leg->SetBorderSize(0);
  leg->SetFillColorAlpha(kWhite,0);
 
  TLegend *leg2 = new TLegend(.7,.6,1.,.9);
  leg2->AddEntry(data_0,"Data B = 0","ep");
  leg2->AddEntry(data_5,"Data  B = 0.5 T","ep");
  leg2->SetBorderSize(0);
  leg2->SetFillColorAlpha(kWhite,0);
  
  garf_5->Draw("ACO");
  data_5->Draw("same PO");

  garf_0->Draw("same CO");
  data_0->Draw("same PO");
  leg->Draw();
  leg2->Draw();

  c1->SaveAs("transparencyDeltaV.png");

}
