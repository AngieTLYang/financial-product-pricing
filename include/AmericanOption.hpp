#ifndef AMERICAN_OPTION_HPP
#define AMERICAN_OPTION_HPP

#include "Option.hpp"

class AmericanOption : public Option {
public:
    AmericanOption(double S, double K, double T, double r, double sigma);
    double price() const override;
};

#endif // AMERICAN_OPTION_HPP
