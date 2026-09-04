#include "Disciplina.h"
#include <iostream>
#include <algorithm>
#include <random>

Disciplina::Disciplina(const std::string& tipo) : tipo(tipo) {}

void Disciplina::inscribirRobot(const Robot& robot) {
    if (robot.getTipo() != tipo) {
        throw std::invalid_argument("Tipo de robot no coincide con la disciplina");
    }
    robots.push_back(robot);
}

bool Disciplina::tieneRobots() const {
    return !robots.empty();
}

int Disciplina::cantidadRobots() const {
    return robots.size();
}

void Disciplina::generarEnfrentamientos() {
    if (robots.size() < 2) {
        std::cout << "Disciplina " << tipo << ": No hay suficientes robots para enfrentamientos" << std::endl;
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
        std::cout << "⚠️ Robot sin rival en " << tipo << ": " << sinRival.getNombre() 
                  << " - Pasa directamente a la siguiente fase" << std::endl;
    }
}

void Disciplina::ejecutarEnfrentamientos() {
    Enfrentamiento enfrentamiento;
    
    for (const auto& par : enfrentamientos) {
        int ganadorIndex = enfrentamiento.simularBatalla(par.first, par.second);
        const Robot& ganador = (ganadorIndex == 0) ? par.first : par.second;
        
        std::string resultado = "🏆 " + par.first.getNombre() + " vs " + par.second.getNombre() + 
                               " → GANADOR: " + ganador.getNombre();
        resultados.push_back(resultado);
        std::cout << resultado << std::endl;
    }
}

std::string Disciplina::getTipo() const {
    return tipo;
}

const std::vector<Robot>& Disciplina::getRobots() const {
    return robots;
}

const std::vector<std::pair<Robot, Robot>>& Disciplina::getEnfrentamientos() const {
    return enfrentamientos;
}

const std::vector<std::string>& Disciplina::getResultados() const {
    return resultados;
}

void Disciplina::mostrarResumen() const {
    std::cout << "\n  Disciplina: " << tipo << " (" << robots.size() << " robots)" << std::endl;
    for (const auto& robot : robots) {
        std::cout << "    - " << robot.getNombre() << std::endl;
    }
}