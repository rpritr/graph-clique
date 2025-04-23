#include <iostream>
#include <vector>
#include <map>

using namespace std;

// inicializiram stopnje vozlisc na 0 v grafu
map<int, int> initVerticeDegrees(int G)
{
    map<int, int> vertDegree;
    for (int i = 0; i < G; i++)
    {
        vertDegree.insert({i, 0});
    }
    return vertDegree;
}
map<int, int> setVerticeDegrees(vector<vector<int>> G)
{
    map<int, int> vertDegrees = initVerticeDegrees(G.size());
    for (int i = 0; i < G.size(); i++)
    {
        for (int j = 0; j < G[i].size(); j++)
        {
            if (G[i][j] == 1)
                vertDegrees[i]++;
        }
    }
    return vertDegrees;
}

// izpis stopenj vozlisc / vektor int int
void printVerticeDegrees(vector<pair<int, int>> V)
{
    for (int i = 0; i < V.size(); i++)
    {
        cout << V[i].first << ": " << V[i].second << endl;
    }
}
// sort stopenj vozlisc
vector<pair<int, int>> sortNodes(vector<vector<int>> G)
{
    map<int, int> vertDegrees = setVerticeDegrees(G);

    vector<pair<int, int>> sorted(vertDegrees.begin(), vertDegrees.end());
    sort(sorted.begin(), sorted.end(), [](const pair<int, int> &a, const pair<int, int> &b)
         { return a.second > b.second; });

    return sorted;
}
// izpis klike
void printClique(vector<int> C)
{
    for (int i = 0; i < C.size(); i++)
    {
        cout << C.at(i) << " ";
    }
    cout << endl;
}
// pozresno iskanje najvecje klike
void findGreedyMaxClique(vector<vector<int>> G)
{
    cout << "Greedy Clique: " << endl;
    vector<pair<int, int>> sorted = sortNodes(G);
    printVerticeDegrees(sorted);

    vector<int> clique;
    // pregledam vozlisca, poiscem kandidata za kliko, ce ga ni v seznamu ga dodam
    for (int i = 0; i < sorted.size(); i++)
    {
        int addV = sorted[i].first;
        bool add = true;
        for (int j = 0; j < clique.size(); j++)
        {
            if (G[addV][clique[j]] == 0)
            {
                add = false;
                break;
            }
        }
        if (add)
            clique.push_back(addV);
    }
    printClique(clique);
}