


void plotVarBin_dr()
{
  double sigma_pim = .5*119/360; //119 is the fraction in phi                                            
  double sigma_pip = .5*117/360; 

  TFile *f = TFile::Open("./rootfiles/analysis-Sn132-finebin_08_31.root");
  TFile *g = TFile::Open("./rootfiles/analysis-Sn108-finebin_08_31.root");

  TFile *h = TFile::Open("./rootfiles/publishPions_sm.root");
  TH1D *sn132ratio = (TH1D *)h->Get("singleRatio_sn132");
  TH1D *sn108ratio = (TH1D *)h->Get("singleRatio_sn108");
  
  
  vector<double> bin1  = {0, 5, 10,15, 20, 25,  30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90, 95,  100, 110, 120, 130, 140, 150, 155, 160, 165, 170, 175, 180, 190, 200, 220, 240, 260, 300, 400}; 

  vector<double> bin2  = {0, 10, 20,  30, 40, 50, 60, 70, 80, 90,  100, 120, 130, 140, 150, 160, 170, 180, 190, 200, 220, 240, 260, 300,400}; 

  //  vector<double> bin3  = {0, 10, 20,  30, 40, 50, 60, 70, 80, 90,  100, 120, 130, 140, 150, 160, 170, 200, 240, 300, 400};   

  vector<double> bin3  = {0, 15, 30, 45, 60, 90, 120, 170, 240};   //prefered
  vector<double> bin4  = {0, 30, 60, 90, 120, 170, 240};   


  auto pim_fb_132 = (TH1D *)f->Get("pimkecm_ec");
  auto pip_fb_132 = (TH1D *)f->Get("pipkecm_ec");

  auto pim_fb_108 = (TH1D *)g->Get("pimkecm_ec");
  auto pip_fb_108 = (TH1D *)g->Get("pipkecm_ec");

  pim_fb_132->Scale(1./sigma_pim);
  pip_fb_132->Scale(1./sigma_pip);

  pim_fb_108->Scale(1./sigma_pim);
  pip_fb_108->Scale(1./sigma_pip);

  auto pim_bin1_132 = pim_fb_132->Rebin(bin1.size()-1,"pim_bin1",bin1.data());
  auto pip_bin1_132 = pip_fb_132->Rebin(bin1.size()-1,"pip_bin1",bin1.data());

  auto pim_bin2_132 = pim_fb_132->Rebin(bin2.size()-1,"pim_bin2",bin2.data());
  auto pip_bin2_132 = pip_fb_132->Rebin(bin2.size()-1,"pip_bin2",bin2.data());

  auto pim_bin3_132 = pim_fb_132->Rebin(bin3.size()-1,"pim_bin3",bin3.data());
  auto pip_bin3_132 = pip_fb_132->Rebin(bin3.size()-1,"pip_bin3",bin3.data());

  auto pim_bin4_132 = pim_fb_132->Rebin(bin4.size()-1,"pim_bin4",bin4.data());
  auto pip_bin4_132 = pip_fb_132->Rebin(bin4.size()-1,"pip_bin4",bin4.data());

  auto pim_bin1_108 = pim_fb_108->Rebin(bin1.size()-1,"pim_bin1",bin1.data());
  auto pip_bin1_108 = pip_fb_108->Rebin(bin1.size()-1,"pip_bin1",bin1.data());

  auto pim_bin2_108 = pim_fb_108->Rebin(bin2.size()-1,"pim_bin2",bin2.data());
  auto pip_bin2_108 = pip_fb_108->Rebin(bin2.size()-1,"pip_bin2",bin2.data());

  auto pim_bin3_108 = pim_fb_108->Rebin(bin3.size()-1,"pim_bin3",bin3.data());
  auto pip_bin3_108 = pip_fb_108->Rebin(bin3.size()-1,"pip_bin3",bin3.data());

  auto pim_bin4_108 = pim_fb_108->Rebin(bin4.size()-1,"pim_bin4",bin4.data());
  auto pip_bin4_108 = pip_fb_108->Rebin(bin4.size()-1,"pip_bin4",bin4.data());

  pim_fb_132->Divide(pip_fb_132);
  pim_bin1_132->Divide(pip_bin1_132);
  pim_bin2_132->Divide(pip_bin2_132);
  pim_bin3_132->Divide(pip_bin3_132);
  pim_bin4_132->Divide(pip_bin4_132);
  
  pim_fb_108->Divide(pip_fb_108);
  pim_bin1_108->Divide(pip_bin1_108);
  pim_bin2_108->Divide(pip_bin2_108);
  pim_bin3_108->Divide(pip_bin3_108);
  pim_bin4_108->Divide(pip_bin4_108);

  pim_fb_132->Divide(pim_fb_108);
  pim_bin1_132->Divide(pim_bin1_108);
  pim_bin2_132->Divide(pim_bin2_108);
  pim_bin3_132->Divide(pim_bin3_108);
  pim_bin4_132->Divide(pim_bin4_108);

  pim_bin1_132->SetLineColor(2);
  pim_bin2_132->SetLineColor(3);
  pim_bin3_132->SetLineColor(6);
  pim_bin4_132->SetLineColor(2);
    
  pim_bin1_132->SetLineWidth(4);
  pim_bin2_132->SetLineWidth(4);
  pim_bin3_132->SetLineWidth(4);
  pim_bin4_132->SetLineWidth(4);
  
  sn132ratio->Divide(sn108ratio);
  
  TCanvas *c1 = new TCanvas("c1","c1",1);
  c1->SetLogy();
  pim_fb_132->GetYaxis()->SetRangeUser(.5,20);
  //  pim_fb_132->Draw();
  //    pim_bin1_132->Draw();
  //    pim_bin2_132->Draw("same");
    pim_bin3_132->Draw();
  //  pim_bin4_132->Draw();
  //  sn132ratio->Draw("same");

  for(int i = 1; i <= pim_bin3_132->GetNbinsX(); i++)
    cout<<pim_bin3_132->GetBinCenter(i)<<",";
  cout<<endl;
  for(int i = 1; i <= pim_bin3_132->GetNbinsX(); i++)
    cout<<pim_bin3_132->GetBinContent(i)<<",";
  cout<<endl;
  for(int i = 1; i <= pim_bin3_132->GetNbinsX(); i++)
    cout<<pim_bin3_132->GetBinError(i)<<",";
  cout<<endl;

}
