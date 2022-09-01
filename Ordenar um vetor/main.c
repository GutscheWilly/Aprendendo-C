# include <stdio.h>

int main(){

    int valor[100], save_valor, i, j, menor;

    for (i = 0 ; i < 100 ; i ++){

        printf("Informe o valor [%d]: ", i);
        scanf("%d", &valor[i]);
    }

    printf("\n\n\n");

    for (i = 0 ; i < 100 ; i++){

        printf("Valor [%d] = %d\n", i, valor[i]);
    }

    printf("\n\n\n");

    for (i = 0 ; i < 100 ; i++){

        menor = valor[i];

        for (j = i ; j < 100 ; j++){

            if (valor[j] < menor){

                menor = valor[j];

                valor[j] = valor[i];

                valor[i] = menor;
            }
        }
    }

    for (i = 0 ; i  < 100 ;  i++){

        printf("Valor [%d] = %d\n", i, valor[i]);
    }

    return(0);
}