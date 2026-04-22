#ifndef FRACTION_H
    #define FRACTION_H

#include <iostream>

class fraction {
    long long num;
    long long den;
    
    public : 
        fraction (long long num = 0, long long den = 1);
    
        void Set(long long num, long long den);
        
        void SetNum(long long num);

        void SetDen(long long den);
        
        long long getNum() const;

        long long getDen() const;
        
        void Simplifier();
        
        fraction operator + (const fraction &obj) const;
        
        fraction& operator += (const fraction &obj);
        
        fraction operator + (const int &number) const;

        fraction& operator += (const int &number);

        fraction operator + (const float &number) const;

        fraction& operator += (const float &number);

        fraction operator + (const double &number) const;

        fraction& operator += (const double &number);

        fraction operator - (const fraction &obj) const;
        
        fraction& operator -= (const fraction &obj);
        
        fraction operator - (const int &number) const;
        
        fraction& operator -= (const int &number);

        fraction operator - (const float &number) const;
        
        fraction& operator -= (const float &number);

        fraction operator - (const double &number) const;

        fraction& operator -= (const double &number);
        
        fraction operator * (const fraction &obj) const;

        fraction& operator *= (const fraction &obj);
        
        fraction operator * (const int &scalar) const;
        
        fraction& operator *= (const int &scalar);

        fraction operator * (const float &scalar) const;
        
        fraction& operator *= (const float &scalar);
        
        fraction operator * (const double &scalar) const;
        
        fraction& operator *= (const double &scalar);
        
        fraction operator / (const fraction &obj) const;

        fraction& operator /= (const fraction &obj);
        
        fraction operator / (const int &scalar) const;
        
        fraction& operator /= (const int &scalar);
        
        fraction operator / (const float &scalar) const;
        
        fraction& operator /= (const float &scalar);
        
        fraction operator / (const double &scalar) const;
        
        fraction& operator /= (const double &scalar);
        
        fraction& operator = (const int &number); 

        fraction& operator = (const float &number);
        
        fraction& operator = (const double &number);

        bool operator == (const fraction &obj) const;
        
        bool operator != (const fraction &obj) const;
        
        bool operator == (const int &number) const;
        
        bool operator != (const int &number) const;

        bool operator == (const float &number) const;

        bool operator != (const float &number) const;
        
        bool operator == (const double &number) const;
        
        bool operator != (const double &number) const;

        bool operator > (const fraction &obj) const;
        
        bool operator >= (const fraction &obj) const;
        
        bool operator < (const fraction &obj) const;

        bool operator <= (const fraction &obj) const;
        
        bool operator > (const int &number) const;

        bool operator >= (const int &number) const;

        bool operator < (const int &number) const;

        bool operator <= (const int number) const;

        bool operator > (const float &number) const;

        bool operator >= (const float &number) const;

        bool operator < (const float &number) const;

        bool operator <= (const float &number) const;
        
        bool operator > (const double &number) const;
        
        bool operator >= (const double &number) const;

        bool operator < (const double &number) const;
        
        bool operator <= (const double &number) const;
        
        fraction operator - () const;
        
        fraction toFraction(const double &value) const;
        
        fraction toFraction(const float &value) const;

    friend std::istream& operator >> (std::istream &in, fraction &obj);
    friend std::ostream& operator << (std::ostream &out, const fraction &obj);
};

#endif