#include "/home/justin/mythesis/thesis_style.h"

using namespace style;

void plotTotalDoubleRatio()
{
  double x[2] = {-1,10};
  double y[2] = {2.42299,2.42299};
  double yerr[2] = {.046775,.046775};
  double xerr[2] = {0,0};
  //                          0          1         2       3           4      5       6
  vector<TString> label = {"AMD+JAM","#chi BUU","UrQMD","IQMD-BNU","SMASH","TuQMD","pBUU"};

  vector<double> stiff_dr = {2.010429448,2.3261826,1.831156419,2.014091353,1.846693731,2.139241691,2.053547455};//soft

 vector<double> soft_dr = {1.905637255,2.132652096,1.811179408,1.77183966,1.89199499,2.209500946,1.919319357};//stiff

 vector<int> order = {1,5,6,0,4,3,2};

 TGraph *stiff_g = new TGraph(label.size()+1);
 TGraph *soft_g = new TGraph(label.size()+1);

 TGraphErrors *data = new TGraphErrors(2,x,y,xerr,yerr);

 make(stiff_g);
 make(soft_g);

 for(int i = 0; i < label.size(); i++)
   {
     stiff_g->SetPoint(i,i+1,stiff_dr.at(order.at(i)) );
     soft_g->SetPoint(i,i+1,soft_dr.at(order.at(i)) );
   }

 stiff_g->SetMarkerStyle(20);
 soft_g->SetMarkerStyle(20);

 stiff_g->SetMarkerSize(4);
 soft_g->SetMarkerSize(4);

 stiff_g->SetMarkerColor(kRed - 4);
 soft_g->SetMarkerColor(kBlue - 4);

 data->SetFillColorAlpha(kCyan - 4, .35);
 data->SetLineStyle(10);
 data->SetLineWidth(4);
 
 TAxis *ax = stiff_g->GetXaxis();
 ax->SetNdivisions(10);
 
 ax->ChangeLabel(1,-1,0,1,-1,-1,""); //0 erase

 for(int i = 0; i < label.size(); i++)
   ax->ChangeLabel(i+2,315,-1,1,-1,-1,label.at(order.at(i)) );

 TLegend *leg = new TLegend(.6,.72,.9,.92);
 leg->AddEntry(data,"Data","FL");
 leg->AddEntry(stiff_g,"Stiff","P");
 leg->AddEntry(soft_g,"Soft","P");
 leg->SetBorderSize(0);
 leg->SetFillColorAlpha(0,0);
 
 stiff_g->GetYaxis()->SetRangeUser(1.65,2.9);
 stiff_g->GetYaxis()->SetTitle("R_{132+124}/R_{108+112}");
 stiff_g->GetYaxis()->SetTitleOffset(1.1);
 stiff_g->GetYaxis()->SetNdivisions(505);
 
 TCanvas *cvs = style::stdcvs();
 cvs->SetBottomMargin(.28);
 cvs->SetLeftMargin(.15);
 
 stiff_g->Draw("APO");
 soft_g->Draw("same PO");
 data->Draw("same E3L");
 leg->Draw();
 
}
