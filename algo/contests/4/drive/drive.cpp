#include <fstream>
#include <string>
#include <stack>
#include <iostream>
#include <algorithm>
#include <iomanip>

struct lights
{
    uint32_t red;
    uint32_t green;
    uint32_t position;

    bool operator<(lights const& other) const
    {
        return position < other.position;
    }

    double before_green(double time) const
    {
        time = std::fmod(time, red + green);
        return red > time ? red - time : 0;
    }
};

bool is_fast_enough(double speed, uint32_t time, uint32_t dest,
                    std::vector<lights> const& traffic_lights)
{
    double pos = 0;
    double t = 0;

    for (lights const& l : traffic_lights)
    {
        t += (l.position - pos) / speed;
        pos = l.position;
        t += l.before_green(t);
    }
    if (pos < dest)
    {
        t += (dest - pos) / speed;
    }

    return t < time;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::ifstream in("drive.in");

    uint32_t T, D, N;
    in >> T >> D >> N;

    std::vector<lights> lights;
    for (size_t i = 0; i < N; ++i)
    {
        uint32_t red, green, pos;
        in >> red >> green >> pos;
        if (pos <= D)
        {
            lights.push_back({red, green, pos});
        }
    }

    std::sort(begin(lights), end(lights));

    double answer;
    const double max_speed = 1e12;
    if (!is_fast_enough(max_speed, T, D, lights))
    {
        answer = -1.0;
    }
    else
    {
        double lower = (double) D/T;
        double upper = max_speed;

        for (size_t i = 0; i < 1000; ++i)
        {
            double mid = (lower + upper) / 2;
            (is_fast_enough(mid, T, D, lights) ? upper : lower) = mid;
        }
        answer = upper;
    }
    std::ofstream out("drive.out");
    out << std::setprecision(18) << answer << std::endl;
    return 0;
}
