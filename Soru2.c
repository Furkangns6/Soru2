#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

void customSort(int arr[], int n) {
    qsort

    int *result = (int *)malloc(n * sizeof(int));
    int i, j = 0, k = n - 1;

    for (i = 0; i < n; i++) {
        if (i % 2 == 0) {
            result[i] = arr[j++]; 
        } else {
            result[i] = arr[k--];
        }
    }

    for (i = 0; i < n; i++) {
        arr[i] = result[i];
    }

    free(result);
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {60, 80, 3, 9, 57, 11};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Orijinal dizi:\n");
    printArray(arr, n);

    customSort(arr, n);

    printf("Sıralanmış dizi:\n");
    printArray(arr, n);

    return 0;
}
