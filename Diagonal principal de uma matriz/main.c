# include <stdio.h>
# include <time.h>

int main(){

    int tam = 5;
    int matriz[tam][tam], l, c;

    srand(time(NULL));

    // Gerando aleatoriamente a matriz e imprimindo ela:

    printf("\n\nMatriz:\n\n");

    for (l = 0 ; l < tam ; l++){

        for (c = 0 ; c < tam ; c++){

            matriz[l][c] = rand() % 100;

            printf("%3d ", matriz[l][c]);
        }

        printf("\n");
    }

    // Imprimindo somente a diagonal principal da matriz:

    printf("\n\nDiagonal principal da matriz:\n\n");

    for  (l = 0 ; l < tam ; l++){

        for (c = 0 ; c < l ; c++){

            printf("    ");
        }

        printf("%3d\n", matriz[l][l]);
    }

    return(0);
}