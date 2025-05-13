#include <iostream>
#include "src/clique.h"
#include "src/time.h"

using namespace std;

int main()
{

    Graph g("./graphs/graph22.txt"); // kreiram graf
    g.printGraphMatrix();
    g.printGraphStats();
    cout << "Edge list: " << endl;
    g.printEdgeList();

    Time bruteforce; // stevec za cas izvajanja BronKerbosch

    Clique b(g);
    b.findBruteforceClique();
    bruteforce.stop();
    bruteforce.printDuration("Bruteforce duration");

    Clique c(g);
    Time timerGreedy; // stevec za cas izvajanja pozresne metode
    c.findGreedyMaxClique();
    timerGreedy.stop();
    timerGreedy.printDuration("Greedy duration");

    Time timerBron; // stevec za cas izvajanja BronKerbosch
    Clique d(g);
    d.findBronKerboschMaxClique();
    timerBron.stop();
    timerBron.printDuration("BronKerbosch duration");

    return 0;
}