#include "basic_utilities.h"
#include "fraction.h"

#include <iostream>
#include <cmath>
    
fraction :: fraction(long long num = 0, long long den = 1) {
    this->num = num;
    this->den = den;
    
    this->Simplifier();
}

void fraction :: Set(long long num, long long den) {
    this->num = num;
        this->den = den;
        
        this->Simplifier();
    }
    
void fraction :: SetNum(long long num) {
    this->num = num;
    this->Simplifier();
}

void fraction :: SetDen(long long den) {
    this->den = den;
    this->Simplifier();
}

long long fraction :: getNum() const {
    return num;
}

long long fraction :: getDen() const {
    return den;
}

void fraction :: Simplifier() {
    long long divisor = gcd(num, den);
    num /= divisor;
    den /= divisor;
    
    if(den < 0) {
        num *= -1;
        den *= -1;
    }
}

fraction fraction :: operator + (const fraction &obj) const {
    fraction temp;
    long long a = den;
    long long b = obj.den;
    long long divisor = gcd(a, b);
    ::Simplifier(a, b);
    
    temp.num = num*b + a*obj.num;
    temp.den = a*b*divisor;
    
    temp.Simplifier();
    return temp;
}

fraction& fraction :: operator += (const fraction &obj) {
    long long a = obj.den;
    long long divisor = gcd(den, a);
    ::Simplifier(den, a);
    
    num = num*a + den*obj.num;
    den = den*a*divisor;
    
    this->Simplifier();
    return *this;
}

fraction fraction :: operator + (const int &number) const {
    fraction temp(number);
    return *this + temp;
}

fraction& fraction :: operator += (const int &number) {
    fraction temp(number);
    *this += temp;
    
    return *this;
}

fraction fraction :: operator + (const float &number) const {
    fraction temp = toFraction(number);
    return *this + temp;
}

fraction& fraction :: operator += (const float &number) {
    fraction temp = toFraction(number);
    *this += temp;
    
    return *this;
}

fraction fraction :: operator + (const double &number) const {
    fraction temp = toFraction(number);
    return *this + temp;
}

fraction& fraction :: operator += (const double &number) {
    fraction temp = toFraction(number);
    *this += temp;

    return *this;
}

fraction fraction :: operator - (const fraction &obj) const {
    fraction temp;
    long long a = den;
    long long b = obj.den;
    long long divisor = gcd(a, b);
    ::Simplifier(a, b);
    
    temp.num = num*b - a*obj.num;
    temp.den = a*b*divisor;
    
    temp.Simplifier();
    return temp;
}

fraction& fraction :: operator -= (const fraction &obj) {
    long long a = obj.den;
    long long divisor = gcd(den, a);
    ::Simplifier(den, a);
    
    num = num*a - den*obj.num;
    den = den*a*divisor;
    
    this->Simplifier();
    return *this;
}

fraction fraction :: operator - (const int &number) const {
    fraction temp(number);
    return *this - temp;
}

fraction& fraction :: operator -= (const int &number) {
    fraction temp(number);
    *this -= temp;
    
    return *this;
}

fraction fraction :: operator - (const float &number) const {
    fraction temp = toFraction(number);
    return *this - temp;
}

fraction& fraction :: operator -= (const float &number) {
    fraction temp = toFraction(number);
    *this -= temp;
    
    return *this;
}

fraction fraction :: operator - (const double &number) const {
    fraction temp = toFraction(number);
    return *this - temp;
}

fraction& fraction :: operator -= (const double &number) {
    fraction temp = toFraction(number);
    *this -= temp;
    
    return *this;
}

fraction fraction :: operator * (const fraction &obj) const {
    fraction temp;
    long long a = num;
    long long b = den;
    long long c = obj.num;
    long long d = obj.den;
    ::Simplifier(a, d);
    ::Simplifier(c, b);
    
    temp.num = a*c;
    temp.den = b*d;
    
    temp.Simplifier();
    return temp;
}

fraction& fraction :: operator *= (const fraction &obj) {
    long long a = obj.num;
    long long b = obj.den;
    ::Simplifier(num, b);
    ::Simplifier(a, den);
    num *= a;
    den *= b;
    
    this->Simplifier();
    return *this;
}

fraction fraction :: operator * (const int &scalar) const {
    fraction temp(scalar);
    return (*this)*temp;
}

fraction& fraction :: operator *= (const int &scalar) {
    fraction temp(scalar);
    *this *= temp;
    return *this;
}

fraction fraction :: operator * (const float &scalar) const {
    fraction temp = toFraction(scalar);
    return (*this)*temp;
}

fraction& fraction :: operator *= (const float &scalar) {
    fraction temp = toFraction(scalar);
    *this *= temp;
    return *this;
}

fraction fraction :: operator * (const double &scalar) const {
    fraction temp = toFraction(scalar);
    return (*this)*temp;
}

fraction& fraction :: operator *= (const double &scalar) {
    fraction temp = toFraction(scalar);
    *this *= temp;
    return *this;
}

