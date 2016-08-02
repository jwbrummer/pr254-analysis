// Written by JWB during June 2016. This script chains all of the weekend 1 24Mg runs together and proceeds to draw a chained
// and calibrated excitation energy spectrum after taking the line-shape correction, X1posCorr, into account.

{
   int runs[22] = {1040,1041,1043,1046,1049,1051,1053,1056,1059,1062,1063,1064,1066,1067,1068,1072,1073,1074,1076,1077,1078,1079};
	
	TChain *ch = new TChain("DATA");
	
	for(int i=0;i<22;i++)
		{
			char buffer[256];
			sprintf(buffer,"/home/wiggert/Documents/pr254/sortedRuns/weekend1/sorted0%d.root",runs[i]);
			printf(buffer);
			printf("\n");
			ch->Add(buffer);
		}

	ch->Print();

	ch->SetAlias("X1posCorr","X1pos - 3.40739*thetaSCAT - 0.079275*thetaSCAT*thetaSCAT");
	ch->SetAlias("newEx","16.8511 - 0.0215884*X1posCorr + 3.49076e-6*X1posCorr*X1posCorr");

	gROOT->ProcessLine(".x /home/wiggert/Documents/spectra/weekend1/pid/CUTpad1vstofRun1040.C");

	ch->Draw("newEx>>hEx(12000,2,14)","CUTpad1vstofRun1040 && !X1flag && !X2flag && !U1flag","");
}
