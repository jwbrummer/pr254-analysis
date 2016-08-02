{
  //Written by JWB 13/07/2016
  //Generate a fit by plotting the points where certain excited states (in MeV) are found in the X1pos spectrum.
  TGraph *g = new TGraph();
  g->SetPoint(0,767.813,3.308);
  g->SetPoint(1,702.424,4.402);
  g->SetPoint(2,663.883,5.035);
  g->SetPoint(3,623.125,5.711);
  g->SetPoint(4,608.375,5.953);
  g->SetPoint(5,603.375,6.043);
  g->SetPoint(6,532.277,7.338);
  g->Draw("AL*");
  g->Fit("pol2");
}
