#pragma once

#include <iostream>

void encode(std::istream &in, std::ostream &out, const tree &tree);

void decode(std::istream &in, std::ostream &out, tree &tree);
