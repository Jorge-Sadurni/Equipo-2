#include "Competencia.h"
#include <iostream>
#include <stdexcept>

Competencia::Competencia(const std::string& nombre) 
    : nombre(nombre), estado(EstadoCompetencia::REGISTRO_ABIERTO) {
    inicializarDisciplinas();
}

void Competencia::inicializarDisciplinas() {
    // Tipos de robot sugeridos (puedes ampliarlos)
    std::vector<std::string> tipos = {"Sumo", "Seguidor de linea", "Laberinto", "Velocista"};
    for (const auto& tipo : tipos) {
        disciplinas.emplace(tipo, Disciplina(tipo));
    }
}

void Competencia::registrarEquipo(const Equipo& equipo) {
    if (estado != EstadoCompetencia::REGISTRO_ABIERTO) {
        throw std::runtime_error("El registro está cerrado");
    }
    
    equipos.push_back(equipo);
    inscribirRobotsAutomaticamente(equipo);
    std::cout << "✓ Equipo " << equipo.getNombreEquipo() << " registrado" << std::endl;
}

void Competencia::inscribirRobotsAutomaticamente(const Equipo& equipo) {
    for (const auto& robot : equipo.getRobots()) {
        auto it = disciplinas.find(robot.getTipo());
        if (it != disciplinas.end()) {
            it->second.inscribirRobot(robot);
        } else {
            std::cout << "Tipo de robot no válido: " << robot.getTipo() 
                      << " (Robot " << robot.getNombre() << ")" << std::endl;
        }
    }
}

void Competencia::cerrarRegistro() {
    if (estado != EstadoCompetencia::REGISTRO_ABIERTO) {
        throw std::runtime_error("El registro ya está cerrado");
    }
    
    estado = EstadoCompetencia::REGISTRO_CERRADO;
    std::cout << "\nRegistro cerrado. Iniciando fase de competencia..." << std::endl;
    generarYEjecutarEnfrentamientos();
}

void Competencia::generarYEjecutarEnfrentamientos() {
    estado = EstadoCompetencia::EN_COMPETENCIA;
    
    std::cout << "\nGENERANDO ENFRENTAMIENTOS..." << std::endl;
    
    for (auto& pair : disciplinas) {
        pair.second.generarEnfrentamientos();
    }
    
    std::cout << "\nEJECUTANDO BATALLAS..." << std::endl;
    for (auto& pair : disciplinas) {
        pair.second.ejecutarEnfrentamientos();
    }
    
    estado = EstadoCompetencia::FINALIZADA;
}

EstadoCompetencia Competencia::getEstado() const {
    return estado;
}

std::string Competencia::getEstadoString() const {
    switch(estado) {
        case EstadoCompetencia::REGISTRO_ABIERTO: return "REGISTRO_ABIERTO";
        case EstadoCompetencia::REGISTRO_CERRADO: return "REGISTRO_CERRADO";
        case EstadoCompetencia::EN_COMPETENCIA: return "EN_COMPETENCIA";
        case EstadoCompetencia::FINALIZADA: return "FINALIZADA";
        default: return "DESCONOCIDO";
    }
}

void Competencia::generarReporte() const {
    std::cout << "\n";
    mostrarSeparador();
    std::cout << "REPORTE FINAL - " << nombre << std::endl;
    mostrarSeparador();
    
    // Equipos participantes
    std::cout << "\nEQUIPOS PARTICIPANTES:" << std::endl;
    for (const auto& equipo : equipos) {
        equipo.mostrarResumen();
    }
    
    // Resultados por disciplina
    std::cout << "\nRESULTADOS DE BATALLAS:" << std::endl;
    bool hayResultados = false;
    for (const auto& pair : disciplinas) {
        const auto& resultados = pair.second.getResultados();
        if (!resultados.empty()) {
            hayResultados = true;
            std::cout << "\n  Disciplina: " << pair.first << std::endl;
            for (const auto& resultado : resultados) {
                std::cout << "    " << resultado << std::endl;
            }
        }
    }
    
    if (!hayResultados) {
        std::cout << "  No se realizaron batallas" << std::endl;
    }
    
    mostrarSeparador();
}

void Competencia::mostrarSeparador() const {
    std::cout << std::string(60, '=') << std::endl;
}