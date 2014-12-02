#pragma once

#include <istream>
#include <ostream>

namespace imprecise
{
    class mydouble
    {
        mydouble(double value, double da)
            : d(value)
            , da(std::max(da, default_da_multiplier * value))
        {}

        mydouble()
            : d(0)
            , da(default_da_multiplier)
        {}

        mydouble(double value)
            : d(value)
            , da(default_da_multiplier * value)
        {}

        double get_value() const;

        double get_presision() const;

        mydouble operator+(mydouble a);

        mydouble operator-();

        mydouble operator-(mydouble a);

        mydouble operator*(mydouble a);

        mydouble operator/(mydouble a);

        bool operator<(mydouble a);

        bool operator>(mydouble a);

        bool operator==(mydouble a);

        void operator=(mydouble a);

        void operator+=(mydouble a);

        void operator*=(mydouble a);

        void operator/=(mydouble a);

        void operator-=(mydouble a);

        bool operator>=(mydouble a);

        bool operator<=(mydouble a);

        bool operator!=(mydouble a);

        friend std::ostream& operator<<(std::ostream &output, mydouble a);

        friend std::istream& operator>>(std::istream  &input, mydouble b);
    private:

        const double default_da_multiplier = 0.000000000000001;

        double d;
        double da;
    };
} /* end namespace */
