CXX = g++
CXXFLAGS = -std=c++11 -Wall

SRC = main.cpp src/Graph.cpp src/Clique.cpp src/Time.cpp src/Subset.cpp
HEADERS = src/Graph.h src/Clique.h src/Time.h src/Subset.h
TARGET = maxclique

all: $(TARGET)

$(TARGET): $(SRC) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)