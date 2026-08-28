#include "Integrante.h"

Integrante::Integrante(const std::string& nombre, const std::string& rol)
    : nombre(nombre), rol(rol) {}

std::string Integrante::getNombre() const {
    return nombre;
}

std::string Integrante::getRol() const {
    return rol;
}

void Integrante::setNombre(const std::string& nuevoNombre) {
    if (!nuevoNombre.empty()) {
        nombre = nuevoNombre;
    }
}

void Integrante::setRol(const std::string& nuevoRol) {
    if (!nuevoRol.empty()) {
        rol = nuevoRol;
    }
}
