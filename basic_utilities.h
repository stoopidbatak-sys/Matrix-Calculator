#ifndef BASIC_UTILITIES_H
    #define BASIC_UTILITIES_H

#include <iostream>
#include "BigInt.h"

    BigInt gcd(BigInt a, BigInt b);

    void Simplifier(BigInt &num, BigInt &den);

    void SafeInput(int &x);

    void SafeInput(std::istream &in, long long &x);

#endif