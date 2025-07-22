#include <iostream>
#include "OptionType.hpp"
#include "EuropeanOption.hpp"
#include "AmericanOption.hpp"

int main() {
    // Sample market data
    double S = 100.0;    // Spot price
    double K = 100.0;    // Strike price
    double T = 1.0;      // Time to maturity (1 year)
    double r = 0.05;     // Risk-free interest rate (5%)
    double sigma = 0.2;  // Volatility (20%)

    // European option
    EuropeanOption euroCall(S, K, T, r, sigma, OptionType::Call);
    std::cout << "European Call Option Price: " << euroCall.price() << std::endl;
    EuropeanOption euroPut(S, K, T, r, sigma, OptionType::Put);
    std::cout << "European Put Option Price: " << euroPut.price() << std::endl;

    int N = 1000;
    // American option 
    AmericanOption amerCall(S, K, T, r, sigma, N, OptionType::Call);
    std::cout << "American Option Price: " << amerCall.price() << std::endl;
    AmericanOption amerPut(S, K, T, r, sigma, N, OptionType::Put);
    std::cout << "American Option Price: " << amerPut.price() << std::endl;

    return 0;
}
