#include <iostream>
#include <fstream>

typedef unsigned int uint32_t;
const uint32_t size = 1 << 24;
uint32_t data[size];

class my_random
{
public:
    my_random(uint32_t a, uint32_t b)
        : a_(a)
        , b_(b)
        , cur_(0)..
    {}

    uint32_t next()
    {
        cur_ = cur_ * a_ + b_;
        return cur_ >> 8;
    }
private:
    const uint32_t a_;
    const uint32_t b_;
    uint32_t cur_;
};

void add(uint32_t l, uint32_t r, uint32_t val)
{
    data[l] += val;
    data[r] -= val;
}

void build_sum_array()
{
    for (uint32_t i = 1; i < size; ++i)
    {
        data[i] += data[i - 1];
    }
    for (uint32_t i = 1; i < size; ++i)
    {
        data[i] += data[i - 1];
    }
}

uint32_t get_sum(uint32_t l, uint32_t r)
{
    if (l == 0)
    {
        return data[r - 1];
    }
    return data[r - 1] - data[l - 1];
}
int main()
{
    std::ifstream in("fastadd.in");
    uint32_t m, q, a, b;
    in >> m;
    in >> q;
    in >> a;
    in >> b;
    my_random random(a, b);
    for (uint32_t i = 0; i < m; ++i)
    {
        uint32_t val = random.next();
        uint32_t l = random.next();
        uint32_t r = random.next();
        if (r < l)
        {
            std::swap(l, r);
        }
        add(l, r + 1, val);
    }

    build_sum_array();
    uint32_t sum = 0;
    for (uint32_t i = 0; i < q; ++i)
    {
        uint32_t l = random.next();
        uint32_t r = random.next();
        if (r < l)
        {
            std::swap(l, r);
        }
        sum += get_sum(l, r + 1);
    }
    std::ofstream out("fastadd.out");
    out << sum << std::endl;
    return 0;
}
