

void plotDanData()
{

  TFile *sn132_f = TFile::Open("Cozma_132.root");
  TFile *sn108_f = TFile::Open("Cozma_108.root");


  vector<int> sim_c = {kGreen,kGreen,kGreen,kBlue,kBlue,kBlue,kRed,kRed,kRed};
  vector<int> sim_ls = {6,7,1,6,7,1,6,7,1};
  vector<int> sim_lw = {4,4,4,4,4,4,4,4,4};

  TH1D *sn132_ratio_vec[9];
  TH1D *sn108_ratio_vec[9];
  TH1D *double_ratio_vec[9];

  TCanvas *c1 = new TCanvas("c1","c1",1);
  TCanvas *c2 = new TCanvas("c2","c2",1);
  TCanvas *c3 = new TCanvas("c3","c3",1);
  
  for(int i = 0; i < 9; i++)
    {
      cout<<i<<endl;
      sn132_ratio_vec[i] = (TH1D *)sn132_f->Get(Form("sim%d_ratio",i+1));
      sn108_ratio_vec[i] = (TH1D *)sn108_f->Get(Form("sim%d_ratio",i+1));

      /*
      sn132_ratio_vec[i]->Smooth();
      sn108_ratio_vec[i]->Smooth();
      */
       
      sn132_ratio_vec[i] -> SetLineWidth(sim_lw[i]);
      sn132_ratio_vec[i] -> SetLineStyle(sim_ls[i]);
      sn132_ratio_vec[i] -> SetLineColor(sim_c[i]);
						      
      sn108_ratio_vec[i] -> SetLineWidth(sim_lw[i]);
      sn108_ratio_vec[i] -> SetLineStyle(sim_ls[i]);
      sn108_ratio_vec[i] -> SetLineColor(sim_c[i]);

      auto doubleRatio = (TH1D *)sn132_ratio_vec[i]->Clone();
      doubleRatio->Divide(sn108_ratio_vec[i]);
      double_ratio_vec[i] = doubleRatio;

      double_ratio_vec[i] -> SetLineWidth(sim_lw[i]);
      double_ratio_vec[i] -> SetLineStyle(sim_ls[i]);
      double_ratio_vec[i] -> SetLineColor(sim_c[i]);


      c1->SetLogy();
      c2->SetLogy();
      
      if(i == 0)
	{
	  c1->cd();
	  sn132_ratio_vec[i]->GetYaxis()->SetRangeUser(.5,20);
	  sn132_ratio_vec[i]->Draw("HIST L");

	  c2->cd();
	  sn108_ratio_vec[i]->GetYaxis()->SetRangeUser(.1,10);
	  sn108_ratio_vec[i]->Draw("HIST L");

	  c3->cd();
	  double_ratio_vec[i]->GetYaxis()->SetRangeUser(1.5,5);
	  double_ratio_vec[i]->Draw("HIST L");
	}
      else
	{
	  c1->cd();
	  sn132_ratio_vec[i]->Draw("same HIST L");
	  c2->cd();
	  sn108_ratio_vec[i]->Draw("same HIST L");
	  c3->cd();
	  double_ratio_vec[i]->Draw("same HIST L");
	}

    }



  ofstream outfile;
  outfile.open("Bayes_Sn132_Cozma.txt");
  for(int i = 0; i < 9; i++)
    {

      //      for(int bin = 1; bin <= sn132_ratio_vec[i]->GetNbinsX();bin++)
      //	outfile<<sn132_ratio_vec[i]->GetBinCenter(bin)<<",";
      //      outfile<<endl;
      for(int bin = 1; bin <= sn132_ratio_vec[i]->GetNbinsX();bin++)
	outfile<<sn132_ratio_vec[i]->GetBinContent(bin)<<",";
      outfile<<endl;
    }

  outfile.close();
  outfile.open("Bayes_Sn108_Cozma.txt");
  for(int i = 0; i < 9; i++)
    {

      //      for(int bin = 1; bin <= sn108_ratio_vec[i]->GetNbinsX();bin++)
      //	outfile<<sn108_ratio_vec[i]->GetBinCenter(bin)<<",";
      //      outfile<<endl;
      for(int bin = 1; bin <= sn108_ratio_vec[i]->GetNbinsX();bin++)
	outfile<<sn108_ratio_vec[i]->GetBinContent(bin)<<",";
      outfile<<endl;
    }


}
