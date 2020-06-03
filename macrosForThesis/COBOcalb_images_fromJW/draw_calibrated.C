void draw_calibrated()
{
  auto file1 = new TFile("overview_before_fix.root");
  auto file2 = new TFile("overview_after_fix.root");

  gStyle -> SetOptStat(0);

  for (auto ba : {0,1}) {
    TFile *file = file1;
    TString header = "before_";
    if (ba==1) {
      file = file2;
      header = "after_";
    }

    //for (auto ii : {1,2,4,5,6})
    for (auto ii : {1})
    {
      TString gname = Form("run2905_yoffset%d",ii);

      TString cname;
      TString title;
      if (ii==1) { cname = "all";   title = ";dy (mm);"; }
      if (ii==2) { cname = "layer"; title = ";dy (mm);layer"; }
      if (ii==4) { cname = "row_at_layer50";  title = "layer 50;dy (mm);row"; }
      if (ii==5) { cname = "row_at_layer30";  title = "layer 30;dy (mm);row"; }
      if (ii==6) { cname = "row_at_layer10";  title = "layer 10;dy (mm);row"; }

      auto cvs = new TCanvas(header+cname,header+cname,1000,1000);
      cvs->SetBottomMargin(.15);
      cvs->SetLeftMargin(.15);      
      cvs->SetRightMargin(.05);
      
      auto hist = (TH2D *) file -> Get(gname);
      hist -> SetNameTitle(header+cname,title);
      hist -> GetXaxis()->SetTitle("dy (mm)");

      if(ii >= 4)
	{
	  hist -> GetYaxis()->SetTitle("Row");
	  hist -> GetYaxis()->SetTitleOffset(1.1);
	}
      else if( ii == 1)
	{
	  hist -> GetYaxis()->SetTitle("# Clusters");
	  hist -> GetYaxis()->SetTitleOffset(1.1);
	  hist->SetLineWidth(4);
	}
      
      hist -> Draw("col");

      //      cvs->SetRightMargin(.15);
      //      hist -> Draw("colz");

      cvs -> Draw();
      cvs->SaveAs(gname + header+cname + ".png");
    }
  }
}
