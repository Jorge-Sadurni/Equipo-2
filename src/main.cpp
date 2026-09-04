#include <iostream>
#include <limits>
#include <string>
#include "Competencia.h"
#include "Equipo.h"
#include "Integrante.h"
#include "Robot.h"

int leerCantidad(const std::string& mensaje, int minimo, int maximo = 0) {
    int cantidad;
    while (true) {
        std::cout << mensaje;
        if (std::cin >> cantidad && cantidad >= minimo && (maximo == 0 || cantidad <= maximo)) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return cantidad;
        }

        std::cout << "Ingresa un numero valido";
        if (maximo != 0) {
            std::cout << " entre " << minimo << " y " << maximo;
        } else {
            std::cout << " mayor o igual a " << minimo;
        }
        std::cout << ".\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

std::string leerTexto(const std::string& mensaje) {
    std::string texto;
    do {
        std::cout << mensaje;
        std::getline(std::cin, texto);
        if (texto.empty()) {
            std::cout << "La respuesta no puede estar vacia.\n";
        }
    } while (texto.empty());
    return texto;
}

Equipo capturarEquipo(int numeroEquipo) {
    std::cout << "\n--- Equipo " << numeroEquipo << " ---\n";
    Equipo equipo(leerTexto("Nombre del equipo: "));

    int cantidadIntegrantes = leerCantidad("Cantidad de integrantes (1-3): ", 1, 3);
    for (int i = 1; i <= cantidadIntegrantes; ++i) {
        std::cout << "\nIntegrante " << i << "\n";
        std::string nombre = leerTexto("Nombre: ");
        std::string carrera = leerTexto("Carrera (rol): ");
        equipo.agregarIntegrante(Integrante(nombre, carrera));
    }

    int cantidadRobots = leerCantidad("Cuantos robots desea registrar en este equipo: ", 1);
    for (int i = 1; i <= cantidadRobots; ++i) {
        std::cout << "\nRobot " << i << "\n";
        std::string nombre = leerTexto("Nombre del robot: ");
        std::string tipo = leerTexto("Tipo de robot (Sumo, Seguidor de linea, Laberinto o Velocista): ");
        equipo.agregarRobot(Robot(nombre, tipo));
    }

    return equipo;
}

int main() {
    try {
        Competencia competencia("Competencia de Robótica 2026");
        
        std::cout << "BIENVENIDO AL SISTEMA DE GESTION DE COMPETENCIA DE ROBOTICA" << std::endl;
        std::cout << "Estado inicial: " << competencia.getEstadoString() << std::endl;

        int cantidadEquipos = leerCantidad("Cantidad de equipos: ", 1);
        for (int i = 1; i <= cantidadEquipos; ++i) {
            competencia.registrarEquipo(capturarEquipo(i));
        }

        competencia.cerrarRegistro();
        competencia.generarReporte();

        std::cout << "\nCompetencia finalizada exitosamente!" << std::endl;
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}