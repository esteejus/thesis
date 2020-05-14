#include "/home/justin/mythesis/thesis_style.h"

using namespace style;

void plotTransparency()
{
  gStyle->SetOptStat(0);
  
  //Fall 2015 0T magnetic field

  /*
  vector<double> xgarf = {20,10,0,-10,-20,-30,-41.07,-56.23,-70.11,-83.1,-94.48,-103.27,-114.8,-124.38,-132.76};
  vector<double> xdata = {-41.07,-56.23,-70.11,-83.1,-94.48,-103.27,-114.8,-124.38,-132.76,-142.54,-152.33};

  vector<double> ydata = {.6778,.8042,.8664,.9159,.9507,.9727,1.001,1.008,1.014,.99926,.99926};
  vector<double> ygarf = {0,.124,.236,.374,.4845,.583,.7,.8185,.877,.9405,.9668,.9855,.996,1,1};
  */


  vector<double> data_v = {-142.54, -132.76, -124.38, -114.8, -103.27, -94.48, -83.1, -70.11, -56.23, -41.07};
  vector<double> data_trans = {0.999267, 1.014835,1.008425,1.001099,0.972711,0.950733,0.915934,0.866484,0.804212, 0.677839};

  vector<double> garf_v =  {-132.76,-124.38,-114.8, -103.27, -94.48, -83.1, -70.11, -56.23, -41.07, -30, -20, -10, 0, 10, 20};
  vector<double> garf_trans =  {1, 1, 0.996, 0.9855, 0.968, 0.9405, 0.877, 0.8185, 0.7, 0.583, 0.4845, 0.374, 0.236, 0.124, 0};
  vector<double> garf_v_err =  {.0 ,.0 , .0 , .0 , .0, .0, .0, .0, .0, .0, .0, .0, .0, .0, .0};
  vector<double> garf_trans_err =  {.03 ,.03 , .03 , .03 , .03, .03, .03, .03, .03, .03, .03, .03, .03, .03, .03};

  TGraph *data_avg = new TGraph(data_v.size(),data_v.data(),data_trans.data());
  TGraphErrors *garf_avg = new TGraphErrors(garf_v.size(),garf_v.data(),garf_trans.data(),garf_v_err.data(),garf_trans_err.data());


  vector<double> data_5_v =   {-170.98, -164.98, -145.9, -136.54, -127.16, -119.14, -114.9, -110.06, -90.5, -79.6, -53.86, -39.34};
  vector<double> data_5_trans =   {1, 0.999794, 0.998232, 0.995282, 0.980169, 0.954406, 0.942936, 0.932959, 0.910684, 0.901025, 0.873159, 0.844473};
  vector<double> data_5_v_err = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
  //  vector<double> data_5_trans_err = {0.033, 0.034, 0.047, 0.025, 0.029, 0.0327, 0.0303, 0.031, 0.029, 0.037, 0.0302, 0.073, 0.0348};
  vector<double> data_5_trans_err = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};


  vector<double> garf_5_v =    {-180,-170,-160,-152.33,-142.55,-132.76,-124.38,-114.84,-103.27,-94.48,-100,-90,-80,-70,-60,-50,-40,-30,0,10,20};
    vector<double> garf_5_trans =    {0.9975,0.99525,0.99375,0.9945,0.9855,0.97975,0.96725,0.95275,0.93275,0.929,0.929768,0.9205,0.91325,0.90925,0.911,0.893,0.87425,0.825,0.67025,0.574,0};
    vector<double> garf_5_v_err =  { .0, .0, .0, .0, .0, .0, .0, .0, .0, .0, .0, .0, .0, .0, .0, .0, .0, .0, .0, .0, .0, .0};
    vector<double> garf_5_trans_err =  {.02, .02, .02, .02, .02, .02, .02, .02, .02, .02, .02, .02, .02, .02, .02, .02, .02, .02, .02, .02, .02, .02};

  TGraphErrors *data_5_avg = new TGraphErrors(data_5_v.size(),data_5_v.data(),data_5_trans.data(),data_5_v_err.data(),data_5_trans_err.data());
  TGraphErrors *garf_5_avg = new TGraphErrors(garf_5_v.size(),garf_5_v.data(),garf_5_trans.data(),garf_5_v_err.data(),garf_5_trans_err.data());


  
  TCanvas *c1 = new TCanvas("c1","c1",1000,800);
  c1->SetTopMargin(.05);
  c1->SetBottomMargin(.12);
  c1->SetRightMargin(.05);
  c1->SetLeftMargin(.12);

  gPad->SetFrameLineWidth(10);
  gStyle->SetLineWidth(10);
  garf_avg->SetLineWidth(4);
  data_avg->SetLineWidth(4);

    
  garf_avg->GetXaxis()->SetTitle("V_{avg} (V)");
  garf_avg->GetXaxis()->CenterTitle();
  garf_avg->GetYaxis()->SetTitle("e^{-} Transparency (%)");
  garf_avg->GetYaxis()->CenterTitle();

  garf_avg->GetXaxis()->SetTitleSize(.05);
  garf_avg->GetYaxis()->SetTitleSize(.05);
  
  garf_avg->GetXaxis()->SetLabelSize(.05);
  garf_avg->GetYaxis()->SetLabelSize(.05);
  garf_avg->GetXaxis()->SetTitleOffset(1.1);
  garf_avg->GetYaxis()->SetTitleOffset(1.1);

  garf_avg->SetTitle("");

  data_avg->SetMarkerColor(kGreen + 1);
  data_avg->SetLineColor(kGreen - 4);

  data_avg->SetMarkerStyle(23);
  garf_avg->SetMarkerStyle(23);

  data_avg->SetMarkerSize(1.5);
  garf_avg->SetLineWidth(20);
  garf_avg->SetLineColor(kGreen-4);
  garf_avg->SetLineStyle(10);
  garf_avg->SetFillColorAlpha(kGreen-4,.5);
  garf_avg->SetMarkerSize(1.5);


  data_avg->SetLineWidth(10);
  data_5_avg->SetLineWidth(10);


  data_5_avg->SetMarkerColor(kBlue + 1);
  data_5_avg->SetLineColor(kBlue - 4);

  data_5_avg->SetMarkerStyle(20);
  garf_5_avg->SetMarkerStyle(20);

  data_5_avg->SetMarkerSize(1.5);
  garf_5_avg->SetLineWidth(20);
  garf_5_avg->SetLineStyle(7);
  garf_5_avg->SetLineColor(kBlue-4);
  garf_5_avg->SetFillColorAlpha(kBlue-4,.5);
  garf_5_avg->SetMarkerSize(1.5);






  TLegend *leg = new TLegend(.12,.2,.55,.7);
  leg->AddEntry(garf_avg,"Garfield sim. B = 0T","lf");
  leg->AddEntry(garf_5_avg,"Garfield sim. B = 0.5T","lf");
  leg->SetBorderSize(0);
  leg->SetFillColorAlpha(kWhite,0);

  TLegend *leg2 = new TLegend(.45,.2,.8,.7);
  leg2->AddEntry(data_avg,"Data B = 0T","ep");
  leg2->AddEntry(data_5_avg,"Data B = 0.5T","ep");
  leg2->SetBorderSize(0);
  leg2->SetFillColorAlpha(kWhite,0);

  TH1D *dummy = new TH1D("dummy","",1,-200,40);

    
  dummy->GetXaxis()->SetTitle("V_{avg} (V)");
  dummy->GetXaxis()->CenterTitle();
  dummy->GetYaxis()->SetTitle("e^{-} Transparency (%)");
  dummy->GetYaxis()->CenterTitle();

  dummy->GetXaxis()->SetTitleSize(.05);
  dummy->GetYaxis()->SetTitleSize(.05);
  
  dummy->GetXaxis()->SetLabelSize(.05);
  dummy->GetYaxis()->SetLabelSize(.05);
  dummy->GetXaxis()->SetTitleOffset(1.1);
  dummy->GetYaxis()->SetTitleOffset(1.1);

  dummy->SetTitle("");




  
  dummy->Draw();
  data_5_avg->GetXaxis()->SetRangeUser(-190,10);
  garf_avg->Draw("same E3L");
  garf_5_avg->Draw("same E3L");
  data_5_avg->Draw("same PO");
  data_avg->Draw("same PO");

  leg->Draw();
  leg2->Draw();
  
  c1->SaveAs("averageTransparency.png");

}
