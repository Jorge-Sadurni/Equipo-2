#include "Disciplina.h"
#include "Enfrentamiento.h"
#include <iostream>
#include <algorithm>
#include <random>
#include <stdexcept>

Disciplina::Disciplina(const std::string& tipo) : tipo(tipo) {}

void Disciplina::inscribirRobot(const Robot& robot) {
    if (robot.getTipo() != tipo) {
        throw std::invalid_argument("Tipo de robot no coincide con la disciplina");
    }
    robots.push_back(robot);
}

void Disciplina::generarEnfrentamientos() {
    if (robots.empty()) {
        std::cout << "Disciplina " << tipo << ": NO HUBO ROBOTS INSCRITOS" << std::endl;
        return;
    }

    if (robots.size() == 1) {
        std::cout << "Disciplina " << tipo
                  << ": NO HUBO ROBOTS SUFICIENTES, SOLO HAY 1 ROBOT INSCRITO"
                  << std::endl;
        return;
    }
    
    // Mezclar robots aleatoriamente
    std::vector<Robot> robotsMezclados = robots;
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(robotsMezclados.begin(), robotsMezclados.end(), g);
    
    // Crear parejas
    for (size_t i = 0; i < robotsMezclados.size() - 1; i += 2) {
        enfrentamientos.push_back({robotsMezclados[i], robotsMezclados[i + 1]});
    }
    
    // Si queda un robot sin pareja, reportarlo
    if (robotsMezclados.size() % 2 != 0) {
        const Robot& sinRival = robotsMezclados[robotsMezclados.size() - 1];
        std::cout << "Robot sin rival en " << tipo << ": " << sinRival.getNombre() 
                  << " - Pasa directamente a la siguiente fase" << std::endl;
    }
}

void Disciplina::ejecutarEnfrentamientos() {
    Enfrentamiento enfrentamiento;
    
    for (const auto& par : enfrentamientos) {
        int ganadorIndex = enfrentamiento.simularBatalla(par.first, par.second);
        const Robot& ganador = (ganadorIndex == 0) ? par.first : par.second;
        
        std::string resultado = par.first.getNombre() + " vs " + par.second.getNombre() + 
                               " - GANADOR: " + ganador.getNombre();
        resultados.push_back(resultado);
        std::cout << resultado << std::endl;
    }
}

const std::vector<std::string>& Disciplina::getResultados() const {
    return resultados;
}
