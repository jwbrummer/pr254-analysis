// Written by Dr. P. Adsley (Date: Unknown)
// This script is called in ~/.startup.cpp (on k600daq) and contains different spectra
// that are combined in one window to draw all spectra with merely one command
// which is convenient and generally useful during weekends running experiments with silicon
// detectors.

void draw_me(string histname)
{
	((TH2I*)a->GetSocketClientNetFolder()->FindObjectAny(histname.c_str()))->Draw();
}

void draw_me(string histname, string options)
{
	((TH2I*)a->GetSocketClientNetFolder()->FindObjectAny(histname.c_str()))->Draw(options.c_str());

}

void draw_me(string histname, string options, bool stats)
{
	//do draw_me("name","options",false) to suppress the stats box //Not currently working
	((TH2I*)a->GetSocketClientNetFolder()->FindObjectAny(histname.c_str()))->SetStats(0);
	((TH2I*)a->GetSocketClientNetFolder()->FindObjectAny(histname.c_str()))->Draw(options.c_str());
	((TH2I*)a->GetSocketClientNetFolder()->FindObjectAny(histname.c_str()))->SetStats(0);

}

void draw_me(string histname, double xmin, double xmax)
{
        TH2 *histo = ((TH2I*)a->GetSocketClientNetFolder()->FindObjectAny(histname.c_str()));
	histo->GetXaxis()->SetRangeUser(xmin, xmax);
	histo->Draw();
}


void draw_me(string histname, string options, double xmin, double xmax)
{
        TH2 *histo = ((TH2I*)a->GetSocketClientNetFolder()->FindObjectAny(histname.c_str()));
	histo->GetXaxis()->SetRangeUser(xmin, xmax);
	histo->Draw(options.c_str());
}

void draw_me(string histname, double xmin, double xmax, double ymin, double ymax)
{
	TH2 *histo = ((TH2I*)a->GetSocketClientNetFolder()->FindObjectAny(histname.c_str()));
	histo->GetXaxis()->SetRangeUser(xmin, xmax);
	histo->GetYaxis()->SetRangeUser(ymin, ymax);
	histo->Draw();
}

void draw_me(string histname, string options, double xmin, double xmax, double ymin, double ymax)
{
	TH2 *histo = ((TH2I*)a->GetSocketClientNetFolder()->FindObjectAny(histname.c_str()));
	histo->GetXaxis()->SetRangeUser(xmin, xmax);
	histo->GetYaxis()->SetRangeUser(ymin, ymax);
	histo->Draw(options.c_str());
}

void print_efficiencies()
{
	TH2 *histo = ((TH2I*)a->GetSocketClientNetFolder()->FindObjectAny("Efficiency_000"));
	cout << "Efficiency X1 \t" << histo->GetMean() << endl;
	TH2 *histo = ((TH2I*)a->GetSocketClientNetFolder()->FindObjectAny("Efficiency_001"));
	cout << "Efficiency U1 \t" << histo->GetMean() << endl;
	TH2 *histo = ((TH2I*)a->GetSocketClientNetFolder()->FindObjectAny("Efficiency_002"));
	cout << "Efficiency X2 \t" << histo->GetMean() << endl;
	TH2 *histo = ((TH2I*)a->GetSocketClientNetFolder()->FindObjectAny("Efficiency_003"));
	cout << "Efficiency U2 \t" << histo->GetMean() << endl;

}

//void draw_me_like_one_of_your_french_girls()
void draw_me_like_one_of_your_french_girls_oo_la_la()
{
  TCanvas *froggie = new TCanvas("froggie","Rose Dewitt Bukater",1170,960);
  froggie->Divide(2,2);

  froggie->cd(1);
  froggie->GetPad(1)->SetLineColor(3);
  (TH2I*)a->GetSocketClientNetFolder()->FindObjectAny("Position_000")->Draw();
  
  froggie->cd(2);
  froggie->GetPad(2)->SetLogz();
  (TH2I*)a->GetSocketClientNetFolder()->FindObjectAny("X1Y1")->Draw("col");
  
  froggie->cd(3);
  froggie->GetPad(3)->SetLogz();
  (TH2I*)a->GetSocketClientNetFolder()->FindObjectAny("ThSCATvsX1")->Draw("col");

  froggie->cd(4);
  //(TH2I*)a->GetSocketClientNetFolder()->FindObjectAny("Pad1vsTOF_000")->Draw("col");
  froggie->GetPad(4)->SetLogz();
  draw_me("Pad1vsTOF_000","col",2500,4000,0,2000);

  //c1->cd();
}

