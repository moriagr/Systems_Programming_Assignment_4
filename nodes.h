#ifndef NODES_H
#define NODES_H

typedef struct Node{
    int value;
    struct Edge* next_edge;
    struct Node* next_node;
} Node;

typedef struct Graph {
    struct Edge* next_edge;
    struct Node* next_node;
    int num_of_edges;
    int num_of_nodes;
} Graph;

void add_node(Node node);
void delete_node(Node node);
int get_node_value();
void create_graph();
void deleteGraph(Graph graph);

#endif

//#ifndef NODE_H
//#define NODE_H
//
//#define MAX_NODES 100
//
//typedef struct {
//    int num_edges;
//    int edges[MAX_NODES];
//} Node;
//
//void create_graph();
//
//void add_node();
//
//void add_edge(int from, int to, int weight);
//
//
//#endif
