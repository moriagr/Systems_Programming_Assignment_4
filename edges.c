#include "edges.h"
#include <stdlib.h>

static Edge* head = NULL;

void addEdge(int from, int to, char weight) {
    Edge* edge = malloc(sizeof(Edge));
    edge->from = from;
    edge->to = to;
    edge->weight = weight;
}

void deleteEdge(Node *vertex) {
    Edge* edge = head;
    if (edge->from == vertex) {
        head = edge->next;
        free(edge);
        return;
    }
    while (edge->next != NULL) {
        if (edge->next->vertex == vertex) {
            Edge* to_delete = edge->next;
            edge->next = to_delete->next;
            free(to_delete);
            return;
        }
        edge = edge->next;
    }
}

