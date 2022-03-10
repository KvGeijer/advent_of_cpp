#include <iostream>
#include <vector>

int main();
std::vector<int> parse();
void fuel_computations(std::vector<int> modules);

class SpaceShip {
    public:
        SpaceShip() { weight = 0; }
        void add_module(int module_weight);
        int get_weight() { return weight; }
        int get_naive_weight() { return naive_weight; }

    private:
        int weight;
        int naive_weight;
};
