#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int n, i;
    clock_t start, end;
    double cpu_time_used;

    printf("Enter the number of elements (n): ");
    scanf("%d", &n);

    if (n < 5000) {
        printf("Please enter a value of n greater than 5000.\n");
        return 1;
    }

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 10000;
    }
    start = clock();
    selectionSort(arr, n);
    end = clock();

    cpu_time_used = ((double)(end - start))/CLOCKS_PER_SEC;

    printf("Time taken for sorting: %lf seconds\n", cpu_time_used);

    free(arr);
    return 0;
}
