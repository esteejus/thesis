


void plotSpectra(int run = 132)
{
  double sigma_pim = .5*119/360; //119 is the fraction in phi                                            
  double sigma_pip = .5*117/360; 

  double sn132_event = 414047;
  double sn108_event = 229770;


  TFile *g = TFile::Open("./rootfiles/publishPions_sm.root");
  TH1D *sn132ratio = (TH1D *)g->Get("pim_sn132");

  TFile *f = nullptr;

  if(run == 132)
    f = TFile::Open("./rootfiles/analysis-Sn132-finebin_08_31.root");
  else if(run == 108)
    f = TFile::Open("./rootfiles/analysis-Sn108-finebin_08_31.root");
  
  vector<double> bin1  = {0, 5, 10,15, 20, 25,  30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90, 95,  100, 110, 120, 130, 140, 150, 155, 160, 165, 170, 175, 180, 190, 200, 220, 240, 260, 300, 400}; 

  vector<double> bin2  = {0, 10, 20,  30, 40, 50, 60, 70, 80, 90,  100, 120, 130, 140, 150, 160, 170, 180, 190, 200, 220, 240, 260, 300,400}; 

  //  vector<double> bin3  = {0, 10, 20,  30, 40, 50, 60, 70, 80, 90,  100, 120, 130, 140, 150, 160, 170, 200, 240, 300, 400};   

  vector<double> bin3  = {0, 5, 10,15, 20, 25,  30, 40, 50, 60, 70, 80, 90,  100, 110, 120, 130, 140, 150, 160, 170, 200, 240, 300, 400};   

  vector<double> bin4  = {0, 30, 60, 90, 120, 170, 240};   


  auto pim_fb = (TH1D *)f->Get("pimkecm_ec");
  auto pip_fb = (TH1D *)f->Get("pipkecm_ec");

  if(run == 132)
    {
      pim_fb->Scale(1./sigma_pim/sn132_event,"width");
      pip_fb->Scale(1./sigma_pip/sn132_event,"width");
    }
  else if(run == 108)
    {
      pim_fb->Scale(1./sigma_pim/sn108_event,"width");
      pip_fb->Scale(1./sigma_pip/sn108_event,"width");
    }
    
  cout<<"mult "<<  pip_fb->Integral("width")<<endl;
  //  cout<<"mult "<<  sn132ratio ->Integral("width")<<endl;

  auto pim_bin1 = pim_fb->Rebin(bin1.size()-1,"pim_bin1",bin1.data());
  auto pip_bin1 = pip_fb->Rebin(bin1.size()-1,"pip_bin1",bin1.data());

  auto pim_bin2 = pim_fb->Rebin(bin2.size()-1,"pim_bin2",bin2.data());
  auto pip_bin2 = pip_fb->Rebin(bin2.size()-1,"pip_bin2",bin2.data());

  auto pim_bin3 = pim_fb->Rebin(bin3.size()-1,"pim_bin3",bin3.data());
  auto pip_bin3 = pip_fb->Rebin(bin3.size()-1,"pip_bin3",bin3.data());

  auto pim_bin4 = pim_fb->Rebin(bin4.size()-1,"pim_bin4",bin4.data());
  auto pip_bin4 = pip_fb->Rebin(bin4.size()-1,"pip_bin4",bin4.data());

  pim_bin1->Scale(1,"width");
  pim_bin2->Scale(1,"width");
  pim_bin3->Scale(1,"width");
  pim_bin4->Scale(1,"width");

  pip_bin1->Scale(1,"width");
  pip_bin2->Scale(1,"width");
  pip_bin3->Scale(1,"width");
  pip_bin4->Scale(1,"width");

  //  pim_bin2->Divide(pip_bin2);
  //  pim_bin3->Divide(pip_bin3);
  //  pim_bin4->Divide(pip_bin4);
  
  pim_bin1->SetLineColor(2);
  pim_bin2->SetLineColor(3);
  pim_bin3->SetLineColor(6);
  pim_bin4->SetLineColor(2);
    
  pim_bin1->SetLineWidth(4);
  pim_bin2->SetLineWidth(4);
  pim_bin3->SetLineWidth(4);
  pim_bin4->SetLineWidth(4);
  
  TCanvas *c1 = new TCanvas("c1","c1",1);
  c1->SetLogy();
  pim_fb->GetYaxis()->SetRangeUser(.5,20);
  sn132ratio->SetLineWidth(4);
  pim_bin3->GetXaxis()->SetRangeUser(0,300);

  //  pim_fb->Draw();
  //  pim_bin1->Draw();
  //  pim_bin2->Draw("same");
  pim_bin3->Draw();
  //  pim_bin4->Draw("same");
  sn132ratio->Draw("same");



  cout<<"Pim "<<endl;
 for(int i = 1; i <= pim_bin3->GetNbinsX(); i++)
    cout<<pim_bin3->GetBinCenter(i)<<",";
  cout<<endl;
  for(int i = 1; i <= pim_bin3->GetNbinsX(); i++)
    cout<<pim_bin3->GetBinContent(i)<<",";
  cout<<endl;
  for(int i = 1; i <= pim_bin3->GetNbinsX(); i++)
    cout<<pim_bin3->GetBinError(i)<<",";
  cout<<endl;
  
  cout<<endl;
  cout<<"Pip "<<endl;
 for(int i = 1; i <= pip_bin3->GetNbinsX(); i++)
    cout<<pip_bin3->GetBinCenter(i)<<",";
  cout<<endl;
  for(int i = 1; i <= pip_bin3->GetNbinsX(); i++)
    cout<<pip_bin3->GetBinContent(i)<<",";
  cout<<endl;
  for(int i = 1; i <= pip_bin3->GetNbinsX(); i++)
    cout<<pip_bin3->GetBinError(i)<<",";
  cout<<endl;


  
}
