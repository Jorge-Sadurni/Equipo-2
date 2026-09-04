#pragma once
#include <vector>
#include "Robot.h"

class Enfrentamiento {
public:
    // Simula una batalla entre dos robots, retorna índice del ganador (0 o 1)
    int simularBatalla(const Robot& robot1, const Robot& robot2) const;
    
    // Versión con vector (mantiene compatibilidad)
    int simularBatalla(const std::vector<Robot>& robots) const;
};