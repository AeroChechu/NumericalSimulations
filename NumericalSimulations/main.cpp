#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include "FourierFTCS1D.h"

using namespace std;

double sinx(double x)
{
	return sin(x);
}


int main()
{
	cout << "Maria Cecilia Tomasetti's repository" << endl;

	double delX = M_PI/10.;
	double s = 0.4;
	double k = 1.0;
	double BC1 = 0.0;
	double BC2 = 0.0;
	double lenX = M_PI;
	double Tmax = 1.0;

	FourierFTCS1D(delX, s, k, sinx, BC1, BC2, lenX, Tmax);
}