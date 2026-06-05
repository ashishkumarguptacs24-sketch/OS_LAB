#include <stdio.h>

int main() {
    int pages[50], frames[10];
    int n, f, i, j, k, faults = 0;
    int found, pos, farthest, index;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string: ");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for(i = 0; i < f; i++)
        frames[i] = -1;

    for(i = 0; i < n; i++) {
        found = 0;

        for(j = 0; j < f; j++) {
            if(frames[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        if(!found) {
            pos = -1;
            farthest = i + 1;

            for(j = 0; j < f; j++) {
                for(k = i + 1; k < n; k++) {
                    if(frames[j] == pages[k]) {
                        if(k > farthest) {
                            farthest = k;
                            pos = j;
                        }
                        break;
                    }
                }

                if(k == n) {
                    pos = j;
                    break;
                }
            }

            if(pos == -1)
                pos = 0;

            frames[pos] = pages[i];
            faults++;
        }

        printf("\n");
        for(j = 0; j < f; j++)
            printf("%d\t", frames[j]);
    }

    printf("\n\nTotal Page Faults = %d", faults);

    return 0;
}
