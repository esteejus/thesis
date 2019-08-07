void example_polya()
{
  TFile *f = TFile::Open("./1214rootfiles/aval_merge_1214V.root");
  //  TFile *f = TFile::Open("./1214rootfiles/aval_merge_1214V.root");
  TH1F *gain = (TH1F *)f->Get("gain");  
  gain->Rebin(60);

  //gain->Draw();

  int num_bins = gain->GetXaxis()->GetNbins();
  double mean = gain->GetMean();
  //  double norm = gain->Integral(0,num_bins,"width");
  TGraph *polya_e = new TGraph(num_bins);
  for(int i = 0; i<num_bins; i++)
    polya_e->SetPoint(i,gain->GetBinCenter(i)/mean,gain->GetBinContent(i));

  double norm = polya_e->Integral(0,100);
  //  cout<<"Final integral "<<polya_e->Integral(0,100);

  for(int i = 0; i<num_bins; i++)
    {
      double x,y;
      polya_e->GetPoint(i,x,y);
      polya_e->SetPoint(i,x,y/norm);
    }
  cout<<"Final integral "<<polya_e->Integral(0,100)<<endl;
  polya_e->GetXaxis()->SetRangeUser(0,8);
  gain->Scale(1./gain->Integral("width"));
  gain->GetXaxis()->SetRangeUser(0,6000);
  gain->Draw();
  //  polya_e->Draw();

  TF1 * polya = new TF1("polya","[0]*(pow([1],[1])/TMath::Gamma([1]))*pow(x,[1]-1)*exp(-[1]*x)",0,10);
  polya->SetParameter(0,1);
  polya->SetParameter(1,1/.7);
  //  polya->Draw("same");

  TF1 *polya_lowgain = new TF1("polya_lowgain","(1/104.48)*(pow(1.41,1.41)/TMath::Gamma(1.41))*pow(x/1\
04.48,1.41-1)*exp(-1.41*(x/104.48))",0,10000);

  
 TF1 * polya_n = new TF1("polya_n","(1/[0])*(pow([1],[1])/TMath::Gamma([1]))*pow(x/[0],[1]-1)*exp(-[1]*(x/[0]))",0,10000);
 //  polya_n->FixParameter(0,1024.);
  polya_n->SetParameter(0,152.6);
  polya_n->SetParameter(1,1/.71);
  //  polya_n->Draw("same");
  cout<<"Mean "<<polya_n->Mean(0,10000)<<endl;

  //  polya_lowgain->Draw("same");
  gain->Fit(polya_n);
  
  /*  
  TF1 *polya = new TF1("polya","[0]*ROOT::Math::negative_binomial_pdf(x,[1],[2])",0,10);
  polya->FixParameter(0,1.);
  polya->SetParameter(1,.8);
  polya->SetParameter(2,2);

  polya->SetLineColor(2);
  polya->SetNpx(100000);
  */

  
   //polya_e->Fit(polya);
  
  /*int num_el = 1000;
  double est_mean = num_el*mean;
  TH1D *test = new TH1D("test ","Test",20000,0,10000000);
  for(int i = 0; i< 1e5; i++)
    {
      double gain_v = 0; 
      for(int ie = 0; ie < num_el ; ie++)
	gain_v += gain -> GetRandom();

      test->Fill(gain_v);
    }
  test->Fit("gaus");
  test->Draw();
  */
  return;
}
