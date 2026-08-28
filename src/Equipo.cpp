#include "Equipo.h"
#include <iostream>

Equipo::Equipo(const std::string& nombreEquipo)
    : nombreEquipo(nombreEquipo) {}

void Equipo::agregarIntegrante(const Integrante& i) {
    integrantes.push_back(i);
}

void Equipo::agregarRobot(const Robot& r) {
    robots.push_back(r);
}

std::string Equipo::getNombreEquipo() const {
    return nombreEquipo;
}

const std::vector<Integrante>& Equipo::getIntegrantes() const {
    return integrantes;
}

const std::vector<Robot>& Equipo::getRobots() const {
    return robots;
}

void Equipo::mostrarResumen() const {
    std::cout << "\n=== Equipo: " << nombreEquipo << " ===\n";

    std::cout << "Integrantes (" << integrantes.size() << "):\n";
    for (const auto& i : integrantes) {
        std::cout << "  - " << i.getNombre() << " (" << i.getRol() << ")\n";
    }

    std::cout << "Robots (" << robots.size() << "):\n";
    for (const auto& r : robots) {
        std::cout << "  - " << r.getNombre() << " [" << r.getTipo() << "]\n";
    }
}
