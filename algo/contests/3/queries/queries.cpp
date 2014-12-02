#include <fstream>
#include <algorithm>
#include <map>
#include <vector>

std::map<uint32_t, std::vector<uint32_t>> data;

bool contains(uint32_t l, uint32_t r, uint32_t value)
{
    if (data[value].empty())
    {
        return false;
    }

    auto low = std::lower_bound(begin(data[value]), end(data[value]), l);
    auto up = std::upper_bound(begin(data[value]), end(data[value]), r);

    return (up - low) > 0;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::ifstream in("queries.in");
    std::ofstream out("queries.out");

    uint32_t N;
    in >> N;
    for (uint32_t i = 1; i < N + 1; ++i)
    {
        uint32_t value;
        in >> value;
        data[value].push_back(i);
    }

    for (auto &pair : data)
    {
        std::sort(begin(pair.second), end(pair.second));
    }

    uint32_t K;
    in >> K;
    for (uint32_t i = 0; i < K; ++i)
    {
        uint32_t l, r, value;
        in >> l >> r >> value;
        out << contains(l , r, value);
    }
    out << std::endl;
    return 0;
}
