#include <stdio.h> 
#include <stdlib.h> 
 
struct Item { 
    int value, weight; 
    float ratio; 
}; 
 
int compare(const void *a, const void *b) { 
    struct Item *item1 = (struct Item *)a; 
    struct Item *item2 = (struct Item *)b; 
    if (item1->ratio < item2->ratio) return 1; 
    if (item1->ratio > item2->ratio) return -1; 
    return 0; 
} 
 
void fractionalKnapsack(int W, struct Item items[], int n) { 
 
    qsort(items, n, sizeof(struct Item), compare); 
 
    int curWeight = 0; 
    float finalValue = 0.0; 
    printf("Included items:\n"); 
    printf("Value  Weight  Fraction\n"); 
 
    for (int i = 0; i < n; i++) { 
        if (curWeight + items[i].weight <= W) { 
            curWeight += items[i].weight; 
            finalValue += items[i].value; 
            printf("%5d  %6d  1.0000\n", items[i].value, items[i].weight); 
        } else { 
            int remaining = W - curWeight; 
            finalValue += items[i].value * ((float)remaining / items[i].weight); 
            printf("%5d  %6d  %.4f\n", items[i].value, items[i].weight, (float)remaining / items[i].weight); 
            break; 
        } 
    } 
 
    printf("\nMaximum value in Knapsack = %.2f\n", finalValue); 
} 
 
int main() { 
    int n, W; 
     
    printf("Enter the number of items: "); 
    scanf("%d", &n); 
 
 
    printf("Enter the capacity of knapsack: "); 
    scanf("%d", &W); 
 
    struct Item *items = (struct Item *)malloc(n * sizeof(struct Item)); 
 
    for (int i = 0; i < n; i++) { 
        printf("Enter value and weight for item %d: ", i + 1); 
        scanf("%d %d", &items[i].value, &items[i].weight); 
        items[i].ratio = (float)items[i].value / items[i].weight; 
    } 
 
    fractionalKnapsack(W, items, n); 
 
    free(items); 
 
    return 0; 
}