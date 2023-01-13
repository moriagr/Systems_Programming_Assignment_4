#include "graph.h"
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <ctype.h>

pnode find_node(pnode *head, int num_of_node)
{
    if (head == NULL || *head == NULL)
    {
        printf("head pointer is null\n");
        return NULL;
    }
    pnode _node = NULL;
    pnode tmpHead = *head;
    while (tmpHead != NULL)
    {
        if (tmpHead->node_num == num_of_node)
        {
            _node = tmpHead;
            break;
        }
        tmpHead = tmpHead->next;
    }
    return _node;
}

void insert_node(pnode *head, int end_point)
{
    pnode find = find_node(head, end_point);
    if (find == NULL)
    {
        node *next_node = (pnode)malloc(sizeof(node));
        next_node->node_num = end_point;
        next_node->next = NULL;
        find = next_node;
    }
}

void add_node(pnode *head, pnode node_to_add)
{
    if ((*head)->node_num == INT_MAX)
    {
        (*head) = node_to_add;
        return;
    }
    pnode curr = *head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = node_to_add;
}

void add_edges(pnode pnode1, pnode *head)
{
    int end_point, weight;
    pedge root_edge = (pedge)malloc(sizeof(edge));
    pedge next_edge = root_edge;
    int flag = 0;
    while (scanf(" %d %d", &end_point, &weight) == 2)
    {
        pedge _edge = (pedge)malloc(sizeof(edge));
        if (_edge == NULL)
        {
            printf("Not enough memory!");
            exit(0);
        }
        // insert_node(head, end_point);
        pnode find = NULL;
        find = find_node(head, end_point);
        if (find == NULL)
        {
            find = (pnode)malloc(sizeof(node));
            if (find == NULL)
            {
                printf("Not enough memory!");
                exit(0);
            }
            find->node_num = end_point;
            find->next = NULL;
            // find = next_node;
            add_node(head, find);
        }
        _edge->endpoint = find;
        _edge->weight = weight;
        _edge->next = NULL;
        if (flag == 0)
        {
            pnode1->edges = _edge;
        }
        else
        {
            next_edge->next = _edge;
        }
        flag = 1;
        next_edge = _edge;
    }
}

void build_graph_cmd(pnode *head)
{

    int num_of_nodes;
    scanf(" %d", &num_of_nodes);
    if (num_of_nodes < 1)
    {
        return;
    }
    // *head = malloc(sizeof(struct GRAPH_NODE_));
    // *head = (pnode)malloc(num_of_nodes * sizeof(struct GRAPH_NODE_));
    pnode temp_node = NULL;
    temp_node = (pnode)malloc(sizeof(node));
    if (temp_node == NULL)
    {
        printf("Not enough memory!");
        exit(0);
    }
    temp_node->node_num = INT_MAX;
    temp_node->next = NULL;
    *head = temp_node;
    for (int i = 0; i < num_of_nodes; i++)
    {
        char nChar;
        if (scanf(" %c", &nChar) != 1)
        {
            exit(0);
        }
        int vertex;
        if (scanf(" %d", &vertex) != 1)
        {
            exit(0);
        }

        pnode _node = find_node(head, vertex);
        if (_node == NULL)
        {
            pnode new_node = NULL;
            new_node = (pnode)malloc(sizeof(node));
            if (new_node == NULL)
            {
                printf("Not enough memory!");
                exit(0);
            }
            new_node->edges = NULL;
            new_node->node_num = vertex;
            new_node->next = NULL;
            _node = new_node;
            add_node(head, _node);
        }

        add_edges(_node, head);

        if (i == 0)
        {
            *head = _node;
        }
    }
}

void insert_node_cmd(pnode *head)
{
    int vertex;
    scanf(" %d", &vertex);
    pnode find = find_node(head, vertex);

    if (find == NULL)
    {
        node *next_node = (pnode)malloc(sizeof(node));
        next_node->node_num = vertex;
        find = next_node;
        next_node->next = NULL;

        add_edges(find, head);
        pnode next_ = *head;
        while (next_->next != NULL)
        {
            next_ = next_->next;
        }
        next_->next = find;
    }
    else
    {
        if (find->edges != NULL)
            delete_edges_cmd(&find->edges);
        add_edges(find, head);
    }
}

void delete_node_cmd(pnode *head)
{
    int node_to_delete;
    scanf(" %d", &node_to_delete);
    void delete_node(pnode * head, int node_to_delete);
}

void delete_node(pnode *head, int node_to_delete)
{
    pnode currentNode;
    if ((*head)->node_num == node_to_delete)
    {
        delete_edges_cmd(&(*head)->edges);
        currentNode = *head;
        *head = (*head)->next;
        free(currentNode->next);
        // currentNode->next = NULL;
    }

    pnode prev = *head;
    pnode curr;
    while (prev->next != NULL)
    {
        curr = prev->next;
        if (curr->node_num == node_to_delete)
        {
            delete_edges_cmd(&curr->edges);
            currentNode = curr;
            prev->next = curr->next;
            if (curr->next != NULL)
            {
                curr = curr->next;
            }
            currentNode->next = NULL;
        }
        delete_edge(&prev->edges, node_to_delete);
        prev = prev->next;
    }
    currentNode->d = 0;
    currentNode->visited = 0;
    currentNode->node_num = -1;
    delete_edge(&prev->edges, node_to_delete);
    free(currentNode);
}

void delete_edge(pedge *edges, int edge_to_delete)
{
    pedge root;

    if ((*edges) == NULL)
    {
        return;
    }

    if ((*edges)->endpoint->node_num == edge_to_delete)
    {
        root = *edges;
        *edges = (*edges)->next;
        free(root);
    }

    pedge prev = *edges;
    pedge curr;
    while (prev->next != NULL)
    {
        curr = prev->next;
        if (curr->endpoint->node_num == edge_to_delete)
        {
            prev->next = curr->next;
            free(curr);
        }
        if (prev->next != NULL)
        {
            prev = prev->next;
        }
    }
}

