#include <iostream>
#include <fstream>

std::ifstream in;
std::ofstream out;

int parse();

int number()
{
    int res = 0;
    for (;;)
    {
        char c = in.get();
        if (c >= '0' && c <= '9')
            res = res * 10 + c - '0';
        else
        {
            in.putback(c);
            return res;
        }
    }
}

int braces()
{
    char c = in.get();
    if (c == '(')
    {
        int x = parse();
        in.get();
        return x;
    }
    else
    {
        in.putback(c);
        return number();
    }
}

int factor()
{
    int x = braces();
    for (;;)
    {
        char c = in.get();
        switch (c)
        {
            case '*':
                x *= braces();
                break;
            case '/':
                x /= braces();
                break;
            default:
                in.putback(c);
                return x;
        }
    }
}

int parse()
{
    int x = factor();
    for (;;)
    {
        char c = in.get();
        switch (c)
        {
            case '+':
                x += factor();
                break;
            case '-':
                x -= factor();
                break;
            default:
                in.putback(c);
                return x;
        }
    }
}


int main()
{
    std::ifstream in("evalhard.in");
    std::ofstream out("evalhard.out");
    out << parse() << std::endl;
}
