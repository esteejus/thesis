
TH1D * GetHist(TGraph *graph)
{
   auto nPoints = graph->GetN(); // number of points in your TGraph

  vector<double> x_p,y_p;
  
  for(int i=0; i < nPoints; ++i)
    {
      double x,y;
      graph->GetPoint(i,x,y);

      x_p.push_back(x);
      y_p.push_back(y);
 }
  double bin_w = (x_p.at(1) - x_p.at(0))/2;
  double max = x_p.at(x_p.size()-1) + bin_w;
  double min = x_p.at(0) - bin_w;  

  TString name = graph->GetName();
  TH1D *h = new TH1D(name,name,nPoints,min,max);
  for(int i = 0; i < x_p.size(); i++)
      h->SetBinContent(i + 1,y_p.at(i));

  return h;  
}

void convert()
{
  TFile *f = TFile::Open("resonance_out.root");
  TFile *f_b = TFile::Open("output_Boltz.root");
  TGraph *g = (TGraph *)f->Get("f2fcn");
  TGraph *boltz15 = (TGraph *)f_b->Get("boltz_20");
  auto hist = GetHist(g);
  auto hist_b = GetHist(boltz15);
  //  g->Draw();
  hist->Scale(1./hist->Integral("width"));
    cout<<hist->Integral("width")<<endl;
  cout<<hist_b->Integral("width")<<endl;

  hist->Draw("hist");
  hist_b->Draw("same");
}
