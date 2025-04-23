#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> initGraph(int V, int E)
{
    vector<vector<int>> G(E, vector<int>(V, 0)); // 2D array graph E X V
    return G;
}

void printGraphMatrix(vector<vector<int>> G)
{
    for (int i = 0; i < G.size(); i++)
    {
        for (int j = 0; j < G[i].size(); j++)
        {
            cout << G[i][j] << " ";
        }
        cout << endl;
    }
}
void printGraphList(vector<vector<int>> G)
{
    for (int i = 0; i < G.size(); i++)
    {
        for (int j = i; j < G[i].size(); j++)
        {
            if (G[i][j] == 1)
                cout << i << " " << j << endl;
        }
    }
}
void printGraphStats(vector<vector<int>> G)
{
    cout << endl;
    cout << "Edge size: " << G.size() << endl;
    cout << "Vertices size: " << G.size() << endl; // TODO!!!
    cout << "Graph: " << endl;
    printGraphList(G);
}