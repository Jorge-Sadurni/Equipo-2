#pragma once
#include <string>
#include <vector>
#include <map>
#include "Equipo.h"
#include "Disciplina.h"
#include "Enfrentamiento.h"

enum class EstadoCompetencia {
    REGISTRO_ABIERTO,
    REGISTRO_CERRADO,
    EN_COMPETENCIA,
    FINALIZADA
};

class Competencia {
private:
    std::string nombre;
    std::vector<Equipo> equipos;
    std::map<std::string, Disciplina> disciplinas;
    EstadoCompetencia estado;
    Enfrentamiento enfrentamiento;

public:
    explicit Competencia(const std::string& nombre);
    
    // Gestión de equipos
    void registrarEquipo(const Equipo& equipo);
    void cerrarRegistro();
    
    // Estado
    EstadoCompetencia getEstado() const;
    std::string getEstadoString() const;
    
    // Reportes
    void generarReporte() const;
    
private:
    void inicializarDisciplinas();
    void inscribirRobotsAutomaticamente(const Equipo& equipo);
    void generarYEjecutarEnfrentamientos();
    void mostrarSeparador() const;
};