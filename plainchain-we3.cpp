// Written by JWB during June 2016. A simple script that merely chains all weekend 3 24Mg runs together.

{
   int runs[45] = {3025,3026,3031,3032,3035,3036,3038,3039,3042,3056,3059,3062,3063,3067,3068,3071,3072,3075,3076,3079,3080,3083,3084,3087,3088,3091,3092,3095,3096,3099,3100,3103,3104,3107,3108,3109,3112,3113,3115,3118,3119,3120,3123,3124,3125};
	
	TChain *ch = new TChain("DATA");
	
	for(int i=0;i<45;i++)
		{
			char buffer[256];
			sprintf(buffer,"~/Documents/pr254/sortedRuns/weekend3/sorted0%d.root",runs[i]);
			printf(buffer);
			printf("\n");
			ch->Add(buffer);
		}
	//ch2->Print();
	printf("\nWeekend 3 24Mg runs added to chain ch.\n");
}
