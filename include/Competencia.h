#pragma once
#include <string>
#include <vector>
#include "Robot.h"

class Competencia {
public:
    std::vector<Robot> filtrarPorTipo(const std::vector<Robot>& robots,
                                      const std::string& tipo) const;
};