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
    
    void inscribirRobot(const Robot& robot);
    void generarEnfrentamientos();
    void ejecutarEnfrentamientos();
    const std::vector<std::string>& getResultados() const;
};
