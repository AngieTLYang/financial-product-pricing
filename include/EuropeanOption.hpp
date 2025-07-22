#ifndef EUROPEANOPTION_HPP
#define EUROPEANOPTION_HPP

#include "Option.hpp"
#include "OptionType.hpp"

class EuropeanOption : public Option {
private:
    OptionType type;

public:
    EuropeanOption(double S, double K, double T, double r, double sigma, OptionType type);
    double price() const override;
};

#endif // EUROPEANOPTION_HPP
