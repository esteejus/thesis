#include "/home/justin/mythesis/thesis_style.h"

using namespace style;

void plotPulse()
{

  TFile *f = TFile::Open("pulses.root");
  TF1 *sat = (TF1 *)f->Get("sat");
  TF1 *not_sat = (TF1 *)f->Get("not_sat");  

  TH1D *sat_b = (TH1D *)f->Get("sat_b");
  TH1D *not_sat_b = (TH1D *)f->Get("not_sat_b");  

  double threshold = -20./3500;
  double sat_tb = 0;
  double timex1 = 0;
  double timex2 = 0;
  bool start = false;
  bool endd = false;
  for(int i = 45; i < sat_b->GetNbinsX(); i++)
    {
      double adc = sat_b->GetBinContent(i);
      //      cout <<adc <<endl;
      if(adc < threshold && !start)
	{
	  sat_tb = i;
	  timex1 = i;
	  cout<<adc<<" time "<<timex1<<endl;
	  start = true;
	}
      if(adc > threshold && !endd)
	{
	  timex2 = i;
	  cout<<"time 2 "<<timex2<<endl;
	  endd = true;
	}
    }
      cout<<timex2 - timex1<<endl;
      if(!(timex2-timex1 > 8))
	sat_tb = 0;


      cout<<"Sat tb "<<sat_tb<<" "<<threshold<<endl;

  TGraph *sat_tb_point = new TGraph(1);
  sat_tb_point->SetPoint(0,sat_tb,-.0206);
  sat_tb_point->SetMarkerStyle(20);
  sat_tb_point->SetMarkerSize(2);
  sat_tb_point->SetMarkerColor(3);  

  TGraph *sat_mc_tb_point = new TGraph(1);
  sat_mc_tb_point->SetPoint(0,sat_tb-30,0);
  sat_mc_tb_point->SetMarkerStyle(20);
  sat_mc_tb_point->SetMarkerSize(2);
  sat_mc_tb_point->SetMarkerColor(2);  

  style::make(sat);
  style::make(not_sat);

  style::make(sat_b);
  style::make(not_sat_b);
 
  TCanvas *c1 = style::stdcvs();
  TCanvas *c2 = style::stdcvs("cvs_2",1000,500);
  TCanvas *c3 = style::stdcvs("cvs_3",1000,500);
  sat->SetLineWidth(6);
  not_sat->SetLineWidth(6);
  not_sat->SetLineStyle(9);

  sat_b->SetLineWidth(6);
  not_sat_b->SetLineWidth(6);
  not_sat_b->SetLineStyle(9);

  TLegend *leg = new TLegend(.5,.5,.92,.9);
  leg->AddEntry(sat,"Saturated Signal","L");
  leg->AddEntry(not_sat,"Normal Signal","L");
  leg->SetBorderSize(0);
  leg->SetFillColor(0);
  
  TLegend *leg2 = new TLegend(.5,.5,.92,.9);
  leg2->AddEntry(sat_b,"Saturated Signal Pole Zero","L");
  leg2->AddEntry(not_sat_b,"Normal Signal Pole Zero","L");
  leg2->AddEntry(sat_tb_point,"Saturated Tb","P");
  leg2->AddEntry(sat_mc_tb_point,"Saturated Embedding Threshold","P");
  leg2->SetBorderSize(0);
  leg2->SetFillColor(0);

  sat->SetNpx(10000);
  not_sat->SetNpx(10000);  

  sat->SetTitle("");
  sat->GetYaxis()->SetTitle("ADC");
  sat->GetXaxis()->SetTitle("Time bucket (Tb)");
  sat->GetYaxis()->CenterTitle();
  not_sat->GetYaxis()->SetTitle("ADC");
  not_sat->GetYaxis()->CenterTitle();
  not_sat->GetXaxis()->SetTitle("Time bucket (Tb)");

  not_sat->GetYaxis()->SetLabelSize(.06);
  sat->GetYaxis()->SetLabelSize(.06);
  not_sat->GetXaxis()->SetLabelSize(.06);
  sat->GetXaxis()->SetLabelSize(.06);

  not_sat->GetYaxis()->SetTitleSize(.06);
  sat->GetYaxis()->SetTitleSize(.06);
  not_sat->GetXaxis()->SetTitleSize(.06);
  sat->GetXaxis()->SetTitleSize(.06);
  
  sat->GetYaxis()->SetTitleOffset(.9);
  
  sat->GetXaxis()->CenterTitle();
  sat->GetYaxis()->CenterTitle();


  //  not_sat->GetXaxis()->SetRangeUser(0,60);
  not_sat_b->GetXaxis()->SetRangeUser(0,40);
 
  c1->cd();
  sat->GetXaxis()->SetRangeUser(0,100);
  sat->Draw();
  not_sat->Draw("same");
  sat_b->Draw("same L");
  not_sat_b->Draw("same L");
  leg->Draw();

  c1->SaveAs("pulseshape.jpg");
  c1->SaveAs("pulseshape.png");  

  c2->cd();
  sat->GetXaxis()->SetRangeUser(0,100);
  sat->Draw();
  not_sat->Draw("same");
  leg->Draw();

  auto sat_clone = (TF1 *)sat->Clone();
  auto not_sat_clone = (TF1 *)not_sat->Clone();  
  sat_clone->SetLineColor(kRed-9);
  not_sat_clone->SetLineColor(kRed-9);
  style::make(sat_clone);
  style::make(not_sat_clone);
  c2->SaveAs("satpulse.png");
  
  c3->cd();
  sat_clone->GetXaxis()->SetRangeUser(0,100);
  sat_clone->GetYaxis()->SetRangeUser(-.05,.2); 
  sat_clone->Draw();
  not_sat_clone->Draw("same");
  sat_b->Draw("same L");
  not_sat_b->Draw("same L");
  sat_tb_point->Draw("same PO");
  sat_mc_tb_point->Draw("same PO");
  leg2->Draw();

  c3->SaveAs("satpulsepz.png");
}
