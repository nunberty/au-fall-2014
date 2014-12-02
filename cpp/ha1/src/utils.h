#pragma once

#include <limits>
#include <vector>
#include <array>

typedef std::vector<bool> code;

const int chars_count = std::numeric_limits<uint8_t>::max() + 1;

std::array<unsigned int, chars_count> count_entries(std::istream &in);
