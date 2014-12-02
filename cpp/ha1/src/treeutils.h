#pragma once

#include <cstdint>
#include <vector>
#include <array>
#include <iostream>
#include "utils.h"

struct tree
{
    tree();

    static tree build_tree(const std::array<unsigned int, chars_count> &counts);

    std::vector<code> get_codes() const;

    size_t get_start() const;

    bool is_leaf(size_t node) const;

    uint8_t get_char(size_t node) const;

    size_t get_next(size_t current, bool bit) const;

    uint64_t get_data_length() const;

    uint64_t get_input_data_size() const;

    uint64_t get_meta_data_size() const;

    uint64_t data_bit_size;
private:
    struct node
    {
        node(uint8_t symbol, unsigned int weight);

        node();

        node(unsigned int weight, size_t left, size_t right);

        bool is_leaf() const;

        std::array<size_t, 2> get_children() const;

        uint8_t symbol;
        unsigned int weight;
        size_t left;
        size_t right;
    };

    void init_codes_rec(const size_t  n, const code &c,
                      std::vector<code> &codes) const;

    std::array<node, 2 * chars_count> tree_;
    size_t n_nodes_;
    uint64_t data_length_;
    size_t root_;
};
