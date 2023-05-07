#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <limits>
#include <cstdlib>
using namespace std;

namespace ariel
{
    class Fraction
    {
    private:
        int _num1;

        int _num2;

        static const int max = numeric_limits<int>::max();

        static const int min = numeric_limits<int>::min();

    public:
        int getNumerator() const
        {
            return this->_num1;
        }

        int getDenominator() const
        {
            return this->_num2;
        }

        static int _overflow_addition_check(int num1, int num2)
        {
            if ((num2 > 0 && num1 > (max - num2)) || (num2 < 0 && num1 < (min - num2)))
            {
                throw std::overflow_error("+ overflow");
            }

            return (num1 + num2);
        }

        static int _overflow_subtraction_check(int num1, int num2)
        {
            if ((num2 < 0 && num1 > max + num2) || (num2 > 0 && num1 < min + num2))
            {
                throw std::overflow_error("- overflow");
            }

            return (num1 - num2);
        }

        static int _overflow_multiplication_check(int num1, int num2)
        {
            if ((num2 > 0 && num1 > max / num2) || (num2 < 0 && num1 < max / num2))
            {
                throw std::overflow_error("* overflow");
            }

            return (num1 * num2);
        }

        static int _overflow_division_check(int num1, int num2)
        {
            if (num2 == 0 || (num1 == min && num2 == -1))
            {
                throw std::overflow_error("/ overflow");
            }

            return (num1 / num2);
        }

        Fraction(int num1, int num2); // constructor

        Fraction(float num); // constructor

        Fraction(); // default constructor

        ~Fraction(); // destructor

        Fraction(const Fraction &other); // copy constructor

        Fraction(Fraction &&other) noexcept; // move constructor

        // +
        Fraction operator+(const Fraction &) const;

        Fraction operator+(float) const;

        friend Fraction operator+(float, const Fraction &);

        // -
        Fraction operator-(const Fraction &) const;

        Fraction operator-(float) const;

        friend Fraction operator-(float, const Fraction &);

        // *
        Fraction operator*(const Fraction &) const;

        Fraction operator*(float) const;

        friend Fraction operator*(float, const Fraction &);

        // /
        Fraction operator/(const Fraction &) const;

        Fraction operator/(float) const;

        friend Fraction operator/(float, const Fraction &);

        // +=
        friend Fraction &operator+=(Fraction &, const Fraction &);

        friend Fraction &operator+=(Fraction &, float);

        // -=
        friend Fraction &operator-=(Fraction &, const Fraction &);

        friend Fraction &operator-=(Fraction &, float);

        // *=
        friend Fraction &operator*=(Fraction &, const Fraction &);

        friend Fraction &operator*=(Fraction &, float);

        // /=
        friend Fraction &operator/=(Fraction &, const Fraction &);

        friend Fraction &operator/=(Fraction &, float);

        // ++
        Fraction &operator++();

        Fraction operator++(int);

        // --
        Fraction &operator--();

        Fraction operator--(int);

        // ==
        bool operator==(const Fraction &) const;

        bool operator==(float) const;

        friend bool operator==(float, const Fraction &);

        // >
        bool operator>(const Fraction &) const;

        bool operator>(float) const;

        friend bool operator>(float, const Fraction &);

        // <
        bool operator<(const Fraction &) const;

        bool operator<(float) const;

        friend bool operator<(float, const Fraction &);

        // >=
        bool operator>=(const Fraction &) const;

        bool operator>=(float) const;

        friend bool operator>=(float, const Fraction &);

        // <=
        bool operator<=(const Fraction &) const;

        bool operator<=(float) const;

        friend bool operator<=(float, const Fraction &);

        // <<
        friend ostream &operator<<(ostream &, const Fraction &);

        // >>
        friend istream &operator>>(istream &, Fraction &);

        // =
        Fraction &operator=(const Fraction &);

        Fraction &operator=(Fraction &&) noexcept; // move operator
    };
};

#endif