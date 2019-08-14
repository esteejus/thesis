#include "/home/justin/mythesis/thesis_style.h"

void openBeamFile(string filename, vector<double> &xx, vector<double> &yy, vector<double> &zz)
{
 string line;
  ifstream file(filename);
  while(getline(file,line))
    {
      stringstream sstring(line);
      double x,y,z;
      sstring >> x >> y >> z;
      xx.push_back(x/10.);
      yy.push_back(y/10.);
      zz.push_back(z/10.); //convert to cm
    }
}

void getBeamPath()
{
  vector<double> x_132, y_132, z_132;
  vector<double> x_108, y_108, z_108;
  vector<double> x_124, y_124, z_124;
  vector<double> x_112, y_112, z_112;
      
  openBeamFile("_132Sn_BeamTrack.data",x_132,y_132,z_132);
  TGraph *beam_132 = new TGraph(x_132.size(), z_132.data(),x_132.data());
  beam_132 -> GetYaxis()->SetRangeUser(-43.2,43.2);
  beam_132 -> GetXaxis()->SetRangeUser(0,132);

  openBeamFile("_108Sn_BeamTrack.data",x_108,y_108,z_108);
  TGraph *beam_108 = new TGraph(x_108.size(), z_108.data(),x_108.data());
  beam_108 -> GetYaxis()->SetRangeUser(-43.2,43.2);
  beam_108 -> GetXaxis()->SetRangeUser(0,108);

  openBeamFile("_124Sn_BeamTrack.data",x_124,y_124,z_124);
  TGraph *beam_124 = new TGraph(x_124.size(), z_124.data(),x_124.data());
  beam_124 -> GetYaxis()->SetRangeUser(-43.2,43.2);
  beam_124 -> GetXaxis()->SetRangeUser(0,124);

  openBeamFile("_112Sn_BeamTrack.data",x_112,y_112,z_112);
  TGraph *beam_112 = new TGraph(x_112.size(), z_112.data(),x_112.data());
  beam_132 -> GetYaxis()->SetRangeUser(-14,1);
  beam_132 -> GetXaxis()->SetRangeUser(0,112);
  beam_132 -> GetYaxis()->SetTitle("x (cm)");
  beam_132 -> GetXaxis()->SetTitle("z (cm)");

  TCanvas *c1 = style::stdcvs();
  style::make(beam_132);
  style::make(beam_108);
  style::make(beam_112);
  style::make(beam_124);

  beam_132 -> SetLineWidth(5);
  beam_108 -> SetLineWidth(5);
  beam_112 -> SetLineWidth(5);
  beam_124 -> SetLineWidth(5);

  beam_132 -> SetLineColor(kRed + 3);
  beam_124 -> SetLineColor(kRed - 2);
  beam_112 -> SetLineColor(kRed - 6);
  beam_108 -> SetLineColor(kRed - 9);

  TLegend *leg = new TLegend(.2,.2,.5,.6);
  leg->AddEntry(beam_132,"{}^{132}Sn","l");
  leg->AddEntry(beam_124,"{}^{124}Sn","l");
  leg->AddEntry(beam_112,"{}^{112}Sn","l");
  leg->AddEntry(beam_108,"{}^{108}Sn","l");
      
  beam_132 -> Draw("ALO");
  beam_108 -> Draw("same LO");
  beam_112 -> Draw("same LO");
  beam_124 -> Draw("same LO");
  leg->SetBorderSize(0);
  leg->Draw("same");

  c1->SaveAs("beampath.png");
  //  TF1 *beampath = new TF1("beampath","[0] + [1]*x + [2]*pow(x,2)",0,130); 
  //  beampath->SetParameters(-0.0685578,-0.046186, -0.000395632);
  //  beampath->SetParameters(-0.685578,-0.046186,-3.95632e-05);
  //  beam_132->Fit(beampath);
  //  beampath->Draw("same");


}
