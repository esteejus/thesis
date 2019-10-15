
TSpline3 *bp_spl;
TSpline3 *kp_spl;
TSpline3 *bm_spl;
TSpline3 *km_spl;

double ratio_fcn(double *x, double *par)
{
  double ke = x[0];
  double a = 132;
  double a_tar = 124;
  double z = 50 + 50;
  double r_o = 1.25; //fm
  double T = 4000; //temperature 
  
  double sigma_pip = kp_spl->Eval(ke)*pow(a+a_tar,bp_spl->Eval(ke));
  double sigma_pim = km_spl->Eval(ke)*pow(a+a_tar,bm_spl->Eval(ke));

  if(ke < 37 || ke > 280)
    sigma_pim = 0;

  double up_un = 1.44*z * (pow(2,2/3.) -1 )/( r_o*pow(a,1/3.) );


  //  return TMath::Exp(-2*up_un/T);
  return (sigma_pim/sigma_pip) * TMath::Exp(-2*up_un/T);
  //  return (sigma_pim/sigma_pip);
}




void plotThermalRatio()
{

  vector<double> b_plus = {.799  , .697 , .621  , .629  , .646  , .671  , .674  , .695 , .692   , .694};
  vector<double> k_plus = {12.11 , 24.5 , 36.35 , 37.76 , 35.06 , 32.26 , 32.09 , 28.1 , 24.24 , 22.4};
  vector<double> t_ke   = {37,52,68,83,100,125,151,187,233,280};

  vector<double> b_minus = {1, .833, .805, .78, .751, .731, .759, .793, .735, .765};
  vector<double> k_minus = {10.8, 22.12, 23.9, 25.64, 28.52, 29.43, 24.2, 17.46, 21.56, 16.12};


  cout<<b_plus.size()<<" "<<k_plus.size()<<" "<<t_ke.size()<<endl;
  cout<<b_minus.size()<<" "<<k_minus.size()<<endl;

  bp_spl = new TSpline3("bp_spl",t_ke.data(),b_plus.data(),t_ke.size());
  TGraph *bp_g = new TGraph(t_ke.size(),t_ke.data(),b_plus.data());

  kp_spl = new TSpline3("kp_spl",t_ke.data(),k_plus.data(),t_ke.size());
  TGraph *kp_g = new TGraph(t_ke.size(),t_ke.data(),k_plus.data());

  bm_spl = new TSpline3("bm_spl",t_ke.data(),b_minus.data(),t_ke.size());
  TGraph *bm_g = new TGraph(t_ke.size(),t_ke.data(),b_minus.data());

  km_spl = new TSpline3("kp_spl",t_ke.data(),k_minus.data(),t_ke.size());
  TGraph *km_g = new TGraph(t_ke.size(),t_ke.data(),k_minus.data());


 /*
  bp_g->SetMarkerStyle(20);
  bp_g->Draw("APO");
  bp_spl->Draw("same");

  
  kp_g->SetMarkerStyle(20);
  kp_g->Draw("APO");
  kp_spl->Draw("same");

  km_g->SetMarkerStyle(20);
  km_g->Draw("APO");
  km_spl->Draw("same");


  bm_g->SetMarkerStyle(20);
  bm_g->Draw("APO");
  bm_spl->Draw("same");
 */
  
  vector<double> ke_paper = {15,45,75,105,135,165,210,270};
  vector<double> ratio_pap= {14.2945774657025,5.30907736247361,3.63551146705497,2.6402078978948,2.28804216799197,1.78013423106001,1.33770550125454,1.0760035461724};


  TGraph *ratio_p = new TGraph(ke_paper.size(),ke_paper.data(),ratio_pap.data());
  ratio_p->SetMarkerStyle(20);
  
  TF1 *ratio = new TF1("ratio",ratio_fcn,0,300,0);
  ratio->Draw();
  ratio_p->Draw("same PO");

  cout<<"pu/pu "<<ratio->Eval(37)<<endl;

}
