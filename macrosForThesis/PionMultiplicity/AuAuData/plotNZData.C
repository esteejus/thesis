#include "/home/justin/mythesis/thesis_style.h"

using namespace style;


void CanvasPartition(TCanvas *C,const Int_t Nx,const Int_t Ny,
                     Float_t lMargin, Float_t rMargin,
                     Float_t bMargin, Float_t tMargin)
{
  if (!C) return;

  // Setup Pad layout:
  Float_t vSpacing = 0.0;
  Float_t vStep  = (1.- bMargin - tMargin - (Ny-1) * vSpacing) / Ny;

  Float_t hSpacing = 0.0;
  Float_t hStep  = (1.- lMargin - rMargin - (Nx-1) * hSpacing) / Nx;

  Float_t vposd,vposu,vmard,vmaru,vfactor;
  Float_t hposl,hposr,hmarl,hmarr,hfactor;

  for (Int_t i=0;i<Nx;i++) {

    if (i==0) {
      hposl = 0.0;
      hposr = lMargin + hStep;
      hfactor = hposr-hposl;
      hmarl = lMargin / hfactor;
      hmarr = 0.0;
    } else if (i == Nx-1) {
      hposl = hposr + hSpacing;
      hposr = hposl + hStep + rMargin;
      hfactor = hposr-hposl;
      hmarl = 0.0;
      hmarr = rMargin / (hposr-hposl);
    } else {
      hposl = hposr + hSpacing;
      hposr = hposl + hStep;
      hfactor = hposr-hposl;
      hmarl = 0.0;
      hmarr = 0.0;
    }

    for (Int_t j=0;j<Ny;j++) {

      if (j==0) {
	vposd = 0.0;
	vposu = bMargin + vStep;
	vfactor = vposu-vposd;
	vmard = bMargin / vfactor;
	vmaru = 0.0;
      } else if (j == Ny-1) {
	vposd = vposu + vSpacing;
	vposu = vposd + vStep + tMargin;
	vfactor = vposu-vposd;
	vmard = 0.0;
	vmaru = tMargin / (vposu-vposd);
      } else {
	vposd = vposu + vSpacing;
	vposu = vposd + vStep;
	vfactor = vposu-vposd;
	vmard = 0.0;
	vmaru = 0.0;
      }

      C->cd(0);

      char name[16];
      sprintf(name,"pad_%i_%i",i,j);
      TPad *pad = (TPad*) gROOT->FindObject(name);
      if (pad) delete pad;
      pad = new TPad(name,"",hposl,vposd,hposr,vposu);
      pad->SetLeftMargin(hmarl);
      pad->SetRightMargin(hmarr);
      pad->SetBottomMargin(vmard);
      pad->SetTopMargin(vmaru);

      pad->SetFrameBorderMode(0);
      pad->SetBorderMode(0);
      pad->SetBorderSize(0);

      pad->Draw();
    }
  }

}


