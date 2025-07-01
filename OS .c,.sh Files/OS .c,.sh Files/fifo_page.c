#include <stdio.h>

void fifoPageReplacement(int pages[], int numPages, int frameSize) {
    int frame[frameSize];
    int pageFaults = 0, k = 0, i, j;
    int isPresent;

    for (i = 0; i < frameSize; i++) {
        frame[i] = -1;
    }

    for (i = 0; i < numPages; i++) {
        isPresent = 0;

        for (j = 0; j < frameSize; j++) {
            if (frame[j] == pages[i]) {
                isPresent = 1;
                break;
            }
        }

        if (!isPresent) {
            frame[k] = pages[i];
            k = (k + 1) % frameSize;
            pageFaults++;
            printf("Page %d caused a page fault. Frame: ", pages[i]);
            for (j = 0; j < frameSize; j++) {
                printf("%d ", frame[j]);
            }
            printf("\n");
        } else {
            printf("Page %d is already in the frame. No page fault.\n", pages[i]);
        }
    }

    printf("Total Page Faults: %d\n", pageFaults);
}

int main() {
    int numPages, frameSize;

    printf("Enter number of pages: ");
    scanf("%d", &numPages);
    int pages[numPages];

    printf("Enter page numbers:\n");
    for (int i = 0; i < numPages; i++) {
        printf("Page %d: ", i + 1);
        scanf("%d", &pages[i]);
    }

    printf("Enter number of frames: ");
    scanf("%d", &frameSize);

    fifoPageReplacement(pages, numPages, frameSize);

    return 0;
}