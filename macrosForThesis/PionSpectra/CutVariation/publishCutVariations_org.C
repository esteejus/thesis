#include "/home/justin/mythesis/thesis_style.h"

using namespace style;

void publishCutVariations_org()
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
  
  TFile *f = TFile::Open("cutVariaiton_singleRatio.root");
  TGraphErrors *singleRatio[bins][var];
  TBox *box[bins][var];
  TLine *line[bins][var];

  TCanvas *cvs[var];
  for(int iVar = 0; iVar < var; iVar++)
    {
      cvs[iVar] = style::stdcvs(Form("cvs_%d",iVar));
      //      cvs[iVar] = new TCanvas(Form("c%d",iVar),Form("c%d",iVar),1);
      cvs[iVar]->Divide(1,bins,0,0);
      cvs[iVar]->SetBottomMargin(.5);
      //      cvs[iVar]->SetLineWidth(linew);
      //      cvs[iVar]->SetFrameLineWidth(linew);
    }
  
  gPad->SetLineWidth(linew);
  gStyle->SetLineWidth(linew);
  gStyle->SetFrameLineWidth(linew);
  gStyle->SetEndErrorSize(5);


  for(int iBin = 1; iBin <= bins; iBin++)
    {
      for(int iVar = 0; iVar < var; iVar++)
	{
	  singleRatio[iBin][iVar] = (TGraphErrors *)f->Get(Form("singleRatio_%d_%d",iBin,iVar));
	  
	  double x,y,ye;
	  singleRatio[iBin][iVar] -> GetPoint(3,x,y);
	  ye = singleRatio[iBin][iVar] -> GetErrorY(3);
	  box[iBin][iVar] = new TBox(-.5,y-ye,6.5,y+ye);
	  line[iBin][iVar] = new TLine(-.5,y,6.5,y);
	  //	  singleRatio[iBin][iVar]->GetYaxis()->SetRangeUser(y-ye*frac,y+ye*frac);
	  singleRatio[iBin][iVar]->GetXaxis()->SetLimits(-.5,6.5);




	  singleRatio[iBin][iVar]->SetLineWidth(4);

	  singleRatio[iBin][iVar]->GetYaxis()->SetNdivisions(ndiv);
	  singleRatio[iBin][iVar]->SetTitle(Form("Bin %d",iBin));
	  singleRatio[iBin][iVar]->SetPointError(default_p,0,0);
	  singleRatio[iBin][iVar]->SetMarkerStyle(markS);
	  singleRatio[iBin][iVar]->SetMarkerSize(markSz);
	  singleRatio[iBin][iVar]->SetMarkerColor(markCl);	  

	  cvs[iVar]->cd(iBin);
 	  singleRatio[iBin][iVar]->Draw("APO");

	  box[iBin][iVar]->SetFillColorAlpha(kRed, .2);
	  box[iBin][iVar]->Draw("same");
	  line[iBin][iVar]->SetLineStyle(lineSt);
	  line[iBin][iVar]->Draw("same");


	}
    }

}
