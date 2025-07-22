#include "BlackScholes.hpp"
#include <cmath>    // std::log, std::sqrt, std::exp, std::erf

static double norm_cdf(double x) {
    return 0.5 * (1.0 + std::erf(x / std::sqrt(2.0)));
}

BlackScholesResult calculate_black_scholes(double S, double K, double T, double r, double sigma) {
    double d1 = (std::log(S / K) + (r + 0.5 * sigma * sigma) * T) / (sigma * std::sqrt(T));
    double d2 = d1 - sigma * std::sqrt(T);

    double call = S * norm_cdf(d1) - K * std::exp(-r * T) * norm_cdf(d2);
    double put = K * std::exp(-r * T) * norm_cdf(-d2) - S * norm_cdf(-d1);

    return {call, put};
}
