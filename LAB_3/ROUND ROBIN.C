#include <stdio.h>

int main() {
    int n, tq;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], rt[n], wt[n], tat[n];

    // Input burst times
    for(int i = 0; i < n; i++) {
        printf("Enter Burst Time for Process %d: ", i + 1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    int time = 0, done;

    // Gantt chart arrays (max size assumed)
    int gantt_p[100], gantt_t[100];
    int k = 0;

    // Round Robin Scheduling
    do {
        done = 1;
        for(int i = 0; i < n; i++) {
            if(rt[i] > 0) {
                done = 0;

                gantt_p[k] = i + 1; // store process number

                if(rt[i] > tq) {
                    time += tq;
                    rt[i] -= tq;
                } else {
                    time += rt[i];
                    wt[i] = time - bt[i];
                    rt[i] = 0;
                }

                gantt_t[k] = time; // store current time
                k++;
            }
        }
    } while(!done);

    // Calculate Turnaround Time
    for(int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }

    // Display results
    float total_wt = 0, total_tat = 0;

    printf("\nProcess\tBT\tWT\tTAT\n");
    for(int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\n", i + 1, bt[i], wt[i], tat[i]);
        total_wt += wt[i];
        total_tat += tat[i];
    }

    printf("\nAverage Waiting Time = %.2f", total_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", total_tat / n);

    // ✅ Print Gantt Chart
    printf("\nGantt Chart:\n");

    printf("0");
    for(int i = 0; i < k; i++) {
        printf(" | P%d | %d", gantt_p[i], gantt_t[i]);
    }
    printf("\n");

    return 0;
}
