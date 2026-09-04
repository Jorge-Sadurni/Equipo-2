#include <iostream>
#include <string>
#include <vector>
#include "Robot.h"
#include "Integrante.h"
#include "Equipo.h"
#include "Competencia.h"
#include "Enfrentamiento.h"

using namespace std;

// ---------------------------------------------------------------------
// Tema 6: captura de un Equipo completo por consola
// Flujo: nombre del equipo -> numero de integrantes -> cada integrante
//        -> numero de robots -> cada robot
// ---------------------------------------------------------------------
Equipo capturarEquipo()
{
    string nombreEquipo;
    cout << "Nombre del equipo: ";
    getline(cin, nombreEquipo);

    Equipo equipo(nombreEquipo);

    int numIntegrantes = 0;
    cout << "Numero de integrantes: ";
    cin >> numIntegrantes;
    cin.ignore(); // limpiar el salto de linea pendiente antes de usar getline

    for (int i = 0; i < numIntegrantes; ++i)
    {
        string nombre, rol;
        cout << "  Integrante " << (i + 1) << " - nombre: ";
        getline(cin, nombre);
        cout << "  Integrante " << (i + 1) << " - rol (Analista/Programador/Tester/...): ";
        getline(cin, rol);
        equipo.agregarIntegrante(Integrante(nombre, rol));
    }

    int numRobots = 0;
    cout << "Numero de robots: ";
    cin >> numRobots;
    cin.ignore();

    for (int i = 0; i < numRobots; ++i)
    {
        string nombre, tipo;
        cout << "  Robot " << (i + 1) << " - nombre: ";
        getline(cin, nombre);
        cout << "  Robot " << (i + 1) << " - tipo (Sumo/Seguidor de linea/Combate/...): ";
        getline(cin, tipo);
        equipo.agregarRobot(Robot(nombre, tipo));
    }

    return equipo;
}

// ---------------------------------------------------------------------
// Tema 5: datos de ejemplo para practicar vector<Robot> y filtrado
// ---------------------------------------------------------------------
vector<Robot> robotsDeEjemplo()
{
    return {
        Robot("Titan", "Sumo"),
        Robot("Rayo", "Seguidor de linea"),
        Robot("Coloso", "Sumo"),
        Robot("Vortex", "Combate"),
        Robot("Centella", "Seguidor de linea")};
}

int main()
{
    Competencia competencia;
    Enfrentamiento enfrentamiento;

    cout << "=== Demo POO - Parcial 1: Sistema de gestion de competencia de robotica ===\n";
    cout << "(Este programa cubre: captura por consola, vector<Robot>, filtrado y batalla aleatoria)\n";

    // --- Tema 5: cargar y filtrar por tipo ---
    vector<Robot> robots = robotsDeEjemplo();
    cout << "\n--- Robots de ejemplo cargados (" << robots.size() << ") ---\n";
    for (const auto &r : robots)
    {
        cout << "  " << r.getNombre() << " [" << r.getTipo() << "]\n";
    }

    string tipoBuscado = "Sumo";
    vector<Robot> filtrados = competencia.filtrarPorTipo(robots, tipoBuscado);
    cout << "\n--- Robots filtrados por tipo '" << tipoBuscado << "' (" << filtrados.size() << ") ---\n";
    for (const auto &r : filtrados)
    {
        cout << "  " << r.getNombre() << "\n";
    }

    // --- Tema 7: simular una batalla aleatoria entre los robots de ejemplo ---
    cout << "\n--- Simulacion de batalla (2 robots al azar, ganador al azar) ---\n";
    int idxGanador = enfrentamiento.simularBatalla(filtrados);
    cout << "Robot ganador: " << filtrados[idxGanador].getNombre()
         << " [" << filtrados[idxGanador].getTipo() << "]\n";

    // --- Tema 6 y 9: captura de los equipos ---
    cout << "\n=== SOLO HOY: INSCRIPCION DE ROBOTS ===\n";

    int cantidadEquipos = 0;
    cout << "Cuantos equipos quieren registrarse? ";
    cin >> cantidadEquipos;
    cin.ignore();

    for (int i = 0; i < cantidadEquipos; ++i)
    {
        cout << "\n--- Registro del equipo " << (i + 1) << " ---\n";
        Equipo equipo = capturarEquipo();
        equipo.mostrarResumen();

        if (equipo.getRobots().size() >= 2)
        {
            int idx = enfrentamiento.simularBatalla(equipo.getRobots());
            cout << "\nGanador de la batalla de ejemplo: "
                 << equipo.getRobots()[idx].getNombre() << "\n";
        }
        else
        {
            cout << "\nSe necesitan al menos 2 robots en el equipo para simular una batalla.\n";
        }
    }

    return 0;
}
