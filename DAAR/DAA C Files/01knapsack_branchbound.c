#include <stdio.h> 
#include <stdlib.h> 
 
#define MAX_ITEMS 10 
 
struct Item { 
    int weight; 
    int profit; 
    float ratio; 
}; 
 
int numItems, capacity; 
struct Item items[MAX_ITEMS]; 
int maxProfit = 0; 
int finalSet[MAX_ITEMS]; 
 
void knapsack(int currentWeight, int currentProfit, int level, int include[]) { 
    if (level == numItems) { 
        if (currentWeight <= capacity && currentProfit > maxProfit) { 
            maxProfit = currentProfit; 
            for (int i = 0; i < numItems; i++) { 
                finalSet[i] = include[i]; 
            } 
        } 
        return; 
    } 
 
    float upperBound = currentProfit; 
    int remainingWeight = capacity - currentWeight; 
    int i = level; 
    while (i < numItems && remainingWeight >= items[i].weight) { 
        remainingWeight -= items[i].weight; 
        upperBound += items[i].profit; 
        i++; 
    } 
    if (i < numItems) { 
        upperBound += (float)remainingWeight / items[i].weight * items[i].profit; 
    } 
 
    if (upperBound <= maxProfit) { 
        return; 
    } 
 
    include[level] = 1; 
    knapsack(currentWeight + items[level].weight, currentProfit + items[level].profit, level + 1, 
include); 
 
 
    include[level] = 0; 
    knapsack(currentWeight, currentProfit, level + 1, include); 
} 
 
int main() { 
    printf("Enter the number of items: "); 
    scanf("%d", &numItems); 
 
    printf("Enter the capacity of knapsack: "); 
    scanf("%d", &capacity); 
 
    printf("Enter weight and profit of each item:\n"); 
    for (int i = 0; i < numItems; i++) { 
        printf("Item %d: ", i + 1); 
        scanf("%d %d", &items[i].weight, &items[i].profit); 
        items[i].ratio = (float)items[i].profit / items[i].weight; 
    } 
 
    int include[MAX_ITEMS] = {0}; 
    knapsack(0, 0, 0, include); 
 
    printf("Maximum profit: %d\n", maxProfit); 
    printf("Selected items (1 for selected, 0 for not selected):\n"); 
    for (int i = 0; i < numItems; i++) { 
        printf("%d ", finalSet[i]); 
    } 
    printf("\n"); 
 
    return 0; 
} 