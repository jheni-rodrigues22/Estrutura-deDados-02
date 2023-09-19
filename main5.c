#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>


void insertion_sort(int matriz[5][5]);

int main() {
    int matrix[5][5];
    int i, j;

	setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    printf("Matriz antes da ordenação:\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            matrix[i][j] = rand() % 100;
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    insertion_sort(matrix);

    printf("\nMatriz após a ordenação:\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}

void insertion_sort(int matriz[5][5]) {
	int i, j;
    for (i = 0; i < 5; i++) {
        for (j = 1; j < 5; j++) {
            int key = matriz[i][j];
            int k = j - 1;
            while (k >= 0 && matriz[i][k] > key) {
                matriz[i][k + 1] = matriz[i][k];
                k = k - 1;
            }
            matriz[i][k + 1] = key;
        }
    }
}

