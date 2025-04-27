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
    Graph(int V);
    vector<vector<int>> getGraph() const;
    vector<vector<int>> readGraph(string path);
    void printGraphMatrix();
    void printEdgeList();
    void printGraphStats();
};

// konstruktor za graf
Graph::Graph(int V)
{
    this->V = V;
    this->E = 0;
    G = vector<vector<int>>(V, vector<int>(V, 0)); // V x V matrika inicializirana na 0
}

vector<vector<int>> Graph::getGraph() const
{
    return this->G;
}
// preberem graf iz datoteke, vrnem G
vector<vector<int>> Graph::readGraph(string path)
{
    ifstream file(path);
    int u, v;

    while (file >> u >> v)
    {
        G[u][v] = 1;
        G[v][u] = 1;
    }

    return G;
}

// izpisem matriko sosednosti za graf G
void Graph::printGraphMatrix()
{
    for (int i = 0; i < this->G.size(); i++)
    {
        for (int j = 0; j < this->G[i].size(); j++)
        {
            cout << this->G[i][j] << " ";
        }
        cout << endl;
    }
}

// izpis povezav v grafu
void Graph::printEdgeList()
{
    for (int i = 0; i < this->G.size(); i++)
    {
        for (int j = i; j < this->G[i].size(); j++)
        {
            if (this->G[i][j] == 1)
                cout << i << " " << j << endl;
        }
    }
}

// izpis lastnosti grafa
void Graph::printGraphStats()
{
    cout << endl;
    cout << "Edge size: " << this->G.size() << endl;
    cout << "Vertices size: " << this->G.size() << endl; // TODO!!!
    cout << "Graph: " << endl;
    this->printEdgeList();
}