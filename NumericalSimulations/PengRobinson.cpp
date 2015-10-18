#include "PengRobinson.h"
#include <vector>
#include <cmath>
#include <fstream>
#include <iostream>

using namespace std;

void PengRobinson(double p0, double rho_min, double rho_max, int Npts, double omega, double t_cr, double p_cr, double tol)
{
	double delta_rho = (rho_max - rho_min) / Npts;
	vector<double> rho(Npts);
	double Rgas = 8.314;
	double b_pr = 0.0778*pow(Rgas*t_cr, 2) / p_cr;
	double ac_pr = 0.45724*Rgas*t_cr / p_cr;
	double Temp{};
	double k1 = 0.37464 + 1.54226*omega - 0.26992*omega*omega;
	for (int i = 0; i < Npts; i++)
	{
		rho[i] = rho_min + i*delta_rho;
		double rh = rho[i];
		double appo1 = ac_pr*rh*rh / (1 + 2 * b_pr*rho[i] - pow(b_pr*rh, 2));
		double appo2 = rh*Rgas / (1 - b_pr*rh);
		double appo = Temp / t_cr;
		double alpha = pow(1 + k1*(1 - sqrt(appo)), 2);
		do
		{
			appo = Temp / t_cr;
			Temp = (p0 + alpha*appo1) / appo2;
		} while (fabs(appo*t_cr - Temp) <= tol);

		cout << "Temperature = " << Temp << " Density = " << rh << endl;

	}

}
