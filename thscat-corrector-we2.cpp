// Written by JWB on 10/07/2016. This script does the line-shape correction for all 24Mg runs of weekend 2.
// The line-shape correction is necessary to correct for the tilt in the ThSCATvX1pos spectrum which will
// lead to a poor peak resolution if not fixed.

{
  int runs[42] = {2012,2014,2015,2017,2018,2019,2021,2022,2024,2025,2027,2028,2030,2031,2034,2035,2037,2038,2040,2041,2043,2044,2056,2057,2058,2060,2061,2062,2063,2066,2068,2069,2071,2072,2074,2075,2077,2079,2080,2082,2083,2085};
    
  
  for(int i=0;i<42;i++)
    {
      if(runs[i]<2066)
	{
	  if(runs[i]==2012)
	    {
	      gROOT->ProcessLine(".x /home/wiggert/Documents/pr254/spectra/weekend2/pid/CUTpad1vstofRun2012.C");
	    }
	  char runNum[256];
	  sprintf(runNum,"/home/wiggert/Documents/pr254/sortedRuns/weekend2/sorted0%d.root",runs[i]);
	  TFile *file = TFile::Open(runNum);

	  char buffer1[256];
	  sprintf(buffer1,"thetaSCAT:X1pos-3.50214*thetaSCAT-0.0785534*thetaSCAT*thetaSCAT>>hThSCATvX1posRun%d(500,0,800,500,-10,0)",runs[i]);
	  DATA->Draw(buffer1,"CUTpad1vstofRun2012 && !X1flag && !X2flag && !U1flag","col");
	}
      else
	{
	  if(runs[i]==2066)
	    {
	      gROOT->ProcessLine(".x /home/wiggert/Documents/pr254/spectra/weekend2/pid/CUTpad1vstofRun2066.C");
	    }
	  char runNum[256];
	  sprintf(runNum,"/home/wiggert/Documents/pr254/sortedRuns/weekend2/sorted0%d.root",runs[i]);
	  TFile *file = TFile::Open(runNum);

	  char buffer1[256];
	  sprintf(buffer1,"thetaSCAT:X1pos-3.56117*thetaSCAT-0.0521338*thetaSCAT*thetaSCAT>>hThSCATvX1posRun%d(500,0,800,500,-10,0)",runs[i]);
	  DATA->Draw(buffer1,"CUTpad1vstofRun2066 && !X1flag && !X2flag && !U1flag","col");
  	}

      c1->SetWindowPosition(0,500);
      char pngName[256];
      char cName[256];
      char rootName[256];
      
      sprintf(pngName,"/home/wiggert/Documents/pr254/spectra/weekend2/thscat/X1posCorrRun%d.png",runs[i]);
      sprintf(cName,"/home/wiggert/Documents/pr254/spectra/weekend2/thscat/X1posCorrRun%d.C",runs[i]);
      sprintf(rootName,"/home/wiggert/Documents/pr254/spectra/weekend2/thscat/X1posCorrRun%d.root",runs[i]);
      
      c1->SaveAs(pngName);
      c1->SaveAs(cName);
      c1->SaveAs(rootName);
    }
}
