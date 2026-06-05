#include <stdio.h>

int main() {
    int pages[50], frames[10], time[10];
    int n, f, i, j, k, faults = 0, counter = 0;
    int found, lru, min;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string: ");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for(i = 0; i < f; i++) {
        frames[i] = -1;
        time[i] = 0;
    }

    for(i = 0; i < n; i++) {
        found = 0;

        for(j = 0; j < f; j++) {
            if(frames[j] == pages[i]) {
                counter++;
                time[j] = counter;
                found = 1;
                break;
            }
        }

        if(!found) {
            min = time[0];
            lru = 0;

            for(j = 1; j < f; j++) {
                if(time[j] < min) {
                    min = time[j];
                    lru = j;
                }
            }

            counter++;
            frames[lru] = pages[i];
            time[lru] = counter;
            faults++;
        }

        printf("\n");
        for(k = 0; k < f; k++)
            printf("%d\t", frames[k]);
    }

    printf("\n\nTotal Page Faults = %d", faults);

    return 0;
}
