auto me = 0.5109989461;                                                                                
auto mp = 938.2720813;                                                                                 
auto mn = 939.565346;                                                                                  
auto md = 1875.612762;                                                                                 
auto mt = 2808.921112;                                                                                 
auto mhe3 = 2808.39132;                                                                                
auto mal = 3727.379378;

void particleCalib()
{
  double max = 2000;
  
  TF1 *p_const = new TF1("p_const","TMath::Exp([0])",0,max);
  p_const->SetParameter(0,-.17377);

  TF1 *p_lin = new TF1("p_lin","TMath::Exp([0] + [1]*x)",0,max);
  p_lin->SetParameters(-.05823,-1.78728e-4);

  TF1 *d_lin = new TF1("d_lin","TMath::Exp([0] + [1]*x)",0,max);
  d_lin->SetParameters(-.0487855,-1.68159e-4);

  TF1 *t_lin = new TF1("t_lin","TMath::Exp([0] + [1]*x)",0,max);
  t_lin->SetParameters(-.0715918,-1.20368e-4);

  TF1 *he3_lin = new TF1("he3_lin","TMath::Exp([0] + [1]*x)",0,max);
  he3_lin->SetParameters(-.0486119,-1.137e-4);

  TF1 *he4_lin = new TF1("he4_lin","TMath::Exp([0] + [1]*x)",0,max);
  he4_lin->SetParameters(-.0628344,-1.05124e-4);

  p_lin->SetLineColor(kRed);
  d_lin->SetLineColor(kRed-4);
  t_lin->SetLineColor(kRed-7);  
  he3_lin->SetLineColor(kRed-9);
  he4_lin->SetLineColor(kRed-10);
  
  p_lin->Draw();
  d_lin->Draw("same");
  t_lin->Draw("same");
  he3_lin->Draw("same");
  he4_lin->Draw("same");

}
