#include "BinomialPricing.hpp"
#include <cmath>
#include <vector>   
#include <algorithm>

BinomialPricingResult calculate_binomial_pricing(double S, double K, double T, double r, double sigma, int N) {
    double dt = T / N;
    double u = std::exp(sigma * std::sqrt(dt));
    double d = 1.0 / u;
    double p = (std::exp(r *dt) - d) / (u - d);
    double discount = std:: exp(-r *dt);
    
    std::vector<double> callPrices(N + 1);
    std::vector<double> putPrices(N + 1);

    for (int i = 0; i <= N; ++i) {
        double ST = S * std::pow(u, N - i) * std::pow(d, i);
        callPrices[i] = std::max(ST - K, 0.0);
        putPrices[i] = std::max(K - ST, 0.0);
    }


    for (int step = N - 1; step >= 0; --step) {
        for (int i = 0; i <= step; ++i) {
            double ST = S * std::pow(u, step - i) * std::pow(d, i);

            // Call
            double holdCall = discount * (p * callPrices[i] + (1 - p) * callPrices[i + 1]);
            double exerciseCall = std::max(ST - K, 0.0);
            callPrices[i] = std::max(holdCall, exerciseCall);

            // Put
            double holdPut = discount * (p * putPrices[i] + (1 - p) * putPrices[i + 1]);
            double exercisePut = std::max(K - ST, 0.0);
            putPrices[i] = std::max(holdPut, exercisePut);
        }
    }

    return BinomialPricingResult{ callPrices[0], putPrices[0] };
}