# include <stdio.h>

int main(){

    int matriz[4][4], linha[4] = {0}, coluna[4] = {0}, diagonal[2] = {0}, l, c, diferente = 0;

    // Criando a matriz:

    for (l = 0 ; l < 4 ; l++){

        for (c = 0 ; c < 4 ; c++){

            printf("Digite um valor para a posicao [%d] [%d]:  ", l, c);
            scanf("%d", &matriz[l][c]);
        }
    }

    // Verificando o somatório de cada linha e atribuindo no vetor << linha >>:

    for (l = 0 ; l < 4 ; l++){

        for (c = 0 ; c < 4 ; c++){

            linha[l] += matriz[l][c];
        }
    }

    // Verificando o somatório de cada coluna e atribuindo no vetor << coluna >>:

    for (c = 0 ; c < 4 ; c++){

        for (l = 0 ; l < 4 ; l++){

            coluna[c] += matriz[l][c];
        }
    }

    // Verificando o  somatório da diagonal principal e atribuindo no vetor << diagonal >>:

    for (l = 0 ; l < 4 ; l++){

        diagonal[0] += matriz[l][l];
    }

    // Verificando o somatório da diagonal secundária e atribuindo no vetor << diagonal >>:

    for (l = 0 ; l < 4 ; l++){

        diagonal[1] += matriz[l][3 - l];
    }

    // Percorrendo o vetor << linha >> e analisando se todos os seus elementos são iguais:

    for (l = 1 ; l < 4 ; l++){

        if (linha[l] != linha[l - 1]){

            diferente++;
        }
    }

    // Percorendo o vetor << coluna >> e analisando se todos os seus elementos são iguais:

    if (diferente == 0){

        for (c = 1 ; c < 4 ; c++){

            if (coluna[c] != coluna[c - 1]){

                diferente++;
            }
        }
    }

    // Analisando se o vetor << diagonal >> possui seus dois elementos iguais:

    if (diferente == 0){
        
        if (diagonal[0] != diagonal[1]){

            diferente++;
        }
    }

    // Imprimindo a matriz:

    printf("\n\nMatriz:\n\n");

    for (l = 0 ; l < 4 ; l++){

        for (c = 0 ; c < 4 ; c++){

            printf("%2d ", matriz[l][c]);
        }

        printf("\n");
    }

    // Verificando se a matriz é ou não um quadrado mágico:

    if (diferente == 0 && linha[0] == coluna[0] && linha[0] == diagonal[0]){

        printf("\n\n<<<< Forma um Quadrado Magico >>>>\n\n");

    } else{

        printf("\n\n<<<< Nao forma um Quadrado Magico >>>>\n\n");
    }

    return(0);
}