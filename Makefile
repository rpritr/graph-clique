CXX = g++
CXXFLAGS = -std=c++11 -Wall

SRC = main.cpp src/Graph.cpp src/Clique.cpp
HEADERS = src/Graph.h src/Clique.h
TARGET = maxclique

all: $(TARGET)

$(TARGET): $(SRC) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)