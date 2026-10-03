#include "BigInt.h"
#include "basic_utilities.h"
#include <iostream>
#include <vector>
using namespace std;

BigInt :: BigInt () {
    num.push_back(0);
    negative = false;
}

BigInt :: BigInt (long long number) {
    if (number == 0) {
        num.push_back(0);
        negative = false;

        return;
    }

    if (number < 0) {
        negative = true;
        number *= -1;
    }
    else {
        negative = false;
    }

    for (long long i=number; i>0; i /= 10) {
        num.push_back(i%10);
    }
}

BigInt :: BigInt (vector<int> number, bool negativity) {
    num = number;
    negative = negativity;
}

BigInt BigInt :: operator - () const {
    if (*this == 0)
        return *this;

    BigInt temp = *this;
    temp.negative = !(temp.negative);

    return temp;
}

void BigInt :: removeZeros () {

    while (num.back() == 0) {
        if (num.size() <= 1)
            break;

        num.pop_back();
    }
}

BigInt BigInt :: absolute () const {
    if (*this < 0)
        return -*this;

    return *this;
}

BigInt BigInt :: operator + (const BigInt &number) const {
    if (negative != number.negative) {
        if (negative == true)
            return number - (-*this);
        else
            return *this - (-number);
    }

    vector<int> temp;
    int index = 0;
    int carry = 0;
    while (index != num.size() && index != number.num.size()) {
        int sum = num[index] + number.num[index] + carry;
        temp.push_back(sum%10);
        carry = sum/10;
        index++;
    }

    BigInt remaining = (index == number.num.size()) ? *this : number;
    for (index; index<remaining.num.size(); index++) {
        int sum = remaining.num[index] + carry;
        temp.push_back(sum%10);
        carry = sum/10;
    }

    if (carry != 0)
        temp.push_back(carry);

    BigInt sum (temp, negative);
    sum.removeZeros();

    return sum;

}

BigInt BigInt :: operator + (const long long &number) const {
    return *this + BigInt(number);
}

BigInt& BigInt :: operator += (const BigInt &number) {
    *this = *this + number;
    return *this;
}

BigInt& BigInt :: operator += (const long long &number) {
    *this = *this + number;
    return *this;
}

BigInt BigInt :: operator - (const BigInt &number) const {
    if (negative != number.negative) {
        if (negative == true)
            return -number + *this;
        else
            return *this + (-number);
    }

    BigInt greater, smaller;
    if ((*this).absolute() > number.absolute()) {
        greater = *this;
        smaller = number;   
    }
    else {
        greater = number;
        smaller = *this;  
    }

    vector<int> temp;
    int index = 0;
    int borrow = 0;
    while (index != greater.num.size() && index != smaller.num.size()) {
        int ans = greater.num[index] - smaller.num[index] - borrow;
        if (ans < 0) {
            ans += 10;
            borrow = 1;
        }
        else {
            borrow = 0;
        }

        temp.push_back(ans);
        index++;
    }

    for (index; index<greater.num.size(); index++) {
        int ans = greater.num[index] - borrow;
        if (ans < 0) {
            ans += 10;
            borrow = 1;
        }
        else {
            borrow = 0;
        }

        temp.push_back(ans);
    }

    BigInt sub (temp, (number > *this));
    sub.removeZeros();

    return sub;
    
}

BigInt BigInt :: operator - (const long long &number) const {
    return *this - BigInt(number);
}

BigInt& BigInt :: operator -= (const BigInt &number) {
    *this = *this - number;
    return *this;
}

BigInt BigInt :: operator -= (const long long &number) {
    *this = *this - number;
    return *this;
}

BigInt BigInt :: operator * (const BigInt &number) const {
    if (*this == 0 || number == 0) {
        return BigInt(0);
    }

    BigInt product;

    for (int i=0; i<number.num.size(); i++) {
        BigInt temp = *this;
        vector<int> singleProduct;
        int carry = 0;

        for (int j=0; j<temp.num.size(); j++) {
            int res = temp.num[j] * number.num[i] + carry;
            singleProduct.push_back(res%10);
            carry = res/10;
        }

        if (carry != 0)
            singleProduct.push_back(carry);

        for (int k=0; k<i; k++)
            singleProduct.insert(singleProduct.begin(), 0);

        product += BigInt(singleProduct, 0);
    }

    product.negative = (negative != number.negative);
    product.removeZeros();

    return product;
}

BigInt BigInt :: operator * (const long long &number) const {
    return *this * BigInt(number);
}

BigInt& BigInt :: operator *= (const BigInt &number) {
    *this = *this * number; 
    return *this;
}

BigInt BigInt :: operator *= (const long long &number) {
    *this = *this * number; 
    return *this;
}

