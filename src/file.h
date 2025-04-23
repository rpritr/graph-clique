#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "graph.h"
using namespace std;

vector<vector<int>> readGraph(string file, int V)
{
    vector<vector<int>> G = initGraph(4, 4);
    ifstream infile(file);
    int u, v;

    cout << "Edge size: " << G.size() << endl;
    cout << "Vertices size: " << G.size() << endl; // TODO!!!
    cout << "Graph: " << endl;

    while (infile >> u >> v)
    {
        G[u][v] = 1;
        G[v][u] = 1;
        cout << u << " " << v << endl;
    }
    cout << "Graph adjecency list: " << endl;
    printGraph(G);
    return G;
}