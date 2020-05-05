#include "/home/justin/mythesis/thesis_style.h"

using namespace style;

void publishgasplots()
{

  TFile *inf = new TFile("gasplots.root","UPDATE");
  TGraph *e_drift = (TGraph *)inf->Get("e_driftvel");
  e_drift->GetXaxis()->SetTitle("#varepsilon (V/cm/Torr)");
  style::save(e_drift,"test.png");

}
