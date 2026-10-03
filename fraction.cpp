#include "basic_utilities.h"
#include "fraction.h"
#include "BigInt.h"

#include <iostream>
#include <cmath>
    
fraction :: fraction(BigInt num, BigInt den) {
    this->num = num;
    this->den = den;
    
    this->Simplifier();
}

fraction :: fraction(long long num, long long den) {
    this->num = BigInt(num);
    this->den = BigInt(den);
    
    this->Simplifier();
}

void fraction :: Set(BigInt num, BigInt den) {
    this->num = num;
    this->den = den;
        
    this->Simplifier();
}

void fraction :: Set(long long num, long long den) {
    this->num = BigInt(num);
    this->den = BigInt(den);
    
    this->Simplifier();
}
    
void fraction :: SetNum(BigInt num) {
    this->num = num;
    this->Simplifier();
}

void fraction :: SetNum(long long num) {
    this->num = BigInt(num);
    this->Simplifier();
}

void fraction :: SetDen(BigInt den) {
    this->den = den;
    this->Simplifier();
}

void fraction :: SetDen(long long den) {
    this->den = BigInt(den);
    this->Simplifier();
}

BigInt fraction :: getNum() const {
    return num;
}

BigInt fraction :: getDen() const {
    return den;
}

void fraction :: Simplifier() {
    BigInt divisor = gcd(num, den);
    num /= divisor;
    den /= divisor;
    
    if (den < 0) {
        num *= -1;
        den *= -1;
    }
}

fraction fraction :: operator + (const fraction &obj) const {
    fraction temp;
    BigInt a = den;
    BigInt b = obj.den;
    BigInt divisor = gcd(a, b);
    ::Simplifier(a, b);
    
    temp.num = num*b + a*obj.num;
    temp.den = a*b*divisor;
    
    temp.Simplifier();
    return temp;
}

fraction& fraction :: operator += (const fraction &obj) {
    *this = *this + obj;
    return *this;
}

fraction fraction :: operator + (const long long &number) const {
    fraction temp(number, 1);
    return *this + temp;
}

fraction& fraction :: operator += (const long long &number) {
    fraction temp(number, 1);
    *this += temp;
    
    return *this;
}

fraction fraction :: operator - (const fraction &obj) const {
    fraction temp;
    BigInt a = den;
    BigInt b = obj.den;
    BigInt divisor = gcd(a, b);
    ::Simplifier(a, b);
    
    temp.num = num*b - a*obj.num;
    temp.den = a*b*divisor;
    
    temp.Simplifier();
    return temp;
}

fraction& fraction :: operator -= (const fraction &obj) {
    *this = *this - obj;
    return *this;
}

fraction fraction :: operator - (const long long &number) const {
    fraction temp(number, 1);
    return *this - temp;
}

fraction& fraction :: operator -= (const long long &number) {
    fraction temp(number, 1);
    *this -= temp;
    
    return *this;
}

fraction fraction :: operator * (const fraction &obj) const {
    fraction temp;
    BigInt a = num;
    BigInt b = den;
    BigInt c = obj.num;
    BigInt d = obj.den;
    ::Simplifier(a, d);
    ::Simplifier(c, b);
    
    temp.num = a*c;
    temp.den = b*d;
    
    temp.Simplifier();
    return temp;
}

fraction& fraction :: operator *= (const fraction &obj) {
    *this = *this * obj;

    return *this;
}

fraction fraction :: operator * (const long long &scalar) const {
    fraction temp(scalar, 1);
    return (*this)*temp;
}

fraction& fraction :: operator *= (const long long &scalar) {
    fraction temp(scalar, 1);
    *this *= temp;
    return *this;
}

fraction fraction :: operator / (const fraction &obj) const {
    if (obj.num == 0) {
        throw std::runtime_error("Division by zero");
    }
    
    fraction temp;
    BigInt a = num;
    BigInt b = den;
    BigInt c = obj.num;
    BigInt d = obj.den;
    ::Simplifier(a, c);
    ::Simplifier(b, d);
    
    temp.num = a*d;
    temp.den = b*c;
    
    temp.Simplifier();
    return temp;
}

fraction& fraction :: operator /= (const fraction &obj) {
    if (obj.num == 0) {
        throw std::runtime_error("Division by zero");
    }
    
    *this = *this/obj;

    return *this;
}

fraction fraction :: operator / (const long long &scalar) const {
    if (scalar == 0) {
        throw std::runtime_error("Division by zero");
    }
    
    fraction temp(scalar, 1);
    return (*this)/temp;
}

fraction& fraction :: operator /= (const long long &scalar) {
    if (scalar == 0) {
        throw std::runtime_error("Division by zero");
    }

    fraction temp(scalar, 1);
    *this /= temp;
    return *this;
}

fraction& fraction :: operator = (const BigInt &number) {
    num = number;
    den = BigInt(1);
    return *this;
}

fraction& fraction :: operator = (const long long &number) {
    num = BigInt(number);
    den = BigInt(1);
    return *this;
}

bool fraction :: operator == (const fraction &obj) const {
    if (num == obj.num && den == obj.den)
        return true;
    return false;
}

bool fraction :: operator != (const fraction &obj) const {
    return !(*this == obj);
}

bool fraction :: operator == (const long long &number) const {
    fraction temp(number, 1);
    return (*this == temp);
}

bool fraction :: operator != (const long long &number) const {
    return !(*this == number);
}

bool fraction :: operator > (const fraction &obj) const {
    return ((num*obj.den) > (obj.num*den));
}

bool fraction :: operator >= (const fraction &obj) const {
    return (*this > obj || *this == obj);
}

bool fraction :: operator < (const fraction &obj) const {
    return ((num*obj.den) < (obj.num*den));
}

bool fraction :: operator <= (const fraction &obj) const {
    return (*this < obj || *this == obj);
}

bool fraction :: operator > (const long long &number) const {
    return (num > (den*number));
}

bool fraction :: operator >= (const long long &number) const {
    return (*this > number || *this == number);
}

bool fraction :: operator < (const long long &number) const {
    return (num < (den*number));
}

bool fraction :: operator <= (const long long &number) const {
    return (*this < number || *this == number);
}

fraction fraction :: operator - () const {
    return fraction(-num, den);
}

std::istream& operator >> (std::istream &in, fraction &obj) {
    in>>obj.num;
    
    if(in.peek() == '/') {
        in.get();
        in>>obj.den;
        
        if(obj.den == 0) {
            std::cout<<"Denominator can't be 0!"<<std::endl;
            std::cout<<"Enter the fraction again : ";
            std::cin>>obj;
            
            if(obj.den == 0) {
                std::cout<<"You entered 0 again!"<<std::endl;
                std::cout<<"Dominator set to 1"<<std::endl;
                obj.den = 1;
            }
        }
    }

    obj.Simplifier();
    return in;
}

std::ostream& operator << (std::ostream &out, const fraction &obj) {
    out<<obj.num;
    if (obj.den != 1) 
    out<<"/"<<obj.den;
    return out;
}