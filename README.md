# Network-Modeling-with-Kruskal-s-Minimum-Spanning-Tree
Small project that solves the airport railway problem using Kruskal’s Minimum Spanning Tree Algorithm.

The program solves the problem where we need to design transportation network that connects several cities by airports and railways with minimum overall construction
costs when map of the cities and the costs of connections between them are given. It is assumed that every cities that has airport are connected to each other and that all connections works both ways. Program takes input file with following form.

N number of cities

A number of potential airports

A number of lines a c where a is a city and c is a cost of constructing airport to that city.

E number of potential railways.

E number of lines a b c where a and b are cities and c is cost of constructing railway between them.


Program returns "Impossible" if the network is impossible to build. Otherwise it returns line that contains total cost and line that contains number of airports and railways in network with minimum cost.
