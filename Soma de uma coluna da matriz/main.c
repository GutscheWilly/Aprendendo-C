# include <stdio.h>
# include <time.h>

void Receber_tamanho_matriz(int *quant_linhas, int *quant_colunas);
void Gerar_matriz_aleatoriamente(int matriz[][100], int *quant_linhas, int *quant_colunas);
void Imprimir_matriz(int matriz[][100], int *quant_linhas, int *quant_colunas);
int Soma_da_coluna(int matriz[][100], int *quant_linhas, int coluna);
void Imprimir_soma_das_colunas(int *quant_colunas, int matriz[][100], int *quant_linhas);

int main(){

    int mat[100][100], num_linhas, num_colunas;

    Receber_tamanho_matriz(&num_linhas, &num_colunas);

    Gerar_matriz_aleatoriamente(mat, &num_linhas, &num_colunas);

    Imprimir_matriz(mat, &num_linhas, &num_colunas);

    Imprimir_soma_das_colunas(&num_colunas, mat, &num_linhas);

    return(0);
}

void Receber_tamanho_matriz(int *quant_linhas, int *quant_colunas){

    printf("Digite a quantidade de linhas da matriz: ");
    scanf("%d", quant_linhas);

    printf("\nDigite a quantidade de colunas da matriz: ");
    scanf("%d", quant_colunas);

    return;
}

void Gerar_matriz_aleatoriamente(int matriz[][100], int *quant_linhas, int *quant_colunas){

    int l, c;

    srand(time(NULL));

    for(l = 0 ; l < *quant_linhas ; l++){

        for(c = 0 ; c < *quant_colunas ; c++){

            matriz[l][c] = rand() % 100;
        }
    }

    return;
}

void Imprimir_matriz(int matriz[][100], int *quant_linhas, int *quant_colunas){

    int l, c;

    printf("\n\nMatriz:\n\n");

    for(l = 0 ; l < *quant_linhas ; l++){

        for(c = 0 ; c < *quant_colunas ; c++){

            printf("%2d ", matriz[l][c]);
        }

        printf("\n");
    }

    return;
}

int Soma_da_coluna(int matriz[][100], int *quant_linhas, int coluna){

    int soma = 0, l;

    for(l = 0 ; l < *quant_linhas ; l++){

        soma += matriz[l][coluna];
    }

    return(soma);
}

void Imprimir_soma_das_colunas(int *quant_colunas, int matriz[][100], int *quant_linhas){

    int c, soma_da_coluna;

    printf("\n\n");

    for(c = 0 ; c < *quant_colunas ; c++){

        soma_da_coluna = Soma_da_coluna(matriz, quant_linhas, c);

        printf("Soma da coluna %d = %d\n", c, soma_da_coluna);
    }

    return;
}