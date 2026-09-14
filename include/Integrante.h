#pragma once
#include <string>

class Integrante
{
private:
    std::string nombre;
    std::string carrera;

public:
    Integrante(const std::string& nombre, const std::string& carrera);

    std::string getNombre() const;
    std::string getCarrera() const;

    void setNombre(const std::string& nuevoNombre);
    void setCarrera(const std::string& nuevaCarrera);
};
