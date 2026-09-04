#include "Competencia.h"

using namespace std;

vector<Robot> Competencia::filtrarPorTipo(const vector<Robot> &robots,
                                          const string &tipo) const
{
    vector<Robot> resultado;
    for (const auto &robot : robots)
    {
        if (robot.getTipo() == tipo)
        {
            resultado.push_back(robot);
        }
    }
    return resultado;
}