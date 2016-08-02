// Written by JWB on 17/07/2016 to generate the calibrated excitation energy spectra and generate the peak offsets. This script is redundant as it was replaced
// by the script "tspectra-offsets.cpp".

#include <TFile.h>
#include <TTree.h>
#include <TH1.h>
#include <TSpectrum.h>
#include <TCanvas.h>
#include <TF1.h>
#include <TGraph.h>
#include <iostream>
#include <fstream>
#include <TAxis.h>
#include <TH2.h>

// Only need to get offset which is caused by beam dispersion. Do not need to get gains.
double offset[109];
int runs[109]={1040,1041,1043,1046,1049,1051,1053,1056,1059,1062,1063,1064,1066,1067,1068,1072,1073,1074,1076,1077,1078,1079,2012,2014,2015,2017,2018,2019,2021,2022,2024,2025,2027,2028,2030,2031,2034,2035,2037,2038,2040,2041,2043,2044,2056,2057,2058,2060,2061,2062,2063,2066,2068,2069,2071,2072,2074,2075,2077,2079,2080,2082,2083,2085,3025,3026,3031,3032,3035,3036,3038,3039,3042,3056,3059,3062,3063,3067,3068,3071,3072,3075,3076,3079,3080,3083,3084,3087,3088,3091,3092,3095,3096,3099,3100,3103,3104,3107,3108,3109,3112,3113,3115,3118,3119,3120,3123,3124,3125};
  
double state_E[5] = {5423.15, 5685.37, 6288.08, 6778.3, 8784.86}; //get the energies of each state (in MeV) from nndc to know by how much the peaks should shift.