void draw_me_frontback()
{
********************************************************************************
Note the additions to make the canvasses automatically Log z
********************************************************************************

  TCanvas *cake = new TCanvas("cake","Chocolate Cake",1120,850);
  cake->Divide(3,2);
  
  TPad *p1 = cake->cd(1);
  p1->SetLogz();
  draw_me("SiFBADC_001","col",000,4000,0,4000);
  
  TPad *p2 = cake->cd(2);
  p2->SetLogz();
  draw_me("SiFBADC_002","col",000,4000,0,4000);

   TPad *p3 = cake->cd(3);
  p3->SetLogz();
  draw_me("SiFBADC_003","col",000,4000,0,4000);

  TPad *p4 = cake->cd(4);
  p4->SetLogz();
  draw_me("SiFBADC_004","col",000,4000,0,4000);

  TPad *p5 = cake->cd(5);
  p5->SetLogz();
  draw_me("SiFBADC_005","col",000,4000,0,4000);

  /* cake->cd(6);
     draw_me("K600vsCalSi","col");*/

  //c1->cd();
}

void draw_me_K600vsCalSi()
{
  TCanvas *bleh = new TCanvas("K600vsCalSi","K600vsCalSi",1170,900);
  bleh->cd(1);
  draw_me("K600vsCalSi","col");
}

void some_stuff()
{
  gROOT->ProcessLine("draw_me_TDC2D()");
  gROOT->ProcessLine("draw_me_PadvsX()");
  gROOT->ProcessLine("draw_me_like_one_of_your_french_girls_oo_la_la()");
  gROOT->ProcessLine("draw_me_K600vsCalSi()");
  gROOT->ProcessLine("draw_me_frontback()");
  gROOT->ProcessLine("print_efficiencies()");
}

void draw_me_TDC2D()
{
  TCanvas *tdc2d = new TCanvas("tdc2d","TDC2DModules",1170,960);
  tdc2d->Divide(4,2);

  tdc2d->cd(1);
  draw_me("TDC2DModule_000","col");
  
   tdc2d->cd(2);
  draw_me("TDC2DModule_001","col");
  
  tdc2d->cd(3);
  draw_me("TDC2DModule_002","col");

  tdc2d->cd(4);
  draw_me("TDC2DModule_003","col");

  tdc2d->cd(5);
  draw_me("TDC2DModule_004","col");

  tdc2d->cd(6);
  draw_me("TDC2DModule_005","col");

  tdc2d->cd(7);
  draw_me("TDC2DModule_006","col");

  tdc2d->cd(8);
  draw_me("TDC2DModule_007","col");

  //c1->cd();
}


void draw_me_PadvsX()
{
  TCanvas *padvsx = new TCanvas("padvsx","Paddle vs Position",1170,960);
  padvsx->Divide(2,2);

  padvsx->cd(1);
  draw_me("Pad1HivsX","col");
  
  padvsx->cd(2);
  draw_me("Pad1LowvsX","col");
  
  padvsx->cd(3);
  draw_me("Pad2HivsX","col");

  padvsx->cd(4);
  draw_me("Pad2LowvsX","col");

  //c1->cd();
}





void ZeroHistogram(string histname)
{
  TH2I* histo = (TH2I*)a->GetSocketClientNetFolder()->FindObjectAny(histname.c_str());
  printf("Number of bins: %d\n",histo->GetXaxis()->GetNbins());
  histo->SetTitle("Buggeration");
  histo->GetXaxis()->SetTitle("Titwaddery");
  histo->GetYaxis()->SetTitle("Bollocksy");
  for(int i=0;i<histo->GetXaxis()->GetNbins();i++)
    {
      for(int j=0;j<histo->GetYaxis()->GetNbins();j++)
	{
	  histo->SetBinContent(i,j,0);
	}
    }
  histo->Draw("col");
}
