#include <fstream>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cmath>

struct random_emulator
{
    random_emulator(uint32_t a, uint32_t b)
        : a(a)
        , b(b)
        , cur(0)
    {}

    uint32_t next_rand24()
    {
        cur = cur * a + b;
        return cur >> 8;
    }

    uint32_t next_rand32()
    {
        uint32_t a = next_rand24();
        uint32_t b = next_rand24();
        return (a << 8) ^ b;
    }

private:
    uint32_t a;
    uint32_t b;
    uint32_t cur;
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::ifstream in("postman.in");
    std::ofstream out("postman.out");
    int n, a, b;
    in >> n >> a >> b;

    random_emulator re(a, b);
    std::vector<uint32_t> points(n);
    for (int i = 0; i < n; ++i)
    {
        points[i] = re.next_rand32();
    }
    uint32_t mid = n / 2;
    std::nth_element(begin(points), begin(points) + mid, points.end());
    int64_t median = points[mid];
    std::nth_element(begin(points), begin(points) + mid - 1, points.end());
    median = n % 2 == 0 ? (points[mid - 1] + median ) / 2 : median;
    int64_t sum = 0;
    for (int i = 0; i < n; ++i)
    {
        sum += std::abs(median - points[i]);
    }
    out << sum << std::endl;
    return 0;
}
