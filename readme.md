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

Graph g(PATH);
g.printGraphMatrix(); // izpis matrike sosednosti
g.printGraphStats(); // izpis karatkeristik grafa
g.printEdgeList(); // izpis seznama povezav

# Vhodni format

Vsaka vrstica predstavlja povezavo med vozliščema
0 0__
0 1__
1 2__
2 3__
3 4__
2 4__

# Zagon programa

make && ./maxclique 