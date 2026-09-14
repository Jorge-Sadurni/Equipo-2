#pragma once
#include <string>

using namespace std;


class Integrante
{
private:
    string nombre;
    string carrera;

public:
    Integrante(const string &nombre, const string &carrera);

    string getNombre() const;
    string getCarrera() const;

    void setNombre(const string &nuevoNombre);
    void setCarrera(const string &nuevaCarrera);
};
