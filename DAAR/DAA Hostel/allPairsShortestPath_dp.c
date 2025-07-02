#include <stdio.h> 
 
#define MAX 20 
#define INF 99999 
 
void printSolution(int dist[MAX][MAX], int n) { 
    printf("Shortest distances between every pair of vertices:\n"); 
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < n; j++) { 
            if (dist[i][j] == INF) 
                printf("%7s", "INF"); 
            else 
                printf("%7d", dist[i][j]); 
        } 
        printf("\n"); 
    } 
} 
 
void floydWarshall(int graph[MAX][MAX], int n) { 
    int dist[MAX][MAX]; 
 
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) 
            dist[i][j] = graph[i][j]; 
 
    for (int k = 0; k < n; k++) { 
        for (int i = 0; i < n; i++) { 
            for (int j = 0; j < n; j++) { 
                if (dist[i][k] + dist[k][j] < dist[i][j]) 
                    dist[i][j] = dist[i][k] + dist[k][j]; 
            } 
        } 
    } 
 
    printSolution(dist, n); 
} 
 
int main() { 
    int n; 
    int graph[MAX][MAX]; 
 
    printf("Enter the number of vertices: "); 
    scanf("%d", &n); 
 
    printf("Enter the adjacency matrix of the graph (use %d to represent infinity):\n", INF); 
 
 
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) 
            scanf("%d", &graph[i][j]); 
 
    floydWarshall(graph, n); 
    return 0; 
}
