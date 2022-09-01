# include <stdio.h>
# include <stdio.h>

int main(){

    int matriz_A [3][3] = {0}, matriz_B [3][3]= {0}, matriz_C [3][3]= {0}, l, c;

    srand(time(NULL));

    // Gerando a matriz A e a matriz B aleatoriamente:

    for (l = 0 ; l < 3 ; l++){

        for (c = 0 ; c < 3 ; c++){

            matriz_A[l][c] = rand() % 100;

            matriz_B[l][c] = rand() % 100; 
        }
    }

    // Somando a matriz A com a matriz B, assim criando a matriz C:

    for (l = 0 ; l < 3 ; l++){

        for (c = 0 ; c < 3 ; c++){

            matriz_C[l][c] = matriz_A[l][c] + matriz_B[l][c];
        }
    }

    // Imprimindo a matriz A:

    printf("\n\nMatriz A:\n\n");

    for (l = 0 ; l < 3 ; l++){

        for (c = 0 ; c < 3 ; c++){

            printf("%3d ", matriz_A[l][c]);
        }

        printf("\n\n");
    }

    // Imprimindo a matriz B:

    printf("\n\nMatriz B:\n\n");

    for (l = 0 ; l < 3 ; l++){

        for (c = 0 ; c < 3 ; c++){

            printf("%3d ", matriz_B[l][c]);
        }

        printf("\n\n");
    }

    // Imprimindo a matriz C:

    printf("\n\nMatriz C:\n\n");

    for (l = 0 ; l < 3 ; l++){

        for (c = 0 ; c < 3 ; c++){

            printf("%4d ", matriz_C[l][c]);
        }

        printf("\n\n");
    }

    return(0);
} 