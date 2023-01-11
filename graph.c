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

void add_edges(pnode pnode1, pnode *head){
    //B 5 0 4 2 1
    int end_point, weight;
    pedge root_edge = (pedge) malloc(sizeof(struct edge_));
    pedge next_edge = root_edge;
    int flag = 0;
    while (scanf(" %d %d", &end_point, &weight) == 2) {
        pedge _edge = malloc(sizeof(struct edge_));
        pnode find = find_node(head, end_point);
        if (find == NULL) {
            node *next_node = malloc(sizeof(struct GRAPH_NODE_));
            next_node->node_num = end_point;
            find = next_node;
        }
        _edge->endpoint = find;
        _edge->weight = weight;
        if (flag == 0) {
            pnode1->edges = _edge;
            root_edge = _edge;
        } else {
            next_edge->next = _edge;
        }
        flag = 1;
        next_edge = _edge;
    }
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

        add_edges(_node,head);

        if (i == 0) {
            *head = _node;
        } else {
            tmpHead->next = _node;
        }
        tmpHead = _node;
    }
}

void insert_node_cmd(pnode *head) {
    int vertex;
    scanf(" %d", &vertex);
    pnode find = find_node(head, vertex);

    if (find == NULL) {
        node *next_node = malloc(sizeof(struct GRAPH_NODE_));
        next_node->node_num = vertex;
        find = next_node;
        add_edges(find, head);
        pnode next_ = *head;
        while (next_->next != NULL){
            next_ = next_->next;
        }
        next_->next = find;
    } else{
        if (find->edges != NULL)
            delete_edges_cmd(&find->edges);
        add_edges(find, head);
    }


}

void delete_node_cmd(pnode *pnode1) {

}

void delete_edges_cmd(pedge *root){
    pedge current = *root;
    pedge next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    *root = NULL;
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
    pnode current = *head;
    pnode next;

    while (current != NULL) {
        pedge edges = current -> edges;
        delete_edges_cmd(&edges);
        next = current->next;
        free(current);
        current = next;
    }

    *head = NULL;
}

void shortsPath_cmd(pnode head) {
    int start, end;
    scanf(" %d %d", &start, &end);
    pnode startNode = find_node(&head, start);
    pnode tempNode = startNode;
    pedge currentEdge = tempNode->edges;


}


void TSP_cmd(pnode head) {

}


