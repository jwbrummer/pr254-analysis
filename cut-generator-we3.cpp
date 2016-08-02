// Written by JWB on 09/07/2016. This script makes the same PID cut for all of the 24Mg weekend 3 runs because there was only one field setting
// during the course of the weekend.

{
  int runs[45] = {3025,3026,3031,3032,3035,3036,3038,3039,3042,3056,3059,3062,3063,3067,3068,3071,3072,3075,3076,3079,3080,3083,3084,3087,3088,3091,3092,3095,3096,3099,3100,3103,3104,3107,3108,3109,3112,3113,3115,3118,3119,3120,3123,3124,3125};
  
  for(int i=0;i<45;i++)
    {
      char sortNum[256];
      sprintf(sortNum,"/home/wiggert/Documents/pr254/sortedRuns/weekend3/sorted0%d.root",runs[i]);
      TFile *_file0 = TFile::Open(sortNum);
      
      char buffer[256];
      sprintf(buffer,"pad1:tof>>hPad1vsTOFRun%d(500,3200,3600,500,500,2000)",runs[i]);
      DATA->Draw(buffer,"abs(tof)<1e4 && !X1flag && !X2flag && !U1flag","col");
      c1->SetWindowPosition(1500,300);
      char buffer2[256];
      sprintf(buffer2,"CUTpad1vstofRun%d",runs[i]);
      TCutG *cutg = new TCutG(buffer2,11);
      cutg->SetVarX("tof");
      cutg->SetVarY("pad1");
      cutg->SetTitle("Graph");
      cutg->SetFillColor(1);
      cutg->SetPoint(0,3354.74,1794.23);
      cutg->SetPoint(1,3397.13,1444.65);
      cutg->SetPoint(2,3445.26,1202.33);
      cutg->SetPoint(3,3465.37,1011.65);
      cutg->SetPoint(4,3445.26,932.203);
      cutg->SetPoint(5,3408.62,884.534);
      cutg->SetPoint(6,3357.61,1079.18);
      cutg->SetPoint(7,3331.03,1257.94);
      cutg->SetPoint(8,3308.76,1464.51);
      cutg->SetPoint(9,3305.17,1746.56);
      cutg->SetPoint(10,3354.74,1794.23);
      cutg->Draw("SAME");

      char pngName[256];
      char cName[256];

      sprintf(pngName,"/home/wiggert/Documents/pr254/spectra/weekend3/pid/CUTpad1vstofRun%d.png",runs[i]);
      sprintf(cName,"/home/wiggert/Documents/pr254/spectra/weekend3/pid/CUTpad1vstofRun%d.C",runs[i]);
      
      c1->SaveAs(pngName);
      c1->SaveAs(cName);
    }
}
