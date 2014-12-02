#include <iostream>
#include "binaryio.h"

bit_reader::bit_reader(std::istream &in)
    : in_(in)
    , buffer_(0)
    , length_(0)

{}

bool bit_reader::read_bit()
{
    unsigned int pos = length_ % 8;
    if (pos == 0)
    {
        in_.read(reinterpret_cast<char*>(&buffer_), sizeof(buffer_));

    }
    ++length_;
    bool b = (buffer_ >> (7 - (pos))) & 1;
    return b;
}

bit_writer::bit_writer(std::ostream &out)
    : out_(out)
    , buffer_(0)
    , length_(0)
{}

void bit_writer::write(const code &code)
{
    for (bool b: code)
    {
        write_bit(b);
    }
}

void bit_writer::write_bit(bool bit)
{
    unsigned int pos = length_ % 8;
    ++length_;
    buffer_ |= bit << (7 - pos);
    if (pos == 7)
    {
        flush_buffer();
    }
}

void bit_writer::flush_buffer()
{
    out_.write(reinterpret_cast<char*>(&buffer_), sizeof(buffer_));
    buffer_ = 0;
}
