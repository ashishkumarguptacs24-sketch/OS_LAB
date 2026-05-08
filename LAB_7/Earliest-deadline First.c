#include <stdio.h>

struct Process {
    int pid;
    int burst;
    int period;
    int remaining;
};

int main() {
    int n, i, j, time, hyperperiod = 20;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    // Input process details
    for(i = 0; i < n; i++) {
        p[i].pid = i + 1;

        printf("\nEnter Burst Time for Process %d: ", i + 1);
        scanf("%d", &p[i].burst);

        printf("Enter Period for Process %d: ", i + 1);
        scanf("%d", &p[i].period);

        p[i].remaining = p[i].burst;
    }

    printf("\nExecution Sequence:\n");

    for(time = 0; time < hyperperiod; time++) {

        // Release processes at their period
        for(i = 0; i < n; i++) {
            if(time % p[i].period == 0) {
                p[i].remaining = p[i].burst;
            }
        }

        int selected = -1;
        int min_period = 9999;

        // Select highest priority (minimum period)
        for(i = 0; i < n; i++) {
            if(p[i].remaining > 0 && p[i].period < min_period) {
                min_period = p[i].period;
                selected = i;
            }
        }

        if(selected != -1) {
            printf("Time %d -> Process P%d\n", time, p[selected].pid);
            p[selected].remaining--;
        } else {
            printf("Time %d -> Idle\n", time);
        }
    }

    return 0;
}
