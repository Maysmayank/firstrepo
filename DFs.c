#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    int numVertices;
    struct Node** adjLists;
    int* visited;
};

struct Node* createNode(int vertex);
struct Graph* createGraph(int vertices);
void addEdge(struct Graph* graph, int src, int dest);
void dfs(struct Graph* graph, int startVertex);
void dfsTraversal(struct Graph* graph, int vertex);

struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adjLists = (struct Node**)malloc(vertices * sizeof(struct Node*));
    graph->visited = (int*)malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}

void dfs(struct Graph* graph, int startVertex) {
    graph->visited[startVertex] = 1;
    printf("DFS: ");
    dfsTraversal(graph, startVertex);
    printf("\n");
}

void dfsTraversal(struct Graph* graph, int vertex) {
    printf("%d ", vertex);

    struct Node* temp = graph->adjLists[vertex];
    while (temp != NULL) {
        int adjVertex = temp->vertex;
        if (!graph->visited[adjVertex]) {
            graph->visited[adjVertex] = 1;
            dfsTraversal(graph, adjVertex);
        }
        temp = temp->next;
    }
}

int main() {
    struct Graph* graph = createGraph(6);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 4);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);

    int startVertex = 0;
    dfs(graph, startVertex);

    return 0;
}
