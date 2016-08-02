// Written by JWB during June 2016. A simple script that merely chains all weekend 2 24Mg runs together.

{
   int runs[42] = {2012,2014,2015,2017,2018,2019,2021,2022,2024,2025,2027,2028,2030,2031,2034,2035,2037,2038,2040,2041,2043,2044,2056,2057,2058,2060,2061,2062,2063,2066,2068,2069,2071,2072,2074,2075,2077,2079,2080,2082,2083,2085};
	
	TChain *ch = new TChain("DATA");
	
	for(int i=0;i<42;i++)
		{
			char buffer[256];
			sprintf(buffer,"~/Documents/pr254/sortedRuns/sorted0%d.root",runs[i]);
			printf(buffer);
			printf("\n");
			ch->Add(buffer);
		}
	//ch2->Print();
	printf("\nWeekend 2 24Mg runs added to chain ch.\n");
}
