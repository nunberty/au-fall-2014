#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm>

uint32_t count(const std::vector<int32_t> &nums, int32_t l, int32_t r)
{
    auto low = std::lower_bound(begin(nums), end(nums), l);
    auto up = std::upper_bound(begin(nums), end(nums), r);
    return up - low;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::ifstream in("find3.in");
    std::ofstream out("find3.out");

    uint32_t N;
    in >> N;
    std::vector<int32_t> nums(N);
    for (uint32_t i = 0; i < N; ++i)
    {
        in >> nums[i];
    }
    std::sort(begin(nums), end(nums));

    uint32_t K;
    in >> K;
    for (uint32_t i = 0; i < K; ++i)
    {
        int32_t l, r;
        in >> l >> r;
        out << count(nums, l , r) << " ";
    }
    return 0;
}