void plotNZData()
{
  gStyle->SetOptStat(0);
  
  double sp_nz[4] = {1.2,1.36,1.36,1.56};
  double sp_pion[4] = {2,3.09,3.11,4.84};
  double sp_x[4]     = {0,0,0,0};
  double sp_y[4]     = {.0495,.0708,.24,.12};

  
  double gev_4_nz[4]     = {1,1.179,1.398,1.493};
  double gev_4_pion[4]     = {1.02,1.536,2.474,3.00};
  
  double gev_4_x[4]     = {0,0,0,0};
  double gev_4_y[4]     = {.072,.109,.171,.209};

  
  double gev_8_nz[8]     = {1.053,1.0564,1.1089,1.1409,1.327,1.3285,1.399,1.495};
  double gev_8_pion[8]   = {1.1189,1.144,1.1659,1.3977,1.4759,1.8643,1.958,2.04};
  
  double gev_8_x[8]     = {0,0,0,0,0,0,0,0};
  double gev_8_y[8]     = {.22,.22,.23,.28,.298,.3696,.388,.1848};

  double gev_1_nz[4]     = {1.006,1.186,1.408,1.502};
  double gev_1_pion[4]   = {1.00,1.266,1.527,1.652};
  
  double gev_1_x[4]     = {0,0,0,0};
  double gev_1_y[4]     = {.069,0.089,.107,.1138};


  double error = .01;
  TGraphErrors *paper_4 = new TGraphErrors(1);
  paper_4->SetPoint(1,1.56,3.08);
  paper_4->SetPointError(1,0,error);
  paper_4->SetMarkerColor(1);
  paper_4->SetMarkerStyle(47);
  paper_4->SetMarkerSize(2.);
  paper_4->SetLineWidth(2);
  paper_4->SetLineColor(1);

  TGraphErrors *paper_8 = new TGraphErrors(1);
  paper_8->SetPoint(1,1.56,2.1255);
  paper_8->SetPointError(1,0,error);
  paper_8->SetMarkerColor(1);
  paper_8->SetMarkerStyle(47);
  paper_8->SetMarkerSize(2.);
  paper_8->SetLineWidth(2);
  paper_8->SetLineColor(1);

  TGraphErrors *paper_1 = new TGraphErrors(1);
  paper_1->SetPoint(1,1.56,1.721);
  paper_1->SetPointError(1,0,error);
  paper_1->SetMarkerColor(1);
  paper_1->SetMarkerStyle(47);
  paper_1->SetMarkerSize(2.);
  paper_1->SetLineWidth(2);
  paper_1->SetLineColor(1);


  TGraphErrors *my_4 = new TGraphErrors(1);
  my_4->SetPoint(1,1.56,3.39);
  my_4->SetPointError(1,0,error);
  my_4->SetMarkerColor(3);
  my_4->SetMarkerStyle(33);
  my_4->SetMarkerSize(2.);
  my_4->SetLineWidth(2);
  my_4->SetLineColor(1);

  TGraphErrors *my_8 = new TGraphErrors(1);
  my_8->SetPoint(1,1.56,2.235);
  my_8->SetPointError(1,0,error);
  my_8->SetMarkerColor(3);
  my_8->SetMarkerStyle(33);
  my_8->SetMarkerSize(2.);
  my_8->SetLineWidth(2);
  my_8->SetLineColor(1);

  TGraphErrors *my_1 = new TGraphErrors(1);
  my_1->SetPoint(1,1.56,1.748);
  my_1->SetPointError(1,0,error);
  my_1->SetMarkerColor(3);
  my_1->SetMarkerStyle(33);
  my_1->SetMarkerSize(2.);
  my_1->SetLineWidth(2);
  my_1->SetLineColor(1);


  
  TGraphErrors *sp = new TGraphErrors(4,sp_nz,sp_pion,sp_x,sp_y);
  TGraphErrors *gev_4 = new TGraphErrors(4,gev_4_nz,gev_4_pion,gev_4_x,gev_4_y);
  TGraphErrors *gev_8 = new TGraphErrors(8,gev_8_nz,gev_8_pion,gev_8_x,gev_8_y);
  TGraphErrors *gev_1 = new TGraphErrors(4,gev_1_nz,gev_1_pion,gev_1_x,gev_1_y);

  TF1 *fit_sp = new TF1("fit_sp","[0] + [1]*(x) + [2]*pow(x,2)",.9,2);
  fit_sp->SetParameter(0,2.514);
  fit_sp->SetParameter(1,-6.827);
  fit_sp->SetParameter(2,5.3319);

  
  TF1 *fit_4 = new TF1("fit_4","[0] + [1]*(x) + [2]*pow(x,2)",.9,2);
  fit_4->SetParameter(0,2.38);
  fit_4->SetParameter(1,-4.9576);
  fit_4->SetParameter(2,3.5954);

  TF1 *fit_4_lin = new TF1("fit_4_lin","[0] + [1]*(x)",.9,2);
  fit_4_lin->SetParameter(0,-2.6211);
  fit_4_lin->SetParameter(1,3.62335);

  TF1 *fit_8 = new TF1("fit_8","[0] + [1]*(x) + [2]*pow(x,2)",.9,2);
  fit_8->SetParameter(0,2.397);
  fit_8->SetParameter(1,-3.839);
  fit_8->SetParameter(2,2.4969);

  TF1 *fit_8_lin = new TF1("fit_8_lin","[0] + [1]*(x)",.9,2);
  fit_8_lin->SetParameter(0,-1.197);
  fit_8_lin->SetParameter(1,2.2);

  TF1 *fit_1 = new TF1("fit_1","[0] + [1]*(x)",.9,2);
  fit_1->SetParameter(0,-.351);
  fit_1->SetParameter(1,1.3459);


  //  cout<<"gev .4 "<<fit_4_lin->Eval(1.56)<<" "<<fit_4->Eval(1.56)<<endl;
  //  cout<<"gev .8 "<<fit_8_lin->Eval(1.56)<<" "<<fit_8->Eval(1.56)<<endl;
  //  cout<<"gev 1. "<<fit_1->Eval(1.56)<<" "<<fit_1->Eval(1.56)<<endl;

  //  sp->Fit(fit_sp);
//  gev_4->Fit(fit_4_lin);
  //  gev_8->Fit(fit_8_lin);
  //  gev_1->Fit(fit_1);
    
  //linear
  //  TF1 *fit_2 = new TF1("fit_2","TMath::Exp([0] + [1]/x)",0,.7);
  //  fit_2->SetParameters(-1.4,-1.15);
  //  cout<<"Fit "<<  fit_2->Eval(.27)<<endl;

  TLatex label_4;


 TCanvas *C = (TCanvas*) gROOT->FindObject("C");
  if (C) delete C;
  C = new TCanvas("C","canvas",1500,600);
  C->SetFillStyle(4000);

  // Number of PADS
  const Int_t Nx = 4;
  const Int_t Ny = 1;

  // Margins
  Float_t lMargin = 0.12;
  Float_t rMargin = 0.05;
  Float_t bMargin = 0.1;
  Float_t tMargin = 0.05;

  // Canvas setup
  CanvasPartition(C,Nx,Ny,lMargin,rMargin,bMargin,tMargin);

 TPad *pad[Nx][Ny];

 for (Int_t i = 0; i < Nx; i++)
   {
     for (Int_t j = 0; j < Ny; j++)
       {
	 C->cd(0);
	 // Get the pads previously created.
	 char pname[16];
	 sprintf(pname,"pad_%i_%i",i,j);
	 pad[i][j] = (TPad*) gROOT->FindObject(pname);
	 
	 pad[i][j]->Draw();
	 pad[i][j]->SetFillStyle(4000);
	 pad[i][j]->SetFrameFillStyle(4000);
	 
	 // Size factors
	 Float_t xFactor = pad[0][0]->GetAbsWNDC()/pad[i][j]->GetAbsWNDC();
	 Float_t yFactor = pad[0][0]->GetAbsHNDC()/pad[i][j]->GetAbsHNDC();
       }
   }
  
 
      //  TCanvas *c1 = new TCanvas("c1","c1",1200,400);
      //  c1->Divide(4,1,0,0);
  gStyle->SetLineWidth(4);
  /*
  c1->cd(1)->SetFrameLineWidth(3);
  c1->cd(2)->SetFrameLineWidth(3);
  c1->cd(3)->SetFrameLineWidth(3);
  c1->cd(4)->SetFrameLineWidth(3);
  c1->SetTopMargin(.01);
  c1->cd(1)->SetTopMargin(.01);
  c1->cd(2)->SetTopMargin(.01);
  c1->cd(3)->SetTopMargin(.01);
  c1->cd(4)->SetTopMargin(.01);
  c1->cd(1)->SetBottomMargin(.2);
  c1->cd(2)->SetBottomMargin(.2);
  c1->cd(3)->SetBottomMargin(.2);
  c1->cd(4)->SetBottomMargin(.2);

  c1->SetLeftMargin(.3);
  c1->SetRightMargin(.06);
  c1->SetBottomMargin(.2);
  */

  //  pad[0][0]->cd();

  double yhigh = 5.1;
  double ylow = .9;

  double xlow = .95;
  double xhigh = 1.59;

  TH1D *xaxis = new TH1D("xaxis","",1,xlow,xhigh);


  sp->SetTitle("");
  sp->GetYaxis()->SetRangeUser(ylow,yhigh);
  //sp->GetXaxis()->SetLimits(.95,1.59);
  sp->GetYaxis()->SetTitle("#pi^{-}/#pi^{+}");
  sp->GetYaxis()->CenterTitle();
  sp->GetYaxis()->SetTitleSize(.08);
  sp->SetMarkerColor(4);
  sp->SetMarkerStyle(20);
  sp->SetMarkerSize(2);


  gev_4->SetTitle("");
  gev_4->GetYaxis()->SetRangeUser(ylow,yhigh);
  //  gev_4->GetXaxis()->SetLimits(.95,1.59);
  gev_4->GetYaxis()->SetTitle("#pi^{-}/#pi^{+}");
  gev_4->GetYaxis()->CenterTitle();
  gev_4->GetYaxis()->SetTitleSize(.08);
  gev_4->SetMarkerColor(4);
  gev_4->SetMarkerStyle(20);
  gev_4->SetMarkerSize(2);
      
  gev_8->SetTitle("");
  gev_8->GetYaxis()->SetRangeUser(ylow,yhigh);
  //  gev_8->GetXaxis()->SetLimits(.95,1.59);
  gev_8->SetMarkerColor(4);
  gev_8->SetMarkerStyle(20);
  gev_8->SetMarkerSize(2);

  gev_1->SetTitle("");
  gev_1->GetYaxis()->SetRangeUser(ylow,yhigh);
  //  gev_1->GetXaxis()->SetLimits(.95,1.59);
  gev_1->SetMarkerColor(4);
  gev_1->SetMarkerStyle(20);
  gev_1->SetMarkerSize(2);

  fit_sp->SetLineColor(2);

  
  auto leg = new TLegend(.1,.5,.89,.9,"","NDC");

  //  leg->AddEntry(gev_4,"Measured data Reisdorf et al.","ep");
  //  leg->AddEntry(fit_4_lin,"Reisdorf et al. linear fit","l");
  //  leg->AddEntry(gev_4,"Measured data Reisdorf et al.","ep");
  leg->SetBorderSize(0);


  pad[0][0]->cd();
  fit_sp->GetXaxis()->SetLabelSize(.05);
  fit_sp->GetYaxis()->SetLabelSize(.05);
  fit_sp->GetYaxis()->SetLabelOffset(.02);
  fit_sp->SetTitle(".4 A GeV");
  fit_sp->SetTitle("");
  fit_sp->GetXaxis()->SetRangeUser(xlow,xhigh);
  fit_sp->GetYaxis()->SetRangeUser(ylow,yhigh);
  fit_sp->Draw("");
  sp->Draw("same PO");
  //  fit_sp->Draw("same");


  pad[1][0]->cd();
  fit_4->GetXaxis()->SetLabelSize(.08);
  fit_4->GetYaxis()->SetLabelSize(.08);
  fit_4->GetYaxis()->SetLabelOffset(.02);
  fit_4->SetTitle(".4 A GeV");
  //  gev_4->SetTitleSize(.08);
  fit_4->GetXaxis()->SetRangeUser(xlow,xhigh);
  fit_4->GetYaxis()->SetRangeUser(ylow,yhigh);
  fit_4->Draw();
  gev_4->Draw("same PO");
  
  pad[2][0]->cd();
 fit_8_lin->GetXaxis()->SetLabelSize(.08);
  //  gev_8->GetXaxis()->SetTitle("N/Z");
  //  gev_8->GetXaxis()->CenterTitle();
  fit_8_lin->GetXaxis()->SetTitleSize(.08);  
  fit_8_lin->SetTitle(".8 A GeV");
  fit_8_lin->GetXaxis()->SetRangeUser(xlow,xhigh);
  fit_8_lin->GetYaxis()->SetRangeUser(ylow,yhigh);
  fit_8_lin->Draw();
  gev_8->Draw("same PO");

  
  pad[3][0]->cd();
  fit_1->GetXaxis()->SetLabelSize(.08);
  fit_1->GetXaxis()->SetRangeUser(xlow,xhigh);
  fit_1->GetYaxis()->SetRangeUser(ylow,yhigh);
  fit_1->Draw();
  gev_1->Draw("same PO");
  fit_1->SetTitle("1 A GeV");

    
}
