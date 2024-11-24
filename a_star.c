#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define INF 9999

int graph[MAX][MAX], visited[MAX], gCost[MAX], fCost[MAX], n;
int heuristic[MAX], goal;

int findMinFcost() {
    int min = INF, minIndex = -1;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && fCost[i] < min) {
            min = fCost[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void AStar(int start) {
    printf("A* Path: ");
    visited[start] = 1;
    gCost[start] = 0;
    fCost[start] = gCost[start] + heuristic[start];
    printf("%d ", start);

    while (start != goal) {
        int nextNode = findMinFcost();
        if (nextNode == -1) {
            printf("\nNo Path Found.\n");
            return;
        }
        printf("-> %d ", nextNode);
        visited[nextNode] = 1;
        gCost[nextNode] = gCost[start] + graph[start][nextNode];
        fCost[nextNode] = gCost[nextNode] + heuristic[nextNode];
        start = nextNode;
    }
    printf("\nGoal reached: %d\n", goal);
}

int main() {
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    
    printf("Enter the adjacency matrix (use %d for infinity):\n", INF);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    
    printf("Enter heuristic values for each node:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &heuristic[i]);
    }

    printf("Enter goal node: ");
    scanf("%d", &goal);

    int start;
    printf("Enter start node: ");
    scanf("%d", &start);

    AStar(start);
    return 0;
}