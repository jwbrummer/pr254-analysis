// Written by JWB on 15/07/2016. This script generates three spectra that shows how much the beam drifted during weekend 2.
// Each state is represented by a line and when that line is broken it means that the magnet fields have shifted appreciably.
// The spectrum gives an idea of the stability of the beam during the weekend.

{
  int runs[42]={2012,2014,2015,2017,2018,2019,2021,2022,2024,2025,2027,2028,2030,2031,2034,2035,2037,2038,2040,2041,2043,2044,2056,2057,2058,2060,2061,2062,2063,2066,2068,2069,2071,2072,2074,2075,2077,2079,2080,2082,2083,2085};
  gROOT->ProcessLine(".x /home/wiggert/Documents/pr254/spectra/weekend2/pid/CUTpad1vstofRun2012.C");
  TChain *ch = new TChain("DATA");
  for(int i=0;i<42;i++)
    {
      char buffer[256];
      sprintf(buffer,"/home/wiggert/Documents/pr254/sortedRuns/weekend2/sorted0%d.root",runs[i]);
      printf(buffer);
      printf("\n");
      ch->Add(buffer);
    }
  ch->SetAlias("X1posCorr","X1pos-3.50214*thetaSCAT-0.0785534*thetaSCAT*thetaSCAT");
  ch->SetAlias("calEx","19.096-0.0271916*X1posCorr+8.37548e-6*X1posCorr*X1posCorr");
  ch->SetAlias("gates","CUTpad1vstofRun2012 && !X1flag && !X2flag && !U1flag");

  ch->Draw("calEx>>hEx_Cal_WE2(2000,0,18)","gates");
  c1->SaveAs("/home/wiggert/Documents/pr254/spectra/weekend2/chained/x1pos-chained-we2.png");
  c1->SaveAs("/home/wiggert/Documents/pr254/spectra/weekend2/chained/x1pos-chained-we2.C");

  ch->Draw("X1posCorr:Entry$>>hPeakDriftWE2(2000,0,20e6,2000,0,800)","gates","col");
  c1->SaveAs("/home/wiggert/Documents/pr254/spectra/weekend2/chained/x1pos-peak-drift-with-time-we2.png");
  c1->SaveAs("/home/wiggert/Documents/pr254/spectra/weekend2/chained/x1pos-peak-drift-with-time-we2.C");

  ch->Draw("calEx:Entry$","gates","col");
  c1->SaveAs("/home/wiggert/Documents/pr254/spectra/weekend2/chained/Ex-peak-drift-with-time-we2.png");
  c1->SaveAs("/home/wiggert/Documents/pr254/spectra/weekend2/chained/Ex-peak-drift-with-time-we2.C");
}

