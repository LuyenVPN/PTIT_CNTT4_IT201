#include <stdio.h>
#include<stdlib.h>
typedef  struct  Graph {
    int V;//so dinh ben trong do thi
    int **matrix;//mang 2 chieu dai dien cho do th
}Graph;
//xay dung ham khoi tao do thi
Graph *createGraph(int V) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->V = V;
    //cap phat bo nho cho mang 2 chieu
    graph->matrix = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++) {
        //cap phat bo nho cho tung mang con trong mang 2 chieu
        graph->matrix[i] = (int *)calloc(V ,sizeof(int));
    }
    return graph;
}
//xay dung ham ket noi 2 dinh
void addEdge(Graph *graph,int src, int dest) {
    graph->matrix[src][dest] = 1;
    graph->matrix[dest][src] = 1;
}
//in ma tran
void printMatrix(Graph *graph) {
    for (int i = 0; i < graph->V; i++) {
        for (int j = 0; j < graph->V; j++) {
            printf("%d ",graph->matrix[i][j]);
        }
        printf("\n");
    }
}
void printGraph(Graph *graph) {
    for (int i = 0; i < graph->V; i++) {
        printf("%d: ",i);
        for (int j = 0; j < graph->V; j++) {
            if (graph->matrix[i][j] == 1) {
                printf("%d ",j);
            }
        }
        printf("\n");
    }
}
//duyet dfs
void DFSUtil(Graph *graph, int src, int *visited) {
    //b1:in ra dinh src va danh dau da di qua
    printf("%d ", src);
    visited[src] = 1;
    //b2:kiem tra cac duong co the di tu dinh src
    //su dung vong lap voi tat ca dinh trong do thi
    for (int i = 0; i < graph->V; i++) {
        //b3 neu co duong (matrix[src][i]=1;
        //va dinh tiep theo chua duoc di qua
        if (graph->matrix[src][i] == 1 && visited[i] == 0) {
            //b4: di den tinh tiep theo va thuc hien lai toan bo logic
            DFSUtil(graph, i, visited);
        }

    }
}

void DFS(Graph *graph, int src) {
    int *visited = (int *)calloc(graph->V, sizeof(int));
    printf("bat  dau duyet DFS tu dinh %d: ", src);
    DFSUtil(graph, src, visited);
    printf("\n");
    free(visited);

}

int main(void) {
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
    printMatrix(graph);
    int star;
    printf("star:");
    scanf("%d",&star);
    DFS(graph,star);
    return 0;
}