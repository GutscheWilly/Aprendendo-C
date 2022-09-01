# include <stdio.h>
# include <time.h>

int main(){

    int tam = 7;
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

    // Imprimindo a diagonal secundária da matriz:

    printf("\n\nDiagonal secundaria da matriz:\n\n");

    for (l = 0 ; l < tam ; l++){

        for (c = tam - 1 ; c > l ; c--){

            printf("   ");
        }

        printf("%2d\n", matriz[l][tam - 1 - l]);
    }

    return(0);
}