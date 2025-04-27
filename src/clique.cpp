#include "clique.h"

// konstruktor za razred Clique
Clique::Clique(const Graph &G) : G(G)
{
    for (int i = 0; i < G.getGraph().size(); i++)
    {
        for (int j = 0; j < G.getGraph()[i].size(); j++)
        {
            if (G.getGraph()[i][j] == 1)
                this->vertDegrees[i]++;
        }
    }
}

// izpis stopenj vozlisc v grafu
void Clique::printVerticeDegrees(vector<pair<int, int>> V)
{
    for (int i = 0; i < V.size(); i++)
    {
        cout << V[i].first << ": " << V[i].second << endl;
    }
}

// sort stopenj vozlisc
vector<pair<int, int>> Clique::sortNodes()
{

    vector<pair<int, int>> sorted(this->vertDegrees.begin(), this->vertDegrees.end());
    sort(sorted.begin(), sorted.end(), [](const pair<int, int> &a, const pair<int, int> &b)
         { return a.second > b.second; });

    return sorted;
}

// izpis klike
void Clique::printClique()
{
    for (int i = 0; i < this->clique.size(); i++)
    {
        cout << this->clique.at(i) << " ";
    }
    cout << endl;
}

// pozresno iskanje najvecje klike
void Clique::findGreedyMaxClique()
{
    cout << "Greedy Clique: " << endl;
    vector<pair<int, int>> sorted = sortNodes();
    this->printVerticeDegrees(sorted);

    // pregledam vozlisca, poiscem kandidata za kliko, ce ga ni v seznamu ga dodam
    for (int i = 0; i < sorted.size(); i++)
    {
        int addV = sorted[i].first;
        bool add = true;

        for (int j = 0; j < this->clique.size(); j++)
        {
            if (this->G.getGraph()[addV][this->clique[j]] == 0)
            {
                add = false;
                break;
            }
        }
        if (add)
            this->clique.push_back(addV);
    }
    this->printClique();
}

void Clique::findBronKerboschMaxClique()
{
}