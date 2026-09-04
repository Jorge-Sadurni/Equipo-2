#include "Equipo.h"
#include <iostream>

Equipo::Equipo(const std::string& nombreEquipo) : nombreEquipo(nombreEquipo) {}

void Equipo::agregarIntegrante(const Integrante& i) {
    if (integrantes.size() >= 3) {
        throw std::runtime_error("El equipo ya tiene el número máximo de integrantes (3)");
    }
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
    std::cout << "\n  Equipo: " << nombreEquipo 
              << " (" << integrantes.size() << " integrantes, " 
              << robots.size() << " robots)" << std::endl;
    
    std::cout << "  Integrantes:" << std::endl;
    for (const auto& integrante : integrantes) {
        std::cout << "    - " << integrante.getNombre() 
                  << " (Carrera: " << integrante.getRol() << ")" << std::endl;
    }
    
    std::cout << "  Robots:" << std::endl;
    for (const auto& robot : robots) {
        std::cout << "    - " << robot.getNombre() 
                  << " (" << robot.getTipo() << ")" << std::endl;
    }
}