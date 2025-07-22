#ifndef BLACKSCHOLES_HPP
#define BLACKSCHOLES_HPP

struct BlackScholesResult {
    double call;
    double put;
};

BlackScholesResult calculate_black_scholes(double S, double K, double T, double r, double sigma);

#endif // BLACKSCHOLES_HPP