fraction fraction :: operator / (const fraction &obj) const {
    if (obj.num == 0) {
        throw std::runtime_error("Division by zero");
    }
    
    fraction temp;
    long long a = num;
    long long b = den;
    long long c = obj.num;
    long long d = obj.den;
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
    
    long long a = obj.num;
    long long b = obj.den;
    ::Simplifier(num, a);
    ::Simplifier(den, b);
    
    num *= b;
    den *= a;
    
    this->Simplifier();
    return *this;
}

fraction fraction :: operator / (const int &scalar) const {
    if (scalar == 0) {
        throw std::runtime_error("Division by zero");
    }
    
    fraction temp(scalar);
    return (*this)/temp;
}

fraction& fraction :: operator /= (const int &scalar) {
    if (scalar == 0) {
        throw std::runtime_error("Division by zero");
    }

    fraction temp(scalar);
    *this /= temp;
    return *this;
}

fraction fraction :: operator / (const float &scalar) const {
    if (scalar == 0) {
        throw std::runtime_error("Division by zero");
    }

    fraction temp = toFraction(scalar);
    return (*this)/temp;
}

fraction& fraction :: operator /= (const float &scalar) {
    if (scalar == 0) {
        throw std::runtime_error("Division by zero");
    }

    fraction temp = toFraction(scalar);
    *this /= temp;
    return *this;
}

fraction fraction :: operator / (const double &scalar) const {
    if (scalar == 0) {
        throw std::runtime_error("Division by zero");
    }
    
    fraction temp = toFraction(scalar);
    return (*this)/temp;
}

fraction& fraction :: operator /= (const double &scalar) {
    if (scalar == 0) {
        throw std::runtime_error("Division by zero");
    }

    fraction temp = toFraction(scalar);
    *this /= temp;
    return *this;
}

fraction& fraction :: operator = (const int &number) {
    num = number;
    den = 1;
    return *this;
} 

fraction& fraction :: operator = (const float &number) {
    fraction temp = toFraction(number);
    *this = temp;
    return *this;
}

fraction& fraction :: operator = (const double &number) {
    fraction temp = toFraction(number);
    *this = temp;
    return *this;
}

bool fraction :: operator == (const fraction &obj) const {
    if (num == obj.num) 
    if(den == obj.den)
    return true;
    return false;
}

bool fraction :: operator != (const fraction &obj) const {
    return !(*this == obj);
}

bool fraction :: operator == (const int &number) const {
    fraction temp(number);
    return (*this == temp);
}

bool fraction :: operator != (const int &number) const {
    return !(*this == number);
}

bool fraction :: operator == (const float &number) const {
    fraction temp = toFraction(number);
    return (*this == temp);
}

bool fraction :: operator != (const float &number) const {
    return !(*this == number);
}

bool fraction :: operator == (const double &number) const {
    fraction temp = toFraction(number);
    return (*this == temp);
}

bool fraction :: operator != (const double &number) const {
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

bool fraction :: operator > (const int &number) const {
    return (num > (number*den));
}

bool fraction :: operator >= (const int &number) const {
    return (*this > number || *this == number);
}

bool fraction :: operator < (const int &number) const {
    return (num < (number*den));
}

bool fraction :: operator <= (const int number) const {
    return (*this < number || *this == number);
}

bool fraction :: operator > (const float &number) const {
    fraction temp = toFraction(number);
    return (*this > temp);
}

bool fraction :: operator >= (const float &number) const {
    return (*this > number || *this == number);
}

bool fraction :: operator < (const float &number) const {
    fraction temp = toFraction(number);
    return (*this < temp);
}

bool fraction :: operator <= (const float &number) const {
    return (*this < number || *this == number);
}

bool fraction :: operator > (const double &number) const {
    fraction temp = toFraction(number);
    return (*this > temp);
}

bool fraction :: operator >= (const double &number) const {
    return (*this > number || *this == number);
}

bool fraction :: operator < (const double &number) const {
    fraction temp = toFraction(number);
    return (*this < temp);
}

bool fraction :: operator <= (const double &number) const {
    return (*this < number || *this == number);
}

fraction fraction :: operator - () const {
    return fraction(-num, den);
}

fraction fraction :: toFraction(const double &value) const {
    const long long precision = 1000000000LL; // 10^9
    
    long long numerator = round(value * precision);
    long long denominator = precision;
    
    long long g = gcd(abs(numerator), denominator);
    
    numerator /= g;
    denominator /= g;
    
    fraction temp(numerator, denominator);
    return temp;
}

fraction fraction :: toFraction(const float &value) const {
    const long long precision = 10000000LL; // 10^7 (matches float precision)
    
    long long numerator = round(value * precision);
    long long denominator = precision;
    
    long long g = gcd(llabs(numerator), denominator);
    
    numerator /= g;
    denominator /= g;
        
    return fraction(numerator, denominator);
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