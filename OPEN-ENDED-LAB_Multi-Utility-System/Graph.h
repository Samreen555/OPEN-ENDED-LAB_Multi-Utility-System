#ifndef GRAPH_H
#define GRAPH_H

#define MAX_NODES 100

class Graph {
    int adjMatrix[MAX_NODES][MAX_NODES];
    int numVertices;

public:
    Graph(int vertices);
    void addEdge(int u, int v, int weight);
    void dijkstra(int start, int end);
};

#endif
