#include "Disciplina.h"
#include "Enfrentamiento.h"
#include <iostream>
#include <algorithm>
#include <map>
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
        const std::string mensaje = "NO SE LLEVARON A CABO LOS ENFRENTAMIENTOS DE " + tipo + ": NO HUBO ROBOTS INSCRITOS";
        resultados.push_back(mensaje);
        std::cout << mensaje << std::endl;
        return;
    }

    if (robots.size() == 1) {
        const std::string mensaje = "NO SE LLEVARON A CABO LOS ENFRENTAMIENTOS DE " + tipo
            + ": NO HUBO ROBOTS SUFICIENTES, SOLO HAY 1 ROBOT INSCRITO";
        resultados.push_back(mensaje);
        std::cout << mensaje << std::endl;
        return;
    }
    
    // Mezclar robots aleatoriamente
    std::vector<Robot> robotsMezclados = robots;
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(robotsMezclados.begin(), robotsMezclados.end(), g);
    
    for (size_t i = 0; i < robotsMezclados.size(); ++i) {
        for (size_t j = i + 1; j < robotsMezclados.size(); ++j) {
            enfrentamientos.push_back({robotsMezclados[i], robotsMezclados[j]});
        }
    }
}

void Disciplina::ejecutarEnfrentamientos() {
    if (robots.size() < 2) {
        return;
    }

    Enfrentamiento enfrentamiento;
    std::map<std::string, int> victorias;

    for (const auto& robot : robots) {
        victorias[robot.getNombre()] = 0;
    }
    
    for (const auto& par : enfrentamientos) {
        int ganadorIndex = enfrentamiento.simularBatalla(par.first, par.second);
        const Robot& ganador = (ganadorIndex == 0) ? par.first : par.second;
        ++victorias[ganador.getNombre()];
        
        std::string resultado = par.first.getNombre() + " vs " + par.second.getNombre() + 
                               " - GANADOR: " + ganador.getNombre();
        resultados.push_back(resultado);
        std::cout << resultado << std::endl;
    }

    const Robot* ganadorAbsoluto = &robots.front();
    for (const auto& robot : robots) {
        if (victorias[robot.getNombre()] > victorias[ganadorAbsoluto->getNombre()]) {
            ganadorAbsoluto = &robot;
        }
    }

    std::string resultadoFinal = "GANADOR ABSOLUTO DE " + tipo + ": " + ganadorAbsoluto->getNombre();
    resultados.push_back(resultadoFinal);
    std::cout << resultadoFinal << std::endl;
}

const std::vector<std::string>& Disciplina::getResultados() const {
    return resultados;
}
