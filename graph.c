#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

pnode find_node(pnode *head, int num_of_node) {
    pnode _node = NULL;
    pnode tmpHead = *head;
    while (tmpHead->next != NULL) {
        if (tmpHead->node_num == num_of_node) {
            _node = tmpHead;
            break;
        }
        tmpHead = tmpHead->next;
    }
    return _node;
}


void build_graph_cmd(pnode *head) {

    int num_of_nodes;
    scanf(" %d", &num_of_nodes);
    if (num_of_nodes < 1) {
        return;
    }
    *head = malloc(num_of_nodes * sizeof(struct GRAPH_NODE_));
    pnode tmpHead = *head;


    for (int i = 0; i < num_of_nodes; i++) {
        char nChar;
        scanf(" %c", &nChar);
        int vertex;
        scanf(" %d", &vertex);

        node *_node = malloc(sizeof(struct GRAPH_NODE_));
        _node->edges = NULL;
        _node->node_num = vertex;

        int next;
        pedge root_edge = (pedge) malloc(sizeof(struct edge_));
        pedge next_edge = root_edge;
        int flag = 0;
        int weight;
        while (scanf(" %d %d", &next, &weight) == 2) {
            pedge _edge = malloc(sizeof(struct edge_));
            pnode find = find_node(head, next);
            if (find == NULL) {
                node *next_node = malloc(sizeof(struct GRAPH_NODE_));
                next_node->node_num = next;
                find = next_node;
            }
            _edge->endpoint = find;
            _edge->weight = weight;
            if (flag == 0) {
                _node->edges = _edge;
                root_edge = _edge;
            }
            else{
                next_edge->next = _edge;
            }
            flag = 1;
            next_edge = _edge;
        }
        if (i == 0) {
            *head = _node;
        } else {
            tmpHead->next = _node;
        }
        tmpHead = _node;
    }
}

void insert_node_cmd(pnode *head) {

}

void delete_node_cmd(pnode *head) {

}

void printGraph_cmd(pnode head) {
    pnode current = head;
    while (current != NULL) {
        printf("Node %d: ", current->node_num);
        pedge current_edge = current->edges;
        while (current_edge != NULL) {
            printf("%d (weight: %d) ", current_edge->endpoint->node_num, current_edge->weight);
            current_edge = current_edge->next;
        }
        printf("\n");
        current = current->next;
    }
}

void deleteGraph_cmd(pnode *head) {

}

void shortsPath_cmd(pnode head) {

}

void TSP_cmd(pnode head) {

}


