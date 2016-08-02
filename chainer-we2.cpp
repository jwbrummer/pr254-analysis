// Written by JWB during June 2016. This script chains all of the weekend 2 24Mg runs together and proceeds to draw a chained
// and calibrated excitation energy spectrum after taking the line-shape correction, X1posCorr, into account.

{
   int runs[42] = {2012,2014,2015,2017,2018,2019,2021,2022,2024,2025,2027,2028,2030,2031,2034,2035,2037,2038,2040,2041,2043,2044,2056,2057,2058,2060,2061,2062,2063,2066,2068,2069,2071,2072,2074,2075,2077,2079,2080,2082,2083,2085};
	
	TChain *ch = new TChain("DATA");
	
	for(int i=0;i<42;i++)
		{
			char buffer[256];
			sprintf(buffer,"/home/wiggert/Documents/pr254/sortedRuns/weekend2/sorted0%d.root",runs[i]);
			printf(buffer);
			printf("\n");
			ch->Add(buffer);
		}

	ch->Print();

	ch->SetAlias("X1posCorr","X1pos - 3.40739*thetaSCAT - 0.079275*thetaSCAT*thetaSCAT");
	ch->SetAlias("newEx","16.8511 - 0.0215884*X1posCorr + 3.49076e-6*X1posCorr*X1posCorr");

	gROOT->ProcessLine(".x /home/wiggert/Documents/pr254/spectra/weekend1/CUTpad1vstofRun1040.C");

	ch->Draw("newEx>>hEx(12000,2,14)","CUTpad1vstofRun1040 && !X1flag && !X2flag && !U1flag","");
}
