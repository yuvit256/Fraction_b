#include <iostream>
#include <stdexcept>
#include "Fraction.hpp"

using namespace std;
namespace ariel
{
    int commonDivider(int a, int b)
    {
        if (a == 0)
        {
            return b;
        }
        else if (b == 0)
        {
            return a;
        }
        if (a < b)
        {
            return commonDivider(a, b % a);
        }
        else
        {
            return commonDivider(b, a % b);
        }
    }

    Fraction floatToFrac(float number)
    {
        int power = 1;
        while (number != (int)number && power < 1000)
        {
            number *= 10;
            power *= 10;
        }
        int comdiv = commonDivider(number, power);
        number = number / comdiv;
        power = power / comdiv;
        return Fraction(number, power);
    }

    Fraction::Fraction(int num1, int num2)
    {
        if (num2 == 0)
        {
            throw std::invalid_argument("Can't divide by zero");
        }
        else
        {
            int comdiv = commonDivider(num1, num2);
            this->_num1 = num1 / comdiv;
            this->_num2 = num2 / comdiv;
        }
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
        int up = (this->_num1 * other._num2) + (this->_num2 * other._num1);
        int down = this->_num2 * other._num2;
        int comdiv = commonDivider(up, down);
        up = up / comdiv;
        down = down / comdiv;
        return Fraction(up, down);
    }

    Fraction Fraction::operator+(float val) const
    {
        Fraction fVal = floatToFrac(val);
        return fVal + *this;
    }

    Fraction operator+(float val, const Fraction &other)
    {
        Fraction fVal = floatToFrac(val);
        return fVal + other;
    }

    Fraction Fraction::operator*(const Fraction &other) const
    {
        int up = this->_num1 * other._num1;
        int down = this->_num2 * other._num2;
        int comdiv = commonDivider(up, down);
        up = up / comdiv;
        down = down / comdiv;
        return Fraction(up, down);
    }

    Fraction Fraction::operator*(float val) const
    {
        Fraction fVal = floatToFrac(val);
        return fVal * *this;
    }

    Fraction operator*(float val, const Fraction &other)
    {
        Fraction fVal = floatToFrac(val);
        return fVal * other;
    }

    Fraction Fraction::operator-(const Fraction &other) const
    {
        int up = (this->_num1 * other._num2) - (other._num1 * this->_num2);
        int down = (this->_num2 * other._num2);
        int comdiv = commonDivider(up, down);
        up = up / comdiv;
        down = down / comdiv;
        return Fraction(up, down);
    }

    Fraction Fraction::operator-(float val) const
    {
        Fraction fVal = floatToFrac(-1.0F * val);
        return fVal + *this;
    }

    Fraction operator-(float val, const Fraction &other)
    {
        return floatToFrac(val) - other;
    }

    Fraction Fraction::operator/(const Fraction &other) const
    {
        if (this->_num1 == 0 || other._num1 == 0)
        {
            throw std::invalid_argument("Can't divide by zero");
        }
        else
        {
            int up = this->_num1 * other._num2;
            int down = this->_num2 * other._num1;
            int comdiv = commonDivider(up, down);
            up = up / comdiv;
            down = down / comdiv;
            return Fraction(up, down);
        }
    }

    Fraction Fraction::operator/(float val) const
    {
        Fraction fVal = floatToFrac(val);
        return fVal / *this;
    }

    Fraction operator/(float val, const Fraction &other)
    {
        Fraction fVal = floatToFrac(val);
        Fraction ret = fVal / other;
        return 1.0 / ret;
    }

    bool Fraction::operator==(const Fraction &other) const
    {
        return this->_num1 * other._num2 == this->_num2 * other._num1;
    }

    bool operator==(float val, const Fraction &other)
    {
        Fraction fVal = floatToFrac(val);
        return fVal == other;
    }

    bool Fraction::operator==(float val) const
    {
        Fraction fVal = floatToFrac(val);
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
        Fraction fVal = floatToFrac(val);
        return fVal > *this;
    }

    bool operator>(float val, const Fraction &other)
    {
        Fraction fVal = floatToFrac(val);
        return fVal < other;
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
        Fraction fVal = floatToFrac(val);
        return fVal >= *this;
    }

    bool operator<(float val, const Fraction &other)
    {
        Fraction fVal = floatToFrac(val);
        return fVal < other;
    }

    bool Fraction::operator<(float val) const
    {
        Fraction fVal = floatToFrac(val);
        return fVal > *this;
    }

    bool Fraction::operator<=(float val) const
    {
        Fraction fVal = floatToFrac(val);
        return fVal <= *this;
    }

    bool operator<=(float val, const Fraction &other)
    {
        Fraction fVal = floatToFrac(val);
        return fVal <= other;
    }

    bool operator>=(float val, const Fraction &other)
    {
        Fraction fVal = floatToFrac(val);
        return fVal >= other;
    }

    Fraction &Fraction::operator++()
    {
        this->_num1 += this->_num2;
        return *this;
    }

    Fraction Fraction::operator++(int)
    {
        this->_num1 += this->_num2;
        return *this;
    }

    Fraction &Fraction::operator--()
    {
        this->_num1 -= this->_num2;
        return *this;
    }

    Fraction Fraction::operator--(int)
    {
        this->_num1 -= this->_num2;
        return *this;
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
        os << other._num1 << "/" << other._num2 << endl;
        return os;
    }

    istream &operator>>(istream &is, Fraction &other)
    {
        is >> other._num1 >> other._num2;
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
