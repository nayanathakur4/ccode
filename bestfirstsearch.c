#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define INF 9999

int graph[MAX][MAX], visited[MAX], n;
int heuristic[MAX], goal;

int findMinHeuristic() {
    int min = INF, minIndex = -1;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && heuristic[i] < min) {
            min = heuristic[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void bestFirstSearch(int start) {
    printf("Best First Search Path: ");
    visited[start] = 1;
    printf("%d ", start);

    while (start != goal) {
        int nextNode = findMinHeuristic();
        if (nextNode == -1) {
            printf("\nNo Path Found.\n");
            return;
        }
        printf("-> %d ", nextNode);
        visited[nextNode] = 1;
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

    bestFirstSearch(start);
    return 0;
}
