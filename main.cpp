#include <iostream>
#include "src/file.h"
using namespace std;

int main()
{

    cout << "test" << endl;
    // vector<vector<int>> G = initGraph(3, 5);
    vector<vector<int>> G2 = readGraph("graph.txt", 3);

    // printGraph(G);
    // printGraph(G2);
    return 0;
}