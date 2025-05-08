#include "graph.h"

using namespace std;

// konstruktor za graf
Graph::Graph(string path)
{
    this->V = 0;
    this->E = 0;

    ifstream file(path);
    int u, v;
    double w;
    int maxVert = 0;
    while (file >> u >> v >> w)
    {
        maxVert = max({maxVert, u, v});
    }
    this->V = maxVert + 1;

    G = vector<vector<int>>(V, vector<int>(V, 0)); // V x V matrika inicializirana na 0
    this->readGraph(path);
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
    double w;
    while (file >> u >> v >> w)
    {
        if (u != v) // ignoriram zanke
        {
            G[u][v] = 1;
            G[v][u] = 1;
        }
        this->E++;
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
                cout << i << " -> " << j << endl;
        }
    }
}

// izpis lastnosti grafa
void Graph::printGraphStats()
{
    cout << endl;
    cout << "Edge size: " << this->E << endl;
    cout << "Vertices size: " << this->G.size() << endl; // TODO!!!
}