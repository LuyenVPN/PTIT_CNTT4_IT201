#include <math.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int vertex;
    struct Node* next;
}Node;

Node *createNode(int vertex) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}
typedef struct Graph {
    int V;
    Node **matrix;
}Graph;

Graph *createGraph(int V) {
    Graph* graph= (Graph*)malloc(sizeof(Graph));
    graph->V=V;
    graph->matrix=(Node **)malloc(V * sizeof(Node *));
    for (int i=0; i< V; i++) {
        graph->matrix[i]=NULL;
    }
    return graph;
}
void addEdge(Graph *graph, int src, int dest) {
    Node* newNode= createNode(dest);
    newNode->next=graph->matrix[src];
    graph->matrix[src]=newNode;

    newNode=createNode(src);
    newNode->next=graph->matrix[dest];
    graph->matrix[dest]=newNode;
}
void printGraph(Graph *graph) {
    for (int i=0; i< graph->V; i++) {
        Node* temp= graph->matrix[i];
        printf("%d:",i);
        while (temp) {
            printf("%d -> ",temp->vertex);
            temp=temp->next;
        }
        printf("Null\n");
    }
}
int main() {
    int n;
    int matrix[100][100];
    do {
        printf("Nhap so dinh (0 < n < 100): ");
        scanf("%d", &n);
    } while (n <= 0 || n >= 100);
    printf("Nhap ma tran ke (%dx%d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            do {
                printf("A[%d][%d] = ", i, j);
                scanf("%d", &matrix[i][j]);
                if (matrix[i][j] != 0 && matrix[i][j] != 1)
                    printf("Chi duoc nhap 0 hoac 1. Nhap lai.\n");
            } while (matrix[i][j] != 0 && matrix[i][j] != 1);
        }
    }
    Graph* graph = createGraph(n);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (matrix[i][j] == 1) {
                addEdge(graph, i, j);
            }
        }
    }
    printGraph(graph);
    return 0;
}