#pragma once
#include <string>
#include <vector>
#include "Robot.h"

using namespace std;

class Competencia
{
public:
    vector<Robot> filtrarPorTipo(const vector<Robot> &robots,
                                 const string &tipo) const;
};