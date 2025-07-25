#include <stdlib.h>
#include <stdio.h>

typedef struct Graph {
    int V;
    int **matrix;
}Graph;
Graph *createGraph(int V) {
    Graph *graph= (Graph*)malloc(sizeof(Graph));
    graph->V=V;
    graph->matrix=(int **)malloc(V* sizeof(int*));
    for (int i=0; i<V;i++) {
        graph->matrix[i]=(int*)calloc(V,sizeof(int));
    }
    return graph;
}
void addgraph(Graph *graph, int src, int dest) {
    graph->matrix[src][dest]= graph->matrix[dest][src]=1;
}
void printGraph(Graph *graph) {
    for (int i=0; i<graph->V; i++) {
        for (int j=0; j<graph->V;j++) {
            printf("%d ",graph->matrix[i][j]);
        }
        printf("\n");
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
        addgraph(graph,src,dest);
    }
    printGraph(graph);
    return 0;
}