// Written by JWB on 15/07/2016. This script generates three spectra that shows how much the beam drifted during weekend 1.
// Each state is represented by a line and when that line is broken it means that the magnet fields have shifted appreciably.
// The spectrum gives an idea of the stability of the beam during the weekend.

{
  int runs[22] = {1040,1041,1043,1046,1049,1051,1053,1056,1059,1062,1063,1064,1066,1067,1068,1072,1073,1074,1076,1077,1078,1079};
  TChain *ch = new TChain("DATA");
	
  for(int i=0;i<22;i++)
    {
if(i==0)
{
  gROOT->ProcessLine(".x /home/wiggert/Documents/pr254/spectra/weekend1/pid/CUTpad1vstofRun1040.C");
}
      char buffer[256];
      sprintf(buffer,"/home/wiggert/Documents/pr254/sortedRuns/weekend1/sorted0%d.root",runs[i]);
      printf(buffer);
      printf("\n");
      ch->Add(buffer);
    }


  ch->SetAlias("X1posCorr","X1pos - 3.40739*thetaSCAT - 0.079275*thetaSCAT*thetaSCAT");
  ch->SetAlias("calEx","16.8511 - 0.0215884*X1posCorr + 3.49076e-6*X1posCorr*X1posCorr");
  ch->SetAlias("gates","CUTpad1vstofRun1040 && !X1flag && !X2flag && !U1flag");

  ch->Draw("calEx>>hEx_Cal_WE1(2000,2,14)","gates");
  c1->SaveAs("/home/wiggert/Documents/pr254/spectra/weekend1/chained/x1pos-chained-we1.png");
  c1->SaveAs("/home/wiggert/Documents/pr254/spectra/weekend1/chained/x1pos-chained-we1.C");

  ch->Draw("X1posCorr:Entry$>>hPeakDriftWE1(2000,0,17e6,2000,0,800)","gates","col");
  c1->SaveAs("/home/wiggert/Documents/pr254/spectra/weekend1/chained/x1pos-peak-drift-with-time-we1.png");
  c1->SaveAs("/home/wiggert/Documents/pr254/spectra/weekend1/chained/x1pos-peak-drift-with-time-we1.C");

  ch->Draw("calEx:Entry$","gates","col");
  c1->SaveAs("/home/wiggert/Documents/pr254/spectra/weekend1/chained/Ex-peak-drift-with-time-we1.png");
  c1->SaveAs("/home/wiggert/Documents/pr254/spectra/weekend1/chained/Ex-peak-drift-with-time-we1.C");


}
