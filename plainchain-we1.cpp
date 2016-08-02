// Written by JWB during June 2016. A simple script that merely chains all weekend 1 24Mg runs together.

{
  int runs[22] = {1040,1041,1043,1046,1049,1051,1053,1056,1059,1062,1063,1064,1066,1067,1068,1072,1073,1074,1076,1077,1078,1079};
   	
	TChain *ch = new TChain("DATA");
	
	for(int i=0;i<22;i++)
		{
			char buffer[256];
			sprintf(buffer,"~/Documents/pr254/sortedRuns/weekend1/sorted0%d.root",runs[i]);
			printf(buffer);
			printf("\n");
			ch->Add(buffer);
		}
	printf("\nWeekend 1 24Mg runs added to chain *ch.\n");
}
