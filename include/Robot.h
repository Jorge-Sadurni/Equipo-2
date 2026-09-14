#pragma once
#include <string>

using namespace std;


class Robot
{
private:
    string nombre;
    string tipo; 

public:
    
    Robot(const string &nombre, const string &tipo);

    
    string getNombre() const;
    string getTipo() const;

    void setNombre(const string &nuevoNombre);
    void setTipo(const string &nuevoTipo);
};
