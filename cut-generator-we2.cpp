// Written by JWB on 09/07/2016. This script makes two different cuts for the two different field settings experience during weekend 2.
// The end results is that this script make PID cuts for all weekend 2 24Mg runs.

{
  int runs[42] = {2012,2014,2015,2017,2018,2019,2021,2022,2024,2025,2027,2028,2030,2031,2034,2035,2037,2038,2040,2041,2043,2044,2056,2057,2058,2060,2061,2062,2063,2066,2068,2069,2071,2072,2074,2075,2077,2079,2080,2082,2083,2085};
  
  for(int i=0;i<42;i++)
    {
      char sortNum[256];
      sprintf(sortNum,"/home/wiggert/Documents/pr254/sortedRuns/weekend2/sorted0%d.root",runs[i]);
      TFile *_file0 = TFile::Open(sortNum);
      
      char buffer[256];
      sprintf(buffer,"pad1:tof>>hPad1vsTOFRun%d(500,3200,3600,500,500,2000)",runs[i]);
      DATA->Draw(buffer,"abs(tof)<1e4 && !X1flag && !X2flag && !U1flag","col");
      c1->SetWindowPosition(0,500);
      if(runs[i]<2066)
	{
	  char buffer2[256];
	  sprintf(buffer2,"CUTpad1vstofRun%d",runs[i]);
	  TCutG *cutg = new TCutG(buffer2,15);
	  cutg->SetVarX("tof");
	  cutg->SetVarY("pad1");
	  cutg->SetTitle("Graph");
	  cutg->SetFillColor(1);
	  cutg->SetPoint(0,3490.88,1921.35);
	  cutg->SetPoint(1,3520.51,1683);
	  cutg->SetPoint(2,3547,1496.29);
	  cutg->SetPoint(3,3576.63,1353.28);
	  cutg->SetPoint(4,3599.53,1174.52);
	  cutg->SetPoint(5,3599.08,960.011);
	  cutg->SetPoint(6,3587.86,828.919);
	  cutg->SetPoint(7,3562.27,793.167);
	  cutg->SetPoint(8,3508.84,928.231);
	  cutg->SetPoint(9,3481,1126.85);
	  cutg->SetPoint(10,3460.34,1365.2);
	  cutg->SetPoint(11,3446.87,1607.52);
	  cutg->SetPoint(12,3450.02,1810.12);
	  cutg->SetPoint(13,3459.9,1929.29);
	  cutg->SetPoint(14,3490.88,1921.35);
	  cutg->Draw("SAME");
	}
      else
	{
	  char buffer2[256];
	  sprintf(buffer2,"CUTpad1vstofRun%d",runs[i]);
	  TCutG *cutg = new TCutG(buffer2,11);
	  cutg->SetVarX("tof");
	  cutg->SetVarY("pad1");
	  cutg->SetTitle("Graph");
	  cutg->SetFillColor(1);
	  cutg->SetPoint(0,3373.17,1861.76);
	  cutg->SetPoint(1,3408.73,1595.6);
	  cutg->SetPoint(2,3451.29,1309.59);
	  cutg->SetPoint(3,3475.54,1162.61);
	  cutg->SetPoint(4,3483.08,975.9);
	  cutg->SetPoint(5,3464.22,860.699);
	  cutg->SetPoint(6,3424.89,888.506);
	  cutg->SetPoint(7,3367.24,1095.07);
	  cutg->SetPoint(8,3337.61,1472.46);
	  cutg->SetPoint(9,3334.91,1754.5);
	  cutg->SetPoint(10,3373.17,1861.76);
	  cutg->Draw("SAME");
	}

      char pngName[256];
      char cName[256];

      sprintf(pngName,"/home/wiggert/Documents/pr254/spectra/weekend2/pid/CUTpad1vstofRun%d.png",runs[i]);
      sprintf(cName,"/home/wiggert/Documents/pr254/spectra/weekend2/pid/CUTpad1vstofRun%d.C",runs[i]);
      
      c1->SaveAs(pngName);
      c1->SaveAs(cName);
    }
}
