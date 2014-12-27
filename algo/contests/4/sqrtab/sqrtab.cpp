#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>

uint32_t partition_count(uint32_t test)
{
    if (test % 3 == 0 && test % 9 != 0)
    {
        return 0;
    }

    uint32_t sqrt_root = std::sqrt(test / 2.0);
    uint32_t ret = 0;
    for (uint32_t i = 1; i <= sqrt_root; ++i)
    {
        uint32_t diff = test - i * i;
        uint32_t root = std::sqrt(diff);
        if (diff != 0 && test == i * i + root * root)
        {
            ret += root == i ? 1 : 2;
        }
    }
    return ret;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::ifstream in("sqrtab.in");
    size_t count;
    in >> count;

    std::vector<uint32_t> tests(count);
    for (size_t i = 0; i < count; ++i)
    {
        in >> tests[i];
    }

    std::ofstream out("sqrtab.out");
    for (size_t i = 0; i < count; ++i)
    {
        out << partition_count(tests[i]) << std::endl;
    }

    return 0;
}
