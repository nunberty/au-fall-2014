#include "treeutils.h"
#include "binaryio.h"
#include "huffman.h"

void encode(std::istream &in, std::ostream &out, const tree &tree)
{
    out.write(reinterpret_cast<const char*>(&tree), sizeof(tree));

    std::vector<code> codes = tree.get_codes();
    bit_writer writer(out);

    uint8_t byte;
    while (in.read(reinterpret_cast<char*>(&byte), sizeof(byte)))
    {
        code c = codes[byte];
        writer.write(c);
    }
    writer.flush_buffer();
}

void decode(std::istream &in, std::ostream &out, tree &tree)
{
    in.read(reinterpret_cast<char*>(&tree), sizeof(tree));

    uint64_t data_length = tree.get_data_length();

    bit_reader reader(in);

    while (data_length > 0)
    {
        auto parent = tree.get_start();

        while (!tree.is_leaf(parent))
        {
            bool bit = reader.read_bit();
            parent = tree.get_next(parent, bit);
            ++tree.data_bit_size;
        }
        uint8_t c = tree.get_char(parent);
        out.write(reinterpret_cast<const char*>(&c), sizeof(uint8_t));

        --data_length;
    }
}
