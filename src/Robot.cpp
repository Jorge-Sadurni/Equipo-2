#include "Robot.h"

// Lista de inicializacion: se inicializan los atributos directamente,
// en lugar de asignarlos en el cuerpo del constructor.
Robot::Robot(const std::string& nombre, const std::string& tipo)
    : nombre(nombre), tipo(tipo) {}

std::string Robot::getNombre() const {
    return nombre;
}

std::string Robot::getTipo() const {
    return tipo;
}

void Robot::setNombre(const std::string& nuevoNombre) {
    if (!nuevoNombre.empty()) {
        nombre = nuevoNombre;
    }
}

void Robot::setTipo(const std::string& nuevoTipo) {
    if (!nuevoTipo.empty()) {
        tipo = nuevoTipo;
    }
}
