

void plotData_bkgSideband()
{

  TFile *f = TFile::Open("invariant-merge.root");
  TH1D *signal_bkg = (TH1D *)f->Get("corr_event");
  TH1D *em_bkg = (TH1D *)f->Get("ncorr_event");

  int i_rebin = 1;
  
  signal_bkg->Rebin(i_rebin);
  em_bkg->Rebin(i_rebin);
  
  double mass_min = 1250;
  double mass_max = 2000;

  int bin_min = signal_bkg->GetXaxis()->FindBin(mass_min);
  int bin_max = signal_bkg->GetXaxis()->FindBin(mass_max);

  double signal_int = signal_bkg->Integral(bin_min,bin_max);
  double bkg_int    = em_bkg->Integral(bin_min,bin_max);

  em_bkg->Sumw2();
  signal_bkg->Sumw2();
  
  em_bkg->Scale(signal_int/bkg_int);
  em_bkg->SetLineColor(2);
  
  TCanvas *c1 = new TCanvas("c1","c1",800,1600);
  c1->SetLogy();
  TPad *pad1 = new TPad("pad1","pad1",0,.7,1,1);
  TPad *pad2 = new TPad("pad2","pad2",0,.5,1,.7);
  TPad *pad3 = new TPad("pad3","pad3",0,0,1,.5);

  TPad *pad4 = new TPad("pad4","pad4",.37,.78,.95,1);

  pad1->SetBottomMargin(0.00001);
  pad1->SetBorderMode(0);
  pad2->SetBottomMargin(0.1);
  pad2->SetTopMargin(0.00001);
  pad3->SetTopMargin(0.00001);
  pad3->SetBorderMode(0);

  //pad1->SetLogy();
  pad1->Draw();
  pad2->Draw();
  pad3->Draw();
  pad4->Draw();
  pad1->cd();

  
  TH1D *signal_bkg_z = (TH1D *)signal_bkg->Clone();
  TH1D *em_bkg_z = (TH1D *)em_bkg->Clone();
 
  signal_bkg->GetXaxis()->SetRangeUser(1060,1400);
  signal_bkg->GetYaxis()->SetRangeUser(-500,15000);
  signal_bkg->Draw("HIST E");
  em_bkg->Draw("HISTE same");

  TH1D *diff = (TH1D *)signal_bkg->Clone();
  diff->Add(em_bkg,-1);
  diff->GetXaxis()->SetRangeUser(1060,1400);
  diff->GetYaxis()->SetRangeUser(-200,1900);
  pad2->cd();
  diff->Draw();

  TH1D *diff_inset = (TH1D *)diff->Clone();
  pad3->cd();
  diff_inset->SetTitle("");
  diff_inset->GetXaxis()->SetRangeUser(1070,1250);
  diff_inset->GetYaxis()->SetRangeUser(-200,1900);
  diff_inset->SetMarkerStyle(20);
  diff_inset->SetMarkerSize(1);
  diff_inset->Draw("PE");

  pad4->cd();
  pad4->SetLogy();
  signal_bkg_z->GetXaxis()->SetRangeUser(1200,2000);
  em_bkg_z->GetXaxis()->SetRangeUser(1200,2000);
  signal_bkg_z->Draw();
  em_bkg_z->Draw("same");

}

