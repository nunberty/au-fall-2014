#include <istream>
#include <ostream>

#include "mydouble.h"

namespace imprecise {
    double mydouble::get_value() const
    {
        return d;
    }

    double mydouble::get_presision() const
    {
        return da;
    }

    mydouble mydouble::operator+(mydouble a)
    {
        return mydouble(d + a.get_value(), da + a.get_presision());
    }

    mydouble mydouble::operator-()
    {
        return mydouble(-d, da);
    }

    mydouble mydouble::operator-(mydouble a)
    {
        return operator+(-a);
    }

    mydouble mydouble::operator*(mydouble a)
    {
        return mydouble(
                        d * a.get_value(),
                        da * a.get_value() + d * a.get_presision()
                        );
    }

    mydouble mydouble::operator/(mydouble a)
    {
        return mydouble(
                        d / a.get_value(),
                        da / a.get_value() + d * a.get_presision() / (a.get_value() * a.get_value())
                        );
    }

    bool mydouble::operator<(mydouble a)
    {
        return d + da < a.get_value() - a.get_presision();
    }

    bool mydouble::operator==(mydouble a)
    {
        double ra = d- da;
        double la = d + da;
        double lb = a.get_value() - a.get_presision();
        double rb = a.get_value() + a.get_presision();

        return ra <= lb || rb <= la;
    }

    bool mydouble::operator>(mydouble a)
    {
        return !(operator<(a)) && !(operator==(a));
    }

    void mydouble::operator=(mydouble a)
    {
        d = a.get_value();
        da = a.get_presision();
    }


    void mydouble::operator+=(mydouble a)
    {
        return operator=(operator+(a));
    }

    void mydouble::operator*=(mydouble a)
    {
        return operator=(operator*(a));
    }

    void mydouble::operator/=(mydouble a)
    {
        return operator=(operator/(a));
    }

    void mydouble::operator-=(mydouble a)
    {
        return operator=(operator-(a));
    }

    bool mydouble::operator>=(mydouble a)
    {
        return operator>(a) || operator==(a);
    }

    bool mydouble::operator<=(mydouble a)
    {
        return operator<(a) || operator==(a);
    }

    bool mydouble::operator!=(mydouble a)
    {
        return !operator==(a);
    }

    std::ostream& operator<<(std::ostream &output, mydouble a)
    {
        output << a.get_value() << " " << a.get_presision();
        return output;
    }

    std::istream& operator>>(std::istream  &input, mydouble a)
    {
        double value;
        double presision;
        input >> value >> presision;
        a = mydouble(value, presision);
        return input;
    }

}
