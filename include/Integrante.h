#pragma once
#include <string>

// Clase Integrante: representa a un miembro del equipo.
// Nota de clase: "rol" es un string libre en esta sesion (no enum),
// se mantiene simple a proposito para enfocarnos en composicion y vectores.
class Integrante {
private:
    std::string nombre;
    std::string rol; // Ej: "Analista", "Programador", "Tester"

public:
    Integrante(const std::string& nombre, const std::string& rol);

    std::string getNombre() const;
    std::string getRol() const;

    void setNombre(const std::string& nuevoNombre);
    void setRol(const std::string& nuevoRol);
};