BigInt BigInt :: operator / (const BigInt &number) const {
    if (number == 0)
        throw std::runtime_error("Division by zero");

    if (number.absolute() > (*this).absolute()) {
        return BigInt(0);
    }

    vector<int> quotient;
    BigInt currentPart;

    for (int i=num.size()-1; i>=0; i--) {
        if (currentPart == BigInt(0))
            currentPart.num[0] = num[i];
        else
            currentPart.num.insert (currentPart.num.begin(), num[i]);

        for (int j=1; j<=10; j++) {
            if ((number*BigInt(j)).absolute() > currentPart.absolute()) {
                quotient.insert (quotient.begin(), j-1);
                currentPart -= (number*BigInt(j-1)).absolute();
                break;
            }
        }
    }

    BigInt res (quotient, (negative != number.negative));
    res.removeZeros();
    return res;
}

BigInt BigInt :: operator / (const long long &number) const {
    return *this / BigInt(number);
}

BigInt& BigInt :: operator /= (const BigInt &number) {
    *this = *this / number;
    return *this;
}

BigInt BigInt :: operator /= (const long long &number) {
    *this = *this / number; 
    return *this;
}

BigInt BigInt :: operator % (const BigInt &number) const {
    return *this - (number*(*this/number));
}

BigInt BigInt :: operator % (const long long &number) const {
    return *this % BigInt(number);
}

BigInt& BigInt :: operator %= (const BigInt &number) {
    *this = *this%number;
    return *this;
}

BigInt BigInt :: operator %= (const long long &number) {
    *this = *this % number; 
    return *this;
}

bool BigInt :: operator > (const BigInt &number) const {
    if (*this == number)
        return false;

    if (negative != number.negative) {
        return (negative == false);
    }

    if (negative == false) {
        if (number.num.size() != num.size()) {
            return (num.size() > number.num.size());
        }

        int index = num.size()-1;
        while (num[index] == number.num[index]) 
            index--;
            
        return (num[index] > number.num[index]);
    }

    if (number.num.size() != num.size()) {
        return (num.size() < number.num.size());
    }

    int index = num.size()-1;
    while (num[index] == number.num[index]) 
        index--;
        
    return (num[index] < number.num[index]);
}

bool BigInt :: operator > (const long long &number) const {
    return *this > BigInt(number);
}

bool BigInt :: operator >= (const BigInt &number) const {
    return (*this == number || *this > number);
}

bool BigInt :: operator >= (const long long &number) const {
    return (*this == BigInt(number) || *this > BigInt(number));
}

bool BigInt :: operator < (const BigInt &number) const {
    if (*this == number)
        return false;

    if (negative != number.negative) {
        return (negative == true);
    }

    if (negative == false) {
        if (number.num.size() != num.size()) {
            return (num.size() < number.num.size());
        }

        int index = num.size()-1;
        while (num[index] == number.num[index]) 
            index--;
            
        return (num[index] < number.num[index]);
    }

    if (number.num.size() != num.size()) {
        return (num.size() > number.num.size());
    }

    int index = num.size()-1;
    while (num[index] == number.num[index]) 
        index--;
        
    return (num[index] > number.num[index]); 
}

bool BigInt :: operator < (const long long &number) const {
    return *this < BigInt(number);
}

bool BigInt :: operator <= (const BigInt &number) const {
    return (*this == number || *this < number);
}

bool BigInt :: operator <= (const long long &number) const {
    return (*this == BigInt(number) || *this < BigInt(number));
}

bool BigInt :: operator == (const BigInt &number) const {
    bool thisIsZero = (num.size() == 1 && num[0] == 0);
    bool otherIsZero = (number.num.size() == 1 && number.num[0] == 0);
    if (thisIsZero && otherIsZero)
        return true;
        
    if (negative !=  number.negative) 
        return false;

    return (num == number.num);
}

bool BigInt :: operator == (const long long &number) const {
    return (*this == BigInt(number));
}

bool BigInt :: operator != (const BigInt &number) const {
    return !(*this == number);
}

bool BigInt :: operator != (const long long &number) const {
    return !(*this == BigInt(number));
}

int BigInt :: getLength () const {
    return num.size() + (int)negative;
}

ostream& operator << (ostream &out, const BigInt &number) {
    if (number.negative)
        out<<"-";

    for (int i=number.num.size()-1; i>=0; i--) {
        out<<number.num[i];
    }

    return out;
}

istream& operator >> (istream &in, BigInt &number) {
    long long n;
    SafeInput(in, n);

    number.num.clear();

    if (n == 0) {
        number.num.push_back(0);
        number.negative = false;

        return in;
    }

    if (n < 0) {
        number.negative = true;
        n *= -1;
    }
    else {
        number.negative = false;
    }

    for (long long i=n; i>0; i /= 10) {
        number.num.push_back(i%10);
    }

    number.removeZeros();

    return in;
}