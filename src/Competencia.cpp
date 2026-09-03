#include "Competencia.h"

std::vector<Robot> Competencia::filtrarPorTipo(const std::vector<Robot>& robots,
                                               const std::string& tipo) const {
    std::vector<Robot> resultado;
    for (const auto& robot : robots) {
        if (robot.getTipo() == tipo) {
            resultado.push_back(robot);
        }
    }
    return resultado;
}