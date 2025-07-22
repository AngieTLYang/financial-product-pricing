// EuropeanOption.cpp
#include "EuropeanOption.hpp"
#include "BlackScholes.hpp"

EuropeanOption::EuropeanOption(double S, double K, double T, double r, double sigma, OptionType type)
    : Option(S, K, T, r, sigma), type(type) {}

double EuropeanOption::price() const {
    BlackScholesResult result = calculate_black_scholes(S, K, T, r, sigma);
    return (type == OptionType::Call) ? result.call : result.put;
}
