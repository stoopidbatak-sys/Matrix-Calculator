#ifndef BIGINT_H
    #define BIGINT_H

    #include <iostream>
    #include <vector>
    using namespace std;

    class BigInt {
        vector<int> num;
        bool negative;

        public :
            BigInt ();

            BigInt (long long number);

            BigInt (vector<int> number, bool negativity);

            BigInt operator - () const;

            void removeZeros ();

            BigInt absolute () const;

            BigInt operator + (const BigInt &number) const;

            BigInt operator + (const long long &number) const;

            BigInt& operator += (const BigInt &number);

            BigInt& operator += (const long long &number);

            BigInt operator - (const BigInt &number) const;

            BigInt operator - (const long long &number) const;

            BigInt& operator -= (const BigInt &number);

            BigInt operator -= (const long long &number);

            BigInt operator * (const BigInt &number) const;

            BigInt operator * (const long long &number) const;

            BigInt& operator *= (const BigInt &number);

            BigInt operator *= (const long long &number);

            BigInt operator / (const BigInt &number) const;

            BigInt operator / (const long long &number) const;

            BigInt& operator /= (const BigInt &number);

            BigInt operator /= (const long long &number);

            BigInt operator % (const BigInt &number) const;

            BigInt operator % (const long long &number) const;

            BigInt& operator %= (const BigInt &number);

            BigInt operator %= (const long long &number);

            bool operator > (const BigInt &number) const;

            bool operator > (const long long &number) const;

            bool operator >= (const BigInt &number) const;

            bool operator >= (const long long &number) const;

            bool operator < (const BigInt &number) const;

            bool operator < (const long long &number) const;

            bool operator <= (const BigInt &number) const;

            bool operator <= (const long long &number) const;

            bool operator == (const BigInt &number) const;

            bool operator == (const long long &number) const;

            bool operator != (const BigInt &number) const;

            bool operator != (const long long &number) const;

            int getLength () const;

            friend ostream& operator << (ostream &out, const BigInt &number);

            friend istream& operator >> (istream &in, BigInt &number);
    };

#endif