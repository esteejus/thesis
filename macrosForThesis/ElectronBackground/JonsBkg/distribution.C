void distribution(){
    TH1D *histDist=new TH1D("histDist","",1000,0,1);
    Double_t me=0.511;
    Double_t mpi0=135.0;
    Double_t scale=38.3;
    Double_t widthintegral=0;
    ofstream csvout;
    csvout.open("eedist.txt");
    Double_t temp=0;
    Int_t counter=0;
    for(int i=0;i<1400;i++){
        Double_t mee=double(i)/10.;
        Double_t width=1./mee*TMath::Sqrt(1.-4.*me*me/mee/mee)*(1+2*me*me/mee/mee)*TMath::Power((1-mee*mee/mpi0/mpi0),3)*TMath::Power(TMath::Abs(1+0.0305*mee*mee/mpi0/mpi0),2)/scale;
	if(width>0) widthintegral=widthintegral+width;
	if(widthintegral>0 && widthintegral > temp+0.0001 ){
	  csvout << widthintegral << "\t" << mee << endl;
	  counter++;
	}
    if(widthintegral > temp+0.0001)	temp=widthintegral;
    }
    cout << "fill done" << endl;
    cout << "lines: " << counter << endl;
    cout << widthintegral << endl;
    //histDist->Draw();
}
/*
void intPion(){
  TFile *f=new TFile("histP5.root");
  TH1D * histP = new TH1D("histP","",1000,0,500);
  histP=(TH1D*)f->Get("histP5");
  Double_t scale = 1/((double)histP->Integral());
  histP->Scale(scale);
  ofstream csvout;
  csvout.open("pionInt.txt");
  int counter=0;
  Double_t mom, n,n1;
  for(int i=0;i<1000;i++){
    mom=((double)i)*0.5;

    n+=histP->GetBinContent(i);
    if(n>1E-100 && n>n1){
      csvout << n << "\t" << mom << endl;
      counter++;
    }
    n1=n;
  }
  //csvout.Close();
  TCanvas *c1=new TCanvas("c1","",800,800);
  histP->Draw();
  cout << counter << endl;
}
*/
