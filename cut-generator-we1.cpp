// Written by JWB on 09/07/2016. This script makes three different cuts for the three different field settings experience during weekend 1.
// The end results is that this script make PID cuts for all weekend 1 24Mg runs.

{
  int runs[22] = {1040,1041,1043,1046,1049,1051,1053,1056,1059,1062,1063,1064,1066,1067,1068,1072,1073,1074,1076,1077,1078,1079};
  
  for(int i=0;i<22;i++)
    {
      char sortNum[256];
      sprintf(sortNum,"/home/wiggert/Documents/pr254/sortedRuns/weekend1/sorted0%d.root",runs[i]);
      TFile *_file0 = TFile::Open(sortNum);
      
      char buffer[256];
      sprintf(buffer,"pad1:tof>>hPad1vsTOFRun%d(500,3200,3600,500,500,2000)",runs[i]);
      DATA->Draw(buffer,"abs(tof)<1e4 && !X1flag && !X2flag && !U1flag","col");

      if(runs[i]<1056)
      	{
	  char buffer2[256];
	  sprintf(buffer2,"CUTpad1vstofRun%d",runs[i]);
	  TCutG *cutg = new TCutG(buffer2,13);
	  cutg->SetVarX("tof");
	  cutg->SetVarY("pad1");
	  cutg->SetTitle("Graph");
	  cutg->SetFillColor(1);
	  cutg->SetPoint(0,3491.81,1609.75);
	  cutg->SetPoint(1,3487.5,1447.67);
	  cutg->SetPoint(2,3505.1,1180.72);
	  cutg->SetPoint(3,3546.41,964.619);
	  cutg->SetPoint(4,3581.97,847.034);
	  cutg->SetPoint(5,3613.22,847.034);
	  cutg->SetPoint(6,3621.84,1005.93);
	  cutg->SetPoint(7,3616.81,1171.19);
	  cutg->SetPoint(8,3585.92,1425.42);
	  cutg->SetPoint(9,3554.67,1651.06);
	  cutg->SetPoint(10,3520.91,1787.71);
	  cutg->SetPoint(11,3494.68,1717.8);
	  cutg->SetPoint(12,3491.81,1609.75);
	  cutg->Draw("SAME");
      	}
      else if(runs[i]>=1056 && runs[i]<1076)
	{
	  char buffer2[256];
	  sprintf(buffer2,"CUTpad1vstofRun%d",runs[i]);
	  TCutG *cutg = new TCutG(buffer2,13);
	  cutg->SetVarX("tof");
	  cutg->SetVarY("pad1");
	  cutg->SetTitle("Graph");
	  cutg->SetFillColor(1);
	  cutg->SetPoint(0,3487.5,1755.93);
	  cutg->SetPoint(1,3516.95,1736.86);
	  cutg->SetPoint(2,3554.31,1409.53);
	  cutg->SetPoint(3,3585.92,1158.47);
	  cutg->SetPoint(4,3598.49,955.085);
	  cutg->SetPoint(5,3571.19,815.254);
	  cutg->SetPoint(6,3553.23,821.61);
	  cutg->SetPoint(7,3519.83,942.373);
	  cutg->SetPoint(8,3487.5,1094.92);
	  cutg->SetPoint(9,3468.82,1314.19);
	  cutg->SetPoint(10,3461.28,1539.83);
	  cutg->SetPoint(11,3463.79,1708.26);
	  cutg->SetPoint(12,3487.5,1755.93);
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
	  cutg->SetPoint(0,3453.81,1733.69);
	  cutg->SetPoint(1,3482.77,1517.58);
	  cutg->SetPoint(2,3515.45,1355.51);
	  cutg->SetPoint(3,3549.07,1155.3);
	  cutg->SetPoint(4,3548.61,939.195);
	  cutg->SetPoint(5,3521.99,815.254);
	  cutg->SetPoint(6,3469.22,926.483);
	  cutg->SetPoint(7,3418.33,1180.72);
	  cutg->SetPoint(8,3404.32,1396.82);
	  cutg->SetPoint(9,3421.13,1752.75);
	  cutg->SetPoint(10,3453.81,1733.69);
	  cutg->Draw("SAME");
	}
      char pngName[256];
      char cName[256];
      sprintf(pngName,"/home/wiggert/Documents/pr254/spectra/weekend1/pid/CUTpad1vstofRun%d.png",runs[i]);
      sprintf(cName,"/home/wiggert/Documents/pr254/spectra/weekend1/pid/CUTpad1vstofRun%d.C",runs[i]);
      c1->SaveAs(pngName);
      c1->SaveAs(cName);
    }
}
