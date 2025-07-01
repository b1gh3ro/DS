#include <stdio.h>
#include <stdlib.h>

void optimalPageReplacement(int pages[], int n, int frameCount) {
    int frame[frameCount];
    int pageFaults = 0;

    for (int i = 0; i < frameCount; i++) {
        frame[i] = -1;
    }

    printf("\nPage Reference\tFrames\n");

    for (int i = 0; i < n; i++) {
        int page = pages[i];
        int found = 0;

        for (int j = 0; j < frameCount; j++) {
            if (frame[j] == page) {
                found = 1;
                break;
            }
        }

        if (!found) {
            int replaceIdx = -1, farthest = -1;

            for (int j = 0; j < frameCount; j++) {
                int k;
                for (k = i + 1; k < n; k++) {
                    if (frame[j] == pages[k]) {
                        if (k > farthest) {
                            farthest = k;
                            replaceIdx = j;
                        }
                        break;
                    }
                }
                if (k == n) {
                    replaceIdx = j;
                    break;
                }
            }

            if (replaceIdx == -1) {
                replaceIdx = 0;
            }

            frame[replaceIdx] = page;
            pageFaults++;
        }

        printf("%d\t\t\t", page);
        for (int j = 0; j < frameCount; j++) {
            if (frame[j] != -1) {
                printf("%d ", frame[j]);
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }

    printf("Total Page Faults: %d\n", pageFaults);
}

int main() {
    int n, frameCount;

    printf("Enter number of pages: ");
    scanf("%d", &n);
    int pages[n];

    printf("Enter page reference string:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter number of frames: ");
    scanf("%d", &frameCount);

    optimalPageReplacement(pages, n, frameCount);

    return 0;
}