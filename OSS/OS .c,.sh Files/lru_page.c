#include <stdio.h>

int main() {
    int fr[10], p[50], i, j, n;
    int max, found = 0, lg[10], index, k, l, flag1 = 0, flag2 = 0, pf = 0, frsize;

    printf("Total No of Pages in Reference String: ");
    scanf("%d", &n);

    printf("Enter Reference String:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }

    printf("No of Frames: ");
    scanf("%d", &frsize);

    for (i = 0; i < frsize; i++) {
        fr[i] = -1;
    }

    for (j = 0; j < n; j++) {
        flag1 = 0;
        flag2 = 0;

        for (i = 0; i < frsize; i++) {
            if (fr[i] == p[j]) {
                flag1 = 1;
                flag2 = 1;
                break;
            }
        }

        if (flag1 == 0) {
            for (i = 0; i < frsize; i++) {
                if (fr[i] == -1) {
                    fr[i] = p[j];
                    flag2 = 1;
                    pf++;
                    break;
                }
            }
        }

        if (flag2 == 0) {
            for (i = 0; i < frsize; i++) {
                lg[i] = 0;
            }

            for (i = 0; i < frsize; i++) {
                for (k = j - 1; k >= 0; k--) {
                    if (fr[i] == p[k]) {
                        lg[i] = k - j;
                        break;
                    }
                }
            }

            found = 0;
            for (i = 0; i < frsize; i++) {
                if (lg[i] == 0) {
                    index = i;
                    found = 1;
                    break;
                }
            }

            if (found == 0) {
                max = lg[0];
                index = 0;

                for (i = 1; i < frsize; i++) {
                    if (max > lg[i]) {
                        max = lg[i];
                        index = i;
                    }
                }
            }

            fr[index] = p[j];
            pf++;
        }

        printf("\n");
        for (i = 0; i < frsize; i++) {
            printf("\t%d", fr[i]);
        }
    }

    printf("\nNo of Page Faults: %d\n", pf);
    return 0;
}
