#ifndef GRAPH_
#define GRAPH_

typedef struct GRAPH_NODE_ *pnode;

typedef struct edge_ {
    int weight;
    pnode endpoint;
    struct edge_ *next;
} edge, *pedge;


typedef struct GRAPH_NODE_ {
    int node_num;
    pedge edges;
    struct GRAPH_NODE_ *next;
    int d;
    int visited;
} node, *pnode;

void build_graph_cmd(pnode *head);
void insert_node(pnode *head, int end_point);
void add_node(pnode *head, pnode node_to_add);
void delete_edge(pedge *edges, int edge_to_delete);
pnode find_node(pnode *head, int node_num);
void insert_node_cmd(pnode *head);
void delete_node_cmd(pnode *pnode1);
void delete_node(pnode *head, int node_to_delete);
void delete_edges_cmd(pedge *root);
void printGraph_cmd(pnode head); //for self debug
void deleteGraph_cmd(pnode* head);
void shortsPath_cmd(pnode *head);
int dijsktra(pnode *head, int start, int end);
pnode extract_min(pnode *head);
void relax(pnode pnode1, pedge pedge1);
void TSP_cmd(pnode *head);
void permute(pnode *head, int *permutation_arr, int start, int end, int *min_path);

#endif
