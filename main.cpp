#include <iostream>
#include "src/clique.h"
using namespace std;

int main()
{
    Graph g("graph100.txt"); // kreiram graf
    // Graph g("bio-SC-CC.edges");
    g.printGraphMatrix();
    g.printGraphStats();
    cout << "Edge list: " << endl;
    g.printEdgeList();

    Clique c(g);

    c.findGreedyMaxClique();

    Clique d(g);
    d.findBronKerboschMaxClique();

    return 0;
}