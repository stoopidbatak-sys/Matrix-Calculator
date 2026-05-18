#include "basic_utilities.h"

#include <iostream>
#include <limits>
using namespace std;

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