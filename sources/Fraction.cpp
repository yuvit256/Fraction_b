#include <iostream>
#include <stdexcept>
#include "Fraction.hpp"

using namespace std;
namespace ariel
{
    Fraction::Fraction(float num)
    {
        this->_num1 = 1000 * num;
        this->_num2 = 1000;
        int cd = __gcd(abs(this->_num1), abs(this->_num2));
        this->_num1 /= cd;
        this->_num2 /= cd;
    }

    Fraction::Fraction(int num1, int num2)
    {
        if (num2 == 0)
        {
            throw std::invalid_argument("std::runtime_error");
        }
        else
        {
            int comdiv = __gcd(abs(num1), abs(num2));
            if (num2 < 0)
            {
                this->_num1 = (-1 * num1) / comdiv;
                this->_num2 = (-1 * num2) / comdiv;
            }
            else
            {
                this->_num1 = num1 / comdiv;
                this->_num2 = num2 / comdiv;
            }
        }
    }

    Fraction::Fraction()
    {
        this->_num1 = 0;
        this->_num2 = 1;
    }

    Fraction::~Fraction() = default;

    Fraction::Fraction(const Fraction &other)
    {
        this->_num1 = other._num1;
        this->_num2 = other._num2;
    }

    Fraction::Fraction(Fraction &&other) noexcept : _num1(other._num1), _num2(other._num2) {}

    Fraction Fraction::operator+(const Fraction &other) const
    {
        _overflow_multiplication_check(this->_num1, other._num2);
        _overflow_multiplication_check(this->_num2, other._num1);
        _overflow_addition_check((this->_num1 * other._num2), (this->_num2 * other._num1));
        _overflow_multiplication_check(this->_num2, other._num1);
        int up = (this->_num1 * other._num2) + (this->_num2 * other._num1);
        int down = this->_num2 * other._num2;
        int comdiv = __gcd(abs(up), abs(down));
        up = up / comdiv;
        down = down / comdiv;
        return Fraction(up, down);
    }

    Fraction Fraction::operator+(float val) const
    {
        Fraction fVal = Fraction(val);
        return fVal + *this;
    }

    Fraction operator+(float val, const Fraction &other)
    {
        Fraction fVal = Fraction(val);
        return fVal + other;
    }

    Fraction Fraction::operator*(const Fraction &other) const
    {
        _overflow_multiplication_check(this->_num1, other._num1);
        _overflow_multiplication_check(this->_num2, other._num2);
        int up = this->_num1 * other._num1;
        int down = this->_num2 * other._num2;
        int comdiv = __gcd(abs(up), abs(down));
        up = up / comdiv;
        down = down / comdiv;
        return Fraction(up, down);
    }

    Fraction Fraction::operator*(float val) const
    {
        Fraction fVal = Fraction(val);
        return fVal * *this;
    }

    Fraction operator*(float val, const Fraction &other)
    {
        Fraction fVal = Fraction(val);
        return fVal * other;
    }

    Fraction Fraction::operator-(const Fraction &other) const
    {
        _overflow_multiplication_check(this->_num1, other._num2);
        _overflow_multiplication_check(this->_num2, other._num1);
        _overflow_subtraction_check((this->_num1 * other._num2), (other._num1 * this->_num2));
        _overflow_multiplication_check(this->_num2, other._num2);
        int up = (this->_num1 * other._num2) - (other._num1 * this->_num2);
        int down = (this->_num2 * other._num2);
        int comdiv = __gcd(abs(up), abs(down));
        up = up / comdiv;
        down = down / comdiv;
        return Fraction(up, down);
    }

    Fraction Fraction::operator-(float val) const
    {
        Fraction fVal = Fraction(val);
        return *this - fVal;
    }

    Fraction operator-(float val, const Fraction &other)
    {
        Fraction fVal = Fraction(val);
        return fVal - other;
    }

    Fraction Fraction::operator/(const Fraction &other) const
    {
        _overflow_multiplication_check(this->_num1, other._num1);
        _overflow_multiplication_check(this->_num2, other._num2);
        if (other._num1 == 0)
        {
            throw std::runtime_error("std::runtime_error");
        }
        else
        {
            int up = this->_num1 * other._num2;
            int down = this->_num2 * other._num1;
            int comdiv = __gcd(abs(up), abs(down));
            up = up / comdiv;
            down = down / comdiv;
            return Fraction(up, down);
        }
    }

    Fraction Fraction::operator/(float val) const
    {
        Fraction fVal = Fraction(val);
        return *this / fVal;
    }

    Fraction operator/(float val, const Fraction &other)
    {
        Fraction fVal = Fraction(val);
        return fVal / other;
    }

    bool Fraction::operator==(const Fraction &other) const
    {
        return this->_num1 * other._num2 == this->_num2 * other._num1;
    }

