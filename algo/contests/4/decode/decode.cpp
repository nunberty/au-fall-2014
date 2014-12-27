#include <fstream>
#include <string>
#include <stack>
#include <iostream>
#include <algorithm>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::ifstream in("decode.in");

    std::string s;
    in >> s;

    std::stack<char> ret;
    for (char c: s)
    {
        if (!ret.empty() && ret.top() == c)
        {
            ret.pop();
        }
        else
        {
            ret.push(c);
        }
    }

    std::string answer;
    answer.reserve(ret.size());
    while (!ret.empty())
    {
        answer += ret.top();
        ret.pop();
    }

    std::reverse(begin(answer), end(answer));
    std::ofstream out("decode.out");
    out << answer << std::endl;
    return 0;
}
