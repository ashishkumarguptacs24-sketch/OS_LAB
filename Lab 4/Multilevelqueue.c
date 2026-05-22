#include <stdio.h>

struct process {
    int pid, at, bt, ct, tat, wt, priority;
};

void sort(struct process p[], int n) {
    struct process temp;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {

            // Sort by priority, then arrival time
            if (p[i].priority > p[j].priority ||
               (p[i].priority == p[j].priority && p[i].at > p[j].at)) {

                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

int main() {
    int n, i;
    printf("Enter total number of processes: ");
    scanf("%d", &n);

    struct process p[n];

    for (i = 0; i < n; i++) {
        printf("\nProcess %d\n", i + 1);
        printf("Enter Arrival Time: ");
        scanf("%d", &p[i].at);
        printf("Enter Burst Time: ");
        scanf("%d", &p[i].bt);
        printf("Enter Queue (1=System, 2=User): ");
        scanf("%d", &p[i].priority);

        p[i].pid = i + 1;
    }

    sort(p, n);

    int time = 0;

    // For Gantt chart
    int start[n], end[n];

    for (i = 0; i < n; i++) {
        if (time < p[i].at)
            time = p[i].at;

        start[i] = time;

        p[i].ct = time + p[i].bt;
        end[i] = p[i].ct;

        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;

        time = p[i].ct;
    }

    // Display Table
    printf("\nPID\tAT\tBT\tPR\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid, p[i].at, p[i].bt, p[i].priority,
               p[i].ct, p[i].tat, p[i].wt);
    }

    // Gantt Chart
    printf("\nGantt Chart:\n");

    printf(" ");
    for (i = 0; i < n; i++)
        printf("-------");
    printf("\n|");

    for (i = 0; i < n; i++)
        printf(" P%d |", p[i].pid);

    printf("\n ");
    for (i = 0; i < n; i++)
        printf("-------");

    printf("\n%d", start[0]);
    for (i = 0; i < n; i++)
        printf("      %d", end[i]);

    printf("\n");

    return 0;
}
