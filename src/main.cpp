#include <algorithm>
#include <cctype>
#include <iostream>
#include <limits>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
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

    std::string resultado = texto.substr(inicio, fin - inicio);
    std::transform(resultado.begin(), resultado.end(), resultado.begin(), [](unsigned char c) {
        return static_cast<char>(std::toupper(c));
    });
    return resultado;
}

static std::string normalizarTipoRobot(const std::string& tipo) {
    std::string copia = normalizarTexto(tipo);

    if (copia == "SUMO") return "SUMO";
    if (copia == "SEGUIDOR DE LINEA") return "SEGUIDOR DE LINEA";
    if (copia == "VELOCISTA") return "VELOCISTA";
    return "";
}

static std::vector<std::string> tiposValidosRobot() {
    return {"SUMO", "SEGUIDOR DE LINEA", "VELOCISTA"};
}

int leerCantidad(const std::string& mensaje, int minimo, int maximo = 0) {
    while (true) {
        std::cout << mensaje;

        std::string entrada;
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
        } else {
            std::cout << " mayor o igual a " << minimo;
        }
        std::cout << ".\n";
    }
}

std::string leerTexto(const std::string& mensaje) {
    while (true) {
        std::cout << mensaje;

        std::string texto;
        if (!std::getline(std::cin, texto)) {
            throw std::runtime_error("No se pudo leer la entrada.");
        }

        texto = normalizarTexto(texto);
        if (!texto.empty()) {
            return texto;
        }

        std::cout << "La respuesta no puede estar vacia ni estar formada solo por espacios.\n";
    }
}

std::string leerNombreUnico(const std::string& mensaje, std::set<std::string>& nombresUsados) {
    while (true) {
        std::string nombre = leerTexto(mensaje);
        if (nombresUsados.insert(nombre).second) {
            return nombre;
        }

        std::cout << "Ese nombre ya existe. Ingresa un nombre diferente.\n";
    }
}

std::string leerCarrera(const std::string& mensaje) {
    const std::vector<std::string> carreras = {
        "INGENIERIA MECATRONICA",
        "INGENIERIA INDUSTRIAL",
        "INGENIERIA AMBIENTAL"
    };

    while (true) {
        std::string carrera = leerTexto(mensaje + " (" + carreras[0] + ", " + carreras[1] + ", " + carreras[2] + "): ");
        if (std::find(carreras.begin(), carreras.end(), carrera) != carreras.end()) {
            return carrera;
        }

        std::cout << "Carrera invalida. Solo se permiten: " << carreras[0] << ", "
                  << carreras[1] << " y " << carreras[2] << ".\n";
    }
}

std::string leerTipoRobot(const std::string& mensaje) {
    const std::vector<std::string> tipos = tiposValidosRobot();

    while (true) {
        std::string entrada = leerTexto(mensaje + " (" + tipos[0] + ", " + tipos[1] + ", " + tipos[2] + "): ");
        std::string tipoNormalizado = normalizarTipoRobot(entrada);

        if (!tipoNormalizado.empty()) {
            return tipoNormalizado;
        }

        std::cout << "Tipo de robot invalido. Opciones validas: ";
        for (size_t i = 0; i < tipos.size(); ++i) {
            if (i > 0) std::cout << ", ";
            std::cout << tipos[i];
        }
        std::cout << ".\n";
    }
}

Equipo capturarEquipo(int numeroEquipo, std::set<std::string>& nombresUsados) {
    std::cout << "\n--- Equipo " << numeroEquipo << " ---\n";
    Equipo equipo(leerNombreUnico("Nombre del equipo: ", nombresUsados));

    int cantidadIntegrantes = leerCantidad("Cantidad de integrantes (1-3): ", 1, 3);
    for (int i = 1; i <= cantidadIntegrantes; ++i) {
        std::cout << "\nIntegrante " << i << "\n";
        std::string nombre = leerNombreUnico("Nombre: ", nombresUsados);
        std::string carrera = leerCarrera("Carrera");
        equipo.agregarIntegrante(Integrante(nombre, carrera));
    }

    int cantidadRobots = leerCantidad("Cuantos robots desea registrar en este equipo (1-2): ", 1, 2);
    for (int i = 1; i <= cantidadRobots; ++i) {
        std::cout << "\nRobot " << i << "\n";
        std::string nombre = leerNombreUnico("Nombre del robot: ", nombresUsados);
        std::string tipo = leerTipoRobot("Tipo de robot");
        equipo.agregarRobot(Robot(nombre, tipo));
    }

    return equipo;
}

int main() {
    try {
        Competencia competencia("COMPETENCIA DE ROBOTICA 2026");

        std::cout << "BIENVENIDO AL SISTEMA DE GESTION DE COMPETENCIA DE ROBOTICA" << std::endl;
        std::cout << "Estado inicial: " << competencia.getEstadoString() << std::endl;

        std::set<std::string> nombresUsados;
        int cantidadEquipos = leerCantidad("Cantidad de equipos (1-10): ", 1, 10);
        for (int i = 1; i <= cantidadEquipos; ++i) {
            competencia.registrarEquipo(capturarEquipo(i, nombresUsados));
        }

        competencia.cerrarRegistro();
        competencia.generarReporte();

        std::cout << "\nCompetencia finalizada exitosamente!" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        std::cout << "\nPresiona Enter para salir...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();
        return 1;
    }

    std::cout << "\nPresiona Enter para salir...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
    return 0;
}