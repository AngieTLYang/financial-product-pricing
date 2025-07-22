#include "AmericanOption.hpp"
#include "BinomialPricing.hpp"
#include <cmath>
#include <algorithm>
#include <vector>

AmericanOption::AmericanOption(double S, double K, double T, double r, double sigma, int N, OptionType type)
    : Option(S, K, T, r, sigma), N(N), type(type) {}

double AmericanOption::price() const {
    auto result = calculate_binomial_pricing(S, K, T, r, sigma, N);
    return (type == OptionType::Call) ? result.call : result.put;
}
