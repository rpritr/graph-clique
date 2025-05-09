# MaxClique

C++ implementacija za iskanje največjih klik v neusmerjenem grafu:
- požrešna metoda
- Bron–Kerbosch algoritem

# Uporaba:

Graph g(PATH);

Clique c(g);
c.findGreedyMaxClique();

Clique d(g);
d.findBronKerboschMaxClique();

# Metode

Graph g(PATH);<br/>

g.printGraphMatrix(); // izpis matrike sosednosti

g.printGraphStats(); // izpis karatkeristik grafa

g.printEdgeList(); // izpis seznama povezav

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