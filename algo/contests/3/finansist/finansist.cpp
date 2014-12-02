#include <fstream>
#include <vector>

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

uint64_t gcd(uint64_t sum, uint64_t n)
{
    while (n != 0) {
        unsigned r = sum % n;
        sum = n;
        n = r;
    }
    return sum;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::ifstream in("finansist.in");

    uint64_t n, a, b;
    in >> n >> a >> b;
    random_emulator re(a, b);

    uint64_t sum = 0;
    std::vector<uint32_t> points(n);
    for (size_t i = 0; i < n; ++i)
    {
        points[i] = re.next_rand32();
        sum += points[i];
    }
    std::ofstream out("finansist.out");
    uint64_t gcd_n_sum = gcd(sum, n);
    out << sum/gcd_n_sum << "/" << n/gcd_n_sum << std::endl;
    return 0;
}
