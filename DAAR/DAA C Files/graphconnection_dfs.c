#include <stdio.h> 
#include <stdlib.h> 
 
#define MAX 100 
 
int adj[MAX][MAX], visited[MAX], n; 
 
void dfs(int v) { 
    visited[v] = 1; 
    for (int i = 0; i < n; i++) { 
        if (adj[v][i] == 1 && visited[i] == 0) { 
            dfs(i); 
        } 
    } 
} 
 
int isConnected() { 
    for (int i = 0; i < n; i++) { 
        visited[i] = 0; 
    } 
 
    dfs(0);   
 
    for (int i = 0; i < n; i++) { 
        if (visited[i] == 0) { 
            return 0;   
        } 
    } 
    return 1;   
} 
 
int main() { 
    printf("Enter number of nodes: "); 
    scanf("%d", &n); 
 
    printf("Enter adjacency matrix (0/1):\n"); 
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < n; j++) { 
            scanf("%d", &adj[i][j]); 
        } 
    } 
 
    if (n <= 0) { 
        printf("Invalid number of nodes.\n"); 
        return 1; 
    } 
 
 
    if (isConnected()) { 
        printf("The graph is connected.\n"); 
    } else { 
        printf("The graph is not connected.\n"); 
    } 
 
    return 0; 
} 