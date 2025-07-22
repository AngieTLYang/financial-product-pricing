// include/Option.hpp
#ifndef OPTION_HPP
#define OPTION_HPP

class Option {
protected:
    double S;    // Underlying price
    double K;    // Strike price
    double T;    // Time to maturity
    double r;    // Risk-free rate
    double sigma; // Volatility

public:
    Option(double S, double K, double T, double r, double sigma);
    virtual double price() const = 0; // pure virtual
    virtual ~Option() = default;
};

#endif
