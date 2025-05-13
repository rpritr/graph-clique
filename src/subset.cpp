#include "subset.h"

vector<vector<int>> Subset::generate(const vector<int> &nodes)
{
    vector<vector<int>> all;
    all.push_back({}); // začnem s prazno množico

    for (int i = 0; i < nodes.size(); ++i)
    {
        int n = all.size();
        for (int j = 0; j < n; ++j)
        {
            vector<int> subset = all[j]; // kopiramo obstoječo podmnožico
            subset.push_back(nodes[i]);  // dodamo novo vozlišče
            all.push_back(subset);       // shranimo novo podmnožico
        }
    }

    return all;
}