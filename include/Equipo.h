#pragma once
#include <string>
#include <vector>
#include "Integrante.h"
#include "Robot.h"

// Clase Equipo: HAS-A Integrante(s), HAS-A Robot(s).
// Composicion practicada directamente porque es una pieza que
// casi con certeza los equipos van a necesitar en su proyecto.
class Equipo {
private:
    std::string nombreEquipo;
    std::vector<Integrante> integrantes;
    std::vector<Robot> robots;

public:
    explicit Equipo(const std::string& nombreEquipo);

    void agregarIntegrante(const Integrante& i);
    void agregarRobot(const Robot& r);

    std::string getNombreEquipo() const;
    const std::vector<Integrante>& getIntegrantes() const;
    const std::vector<Robot>& getRobots() const;

    // Imprime un resumen legible del equipo (nombre, integrantes, robots)
    void mostrarResumen() const;
};