void delete_edges_cmd(pedge *root)
{
    pedge current = *root;
    pedge next;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }

    *root = NULL;
}

void printGraph_cmd(pnode head)
{
    pnode current = head;
    while (current != NULL)
    {
        printf("Node %d: ", current->node_num);
        pedge current_edge = current->edges;
        while (current_edge != NULL)
        {
            printf("%d (weight: %d) ", current_edge->endpoint->node_num, current_edge->weight);
            current_edge = current_edge->next;
        }
        printf("\n");
        current = current->next;
    }
}

// void deleteGraph_cmd(pnode *head)
// {
//     pnode current = *head;
//     pnode next;
//     // pnode currentNode;

//     while (current != NULL)
//     {
//         pedge edge_current = NULL;
//         // delete_edges_cmd(&edges);
//         edge_current = current->edges;
//         pedge next_edge;

//         while (edge_current != NULL)
//         {
//             next_edge = edge_current->next;
//             free(edge_current);
//             edge_current = next_edge;
//         }
//         next = current->next;
//         // delete_node(&current, current->node_num);
//         // free(current);
//         // current = next;

//         // delete_edges_cmd(&current->edges);
//         // currentNode = *head;
//         // *head = (*head)->next;
//         // if(current->next!=)
//         // delete_edge(&current->edges, current->node_num);
//         free(current);
//         // current->edges = NULL;
//         // current->node_num=-1;
//         // current->next=NULL;

//         current = next;

//         // currentNode->next = NULL;
//     }
//     // free((*head));
//     head = NULL;
// }

void deleteGraph_cmd(pnode *head)
{
    pnode current_node = *head;

    while (current_node != NULL)
    {
        pedge edge_current = current_node->edges;

        while (edge_current != NULL)
        {
            pedge free_edge = edge_current;
            edge_current = edge_current->next;
            free(free_edge);
        }
        pnode free_node = current_node;
        current_node = current_node->next;
        free(free_node);
    }
    free(current_node);
}

pnode extract_min(pnode *head)
{
    pnode curr = *head;
    pnode min = *head;
    while (curr != NULL)
    {
        if (min->d > curr->d && curr->visited == 0)
        {
            min = curr;
        }
        curr = curr->next;
    }
    min->visited = 1;
    return min;
}

// e = (u,v)
void relax(pnode u, pedge e)
{
    pnode v = e->endpoint;
    if (v->d == u->d)
    {
        return;
    }
    if (v->d > u->d + e->weight)
    {
        v->d = u->d + e->weight;
    }
}

void shortsPath_cmd(pnode *head)
{
    int start, end;
    scanf(" %d %d", &start, &end);

    printf("Dijsktra shortest path: %d \n", dijsktra(head, start, end));
}

int dijsktra(pnode *head, int start, int end)
{
    // initialize distances
    pnode graph_node = *head;

    while (graph_node != NULL)
    {
        if (graph_node->node_num == start)
        {
            graph_node->d = 0;
        }
        else
        {
            graph_node->d = INT_MAX;
        }
        graph_node->visited = 0;
        graph_node = graph_node->next;
    }

    graph_node = *head;
    while (graph_node != NULL)
    {
        pnode min = extract_min(head);

        pedge min_edge = min->edges;
        while (min_edge != NULL)
        {
            relax(min, min_edge);
            min_edge = min_edge->next;
        }
        graph_node = graph_node->next;
    }

    pnode endNode = find_node(head, end);

    if (endNode->d == INT_MAX)
    {
        endNode->d = -1;
    }
    return endNode->d;
}

void TSP_cmd(pnode *head)
{
    int num_of_vertices;
    scanf(" %d", &num_of_vertices);
    if (num_of_vertices < 1)
    {
        return;
    }
    // int to_visit[num_of_vertices];
    int *to_visit = (int *)malloc(num_of_vertices * sizeof(int));

    for (int i = 0; i < num_of_vertices; i++)
    {
        scanf(" %d", &to_visit[i]);
    }

    int min_path = INT_MAX;
    permute(head, to_visit, 0, num_of_vertices - 1, &min_path);
    if (min_path == INT_MAX)
    {
        min_path = -1;
    }
    free(to_visit);
    printf("TSP shortest path: %d \n", min_path);
}

void permute(pnode *head, int *permutation_arr, int start, int end, int *min_path)
{
    if (start == end)
    {
        int short_path = INT_MAX;
        for (int i = 0; i < end; i++)
        {
            if (find_node(head, permutation_arr[i])->edges == NULL)
            {
                short_path = INT_MAX;
                break;
            }

            int from = permutation_arr[i];
            int to = permutation_arr[i + 1];
            int short_path_dijsktra = dijsktra(head, from, to);

            if (short_path_dijsktra >= *min_path || short_path_dijsktra == -1)
            {
                return;
            }

            if (short_path == INT_MAX)
            {
                short_path = 0;
            }
            short_path += short_path_dijsktra;
        }
        if (short_path != -1 && short_path < *min_path)
        {
            *min_path = short_path;
        }
    }
    else
    {
        for (int i = start; i <= end; i++)
        {
            // Swap the current element with the start element
            int temp = permutation_arr[start];
            permutation_arr[start] = permutation_arr[i];
            permutation_arr[i] = temp;

            // Recurse on the sub-array
            permute(head, permutation_arr, start + 1, end, min_path);

            // Swap the elements back to restore the original array
            permutation_arr[i] = permutation_arr[start];
            permutation_arr[start] = temp;
        }
    }
}
