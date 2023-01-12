#include "graph.h"
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <ctype.h>

pnode find_node(pnode *head, int num_of_node) {
    pnode _node = NULL;
    pnode tmpHead = *head;
    while (tmpHead != NULL) {
        if (tmpHead->node_num == num_of_node) {
            _node = tmpHead;
            break;
        }
        tmpHead = tmpHead->next;
    }
    return _node;
}

pnode insert_node(pnode *head, int end_point){
    pnode find = find_node(head, end_point);
    if (find == NULL) {
        node *next_node = malloc(sizeof(struct GRAPH_NODE_));
        next_node->node_num = end_point;
        find = next_node;
    }
}

void add_node(pnode *head, pnode node_to_add){
    pnode curr = *head;
    while (curr->next != NULL){
        curr = curr->next;
    }
    curr->next = node_to_add;
}

void add_edges(pnode pnode1, pnode *head) {
    //B 5 0 4 2 1
    int end_point, weight;
    pedge root_edge = (pedge) malloc(sizeof(struct edge_));
    pedge next_edge = root_edge;
    int flag = 0;
    while (scanf(" %d %d", &end_point, &weight) == 2) {
        pedge _edge = malloc(sizeof(struct edge_));
        insert_node(head, end_point);
        pnode find = find_node(head, end_point);
        if (find == NULL) {
            node *next_node = malloc(sizeof(struct GRAPH_NODE_));
            next_node->node_num = end_point;
            find = next_node;
            add_node(head,find);
        }
        _edge->endpoint = find;
        _edge->weight = weight;
        if (flag == 0) {
            pnode1->edges = _edge;
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

        pnode _node = find_node(head, vertex);
        if (_node == NULL){
            node *new_node = malloc(sizeof(struct GRAPH_NODE_));
            new_node->edges = NULL;
            new_node->node_num = vertex;
            _node = new_node;
            add_node(head, _node);
        }

        add_edges(_node, head);

        if (i == 0) {
            *head = _node;
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
        while (next_->next != NULL) {
            next_ = next_->next;
        }
        next_->next = find;
    } else {
        if (find->edges != NULL)
            delete_edges_cmd(&find->edges);
        add_edges(find, head);
    }


}

void delete_node_cmd(pnode *head) {
    int node_to_delete;
    scanf(" %d", &node_to_delete);
    pnode currentNode;
    if ((*head)->node_num == node_to_delete) {
        delete_edges_cmd(&(*head)->edges);
        currentNode = *head;
        *head = (*head)->next;
        currentNode->next = NULL;
    }

    pnode prev = *head;
    pnode curr;
    while (prev->next != NULL) {
        curr = prev->next;
        if (curr->node_num == node_to_delete) {
            delete_edges_cmd(&curr->edges);
            currentNode = curr;
            prev->next = curr->next;
            if (curr->next != NULL){
                curr = curr->next;
            }
            currentNode->next = NULL;
        }
        delete_edge(&prev->edges, node_to_delete);
        prev = prev->next;
    }
    delete_edge(&prev->edges, node_to_delete);
    free(currentNode);
}

void delete_edge(pedge *edges, int edge_to_delete){
    pedge root;

    if ((*edges) == NULL){
        return;
    }

    if ((*edges)->endpoint->node_num == edge_to_delete) {
        root = *edges;
        *edges = (*edges)->next;
        free(root);
    }

    pedge prev = *edges;
    pedge curr;
    while (prev->next != NULL) {
        curr = prev->next;
        if (curr->endpoint->node_num == edge_to_delete) {
            prev->next = curr->next;
            free(curr);
        }
        if (prev->next != NULL){
            prev = prev->next;
        }
    }

}

void delete_edges_cmd(pedge *root) {
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
        pedge edges = current->edges;
        delete_edges_cmd(&edges);
        next = current->next;
        free(current);
        current = next;
    }

    *head = NULL;
}

pnode extract_min(pnode *head){
    pnode curr = *head;
    pnode min = *head;
    while (curr != NULL){
        if (min->d > curr->d && curr->visited == 0){
            min = curr;
        }
        curr = curr->next;
    }
    min->visited = 1;
    return min;
}

//e = (u,v)
void relax(pnode u, pedge e){
    pnode v = e->endpoint;
    if (v->d > u->d + e->weight){
        v->d = u->d + e->weight;
        v->p = u;
    }
}

void shortsPath_cmd(pnode *head) {
    int start, end;
    scanf(" %d %d", &start, &end);
    pnode graph_node = *head;

    //initialize distances
    while(graph_node != NULL) {
        if(graph_node->node_num == start){
            graph_node->d = 0;
        }
        else{
            graph_node->d = INT_MAX;
        }
        graph_node->visited = 0;
        graph_node = graph_node->next;
    }

    graph_node = *head;
    while (graph_node != NULL){
        pnode min = extract_min(head);

        pedge min_edge = min->edges;
        while (min_edge != NULL){
            relax(min, min_edge);
            min_edge = min_edge->next;
        }
        graph_node = graph_node->next;
    }

    pnode endNode = find_node(head, end);
    printf("Dijsktra shortest path: %d\n", endNode->d);

}

void TSP_cmd(pnode head) {

}


