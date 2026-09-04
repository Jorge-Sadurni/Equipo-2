#pragma once
#include <string>

using namespace std;

// Clase Integrante: representa a un miembro del equipo.
// Nota de clase: "rol" es un string libre en esta sesion (no enum),
// se mantiene simple a proposito para enfocarnos en composicion y vectores.
class Integrante
{
private:
    string nombre;
    string rol; // Ej: "Analista", "Programador", "Tester"

public:
    Integrante(const string &nombre, const string &rol);

    string getNombre() const;
    string getRol() const;

    void setNombre(const string &nuevoNombre);
    void setRol(const string &nuevoRol);
};
