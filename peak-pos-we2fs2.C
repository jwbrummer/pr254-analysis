{
  //Written by JWB 13/07/2016
  //Generate a fit by plotting the points where certain excited states (in MeV) are found in the X1pos spectrum.
  TGraph *g = new TGraph();
  g->SetPoint(0,717.715,4.402);
  g->SetPoint(1,679.233,5.035);
  g->SetPoint(2,638.552,5.711);
  g->SetPoint(3,547.578,7.338);
  g->Draw("AL*");
  g->Fit("pol2");
}
