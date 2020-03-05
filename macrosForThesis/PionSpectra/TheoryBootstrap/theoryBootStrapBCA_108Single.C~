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


vector<double> SampleBoot(vector< vector<double>> data)
{
  vector<double> boot(data.size(),0);

  for(int iBin = 0; iBin < data.size(); iBin++)
    {
      int num_th = data.at(iBin).size(); //# of theories

      for(int i = 0; i < num_th; i++)
	boot.at(iBin) += data.at(iBin).at(ran->Integer(num_th));

      boot.at(iBin) /= num_th;
    }
  
  return boot;
}


vector<TH1D *> BootStrap(int n_throws, vector< vector<double>> data)
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
      auto vec = SampleBoot(data);
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


  vector< vector<double>> soft_data(7,vector<double>(0));
  vector< vector<double>> stiff_data(7,vector<double>(0));

  loadVec(soft_data,xbuu_DR);
  loadVec(soft_data,tuQMD_05_DR);
  loadVec(soft_data,pBUU_soft_no_DR);
  loadVec(soft_data,amdJAM55_DR);
  loadVec(soft_data,urQMD_46_DR);
  
  loadVec(stiff_data,xbuu_DR);
  loadVec(stiff_data,tuQMD_20_DR);
  loadVec(stiff_data,pBUU_stiff_no_DR);
  loadVec(stiff_data,amdJAM152_DR);
  loadVec(stiff_data,urQMD_104_DR);

  int num_boot = 1e5;
  auto stiff_hist_vec = BootStrap(num_boot,stiff_data);
  auto soft_hist_vec = BootStrap(num_boot,soft_data);

  //  soft_hist_vec.at(1)->Draw();  


  TCanvas *c1 = new TCanvas("c1","c1",1);
  TH1 *cumulative;
  /*
  cumulative = stiff_hist_vec.at(0)->GetCumulative();
  cumulative->Draw();
  */
  
  double low = .025 * num_boot;
  double high = .975 * num_boot;

  for(int iBin = 0; iBin < xbuu_DR->GetN(); iBin++)
    {
      double x,y;
      xbuu_DR->GetPoint(iBin,x,y);
      cout<<x<<",";
    }
  cout<<endl;


  for(int iBin = 0; iBin < stiff_hist_vec.size(); iBin++)
      cout<<stiff_hist_vec.at(iBin)->GetMean()<<",";

  cout<<endl<<"Low "<<endl;
  
  for(int iBin = 0; iBin < stiff_hist_vec.size(); iBin++)
    {
      cumulative = stiff_hist_vec.at(iBin)->GetCumulative();
      cout<<stiff_hist_vec.at(iBin)->GetMean() - cumulative->GetXaxis()->GetBinCenter(cumulative->FindFirstBinAbove(low)-1)<<",";
    }
  cout<<endl<<"High "<<endl;

  for(int iBin = 0; iBin < stiff_hist_vec.size(); iBin++)
    {
      cumulative = stiff_hist_vec.at(iBin)->GetCumulative();
      cout<<cumulative->GetXaxis()->GetBinCenter(cumulative->FindFirstBinAbove(high)+1)-stiff_hist_vec.at(iBin)->GetMean()<<",";
    }
  cout<<endl;
  
  cout<<endl<<endl<<"Soft"<<endl;

  for(int iBin = 0; iBin < soft_hist_vec.size(); iBin++)
      cout<<soft_hist_vec.at(iBin)->GetMean()<<",";

  cout<<endl<<"Low "<<endl;
  
  for(int iBin = 0; iBin < soft_hist_vec.size(); iBin++)
    {
      cumulative = soft_hist_vec.at(iBin)->GetCumulative();
      cout<<soft_hist_vec.at(iBin)->GetMean() - cumulative->GetXaxis()->GetBinCenter(cumulative->FindFirstBinAbove(low)-1)<<",";
    }

  cout<<endl<<"High"<<endl;
  
  for(int iBin = 0; iBin < soft_hist_vec.size(); iBin++)
    {
      cumulative = soft_hist_vec.at(iBin)->GetCumulative();
      cout<<cumulative->GetXaxis()->GetBinCenter(cumulative->FindFirstBinAbove(high)+1)-soft_hist_vec.at(iBin)->GetMean()<<",";
    }
  cout<<endl;
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
