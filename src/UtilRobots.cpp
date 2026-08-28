#include "UtilRobots.h"
#include <random>
#include <stdexcept>

std::vector<Robot> filtrarPorTipo(const std::vector<Robot>& robots, const std::string& tipo) {
    std::vector<Robot> resultado;
    for (const auto& r : robots) {
        if (r.getTipo() == tipo) {
            resultado.push_back(r);
        }
    }
    return resultado;
}

int simularBatalla(const std::vector<Robot>& robots) {
    if (robots.size() < 2) {
        throw std::invalid_argument("Se necesitan al menos 2 robots para simular una batalla.");
    }

    // Generador moderno de numeros aleatorios (mejor distribucion que rand())
    static std::random_device rd;
    static std::mt19937 gen(rd());

    std::uniform_int_distribution<size_t> distIndice(0, robots.size() - 1);

    // Elegir dos indices distintos
    size_t idx1 = distIndice(gen);
    size_t idx2 = distIndice(gen);
    while (idx2 == idx1) {
        idx2 = distIndice(gen);
    }

    // Elegir ganador entre los dos (50/50 por ahora; cada equipo puede
    // ponderar esto mas adelante segun atributos del robot)
    std::uniform_int_distribution<int> monedaDist(0, 1);
    int moneda = monedaDist(gen);

    return (moneda == 0) ? static_cast<int>(idx1) : static_cast<int>(idx2);
}
