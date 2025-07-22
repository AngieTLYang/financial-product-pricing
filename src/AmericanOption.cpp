#include "AmericanOption.hpp"
#include <cmath>
#include <algorithm>
#include <vector>

AmericanOption::AmericanOption(double S, double K, double T, double r, double sigma)
    : Option(S, K, T, r, sigma) {}

double AmericanOption::price() const {
    const int N = 1000; // Number of time steps (increase for more accuracy)
    double dt = T / N;
    double u = std::exp(sigma * std::sqrt(dt));      // up factor
    double d = 1.0 / u;                              // down factor
    double p = (std::exp(r * dt) - d) / (u - d);     // risk-neutral probability
    double discount = std::exp(-r * dt);

    // Step 1: Setup terminal payoffs
    std::vector<double> optionPrices(N + 1);
    for (int i = 0; i <= N; ++i) {
        double ST = S * std::pow(u, N - i) * std::pow(d, i);
        optionPrices[i] = std::max(ST - K, 0.0); // American call payoff
    }

    // Step 2: Backward induction
    for (int step = N - 1; step >= 0; --step) {
        for (int i = 0; i <= step; ++i) {
            double ST = S * std::pow(u, step - i) * std::pow(d, i);
            double hold = discount * (p * optionPrices[i] + (1 - p) * optionPrices[i + 1]);
            double exercise = std::max(ST - K, 0.0); // early exercise value
            optionPrices[i] = std::max(hold, exercise);
        }
    }

    return optionPrices[0];
}
