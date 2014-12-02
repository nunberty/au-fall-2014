#include <vector>
#include <array>
#include <queue>
#include <limits>
#include <cstdint>
#include "utils.h"
#include "treeutils.h"

tree::node::node(uint8_t symbol, unsigned int weight)
    : symbol(symbol)
    , weight(weight)
    , left(-1)
    , right(-1)
{}

tree::node::node()
{}

tree::node::node(unsigned int weight, size_t left, size_t right)
    : symbol(0)
    , weight(weight)
    , left(left)
    , right(right)
{}

bool tree::node::is_leaf() const
{
    return left == std::numeric_limits<size_t>::max();
}

std::array<size_t, 2> tree::node::get_children() const
{
    return {{left, right}};
}

tree::tree()
    : n_nodes_(0)
    , data_length_(0)
    , root_(0)
{}

tree tree::build_tree(const std::array<unsigned int, chars_count> &counts)
{
    tree res;

    auto comp = [&] (size_t a, size_t b)
        {
            return res.tree_[a].weight > res.tree_[b].weight;
        };

    std::priority_queue<size_t, std::vector<size_t>, decltype(comp)>
        queue(comp);
    for (size_t c = 0; c < counts.size(); ++c)
    {
            res.data_length_ += counts[c];
            res.tree_[res.n_nodes_] = node(c, counts[c]);
            queue.push(res.n_nodes_);
            ++res.n_nodes_;
    }

    while (queue.size() != 1)
    {
        size_t a = queue.top();
        queue.pop();
        size_t b = queue.top();
        queue.pop();
        node ab(res.tree_[a].weight + res.tree_[b].weight, a, b);
        res.tree_[res.n_nodes_] = ab;
        queue.push(res.n_nodes_);
        ++res.n_nodes_;
    }

    res.root_ = queue.top();
    return res;
}

void tree::init_codes_rec(const size_t n, const code &c,
                        std::vector<code> &codes) const
{
    if (tree_[n].is_leaf())
    {
        codes[tree_[n].symbol] = c;
        return;
    }

    auto children = tree_[n].get_children();
    for (int i = 0; i < 2; ++i)
    {
        code code(c);
        code.push_back(i);
        init_codes_rec(children[i], code, codes);
    }
}

std::vector<code> tree::get_codes() const
{
    code c;
    std::vector<code> codes(chars_count);
    init_codes_rec(root_, c, codes);
    return codes;
}

size_t tree::get_start() const
{
    return root_;
}

bool tree::is_leaf(size_t node) const
{
    return tree_[node].is_leaf();
}

uint8_t tree::get_char(size_t node) const
{
    return tree_[node].symbol;
}

size_t tree::get_next(size_t current, bool bit) const
{
    return tree_[current].get_children()[bit];
}

uint64_t tree::get_data_length() const
{
    return data_length_;
}

uint64_t tree::get_input_data_size() const
{
    return data_length_ * sizeof(uint8_t);
}

uint64_t tree::get_meta_data_size() const
{
    return sizeof(tree);
}
