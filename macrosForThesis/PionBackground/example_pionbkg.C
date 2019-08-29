
//Example script for showing how to background subtrack through weighting
//This is a working proof of it

void example_pionbkg()
{

TF1 *signal = new TF1("signal_fcn","[0]*TMath::Gaus(x,[1],[2],true)",-10,10);
TF1 *bkg    = new TF1("bkg","[0]*TMath::Gaus(x,[1],[2],true)",-10,10);

  double nSignal = 1000;
  double nBkg    = 3000;

  signal->SetParameters(nSignal,0,1);
  bkg   ->SetParameters(nBkg,2,1);

  cout<<"Integral "<<signal->Integral(-20,20)<<endl;

  auto sum = [=](double *x, double *p){
    return signal->Eval(x[0]) + bkg->Eval(x[0]);
  };
  
  TF1 *total = new TF1("total",sum,-10,10,0);
  
  TCanvas *c1 = new TCanvas("c1","c1",1);
  total->SetLineColor(1);
  signal->SetLineColor(2);
  bkg   ->SetLineColor(3);
  
  total->Draw();
  signal->Draw("same");
  bkg->Draw("same");

  TH1D *exp = new TH1D("exp","exp",100,-10,10);
  TH1D *signal_w = new TH1D("signal_w","signal_w",100,-10,10);
  TH1D *signal_t = new TH1D("signal_t","signal_t",100,-10,10);
  TH1D *bkg_t = new TH1D("bkg_t","bkg_t",100,-10,10);
  
  for(int i = 0; i < nSignal; i++)
    {
      double signal_v = signal->GetRandom();
      exp->Fill(signal_v);
      signal_w->Fill(signal_v,signal->Eval(signal_v)/total->Eval(signal_v));
      signal_t->Fill(signal_v);
    }

  for(int i = 0; i < nBkg; i++)
    {
      double bkg_v = bkg->GetRandom();
      exp->Fill(bkg_v);
      signal_w->Fill(bkg_v,signal->Eval(bkg_v)/total->Eval(bkg_v));
      bkg_t->Fill(bkg_v);
    }

  TCanvas *c2 = new TCanvas("c2","c2",1);
  signal_t->SetLineColor(4);
  signal_t->Scale(1,"width");
  bkg_t->Scale(1,"width");
  bkg_t->SetLineColor(3);
  
  exp->Scale(1,"width");
  signal_w->Scale(1,"width");
  exp->SetLineColor(1);
  exp->Draw();
  signal_w->SetLineColor(2);
  signal_w->Draw("same");
  signal->Draw("same");
  signal_t->Draw("same");
  bkg_t->Draw("same");

}
