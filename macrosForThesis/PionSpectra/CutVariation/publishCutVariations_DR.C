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



void publishCutVariations_DR( int this_var)
{

  int bins = 6;
  int var  = 4;
  int default_p = 3;
  double frac = 1.2;

  int lineSt = 6;
  int markCl = 1;
  int markS  = 20;
  int markSz = 2;
  int linew = 4;
  int ndiv = 405;

  TFile *f = TFile::Open("cutVariaiton_DR.root");
  TGraphErrors *singleRatio[bins][var];
  TBox *box[bins][var];
  TLine *line[bins][var];
  TArrow *arrowL = new TArrow(.25,.04,.3,.04,.02,"<|");
  TArrow *arrowR = new TArrow(.75,.04,.8,.04,.02,"|>");

  gStyle->SetOptStat(0);

  TCanvas *C = (TCanvas*) gROOT->FindObject("C");
  if (C) delete C;
  C = new TCanvas("C","canvas",1024,640);
  C->SetFillStyle(4000);

  // Number of PADS
  const Int_t Nx = 1;
  const Int_t Ny = 6;

  // Margins
  Float_t lMargin = 0.12;
  Float_t rMargin = 0.05;
  Float_t bMargin = 0.1;
  Float_t tMargin = 0.05;

  // Canvas setup
  CanvasPartition(C,Nx,Ny,lMargin,rMargin,bMargin,tMargin);

  /*
  // Dummy histogram.
  TH1F *h = (TH1F*) gROOT->FindObject("histo");
  if (h) delete h;
  h = new TH1F("histo","",100,-5.0,5.0);
  h->FillRandom("gaus",10000);
  h->GetXaxis()->SetTitle("x axis");
  h->GetYaxis()->SetTitle("y axis");
  */

  gPad->SetLineWidth(linew);
  gStyle->SetLineWidth(linew);
  gStyle->SetFrameLineWidth(linew);
  gStyle->SetEndErrorSize(5);


  for(int iBin = 1; iBin <= 6; iBin++)
    {
      for(int iVar = 0; iVar < var; iVar++)
	{

	  singleRatio[iBin][iVar] = (TGraphErrors *)f->Get(Form("sn132_singleRatio_%d_%d",iBin,iVar));
	}
    }
  
  TPad *pad[Nx][Ny];


  int iVar = this_var;
      for (Int_t i=0;i<Nx;i++)
	{
	  for (Int_t iBin = 0 ;iBin < Ny; iBin++)
	    {
	      C->cd(0);
	      // Get the pads previously created.
	      char pname[16];
	      sprintf(pname,"pad_%i_%i",i,iBin);
	      pad[i][iBin] = (TPad*) gROOT->FindObject(pname);

	      pad[i][iBin]->Draw();
	      pad[i][iBin]->SetFillStyle(4000);
	      pad[i][iBin]->SetFrameFillStyle(4000);
	      pad[i][iBin]->cd();

	      // Size factors
	      Float_t xFactor = pad[0][0]->GetAbsWNDC()/pad[i][iBin]->GetAbsWNDC();
	      Float_t yFactor = pad[0][0]->GetAbsHNDC()/pad[i][iBin]->GetAbsHNDC();
	      // TICKS Y Axis
	      singleRatio[Ny - iBin][iVar]->GetYaxis()->SetTickLength(xFactor*0.04/yFactor);
	      // TICKS X Axis
	      singleRatio[Ny - iBin ][iVar]->GetXaxis()->SetTickLength(yFactor*0.06/xFactor);
	   
	      double x,y,ye;
	      singleRatio[Ny - iBin ][iVar] -> GetPoint(3,x,y);
	      ye = singleRatio[Ny - iBin ][iVar] -> GetErrorY(3);
	      box[Ny - iBin ][iVar] = new TBox(-.5,y-ye,6.5,y+ye);
	      line[Ny - iBin ][iVar] = new TLine(-.5,y,6.5,y);
	      //singleRatio[Ny - iBin ][iVar]->GetYaxis()->SetRangeUser(y-ye*frac,y+ye*frac);
	      singleRatio[Ny - iBin ][iVar]->GetXaxis()->SetLimits(-.5,6.5);

	      singleRatio[Ny - iBin ][iVar]->SetLineWidth(4);
	      singleRatio[Ny - iBin ][iVar]->GetYaxis()->SetNdivisions(ndiv);
	      singleRatio[Ny - iBin ][iVar]->GetYaxis()->SetTitle(Form("Bin %d",Ny - iBin ));
	      singleRatio[Ny - iBin ][iVar]->GetYaxis()->CenterTitle();
	      singleRatio[Ny - iBin ][iVar]->GetYaxis()->SetTitleFont(43);
	      singleRatio[Ny - iBin ][iVar]->GetYaxis()->SetTitleSize(30);
	      singleRatio[Ny - iBin ][iVar]->GetYaxis()->SetTitleOffset(1);
	      singleRatio[Ny - iBin ][iVar]->GetYaxis()->SetLabelFont(43);
	      singleRatio[Ny - iBin ][iVar]->GetYaxis()->SetLabelSize(20);
	      singleRatio[Ny - iBin ][iVar]->SetTitle("");

	      singleRatio[Ny - iBin ][iVar]->GetXaxis()->SetNdivisions(7);
	      singleRatio[Ny - iBin ][iVar]->GetXaxis()->SetTitle("Looser                       Tighter");
	      singleRatio[Ny - iBin ][iVar]->GetXaxis()->CenterTitle();
	      singleRatio[Ny - iBin ][iVar]->GetXaxis()->SetTitleFont(43);
	      singleRatio[Ny - iBin ][iVar]->GetXaxis()->SetTitleSize(30);
	      singleRatio[Ny - iBin ][iVar]->GetXaxis()->SetTitleOffset(3);
	      singleRatio[Ny - iBin ][iVar]->GetXaxis()->SetLabelFont(43);
	      singleRatio[Ny - iBin ][iVar]->GetXaxis()->SetLabelSize(20);


	      singleRatio[Ny - iBin ][iVar]->SetPointError(default_p,0,0);
	      singleRatio[Ny - iBin ][iVar]->SetMarkerStyle(markS);
	      singleRatio[Ny - iBin ][iVar]->SetMarkerSize(markSz);
	      singleRatio[Ny - iBin ][iVar]->SetMarkerColor(markCl);	  

	      singleRatio[Ny - iBin ][iVar]->Draw("APO");

	      box[Ny - iBin ][iVar]->SetFillColorAlpha(kRed, .2);
	      box[Ny - iBin ][iVar]->Draw("same");
	      line[Ny - iBin ][iVar]->SetLineStyle(lineSt);
	      line[Ny - iBin ][iVar]->Draw("same");
	    }
	}
      C->cd();
      arrowL->SetLineWidth(linew);
      arrowR->SetLineWidth(linew);
      arrowL->Draw();
      arrowR->Draw();    
      C -> SaveAs(Form("cvs_%d_DR.png",iVar));
   
  /*
    for(int iBin = 1; iBin <= 1; iBin++)
    {
    for(int iVar = 0; iVar < var; iVar++)
    {
    singleRatio[iBin][iVar] = (TGraphErrors *)f->Get(Form("singleRatio_%d_%d",iBin,iVar));
	  
    double x,y,ye;
    singleRatio[iBin][iVar] -> GetPoint(3,x,y);
    ye = singleRatio[iBin][iVar] -> GetErrorY(3);
    box[iBin][iVar] = new TBox(-.5,y-ye,6.5,y+ye);
    line[iBin][iVar] = new TLine(-.5,y,6.5,y);
    //singleRatio[iBin][iVar]->GetYaxis()->SetRangeUser(y-ye*frac,y+ye*frac);
    singleRatio[iBin][iVar]->GetXaxis()->SetLimits(-.5,6.5);

    singleRatio[iBin][iVar]->SetLineWidth(4);
    singleRatio[iBin][iVar]->GetYaxis()->SetNdivisions(ndiv);
    singleRatio[iBin][iVar]->GetYaxis()->SetTitle(Form("Bin %d",iBin));
    singleRatio[iBin][iVar]->GetYaxis()->CenterTitle();
    singleRatio[iBin][iVar]->GetYaxis()->SetTitleSize(.3);
    singleRatio[iBin][iVar]->GetYaxis()->SetTitleOffset(.15);
    singleRatio[iBin][iVar]->GetYaxis()->SetLabelSize(.1);
    singleRatio[iBin][iVar]->SetTitle("");

    singleRatio[iBin][iVar]->GetXaxis()->SetNdivisions(7);
    singleRatio[iBin][iVar]->GetXaxis()->SetTitle("Looser                       Tighter");
    singleRatio[iBin][iVar]->GetXaxis()->CenterTitle();
    singleRatio[iBin][iVar]->GetXaxis()->SetTitleSize(.3);
    singleRatio[iBin][iVar]->GetXaxis()->SetTitleOffset(.15);
    singleRatio[iBin][iVar]->GetXaxis()->SetLabelSize(.1);


    singleRatio[iBin][iVar]->SetPointError(default_p,0,0);
    singleRatio[iBin][iVar]->SetMarkerStyle(markS);
    singleRatio[iBin][iVar]->SetMarkerSize(markSz);
    singleRatio[iBin][iVar]->SetMarkerColor(markCl);	  

    pad[0][iBin]->cd();
    // cvs[iVar]->cd(iBin);
    singleRatio[iBin][iVar]->Draw("APO");

    box[iBin][iVar]->SetFillColorAlpha(kRed, .2);
    box[iBin][iVar]->Draw("same");
    line[iBin][iVar]->SetLineStyle(lineSt);
    line[iBin][iVar]->Draw("same");


    }
    }
  */
}
