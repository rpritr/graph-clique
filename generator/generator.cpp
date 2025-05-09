#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;

int main()
{
    const int V = 500;
    vector<int> clique_sizes = {30, 25, 40}; // Tri velike klike
    set<pair<int, int>> edges;
    int offset = 0;

    // 1. Dodamo klike
    for (int size : clique_sizes)
    {
        for (int i = offset; i < offset + size; ++i)
        {
            for (int j = i + 1; j < offset + size; ++j)
            {
                edges.insert({i, j});
            }
        }
        offset += size;
    }

    // 2. Dodamo naključne povezave
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, V - 1);

    while (edges.size() < 100)
    {
        int u = dis(gen);
        int v = dis(gen);
        if (u == v)
            continue;
        if (u > v)
            swap(u, v);
        edges.insert({u, v});
    }

    // 3. Zapišemo v datoteko
    ofstream outfile("graph100.txt");
    if (!outfile.is_open())
    {
        cerr << "Napaka pri odpiranju datoteke!" << endl;
        return 1;
    }

    for (const auto &edge : edges)
    {
        outfile << edge.first << " " << edge.second << " 0\n";
    }

    outfile.close();
    cout << "Generiranih " << edges.size() << " povezav." << endl;

    return 0;
}