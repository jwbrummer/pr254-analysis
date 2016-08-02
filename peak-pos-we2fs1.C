{
  //Written by JWB 13/07/2016
  //Generate a fit by plotting the points where certain excited states (in MeV) are found in the X1pos spectrum.
  TGraph *g = new TGraph();
  g->SetPoint(0,684.606,4.402);
  g->SetPoint(1,645.950,5.035);
  g->SetPoint(2,604.872,5.711);
  g->SetPoint(3,585.452,6.043);
  g->SetPoint(4,513.769,7.338);
  g->Draw("AL*");
  g->Fit("pol2");
}
