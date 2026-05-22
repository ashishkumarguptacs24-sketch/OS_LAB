#include <stdio.h>

struct Process {
    int id;
    int burstTime;
    int share;      // CPU share percentage
};

int main() {
    int n, i;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    // Input process details
    for(i = 0; i < n; i++) {
        printf("\nEnter Burst Time for Process P%d: ", i + 1);
        scanf("%d", &p[i].burstTime);

        printf("Enter CPU Share (in %% ) for Process P%d: ", i + 1);
        scanf("%d", &p[i].share);

        p[i].id = i + 1;
    }

    printf("\n--- Proportional Scheduling ---\n");
    printf("Process\tBurst Time\tCPU Share\tAllocated CPU Time\n");

    for(i = 0; i < n; i++) {
        float allocatedTime;

        // CPU time allocated proportionally
        allocatedTime = (p[i].burstTime * p[i].share) / 100.0;

        printf("P%d\t%d\t\t%d%%\t\t%.2f\n",
               p[i].id,
               p[i].burstTime,
               p[i].share,
               allocatedTime);
    }

    return 0;
}