void Calibration()
{
  ofstream mOutput;
  mOutput.open("x1pos-peak-offset.dat"); //create a datafile into which the results are read; these values are then put into the switch-case structure in main.c

  for(int i=0;i<109;i++)
    {
      offset[i] = 0;
      TCanvas *c1 = new TCanvas("c1","c1",800,600);
      c1->SetWindowPosition(1500,300);
      if(runs[i]<2012)
	{
	  char buffer[256];
	  sprintf(buffer,"/home/wiggert/Document/pr254/spectra/weekend1/x1pos/X1pos2DRun%d.root",runs[i]);
	  TFile *fin = TFile::Open(buffer);
	  TH1F *h = (TH1F*)fin->FindObjectAny("hCalX1posRun");
      
	  h->Rebin(4);
	  h->Draw();
	  //h->GetXaxis()->SetRangeUser(500,4000); Do I need to use this? What does this do?
	  TSpectrum *sp = new TSpectrum();
	  sp->Search(h,2,"",0.7);
	  //sp->Search: histo name, sigma,earch parameter, 0-1 parameter where 1 only finds highest peak and 0 will descend into the background and find too many peaks.





	  char pngBuffer[256];
	  sprintf(pngBuffer,"/home/wiggert/Documents/pr254/spectra/weekend1/x1pos-peak-search/x1pos-peak-search-run%d.png",runs[i]);
	  c1->SaveAs(pngBuffer);
	}
      else if(runs[i]>=2012 && runs[i]<3025)
	{
	  char buffer[256];
	  sprintf(buffer,"/home/wiggert/Document/pr254/spectra/weekend2/x1pos/X1pos2DRun%d.root",runs[i]);
	  TFile *fin = TFile::Open(buffer);
	  TH1F *h = (TH1F*)fin->FindObjectAny("hCalX1posRun");
      
	  h->Rebin(4);
	  h->Draw();
	  //h->GetXaxis()->SetRangeUser(500,4000); 
	  TSpectrum *sp = new TSpectrum();
	  sp->Search(h,2,"",0.7);



	  
	  char pngBuffer[256];
	  sprintf(pngBuffer,"/home/wiggert/Documents/pr254/spectra/weekend2/x1pos-peak-search/x1pos-peak-search-run%d.png",runs[i]);
	  c1->SaveAs(pngBuffer);
	}
      else
	{
	  char buffer[256];
	  sprintf(buffer,"/home/wiggert/Document/pr254/spectra/weekend3/x1pos/X1pos2DRun%d.root",runs[i]);
	  TFile *fin = TFile::Open(buffer);
	  TH1F *h = (TH1F*)fin->FindObjectAny("hCalX1posRun");
      
	  h->Rebin(4);
	  h->Draw();
	  //h->GetXaxis()->SetRangeUser(500,4000); 
	  TSpectrum *sp = new TSpectrum();
	  sp->Search(h,2,"",0.7);

	  float *peak_pos = sp->GetPositionX();
	  //peaks should be in the correct order; need to check if that code needs to be included.
	  TGraph *g = new TGraph();
	  for(int i=0;i<5;i++)
	    {
	      g->SetPoint(n,peak_pos[n],state_E[n]);//setting points to plot all of the peak positions against their energies
	    }
	  TF1 *fit = new TF1("peak_fit","y=mx+c -> [0]+[1]*x",0,10000);
	  g->Fit(peak_fit,"Q");
	  g->Draw("L* same");
	  offset[i] = peak_fit->GetParameter(0);//the zeroth order parameter is the offset, whereas the first order parameter is the gain.
	  char pngBuffer[256];
	  sprintf(pngBuffer,"/home/wiggert/Documents/pr254/spectra/weekend3/x1pos-peak-search/x1pos-peak-search-run%d.png",runs[i]);
	  c1->SaveAs(pngBuffer);
	}
      mOutput.close();
    }
}
/*if(i<128-8)
  {
    TSpectrum *sp = new TSpectrum();
    sp->Search(h,3,"",0.4);//histo name, sigma,earch parameter, 0-1 parameter where 1 only finds highest peak and 0 will descend into the background and find too many peaks.
	  
    if(sp->GetNPeaks()==5)
      {
	float *chan = sp->GetPositionX();
	for(int n=0;n<4;n++){//Ensure that the peaks are in the right order...
	  for(int nn=n+1;nn<5;nn++){
	    if(chan[nn]<chan[n]){
	      float chan_tmp = chan[n];
	      chan[n]=chan[nn];
	      chan[nn]=chan_tmp;
	    }}}
	TGraph *g = new TGraph();
	for(int n=0;n<5;n++){g->SetPoint(n,chan[n],alpha_E[n]);}
	TF1 *fit = new TF1("fit","[0]+[1]*x",0,10000);
	g->Fit(fit,"Q");
	g->Draw("L* same");
	offset[i] = fit->GetParameter(0);
	gains[i] = fit->GetParameter(1);
      }
    else if(sp->GetNPeaks()==6)
      {
	float *chan = sp->GetPositionX();
	for(int n=0;n<5;n++){
	  for(int nn=n+1;nn<6;nn++){
	    if(chan[nn]<chan[n]){
	      float chan_tmp = chan[n];
	      chan[n] = chan[nn];
	      chan[nn] = chan_tmp;
	    }}}
	TGraph *g = new TGraph();
	for(int n=0;n<5;n++){g->SetPoint(n,chan[n+1],alpha_E[n]);}
	TF1 *fit = new TF1("fit","[0]+[1]*x",0,10000);
	g->Fit(fit,"Q");
	g->Draw("L* same");
	offset[i] = fit->GetParameter(0);
	gains[i] = fit->GetParameter(1);
      }
  }
 else{offset[i] = 0; gains[i] = 1;}
mOutput << i << "\t" << offset[i] << "\t" << gains[i] << endl;
sprintf(buffer,"CalibFiles/FithADC_%d.png",i);
c1->SaveAs(buffer);

for(int j=0;j<h->GetXaxis()->GetNbins();j++)
  {
    CalibADCs->Fill(offset[i]+gains[i]*h->GetXaxis()->GetBinCenter(j),i,h->GetBinContent(j));
  }
}
mOutput.close();
unCalibADCs->SaveAs("unCalibADCs.root");
CalibADCs->SaveAs("CalibADCs.root");
}
*/
