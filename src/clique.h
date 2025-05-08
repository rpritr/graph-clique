#ifndef CLIQUE_H
#define CLIQUE_H

#include <vector>
#include <map>
#include "graph.h"
using namespace std;

class Clique
{
private:
    vector<int> clique;        // najdena klika
    map<int, int> vertDegrees; // stopnje vozlisc v grafu
    const Graph &G;            // referenca na graf

public:
    Clique(const Graph &G);                                         // konstruktor - izracun stopenj vozlisc
    void printVerticeDegrees(vector<pair<int, int>> V);             // izpis stopenj vozlisc
    vector<pair<int, int>> sortNodes();                             // sort za urejanje stopenj vozlisc
    void printClique();                                             // izpis klike
    void findGreedyMaxClique();                                     // pozresno iskanje max klike
    void findBronKerboschMaxClique();                               // iskanje max klike z bronKerbosch algoritmom
    void bronKerbosch(vector<int> R, vector<int> P, vector<int> X); // rekurzivna metoda za bronKerbosch
};

#endif