#include <stdio.h> 
 
#define MAX 100 
 
int max(int a, int b) { 
    return (a > b) ? a : b; 
} 
 
void knapsack(int W, int weights[], int values[], int n) { 
    int dp[MAX][MAX]; 
 
    for (int i = 0; i <= n; i++) { 
        for (int w = 0; w <= W; w++) { 
            if (i == 0 || w == 0) 
                dp[i][w] = 0; 
            else if (weights[i - 1] <= w) 
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]); 
            else 
                dp[i][w] = dp[i - 1][w]; 
        } 
    } 
 
    int maxValue = dp[n][W]; 
    printf("Maximum value that can be put in knapsack = %d\n", maxValue); 
 
    int w = W; 
    printf("Items included in the knapsack:\n"); 
    for (int i = n; i > 0 && maxValue > 0; i--) { 
        if (maxValue == dp[i - 1][w]) 
            continue; 
        else { 
            printf("Item %d (Value = %d, Weight = %d)\n", i, values[i - 1], weights[i - 1]); 
            maxValue -= values[i - 1]; 
            w -= weights[i - 1]; 
        } 
    } 
} 
 
int main() { 
    int n, W; 
    int weights[MAX], values[MAX]; 
 
    printf("Enter the number of items: "); 
    scanf("%d", &n); 
 
 
 
    printf("Enter the weight capacity of the knapsack: "); 
    scanf("%d", &W); 
 
    printf("Enter the value and weight of each item:\n"); 
    for (int i = 0; i < n; i++) { 
        printf("Item %d:\n", i + 1); 
        printf("Value = "); 
        scanf("%d", &values[i]); 
        printf("Weight = "); 
        scanf("%d", &weights[i]); 
    } 
 
    knapsack(W, weights, values, n); 
 
    return 0; 
} 
