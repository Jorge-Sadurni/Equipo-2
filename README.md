# Sistema de Gestión de Competencia de Robótica en C++

Proyecto orientado a objetos para gestionar una competencia de robotica estudiantil para estudiantes de ingenieria. Solo participan las carreras INGENIERIA MECATRONICA, INGENIERIA INDUSTRIAL e INGENIERIA AMBIENTAL.

## Descripción general

Este proyecto modela una competencia en la que:

1. Se crean equipos con nombre, integrantes y robots.
2. Cada robot pertenece a una disciplina: `SUMO`, `SEGUIDOR DE LINEA` o `VELOCISTA`.
3. La competencia valida el registro, cierra la fase de inscripción y genera enfrentamientos por disciplina.
4. Se ejecutan batallas aleatorias y se presenta un reporte final con los resultados.

La competencia permite un maximo de 10 equipos y cada equipo puede registrar como maximo 2 robots. Los nombres de equipos, integrantes y robots no pueden repetirse. Los textos registrados se convierten a MAYUSCULAS y se normalizan sin acentos.

El desarrollo está organizado con separación entre interfaz y lógica, usando clases propias para cada entidad del dominio.

### Diagrama de clases

<p align="center">
  <img src="Diagrama de Clases y Atributos (1).png" alt="Diagrama de clases" width="900" />
</p>

### Identificacion de clases y relaciones

Las clases del sistema colaboran mediante llamadas a sus metodos y no utilizan herencia:

- `Competencia`: administra el nombre, el estado, los equipos y las disciplinas. Registra equipos, cierra el registro, clasifica robots y genera los enfrentamientos.
- `Equipo`: representa un equipo y contiene integrantes y robots.
- `Integrante`: representa a una persona del equipo con nombre y carrera.
- `Robot`: representa un robot con nombre y tipo de disciplina.
- `Disciplina`: agrupa robots del mismo tipo, genera enfrentamientos y almacena sus resultados.
- `Enfrentamiento`: simula la competencia entre dos robots y determina el ganador.

Relaciones principales:

- Una `Competencia` contiene cero o varios `Equipo`.
- Un `Equipo` contiene cero o varios `Integrante` y cero o varios `Robot`.
- Una `Competencia` contiene las disciplinas disponibles.
- Una `Disciplina` agrupa robots del mismo tipo y genera enfrentamientos.
- Un `Enfrentamiento` recibe dos `Robot` para simular la competencia.

```mermaid
classDiagram
    Competencia "1" o-- "0..*" Equipo : contiene
    Competencia "1" o-- "1..*" Disciplina : administra
    Equipo "1" o-- "0..*" Integrante : contiene
    Equipo "1" o-- "0..*" Robot : contiene
    Disciplina "1" o-- "0..*" Robot : agrupa
    Disciplina "1" ..> "0..*" Enfrentamiento : genera
    Enfrentamiento "1" ..> "2" Robot : enfrenta
```

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

### En Windows

Desde la carpeta principal del repositorio, compila:

```powershell
New-Item -ItemType Directory -Force build
g++ -std=c++11 -Wall -Wextra -Iinclude src/main.cpp src/Competencia.cpp src/Disciplina.cpp src/Enfrentamiento.cpp src/Equipo.cpp src/Integrante.cpp src/Robot.cpp -o build/gestionRobots.exe
```

Despues de compilar, ejecuta:

```powershell
.\build\gestionRobots.exe
```

### En macOS

Desde la carpeta principal del repositorio, compila:

```bash
mkdir -p build
g++ -std=c++11 -Wall -Wextra -Iinclude src/main.cpp src/Competencia.cpp src/Disciplina.cpp src/Enfrentamiento.cpp src/Equipo.cpp src/Integrante.cpp src/Robot.cpp -o build/gestionRobots
```

Despues de compilar, ejecuta:

```bash
./build/gestionRobots
```

## Qué esperar al correrlo

Al ejecutar el programa, la aplicación se comporta de la siguiente manera:

1. Muestra el nombre de la competencia y su estado inicial.
2. Solicita la cantidad de equipos a registrar.
2. Para cada equipo, pide:
   - nombre del equipo
   - cantidad de integrantes (máximo 3)
  - nombre y carrera de cada integrante. Las carreras validas son INGENIERIA MECATRONICA, INGENIERIA INDUSTRIAL e INGENIERIA AMBIENTAL
  - cantidad de robots a registrar (maximo 2)
  - nombre y disciplina de cada robot. Las disciplinas validas son SUMO, SEGUIDOR DE LINEA y VELOCISTA
4. Al terminar la captura, cierra el registro de equipos.
5. La competencia inicializa sus disciplinas y registra automáticamente cada robot según su tipo.
6. Genera enfrentamientos por disciplina y ejecuta las batallas aleatorias.
7. Muestra el reporte final con los equipos participantes y los resultados por disciplina.

En resumen, la aplicación no solo construye la estructura del problema, sino que también ejecuta todo el flujo real de una competencia: inscripción, clasificación, enfrentamientos y reporte final.

