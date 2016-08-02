// Written by JWB on 19/07/2016. This is simply a precursor to tspectra.cpp. It was used to test the code by only
// trying to generate tspectra for the 24Mg runs of weekend 3.

{
  int runs[45]={3025,3026,3031,3032,3035,3036,3038,3039,3042,3056,3059,3062,3063,3067,3068,3071,3072,3075,3076,3079,3080,3083,3084,3087,3088,3091,3092,3095,3096,3099,3100,3103,3104,3107,3108,3109,3112,3113,3115,3118,3119,3120,3123,3124,3125};
  gROOT->ProcessLine(".x /home/wiggert/Documents/pr254/spectra/weekend3/pid/CUTpad1vstofRun3025.C");
  for(int i=0;i<45;i++)
    {
      char buffer[256];
      sprintf(buffer,"/home/wiggert/Documents/pr254/sortedRuns/weekend3/sorted0%d.root",runs[i]);
      TFile *fin = TFile::Open(buffer);
      char tempBuffer[256];
      sprintf(tempBuffer,"X1posCorr_Run%d",runs[i]);
      DATA->SetAlias(tempBuffer,"X1pos-3.96147*thetaSCAT-0.110965*thetaSCAT*thetaSCAT");
      char nameBuf[256];
      sprintf(nameBuf,"X1posCorr_Run%d>>hEx_TSpectrum(1000,0,800,1000,0,2000)",runs[i]);
      DATA->Draw(nameBuf,"CUTpad1vstofRun3025 && !X1flag && !X2flag && !U1flag");
      c1->SetWindowPosition(1500,0);
      TSpectrum *sp = new TSpectrum();
      sp->Search(hEx_TSpectrum,1,"",0.35);

      char pngBuffer[256];
      sprintf(pngBuffer,"/home/wiggert/Documents/pr254/spectra/weekend3/tspectra/x1pos-peak-search-run%d.png",runs[i]);
      c1->SaveAs(pngBuffer);
      
    }//end of for loop
}//end of file



