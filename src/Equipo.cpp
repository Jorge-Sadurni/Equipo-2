#include "Equipo.h"
#include <iostream>

using namespace std;

Equipo::Equipo(const string &nombreEquipo)
    : nombreEquipo(nombreEquipo) {}

void Equipo::agregarIntegrante(const Integrante &i)
{
    integrantes.push_back(i);
}

void Equipo::agregarRobot(const Robot &r)
{
    robots.push_back(r);
}

string Equipo::getNombreEquipo() const
{
    return nombreEquipo;
}

const vector<Integrante> &Equipo::getIntegrantes() const
{
    return integrantes;
}

const vector<Robot> &Equipo::getRobots() const
{
    return robots;
}

void Equipo::mostrarResumen() const
{
    cout << "\n=== Equipo: " << nombreEquipo << " ===\n";

    cout << "Integrantes (" << integrantes.size() << "):\n";
    for (const auto &i : integrantes)
    {
        cout << "  - " << i.getNombre() << " (" << i.getRol() << ")\n";
    }

    cout << "Robots (" << robots.size() << "):\n";
    for (const auto &r : robots)
    {
        cout << "  - " << r.getNombre() << " [" << r.getTipo() << "]\n";
    }
}
