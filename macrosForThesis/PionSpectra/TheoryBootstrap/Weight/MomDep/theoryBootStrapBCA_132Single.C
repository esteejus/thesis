TRandom3 *ran = new TRandom3(12345);

void loadVec(vector< vector<double>> &d, TGraphErrors *g)
{
  int num_bins = g->GetN();
   for(int iBin = 0; iBin < num_bins; iBin++)
    {
      double x,y;
      g->GetPoint(iBin,x,y);
      d.at(iBin).push_back(y);
    }
}


vector<double> SampleBoot(vector< vector<double>> data, int idx_max)
{
  double weight = .5;
  vector<double> boot(data.size(),0);

  for(int iBin = 0; iBin < data.size(); iBin++)
    {
      int num_th = data.at(iBin).size(); //# of theories

      for(int i = 0; i < num_th; i++)
	{
	  int rand_idx = ran->Integer(num_th);//ranges from 0 to num_th - 1; vector index
	  //data that is > idx_max is weighted lower
	  //compare the vector indicies
	  
	  if(rand_idx > idx_max)
	    {
	      if(ran->Uniform() > weight)
		rand_idx = ran->Integer(idx_max + 1); //samples from 0 to idx_max
	    }

	  boot.at(iBin) += data.at(iBin).at(rand_idx);
	}

      boot.at(iBin) /= num_th;
    }
  
  return boot;
}


vector<TH1D *> BootStrap(int n_throws, vector< vector<double>> data,int idx_max = 1e9)
{
  vector<TH1D *> hist_vec;
  for(int iBin = 0; iBin < data.size(); iBin++)
    {
      TH1D *h;
      if(iBin < 1)
	h = new TH1D(Form("bin_%d",iBin),Form("bin_%d",iBin),10,0,40);
      else
	h = new TH1D(Form("bin_%d",iBin),Form("bin_%d",iBin),100,0,15);
      hist_vec.push_back(h);
    }

  for(int iBoot = 0; iBoot < n_throws; iBoot++)
    {
      auto vec = SampleBoot(data,idx_max);
      for(int iBin = 0; iBin < vec.size(); iBin++)
	hist_vec.at(iBin)->Fill(vec.at(iBin));
    }

  return hist_vec;
}


