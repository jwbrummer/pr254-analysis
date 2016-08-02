// Written by JWB on 15/07/2016. This script generates three spectra that shows how much the beam drifted during weekend 3.
// Each state is represented by a line and when that line is broken it means that the magnet fields have shifted appreciably.
// The spectrum gives an idea of the stability of the beam during the weekend.


{
  int runs[45]={3025,3026,3031,3032,3035,3036,3038,3039,3042,3056,3059,3062,3063,3067,3068,3071,3072,3075,3076,3079,3080,3083,3084,3087,3088,3091,3092,3095,3096,3099,3100,3103,3104,3107,3108,3109,3112,3113,3115,3118,3119,3120,3123,3124,3125};
  gROOT->ProcessLine(".x /home/wiggert/Documents/pr254/spectra/weekend3/pid/CUTpad1vstofRun3025.C");
  TChain *ch = new TChain("DATA");
  for(int i=0;i<45;i++)
    {
      char buffer[256];
      sprintf(buffer,"/home/wiggert/Documents/pr254/sortedRuns/weekend3/sorted0%d.root",runs[i]);
      printf(buffer);
      printf("\n");
      ch->Add(buffer);
    }
  ch->SetAlias("X1posCorr","X1pos-3.96147*thetaSCAT-0.110965*thetaSCAT*thetaSCAT");
  ch->SetAlias("calEx","18.3874-0.0234076*X1posCorr+4.92999e-6*X1posCorr*X1posCorr");
  ch->SetAlias("gates","CUTpad1vstofRun3025 && !X1flag && !X2flag && !U1flag");

  ch->Draw("calEx>>hEx_Cal_WE3(2000,0,18)","gates");
  c1->SaveAs("/home/wiggert/Documents/pr254/spectra/weekend3/chained/x1pos-chained-we3.png");
  c1->SaveAs("/home/wiggert/Documents/pr254/spectra/weekend3/chained/x1pos-chained-we3.C");

  ch->Draw("X1posCorr:Entry$>>hPeakDriftWE3(2000,0,45e6,2000,0,800)","gates","col");
  c1->SaveAs("/home/wiggert/Documents/pr254/spectra/weekend3/chained/x1pos-peak-drift-with-time-we3.png");
  c1->SaveAs("/home/wiggert/Documents/pr254/spectra/weekend3/chained/x1pos-peak-drift-with-time-we3.C");
/*
  ch->Draw("calEx:Entry$","gates","col");
  c1->SaveAs("/home/wiggert/Documents/pr254/spectra/weekend3/chained/Ex-peak-drift-with-time-we3.png");
  c1->SaveAs("/home/wiggert/Documents/pr254/spectra/weekend3/chained/Ex-peak-drift-with-time-we3.C");*/
}


