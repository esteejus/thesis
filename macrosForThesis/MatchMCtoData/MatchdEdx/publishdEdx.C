#include "/home/justin/mythesis/thesis_style.h"

using namespace style;

void publishdEdx()
{
  vector<double> xvec_d = {450,430,410,390,370,350,330,310,290,270,250,230,210,190,170,150,130,110,90,70,50,30};
  vector<double> mean_d_vec = {21.0945,21.1656,21.0155,21.084,21.2802,21.5517,21.6691,21.7089,21.9353,22.5101,23.0205,23.7143,24.6391,25.9423,27.7671,30.4992,34.6803,41.7807,54.6574,77.6,123,220};
  vector<double> sigma_d_vec = {2.57073,2.5559,2.43828,2.14023,2.45448,2.63387,2.57544,2.49798,2.45187,2.77636,2.88779,2.99449,3.19529,3.41103,3.73242,4.22408,5.10251,6.73288,8.94627,15.6,18.4,14.99};

  vector<double> xvec_mc = {390,370,350,330,310,290,270,250,230,210,190,170,150,130,110,90,70,50,30};
    
  vector<double> mean_mc_vec = {20.8646,20.8,20.8584,20.9096,21.0242,21.1889,21.4688,21.8518,22.4023,23.2309,24.4311,26.1693,28.771,32.8933,39.7323,51.9551,76.7896,124.426,262};
    
  vector<double> sigma_mc_vec = {2.56569,2.49788,2.54408,2.54976,2.53057,2.54595,2.5621,2.57777,2.5949,2.62692,2.74507,2.88023,3.16469,3.66627,4.69026,7.0187,15.69,18.764,27.7};
  
  TGraph *sigma_d = new TGraph(xvec_d.size(),xvec_d.data(),sigma_d_vec.data());
  TGraph *mean_d = new TGraph(xvec_d.size(),xvec_d.data(),mean_d_vec.data());
 
  TGraph *sigma_mc = new TGraph(xvec_mc.size(),xvec_mc.data(),sigma_mc_vec.data());
  TGraph *mean_mc = new TGraph(xvec_mc.size(),xvec_mc.data(),mean_mc_vec.data());

  sigma_d->GetYaxis()->SetTitle("dE/dx arb. units");
  sigma_d->GetXaxis()->SetTitle("Momentum MeV/c");  
  mean_d->GetYaxis()->SetTitle("dE/dx arb. units");
  mean_d->GetXaxis()->SetTitle("Momentum MeV/c");  
  
  TCanvas *cvs = style::stdcvs();
  make(sigma_d);
  make(sigma_mc);
  make(mean_d);
  make(mean_mc);
  
  sigma_d->SetLineColor(2);
  sigma_mc->SetLineColor(4);
  mean_d->SetLineColor(2);
  mean_mc->SetLineColor(4);

  sigma_d->SetLineStyle(9);
  sigma_mc->SetLineStyle(9);

  mean_d->SetLineStyle(10);
  mean_mc->SetLineStyle(10);

  sigma_d->SetMarkerStyle(34);
  sigma_mc->SetMarkerStyle(34);
  sigma_d->SetMarkerSize(5);
  sigma_mc->SetMarkerSize(5);
  sigma_d->SetMarkerColor(2);
  sigma_mc->SetMarkerColor(4);

  mean_d->SetMarkerStyle(33);
  mean_mc->SetMarkerStyle(33);
  mean_d->SetMarkerSize(5);
  mean_mc->SetMarkerSize(5);
  mean_d->SetMarkerColor(2);
  mean_mc->SetMarkerColor(4);

  sigma_d->GetXaxis()->SetRangeUser(48,400);
  sigma_d->GetYaxis()->SetRangeUser(1,150);
  //  sigma_d->GetYaxis()->SetRangeUser(1,500);
 
  //  mean_d->GetXaxis()->SetRangeUser(48,400);
  //  mean_d->GetYaxis()->SetRangeUser(1,40);

  sigma_d->Draw("APE");
  sigma_mc->Draw("same P");

  mean_d->Draw("same PO");
  mean_mc->Draw("same PO");
    
  auto leg = new TLegend(.3,.65,.9,.9);
  leg->AddEntry(sigma_d,"Data #sigma","p");
  leg->AddEntry(mean_d,"Data <dE/dx>","p");
  leg->AddEntry(sigma_mc,"MC #sigma","p");
  leg->AddEntry(mean_mc,"MC <dE/dx>","p");
  leg->SetBorderSize(0);
  leg->Draw("same");
  //  cvs->SetLogx();
  //  cvs->SetLogy();
  cvs->SaveAs("dedxSigmacompare.png");
  cvs->SaveAs("dedxSigmacompare.jpg");

}

