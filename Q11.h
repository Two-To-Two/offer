#include <iostream>
#include <stdexcept>

bool doubleEqual(double n1, double n2); /// IMPORTANT!!!

double Power(double base, int exponent) {
    double ret = 1.0;
    if (exponent > 0) {
        for (int i = 1; i <= exponent; i++) {
            ret *= base;
        }
        return ret;
    } else if (exponent == 0) {
        return ret;
    } else {
        // exception base == 0.0
        try {
            if (doubleEqual(base, 0.0)) {
                throw std::invalid_argument("exponent should not less than zero!");
            }
        }
        catch (const std::invalid_argument& e) {
            return 0.0;
        }

        int absExp = -exponent;
        for (int i = 1; i <= absExp; i++) {
            ret *= base;
        }
        return 1.0 / ret;
    }
}

bool doubleEqual(double n1, double n2) {
    if ((n1 - n2 > -0.0000001) && (n1 - n2 < 0.0000001))
        return true;
    else return false;
}