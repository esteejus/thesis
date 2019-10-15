
TH1D*  bill_method(TH1D *d, bool flag = false)
{
  double a_o = .9723;
  double a_1 = -.9453;
  double b_o = .9545;
  double b_1 = -.9203;

  TH1D *bill = new TH1D("","",270,0,270);

  int i = 2;
  if(flag)
    i = 40;
  
  double pulse_prev = d->GetBinContent(i-1);
  double correct_prev = 0;
     
  for(int i = 0; i < d->GetNbinsX(); i++)
    {
      double pul   = d->GetBinContent(i);
      double correct = (-b_1 * correct_prev + a_o * pul + a_1 * pulse_prev)/b_o;
      pulse_prev = pul;
      correct_prev = correct;
      cout<<i<<" "<<correct<<endl;
      bill->SetBinContent(i,correct);
    }

  return bill;
}

//#include "thesis_style.h"

//using namespace style;

STPulse *ns = new STPulse("pulser_117ns_50tb.dat");
STPulse *s  = new STPulse("saturatedPulse.dat");

double sat_pulse(double *x, double *par)
{
  return s->Pulse(x[0],par[0],0);
}

double nsat_pulse(double *x, double *par)
{
  return ns->Pulse(x[0],par[0],0);
}

void plotSTPulse()
{
  TF1 *not_sat = new TF1("not_sat",nsat_pulse,0,270,1);
  TF1 *not_sat_f = new TF1("not_sat_f",nsat_pulse,0,40,1);
  TF1 *not_sat_10 = new TF1("not_sat_10",nsat_pulse,0,270,1);
  TF1 *sat     = new TF1("sat",sat_pulse,0,270,1);
  TF1 *sat_f     = new TF1("sat_f",sat_pulse,40,270,1);
  
  not_sat_f->SetNpx(270);
  not_sat->SetNpx(270);
  not_sat_10->SetNpx(270);
  sat->SetNpx(270);  
  sat_f->SetNpx(230);
  
  not_sat_f->SetParameter(0,1);
  not_sat->SetParameter(0,1);
  not_sat_10->SetParameter(0,10);
  sat->SetParameter(0,1);
  sat_f->SetParameter(0,1);
  
  TH1D *not_sat_h = (TH1D *)not_sat->GetHistogram();
  TH1D *sat_h = (TH1D *)sat->GetHistogram();

  auto not_sat_b = bill_method(not_sat_h);
  auto sat_b = bill_method(sat_h,true);
  
  not_sat->GetXaxis()->SetTitle("Time Bucket (Tb)");
  sat->GetXaxis()->SetTitle("Time Bucket (Tb)");

  not_sat->GetYaxis()->SetTitle("ADC");
  sat->GetYaxis()->SetTitle("ADC");

  not_sat->GetXaxis()->CenterTitle();
  sat->GetXaxis()->CenterTitle();
  not_sat->GetYaxis()->CenterTitle();
  sat->GetYaxis()->CenterTitle();

  TCanvas *c1 = new TCanvas("c1","c1",1); 
  sat->SetLineWidth(4);
  not_sat->SetLineWidth(4);
  not_sat->SetLineStyle(9);
  
  not_sat_b->SetLineWidth(4);
  sat_b->SetLineWidth(4);  
  not_sat_b->SetLineStyle(9);

  not_sat_b->SetLineColor(4);
  sat_b->SetLineColor(4);  

  /*
  TLegend *leg = new TLegend(.4,.4,.9,.9);
  leg->AddEntry(sat,"Saturated Signal","L");
  leg->AddEntry(not_sat,"Normal Signal","L");
  leg->SetBorderSize(0);
  leg->SetFillColor(0);

  sat->SetNpx(10000);
  not_sat->SetNpx(10000);
  */

  not_sat->GetXaxis()->SetRangeUser(0,100);
  not_sat->GetYaxis()->SetRangeUser(-.1,1.1);

  //  not_sat->GetXaxis()->SetRangeUser(0,40);
  //  not_sat_b->GetXaxis()->SetRangeUser(0,40);

  //  sat->GetXaxis()->SetRangeUser(40,100);
  //  sat_b->GetXaxis()->SetRangeUser(40,100);

  not_sat->Draw();
  sat->Draw("same");
  not_sat_b->Draw("same L");
  sat_b->Draw("same L");


  sat_b->SetName("sat_b");
  //  not_sat_b->SetName("not_sat_b");
  
  TFile *out = new TFile("pulses.root","RECREATE");
  sat->Write();
  not_sat->Write();
  not_sat_b->Write();
  sat_b->Write();

}
