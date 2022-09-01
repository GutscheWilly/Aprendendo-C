# include <stdio.h>

int Soma_linhas(int matriz[100][100], int tamanho, int linha){

    int c, soma_linha = 0;

    for (c = 0 ; c < tamanho ; c++){

        soma_linha += matriz[linha][c];
    }

    return(soma_linha);
}

int main(){

    int matriz[100][100], tamanho, l, c, soma_linha[100];

    printf("Digite o tamanho da matriz: ");
    scanf("%d", &tamanho);

    printf("\n\n");

    for (l = 0 ; l < tamanho ; l++){

        for (c = 0 ; c < tamanho ; c++){

            printf("Digite o valor [%d] [%d]: ", l, c);
            scanf("%d", &matriz[l][c]);
        }
    }

    printf("\n\n");

    for (l = 0 ; l < tamanho ; l++){

        soma_linha[l] = Soma_linhas(matriz, tamanho, l);

        printf("Soma da linha %d = %d\n", l, soma_linha[l]);
    }

    return(0);
}



