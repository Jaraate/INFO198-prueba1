# Compilador y flags
CXX = g++
CXXFLAGS = -Wall -std=c++17

# Directorios
SRC_DIR = src
BIN_DIR = bin

# Archivos fuente y ejecutable
SOURCES = $(SRC_DIR)/indice_Invertido.cpp
TARGET = $(BIN_DIR)/creaIndice

# Regla principal
all: $(TARGET)

# Compilación del ejecutable
$(TARGET): $(SOURCES)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Limpiar binarios
clean:
	rm -rf $(BIN_DIR)

# Ejecutar (opcional)
run: all
	./$(TARGET)