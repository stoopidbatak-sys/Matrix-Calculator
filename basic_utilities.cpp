#include "basic_utilities.h"

long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

void Simplifier(long long &num, long long &den) {
    long long divisor = gcd(num, den);
    while (divisor != 1) {
        num /= divisor;
        den /= divisor;
        divisor = gcd(num, den);
    }

    if(num < 0 && den < 0 || num > 0 && den < 0) {
        num *= -1;
        den *= -1;
    }
}