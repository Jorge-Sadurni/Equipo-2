CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
TARGET = competencia_robotica
SOURCES = main.cpp Competencia.cpp Equipo.cpp Integrante.cpp Robot.cpp Disciplina.cpp Enfrentamiento.cpp
HEADERS = Competencia.h Equipo.h Integrante.h Robot.h Disciplina.h Enfrentamiento.h
OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run