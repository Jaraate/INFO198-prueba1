CXX = g++
CXXFLAGS = -Iinclude -I../common -std=c++17 -Wall

SRC = src/main.cpp src/user.cpp ../common/user_utils.cpp
OBJ = $(SRC:.cpp=.o)
BIN = app

all: $(BIN)

$(BIN): $(OBJ)
	$(CXX) $(OBJ) -o $(BIN) $(CXXFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ) $(BIN)