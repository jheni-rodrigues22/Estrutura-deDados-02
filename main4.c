#include <stdio.h>
#include <stdlib.h>

#define SIZE 3  // Tamanho da matriz 3x3 (é pra funcionar)


void trocar(int *a, int *b) {
	
    int temp = *a;
    *a = *b;
    *b = temp;
    
}

void ordenarMatriz(int matriz[SIZE][SIZE]) {
	
    int tamanho = SIZE * SIZE;
    int vetor[tamanho];
    int i, j;


    i = 0;
    for (; i < SIZE; i++) {
        j = 0;
        for (; j < SIZE; j++) {
            vetor[i * SIZE + j] = matriz[i][j];
        }
    }

    i = 0;
    for (; i < tamanho - 1; i++) {
        j = 0;
        for (; j < tamanho - i - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                trocar(&vetor[j], &vetor[j + 1]);
            }
        }
    }


    i = 0;
    for (; i < SIZE; i++) {
        j = 0;
        for (; j < SIZE; j++) {
            matriz[i][j] = vetor[i * SIZE + j];
        }
    }
}

void exibirMatriz(int matriz[SIZE][SIZE]) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
	
    int matriz[SIZE][SIZE] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};

    	printf("Matriz original:\n");
   			 exibirMatriz(matriz);

   				 ordenarMatriz(matriz);

  					  printf("\nMatriz ordenada:\n");
  						  exibirMatriz(matriz);


    return 0;
    
}

