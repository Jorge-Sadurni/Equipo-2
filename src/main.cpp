#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Competencia.h"
#include "Equipo.h"
#include "Integrante.h"
#include "Robot.h"

int main() {
    // Inicializar semilla para números aleatorios
    srand(static_cast<unsigned int>(time(nullptr)));
    
    try {
        // Crear competencia
        Competencia competencia("Competencia de Robótica 2026");
        
        std::cout << "🤖 BIENVENIDO AL SISTEMA DE GESTIÓN DE COMPETENCIA DE ROBÓTICA" << std::endl;
        std::cout << "Estado inicial: " << competencia.getEstadoString() << std::endl;
        
        // === CREAR EQUIPO 1 ===
        Equipo equipo1("RoboTitans");
        equipo1.agregarIntegrante(Integrante("Ana García", "Programador"));
        equipo1.agregarIntegrante(Integrante("Carlos Ruiz", "Mecánico"));
        
        equipo1.agregarRobot(Robot("Titan-1", "Sumo"));
        equipo1.agregarRobot(Robot("Titan-2", "Seguidor de linea"));
        equipo1.agregarRobot(Robot("Titan-3", "Laberinto"));
        
        // === CREAR EQUIPO 2 ===
        Equipo equipo2("MechWarriors");
        equipo2.agregarIntegrante(Integrante("María López", "Analista"));
        equipo2.agregarIntegrante(Integrante("Juan Pérez", "Programador"));
        equipo2.agregarIntegrante(Integrante("Laura Torres", "Diseñador"));
        
        equipo2.agregarRobot(Robot("Warrior-1", "Sumo"));
        equipo2.agregarRobot(Robot("Warrior-2", "Velocista"));
        equipo2.agregarRobot(Robot("Warrior-3", "Seguidor de linea"));
        
        // === CREAR EQUIPO 3 ===
        Equipo equipo3("CircuitBreakers");
        equipo3.agregarIntegrante(Integrante("Pedro Sánchez", "Tester"));
        equipo3.agregarIntegrante(Integrante("Sofia Martínez", "Programador"));
        
        equipo3.agregarRobot(Robot("Breaker-1", "Sumo"));
        equipo3.agregarRobot(Robot("Breaker-2", "Laberinto"));
        
        // === REGISTRAR EQUIPOS ===
        std::cout << "\n📝 Registrando equipos..." << std::endl;
        competencia.registrarEquipo(equipo1);
        competencia.registrarEquipo(equipo2);
        competencia.registrarEquipo(equipo3);
        
        // === CERRAR REGISTRO Y COMENZAR COMPETENCIA ===
        competencia.cerrarRegistro();
        
        // === GENERAR REPORTE FINAL ===
        competencia.generarReporte();
        
        std::cout << "\n✅ Competencia finalizada exitosamente!" << std::endl;
        
    } catch (const std::exception& e) {
        std::cerr << "❌ Error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}