#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

class Graph
{
private:
    int V;
    int E;
    vector<vector<int>> G;

public:
    Graph(string path);
    vector<vector<int>> getGraph() const;
    vector<vector<int>> readGraph(string path);
    void printGraphMatrix();
    void printEdgeList();
    void printGraphStats();
};

#endif