# include <stdio.h>
# include <time.h>

int main(){

    int tam = 4;
    int matriz[tam][tam], l, c;

    srand(time(NULL));

    // Gerando aleatoriamente e imprimindo a matriz:

    printf("\n\nMatriz:\n\n");

    for (l = 0 ; l < tam ; l++){

        for (c = 0 ; c < tam ; c++){

            matriz[l][c] = rand() % 100;

            printf("%2d ", matriz[l][c]);
        }

        printf("\n");
    }

    // Imprimindo somente os valores abaixo da diagonal principal da matriz:

    printf("\n\nValores abaixo da diagonal principal da matriz:\n\n");

    for (l = 1 ; l < tam ; l++){

        for (c = 0 ; c < l; c++){

            printf("%2d ", matriz[l][c]);
        }

        printf("\n");
    } 

    return(0);
}