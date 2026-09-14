#include "Integrante.h"

Integrante::Integrante(const std::string& nombre, const std::string& carrera)
    : nombre(nombre), carrera(carrera) {}

std::string Integrante::getNombre() const {
    return nombre;
}

std::string Integrante::getCarrera() const {
    return carrera;
}

void Integrante::setNombre(const std::string& nuevoNombre) {
    if (!nuevoNombre.empty()) {
        nombre = nuevoNombre;
    }
}

void Integrante::setCarrera(const std::string& nuevaCarrera) {
    if (!nuevaCarrera.empty()) {
        carrera = nuevaCarrera;
    }
}