// Written by Dr. P. Adsley to generate the ADC histograms and save them as root files so that the histograms may be recalled when using the TSpectrum function.
{
  TFile *fin = TFile::Open("sorted00063.root");
  TTree *trin = (TTree*)fin->FindObjectAny("DATA");

  for(int i=0;i<128;i++)
    {
      char buffer[256];
      
      //TFile *fout = new TFile(buffer,"RECREATE");
      sprintf(buffer,"ADCValues[%d]>>hADC(12000,500,12500)",i);
      trin->Draw(buffer,"","");
      TH1F *hADC = gROOT->FindObjectAny("hADC");
      sprintf(buffer,"CalibFiles/hADC_%d.root",i);
      hADC->SaveAs(buffer);
    }
}
