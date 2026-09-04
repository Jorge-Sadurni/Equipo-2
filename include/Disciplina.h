#pragma once
#include <string>
#include <vector>
#include "Robot.h"

// Clase Disciplina: agrupa robots del mismo tipo y gestiona enfrentamientos
class Disciplina {
private:
    std::string tipo;
    std::vector<Robot> robots;
    std::vector<std::pair<Robot, Robot>> enfrentamientos;
    std::vector<std::string> resultados;

public:
    explicit Disciplina(const std::string& tipo);
    
    // Gestión de robots
    void inscribirRobot(const Robot& robot);
    bool tieneRobots() const;
    int cantidadRobots() const;
    
    // Generación de enfrentamientos
    void generarEnfrentamientos();
    void ejecutarEnfrentamientos();
    
    // Reportes
    std::string getTipo() const;
    const std::vector<Robot>& getRobots() const;
    const std::vector<std::pair<Robot, Robot>>& getEnfrentamientos() const;
    const std::vector<std::string>& getResultados() const;
    
    // Mostrar información
    void mostrarResumen() const;
};
