{
  // as modified for PR226 analysis  
  // Use CUTbasic, CUTlimits and CUTY as defined in read-gates-12C.C
 
  char name[128];


  Int_t nrofruns=18; 
 
  // LiCO runs, WE2
  //Int_t run_no[128]={1023,1024,1025,1026,1030,1032 ,1033,1034 ,1036,1039,1041,1043,1044,1047,1048,1052,1053,1056,1058,1059,1060,1070,1071,1073,1075,1078,1079,1084,1085,1086,1087};   //31 runs in total

  // C runs, WE2
  Int_t run_no[128]={1089,1090,1091,1092,1093,1094,1095,1096,1099,1100,1101,1106,1029,1035,1045,1046,1062,1080};  //18 runs in total

  TF1 *fit = new TF1("fit","gaus(0) + pol1(3)",1,800);
  Double_t a0,a1,a2,a3,a4,norm;
  Double_t width = 5.;
  Double_t par[5];
 
  Float_t peakposition[nrofruns];
  Float_t sigma[nrofruns];


  for(Int_t i=0;i<nrofruns;i++)	{
	  sprintf(name,"~/DATA/ROOT/PR226/run0%4d.root",run_no[i]);
          cout << name << endl;
	  TFile *_file0 = TFile::Open(name);     
  	  TH1F *hX1pos = new TH1F("hX1pos","X1 Position",4000,0.,800.);
          DATA->Draw("X1posC>>hX1pos",CUTbasic && CUTlimits && CUTY,"");

	  norm = hX1pos->Integral(1000,2000);
	  norm=norm/1000.;
          cout << "norm" << norm << endl;
	  fit->SetParameters(1.*norm,690.,1.,norm,0.);
	  //fit->SetParLimits(0,0,1e9);

	  //hX1pos->Fit("fit","R","",614,630);  // for LiCO
	  hX1pos->Fit("fit","R","",680,710);    // for C

	  fit->GetParameters(par);
	  //a0=par[0];a1=par[1];a2=par[2];a3=par[3];
          //cout << endl << " par0 " << a0 <<"; par1 " << a1 <<"; par2 " << a2 << "; par3 "<< a3 << "; par4 "<< a4<< endl << endl;

          peakposition[i] = par[1];
          sigma[i] = par[2];

	  c1->Modified(); c1->Update();
	  c1->WaitPrimitive(); 
  }
  for(Int_t i=0;i<nrofruns;i++)	{
     cout << " "<< run_no[i] <<" "<< peakposition[i] <<" "<< sigma[i] << endl;
  }
  for(Int_t i=0;i<nrofruns;i++)	{
     cout << ""<< run_no[i] <<"  Difference compared with run "<<run_no[0] <<"  "<< peakposition[i]-peakposition[0] << endl;
  }
 
  for(Int_t i=0;i<nrofruns;i++)	{
     cout << "        case "<< run_no[i] <<": x1offset="<< peakposition[i]-peakposition[0] <<"\; printf(\"run %d: x1 offset= %f \\n\",runinfo2.run_number,x1offset); break;   "<< endl;
  }



}