## Funcionamiento de la competencia

1. Se solicita la cantidad de equipos, con un maximo de 10.
2. Se registran los integrantes y hasta 2 robots por equipo.
3. Cada robot se clasifica automaticamente en SUMO, SEGUIDOR DE LINEA o VELOCISTA.
4. Al cerrar el registro, cada disciplina genera sus enfrentamientos.
5. Si una disciplina tiene dos o mas robots, se realiza un torneo todos contra todos. Cada pareja de robots compite una vez.
6. Si una disciplina tiene cero o un robot, se informa que los enfrentamientos no se llevaron a cabo por falta de robots suficientes.
7. Se ejecutan las batallas y se cuentan las victorias de cada robot.
8. Se muestra el reporte final con los equipos, los enfrentamientos y los resultados.

### Ganador absoluto

El ganador absoluto se determina por disciplina. Cada vez que un robot gana una batalla, acumula una victoria. Al terminar todos los enfrentamientos, se comparan las victorias acumuladas y el robot con la mayor cantidad se muestra como:

```text
GANADOR ABSOLUTO DE SUMO: NOMBRE DEL ROBOT
```

Con tres robots se realizan tres enfrentamientos: el primero contra el segundo, el primero contra el tercero y el segundo contra el tercero. De esta forma, todos participan y el ganador absoluto es el robot que obtiene mas victorias.

## Evidencia de pruebas

| Caso de prueba | Resultado esperado |
|---|---|
| Registrar entre 1 y 10 equipos | Se acepta la cantidad y se rechazan valores fuera del rango |
| Intentar registrar mas de 10 equipos | Se rechaza el equipo numero 11 |
| Registrar mas de 2 robots en un equipo | Se rechaza la cantidad y se vuelve a solicitar |
| Registrar nombres repetidos | Se rechaza el nombre y se solicita uno diferente |
| Escribir nombres en minusculas | Los nombres se guardan en MAYUSCULAS |
| Escribir una carrera no permitida | Solo se aceptan INGENIERIA MECATRONICA, INGENIERIA INDUSTRIAL e INGENIERIA AMBIENTAL |
| Escribir una disciplina no permitida | Solo se aceptan SUMO, SEGUIDOR DE LINEA y VELOCISTA |
| Registrar cero robots en una disciplina | Se informa que no se llevaron a cabo los enfrentamientos |
| Registrar un robot en una disciplina | Se informa que no hubo robots suficientes |
| Registrar tres robots en una disciplina | Se realiza un torneo todos contra todos |
| Finalizar un torneo | Se cuentan las victorias y se muestra el ganador absoluto |

### Bugs encontrados y corregidos


- El programa permitia registrar mas de 10 equipos. Se agrego un limite de 10 equipos.
- Cada equipo podia registrar mas de 2 robots. Se agrego la validacion correspondiente.
- Se podian repetir nombres de equipos, integrantes y robots. Ahora todos los nombres deben ser unicos.
- Se aceptaban carreras y disciplinas no validas. Ahora solo se aceptan las opciones definidas por la competencia.
- Una disciplina sin robots o con un solo robot no mostraba claramente por que no habia competencia. Ahora informa la situacion en pantalla y en el reporte final.
- Con una cantidad impar de robots, uno quedaba sin competir. Se cambio a un torneo todos contra todos.
- No se mostraba un ganador general de la disciplina. Ahora se cuentan las victorias y se informa el ganador absoluto.


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
- Uso de `<random>` con `std::random_device`, `std::mt19937` y `std::uniform_int_distribution` para simular resultados.
- Manejo de errores con `std::runtime_error` y `std::invalid_argument` para avisar cuando una operación no es válida.
- Uso de `enum class` para representar de forma segura los estados de la competencia.
- Uso de `std::map` para organizar las disciplinas por tipo de robot.
- Uso de bucles basados en rango (`for (const auto& elemento : coleccion)`) para recorrer colecciones de forma clara.
- Gestión automática de memoria mediante contenedores de la biblioteca estándar, sin utilizar punteros ni liberación manual.

## Observaciones

- El proyecto está pensado para un ejercicio académico de POO y programación con C++.
- La lógica de competencia es didáctica, pero sigue una estructura clara que puede ampliarse para nuevas disciplinas, métricas o tipos de robot.
- El flujo interactivo de consola está diseñado para que el usuario pueda registrar equipos reales y observar el resultado de la competencia en tiempo de ejecución.

<<<<<<< HEAD
## Errores detectados

- La validación de entradas numéricas no es robusta: valores como `1.5`, `.5`, `-3` o texto no numérico pueden romper el flujo del programa.
- El buffer de entrada no se maneja de forma consistente, por lo que los datos sobrantes pueden contaminar los siguientes prompts.
- La captura de nombres y texto no valida formato ni contenido útil, lo que puede generar registros inconsistentes.
- El registro de equipos puede quedar desalineado si una entrada inválida se introduce en medio del proceso.
=======
>>>>>>> f728f37e5d8d66ed6b0fc3f6691fd11fe5e6a28d

