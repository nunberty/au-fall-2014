#include <fstream>
#include <cassert>
#include <cmath>
#include <iostream>

uint64_t sqrt_(uint64_t value)
{
    uint64_t root = std::sqrt(value);
    uint64_t sqr = root * root;
    if (sqr == value)
    {
        return root;
    }

    uint64_t l = 0;
    uint64_t r = (1ul << 32) - 1;
    if (r * r <= value)
    {
        return r;
    }
    assert (l * l <= value && "pre");
    assert (r * r > value && "pre");
    while (r - l > 1)
    {
        uint64_t mid = (l + r) / 2;
        if (mid * mid == value)
        {
            return mid;
        }
        if (mid * mid > value)
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }
    assert (l * l <= value);
    assert (r * r > value);


    return l;
}

int main()
{
    std::ifstream in("sqrt.in");
    std::ofstream out("sqrt.out");

    uint64_t a;
    while (in >> a)
    {
        out << sqrt_(a) << std::endl;
    }

    return 0;
}
