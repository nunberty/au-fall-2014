#pragma once

#include <string>

namespace apa
{
    class lint
    {
    public:
        explicit lint(std::string const& numstr);
        lint(int value);
        lint(double value);
        lint(lint const& value);

        explicit operator long() const;
        explicit operator bool() const;
        std::string to_str() const;

        lint& operator*=(lint const& value);
        lint& operator/=(lint const& value);
        lint& operator+=(lint const& value);
        lint& operator-=(lint const& value);

        bool operator<(lint const& value) const;
        bool operator==(lint const& value) const;
    private:
        uint32_t* value_;
        int8_t sign_;
    };

    std::istream& operator>>(std::istream& in, lint &value);
    std::ostream& operator<<(std::ostream& in, lint const& value);

    lint operator*(lint const& a, lint const&b);
    lint operator/(lint const& a, lint const&b);
    lint operator+(lint const& a, lint const&b);
    lint operator-(lint const& a, lint const&b);

    bool operator<=(lint const& a, lint const& b);
    bool operator>(lint const& a, lint const& b);
    bool operator>=(lint const& a, lint const& b);
    bool operator!=(lint const& a, lint const& b);

    lint& operator++(lint& value);
    lint& operator--(lint& value);
    lint& operator++(lint& value, int);
    lint& operator--(lint& value, int);
};
