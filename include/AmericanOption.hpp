#ifndef AMERICAN_OPTION_HPP
#define AMERICAN_OPTION_HPP

#include "Option.hpp"
#include "OptionType.hpp"

class AmericanOption : public Option {
private:
    int N;
    OptionType type;

public:
    AmericanOption(double S, double K, double T, double r, double sigma, int N, OptionType type);
    double price() const override;
};

#endif // AMERICAN_OPTION_HPP
