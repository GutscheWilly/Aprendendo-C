# include <stdio.h>
# include <time.h>

int main(){

    int matriz [5] [10] = {0}, linha [5] = {0}, coluna [10] = {0}, l, c;

    srand(time(NULL));

    for (l = 0 ; l < 5 ; l++){

        for (c = 0 ; c < 10 ; c++){

            matriz[l][c] = rand() % 100; 
        }
    }

    for (l = 0 ; l < 5 ; l++){

        for (c = 0 ; c < 10 ; c++){

            linha[l] += matriz[l][c];
        }
    }

    for (c = 0 ; c < 10 ; c++){

        for (l = 0 ; l < 5 ; l++){

            coluna[c] += matriz[l][c];
        }
    }

    for (l = 0 ; l < 5 ; l++){

        for (c = 0 ; c < 10 ; c++){

            printf("%3d ", matriz[l][c]);
        }

        printf("\n\n");
    }

    printf("\n\nSoma das linhas:\n\n");

    for (l = 0 ; l < 5 ; l++){

        printf("Soma da linha [%d] = %d\n", l + 1, linha[l]);
    }

    printf("\n\nSoma das colunas:\n\n");

    for (c = 0 ; c < 10 ; c++){
        
        printf("Soma da coluna [%d] = %d\n", c + 1, coluna[c]);
    }

    return(0);
}