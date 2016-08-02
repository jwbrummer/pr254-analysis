// Written by JWB on 19/07/2016. This script draws all separation energy spectra for the 24Mg runs of PR254.
// Look in the PhD logbook of JWB (from page 13 onward) for an explanation of separation energy spectra
// and where the "22./21." comes from.

{
  int runs[109]={1040,1041,1043,1046,1049,1051,1053,1056,1059,1062,1063,1064,1066,1067,1068,1072,1073,1074,1076,1077,1078,1079,2012,2014,2015,2017,2018,2019,2021,2022,2024,2025,2027,2028,2030,2031,2034,2035,2037,2038,2040,2041,2043,2044,2056,2057,2058,2060,2061,2062,2063,2066,2068,2069,2071,2072,2074,2075,2077,2079,2080,2082,2083,2085,3025,3026,3031,3032,3035,3036,3038,3039,3042,3056,3059,3062,3063,3067,3068,3071,3072,3075,3076,3079,3080,3083,3084,3087,3088,3091,3092,3095,3096,3099,3100,3103,3104,3107,3108,3109,3112,3113,3115,3118,3119,3120,3123,3124,3125};

  for(int i=0;i<109;i++)
    {
      if(runs[i]<2012)
	{
	  if(runs[i]<1056)
	    {
	      char we1Buffer[256];
	      sprintf(we1Buffer,"/home/wiggert/Documents/pr254/sortedRuns/weekend1/sorted0%d.root",runs[i]);
	      TFile *file_we1 = TFile::Open(we1Buffer);
	      if(runs[i]==1040)
		{
		  gROOT->ProcessLine(".x /home/wiggert/Documents/pr254/spectra/weekend1/pid/CUTpad1vstofRun1040.C");
		}

	      DATA->SetAlias("gates","CUTpad1vstofRun1040 && !X1flag && !X2flag && !U1flag");
	      DATA->SetAlias("X1posCorr","X1pos-2.81227*thetaSCAT-0.00172417*thetaSCAT*thetaSCAT");
	      DATA->SetAlias("calEx","17.5986-0.0232139*X1posCorr+4.97401e-6*X1posCorr*X1posCorr");
	      char histName[256];
	      sprintf(histName,"22./21.*EnergyFront-calEx*1000:StripFront>>hSeparationEnergyRun%d(16,0,16,3000,-7000,-3000)",runs[i]);
	      DATA->Draw(histName,"gates","col");
	      c1->SetWindowSize(1500,800);
	      /*
		char axName[256];
		sprintf(axName,"hSeparationEnergyRun%d",runs[i]);
		axName->GetXaxis()->SetTitle("x-axis");
		axName->GetYaxis()->SetTitle("y-axis");
	      */
	    }//end of if-statement for weekend 1, field-settings 1
	  else if(runs[i]>=1056 && runs[i]<1076)
	    {
	      char we1Buffer[256];
	      sprintf(we1Buffer,"/home/wiggert/Documents/pr254/sortedRuns/weekend1/sorted0%d.root",runs[i]);
	      TFile *file_we1 = TFile::Open(we1Buffer);
	      if(runs[i]==1056)
		{
		  gROOT->ProcessLine(".x /home/wiggert/Documents/pr254/spectra/weekend1/pid/CUTpad1vstofRun1056.C");
		}

	      DATA->SetAlias("gates","CUTpad1vstofRun1056 && !X1flag && !X2flag && !U1flag");
	      DATA->SetAlias("X1posCorr","X1pos-3.48147*thetaSCAT-0.082033*thetaSCAT*thetaSCAT");
	      DATA->SetAlias("calEx","17.8034-0.0239224*X1posCorr+5.56636e-6*X1posCorr*X1posCorr");
	      char histName[256];
	      sprintf(histName,"22./21.*EnergyFront-calEx*1000:StripFront>>hSeparationEnergyRun%d(16,0,16,3000,-7000,-3000)",runs[i]);
	      DATA->Draw(histName,"gates","col");
	      c1->SetWindowSize(1500,800);
	    }//end of if-statement for weekend 1, field-settings 2
	  else
	    {
	      char we1Buffer[256];
	      sprintf(we1Buffer,"/home/wiggert/Documents/pr254/sortedRuns/weekend1/sorted0%d.root",runs[i]);
	      TFile *file_we1 = TFile::Open(we1Buffer);
	      if(runs[i]==1076)
		{
		  gROOT->ProcessLine(".x /home/wiggert/Documents/pr254/spectra/weekend1/pid/CUTpad1vstofRun1076.C");
		}

	      DATA->SetAlias("gates","CUTpad1vstofRun1076 && !X1flag && !X2flag && !U1flag");
	      DATA->SetAlias("X1posCorr","X1pos-4.74105*thetaSCAT-0.187907*thetaSCAT*thetaSCAT");
	      DATA->SetAlias("calEx","20.2834-0.0290043*X1posCorr+9.35917e-6*X1posCorr*X1posCorr");
	      char histName[256];
	      sprintf(histName,"22./21.*EnergyFront-calEx*1000:StripFront>>hSeparationEnergyRun%d(16,0,16,3000,-7000,-3000)",runs[i]);
	      DATA->Draw(histName,"gates","col");
	      c1->SetWindowSize(1500,800);
	    }//end of if-statement for weekend 1, field-settings 3
	  	  
	  char pngName[256];
	  char cName[256];
	  sprintf(pngName,"/home/wiggert/Documents/pr254/spectra/weekend1/separation-energy/separation-energy-spectrum-Run%d.png",runs[i]);
	  sprintf(cName,"/home/wiggert/Documents/pr254/spectra/weekend1/separation-energy/separation-energy-spectrum-Run%d.C",runs[i]);
	  c1->SaveAs(pngName);
	  c1->SaveAs(cName);
	}
      else if (runs[i]>=2012 && runs[i]<3025)
	{
	  if(runs[i]<2066)
	    {
	      char we2Buffer[256];
	      sprintf(we2Buffer,"/home/wiggert/Documents/pr254/sortedRuns/weekend2/sorted0%d.root",runs[i]);
	      TFile *file_we2 = TFile::Open(we2Buffer);
	      if(runs[i]==2012)
		{
		  gROOT->ProcessLine(".x /home/wiggert/Documents/pr254/spectra/weekend2/pid/CUTpad1vstofRun2012.C");
		}

	      DATA->SetAlias("gates","CUTpad1vstofRun2012 && !X1flag && !X2flag && !U1flag");
	      DATA->SetAlias("X1posCorr","X1pos-3.50214*thetaSCAT-0.0785534*thetaSCAT*thetaSCAT");
	      DATA->SetAlias("calEx","19.096-0.0271916*X1posCorr+8.37548e-6*X1posCorr*X1posCorr");
	      char histName[256];
	      sprintf(histName,"22./21.*EnergyFront-calEx*1000:StripFront>>hSeparationEnergyRun%d(16,0,16,3000,-7000,-3000)",runs[i]);
	      DATA->Draw(histName,"gates","col");
	      c1->SetWindowSize(1500,800);
	    }//end of if-statement for weekend 2, field-settings 1
	  else
	    {
	      
	      char we2Buffer[256];
	      sprintf(we2Buffer,"/home/wiggert/Documents/pr254/sortedRuns/weekend2/sorted0%d.root",runs[i]);
	      TFile *file_we2 = TFile::Open(we2Buffer);
	      if(runs[i]==2066)
		{
		  gROOT->ProcessLine(".x /home/wiggert/Documents/pr254/spectra/weekend2/pid/CUTpad1vstofRun2066.C");
		}

	      DATA->SetAlias("gates","CUTpad1vstofRun2066 && !X1flag && !X2flag && !U1flag");
	      DATA->SetAlias("X1posCorr","X1pos-3.56117*thetaSCAT-0.0521338*thetaSCAT*thetaSCAT");
	      DATA->SetAlias("calEx","19.7331-0.0267545*X1posCorr+7.51906e-6*X1posCorr*X1posCorr");
	      char histName[256];
	      sprintf(histName,"22./21.*EnergyFront-calEx*1000:StripFront>>hSeparationEnergyRun%d(16,0,16,3000,-7000,-3000)",runs[i]);
	      DATA->Draw(histName,"gates","col");
	      c1->SetWindowSize(1500,800);
	    }//end of if-statement for weekend 2, field-settings 2  

	  char pngName[256];
	  char cName[256];
	  sprintf(pngName,"/home/wiggert/Documents/pr254/spectra/weekend2/separation-energy/separation-energy-spectrum-Run%d.png",runs[i]);
	  sprintf(cName,"/home/wiggert/Documents/pr254/spectra/weekend2/separation-energy/separation-energy-spectrum-Run%d.C",runs[i]);
	  c1->SaveAs(pngName);
	  c1->SaveAs(cName);
	}//end of weekend 2 code

      else
	{
	  char we3Buffer[256];
	  sprintf(we3Buffer,"/home/wiggert/Documents/pr254/sortedRuns/weekend3/sorted0%d.root",runs[i]);
	  TFile *file_we3 = TFile::Open(we3Buffer);
	  if(runs[i]==3025)
	    {
	      gROOT->ProcessLine(".x /home/wiggert/Documents/pr254/spectra/weekend3/pid/CUTpad1vstofRun3025.C");
	    }
	  DATA->SetAlias("gates","CUTpad1vstofRun3025 && !X1flag && !X2flag && !U1flag");
	  DATA->SetAlias("X1posCorr","X1pos-3.96147*thetaSCAT-0.110965*thetaSCAT*thetaSCAT");
	  DATA->SetAlias("calEx","18.3874-0.0234076*X1posCorr+4.92999e-6*X1posCorr*X1posCorr");
	  char histName[256];
	  sprintf(histName,"22./21.*EnergyFront-calEx*1000:StripFront>>hSeparationEnergyRun%d(16,0,16,3000,-7000,-3000)",runs[i]);
	  DATA->Draw(histName,"gates","col");
	  c1->SetWindowSize(1500,800);

	  char pngName[256];
	  char cName[256];
	  sprintf(pngName,"/home/wiggert/Documents/pr254/spectra/weekend3/separation-energy/separation-energy-spectrum-Run%d.png",runs[i]);
	  sprintf(cName,"/home/wiggert/Documents/pr254/spectra/weekend3/separation-energy/separation-energy-spectrum-Run%d.C",runs[i]);
	  c1->SaveAs(pngName);
	  c1->SaveAs(cName);

	}//end of weekend 3 code
    }//end of for loop
}//end of file
