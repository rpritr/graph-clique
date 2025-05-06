# MaxClique

C++ implementacija za iskanje največjih klik v neusmerjenem grafu:
- požrešna metoda
- Bron–Kerbosch algoritem

# Uporaba:

Graph initGraph(6); 
initGraph.readGraph("graph.txt");

Clique c(initGraph);
c.findGreedyMaxClique();

Clique d(initGraph);
d.findBronKerboschMaxClique();

# Vhodni format

Vsaka vrstica predstavlja povezavo med vozliščema
0 0
0 1
1 2
2 3
3 4
2 4

# Zagon programa

make && ./maxclique 