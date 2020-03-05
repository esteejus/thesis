void test()
{
//=========Macro generated from canvas: cvs/cvs
//=========  (Mon Feb 24 18:44:50 2020) by ROOT version 6.13/02

   gStyle->SetCanvasPreferGL(kTRUE);

   TCanvas *cvs = new TCanvas("cvs", "cvs",100,64,1500,1000);
   gStyle->SetOptStat(0);
   cvs->Range(-35.12195,-0.511751,257.561,0.993399);
   cvs->SetFillColor(0);
   cvs->SetBorderMode(0);
   cvs->SetBorderSize(2);
   cvs->SetLogy();
   cvs->SetLeftMargin(0.12);
   cvs->SetRightMargin(0.06);
   cvs->SetTopMargin(0.06);
   cvs->SetBottomMargin(0.14);
   cvs->SetFrameLineWidth(10);
   cvs->SetFrameBorderMode(0);
   cvs->SetFrameLineWidth(10);
   cvs->SetFrameBorderMode(0);
   Double_t xAxis1[7] = {0, 30, 60, 90, 120, 170, 240}; 
   
   TH1D *singleRatio_sn108__1 = new TH1D("singleRatio_sn108__1","",6, xAxis1);
   singleRatio_sn108__1->SetBinContent(1,7.120791);
   singleRatio_sn108__1->SetBinContent(2,2.282283);
   singleRatio_sn108__1->SetBinContent(3,1.311681);
   singleRatio_sn108__1->SetBinContent(4,0.9909349);
   singleRatio_sn108__1->SetBinContent(5,0.8208762);
   singleRatio_sn108__1->SetBinContent(6,0.6800425);
   singleRatio_sn108__1->SetBinContent(7,0.8924082);
   singleRatio_sn108__1->SetBinError(1,0.2198919);
   singleRatio_sn108__1->SetBinError(2,0.04890967);
   singleRatio_sn108__1->SetBinError(3,0.03067687);
   singleRatio_sn108__1->SetBinError(4,0.02925379);
   singleRatio_sn108__1->SetBinError(5,0.02937922);
   singleRatio_sn108__1->SetBinError(6,0.0422841);
   singleRatio_sn108__1->SetBinError(7,0.1593297);
   singleRatio_sn108__1->SetMinimum(0.5);
   singleRatio_sn108__1->SetMaximum(8);
   singleRatio_sn108__1->SetEntries(3160.109);
   singleRatio_sn108__1->SetLineWidth(5);
   singleRatio_sn108__1->SetMarkerStyle(21);
   singleRatio_sn108__1->SetMarkerSize(2);
   singleRatio_sn108__1->GetXaxis()->SetTitle("E_{#scale[.6]{COM}} (MeV)");
   singleRatio_sn108__1->GetXaxis()->CenterTitle(true);
   singleRatio_sn108__1->GetXaxis()->SetNdivisions(505);
   singleRatio_sn108__1->GetXaxis()->SetLabelFont(42);
   singleRatio_sn108__1->GetXaxis()->SetLabelSize(0.06);
   singleRatio_sn108__1->GetXaxis()->SetTitleSize(0.06);
   singleRatio_sn108__1->GetXaxis()->SetTitleOffset(1.1);
   singleRatio_sn108__1->GetXaxis()->SetTitleFont(42);
   singleRatio_sn108__1->GetYaxis()->SetTitle("#pi^{-}/#pi^{+}");
   singleRatio_sn108__1->GetYaxis()->CenterTitle(true);
   singleRatio_sn108__1->GetYaxis()->SetLabelFont(42);
   singleRatio_sn108__1->GetYaxis()->SetLabelSize(0.06);
   singleRatio_sn108__1->GetYaxis()->SetTitleSize(0.06);
   singleRatio_sn108__1->GetYaxis()->SetTitleOffset(0.9);
   singleRatio_sn108__1->GetYaxis()->SetTitleFont(42);
   singleRatio_sn108__1->GetZaxis()->SetLabelFont(42);
   singleRatio_sn108__1->GetZaxis()->SetLabelSize(0.06);
   singleRatio_sn108__1->GetZaxis()->SetTitleSize(0.035);
   singleRatio_sn108__1->GetZaxis()->SetTitleFont(42);
   singleRatio_sn108__1->Draw("L E1");
   
   Double_t Graph0_fx1001[7] = {
   15,
   45,
   75,
   105,
   145,
   205,
   270};
   Double_t Graph0_fy1001[7] = {
   6.728772,
   2.41744,
   1.485701,
   1.214191,
   1.04867,
   0.8655765,
   0.7790388};
   Double_t Graph0_fex1001[7] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t Graph0_fey1001[7] = {
   1.284328,
   0.09276438,
   0.1031876,
   0.09740294,
   0.08746317,
   0.08153891,
   0.07660969};
   TGraphErrors *gre = new TGraphErrors(7,Graph0_fx1001,Graph0_fy1001,Graph0_fex1001,Graph0_fey1001);
   gre->SetName("Graph0");
   gre->SetTitle("Graph");

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = 1184;
   color = new TColor(ci, 1, 0.4, 0.4, " ", 0.5);
   gre->SetFillColor(ci);
   gre->SetFillStyle(1);

   ci = TColor::GetColor("#ff6666");
   gre->SetLineColor(ci);
   gre->SetLineStyle(10);
   gre->SetLineWidth(10);

   ci = TColor::GetColor("#ff6666");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(32);
   gre->SetMarkerSize(3);
   
   TH1F *Graph_Graph01001 = new TH1F("Graph_Graph01001","Graph",100,0,295.5);
   Graph_Graph01001->SetMinimum(0.6321862);
   Graph_Graph01001->SetMaximum(8.744168);
   Graph_Graph01001->SetDirectory(0);
   Graph_Graph01001->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph01001->SetLineColor(ci);
   Graph_Graph01001->GetXaxis()->SetLabelFont(42);
   Graph_Graph01001->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph01001->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph01001->GetXaxis()->SetTitleFont(42);
   Graph_Graph01001->GetYaxis()->SetLabelFont(42);
   Graph_Graph01001->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph01001->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph01001->GetYaxis()->SetTitleOffset(0);
   Graph_Graph01001->GetYaxis()->SetTitleFont(42);
   Graph_Graph01001->GetZaxis()->SetLabelFont(42);
   Graph_Graph01001->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph01001->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph01001->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph01001);
   
   gre->Draw("  le3 ");
   
   Double_t Graph1_fx1002[7] = {
   15,
   45,
   75,
   105,
   145,
   205,
   270};
   Double_t Graph1_fy1002[7] = {
   8.909677,
   1.873929,
   1.097167,
   0.9510403,
   0.8476146,
   0.6410241,
   0.5224172};
   Double_t Graph1_fex1002[7] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t Graph1_fey1002[7] = {
   0.9186057,
   0.1439286,
   0.09047077,
   0.04284354,
   0.01815722,
   0.01390547,
   0.003898635};
   gre = new TGraphErrors(7,Graph1_fx1002,Graph1_fy1002,Graph1_fex1002,Graph1_fey1002);
   gre->SetName("Graph1");
   gre->SetTitle("Graph");

   ci = 1182;
   color = new TColor(ci, 0, 1, 1, " ", 0.5);
   gre->SetFillColor(ci);
   gre->SetFillStyle(1);

   ci = TColor::GetColor("#00ffff");
   gre->SetLineColor(ci);
   gre->SetLineStyle(7);
   gre->SetLineWidth(10);

   ci = TColor::GetColor("#00ffff");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(26);
   gre->SetMarkerSize(3);
   
   TH1F *Graph_Graph11002 = new TH1F("Graph_Graph11002","Graph",100,0,295.5);
   Graph_Graph11002->SetMinimum(0.4666667);
   Graph_Graph11002->SetMaximum(10.75926);
   Graph_Graph11002->SetDirectory(0);
   Graph_Graph11002->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph11002->SetLineColor(ci);
   Graph_Graph11002->GetXaxis()->SetLabelFont(42);
   Graph_Graph11002->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph11002->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph11002->GetXaxis()->SetTitleFont(42);
   Graph_Graph11002->GetYaxis()->SetLabelFont(42);
   Graph_Graph11002->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph11002->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph11002->GetYaxis()->SetTitleOffset(0);
   Graph_Graph11002->GetYaxis()->SetTitleFont(42);
   Graph_Graph11002->GetZaxis()->SetLabelFont(42);
   Graph_Graph11002->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph11002->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph11002->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph11002);
   
   gre->Draw("  le3");
   
   Double_t Graph2_fx1003[7] = {
   15,
   45,
   75,
   105,
   145,
   205,
   270};
   Double_t Graph2_fy1003[7] = {
   5.12783,
   2.866301,
   1.89468,
   1.29724,
   1.123325,
   0.8738228,
   0.8288758};
   Double_t Graph2_fex1003[7] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t Graph2_fey1003[7] = {
   0.248676,
   0.02006295,
   0.08189428,
   0.05265163,
   0.06358466,
   0.05800467,
   0.09436826};
   gre = new TGraphErrors(7,Graph2_fx1003,Graph2_fy1003,Graph2_fex1003,Graph2_fey1003);
   gre->SetName("Graph2");
   gre->SetTitle("Graph");

   ci = 1180;
   color = new TColor(ci, 0.2, 0.2, 1, " ", 0.5);
   gre->SetFillColor(ci);
   gre->SetFillStyle(1);

   ci = TColor::GetColor("#3333ff");
   gre->SetLineColor(ci);
   gre->SetLineWidth(10);

   ci = TColor::GetColor("#3333ff");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(28);
   gre->SetMarkerSize(3);
   
   TH1F *Graph_Graph21003 = new TH1F("Graph_Graph21003","Graph",100,0,295.5);
   Graph_Graph21003->SetMinimum(0.2703076);
   Graph_Graph21003->SetMaximum(5.840706);
   Graph_Graph21003->SetDirectory(0);
   Graph_Graph21003->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph21003->SetLineColor(ci);
   Graph_Graph21003->GetXaxis()->SetLabelFont(42);
   Graph_Graph21003->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph21003->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph21003->GetXaxis()->SetTitleFont(42);
   Graph_Graph21003->GetYaxis()->SetLabelFont(42);
   Graph_Graph21003->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph21003->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph21003->GetYaxis()->SetTitleOffset(0);
   Graph_Graph21003->GetYaxis()->SetTitleFont(42);
   Graph_Graph21003->GetZaxis()->SetLabelFont(42);
   Graph_Graph21003->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph21003->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph21003->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph21003);
   
   gre->Draw("  le3 ");
   
   Double_t Graph3_fx1004[7] = {
   15,
   45,
   75,
   105,
   145,
   205,
   270};
   Double_t Graph3_fy1004[7] = {
   5.915687,
   3.525087,
   1.862948,
   1.328699,
   1.016741,
   0.7853862,
   0.7300872};
   Double_t Graph3_fex1004[7] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t Graph3_fey1004[7] = {
   0.148143,
   0.08637765,
   0.01543032,
   0.02370623,
   0.03227817,
   0.04724654,
   0.05660014};
   gre = new TGraphErrors(7,Graph3_fx1004,Graph3_fy1004,Graph3_fex1004,Graph3_fey1004);
   gre->SetName("Graph3");
   gre->SetTitle("Graph");

   ci = 1179;
   color = new TColor(ci, 1, 0.8, 0, " ", 0.5);
   gre->SetFillColor(ci);
   gre->SetFillStyle(1);

   ci = TColor::GetColor("#ffcc00");
   gre->SetLineColor(ci);
   gre->SetLineStyle(4);
   gre->SetLineWidth(10);

   ci = TColor::GetColor("#ffcc00");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(24);
   gre->SetMarkerSize(3);
   
   TH1F *Graph_Graph31004 = new TH1F("Graph_Graph31004","Graph",100,0,295.5);
   Graph_Graph31004->SetMinimum(0.1344528);
   Graph_Graph31004->SetMaximum(6.602864);
   Graph_Graph31004->SetDirectory(0);
   Graph_Graph31004->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph31004->SetLineColor(ci);
   Graph_Graph31004->GetXaxis()->SetLabelFont(42);
   Graph_Graph31004->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph31004->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph31004->GetXaxis()->SetTitleFont(42);
   Graph_Graph31004->GetYaxis()->SetLabelFont(42);
   Graph_Graph31004->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph31004->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph31004->GetYaxis()->SetTitleOffset(0);
   Graph_Graph31004->GetYaxis()->SetTitleFont(42);
   Graph_Graph31004->GetZaxis()->SetLabelFont(42);
   Graph_Graph31004->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph31004->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph31004->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph31004);
   
   gre->Draw("  le3");
   
   Double_t Graph4_fx1005[7] = {
   15,
   45,
   75,
   105,
   145,
   205,
   270};
   Double_t Graph4_fy1005[7] = {
   13.61775,
   2.323992,
   1.091518,
   0.8594962,
   0.7198933,
   0.5845102,
   0.5589248};
   Double_t Graph4_fex1005[7] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t Graph4_fey1005[7] = {
   0.1338632,
   0.0325904,
   0.02455357,
   0.0108742,
   0.01036004,
   0.01829658,
   0.01051967};
   gre = new TGraphErrors(7,Graph4_fx1005,Graph4_fy1005,Graph4_fex1005,Graph4_fey1005);
   gre->SetName("Graph4");
   gre->SetTitle("Graph");

   ci = 1183;
   color = new TColor(ci, 1, 0.6, 1, " ", 0.5);
   gre->SetFillColor(ci);
   gre->SetFillStyle(1);

   ci = TColor::GetColor("#ff99ff");
   gre->SetLineColor(ci);
   gre->SetLineStyle(9);
   gre->SetLineWidth(10);

   ci = TColor::GetColor("#ff99ff");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(30);
   gre->SetMarkerSize(3);
   
   TH1F *Graph_Graph41005 = new TH1F("Graph_Graph41005","Graph",100,0,295.5);
   Graph_Graph41005->SetMinimum(0.4935646);
   Graph_Graph41005->SetMaximum(15.07193);
   Graph_Graph41005->SetDirectory(0);
   Graph_Graph41005->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph41005->SetLineColor(ci);
   Graph_Graph41005->GetXaxis()->SetLabelFont(42);
   Graph_Graph41005->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph41005->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph41005->GetXaxis()->SetTitleFont(42);
   Graph_Graph41005->GetYaxis()->SetLabelFont(42);
   Graph_Graph41005->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph41005->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph41005->GetYaxis()->SetTitleOffset(0);
   Graph_Graph41005->GetYaxis()->SetTitleFont(42);
   Graph_Graph41005->GetZaxis()->SetLabelFont(42);
   Graph_Graph41005->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph41005->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph41005->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph41005);
   
   gre->Draw("  le3 ");
   Double_t xAxis2[7] = {0, 30, 60, 90, 120, 170, 240}; 
   
   TH1D *singleRatio_sn108_copy__2 = new TH1D("singleRatio_sn108_copy__2","",6, xAxis2);
   singleRatio_sn108_copy__2->SetBinContent(1,7.120791);
   singleRatio_sn108_copy__2->SetBinContent(2,2.282283);
   singleRatio_sn108_copy__2->SetBinContent(3,1.311681);
   singleRatio_sn108_copy__2->SetBinContent(4,0.9909349);
   singleRatio_sn108_copy__2->SetBinContent(5,0.8208762);
   singleRatio_sn108_copy__2->SetBinContent(6,0.6800425);
   singleRatio_sn108_copy__2->SetBinContent(7,0.8924082);
   singleRatio_sn108_copy__2->SetBinError(1,0.2198919);
   singleRatio_sn108_copy__2->SetBinError(2,0.04890967);
   singleRatio_sn108_copy__2->SetBinError(3,0.03067687);
   singleRatio_sn108_copy__2->SetBinError(4,0.02925379);
   singleRatio_sn108_copy__2->SetBinError(5,0.02937922);
   singleRatio_sn108_copy__2->SetBinError(6,0.0422841);
   singleRatio_sn108_copy__2->SetBinError(7,0.1593297);
   singleRatio_sn108_copy__2->SetMinimum(0.5);
   singleRatio_sn108_copy__2->SetMaximum(8);
   singleRatio_sn108_copy__2->SetEntries(3160.109);
   singleRatio_sn108_copy__2->SetDirectory(0);
   singleRatio_sn108_copy__2->SetLineWidth(5);
   singleRatio_sn108_copy__2->SetMarkerStyle(21);
   singleRatio_sn108_copy__2->SetMarkerSize(2);
   singleRatio_sn108_copy__2->GetXaxis()->SetTitle("E_{#scale[.6]{COM}} (MeV)");
   singleRatio_sn108_copy__2->GetXaxis()->CenterTitle(true);
   singleRatio_sn108_copy__2->GetXaxis()->SetNdivisions(505);
   singleRatio_sn108_copy__2->GetXaxis()->SetLabelFont(42);
   singleRatio_sn108_copy__2->GetXaxis()->SetLabelSize(0.06);
   singleRatio_sn108_copy__2->GetXaxis()->SetTitleSize(0.06);
   singleRatio_sn108_copy__2->GetXaxis()->SetTitleOffset(1.1);
   singleRatio_sn108_copy__2->GetXaxis()->SetTitleFont(42);
   singleRatio_sn108_copy__2->GetYaxis()->SetTitle("#pi^{-}/#pi^{+}");
   singleRatio_sn108_copy__2->GetYaxis()->CenterTitle(true);
   singleRatio_sn108_copy__2->GetYaxis()->SetLabelFont(42);
   singleRatio_sn108_copy__2->GetYaxis()->SetLabelSize(0.06);
   singleRatio_sn108_copy__2->GetYaxis()->SetTitleSize(0.06);
   singleRatio_sn108_copy__2->GetYaxis()->SetTitleOffset(0.9);
   singleRatio_sn108_copy__2->GetYaxis()->SetTitleFont(42);
   singleRatio_sn108_copy__2->GetZaxis()->SetLabelFont(42);
   singleRatio_sn108_copy__2->GetZaxis()->SetLabelSize(0.06);
   singleRatio_sn108_copy__2->GetZaxis()->SetTitleSize(0.035);
   singleRatio_sn108_copy__2->GetZaxis()->SetTitleFont(42);
   singleRatio_sn108_copy__2->Draw("same L E1");
   
   TLegend *leg = new TLegend(0.6715621,0.5594262,0.9712951,0.8596311,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(10);
   leg->SetFillColor(0);
   leg->SetFillStyle(0);
   TLegendEntry *entry=leg->AddEntry("Graph3","TuQMD","FL");

   ci = 1179;
   color = new TColor(ci, 1, 0.8, 0, " ", 0.5);
   entry->SetFillColor(ci);
   entry->SetFillStyle(1);

   ci = TColor::GetColor("#ffcc00");
   entry->SetLineColor(ci);
   entry->SetLineStyle(4);
   entry->SetLineWidth(10);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph1","ImQMD","FL");

   ci = 1182;
   color = new TColor(ci, 0, 1, 1, " ", 0.5);
   entry->SetFillColor(ci);
   entry->SetFillStyle(1);

   ci = TColor::GetColor("#00ffff");
   entry->SetLineColor(ci);
   entry->SetLineStyle(7);
   entry->SetLineWidth(10);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph2","#chiBUU","FL");

   ci = 1180;
   color = new TColor(ci, 0.2, 0.2, 1, " ", 0.5);
   entry->SetFillColor(ci);
   entry->SetFillStyle(1);

   ci = TColor::GetColor("#3333ff");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(10);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph4","AMD + JAM","FL");

   ci = 1183;
   color = new TColor(ci, 1, 0.6, 1, " ", 0.5);
   entry->SetFillColor(ci);
   entry->SetFillStyle(1);

   ci = TColor::GetColor("#ff99ff");
   entry->SetLineColor(ci);
   entry->SetLineStyle(9);
   entry->SetLineWidth(10);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph0","pBUU","FL");

   ci = 1184;
   color = new TColor(ci, 1, 0.4, 0.4, " ", 0.5);
   entry->SetFillColor(ci);
   entry->SetFillStyle(1);

   ci = TColor::GetColor("#ff6666");
   entry->SetLineColor(ci);
   entry->SetLineStyle(10);
   entry->SetLineWidth(10);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   leg = new TLegend(0.4145527,0.5553279,0.6648865,0.8555328,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(10);
   leg->SetFillColor(0);
   leg->SetFillStyle(0);
   entry=leg->AddEntry("singleRatio_sn108","{}^{108}Sn +{}^{112}Sn","lpe");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(5);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(2);
   entry->SetTextFont(42);
   leg->Draw();
   cvs->Modified();
   cvs->cd();
   cvs->SetSelected(cvs);
}
