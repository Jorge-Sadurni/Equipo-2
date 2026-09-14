#pragma once
#include <string>
#include <vector>
#include "Integrante.h"
#include "Robot.h"

class Equipo
{
private:
    std::string nombreEquipo;
    std::vector<Integrante> integrantes;
    std::vector<Robot> robots;

public:
    explicit Equipo(const std::string& nombreEquipo);

    void agregarIntegrante(const Integrante& integrante);
    void agregarRobot(const Robot& robot);

    std::string getNombreEquipo() const;
    const std::vector<Integrante>& getIntegrantes() const;
    const std::vector<Robot>& getRobots() const;

    // Imprime un resumen legible del equipo (nombre, integrantes, robots)
    void mostrarResumen() const;
};
