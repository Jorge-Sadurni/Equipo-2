#pragma once
#include <string>

class Robot
{
private:
    std::string nombre;
    std::string tipo;

public:
    Robot(const std::string& nombre, const std::string& tipo);

    std::string getNombre() const;
    std::string getTipo() const;

    void setNombre(const std::string& nuevoNombre);
    void setTipo(const std::string& nuevoTipo);
};
