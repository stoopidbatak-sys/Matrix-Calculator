#include "basic_utilities.h"

#include "BigInt.h"
#include <iostream>
#include <limits>
using namespace std;

BigInt gcd(BigInt a, BigInt b) {
    return b == 0 ? a : gcd(b, a % b);
}

void Simplifier(BigInt &num, BigInt &den) {
    BigInt divisor = gcd(num, den);
    
    if (divisor != 1) {
        num /= divisor;
        den /= divisor;
    }

    if(den < 0) {
        num *= -1;
        den *= -1;
    }
}

void SafeInput(int &x) {

    while (true) {
        cin >> x;

        if (cin.fail()) {
            cout << "Invalid input! Enter an integer: ";

            cin.clear();
            cin.ignore(1000, '\n');
        }

        else {
            break;
        }
    }
}

void SafeInput(istream &in, long long &x) {

    while (true) {
        in >> x;

        if (in.fail()) {
            cout << "Invalid input! Enter an integer: ";

            in.clear();
            in.ignore(1000, '\n');
        }

        else {
            break;
        }
    }
}