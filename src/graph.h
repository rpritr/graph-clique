#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> initGraph(int V, int E)
{
    vector<vector<int>> G(E, vector<int>(V, 0)); // 2D array graph E X V
    return G;
}

void printGraph(vector<vector<int>> G)
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