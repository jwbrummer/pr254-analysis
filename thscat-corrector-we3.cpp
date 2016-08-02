// Written by JWB on 10/07/2016. This script does the line-shape correction for all 24Mg runs of weekend 3.
// The line-shape correction is necessary to correct for the tilt in the ThSCATvX1pos spectrum which will
// lead to a poor peak resolution if not fixed.

{
  int runs[45] = {3025,3026,3031,3032,3035,3036,3038,3039,3042,3056,3059,3062,3063,3067,3068,3071,3072,3075,3076,3079,3080,3083,3084,3087,3088,3091,3092,3095,3096,3099,3100,3103,3104,3107,3108,3109,3112,3113,3115,3118,3119,3120,3123,3124,3125};
  gROOT->ProcessLine(".x /home/wiggert/Documents/pr254/spectra/weekend3/pid/CUTpad1vstofRun3025.C");
  for(int i=0;i<45;i++)
    {
      char runNum[256];
      sprintf(runNum,"/home/wiggert/Documents/pr254/sortedRuns/weekend3/sorted0%d.root",runs[i]);
      TFile *file = TFile::Open(runNum);
      // DATA->SetAlias("X1posCorr","thetaSCAT:X1pos-3.96147*thetaSCAT-0.110965*thetaSCAT*thetaSCAT");

      char buffer1[256];
      sprintf(buffer1,"thetaSCAT:X1pos-3.96147*thetaSCAT-0.110965*thetaSCAT*thetaSCAT>>hThSCATvX1posRun%d(500,0,800,500,-10,0)",runs[i]);
      DATA->Draw(buffer1,"CUTpad1vstofRun3025 && !X1flag && !X2flag && !U1flag","col");
      
      char pngName[256];
      char cName[256];
      char rootName[256];
      
      sprintf(pngName,"/home/wiggert/Documents/pr254/spectra/weekend3/thscat/X1posCorrRun%d.png",runs[i]);
      sprintf(cName,"/home/wiggert/Documents/pr254/spectra/weekend3/thscat/X1posCorrRun%d.C",runs[i]);
      sprintf(rootName,"/home/wiggert/Documents/pr254/spectra/weekend3/thscat/X1posCorrRun%d.root",runs[i]);
      
      c1->SaveAs(pngName);
      c1->SaveAs(cName);
      c1->SaveAs(rootName);
    }
}
