#include "nodes.h"
#include "edges.h"
#include <stdlib.h>

Node *nodes; //linked list of nodes

void add_node(Node *node) {

}

void delete_node(int value) {
    for (int i = 0; i < num_nodes; i++) {
        Node *node = graph->next_node;
        if (node.value == value) {

            //

            break;
        }
    }
}

int get_node_value(int index) {
}

void create_graph(Node *root) {

    char num_nodes = getChar();
    Graph *graph = malloc(sizeof(num_nodes));
    graph->next_node = NULL;
    graph->next_edge = NULL;
    graph->num_of_edges = 0;
    graph->num_of_nodes = 0;

    int i = 0;
    while (i<num_nodes){
        char next = getChar();

        if (next == 'A' || next == 'B' || next == 'T' || next == 'S'){
            break;

        } else if (next == 'n'){
            i++;
            Node *node = NULL;
            node->value = getChar();
            next = getChar();

            while (next != 'n' && next != 'A' && next != 'B' && next != 'T' && next != 'S'){
                Edge *edge = NULL;
                edge->from  = node->value;
                edge->to  = getChar();
                edge->weight  = getChar();
                node->next_edge = edge;
                node->next_node = NULL;

            }
            add_node(node);
        }
    }



}

void deleteGraph(Graph graph) {
    Node *node = graph->next_node;
    while (node != NULL) {
        Node *next_node = node->next_node;
        Edge *edge = node->next_edge;
        while (edge != NULL) {
            Edge *next_edge = edge->next_edge;
            free(edge);
            edge = next_edge;
        }
        free(node);
        node = next_node;
    }
}
