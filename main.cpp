#include <iostream>
#include "src/clique.h"
using namespace std;

int main()
{
    Graph initGraph(6);
    initGraph.readGraph("graph.txt");
    initGraph.printGraphMatrix();
    initGraph.printGraphStats();

    Clique c(initGraph);
    c.findGreedyMaxClique();
    c.findBronKerboschMaxClique();
    return 0;
}