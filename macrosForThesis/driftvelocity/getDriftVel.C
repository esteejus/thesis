#include <iostream>
#include <fstream>

#include "TCanvas.h"
#include "TROOT.h"
#include "TMath.h"
#include "TFile.h"
#include "TH3D.h"
#include "DriftLineRKF.hh"
#include "ComponentUser.hh"


#include "ViewField.hh"
#include "ComponentAnalyticField.hh"
#include "MediumMagboltz.hh"
#include "SolidTube.hh"
#include "SolidBox.hh"
#include "GeometrySimple.hh"
#include "Sensor.hh"
#include "AvalancheMC.hh"
#include "AvalancheMicroscopic.hh"
#include "TrackHeed.hh"
#include "Random.hh"
#include "Plotting.hh"
#include <sys/stat.h>
#include <sys/types.h>

using namespace std;
using namespace Garfield;


TGraph *make(TGraph *h)
{
  int fICvs=0;
  int fWCvs=6000;
  int fHCvs=4000;

  double fWUnit=0.006;
  double fHUnit=0.035;

  double fWStat=0.25;
  double fHStat=0.18;
  double fXStat=0.95;
  double fYStat=0.88;

  double fTMargin=0.01;
  double fBMargin=0.305;
  double fLMargin=0.12;
  double fRMargin=0.12;
  double fRMarginH1=0.03;
  double fRMarginH2=0.155;

  double fMainTitleSize=0.08;
  double fAxisLabelSize=0.05;
  double fAxisTitleSize=0.05;
  double fXTitleOffset=.9;
  double fYTitleOffset=.8;
  h->SetTitle("");
  h->GetXaxis()->CenterTitle();
  h->GetXaxis()->SetTitleOffset(fXTitleOffset);
  h->GetXaxis()->SetTitleSize(fAxisTitleSize);
  h->GetXaxis()->SetLabelSize(fAxisLabelSize);
  h->GetYaxis()->CenterTitle();
  h->GetYaxis()->SetTitleOffset(fYTitleOffset);
  h->GetYaxis()->SetTitleSize(fAxisTitleSize);
  h->GetYaxis()->SetLabelSize(fAxisLabelSize);

  return h;
}

int main(int argc, char *argv[])
{
  MediumMagboltz* gas = new MediumMagboltz();
  //gas->LoadGasFile("ar-90-ch4-10-exb.gas"); //for electrons
  //  gas->LoadGasFile("Ar90methane10_bfield.5T.gas"); //for electronsw
  //  if(!gas->LoadGasFile("ar-90-ch4-10-forplot.gas")) //for electrons
  if(!gas->LoadGasFile("ar-90-ch4-10-exb_highprec.gas")) //for electrons
    return 0;
  gas->SetComposition("ar",90.0,"ch4",10.0);
  gas->SetTemperature(293.15);
  gas->SetPressure(760.);
  const std::string path = getenv("GARFIELD_HOME");
  gas->LoadIonMobility(path + "/Data/IonMobility_Ar+_Ar.txt");
  cout<<"Garfiled path "<<path<<endl;

  double B_y = 0;  

  double vx = 0;
  double vy = 0;
  double vz = 0;

  int np = 1e3;
  double emax = 1e3;
  double emin = .01;
  double estep = (emax - emin)/np;
  TGraph *e_driftvel = new TGraph(np);
  for(int i = 0; i < np; i++)
    {
      double efield = i * estep + emin;
       gas->ElectronVelocity(0,efield,0,0,B_y,0,vx,vy,vz); //convert cm/ns to cm/us
	vy *= 1e3;
	e_driftvel -> SetPoint(i,efield,abs(vy));
    }
  
  double i_vx, i_vy, i_vz;

  TGraph *i_driftvel = new TGraph(np);
  for(int i = 0; i < np; i++)
    {
      double efield = i * estep + emin;
       gas->IonVelocity(0,efield,0,0,B_y,0,i_vx,i_vy,i_vz); //convert cm/ns to cm/us
	i_vy *= 1e3 * .2e4;
	i_driftvel -> SetPoint(i,efield,abs(i_vy));
    }

  double E_y = -127.4;
  gas->ElectronVelocity(0,E_y,0,0,B_y,0,vx,vy,vz); //convert cm/ns to cm/us
  vy *= 1e3;
  cout<<"Our drift velocity is "<<vy<<endl;

  TFile *outf = new TFile("gasplots.root","RECREATE");
  
  TCanvas *c1 = new TCanvas("c1","c1",1);
  c1->SetFrameLineWidth(4);
  gStyle->SetLineWidth(4);
  e_driftvel->GetYaxis()->SetTitle("Drift Velocity (cm/#mus)");
  e_driftvel->GetXaxis()->SetTitle("E-field (V/cm)");
  e_driftvel->SetName("e_driftvel");
  //  e_driftvel = make(e_driftvel);
  e_driftvel->SetLineColor(2);
  e_driftvel->SetLineWidth(4);
  e_driftvel->Draw();
  //  c1->SetLogx();
  //  i_driftvel->Draw("same");
  c1->SaveAs("efield_drift.png");

  e_driftvel->Write();
  outf->Close();
  
  return 0;
}
