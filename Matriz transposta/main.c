# include <stdio.h>
# include <time.h>

int main(){

    int matriz[5][4], transposta[4][5], l , c;

    srand(time(NULL));

    // Gerando aleatoriamente e imprimindo a matriz:

    printf("\n\nMatriz:\n\n");

    for (l = 0 ; l < 5 ; l++){

        for (c = 0 ; c < 4 ; c++){

            matriz[l][c] = rand() % 100;

            printf("%2d ", matriz[l][c]);

            transposta[c][l] = matriz[l][c]; // Definindo a matriz transposta
        }

        printf("\n");
    }

    // Imprimindo a matriz transposta:

    printf("\n\nMatriz transposta:\n\n");

    for ( l = 0 ; l < 4 ; l++){

        for (c = 0 ; c < 5 ; c++){

            printf("%2d ", transposta[l][c]);
        }

        printf("\n");
    }

    return(0);
}