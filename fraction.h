#ifndef FRACTION_H
    #define FRACTION_H

#include "BigInt.h"
#include <iostream>

class fraction {
    BigInt num;
    BigInt den;
    
    public : 
        fraction (BigInt num = BigInt(0), BigInt den = BigInt(1));

        fraction (long long num, long long den = 1);
    
        void Set(BigInt num, BigInt den);

        void Set(long long num, long long den);
        
        void SetNum(BigInt num);

        void SetNum(long long num);

        void SetDen(BigInt den);

        void SetDen(long long den);
        
        BigInt getNum() const;

        BigInt getDen() const;
        
        void Simplifier();
        
        fraction operator + (const fraction &obj) const;
        
        fraction& operator += (const fraction &obj);

        fraction operator + (const long long &number) const;

        fraction& operator += (const long long &number);

        fraction operator - (const fraction &obj) const;
        
        fraction& operator -= (const fraction &obj);

        fraction operator - (const long long &number) const;
        
        fraction& operator -= (const long long &number);
        
        fraction operator * (const fraction &obj) const;

        fraction& operator *= (const fraction &obj);

        fraction operator * (const long long &scalar) const;
        
        fraction& operator *= (const long long &scalar);
        
        fraction operator / (const fraction &obj) const;

        fraction& operator /= (const fraction &obj);

        fraction operator / (const long long &scalar) const;
        
        fraction& operator /= (const long long &scalar);

        fraction& operator = (const BigInt &number); 

        fraction& operator = (const long long &number); 

        bool operator == (const fraction &obj) const;
        
        bool operator != (const fraction &obj) const;

        bool operator == (const long long &number) const;
        
        bool operator != (const long long &number) const;

        bool operator > (const fraction &obj) const;
        
        bool operator >= (const fraction &obj) const;
        
        bool operator < (const fraction &obj) const;

        bool operator <= (const fraction &obj) const;

        bool operator > (const long long &number) const;

        bool operator >= (const long long &number) const;

        bool operator < (const long long &number) const;

        bool operator <= (const long long &number) const;
        
        fraction operator - () const;

    friend std::istream& operator >> (std::istream &in, fraction &obj);
    friend std::ostream& operator << (std::ostream &out, const fraction &obj);
};

#endif