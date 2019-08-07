namespace style
{
  TCanvas *stdcvs    ();

      TH1 *make (TH1     *h);
      TH2 *make (TH2     *h);
      TF1 *make (TF1     *f);
  TLegend *make (TLegend *legend);
  TCanvas *make (TCanvas *cvs);
  

  void make (TGraph  *graph);

  void save  (TH1 *h,TString filename, bool logz);
  void save2  (TH2 *h,TString filename, bool logz);
  void save  (TGraph *h,TString filename, bool square, bool logy);
  /********************************************************/

  void init();

     int fICvs=0;
     int fWCvs=1500;
     int fHCvs=1000;

  double fWUnit=0.006;
  double fHUnit=0.035;

  double fWStat=0.25;
  double fHStat=0.18;
  double fXStat=0.95;
  double fYStat=0.88;

  double fTMargin=0.06;
  double fBMargin=0.14;
  double fLMargin=0.12;
  double fRMargin=0.06;
  double fRMarginH1=0.03;
  double fRMarginH2=0.155;

  double fMainTitleSize=0.08;
  double fAxisLabelSize=0.06;
  double fAxisTitleSize=0.06;
  double fXTitleOffset=1.1;
  double fYTitleOffset=.9;

};

void style::init() {
  fXStat=1.-fRMargin;
  fYStat=1.-fTMargin;
  gStyle->SetStatStyle(0);
  gStyle->SetStatW(fWStat);
  gStyle->SetStatH(fHStat);
  gStyle->SetStatX(fXStat);
  gStyle->SetStatY(fYStat);
  gStyle->SetTitleFontSize(fMainTitleSize);
  gStyle->SetLineWidth(10);

}

TCanvas *style::stdcvs()
{
  init();
  auto cvs=new TCanvas("cvs","cvs",fWCvs,fHCvs);
  make(cvs);
  return cvs;
}

TCanvas *style::make(TCanvas *cvs) {
  cvs->SetMargin(fLMargin,fRMargin,fBMargin,fTMargin);
  cvs->SetFrameLineWidth(10);
  
  return cvs;
}

TH1 *style::make(TH1 *h) {
  init();
  gStyle->SetOptStat(0);
  h->GetXaxis()->CenterTitle();
  h->GetXaxis()->SetTitleOffset(fXTitleOffset);
  h->GetXaxis()->SetTitleSize(fAxisTitleSize);
  h->GetXaxis()->SetLabelSize(fAxisLabelSize);
  h->GetYaxis()->CenterTitle();
  h->GetYaxis()->SetTitleOffset(fYTitleOffset);
  h->GetYaxis()->SetTitleSize(fAxisTitleSize);
  h->GetYaxis()->SetLabelSize(fAxisLabelSize);
  h->GetZaxis()->SetLabelSize(fAxisLabelSize);
  h->SetLineWidth(10);
  h->SetTitle("");
  
  return h;
}

void style::make(TGraph *h) {
  init();
  gStyle->SetOptStat(0);
  h->GetXaxis()->CenterTitle();
  h->GetXaxis()->SetTitleOffset(fXTitleOffset);
  h->GetXaxis()->SetTitleSize(fAxisTitleSize);
  h->GetXaxis()->SetLabelSize(fAxisLabelSize);
  h->GetYaxis()->CenterTitle();
  h->GetYaxis()->SetTitleOffset(fYTitleOffset);
  h->GetYaxis()->SetTitleSize(fAxisTitleSize);
  h->GetYaxis()->SetLabelSize(fAxisLabelSize);
  h->SetLineWidth(10);
  h->SetTitle("");
}

TH2 *style::make(TH2 *h) {
  init();
  gStyle->SetOptStat(0);
  //  gStyle->SetLineWidth(10);
  h->GetXaxis()->CenterTitle();
  h->GetXaxis()->SetTitleOffset(fXTitleOffset);
  h->GetXaxis()->SetTitleSize(fAxisTitleSize);
  h->GetXaxis()->SetLabelSize(fAxisLabelSize);
  h->GetYaxis()->CenterTitle();
  h->GetYaxis()->SetTitleOffset(fYTitleOffset);
  h->GetYaxis()->SetTitleSize(fAxisTitleSize);
  h->GetYaxis()->SetLabelSize(fAxisLabelSize);
  h->GetZaxis()->SetLabelSize(fAxisLabelSize);

  
  return h;
}

TF1 *style::make(TF1 *f) {
  f -> SetNpx(1000);
  f->GetXaxis()->CenterTitle();
  f->GetXaxis()->SetTitleOffset(fXTitleOffset);
  f->GetXaxis()->SetTitleSize(fAxisTitleSize);
  f->GetXaxis()->SetLabelSize(fAxisLabelSize);
  f->GetYaxis()->CenterTitle();
  f->GetYaxis()->SetTitleOffset(fYTitleOffset);
  f->GetYaxis()->SetTitleSize(fAxisTitleSize);
  f->GetYaxis()->SetLabelSize(fAxisLabelSize);

  return f;
}

void style::save2(TH2 *h, TString filename,bool logz) {
  init();
  auto cvs=new TCanvas("cvs","cvs",fWCvs,fHCvs);
  if(logz==true)
    cvs->SetLogz();
  h->Draw("colz");
  cvs->SaveAs(filename);
}

void style::save(TGraph *h, TString filename,bool square = false, bool logy = false) {
  init();
  make(h);
  TCanvas *cvs;
  if(square)
    cvs=new TCanvas("cvs","cvs",fWCvs,fWCvs);
  else
    cvs=new TCanvas("cvs","cvs",fWCvs,fHCvs);
  cvs->SetFrameLineWidth(10);
  make(cvs);
  if(logy==true)
    cvs->SetLogy();
  h->Draw();
  cvs->SaveAs(filename);
}

void style::save(TH1 *h, TString filename,bool logz) {
  init();
  auto cvs=new TCanvas("cvs","cvs",fWCvs,fHCvs);
  if(logz==true)
    cvs->SetLogz();
   h->Draw("colz");
   cvs->SaveAs(filename);
}
