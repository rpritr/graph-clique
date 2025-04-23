#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "graph.h"
using namespace std;

vector<vector<int>> readGraph(string path, int V)
{
    vector<vector<int>> G = initGraph(4, 4);
    ifstream file(path);
    int u, v;

    while (file >> u >> v)
    {
        G[u][v] = 1;
        G[v][u] = 1;
    }

    return G;
}
