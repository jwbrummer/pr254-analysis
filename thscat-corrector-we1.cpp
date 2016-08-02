// Written by JWB on 10/07/2016. This script does the line-shape correction for all 24Mg runs of weekend 1.
// The line-shape correction is necessary to correct for the tilt in the ThSCATvX1pos spectrum which will
// lead to a poor peak resolution if not fixed.

{
  int runs[22] = {1040,1041,1043,1046,1049,1051,1053,1056,1059,1062,1063,1064,1066,1067,1068,1072,1073,1074,1076,1077,1078,1079};
  /* Regions of similar field settings:
     1040-1053
     1056-1074
     1076-1079
  */
   
  for(int i=0;i<22;i++)
    {
      if(runs[i]<1056)
	{
	  if(runs[i]==1040)
	    {
	      gROOT->ProcessLine(".x /home/wiggert/Documents/pr254/spectra/weekend1/pid/CUTpad1vstofRun1040.C");
	    }
	  char runNum[256];
	  sprintf(runNum,"/home/wiggert/Documents/pr254/sortedRuns/weekend1/sorted0%d.root",runs[i]);
	  TFile *file = TFile::Open(runNum);
	  
	  char buffer1[256];
	  sprintf(buffer1,"thetaSCAT:X1pos-2.81227*thetaSCAT-0.00172417*thetaSCAT*thetaSCAT>>hThSCATvX1posRun%d(500,0,800,500,-10,0)",runs[i]);
	  DATA->Draw(buffer1,"CUTpad1vstofRun1040 && !X1flag && !X2flag && !U1flag","col");
	}
      else if(runs[i]>=1056 && runs[i]<1076)
	{
	  if(runs[i]==1056)
	    {
	      gROOT->ProcessLine(".x /home/wiggert/Documents/pr254/spectra/weekend1/pid/CUTpad1vstofRun1056.C");
	    }
	  char runNum[256];
	  sprintf(runNum,"/home/wiggert/Documents/pr254/sortedRuns/weekend1/sorted0%d.root",runs[i]);
	  TFile *file = TFile::Open(runNum);

	  char buffer1[256];
	  sprintf(buffer1,"thetaSCAT:X1pos-3.48147*thetaSCAT-0.082033*thetaSCAT*thetaSCAT>>hThSCATvX1posRun%d(500,0,800,500,-10,0)",runs[i]);
	  DATA->Draw(buffer1,"CUTpad1vstofRun1056 && !X1flag && !X2flag && !U1flag","col");
  	}
      else
	{
	  if(runs[i]==1076)
	    {
	      gROOT->ProcessLine(".x /home/wiggert/Documents/pr254/spectra/weekend1/pid/CUTpad1vstofRun1076.C");
	    }
	  char runNum[256];
	  sprintf(runNum,"/home/wiggert/Documents/pr254/sortedRuns/weekend1/sorted0%d.root",runs[i]);
	  TFile *file = TFile::Open(runNum);

	  char buffer1[256];
	  sprintf(buffer1,"thetaSCAT:X1pos-4.74105*thetaSCAT-0.187907*thetaSCAT*thetaSCAT>>hThSCATvX1posRun%d(500,0,800,500,-10,0)",runs[i]);
	  DATA->Draw(buffer1,"CUTpad1vstofRun1076 && !X1flag && !X2flag && !U1flag","col");
	}
      
      c1->SetWindowPosition(1500,500);
      char pngName[256];
      char cName[256];
      char rootName[256];
      
      sprintf(pngName,"/home/wiggert/Documents/pr254/spectra/weekend1/thscat/X1posCorrRun%d.png",runs[i]);
      sprintf(cName,"/home/wiggert/Documents/pr254/spectra/weekend1/thscat/X1posCorrRun%d.C",runs[i]);
      sprintf(rootName,"/home/wiggert/Documents/pr254/spectra/weekend1/thscat/X1posCorrRun%d.root",runs[i]);
      
      c1->SaveAs(pngName);
      c1->SaveAs(cName);
      c1->SaveAs(rootName);
    }
}
