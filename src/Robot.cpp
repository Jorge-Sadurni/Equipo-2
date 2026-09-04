#include "Robot.h"

using namespace std;

// Lista de inicializacion: se inicializan los atributos directamente,
// en lugar de asignarlos en el cuerpo del constructor.
Robot::Robot(const string &nombre, const string &tipo)
    : nombre(nombre), tipo(tipo) {}

string Robot::getNombre() const
{
    return nombre;
}

string Robot::getTipo() const
{
    return tipo;
}

void Robot::setNombre(const string &nuevoNombre)
{
    if (!nuevoNombre.empty())
    {
        nombre = nuevoNombre;
    }
}

void Robot::setTipo(const string &nuevoTipo)
{
    if (!nuevoTipo.empty())
    {
        tipo = nuevoTipo;
    }
}
