# MaxClique

C++ implementation for finding maximum clique in an undirected graph:
- greedy method
- Bron–Kerbosch algorithm

# Usage:

Graph g(PATH);

Clique c(g);
c.findGreedyMaxClique();

Clique d(g);
d.findBronKerboschMaxClique();

# Methods

Graph g(PATH);<br/>

g.printGraphMatrix(); // print adjacency matrix

g.printGraphStats(); // print graph statistics

g.printEdgeList(); // print edge list

# Input format

Each line represents an edge between two nodes

0 0

0 1

1 2

2 3

3 4

2 4

# Run the program

make && ./maxclique