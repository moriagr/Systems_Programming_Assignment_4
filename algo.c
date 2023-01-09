#include "algo.h"
#include "vertex.h"
#include <stdio.h>

#define MAX_NODES 100

Node nodes[MAX_NODES];
int num_nodes = 0;

typedef struct {
    int vertex;
    int distance;
} Node;

void bfs(int start, int end) {
    bool visited[MAX_NODES];
    for (int i = 0; i < num_nodes; i++) {
        visited[i] = false;
    }

    Node queue[MAX_NODES];
    int head = 0;
    int tail = 0;

    queue[tail++] = (Node){start, 0};
    visited[start] = true;

    while (head < tail) {
        Node node = queue[head++];
        int vertex = node.vertex;
        int distance = node.distance;

        if (vertex == end) {
            printf("Shortest path from %d to %d has length %d\n", start, end, distance);
            return;
        }

        for (int i = 0; i < vertices[vertex].num_edges; i++) {
            int neighbor = vertices[vertex].edges[i];
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                queue[tail++] = (Node){neighbor, distance + 1};
            }
        }
    }

    printf("There is no path from %d to %d\n", start, end);
}
