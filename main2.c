#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    int j;

    for (j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void bubbleSort(int arr[], int n) {
	int i, j;
	
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
        }
    }
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int main() {
    int sizes[] = {100, 1000, 10000}; //Tamanho dos arrays
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);
    int i, j;

    for (i = 0; i < num_sizes; i++) {
        int size = sizes[i];
        int arr[size];

        for (j = 0; j < size; j++) {
            arr[j] = rand();
        }

        clock_t start = clock();
        bubbleSort(arr, size);
        clock_t end = clock();
        double elapsed_time_bubble = ((double)(end - start)) / CLOCKS_PER_SEC;
        
        int j;

        for (j = 0; j < size; j++) {
            arr[j] = rand();
        }

        start = clock();
        quicksort(arr, 0, size - 1);
        end = clock();
        double elapsed_time_quicksort = ((double)(end - start)) / CLOCKS_PER_SEC;

        for (j = 0; j < size; j++) {
            arr[j] = rand();
        }

        start = clock();
        mergeSort(arr, 0, size - 1);
        end = clock();
        double elapsed_time_mergesort = ((double)(end - start)) / CLOCKS_PER_SEC;

        printf("Tamanho do array: %d\n", size);
        printf("Tempo de execucao Bubble Sort: %f segundos\n", elapsed_time_bubble);
        printf("Tempo de execucao Quicksort: %f segundos\n", elapsed_time_quicksort);
        printf("Tempo de execucao Mergesort: %f segundos\n\n", elapsed_time_mergesort);
    }

    return 0;
}

