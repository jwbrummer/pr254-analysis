{
  //Written by JWB 13/07/2016
  //Generate a fit by plotting the points where certain excited states (in MeV) are found in the X1pos spectrum.
  TGraph *g = new TGraph();
  g->SetPoint(0,728.985,3.308);
  g->SetPoint(1,663.579,4.402);
  g->SetPoint(2,626.039,5.035);
  g->SetPoint(3,585.326,5.711);
  g->SetPoint(4,570.786,5.953);
  g->SetPoint(5,565.499,6.043);
  g->SetPoint(6,495.067,7.338);
  g->Draw("AL*");
  g->Fit("pol2");
}
