#include <string>
#include "lint.h"

namespace apa
{
    lint::lint(std::string const& numstr)
    {
        size_t start = 0;
        if (numstr[0] == '-')
        {
            sign_ = -1;
            ++start;
        }
        size_t len = numstr.length();
        value_ = new uint32_t[len];
        for (size_t i = start; i < len; ++i)
        {
            char c = numstr[i];
            if ('0' <= c && c <= '9')
            {
                value_[i] = c - '0';
            }
        }
    }

    lint::lint(int value)
    {
        lint(std::to_string(value));
    }

    lint::lint(double value)
    {
        lint(std::to_string(value));
    }

    lint::lint(lint const& value)
    {
        lint(value.to_str());
    }

    lint::operator long() const
    {}

    lint::operator bool() const
    {}

    std::string lint::to_str() const
    {}

    lint& lint::operator*=(lint const& value)
    {}

    lint& lint::operator/=(lint const& value)
    {}

    lint& lint::operator+=(lint const& value)
    {}

    lint& lint::operator-=(lint const& value)
    {}

    bool lint::operator<(lint const& value) const
    {}

    bool lint::operator==(lint const& value) const
    {}

    std::istream& operator>>(std::istream& in, lint &value)
    {}

    std::ostream& operator<<(std::ostream& in, lint const& value)
    {}

    lint operator*(lint const& a, lint const&b)
    {}

    lint operator/(lint const& a, lint const&b)
    {}

    lint operator+(lint const& a, lint const&b)
    {}

    lint operator-(lint const& a, lint const&b)
    {}

    bool operator<=(lint const& a, lint const& b)
    {
        return a < b || a == b;
    }

    bool operator>(lint const& a, lint const& b)
    {
        return b < a;
    }

    bool operator>=(lint const& a, lint const& b)
    {
        return b < a || b == a;
    }

    bool operator!=(lint const& a, lint const& b)
    {
        return !(a == b);
    }

    lint& operator++(lint& value)
    {}

    lint& operator--(lint& value)
    {
        lint tmp = value;
        --value;
        return tmp;
    }

    lint& operator++(lint& value, int)
    {}

    lint& operator--(lint& value, int)
    {}
}
