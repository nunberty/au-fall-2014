#include <algorithm>
#include <fstream>
#include <iostream>

class random_emulator
{
public:
    random_emulator(uint32_t a, uint32_t b)
        : a_(a)
        , b_(b)
        , cur_(0)
    {}

    uint32_t next_rand_32()
    {
        uint32_t a = next_rand_24();
        uint32_t b = next_rand_24();
        return (a << 8) ^ b;
    }
private:
    uint32_t next_rand_24()
    {
        cur_ = cur_ * a_ + b_;
        return cur_ >> 8;
    }

    const uint32_t a_;
    const uint32_t b_;
    uint32_t cur_;
};

struct point
{
    uint32_t x;
    uint32_t val;

    bool operator<(point other) const
    {
        return x < other.x;
    }
};

int main() {
    std::ifstream inf("linesum.in");

    uint32_t n, q;
    uint32_t a, b;
    inf >> n >> q >> a >> b;
    random_emulator re(a, b);

    std::vector<point> points(n);
    for (point& p : points)
    {
        p.val = re.next_rand_32();
        p.x = re.next_rand_32();
    }
    std::sort(begin(points), end(points));

    std::vector<uint32_t> sum(n + 1);
    sum[0] =  0;
    for (size_t i = 1; i <= n; ++i)
    {
        sum[i] = sum[i - 1] + points[i - 1].val;
    }

    uint32_t result = 0;
    for (uint32_t i = 0; i < q; ++i)
    {
        uint32_t l = re.next_rand_32();
        uint32_t r = re.next_rand_32();
        if (l > r)
        {
            std::swap(l, r);
        }

        size_t nl = std::lower_bound(begin(points), end(points), point{l, 0}) - begin(points);
        size_t nr = std::upper_bound(begin(points), end(points), point{r, 0}) - begin(points);
        result += sum[nr] - sum[nl];
    }

    std::ofstream outf("linesum.out");
    outf << result;
    return 0;
}
