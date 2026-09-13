#include "Enfrentamiento.h"
#include <random>
#include <stdexcept>

int Enfrentamiento::simularBatalla(const Robot&, const Robot&) const {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<int> dist(0, 1);

    return dist(gen);
}

int Enfrentamiento::simularBatalla(const std::vector<Robot>& robots) const {
    if (robots.size() != 2) {
        throw std::invalid_argument("Se necesitan exactamente 2 robots para una batalla");
    }
    return simularBatalla(robots[0], robots[1]);
}