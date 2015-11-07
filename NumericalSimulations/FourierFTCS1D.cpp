#include "FourierFTCS1D.h"
#include <vector>
#include <fstream>

using namespace std;

void FourierFTCS1D(double delX, double s, double k, std::function<double(double)> theta0, double BC1, double BC2, double lenX, double Tmax)
{
	auto Npts = (int) (lenX / delX) + 1;
	auto delT = s*delX*delX / k;
	auto time = 0.0;
	vector<double> theta(Npts);
	theta.front() = BC1;
	theta.back() = BC2;
	auto x = 0.0;
	auto coeff = 1 - 2 * s;

	ofstream file(R"(c:\users\cecilia\desktop\outFOU.dat)");
	file << theta.front() << "\t";
	for (auto i = 1; i < Npts-1; ++i)
	{
		x = x + delX;
		theta[i] = theta0(x);
		file << theta[i] << "\t";
	}
	file << theta.back() << "\t" << endl;

	while(time <= Tmax)
	{
		time = time + delT;
		double prev = theta.front();

		file << theta.front() << "\t";
		for (auto i = 1; i<Npts-1; ++i)
		{
			auto tmp = theta[i];
			theta[i] = theta[i + 1] * s + coeff*theta[i] + prev*s;
			prev = tmp;
			file << theta[i] << "\t";
		}
		file << theta.back() << "\t" << endl;
	}
}
