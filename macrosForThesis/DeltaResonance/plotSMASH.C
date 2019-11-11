

void plotSMASH()
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
  
  TFile *delta = TFile::Open("delta.root");
  TH1D *delta_h = (TH1D *)delta->Get("delta_pp");
  delta_h->Rebin(4);
  delta_h->Scale(1./delta_h->Integral("width"));
  
  TCanvas *c1 = new TCanvas("c1","c1",1600,800);
  //  c1->SetLogy();

  TH1D *signal_bkg_z = (TH1D *)signal_bkg->Clone();
  TH1D *em_bkg_z = (TH1D *)em_bkg->Clone();
 
  TH1D *diff = (TH1D *)signal_bkg->Clone();
  diff->Add(em_bkg,-1);
  diff->GetXaxis()->SetRangeUser(1060,1400);
  diff->GetYaxis()->SetRangeUser(-200,1900);
    

  TH1D *diff_inset = (TH1D *)diff->Clone();
  diff_inset->SetTitle("");
  diff_inset->GetXaxis()->SetRangeUser(1070,1250);
  diff_inset->GetYaxis()->SetRangeUser(-200,1900);
  diff_inset->SetMarkerStyle(20);
  diff_inset->SetMarkerSize(1);
  diff_inset->Scale(1./diff_inset->Integral());
  diff_inset->Draw("PE");
  delta_h->SetLineColor(2);
  delta_h->Draw("same HIST");
  


}

