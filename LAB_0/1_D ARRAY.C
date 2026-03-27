#include <stdio.h>

int main() {
    int arr[5], i, sum = 0;

    printf("Enter 5 numbers:\n");
    for(i = 0; i < 5; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    printf("Array elements are:\n");
    for(i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nSum = %d\n", sum);
    return 0;
}
