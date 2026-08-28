#pragma once
#include <string>

// Clase Robot: representa un robot participante en la competencia.
// Atributos privados + acceso controlado (encapsulamiento).
class Robot {
private:
    std::string nombre;
    std::string tipo; // Ej: "Sumo", "Seguidor de linea", "Combate"

public:
    // Constructor con lista de inicializacion
    Robot(const std::string& nombre, const std::string& tipo);

    // Getters
    std::string getNombre() const;
    std::string getTipo() const;

    // Setters (con validacion basica)
    void setNombre(const std::string& nuevoNombre);
    void setTipo(const std::string& nuevoTipo);
};
