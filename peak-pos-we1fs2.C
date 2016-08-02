{
  //Written by JWB 13/07/2016
  //Generate a fit by plotting the points where certain excited states (in MeV) are found in the X1pos spectrum.
  TGraph *g = new TGraph();
  g->SetPoint(0,729.197,3.308);
  g->SetPoint(1,663.407,4.402);
  g->SetPoint(2,625.397,5.035);
  g->SetPoint(3,584.921,5.711);
  g->SetPoint(4,570.539,5.953);
  g->SetPoint(5,565.197,6.043);
  g->SetPoint(6,494.982,7.338);
  g->Draw("AL*");
  g->Fit("pol2");
}
