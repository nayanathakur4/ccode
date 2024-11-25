#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_VERTICES 100  // Maximum number of vertices

// Function to check if coloring a vertex with a given color is safe
bool isSafe(int v, int graph[MAX_VERTICES][MAX_VERTICES], int color[], int c, int V) {
    for (int i = 0; i < V; i++) {
        if (graph[v][i] && color[i] == c) {
            return false;  // Adjacent vertex has the same color
        }
    }
    return true;
}

// Recursive function to solve the graph coloring problem
bool graphColoringUtil(int graph[MAX_VERTICES][MAX_VERTICES], int m, int color[], int v, int V) {
    if (v == V) {  // All vertices are assigned a color
        return true;
    }

    for (int c = 1; c <= m; c++) {  // Try all colors
        if (isSafe(v, graph, color, c, V)) {
            color[v] = c;  // Assign color c to vertex v

            // Recur for the next vertex
            if (graphColoringUtil(graph, m, color, v + 1, V)) {
                return true;
            }

            // Backtrack
            color[v] = 0;
        }
    }

    return false;  // No solution exists
}

// Function to solve the graph coloring problem
bool graphColoring(int graph[MAX_VERTICES][MAX_VERTICES], int m, int V) {
    int color[MAX_VERTICES] = {0};

    if (!graphColoringUtil(graph, m, color, 0, V)) {
        printf("Solution does not exist\n");
        return false;
    }

    // Print the solution
    printf("Solution Exists: Following are the assigned colors:\n");
    for (int i = 0; i < V; i++) {
        printf("Vertex %d -> Color %d\n", i, color[i]);
    }
    return true;
}

// Main function
int main() {
    int V;  // Number of vertices
    int m;  // Number of colors

    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    if (V > MAX_VERTICES) {
        printf("The maximum number of vertices allowed is %d.\n", MAX_VERTICES);
        return -1;
    }

    int graph[MAX_VERTICES][MAX_VERTICES];

    printf("Enter the adjacency matrix of the graph (size %dx%d):\n", V, V);
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the number of colors: ");
    scanf("%d", &m);

    graphColoring(graph, m, V);

    return 0;
}
// Enter the number of vertices: 4
// Enter the adjacency matrix of the graph (size 4x4):
// 0 1 1 0
// 1 0 1 1
// 1 1 0 1
// 0 1 1 0
// Enter the number of colors: 3
// Solution Exists: Following are the assigned colors:
// Vertex 0 -> Color 1
// Vertex 1 -> Color 2
// Vertex 2 -> Color 3
// Vertex 3 -> Color 1