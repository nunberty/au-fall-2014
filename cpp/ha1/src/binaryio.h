#pragma once

#include "utils.h"

class bit_reader
{
 public:
    bit_reader(std::istream &in);

    bool read_bit();

 private:
    std::istream& in_;

    uint8_t  buffer_;

    uint64_t length_;
};

class bit_writer
{
 public:

    bit_writer(std::ostream &out);

    void write(const code &code);

    void write_bit(bool bit);

    void flush_buffer();

 private:

    std::ostream& out_;

    uint8_t buffer_;

    uint64_t length_;
};
