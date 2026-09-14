#include "Enfrentamiento.h"
#include <random>

int Enfrentamiento::simularBatalla(const Robot&, const Robot&) const {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<int> dist(0, 1);

    return dist(gen);
}

