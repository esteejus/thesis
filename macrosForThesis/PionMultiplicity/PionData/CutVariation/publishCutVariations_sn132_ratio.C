#include "/home/justin/mythesis/thesis_style.h"

using namespace style;


void CanvasPartition(TCanvas *C,const Int_t Nx,const Int_t Ny,
                     Float_t lMargin, Float_t rMargin,
                     Float_t bMargin, Float_t tMargin)
{
  if (!C) return;

  // Setup Pad layout:
  Float_t vSpacing = 0.1;
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



void publishCutVariations_sn132_ratio(int this_var = 3,TString filename = "blank")
{
  //  vector< vector<int>> labels = { {14,16,18,20,22,24,26}, {14,16,18,20,22,24,26}, {48,49,50,51,52,53,54}, {47,48,49,50,51,52,53} };

  vector< vector<int>> labels = { {14,16,18,20,22,24,26}, {14,16,18,20,22,24,26}, {35,40,45,51,55,60,65}, {35,40,45,50,55,60,65} };
  vector<TString> labels_n = {"# Clusters","POCA","{}^{132}Sn Multiplicity","{}^{108}Sn Multiplicity"};
    
  int bins = 1;
  int var  = 4;
  int default_p = 3;
  double frac = 4.;

  int lineSt = 6;
  int markCl = 1;
  int markS  = 20;
  int markSz = 2;
  int linew = 4;
  int ndiv = 405;

  TFile *f = TFile::Open("../rootfiles/cutVariaiton_totalYields.root");
  TGraphErrors *singleRatio[bins][var];
  TGraphErrors *pipsingleRatio[bins][var];
  TBox *box[bins][var];
  TLine *line[bins][var];
  TArrow *arrowL = new TArrow(.22,.03,.7,.03,.02,"<|");
  TArrow *arrowR = new TArrow(5.3,.03,5.7,.03,.02,"|>");

  arrowL->SetNDC();
  arrowR->SetNDC();
  
  gStyle->SetOptStat(0);

    TCanvas *C = new TCanvas("c1","",1000,300);

  // Margins
  Float_t lMargin = 0.1;
  Float_t rMargin = 0.05;
  Float_t bMargin = 0.3;
  Float_t tMargin = 0.1;

  // Canvas setup
  C->SetTopMargin(tMargin);
  C->SetBottomMargin(bMargin);
  C->SetLeftMargin(lMargin);
  C->SetRightMargin(rMargin);

  // Number of PADS
  const Int_t Nx = 1;
  const Int_t Ny = 3;


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

  for(int iBin = 0; iBin < 1; iBin++)
    {
      for(int iVar = 0; iVar < var; iVar++)
	{
	  singleRatio[iBin][iVar] = (TGraphErrors *)f->Get(Form("sn132_totalpim_%d_%d",iBin,iVar));
	  pipsingleRatio[iBin][iVar] = (TGraphErrors *)f->Get(Form("sn132_totalpip_%d_%d",iBin,iVar));
	  //calculate ratio
	  for(int i = 0; i < singleRatio[iBin][iVar]->GetN(); i++)
	    {
	      double pim, pip, pim_err, pip_err, x;
	      singleRatio[iBin][iVar] -> GetPoint(i,x,pim);
	      pipsingleRatio[iBin][iVar] -> GetPoint(i,x,pip);
	      pim_err = singleRatio[iBin][iVar] -> GetErrorY(i);
	      pip_err =  pipsingleRatio[iBin][iVar] -> GetErrorY(i);

	      double err = pim/pip * sqrt( pow(pim_err/pim,2) + pow(pip_err/pip,2) );

	      cout<<iVar <<" "<<pim/pip<<endl;
	      singleRatio[iBin][iVar]->SetPoint(i,x,pim/pip);
	      singleRatio[iBin][iVar]->SetPointError(i,0,err);
	    }
	}
    }
  




  


  //  singleRatio[0][1]->Draw(); 

  TPad *pad[Nx][Ny];

  int iVar = this_var;
      for (Int_t i=0;i<Nx;i++)
	{
	  for (Int_t iBin = 0 ;iBin < Ny; iBin++)
	    {
	     
	      singleRatio[i][iBin]->GetXaxis()->ChangeLabel(1,-1,-1,-1,-1,-1,Form("%d",labels.at(iBin).at(0)));
	      singleRatio[i][iBin]->GetXaxis()->ChangeLabel(2,-1,-1,-1,-1,-1,Form("%d",labels.at(iBin).at(1)));
	      singleRatio[i][iBin]->GetXaxis()->ChangeLabel(3,-1,-1,-1,-1,-1,Form("%d",labels.at(iBin).at(2)));
	      singleRatio[i][iBin]->GetXaxis()->ChangeLabel(4,-1,-1,-1,-1,-1,Form("%d",labels.at(iBin).at(3)));
	      singleRatio[i][iBin]->GetXaxis()->ChangeLabel(5,-1,-1,-1,-1,-1,Form("%d",labels.at(iBin).at(4)));
	      singleRatio[i][iBin]->GetXaxis()->ChangeLabel(6,-1,-1,-1,-1,-1,Form("%d",labels.at(iBin).at(5)));
	      singleRatio[i][iBin]->GetXaxis()->ChangeLabel(-1,-1,-1,-1,-1,-1,Form("%d",labels.at(iBin).at(6)));
  //singleRatio[i][iBin]->GetYaxis()->ChangeLabel(labels.at(iBin).at(0),labels.at(iBin).at(1),labels.at(iBin).at(2),labels.at(iBin).at(3),labels.at(iBin).at(4),labels.at(iBin).at(5),labels.at(iBin).at(6));


	      double x,y,ye;
	      singleRatio[i ][iBin] -> GetPoint(3,x,y);
	      ye = singleRatio[i ][iBin] -> GetErrorY(3);
	      box[i ][iBin] = new TBox(-.5,y-ye,6.5,y+ye);
	      line[i ][iBin] = new TLine(-.5,y,6.5,y);
	      singleRatio[i ][iBin]->GetYaxis()->SetRangeUser(y-ye*frac,y+ye*frac);
	      if(iBin == 2)
		singleRatio[i ][iBin]->GetYaxis()->SetRangeUser(y-ye*frac*3,y+ye*frac*3);
	      if(iBin == 0)
		singleRatio[i ][iBin]->GetYaxis()->SetRangeUser(y-ye*frac,y+ye*frac);

	      if(iBin == 1)
		singleRatio[i ][iBin]->GetYaxis()->SetRangeUser(y-ye*frac*.5,y+ye*frac*.5);

	      singleRatio[i ][iBin]->GetXaxis()->SetLimits(-.5,6.5);

	      singleRatio[i ][iBin]->SetLineWidth(4);
	      singleRatio[i ][iBin]->GetYaxis()->SetNdivisions(ndiv);
	      singleRatio[i ][iBin]->GetYaxis()->SetTitle("#pi^{-}/#pi^{+}");
	      singleRatio[i ][iBin]->GetYaxis()->CenterTitle();
	      singleRatio[i ][iBin]->GetYaxis()->SetTitleFont(43);
	      singleRatio[i ][iBin]->GetYaxis()->SetTitleSize(30);
	      singleRatio[i ][iBin]->GetYaxis()->SetTitleOffset(.3);
	      singleRatio[i ][iBin]->GetYaxis()->SetLabelFont(43);
	      singleRatio[i ][iBin]->GetYaxis()->SetLabelSize(20);
	      singleRatio[i ][iBin]->SetTitle("");

	      singleRatio[i ][iBin]->GetXaxis()->SetNdivisions(7);
	      //	      singleRatio[i ][iBin]->GetXaxis()->SetTitle("Looser      " + labels_n.at(iBin) + "        Tighter");
	      singleRatio[i ][iBin]->GetXaxis()->SetTitle(labels_n.at(iBin));

	      singleRatio[i ][iBin]->GetXaxis()->CenterTitle();
	      singleRatio[i ][iBin]->GetXaxis()->SetTitleFont(43);
	      singleRatio[i ][iBin]->GetXaxis()->SetTitleSize(30);
	      singleRatio[i ][iBin]->GetXaxis()->SetTitleOffset(1.);
	      singleRatio[i ][iBin]->GetXaxis()->SetLabelFont(43);
	      singleRatio[i ][iBin]->GetXaxis()->SetLabelSize(20);


	      singleRatio[i ][iBin]->SetPointError(default_p,0,0);
	      singleRatio[i ][iBin]->SetMarkerStyle(markS);
	      singleRatio[i ][iBin]->SetMarkerSize(markSz);
	      singleRatio[i ][iBin]->SetMarkerColor(markCl);	  


	      singleRatio[i ][iBin]->Draw("APO"); 


	      box[i ][iBin]->SetFillColorAlpha(kRed, .2);
	      box[i ][iBin]->Draw("same");
	      line[i ][iBin]->SetLineStyle(lineSt);
	      line[i ][iBin]->Draw("same");

	      // arrowL->SetLineWidth(linew);
	      //   arrowR->SetLineWidth(linew);
	      // arrowL->Draw();
	      // arrowR->Draw();    
	      C -> SaveAs(labels_n.at(iBin) + "_TotalRatio.png");
	    }
	}
    
   
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
