#include <fstream>
#include <iostream>
#include <vector>
#include <utility>
#include "treeutils.h"
#include "huffman.h"

std::string convert(const code &bitset)
{
    std::string ret;
    for (bool b : bitset)
    {
        ret.append(b ? "1" : "0");
    }
    return ret;
}

int main(int argc, char* argv[])
{
    bool is_compress_mode = false;
    bool is_uncompress_mode = false;
    std::string in_file;
    std::string out_file;
    for (int i = 0; i < argc; ++i)
    {
        std::string arg(argv[i]);

        if (arg == "-f" || arg == "--file")
        {
            in_file = argv[i + 1];
        }

        if (arg == "-o" || arg == "--output")
        {
            out_file = argv[i + 1];
        }

        if (arg == "-u")
        {
            is_uncompress_mode = true;
        }

        if (arg == "-c")
        {
            is_compress_mode = true;
        }

    }

    if (!(is_compress_mode || is_uncompress_mode))
    {
        std::cout << "Missing action!" << std::endl;
    }

    if (in_file.empty())
    {
        std::cout << "Missing entry file name!" << std::endl;
    }

    if (out_file.empty())
    {
        std::cout << "Missing output file name!" << std::endl;
    }

    if (is_compress_mode)
    {
        std::ifstream in(in_file, std::ios::binary);
        auto counts = count_entries(in);
        tree tree = tree::build_tree(counts);
        std::vector<code> codes = tree.get_codes();

        uint64_t size = 0;
        for (size_t c = 0; c < codes.size(); ++c)
        {
            size += codes[c].size() * counts[c];
        }
        {
            std::ofstream out(out_file, std::ios::binary);

            in.clear();
            in.seekg(0, std::ios::beg);
            encode(in, out, tree);

            std::cout << tree.get_input_data_size() << std::endl;
            std::cout << size << std::endl;
            std::cout << tree.get_meta_data_size() << std::endl;

        }
    }

    if (is_uncompress_mode)
    {
        {
            tree tree;
            std::ifstream in(in_file, std::ios::binary);
            std::ofstream out(out_file, std::ios::binary);
            decode(in, out, tree);

            std::cout << tree.data_bit_size << std::endl;
            std::cout << tree.get_input_data_size() << std::endl;
            std::cout << tree.get_meta_data_size() << std::endl;

        }
    }

    return 0;
}
