#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTEX 30

typedef struct graphNode {
    int vertex;
    struct graphNode* link;
} GraphNode;

typedef struct {
    int n;
    GraphNode* adjList[MAX_VERTEX];
} GraphType;

void createGraph(GraphType* g) {
    int v;
    g->n = 0;
    for (v = 0; v < MAX_VERTEX; v++)
        g->adjList[v] = NULL;
}

void insertVertex(GraphType* g, int v) {
    if (((g->n) + 1) > MAX_VERTEX) {
        printf("\n 그래프 정점의 개수를 초과하였습니다!");
        return;
    }
    g->n++;
}

void insertEdge(GraphType* g, int u, int v) {
    GraphNode* node;
    if (u >= g->n || v >= g->n) {
        printf("\n 그래프에 없는 정점입니다!");
        return;
    }
    node = (GraphNode*)malloc(sizeof(GraphNode));
    node->vertex = v;
    node->link = g->adjList[u];
    g->adjList[u] = node;
}

void print_adjList(GraphType* g) {
    int i;
    GraphNode* p;
    for (i = 0; i < g->n; i++) {
        printf("\n정점 %c의 인접리스트 ", i + 65);
        p = g->adjList[i];
        while (p != NULL) {
            printf(" -> %c", p->vertex + 65); // 정점 0~4를 A~D로 출력
            p = p->link;
        }
    }
}

int main() {
    int i;
    GraphType* G;
    G = (GraphType*)malloc(sizeof(GraphType));

    createGraph(G);
    for (i = 0; i < 4; i++)
        insertVertex(G, i);
    insertEdge(G, 0, 1);
    insertEdge(G, 1, 3);
    insertEdge(G, 1, 2);
    insertEdge(G, 2, 3);
    insertEdge(G, 2, 1);
    insertEdge(G, 3, 2);
    insertEdge(G, 3, 1);

    printf("<G의 인접 리스트>");
    print_adjList(G);

    return 0;
}