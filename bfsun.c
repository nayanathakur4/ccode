#include <stdio.h>
#include <stdlib.h>


#define MAX 100


struct Node {
    int vertex;
    struct Node* next;
};


struct Graph {
    int numVertices;
    struct Node** adjLists;
    int* visited;
};


struct Queue {
    int items[MAX];
    int front;
    int rear;
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


struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}


int isEmpty(struct Queue* q) {
    if (q->rear == -1)
        return 1;
    else
        return 0;
}


void enqueue(struct Queue* q, int value) {
    if (q->rear == MAX - 1)
        printf("\nQueue Full\n");
    else {
        if (q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}


int dequeue(struct Queue* q) {
    int item;
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        item = -1;
    } else {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            q->front = q->rear = -1;
        }
    }
    return item;
}


void bfs(struct Graph* graph, int startVertex) {
    struct Queue* q = createQueue();


    graph->visited[startVertex] = 1;
    enqueue(q, startVertex);


    while (!isEmpty(q)) {
        int currentVertex = dequeue(q);
        printf("%d ", currentVertex);


        struct Node* temp = graph->adjLists[currentVertex];


        while (temp) {
            int adjVertex = temp->vertex;


            if (graph->visited[adjVertex] == 0) {
                graph->visited[adjVertex] = 1;
                enqueue(q, adjVertex);
            }
            temp = temp->next;
        }
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


    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &startVertex);


    printf("BFS starting from vertex %d:\n", startVertex);
    bfs(graph, startVertex);


    return 0;
}


