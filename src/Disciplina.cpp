#include "Disciplina.h"
#include <iostream>

Disciplina::Disciplina(const std::string& tipo)
    : tipo(tipo) {}

void Disciplina::inscribirRobot(const Robot& robot) {
    if (robot.getTipo() == tipo) {
        robots.push_back(robot);
    }
}

bool Disciplina::tieneRobots() const {
    return !robots.empty();
}

int Disciplina::cantidadRobots() const {
    return static_cast<int>(robots.size());
}

void Disciplina::generarEnfrentamientos() {
    enfrentamientos.clear();
    resultados.clear();

    for (std::size_t indice = 0; indice + 1 < robots.size(); indice += 2) {
        enfrentamientos.emplace_back(robots[indice], robots[indice + 1]);
    }
}

void Disciplina::ejecutarEnfrentamientos() {
    resultados.clear();

    for (const auto& enfrentamiento : enfrentamientos) {
        resultados.push_back(
            enfrentamiento.first.getNombre() + " vs " +
            enfrentamiento.second.getNombre());
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
    std::cout << "Disciplina: " << tipo << "\n"
              << "Robots inscritos: " << robots.size() << "\n"
              << "Enfrentamientos: " << enfrentamientos.size() << "\n";
}
