#include <stdio.h> 
#include <limits.h> 
 
#define MAX_CITIES 10 
 
int n;  
int dist[MAX_CITIES][MAX_CITIES];  
int dp[MAX_CITIES][1 << MAX_CITIES];  
int path[MAX_CITIES][1 << MAX_CITIES];  
 
int tsp(int mask, int pos) { 
     
    if (mask == (1 << n) - 1) { 
        return dist[pos][0];  
    } 
     
    if (dp[pos][mask] != -1) { 
        return dp[pos][mask]; 
    } 
     
    int ans = INT_MAX; 
     
    for (int city = 0; city < n; city++) { 
        if (!(mask & (1 << city))) { 
            int newAns = dist[pos][city] + tsp(mask | (1 << city), city); 
            if (newAns < ans) { 
                ans = newAns; 
                path[pos][mask] = city;  
            } 
        } 
    } 
     
    return dp[pos][mask] = ans; 
} 
 
void printPath() { 
    int curr = 0, mask = 1; 
    printf("Path: 1 -> "); 
    for (int i = 0; i < n - 1; i++) { 
        int next = path[curr][mask]; 
        printf("%d -> ", next + 1); 
        mask |= (1 << next); 
        curr = next; 
    } 
 
 
    printf("1\n");  
} 
 
int main() { 
    printf("Enter the number of cities: "); 
    scanf("%d", &n); 
     
    printf("Enter the distance matrix (%d x %d):\n", n, n); 
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < n; j++) { 
            scanf("%d", &dist[i][j]); 
        } 
    } 
     
     
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < (1 << n); j++) { 
            dp[i][j] = -1; 
            path[i][j] = -1; 
        } 
    } 
     
    int ans = tsp(1, 0);  
     
    printf("Minimum cost of visiting all cities: %d\n", ans); 
    printPath(); 
     
    return 0; 
}
