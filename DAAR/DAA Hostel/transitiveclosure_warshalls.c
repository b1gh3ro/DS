 
#include <stdio.h> 
 
#define MAX_VERTICES 100 
 
void printMatrix(int n, int matrix[MAX_VERTICES][MAX_VERTICES]) { 
    printf("Transitive Closure Matrix:\n"); 
    printf("   "); 
    for (int i = 0; i < n; i++) { 
        printf("%d ", i); 
    } 
    printf("\n"); 
 
    for (int i = 0; i < n; i++) { 
        printf("%d| ", i); 
        for (int j = 0; j < n; j++) { 
            printf("%d ", matrix[i][j]); 
        } 
        printf("\n"); 
    } 
} 
 
void transitiveClosure(int n, int graph[MAX_VERTICES][MAX_VERTICES]) { 
    int closure[MAX_VERTICES][MAX_VERTICES]; 
 
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < n; j++) { 
            closure[i][j] = graph[i][j]; 
        } 
    } 
 
    for (int k = 0; k < n; k++) { 
        for (int i = 0; i < n; i++) { 
            for (int j = 0; j < n; j++) { 
                if (closure[i][j] == 0 && closure[i][k] && closure[k][j]) { 
                    closure[i][j] = 1; 
                } 
            } 
        } 
    } 
 
    printMatrix(n, closure); 
} 
 
int main() { 
    int n, edges, src, dest; 
 
 
 
    printf("Enter the number of vertices: "); 
    scanf("%d", &n); 
 
    int graph[MAX_VERTICES][MAX_VERTICES]; 
 
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < n; j++) { 
            graph[i][j] = 0; 
        } 
    } 
 
    printf("Enter the number of edges: "); 
    scanf("%d", &edges); 
 
    for (int i = 0; i < edges; i++) { 
        printf("Enter edge %d (source destination): ", i + 1); 
        scanf("%d %d", &src, &dest); 
        graph[src][dest] = 1; 
    } 
 
    transitiveClosure(n, graph); 
 
    return 0; 
} 
