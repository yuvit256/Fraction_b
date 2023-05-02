#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cstdlib>
using namespace std;

namespace ariel
{
    class Fraction
    {
    private:
        int _num1;

        int _num2;

    public:
        Fraction(int num1, int num2); // constructor

        ~Fraction(); //destructor

        Fraction(const Fraction &other); // copy constructor

        Fraction(Fraction&& other) noexcept; // move constructor

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

        Fraction& operator=(Fraction&&) noexcept; // move operator
    };
};

#endif