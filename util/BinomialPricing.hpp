#ifndef BINOMIALPRICING_HPP
#define BINOMIALPRICING_HPP

struct BinomialPricingResult {
    double call;
    double put;
};

BinomialPricingResult calculate_binomial_pricing(double S, double K, double T, double r, double sigma, int N);

#endif