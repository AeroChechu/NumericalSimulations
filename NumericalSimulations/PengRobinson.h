#pragma once
#include <vector>

void PengRobinson(double p0, double rho_min, double rho_max, int Npts, double omega, double t_cr, double p_cr)
{
	double delta_rho = (rho_max - rho_min) / Npts;
	vector<double> rho(Npts);
	double Rgas=8.314

	double Temp{};
	for (int i = 0; i < Npts; i++)
	{
		rho[i] = rho_min + i*delta_rho;
		appo=
	}

}
