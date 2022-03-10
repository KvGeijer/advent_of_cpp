#include "main.hpp"

int main()
{
    auto modules = parse();

    fuel_computations(modules);
}


std::vector<int> parse()
{
    int weight;
    std::vector<int> modules;

    while (std::cin >> weight)
    {
        modules.push_back(weight);
    }

    return modules;
}


void fuel_computations(std::vector<int> modules)
{
    SpaceShip ship;

    for (int weight : modules)
    {
        ship.add_module(weight);
    }

    std::cout << "Amount of fuel if ignoring fuel weight: " << ship.get_naive_weight() << std::endl
                << "Amount of real fuel required, if wishing really hard: " << ship.get_weight() << std::endl;
}

void SpaceShip::add_module(int module_weight)
{
    int extra = module_weight/3 - 2;

    naive_weight += extra;
    while (extra > 0)
    {
        weight += extra;
        extra = extra/3 - 2;
    }
}