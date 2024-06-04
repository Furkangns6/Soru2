#include <stdio.h>
#include <stdlib.h>

// Dizi elemanlarını karşılaştırmak için kullanılan fonksiyon
int compare(const void *a, const void *b) {
    return (*(int*)b - *(int*)a); // Büyükten küçüğe sıralama
}

// Diziyi bir büyük bir küçük olacak şekilde yeniden düzenleyen fonksiyon
void customSort(int arr[], int n) {
    // Öncelikle diziyi büyükten küçüğe sıralıyoruz
    qsort(arr, n, sizeof(int), compare);

    // Yeni bir dizi oluşturup bir büyük bir küçük olacak şekilde düzenliyoruz
    int *result = (int *)malloc(n * sizeof(int));
    int i, j = 0, k = n - 1;

    for (i = 0; i < n; i++) {
        if (i % 2 == 0) {
            result[i] = arr[j++]; // Büyük elemanı yerleştir
        } else {
            result[i] = arr[k--]; // Küçük elemanı yerleştir
        }
    }

    // Orijinal diziye yeni düzenlenmiş diziyi kopyalıyoruz
    for (i = 0; i < n; i++) {
        arr[i] = result[i];
    }

    // Bellek temizliği
    free(result);
}

// Diziyi ekrana yazdıran fonksiyon
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
