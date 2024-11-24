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


    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}


void dfs(struct Graph* graph, int vertex) {
    struct Node* adjList = graph->adjLists[vertex];
    struct Node* temp = adjList;


    graph->visited[vertex] = 1;
    printf("%d ", vertex);


    while (temp != NULL) {
        int connectedVertex = temp->vertex;


        if (graph->visited[connectedVertex] == 0) {
            dfs(graph, connectedVertex);
        }
        temp = temp->next;
    }
}


int main() {
    int vertices, edges, src, dest, startVertex;


    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);


    struct Graph* graph = createGraph(vertices);


    printf("Enter the number of edges: ");
    scanf("%d", &edges);


    for (int i = 0; i < edges; i++) {
        printf("Enter edge (source destination): ");
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }


    printf("Enter the starting vertex for DFS: ");
    scanf("%d", &startVertex);


    printf("DFS starting from vertex %d:\n", startVertex);
    dfs(graph, startVertex);


    return 0;
}
