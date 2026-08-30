# Demo POO en C++ — Práctica orientada al Parcial 1 (Sistema de gestión de competencia de robótica)

Proyecto de práctica en clase (sesión de viernes) para POO — Mecatrónica, 3er semestre, La Salle Saltillo.

Cubre, con clases y funciones directamente asociadas al proyecto del Parcial 1:

1. Clase `Robot` — sintaxis básica, separación `.h`/`.cpp`, include guards (`#pragma once`)
2. Constructores de `Robot` e `Integrante` con lista de inicialización
3. Getters/setters de `Robot`
4. Composición: `Equipo` contiene `vector<Integrante>` y `vector<Robot>`
5. `std::vector`: carga de robots de ejemplo y filtrado por tipo
6. Entrada/salida: captura de un `Equipo` completo por consola
7. `<random>`: selección aleatoria de dos robots y ganador de una batalla
8. Buenas prácticas: `const` correctness, paso por referencia constante, organización de archivos
9. Mini-reto integrador (comentado en `main.cpp`, listo para descomentar en clase)

> **Nota importante:** este código es material de práctica, **no** la solución del Parcial 1.
> Faltan las clases y la lógica que cada equipo debe identificar y construir por su cuenta
> (por ejemplo: `Competencia`, `Disciplinas`, manejo de robot sin rival, etc.).


### Diagrama de clases

<p align="center">
  <img src="./uml_digrama_clases.png" alt="Diagrama de clases" width="900" />
</p>


## Estructura

```
poo_parcial1_demo/
├── include/          # Archivos .h (declaraciones / interfaz)
│   ├── Robot.h
│   ├── Integrante.h
│   ├── Equipo.h
│   └── UtilRobots.h
├── src/              # Archivos .cpp (implementación)
│   ├── Robot.cpp
│   ├── Integrante.cpp
│   ├── Equipo.cpp
│   ├── UtilRobots.cpp
│   └── main.cpp
├── Makefile
└── README.md
```

## Compilar y correr

### Windows / macOS / Linux (con `g++` en el PATH)

```bash
make run
```

O manualmente:

```bash
g++ -std=c++17 -Wall -Iinclude src/*.cpp -o gestionCompetencia
./demo        # macOS/Linux
demo.exe      # Windows
```

### Sin `make` (por ejemplo, usando la extensión de C++ de VSCode)

Compilar todos los `.cpp` de `src/` agregando `include/` como carpeta de headers (`-I include`).

## Qué esperar al correrlo

El programa, tal como está, hace lo siguiente automáticamente:

1. Carga 5 robots de ejemplo (`vector<Robot>`)
2. Filtra los robots de tipo `"Sumo"`
3. Simula una batalla aleatoria entre dos robots y anuncia un ganador

El bloque de **captura interactiva de un `Equipo`** y el **mini-reto integrador** están comentados
al final de `main.cpp` — se descomentan en clase para practicar `cin`/`getline` y unir todas las
piezas (`Equipo` + `Robot` + `vector` + batalla) en un solo flujo.

## Buenas prácticas aplicadas (para señalar en clase)

- Include guards (`#pragma once`) en todos los `.h`
- Separación interfaz (`.h`) / implementación (`.cpp`)
- Listas de inicialización en constructores
- Parámetros `std::string` recibidos por referencia constante (`const std::string&`)
- Métodos que no modifican estado marcados `const`
- `const auto&` en recorridos `range-based for`
- `<random>` (`mt19937` + `uniform_int_distribution`) en vez de `rand()`
