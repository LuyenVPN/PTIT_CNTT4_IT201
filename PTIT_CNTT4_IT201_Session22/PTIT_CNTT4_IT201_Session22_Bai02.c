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
    int n,src,dest,count=0;
    printf("N:");
    scanf("%d",&n);
    Graph *graph=createGraph(n);
    printf("Nhap so canh muon nhap:");
    scanf("%d", &count);
    int maxEdges = n * (n - 1) / 2;
    if (count>maxEdges) {
        printf("khong canh hop le");
        return 0;
    }
    for (int i=0; i< count; i++) {
        printf("Nut 1 cua canh %d la:",i+1);
        scanf("%d", &src);
        printf("Nut 2 cua canh %d la:",i+1);
        scanf("%d", &dest);
        if (src<0|| src>=n || dest <0|| dest>=n|| src==dest) {
            printf("khong hop le");
            return 0;
        }
        addEdge(graph,src,dest);
    }
    printGraph(graph);
    return 0;
}