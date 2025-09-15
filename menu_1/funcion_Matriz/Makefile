CXX = g++

CXXFLAGS = -Wall -std=c++17

TARGET = mult_matrices

SRC = mult_matrices.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)