// This was written by JWB on 20/07/2016 to generate calibrated-position tspectra for all 24Mg runs from PR254 with their peak positions found.
// The script also determines the offset for each run by looking at how many peaks were found.

{
  //There are 22, 42 and 45 24Mg runs for WE1, WE2 and WE3 respectively for a total of 109 runs.
  //Run numbers that signifiy the start of a new set of field settings are: 1040, 1056, 1076, 2012, 2066, 3025.
   
  int runs[109]={1040,1041,1043,1046,1049,1051,1053,1056,1059,1062,1063,1064,1066,1067,1068,1072,1073,1074,1076,1077,1078,1079,2012,2014,2015,2017,2018,2019,2021,2022,2024,2025,2027,2028,2030,2031,2034,2035,2037,2038,2040,2041,2043,2044,2056,2057,2058,2060,2061,2062,2063,2066,2068,2069,2071,2072,2074,2075,2077,2079,2080,2082,2083,2085,3025,3026,3031,3032,3035,3036,3038,3039,3042,3056,3059,3062,3063,3067,3068,3071,3072,3075,3076,3079,3080,3083,3084,3087,3088,3091,3092,3095,3096,3099,3100,3103,3104,3107,3108,3109,3112,3113,3115,3118,3119,3120,3123,3124,3125};
  
  double offset[109];
  //double state_E[7]={3.30822,4.4020,5.0354,5.7114,5.9538,6.0430,7.3380};
  double peak=7.3380;
  ofstream offsetOutput;
  offsetOutput.open("/home/wiggert/Documents/pr254/codes/runOffsets.dat");

  for (int i=0;i<109;i++)
    {
      offset[i]=0;
      char histName[256];
if(runs
      sprintf(histName,"~/Documents/pr254/sortedRuns/weekend1/sorted0%d.root",runs[i]);
      TFile *fin = TFile::Open(histName);
      TH1F *h = (TH1F*)fin->FindObjectAny("hCalX1posRun");
      h->Draw();
      TSpectrum *sp = new TSpectrum();
      sp->Search(h,1,"",0.5);
double temp = sp->GetPositionX();
offset[i] = peak-temp;
      //TSpectrum parameters: histo name, sigma, search parameter, 0-1 parameter where 1 only finds highest peak and 0 will descend into the background and find too many peaks.
      
  /*    //int peakNum = sp->GetNPeaks();
      //float *peaks = sp->GetPositionX();


      for(int i=0;i<peakNum;i++)
	{
int stateNum = 0;
	  for(int j=0;j<7;j++)
	    {
	      int min;
	      if(j==0)
		{
		  min = abs(peaks[]-state_E[j]);
stateNum=j;
		}
	      else
		{
		  int temp = abs(peaks[]-state_E[j]);
		  if (temp<min)
		    {
		      min = temp;
stateNum=j;
		    }
		}
	    }

	}
offset[i] = ?*/
      //need to test by printing output into the .dat file to see what TSpectrum finds

      offsetOutput << "case " << runs[i] << ": x1offset=" << offset[i] << "; printf("run %d: x1 offset= %f \n",runinfo2.run_number,x1offset); break;" << endl;
    }//end of for-loop
  offsetOutput.close();
}//end of file

