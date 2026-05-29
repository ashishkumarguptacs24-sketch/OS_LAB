#include <stdio.h>

int main() {
    int b[10], p[10], allocation[10];
    int m, n;

    printf("Enter number of memory blocks: ");
    scanf("%d", &m);

    printf("Enter size of blocks:\n");
    for(int i = 0; i < m; i++) {
        scanf("%d", &b[i]);
    }

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter size of processes:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
        allocation[i] = -1;
    }

    for(int i = 0; i < n; i++) {

        for(int j = 0; j < m; j++) {

            if(b[j] >= p[i]) {
                allocation[i] = j;
                b[j] -= p[i];
                break;
            }
        }
    }

    printf("\nProcess No\tProcess Size\tBlock No\n");

    for(int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t", i + 1, p[i]);

        if(allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }

    return 0;
}
