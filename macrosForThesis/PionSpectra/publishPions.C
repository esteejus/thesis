#include "/home/justin/mythesis/thesis_style.h"

using namespace style;

void publishPions()
{

  TFile *f = TFile::Open("publishPions.root");
  TH1D * pim_sn108 = (TH1D *)f->Get("pim_sn108");
  TH1D * pip_sn108 = (TH1D *)f->Get("pip_sn108");

  TH1D * pim_sn132 = (TH1D *)f->Get("pim_sn132");
  TH1D * pip_sn132 = (TH1D *)f->Get("pip_sn132");

  TH1D *singleRatio_sn132 = (TH1D *)f->Get("singleRatio_sn132");
  TH1D *singleRatio_sn108 = (TH1D *)f->Get("singleRatio_sn108");

  TH1D *doubleRatio = (TH1D *)f->Get("doubleRatio");

  make(pim_sn108);
  make(pim_sn132);
  make(pip_sn108);
  make(pip_sn132);
  make(singleRatio_sn108);
  make(singleRatio_sn132);
  make(doubleRatio);

  int pim_marker = 20;
  int pip_marker = 20;
  int singlesn132 = 20;
  int singlesn108 = 20;
  int doubler = 20; 

  gStyle->SetEndErrorSize(0);

  //style
  int lineS132pim = 1; 
  int lineS132pip = 1;

  int lineS108pim = 7;
  int lineS108pip = 7;



  int markS132pim = 25;
  int markS108pim = 25;  

  int markS132pip = 21;
  int markS108pip = 21;  

  //color
  int lineC132pim = 4; 
  int lineC108pim = 4;

  int lineC132pip = 2;
  int lineC108pip = 2;

  int markC132pim = 4;
  int markC108pim = 4;  

  int markC132pip = 2;
  int markC108pip = 2;  

  //size
  int markSz132pim = 2; //marker size
  int markSz108pim = 2; //marker size 

  int markSz132pip = 2; //marker size
  int markSz108pip = 2; //marker size 

  //  TLegend *leg = new TLegend(.2,.2,.55,.5);
  TLegend *leg = new TLegend(.55,.75,.75,.9);
  leg->SetHeader("{}^{132}Sn +{}^{124}Sn");
  leg->AddEntry(pim_sn132,"#pi^{-}","lpe");
  leg->AddEntry(pip_sn132,"#pi^{+} (x10^{-1} )","lpe");

  TLegend *leg_2 = new TLegend(.75,.75,.95,.9);
  leg_2->SetHeader("{}^{108}Sn +{}^{112}Sn");
  leg_2->AddEntry(pim_sn108,"#pi^{-}","lpe");
  leg_2->AddEntry(pip_sn108,"#pi^{+} (x10^{-1} )","lpe");

  leg_2->SetFillStyle(0);

  TCanvas *cvs = style::stdcvs();
  cvs->SetLogy();

  pim_sn132->GetYaxis()->SetTitle("dM/dEd#Omega");
  pim_sn132->GetYaxis()->CenterTitle();
  pim_sn132->GetXaxis()->SetTitle("K.E. COM (MeV)");
  pim_sn132->GetXaxis()->CenterTitle();
  
  pim_sn132->GetYaxis()->SetRangeUser(1e-6,2e-2);
  pim_sn132->SetLineWidth(5);
  pim_sn132->SetLineStyle(lineS132pim);
  pim_sn132->SetLineColor(lineC132pim);
  pim_sn132->SetMarkerStyle(markS132pim);
  pim_sn132->SetMarkerSize(markSz132pim);
  pim_sn132->SetMarkerColor(markC132pim);
  pim_sn132->Draw("E1");

  pim_sn108->SetLineWidth(5);
  pim_sn108->SetLineStyle(lineS108pim);
  pim_sn108->SetLineColor(lineC108pim);
  pim_sn108->SetMarkerStyle(markS108pim);
  pim_sn108->SetMarkerSize(markSz108pim);
  pim_sn108->SetMarkerColor(markC108pim);
  pim_sn108->Draw("same E1");

  leg->SetBorderSize(0);
  leg->Draw("same");
  
  //  TCanvas *cvs_2 = style::stdcvs("cvs_2");
  //  cvs_2->SetLogy();


  pip_sn132->GetYaxis()->SetTitle("dM/dEd#Omega");
  pip_sn132->GetYaxis()->CenterTitle();
  pip_sn132->GetXaxis()->SetTitle("K.E. COM (MeV)");
  pip_sn132->GetXaxis()->CenterTitle();

  pip_sn132->Scale(1e-1);
  pip_sn108->Scale(1e-1);

  //  pip_sn132->Scale(1./5);
  //  pip_sn108->Scale(1./5);

  //  pip_sn132->GetYaxis()->SetRangeUser(1e-5,3e-3);
  pip_sn132->SetLineWidth(5);
  pip_sn132->SetLineStyle(lineS132pip);
  pip_sn132->SetLineColor(lineC132pip);
  pip_sn132->SetMarkerStyle(markS132pip);
  pip_sn132->SetMarkerSize(markSz132pip);
  pip_sn132->SetMarkerColor(markC132pip);
  pip_sn132->Draw("same E1");

  pip_sn108->SetLineWidth(5);
  pip_sn108->SetLineStyle(lineS108pip);
  pip_sn108->SetLineColor(lineC108pip);
  pip_sn108->SetMarkerStyle(markS108pip);
  pip_sn108->SetMarkerSize(markSz108pip);
  pip_sn108->SetMarkerColor(markC108pip);
  pip_sn108->Draw("same E1");

  leg_2->SetBorderSize(0);
  leg_2->Draw("same");

}
