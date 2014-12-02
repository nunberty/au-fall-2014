#include <fstream>
#include <limits>
#include <cstdint>
#include <iostream>
#include <iomanip>
#include <cassert>


struct cubic_function
{
    long double a;
    long double b;
    long double c;
    long double d;

    long double eval(long double x) const
    {
        return d + x * (c + x * (b + x * a));
    }

    long double operator()(long double x) const
    {
        return eval(x);
    }

    cubic_function normalized() const
    {
        return (a >= 0)
            ? cubic_function{a, b, c, d}
            : cubic_function{-a, -b, -c, -d};
    }
};

double bisect(cubic_function f)
{
    f = f.normalized();
    long double l = -20000.0;
    long double r = 20000.0;
    const int n_iter = 100;
    for (int i = 0; i < n_iter; ++i)
    {
        assert (f(l) <= 0);
        assert (f(r) >= 0);
        long double m = l + (r - l) / 2;
        (f(m) > 0 ? r : l) = m;
    }
    return l;
}

int main()
{
    cubic_function func;

    std::ifstream in("cubroot.in");
    in >> func.a >> func.b >> func.c >> func.d;

    double root = bisect(func);
    std::ofstream out("cubroot.out");
    out << std::setprecision(9) << root << std::endl;
    return 0;
}
