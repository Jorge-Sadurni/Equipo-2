#pragma once
#include <string>
#include <vector>
#include "Integrante.h"
#include "Robot.h"

using namespace std;


class Equipo
{
private:
    string nombreEquipo;
    vector<Integrante> integrantes;
    vector<Robot> robots;

public:
    explicit Equipo(const string &nombreEquipo);

    void agregarIntegrante(const Integrante &i);
    void agregarRobot(const Robot &r);

    string getNombreEquipo() const;
    const vector<Integrante> &getIntegrantes() const;
    const vector<Robot> &getRobots() const;

    // Imprime un resumen legible del equipo (nombre, integrantes, robots)
    void mostrarResumen() const;
};
