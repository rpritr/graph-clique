#ifndef CLIQUE_H
#define CLIQUE_H

#include <vector>
#include <map>
#include "graph.h"
using namespace std;

class Clique
{
private:
    vector<int> clique; // najdena klika
    map<int, int> vertDegrees;
    const Graph &G; // referenca na graf

public:
    Clique(const Graph &G);
    void printVerticeDegrees(vector<pair<int, int>> V);
    vector<pair<int, int>> sortNodes();
    void printClique();
    void findGreedyMaxClique();
    void findBronKerboschMaxClique();
};

#endif