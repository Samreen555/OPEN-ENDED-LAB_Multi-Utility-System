#include <iostream>
#include "Graph.h"
using namespace std;

Graph::Graph(int vertices) : numVertices(vertices) {
    for (int i = 0; i < MAX_NODES; ++i)
        for (int j = 0; j < MAX_NODES; ++j)
            adjMatrix[i][j] = (i == j) ? 0 : INT_MAX;
}

void Graph::addEdge(int u, int v, int weight) {
    adjMatrix[u][v] = weight;
}

void Graph::dijkstra(int start, int end) {
    int dist[MAX_NODES], visited[MAX_NODES], parent[MAX_NODES];
    for (int i = 0; i < numVertices; ++i) {
        dist[i] = INT_MAX;
        visited[i] = 0;
        parent[i] = -1;
    }
    dist[start] = 0;

    for (int count = 0; count < numVertices - 1; ++count) {
        int minDist = INT_MAX, u = -1;
        for (int i = 0; i < numVertices; ++i)
            if (!visited[i] && dist[i] < minDist) {
                minDist = dist[i];
                u = i;
            }
        if (u == -1) break;
        visited[u] = 1;

        for (int v = 0; v < numVertices; ++v) {
            if (!visited[v] && adjMatrix[u][v] != INT_MAX && dist[u] + adjMatrix[u][v] < dist[v]) {
                dist[v] = dist[u] + adjMatrix[u][v];
                parent[v] = u;
            }
        }
    }

    // Output shortest path and cost
    if (dist[end] == INT_MAX) {
        cout << "No path exists from " << start << " to " << end << endl;
        return;
    }

    cout << "Shortest path from " << start << " to " << end << ": ";
    int current = end;
    while (current != -1) {
        cout << current << " ";
        current = parent[current];
    }
    cout << "\n Cost: " << dist[end] << endl;
}
