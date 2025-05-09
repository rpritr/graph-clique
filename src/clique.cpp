#include "clique.h"

// konstruktor za razred Clique
// izracunam stopnje vozlisc
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

// sort po stopnjah vozlisc v grafu
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
    cout << "Greedy Max klika: ";
    this->printClique();
}

void Clique::findBronKerboschMaxClique()
{
    vector<int> R; // prazna mnozica
    vector<int> P; //  mnozica vozlisc v grafu
    vector<int> X; // prazna mnozica

    // nastavimo P
    for (int i = 0; i < G.getGraph().size(); i++)
    {
        P.push_back(i);
    }
    this->bronKerbosch(R, P, X);
}

// https://en.wikipedia.org/wiki/Bron%E2%80%93Kerbosch_algorithm
void Clique::bronKerbosch(vector<int> R, vector<int> P, vector<int> X)
{
    // dodam omejitev za iskanje na velikih grafih za globino rekurzije
    static int depth = 0;
    depth++;
    if (depth > 10000)
    {
        cout << "Depth reached. Exiting." << endl;
        return;
    }
    if (P.empty() && X.empty())
    {
        if (R.size() > clique.size())
        {
            clique = R;
            cout << "bronKerbosch Max klika: ";
            printClique();
            return;
        }
        return;
    }
    if (P.empty())
    {
        return;
    }

    vector<int> Pcopy = P; // delam na kopiji, da ne spreminjam stanja
    for (int i = 0; i < Pcopy.size(); i++)
    {
        vector<int> newR = R;
        vector<int> newP;
        vector<int> newX;

        int v = Pcopy[i];
        // R unija v
        newR.push_back(v);

        // P presek N, kjer je N sosed, torej za vsakega soseda
        // vsi sosedi od vozlisca
        for (int j = 0; j < P.size(); j++)
        {
            int u = P[j];
            if (G.getGraph()[v][u])
            {
                newP.push_back(u);
            }
        }

        // X presek N, kjer je N sosed, torej za vsakega soseda
        for (int k = 0; k < X.size(); k++)
        {
            int u = X[k];
            if (G.getGraph()[v][u])
            {
                newX.push_back(u);
            }
        }
        bronKerbosch(newR, newP, newX); // rekurzivni klic bronKerbosch
        //  P := P \ {v}
        auto it = find(P.begin(), P.end(), v);
        if (it != P.end())
            P.erase(it);

        // **X := X ∪ {v}**
        X.push_back(v);
    }
}