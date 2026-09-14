#pragma once
#include <string>

using namespace std;


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
