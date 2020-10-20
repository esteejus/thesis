


void plotVarBin_dr()
{
  double sigma_pim = .5*119/360; //119 is the fraction in phi                                            
  double sigma_pip = .5*117/360; 

 TFile *f = TFile::Open("/home/justin/mythesis/macrosForThesis/PionSpectra/rootfiles/analysis-Sn132-finebin_pt_09_11.root");
 TFile *g = TFile::Open("/home/justin/mythesis/macrosForThesis/PionSpectra/rootfiles/analysis-Sn108-finebin_pt_09_11.root");

 vector<double> bin = {0, 20, 40, 60 , 80, 100, 120, 140, 160, 180, 200, 220, 240, 280, 320, 450}; // bestw

  auto pim_fb_132 = (TH1D *)f->Get("pimpt_ec");
  auto pip_fb_132 = (TH1D *)f->Get("pippt_ec");

  auto pim_fb_108 = (TH1D *)g->Get("pimpt_ec");
  auto pip_fb_108 = (TH1D *)g->Get("pippt_ec");

  pim_fb_132->Scale(1./sigma_pim);
  pip_fb_132->Scale(1./sigma_pip);

  pim_fb_108->Scale(1./sigma_pim);
  pip_fb_108->Scale(1./sigma_pip);

  auto pim_bin_132 = pim_fb_132->Rebin(bin.size()-1,"pim_bin",bin.data());
  auto pip_bin_132 = pip_fb_132->Rebin(bin.size()-1,"pip_bin",bin.data());

  auto pim_bin_108 = pim_fb_108->Rebin(bin.size()-1,"pim_bin",bin.data());
  auto pip_bin_108 = pip_fb_108->Rebin(bin.size()-1,"pip_bin",bin.data());

  pim_fb_132->Divide(pip_fb_132);
  pim_bin_132->Divide(pip_bin_132);

  pim_fb_108->Divide(pip_fb_108);
  pim_bin_108->Divide(pip_bin_108);

  pim_fb_132->Divide(pim_fb_108);
  pim_bin_132->Divide(pim_bin_108);
  
  TCanvas *c1 = new TCanvas("c1","c1",1);
  //  c1->SetLogy();
  pim_fb_132->GetYaxis()->SetRangeUser(.5,20);
  //  pim_fb_132->Draw();
  //    pim_bin1_132->Draw();
  //    pim_bin2_132->Draw("same");
  pim_bin_132->Draw();
  //    pim_bin_108->Draw();
  //  pim_bin4_132->Draw();
  //  sn132ratio->Draw("same");

  for(int i = 1; i <= pim_bin_132->GetNbinsX(); i++)
    cout<<pim_bin_132->GetBinCenter(i)<<",";
  cout<<endl;
  for(int i = 1; i <= pim_bin_132->GetNbinsX(); i++)
    cout<<pim_bin_132->GetBinContent(i)<<",";
  cout<<endl;
  for(int i = 1; i <= pim_bin_132->GetNbinsX(); i++)
    cout<<pim_bin_132->GetBinError(i)<<",";
  cout<<endl;

}
