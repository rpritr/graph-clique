#include <iostream>
#include "src/file.h"
#include "src/clique.h"
using namespace std;

int main()
{
    // vector<vector<int>> G = initGraph(3, 5);
    vector<vector<int>> G2 = readGraph("graph.txt", 3);
    cout << "Graph adjecency list: " << endl;
    printGraphMatrix(G2);
    printGraphStats(G2);
    findGreedyMaxClique(G2);
    return 0;
}