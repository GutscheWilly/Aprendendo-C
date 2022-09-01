
# include <stdio.h>

int main(){

    int i, j, tam;

    printf("\n\nInforme o tamanho do losango desejado: ");
    scanf("%d", &tam);

    printf("\n\n");

    for (i = 0 ; i < tam / 2 ; i++){

        for (j = 0 ; j < tam / 2 - i ; j++){

            printf("*");
        }

        for (j = 0 ; j < i ; j++){

            printf("  ");
        }

        for (j = 0 ; j < tam / 2 - i ; j++){

            printf("*");
        }


        printf("\n");
    }

    for (i = 1 ; i <= tam / 2 ; i++){

        for (j = 0 ; j < i ; j++){

            printf("*");
        }

        for (j = 0 ; j < tam / 2 - i ; j++){

            printf("  ");
        }

        for (j = 0 ; j < i ; j++){

            printf("*");
        }

        printf("\n");
    }

    return(0);
}