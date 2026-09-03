#include "Enfrentamiento.h"
#include <random>
#include <stdexcept>

int Enfrentamiento::simularBatalla(const std::vector<Robot>& robots) const {
    if (robots.size() < 2) {
        throw std::invalid_argument("Se necesitan al menos 2 robots para simular una batalla.");
    }

    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<size_t> distIndice(0, robots.size() - 1);

    size_t indiceRobot1 = distIndice(gen);
    size_t indiceRobot2 = distIndice(gen);
    while (indiceRobot2 == indiceRobot1) {
        indiceRobot2 = distIndice(gen);
    }

    std::uniform_int_distribution<int> monedaDist(0, 1);
    return monedaDist(gen) == 0
        ? static_cast<int>(indiceRobot1)
        : static_cast<int>(indiceRobot2);
}