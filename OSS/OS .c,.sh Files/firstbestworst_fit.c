#include <stdio.h>
#include <stdlib.h>

void firstFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];
    for (int i = 0; i < n; i++)
        allocation[i] = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                allocation[i] = j;
                blockSize[j] = -1; 
                break;
            }
        }
    }

    printf("\nFirst Fit Allocation:\n");
    printf("Process No.\tProcess Size\tBlock No.\n");
    for (int i = 0; i < n; i++) {
        printf(" %d\t\t%d\t\t", i + 1, processSize[i]);
        if (allocation[i] != -1) {
            printf("%d", allocation[i] + 1);
        } else {
            printf("Not Allocated");
        }
        printf("\n");
    }

    printf("Remaining Memory of Each Block:\n");
    for (int i = 0; i < m; i++) {
        if (blockSize[i] == -1) {
            printf("Block %d: Allocated\n", i + 1);
        } else {
            printf("Block %d: %d\n", i + 1, blockSize[i]);
        }
    }
}

void bestFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];
    for (int i = 0; i < n; i++)
        allocation[i] = -1;

    for (int i = 0; i < n; i++) {
        int bestIdx = -1;
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (bestIdx == -1 || blockSize[bestIdx] > blockSize[j]) {
                    bestIdx = j;
                }
            }
        }
        if (bestIdx != -1) {
            allocation[i] = bestIdx;
            blockSize[bestIdx] = -1; 
        }
    }

    printf("\nBest Fit Allocation:\n");
    printf("Process No.\tProcess Size\tBlock No.\n");
    for (int i = 0; i < n; i++) {
        printf(" %d\t\t%d\t\t", i + 1, processSize[i]);
        if (allocation[i] != -1) {
            printf("%d", allocation[i] + 1);
        } else {
            printf("Not Allocated");
        }
        printf("\n");
    }

    printf("Remaining Memory of Each Block:\n");
    for (int i = 0; i < m; i++) {
        if (blockSize[i] == -1) {
            printf("Block %d: Allocated\n", i + 1);
        } else {
            printf("Block %d: %d\n", i + 1, blockSize[i]);
        }
    }
}

void worstFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];
    for (int i = 0; i < n; i++)
        allocation[i] = -1;

    for (int i = 0; i < n; i++) {
        int worstIdx = -1;
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (worstIdx == -1 || blockSize[worstIdx] < blockSize[j]) {
                    worstIdx = j;
                }
            }
        }
        if (worstIdx != -1) {
            allocation[i] = worstIdx;
            blockSize[worstIdx] = -1; 
        }
    }

    printf("\nWorst Fit Allocation:\n");
    printf("Process No.\tProcess Size\tBlock No.\n");
    for (int i = 0; i < n; i++) {
        printf(" %d\t\t%d\t\t", i + 1, processSize[i]);
        if (allocation[i] != -1) {
            printf("%d", allocation[i] + 1);
        } else {
            printf("Not Allocated");
        }
        printf("\n");
    }

    printf("Remaining Memory of Each Block:\n");
    for (int i = 0; i < m; i++) {
        if (blockSize[i] == -1) {
            printf("Block %d: Allocated\n", i + 1);
        } else {
            printf("Block %d: %d\n", i + 1, blockSize[i]);
        }
    }
}

int main() {
    int m, n;

    printf("Enter number of memory blocks: ");
    scanf("%d", &m);
    int blockSize[m];

    printf("Enter sizes of memory blocks:\n");
    for (int i = 0; i < m; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &blockSize[i]);
    }

    printf("Enter number of processes: ");
    scanf("%d", &n);
    int processSize[n];

    printf("Enter sizes of processes:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &processSize[i]);
    }

    int originalBlockSize[m];
    for (int i = 0; i < m; i++) {
        originalBlockSize[i] = blockSize[i]; 
    }

    firstFit(originalBlockSize, m, processSize, n);
    for (int i = 0; i < m; i++) {
        originalBlockSize[i] = blockSize[i];  
    }
    bestFit(originalBlockSize, m, processSize, n);
    for (int i = 0; i < m; i++) {
        originalBlockSize[i] = blockSize[i]; 
    }
    worstFit(originalBlockSize, m, processSize, n);

    return 0;
}