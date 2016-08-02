{
  //Written by JWB 13/07/2016
  //Generate a fit by plotting the points where certain excited states (in MeV) are found in the X1pos spectrum.
  TGraph *g = new TGraph();
  g->SetPoint(0,709.945,4.402);
  g->SetPoint(1,671.828,5.035);
  g->SetPoint(2,631.320,5.711);
  g->SetPoint(3,616.488,5.953);
  g->SetPoint(4,611.065,6.043);
  g->SetPoint(5,540.825,7.338);
  g->Draw("AL*");
  g->Fit("pol2");
}
