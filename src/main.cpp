#include <cctype>
#include <iostream>
#include <limits>
#include <sstream>
#include <stdexcept>
#include <string>
#include "Competencia.h"
#include "Equipo.h"
#include "Integrante.h"
#include "Robot.h"

static std::string normalizarTexto(const std::string& texto) {
    size_t inicio = 0;
    size_t fin = texto.size();

    while (inicio < fin && std::isspace(static_cast<unsigned char>(texto[inicio]))) {
        ++inicio;
    }

    while (fin > inicio && std::isspace(static_cast<unsigned char>(texto[fin - 1]))) {
        --fin;
    }

    return texto.substr(inicio, fin - inicio);
}

int leerCantidad(const std::string& mensaje, int minimo, int maximo = 0) {
    while (true) {
        std::string entrada;
        std::cout << mensaje;
        if (!std::getline(std::cin, entrada)) {
            throw std::runtime_error("No se pudo leer la entrada.");
        }

        std::stringstream ss(entrada);
        int cantidad = 0;
        char extra = '\0';

        if (ss >> cantidad && !(ss >> extra) && cantidad >= minimo && (maximo == 0 || cantidad <= maximo)) {
            return cantidad;
        }

        std::cout << "Ingresa un numero entero valido";
        if (maximo != 0) {
            std::cout << " entre " << minimo << " y " << maximo;
        }
    }
}
            std::cout << " entre " << minimo << " y " << maximo;
        }
        else
        {
            std::cout << " mayor o igual a " << minimo;
        }
        std::cout << ".\n";
    }
}

std::string leerTexto(const std::string &mensaje)
{
    std::string texto;
std::string leerTexto(const std::string &mensaje)
{
    std::string texto;

    do
    {
        std::cout << mensaje;
        std::getline(std::cin, texto);

        texto = normalizarTexto(texto);

        if (texto.empty())
        {
            std::cout << "La respuesta no puede estar vacia ni estar formada solo por espacios.\n";
        }
    } while (texto.empty());

    return texto;
}
        }

        std::cout << "La respuesta no puede estar vacia ni estar formada solo por espacios.\n";
    }
}

Equipo capturarEquipo(int numeroEquipo)
{
    std::cout << "\n--- Equipo " << numeroEquipo << " ---\n";
    Equipo equipo(leerTexto("Nombre del equipo: "));

    int cantidadIntegrantes = leerCantidad("Cantidad de integrantes (1-3): ", 1, 3);
    for (int i = 1; i <= cantidadIntegrantes; ++i)
    {
        std::cout << "\nIntegrante " << i << "\n";
        std::string nombre = leerTexto("Nombre: ");
        std::string carrera = leerTexto("Carrera (rol): ");
        equipo.agregarIntegrante(Integrante(nombre, carrera));
    }

    int cantidadRobots = leerCantidad("Cuantos robots desea registrar en este equipo: ", 1);
    for (int i = 1; i <= cantidadRobots; ++i)
    {
        std::cout << "\nRobot " << i << "\n";
        std::string nombre = leerTexto("Nombre del robot: ");
        std::string tipo = leerTexto("Tipo de robot (Sumo, Seguidor de linea, Laberinto o Velocista): ");
        equipo.agregarRobot(Robot(nombre, tipo));
    }

    return equipo;
}

int main()
{
    try
    {
        Competencia competencia("Competencia de Robótica 2026");

        std::cout << "BIENVENIDO AL SISTEMA DE GESTION DE COMPETENCIA DE ROBOTICA" << std::endl;
        std::cout << "Estado inicial: " << competencia.getEstadoString() << std::endl;

        int cantidadEquipos = leerCantidad("Cantidad de equipos: ", 1);
        for (int i = 1; i <= cantidadEquipos; ++i)
        {
            competencia.registrarEquipo(capturarEquipo(i));
        }

        competencia.cerrarRegistro();
        competencia.generarReporte();

        std::cout << "\nCompetencia finalizada exitosamente!" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}