#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdio>

enum event_type
{
    POINT = 0,
    LBRACE = 1,
    RBRACE = -1
};

struct event
{
    long time;
    event_type type;
    int id;
};

int main()
{
    FILE* in = fopen("segments.in", "r");
    int n, m;
    fscanf(in, "%d %d", &n, &m);
    std::vector<event> events;
    for (int i = 0; i < n; ++i)
    {
        long a, b;
        fscanf(in, "%ld %ld", &a, &b);
        if (a > b)
        {
            std::swap(a, b);
        }
        events.push_back({a, LBRACE, 0});
        events.push_back({b, RBRACE, 0});
    }
    for (int i = 0; i < m; ++i)
    {
        long p;
        fscanf(in, "%ld", &p);
        events.push_back({p, POINT, i});
    }
    fclose(in);
    auto cmp = [](event x, event y) -> bool
        {
            if (x.time < y.time)
            {
                return true;
            }
            if (x.time > y.time)
            {
                return false;
            }
            return y.type < x.type;
        };
    std::sort(events.begin(), events.end(), cmp);

    std::vector<int> answers(m, 0);
    int counter = 0;
    for (event &e : events)
    {
        switch(e.type)
        {
        case POINT:
            answers[e.id] = counter;
            break;
        case LBRACE:
            ++counter;
            break;
        case RBRACE:
            --counter;
            break;
        }
    }

    FILE* out = fopen("segments.out", "w");
    for (int i = 0; i < m; ++i)
    {
        fprintf(out, "%d ", answers[i]);
    }
    fprintf(out, "\n");
    fclose(out);
    return 0;
}
