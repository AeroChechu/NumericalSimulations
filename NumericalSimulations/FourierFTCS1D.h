#pragma once
#include <functional>

void FourierFTCS1D(double delX, double s, double k, std::function<double(double)> theta0, double BC1, double BC2, double lenX, double Tmax);