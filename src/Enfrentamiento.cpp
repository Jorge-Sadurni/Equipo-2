#include "Enfrentamiento.h"
#include <cstdlib>
#include <ctime>
#include <stdexcept>

int Enfrentamiento::simularBatalla(const Robot&, const Robot&) const {
    // Decisión aleatoria (50% de probabilidad para cada uno)
    return (rand() % 2 == 0) ? 0 : 1;
}

int Enfrentamiento::simularBatalla(const std::vector<Robot>& robots) const {
    if (robots.size() != 2) {
        throw std::invalid_argument("Se necesitan exactamente 2 robots para una batalla");
    }
    return simularBatalla(robots[0], robots[1]);
}