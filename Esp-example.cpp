//Separation energy example: the commands below were taken from the .root_hist file of Arthur
// to know how to draw separation energy spectra. For an explanation look in JWB's PhD logbook
// on page 13 and onward.

/*
X-axis: front strip on detector. 0 is 170 deg, 16 is 110 deg.

Y-axis: 'Q-value' for the reaction (neglecting the increased proton energy due to the boosting of the 22Mg backwards in the lab frame) given by 22/21*Proton_Energy-Excitation_Energy = Proton_Separation_Energy _of_22Mg

The ground state and first-excited-state decays from 22Mg to 21Na+p are clearly visible.
*/

DATA->Draw("pad1:tof>>h2D(2000,2000,4000,2000,0,4000)","","col")
DATA->Draw("pad1:tof>>h2D(2000,2000,4000,2000,0,4000)","CUTpad1vstofRun1056","col")
DATA->SetAlias("X1posCorr","X1pos-3.40739*thetaSCAT-0.079275*thetaSCAT*thetaSCAT")
DATA->Draw("X1posCorr>>hPos(2400,0,800)","CUTpad1vstofRun1056","col")
DATA->Draw("X1posCorr>>hPos(2400,0,800)","CUTpad1vstofRun1056","")
DATA->Draw("EnergyFront:X1posCorr>>hPos(2400,0,800)","CUTpad1vstofRun1056","")
DATA->Draw("EnergyFront:X1posCorr>>hPos(2400,0,800,2000,0,10000)","CUTpad1vstofRun1056","")
DATA->Draw("EnergyFront:X1posCorr>>hPos(2400,0,800,2000,0,10000)","CUTpad1vstofRun1056","col")
DATA->Draw("EnergyFront:X1posCorr>>hPos(2400,0,800,2000,0,10000)","CUTpad1vstofRun1056","")
DATA->Draw("16.8511-0.0215884*X1posCorr+3.49072e-06*X1posCorr*X1posCorr>>hPos(3200,0,16)","CUTpad1vstofRun1031 && !X1flag && !X2flag && !U1flag")
DATA->SetAlias("newEx","16.8511-0.0215884*X1posCorr+3.49072e-06*X1posCorr*X1posCorr")
DATA->Draw("EnergyFront:newEx>>hPos(2400,0,800,2000,0,10000)","CUTpad1vstofRun1056","")
DATA->Draw("EnergyFront:newEx>>hPos(2400,0,16,2000,0,10000)","CUTpad1vstofRun1056","")
DATA->Draw("22./21.*EnergyFront-newEx:newEx>>hPos(2400,0,16,2000,0,10000)","CUTpad1vstofRun1056","")
DATA->Draw("22./21.*EnergyFront-newEx*1000:newEx>>hPos(2400,0,-20000,2000,0,10000)","CUTpad1vstofRun1056","")
DATA->Draw("22./21.*EnergyFront-newEx:newEx>>hPos(2400,0,16,2000,-20000,0)","CUTpad1vstofRun1056","")
DATA->Draw("22./21.*EnergyFront-newEx:newEx>>hPos(2400,0,16,2000,-200000,0)","CUTpad1vstofRun1056","")
DATA->Draw("22./21.*EnergyFront-newEx*1000:newEx>>hPos(2400,0,16,2000,-20000,0)","CUTpad1vstofRun1056","")
DATA->Draw("22./21.*EnergyFront-newEx*1000:newEx>>hPos(2400,0,16,3000,-20000,10000)","CUTpad1vstofRun1056","")
DATA->Draw("22./21.*EnergyFront-newEx*1000:StripFrontx>>hPos(16,0,16,3000,-20000,10000)","CUTpad1vstofRun1056","")
DATA->Draw("22./21.*EnergyFront-newEx*1000:StripFront>>hPos(16,0,16,3000,-20000,10000)","CUTpad1vstofRun1056","")
DATA->Draw("22./21.*EnergyFront-newEx*1000:StripFront>>hPos(16,0,16,3000,-20000,10000)","CUTpad1vstofRun1056","col")
c1->SaveAs("run1056_Q_value_vs_strip_front.png")
c1->SaveAs("run1056_Q_value_vs_strip_front.C")
.! scp run1056_Q_value_vs_strip_front.png online@k600daq:~/PR254/
