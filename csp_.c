#include <stdio.h>
#include <string.h>

#define NUM_COLORS 3
#define NUM_VARIABLES 4
#define NUM_CONSTRAINTS 5

const char* COLORS[] = {"red", "green", "blue"};  // domain
const char* VARIABLES[] = {"A", "B", "C", "D"};    // variables


const char* CONSTRAINTS[][2] = {
    {"A", "B"},
    {"B", "C"},
    {"C", "D"},
    {"A", "D"},
    {"A", "C"}
};

int solve(int index, char solution[NUM_VARIABLES][10]);
int isValid(char solution[NUM_VARIABLES][10]);

int main() {
    char solution[NUM_VARIABLES][10] = {{0}};
    
    if (solve(0, solution)) {
        printf("Solution found:\n");
        for (int i = 0; i < NUM_VARIABLES; i++) {
            printf("%s: %s\n", VARIABLES[i], solution[i]);
        }
    } else {
        printf("No solution exists.\n");
    }
    
    return 0;
}

int solve(int index, char solution[NUM_VARIABLES][10]) {
    if (index == NUM_VARIABLES) {
        return 1;
    }

    for (int i = 0; i < NUM_COLORS; i++) {
        strcpy(solution[index], COLORS[i]);
        
        if (isValid(solution) && solve(index + 1, solution)) {
            return 1;
        }
        
        // Backtrack
        solution[index][0] = '\0'; // Reset to empty string
    }
    
    return 0;
}

int isValid(char solution[NUM_VARIABLES][10]) {
    for (int i = 0; i < NUM_CONSTRAINTS; i++) {
        const char* var1 = CONSTRAINTS[i][0];
        const char* var2 = CONSTRAINTS[i][1];
        
        int idx1 = -1, idx2 = -1;
        for (int j = 0; j < NUM_VARIABLES; j++) {
            if (strcmp(VARIABLES[j], var1) == 0) idx1 = j;
            if (strcmp(VARIABLES[j], var2) == 0) idx2 = j;
        }
        
        if (idx1 != -1 && idx2 != -1 && solution[idx1][0] != '\0' && solution[idx2][0] != '\0') {
            if (strcmp(solution[idx1], solution[idx2]) == 0) {
                return 0; // Invalid if colors are the same
            }
        }
    }
    return 1; 
}
