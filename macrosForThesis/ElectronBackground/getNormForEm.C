
#include "getGausNorm.C"

void getNormForEm()
{

  //e-
 TF1 *total = new TF1("total","[0]*TMath::Gaus(x,[1],[2])",-500, 0);
 total->SetParameters(1.31633e+03,3.54408e+02,1.73671e+02);
 
  // TF1 *total = new TF1("total","[0] + [1]*x + [2]*pow(x,2) + [3]*pow(x,3) + [4]*pow(x,4) + [5]*pow(x,5)+ [6]*pow(x,6)",-500, 0);
  //  total->SetParameters(147.754,1.31299,-4.60831e-05,-4.65737e-05,-2.40293e-07,-5.07279e-10,-4.0121e-13);

  TF1 *sigma = new TF1("sigma","[0] + [1]*x + [2]*pow(x,2) + [3]*pow(x,3)",-500,0);
  sigma->SetParameters(0.148491,0.00059832,1.69265e-06,1.5452e-09);

  TF1 *mean = new TF1("mean","[0] + [1]*x + [2]*pow(x,2) + [3]*pow(x,3) + [4]*pow(x,4) + [5]*pow(x,5) + [6]*pow(x,6) + [7]*pow(x,7) + [8]*pow(x,8)",-500,0);
  mean->SetParameters(-5.5843,-0.131102,-0.00155294,-1.17224e-05,-5.71558e-08,-1.77215e-10,-3.35297e-13,-3.51656e-16,-1.56314e-19);
  


  center = {6,18,30,42,54,66,78,90,102,114,126,138,150,162,180,216,270};

  //  vector<double> center = {650,590,570,550,530,510,490,470,450,430,410,390,370,350,330,310,290,270,250,230,210,190,170,150,130,110,97.5,92.5,87.5};
  
  vector<double> binw = {100,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,5,5,5};


  cout<<center.size()<<" "<<binw.size()<<endl;
 cout<<"norm "<<endl;

 for(int i = 0; i < center.size(); i++)
   {
     double x = -center.at(i);
     double sigma_v = sigma->Eval(x);
     double mean_v  = mean->Eval(x);
     double total_v = total->Eval(x);
     //     cout<<"diff "<<total_v - norm.at(i)<<endl;
     double norm = getGausNorm(total_v*binw.at(i),mean_v,sigma_v);
     cout<<x<<"\t"<<norm<<"\t"<<mean_v<<"\t"<<sigma_v<<"\t"<<total_v*binw.at(i)<<endl;
     //cout<<center.at(i)<<" "<<total_v*binw.at(i)<<endl;
     //cout<<x<<" "<< norm<<endl;     
   }



}
