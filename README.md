# Sistema de Gestión de Competencia de Robótica en C++

Proyecto orientado a objetos para gestionar una competencia de robótica, donde se registran equipos, integrantes y robots, se clasifican por disciplina y se generan enfrentamientos automáticos entre robots del mismo tipo.

## Descripción general

Este proyecto modela una competencia en la que:

1. Se crean equipos con nombre, integrantes y robots.
2. Cada robot pertenece a un tipo o disciplina, como `Sumo`, `Seguidor de linea`, `Laberinto` o `Velocista`.
3. La competencia valida el registro, cierra la fase de inscripción y genera enfrentamientos por disciplina.
4. Se ejecutan batallas aleatorias y se presenta un reporte final con los resultados.

El desarrollo está organizado con separación entre interfaz y lógica, usando clases propias para cada entidad del dominio.

### Diagrama de clases

<p align="center">
  <img src="Diagrama de Clases y Atributos (1).png" alt="Diagrama de clases" width="900" />
</p>

## Estructura del proyecto

```text
Equipo-2/
├── include/                         # Declaraciones de clases
│   ├── Competencia.h
│   ├── Disciplina.h
│   ├── Enfrentamiento.h
│   ├── Equipo.h
│   ├── Integrante.h
│   └── Robot.h
├── src/                            # Implementación de las clases
│   ├── Competencia.cpp
│   ├── Disciplina.cpp
│   ├── Enfrentamiento.cpp
│   ├── Equipo.cpp
│   ├── Integrante.cpp
│   ├── Robot.cpp
│   └── main.cpp
├── build/                          # Archivo compilado generado por el proyecto
├── Makefile                        # Compilación y ejecución rápida
├── README.md
└── Diagrama_de_Clases_Atributos.png
```

## Clases principales

- `Robot`: representa a cada robot participante y almacena su nombre y tipo.
- `Integrante`: almacena los datos de cada integrante del equipo.
- `Equipo`: compone a un equipo con varios integrantes y varios robots.
- `Disciplina`: agrupa robots por tipo y organiza sus enfrentamientos.
- `Enfrentamiento`: simula la batalla entre dos robots.
- `Competencia`: administra el estado de la competencia, registra equipos y genera reportes finales.

## Compilar y correr

### Opción recomendada con Makefile

Desde la raíz del proyecto:

```bash
make
make run
```

Esto compila el proyecto y ejecuta el programa generado.

### Compilación manual

```bash
g++ -std=c++11 -Wall -Wextra -Iinclude src/main.cpp src/Competencia.cpp src/Disciplina.cpp src/Enfrentamiento.cpp src/Equipo.cpp src/Integrante.cpp src/Robot.cpp -o competencia_robotica
./competencia_robotica
```

### En Windows

```bash
competencia_robotica.exe
```

## Qué esperar al correrlo

Al ejecutar el programa, la aplicación se comporta de la siguiente manera:

1. Muestra el nombre de la competencia y su estado inicial.
2. Solicita la cantidad de equipos a registrar.
3. Para cada equipo, pide:
   - nombre del equipo
   - cantidad de integrantes (máximo 3)
   - nombre y carrera de cada integrante
   - cantidad de robots a registrar
   - nombre y tipo de cada robot
4. Al terminar la captura, cierra el registro de equipos.
5. La competencia inicializa sus disciplinas y registra automáticamente cada robot según su tipo.
6. Genera enfrentamientos por disciplina y ejecuta las batallas aleatorias.
7. Muestra el reporte final con los equipos participantes y los resultados por disciplina.

En resumen, la aplicación no solo construye la estructura del problema, sino que también ejecuta todo el flujo real de una competencia: inscripción, clasificación, enfrentamientos y reporte final.

## Buenas prácticas aplicadas dentro del código

Se incorporan varios principios de programación orientada a objetos y buenas prácticas de C++:

- Separación de responsabilidades entre archivos `.h` y `.cpp`.
- Uso de `#pragma once` para evitar múltiples inclusiones de cabeceras.
- Encapsulamiento con atributos privados y acceso controlado por getters/setters.
- Constructores con listas de inicialización.
- Parámetros por referencia constante (`const std::string&`) para evitar copias innecesarias.
- Uso de `const` en métodos que no modifican el estado del objeto.
- Validaciones básicas en setters y en la lógica de registro, por ejemplo, evitando equipos con demasiados integrantes o tipos inválidos.
- Uso de `std::vector` para manejar colecciones dinámicas de equipos, integrantes y robots.
- Organización modular del comportamiento: cada clase tiene una responsabilidad clara dentro del sistema.
- Uso de `std::random` para simular resultados de manera más realista que un simple `rand()`.
- Manejo de errores con `std::runtime_error` y `std::invalid_argument` para avisar cuando una operación no es válida.

## Observaciones

- El proyecto está pensado para un ejercicio académico de POO y programación con C++.
- La lógica de competencia es didáctica, pero sigue una estructura clara que puede ampliarse para nuevas disciplinas, métricas o tipos de robot.
- El flujo interactivo de consola está diseñado para que el usuario pueda registrar equipos reales y observar el resultado de la competencia en tiempo de ejecución.

## Errores detectados

- La validación de entradas numéricas no es robusta: valores como `1.5`, `.5`, `-3` o texto no numérico pueden romper el flujo del programa.
- El buffer de entrada no se maneja de forma consistente, por lo que los datos sobrantes pueden contaminar los siguientes prompts.
- La captura de nombres y texto no valida formato ni contenido útil, lo que puede generar registros inconsistentes.
- El registro de equipos puede quedar desalineado si una entrada inválida se introduce en medio del proceso.