    bool operator==(float val, const Fraction &other)
    {
        Fraction fVal = Fraction(val);
        return fVal == other;
    }

    bool Fraction::operator==(float val) const
    {
        Fraction fVal = Fraction(val);
        return fVal == *this;
    }

    bool Fraction::operator>(const Fraction &other) const
    {
        return this->_num1 * other._num2 > this->_num2 * other._num1;
    }

    bool Fraction::operator<(const Fraction &other) const
    {
        return this->_num1 * other._num2 < this->_num2 * other._num1;
    }

    bool Fraction::operator>(float val) const
    {
        Fraction fVal = Fraction(val);
        return *this > fVal;
    }

    bool operator>(float val, const Fraction &other)
    {
        Fraction fVal = Fraction(val);
        return fVal > other;
    }

    bool Fraction::operator>=(const Fraction &other) const
    {
        return this->_num1 * other._num2 >= this->_num2 * other._num1;
    }

    bool Fraction::operator<=(const Fraction &other) const
    {
        return this->_num1 * other._num2 <= this->_num2 * other._num1;
    }

    bool Fraction::operator>=(float val) const
    {
        Fraction fVal = Fraction(val);
        return *this >= fVal;
    }

    bool operator<(float val, const Fraction &other)
    {
        Fraction fVal = Fraction(val);
        return fVal < other;
    }

    bool Fraction::operator<(float val) const
    {
        Fraction fVal = Fraction(val);
        return fVal > *this;
    }

    bool Fraction::operator<=(float val) const
    {
        Fraction fVal = Fraction(val);
        return *this <= fVal;
    }

    bool operator<=(float val, const Fraction &other)
    {
        Fraction fVal = Fraction(val);
        return fVal <= other;
    }

    bool operator>=(float val, const Fraction &other)
    {
        Fraction fVal = Fraction(val);
        return fVal >= other;
    }

    Fraction &Fraction::operator++()
    {
        this->_num1 += this->_num2;
        int comdiv = __gcd(abs(this->_num1), abs(this->_num2));
        this->_num1 = this->_num1 / comdiv;
        this->_num2 = this->_num2 / comdiv;
        return *this;
    }

    Fraction Fraction::operator++(int)
    {
        Fraction t = *this;
        ++(*this);
        return t;
    }

    Fraction &Fraction::operator--()
    {
        this->_num1 -= this->_num2;
        int comdiv = __gcd(abs(this->_num1), (this->_num2));
        this->_num1 = this->_num1 / comdiv;
        this->_num2 = this->_num2 / comdiv;
        return *this;
    }

    Fraction Fraction::operator--(int)
    {
        Fraction t = *this;
        --(*this);
        return t;
    }

    Fraction &operator+=(Fraction &frac, const Fraction &other)
    {
        frac = frac + other;
        return frac;
    }

    Fraction &operator+=(Fraction &frac, float other)
    {
        frac = frac + other;
        return frac;
    }

    Fraction &operator-=(Fraction &frac, const Fraction &other)
    {
        frac = frac - other;
        return frac;
    }

    Fraction &operator-=(Fraction &frac, float other)
    {
        frac = frac - other;
        return frac;
    }

    Fraction &operator*=(Fraction &frac, const Fraction &other)
    {
        frac = frac * other;
        return frac;
    }

    Fraction &operator*=(Fraction &frac, float other)
    {
        frac = frac * other;
        return frac;
    }

    Fraction &operator/=(Fraction &frac, const Fraction &other)
    {
        frac = frac / other;
        return frac;
    }

    Fraction &operator/=(Fraction &frac, float other)
    {
        frac = frac / other;
        return frac;
    }

    ostream &operator<<(ostream &os, const Fraction &other)
    {
        os << other._num1 << "/" << other._num2;
        return os;
    }

    istream &operator>>(istream &is, Fraction &other)
    {
        int numitor = 0, denitor = 0;
        is >> numitor >> denitor;
        if (is.fail())
        {
            throw std::runtime_error("Invalid input");
        }
        else if (denitor == 0)
        {
            throw std::runtime_error("std::runtime_error");
        }
        else if (denitor < 0)
        {
            numitor *= -1;
            denitor *= -1;
        }
        other._num1 = numitor;
        other._num2 = denitor;
        int comdiv = __gcd(abs(other._num1), abs(other._num2));
        other._num1 = other._num1 / comdiv;
        other._num2 = other._num2 / comdiv;
        return is;
    }

    Fraction &Fraction::operator=(const Fraction &other)
    {
        if (this == &other)
        {
            return *this;
        }
        this->_num1 = other._num1;
        this->_num2 = other._num2;
        return *this;
    }

    Fraction &Fraction::operator=(Fraction &&other) noexcept
    {
        if (this == &other)
        {
            return *this;
        }
        this->_num1 = other._num1;
        this->_num2 = other._num2;
        return *this;
    }
}
