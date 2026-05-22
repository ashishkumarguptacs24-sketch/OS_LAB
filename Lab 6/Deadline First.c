#include <stdio.h>

int main() {

    int n, bt[10], dl[10], temp[10];
    int i, j, time = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {

        printf("\nEnter Burst Time of P%d: ", i + 1);
        scanf("%d", &bt[i]);

        printf("Enter Deadline of P%d: ", i + 1);
        scanf("%d", &dl[i]);

        temp[i] = dl[i];
    }

    printf("\nExecution Order:\n");

    // EDF Scheduling
    for(i = 0; i < n; i++) {

        int min = 9999, pos = -1;

        for(j = 0; j < n; j++) {

            if(temp[j] < min && temp[j] != -1) {

                min = temp[j];
                pos = j;
            }
        }

        printf("P%d executes\n", pos + 1);

        temp[pos] = -1;
    }

    // Gantt Chart
    printf("\nGantt Chart:\n\n|");

    for(i = 0; i < n; i++) {

        int min = 9999, pos = -1;

        for(j = 0; j < n; j++) {

            if(dl[j] < min) {

                min = dl[j];
                pos = j;
            }
        }

        printf("  P%d  |", pos + 1);

        dl[pos] = 9999;
    }

    printf("\n0");

    for(i = 0; i < n; i++) {

        int min = 9999, pos = -1;

        for(j = 0; j < n; j++) {

            if(temp[j] == -1 && bt[j] != -1) {

                pos = j;
                break;
            }
        }

        time += bt[pos];

        printf("     %d", time);

        bt[pos] = -1;
    }

    return 0;
}
