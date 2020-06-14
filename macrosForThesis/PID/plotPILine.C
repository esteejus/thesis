
auto mpi = 139.57018;
auto me = 0.5109989461;
auto mp = 938.2720813;
auto mn = 939.565346;
auto md = 1875.612762;
auto mt = 2808.921112;
auto mhe3 = 2808.39132;
auto mal = 3727.379378;

Double_t particleMass = mpi; // Select particle you'll going to analyze                            

Double_t dedxModelFunc(Double_t *x, Double_t *p) {
  if (x[0] < 0)
    x[0] = -x[0];

  const Double_t m = particleMass;
  Double_t totalE = TMath::Sqrt(m*m + x[0]*x[0]);
  Double_t beta = x[0]/totalE;
  Double_t gamma = 1./TMath::Sqrt(1 - beta*beta);

  Double_t betaP3 = TMath::Power(beta, p[3]);

  return p[0]/betaP3*(p[1] - betaP3 + TMath::Log(p[2] + TMath::Power(1./(beta*gamma), p[4])));
}

void plotPILine()
{

  TFile *f = TFile::Open("histPID-merged_sn132.root");

  auto c1 = (TCanvas *)f->Get("c5");

  auto pip = new TF1("pip", dedxModelFunc, 25., 550., 5, 1);
  pip -> SetParameters( 0.0305075     , 513.643  ,6.70773e-46    ,  2.34166  ,   -101.122);

  auto pim = new TF1("pim", dedxModelFunc, -650., -25., 5, 1);
  pim -> SetParameters( 0.0305075     , 513.643  ,6.70773e-46    ,  2.34166  ,   -101.122);

  /*
  auto hist = (TH2D *)f->Get("histPIDCharged");

  TCanvas *c1 = new TCanvas("c1","c1",1);
  c1->SetLeftMargin(.15);
  c1->SetLogz();
   hist -> Draw("col");

*/
  c1->Draw();
  pim->Draw("same");
  pip->Draw("same");

}
