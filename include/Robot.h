#pragma once
#include <string>

using namespace std;

// Clase Robot: representa un robot participante en la competencia.
// Atributos privados + acceso controlado (encapsulamiento).
class Robot
{
private:
    string nombre;
    string tipo; // Ej: "Sumo", "Seguidor de linea", "Combate"

public:
    // Constructor con lista de inicializacion
    Robot(const string &nombre, const string &tipo);

    // Getters
    string getNombre() const;
    string getTipo() const;

    // Setters (con validacion basica)
    void setNombre(const string &nuevoNombre);
    void setTipo(const string &nuevoTipo);
};
