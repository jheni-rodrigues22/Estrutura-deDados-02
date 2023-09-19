#include <stdio.h>
#include <stdlib.h>
#define MAX 5

void insertion_sort(int *a);

int main(int argc, char** argv) {
    int i, vet[MAX];

    for (i = 0; i < MAX; i++) {
        printf("Digite um valor: ");
        scanf("%d", &vet[i]);
    }

    insertion_sort(vet);

    printf("\nValores ordenados em ordem decrescente:\n");
    for (i = 0; i < MAX; i++) {
        printf("%d\t", vet[i]);
    }

    return 0;
}

void insertion_sort(int *a) {
    int i, j, tmp;

    for (i = 1; i < MAX; i++) {
        tmp = a[i];
        j = i - 1;

        while (j >= 0 && a[j] < tmp) {

            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = tmp;
    }
}