void theoryBootStrapBCA_132Single()
{

    TFile *pBUU_soft_no_f = TFile::Open("/home/justin/Homework/pBUU/K210EM100/input_for_esym.info/pBUUSoft_r-1.root");
  TGraphErrors *pBUU_soft_no_DR = (TGraphErrors *) pBUU_soft_no_f->Get("piRatio132");

  TFile *pBUU_stiff_no_f = TFile::Open("/home/justin/Homework/pBUU/K210EM100/input_for_esym.info/pBUUStiff_r-1.root");
  TGraphErrors *pBUU_stiff_no_DR = (TGraphErrors *) pBUU_stiff_no_f->Get("piRatio132");

  TFile *amdJAM55_f = TFile::Open("/home/justin/Homework/AMDJAM/highStat/input_for_esym.info/AMDJAML55new_r-1.root");
  TGraphErrors *amdJAM55_DR = (TGraphErrors *) amdJAM55_f->Get("piRatio132");

  TFile *amdJAM152_f = TFile::Open("/home/justin/Homework/AMDJAM/highStat/input_for_esym.info/AMDJAML152new_r-1.root");
  TGraphErrors *amdJAM152_DR = (TGraphErrors *) amdJAM152_f->Get("piRatio132");


  TFile *urQMD_46_f = TFile::Open("/home/justin/Homework/UrQMD/input_for_esym.info/UrQMDL46_r-1.root");
  TGraphErrors *urQMD_46_DR = (TGraphErrors *) urQMD_46_f->Get("piRatio132");

  TFile *urQMD_104_f = TFile::Open("/home/justin/Homework/UrQMD/input_for_esym.info/UrQMDL104_r-1.root");
  TGraphErrors *urQMD_104_DR = (TGraphErrors *) urQMD_104_f->Get("piRatio132");


  TFile *imQMD_05_f = TFile::Open("/home/justin/Homework/IQMD-BNU/input_for_esym.info/IQMD-BNUg05_r-1.root");
  TGraphErrors *imQMD_05_DR = (TGraphErrors *) imQMD_05_f->Get("piRatio132");

  TFile *imQMD_20_f = TFile::Open("/home/justin/Homework/IQMD-BNU/input_for_esym.info/IQMD-BNUg20_r-1.root");
  TGraphErrors *imQMD_20_DR = (TGraphErrors *) imQMD_20_f->Get("piRatio132");


  TFile *tuQMD_05_f = TFile::Open("/home/justin/Homework/TuQMD/new-highStat/input_for_esym.info/TuQMDg05_r-1.root");
  TGraphErrors *tuQMD_05_DR = (TGraphErrors *) tuQMD_05_f->Get("piRatio132");

  TFile *tuQMD_20_f = TFile::Open("/home/justin/Homework/TuQMD/new-highStat/input_for_esym.info/TuQMDg20_r-1.root");
  TGraphErrors *tuQMD_20_DR = (TGraphErrors *) tuQMD_20_f->Get("piRatio132");


  TFile *xbuu_f = TFile::Open("/home/justin/Homework/xBUU/old/input_for_esym.info/xBUU_r-1.root");
  TGraphErrors *xbuu_DR = (TGraphErrors *) xbuu_f->Get("piRatio132");

  TFile *xbuu120_f = TFile::Open("/home/justin/Homework/xBUU/new/input_for_esym.info/xBUU_skyrmeL120_r-1.root");
  TGraphErrors *xbuu120_DR = (TGraphErrors *) xbuu120_f->Get("piRatio132");

  //first number is number of bins
  vector< vector<double>> soft_data(7,vector<double>(0));
  vector< vector<double>> stiff_data(7,vector<double>(0));

  loadVec(soft_data,xbuu_DR);
  loadVec(soft_data,amdJAM55_DR);
  loadVec(soft_data,urQMD_46_DR);
  loadVec(soft_data,tuQMD_05_DR);//idx_max = 3
  loadVec(soft_data,imQMD_05_DR);
  loadVec(soft_data,pBUU_soft_no_DR);
    
  loadVec(stiff_data,xbuu_DR);
  loadVec(stiff_data,amdJAM152_DR);
  loadVec(stiff_data,urQMD_104_DR);
  loadVec(stiff_data,tuQMD_20_DR);//idx_max
  loadVec(soft_data,imQMD_20_DR);
  loadVec(stiff_data,pBUU_stiff_no_DR);

  //labed as vector index
  int idx_max = 3;//urQMD position
  
  int num_boot = 1e5;
  auto stiff_hist_vec = BootStrap(num_boot,stiff_data,idx_max);
  auto soft_hist_vec = BootStrap(num_boot,soft_data,idx_max);

  //  soft_hist_vec.at(1)->Draw();  


  TCanvas *c1 = new TCanvas("c1","c1",1);
  TH1 *cumulative;
  /*
  cumulative = stiff_hist_vec.at(0)->GetCumulative();
  cumulative->Draw();
  */
  
  double low = .025 * num_boot;
  double high = .975 * num_boot;

  double x_point_stiff[xbuu_DR->GetN()];
  double y_point_stiff[xbuu_DR->GetN()];
  double x_l_err_stiff[xbuu_DR->GetN()];
  double y_l_err_stiff[xbuu_DR->GetN()];
  double x_h_err_stiff[xbuu_DR->GetN()];
  double y_h_err_stiff[xbuu_DR->GetN()];

  double x_point_soft[xbuu_DR->GetN()];
  double y_point_soft[xbuu_DR->GetN()];
  double x_l_err_soft[xbuu_DR->GetN()];
  double y_l_err_soft[xbuu_DR->GetN()];
  double x_h_err_soft[xbuu_DR->GetN()];
  double y_h_err_soft[xbuu_DR->GetN()];

 for(int iBin = 0; iBin < xbuu_DR->GetN(); iBin++)
    {
      double x,y;
      xbuu_DR->GetPoint(iBin,x,y);
      //      cout<<x<<",";
      x_point_stiff[iBin] = x;
      x_point_soft[iBin] = x;
      x_l_err_soft[iBin] = 0;
      x_h_err_soft[iBin] = 0;
      x_l_err_stiff[iBin] = 0;
      x_h_err_stiff[iBin] = 0;

    }

  for(int iBin = 0; iBin < stiff_hist_vec.size(); iBin++)
    {
      y_point_stiff[iBin] = stiff_hist_vec.at(iBin)->GetMean();
    }

  for(int iBin = 0; iBin < stiff_hist_vec.size(); iBin++)
    {
      cumulative = stiff_hist_vec.at(iBin)->GetCumulative();
      y_l_err_stiff[iBin] = stiff_hist_vec.at(iBin)->GetMean() - cumulative->GetXaxis()->GetBinCenter(cumulative->FindFirstBinAbove(low)-1);

    }


  for(int iBin = 0; iBin < stiff_hist_vec.size(); iBin++)
    {
      cumulative = stiff_hist_vec.at(iBin)->GetCumulative();
      y_h_err_stiff[iBin] = cumulative->GetXaxis()->GetBinCenter(cumulative->FindFirstBinAbove(high)+1)-stiff_hist_vec.at(iBin)->GetMean();
    }

  for(int iBin = 0; iBin < soft_hist_vec.size(); iBin++)
    {
      y_point_soft[iBin] = soft_hist_vec.at(iBin)->GetMean();
    }
  
  for(int iBin = 0; iBin < soft_hist_vec.size(); iBin++)
    {
      cumulative = soft_hist_vec.at(iBin)->GetCumulative();
      y_l_err_soft[iBin] = soft_hist_vec.at(iBin)->GetMean() - cumulative->GetXaxis()->GetBinCenter(cumulative->FindFirstBinAbove(low)-1);
    }

  for(int iBin = 0; iBin < soft_hist_vec.size(); iBin++)
    {
      cumulative = soft_hist_vec.at(iBin)->GetCumulative();
      y_h_err_soft[iBin] = cumulative->GetXaxis()->GetBinCenter(cumulative->FindFirstBinAbove(high)+1)-soft_hist_vec.at(iBin)->GetMean();
    }

  
  TGraphAsymmErrors *stiff_g = new  TGraphAsymmErrors(xbuu_DR->GetN(),x_point_stiff,y_point_stiff,x_l_err_stiff,x_h_err_stiff,y_l_err_stiff,y_h_err_stiff);

  TGraphAsymmErrors *soft_g = new  TGraphAsymmErrors(xbuu_DR->GetN(),x_point_soft,y_point_soft,x_l_err_soft,x_h_err_soft,y_l_err_soft,y_h_err_soft);

  TFile *out = new TFile("momentumDep_sn132.root","RECREATE");
  stiff_g->SetName("stiff_eos");
  soft_g->SetName("soft_eos");

  stiff_g->SetFillColorAlpha(kRed,.4);
  soft_g->SetFillColorAlpha(kBlue,.4);
  stiff_g->Write();
  soft_g->Write();
  
  stiff_g->Draw("A L E3");
  soft_g->Draw("same L E3");
  /*
  TH1D *test = new TH1D("test","test",75,0,4);

  for(int i = 0; i < 1e7; i++)
    {
      double mean = 0; 
      //      cout<<endl;
      for(int j = 0; j < stiff_data.at(0).size(); j++)
	{
	 double value = stiff_data.at(0).at(ran->Integer(stiff_data.at(0).size()));
	 //	 cout<<"Pull "<<j<<" "<<value<<endl;
	 mean += value;
	}

      mean /= stiff_data.at(0).size();
      //      cout<<"Mean value is "<<mean<<endl;
      test->Fill(mean);

    }
  test->Draw();
  */

}
