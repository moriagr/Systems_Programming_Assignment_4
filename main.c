#include "algo.h"
#include "nodes.h"
#include "edges.h"
#include "graph.h"
#include <stdio.h>
#include <ctype.h>

int main() {

    pnode root = NULL;
    char command;
    command = getchar();

    // Create the graph
    while (command == 'A' ||
            command == 'B' ||
            command == 'D' ||
            command == 'S' ||
            command == 'T') {

        if (command == 'A') {
            if(root != NULL){
                deleteGraph_cmd(&root);
            }
            root = NULL;
            build_graph_cmd(&root);

        }else if (command == 'B') {
            insert_node_cmd(&root);

        } else if (command == 'D') {
            delete_node_cmd(&root);

        } else if (command == 'S') {
            shortsPath_cmd(&root);

        } else if (command == 'T') {
            TSP_cmd(&root);
        }

        if(scanf(" %c", &command) != 1){
            break;
        }
        printf("%c\n", command);
    }

    printGraph_cmd(root);
}



// int main() {
//     int arr[] = {1, 2, 3};
//     int n = sizeof(arr) / sizeof(arr[0]);

//     permute(arr, 0, n - 1);

//     return 0;
// }