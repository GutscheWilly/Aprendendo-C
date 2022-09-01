# include <stdio.h>

void Receber_dimensoes(int vetor[]);
int Verificar_dimensoes(int vetor[]);
void Receber_elementos_duas_matrizes(int matrizA[][100], int matrizB[][100], int vetor[]);
void Criando_matriz_multiplicacao(int matrizC[][100], int matrizA[][100], int matrizB[][100], int vetor[]);
void Imprimindo_matriz(int matriz[][100], int *linha, int *coluna);

int main(){

    int dimensoes[4], condicao, matriz1[100][100], matriz2[100][100], matriz3[100][100];

    Receber_dimensoes(dimensoes);

    condicao = Verificar_dimensoes(dimensoes);

    if(condicao){

        Receber_elementos_duas_matrizes(matriz1, matriz2, dimensoes);

        Criando_matriz_multiplicacao(matriz3, matriz1, matriz2, dimensoes);

        printf("Matriz 1 (%dx%d)\n", dimensoes[0], dimensoes[1]);
        Imprimindo_matriz(matriz1, &dimensoes[0], &dimensoes[1]);

        printf("Matriz 2 (%dx%d)\n", dimensoes[2], dimensoes[3]);
        Imprimindo_matriz(matriz2, &dimensoes[2], &dimensoes[3]);

        printf("Matriz 1 * Matriz 2 (%dx%d)\n", dimensoes[0], dimensoes[3]);
        Imprimindo_matriz(matriz3, &dimensoes[0], &dimensoes[3]);

    }else{

        printf("Não é possível realizar a operação, pois as matrizes não seguem a regra MxN, NxO = MxO.");
    }

    return(0);
}

void Receber_dimensoes(int vetor[]){

    int i;

    for (i = 0 ; i < 4 ; i++){

        scanf("%d", &vetor[i]);
    }

    return;
}

int Verificar_dimensoes(int vetor[]){

    int verificacao;

    if (vetor[1] == vetor[2]){

        verificacao = 1;

    }else{

        verificacao = 0;
    }

    return(verificacao);
}

void Receber_elementos_duas_matrizes(int matrizA[][100], int matrizB[][100], int vetor[]){

    int l, c;

    for(l = 0 ; l < vetor[0] ; l++){

        for(c = 0 ; c < vetor[1] ; c++){

            scanf("%d", &matrizA[l][c]);
        }
    }

    for(l = 0 ; l < vetor[2] ; l++){

        for(c = 0 ; c < vetor[3] ; c++){

            scanf("%d", &matrizB[l][c]);
        }
    }

    return;
}

void Criando_matriz_multiplicacao(int matrizC[][100], int matrizA[][100], int matrizB[][100], int vetor[]){

    int l, c, m;

    for(l = 0 ; l < vetor[0] ; l++){

        for(m = 0 ; m < vetor[3] ; m++){

            for(c = 0 ; c < vetor[2] ; c++){

                matrizC[l][m] += matrizA[l][c] * matrizB[c][m]; 
            }
        }
    }

    return;
}

void Imprimindo_matriz(int matriz[][100], int *linha, int *coluna){

    int l, c;

    for(l = 0 ; l < *linha ; l++){

        for(c = 0 ; c < *coluna ; c++){

            printf("%d ", matriz[l][c]); 
        }

        printf("\n");
    }

    return;
}