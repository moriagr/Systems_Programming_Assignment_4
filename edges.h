#ifndef EDGES_H
#define EDGES_H

typedef struct Edge{
    int from;
    int to;
    int weight;
    struct Edge* next;
} Edge;

void add_edge(int from, int to, int weight);
//void delete_edge(int from, int to);
int get_edge_weight(int from, int to);

#endif
