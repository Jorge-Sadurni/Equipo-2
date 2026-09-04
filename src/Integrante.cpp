#include "Integrante.h"

using namespace std;

Integrante::Integrante(const string &nombre, const string &rol)
    : nombre(nombre), rol(rol) {}

string Integrante::getNombre() const
{
    return nombre;
}

string Integrante::getRol() const
{
    return rol;
}

void Integrante::setNombre(const string &nuevoNombre)
{
    if (!nuevoNombre.empty())
    {
        nombre = nuevoNombre;
    }
}

void Integrante::setRol(const string &nuevoRol)
{
    if (!nuevoRol.empty())
    {
        rol = nuevoRol;
    }
}
