#include <iostream>
#include <set>
#include <fstream>
#include <random>

int main(int argc, char const* argv[])
{

    std::size_t count;
    try
    {
        if (argc != 2)
            throw std::invalid_argument("");

        std::string digit{argv[1]};
        count = std::stoul(digit);
    }
    catch (...)
    {
        throw std::invalid_argument("The programm must be started with 1 parameter, which means the points count.");
    }

    std::ofstream f;
    f.open("kkmeans_ex.txt");

    std::set<std::pair<float, float>> points;

    std::uniform_real_distribution<float> d{-100, 100};

    std::random_device rd;
    std::default_random_engine e{rd()};

    while (points.size() != count) {
        float x = d(e);
        float y = d(e);
        if(points.insert({x,y}).second)
            f << x << ';' << y << '\n';
    }

    f.close();

    return 0;
}