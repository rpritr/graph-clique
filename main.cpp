#include <iostream>
#include "src/clique.h"
using namespace std;

int main()
{
    Graph initGraph(6);               // kreiram graf
    initGraph.readGraph("graph.txt"); // preberem iz datoteke
    initGraph.printGraphMatrix();
    initGraph.printGraphStats();

    Clique c(initGraph);

    c.findGreedyMaxClique();

    Clique d(initGraph);
    d.findBronKerboschMaxClique();
    return 0;
}