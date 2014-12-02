#include <array>
#include <istream>
#include "utils.h"

std::array<unsigned int, chars_count> count_entries(std::istream &in)
{
    std::array<unsigned int, chars_count> counts;
    counts.fill(0);

    uint8_t byte;
    while (in.read(reinterpret_cast<char*>(&byte), sizeof(byte)))
    {
        ++counts[byte];
    }

    return counts;
}
