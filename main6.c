#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>


typedef struct {
	
    int linha;
    int coluna;
    
} Posicao;


Posicao buscaSequencial(int matriz[3][3], int valor) {
	
    Posicao posicao;
    int i, j;
    
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (matriz[i][j] == valor) {
                posicao.linha = i;
                posicao.coluna = j;
                return posicao;
                
            }
        }
    }
    
    posicao.linha = -1;
    posicao.coluna = -1;
    
    return posicao;
    
}
	

int main() {
	

    int matriz[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int n;
    
    
    printf("\nDigite o valor de busca: ");
    scanf("%d", &n);
    
   	 Posicao posicao = buscaSequencial(matriz, n);
   	 
   		 if (posicao.linha != -1 && posicao.coluna != -1) {
    	    printf("Valor encontrado na linha %d e coluna %d.\n", posicao.linha, posicao.coluna);
   			 } else {
   				     printf("Valor não encontrado.\n");
    }
    
    return 0;
    
}

