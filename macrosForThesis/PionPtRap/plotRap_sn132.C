#include "/home/justin/mythesis/thesis_style.h"

using namespace style;

void reflect(TH2D *h)
{
  int zerobin = h->GetXaxis()->FindBin(0.);
  cout<<zerobin<<" "<<h->GetNbinsX()<<endl;
  for(int i = 1; i < zerobin; i++)
    {
      for(int j = 1; j < h->GetNbinsY(); j++)
	h->SetBinContent(i + 1,j,h->GetBinContent(h->GetNbinsX()-i,j));
    }

}


void plotRap_sn132()
{
 gStyle->SetFrameLineWidth(6);
 gStyle->SetLineWidth(6);
 
 double events_sn132 = 807197;


  TFile *f = TFile::Open("analysis-Sn132-merge.root");
  TFile *g = TFile::Open("analysis-Sn108-merge.root");


  auto pim132_ypt_ec = (TH2D *)f->Get("pim_ypt_ec");
  auto pip132_ypt_ec = (TH2D *)f->Get("pip_ypt_ec");

  auto pim108_ypt_ec = (TH2D *)g->Get("pim_ypt_ec");
  auto pip108_ypt_ec = (TH2D *)g->Get("pip_ypt_ec");

  pim132_ypt_ec->SetTitle("");
  pim132_ypt_ec->GetXaxis()->SetTitle("y_{o}");
  pim132_ypt_ec->GetYaxis()->SetTitle("P_{T}  (MeV c^{-1})");

  pip132_ypt_ec->SetTitle("");
  pip132_ypt_ec->GetXaxis()->SetTitle("y_{o}");
  pip132_ypt_ec->GetYaxis()->SetTitle("P_{T}  (MeV c^{-1})");

  pim108_ypt_ec->SetTitle("");
  pim108_ypt_ec->GetXaxis()->SetTitle("y_{o}");
  pim108_ypt_ec->GetYaxis()->SetTitle("P_{T}  (MeV c^{-1})");

  pip108_ypt_ec->SetTitle("");
  pip108_ypt_ec->GetXaxis()->SetTitle("y_{o}");
  pip108_ypt_ec->GetYaxis()->SetTitle("P_{T}  (MeV c^{-1})");


  make(pim132_ypt_ec);
  pim132_ypt_ec->Scale(1./events_sn132);
  pim132_ypt_ec->RebinY(4);
  pim132_ypt_ec->RebinX(2);
  reflect(pim132_ypt_ec);

  make(pip132_ypt_ec);
  pip132_ypt_ec->Scale(1./events_sn132);
  pip132_ypt_ec->RebinY(4);
  pip132_ypt_ec->RebinX(2);
  reflect(pip132_ypt_ec);

  make(pim108_ypt_ec);
  pim108_ypt_ec->RebinY();
  reflect(pim108_ypt_ec);

  make(pip108_ypt_ec);
  pip108_ypt_ec->RebinY();
  reflect(pip108_ypt_ec);

  TBox *box = new TBox(-3.49,2,0,449);
  box->SetFillColorAlpha(kWhite,.5); 
 
  TLatex latex;
  latex.SetTextSize(.08);
  latex.SetNDC(true);
   
  TLatex latex2;
  latex2.SetTextSize(.04);
  latex2.SetNDC(true);

  TPaveText *pave1 = new TPaveText(-3,420,-1,450);
  pave1->AddText("Reflected");
  TPaveText *pave2 = new TPaveText(1,420,3,450);
  pave2->AddText("Measured");
  TPaveText *pim = new TPaveText(-.5,420,.5,450);
  pim->AddText("#pi^{-}");
  
  TPaveText *pave3 = new TPaveText(-3,420,-1,450);
  pave3->AddText("Reflected");
  TPaveText *pave4 = new TPaveText(1,420,3,450);
  pave4->AddText("Measured");
  TPaveText *pip = new TPaveText(-.5,420,.5,450);
  pip->AddText("#pi^{+}");
  
 TCanvas *cvs = style::stdcvs("cvs",1600,800);
  cvs->Divide(2,1,0,0);

  cvs->cd(1)->SetLineWidth(6);
  gPad->SetLineWidth(6);
  cvs->cd(1)->SetTopMargin(.01);
  cvs->cd(1)->SetLeftMargin(.15);
  cvs->cd(1);

  pim132_ypt_ec->GetYaxis()->SetNdivisions(505);
  pim132_ypt_ec->GetXaxis()->SetRangeUser(-3.5,3.5);
  pim132_ypt_ec->GetYaxis()->SetRangeUser(0,450);
  pim132_ypt_ec->GetYaxis()->SetTitleOffset(1.2);
  pim132_ypt_ec->Draw("col");
  //  latex2.DrawLatex(.2,.7,"reflected");
  pave1->Draw();
  box->Draw();
  //  latex2.DrawLatex(.8,.7,"measured");
  pave2->Draw();
  //  latex.DrawLatex(.7,.9,"#pi^{-}");
  pim->Draw();
  
  cvs->cd(2)->SetTopMargin(.01);
  cvs->cd(2)->SetRightMargin(.1);
  cvs->cd(2);

  pip132_ypt_ec->GetYaxis()->SetNdivisions(505);
  pip132_ypt_ec->GetXaxis()->SetRangeUser(-3.5,3.5);
  pip132_ypt_ec->GetYaxis()->SetRangeUser(0,450);
  pip132_ypt_ec->Draw("col");
  pave3->Draw();
  //  latex2.DrawLatex(.1,.7,"reflected");
  box->Draw();
  //  latex2.DrawLatex(.8,.7,"measured");
  pave4->Draw();
  //  latex.DrawLatex(.7,.9,"#pi^{+}");
  pip->Draw();

  cvs->SaveAs("ypt_sn132.png"); 
}
