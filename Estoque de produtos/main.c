# include <stdio.h>

void Receber_armazem_produto(int *linha, int *coluna);
int Quantidade_retirada(int estoque[][5], int linha, int coluna);
void Alterar_estoque(int estoque[][5], int linha, int coluna, int quantidade);
void Imprimir_estoque(int estoque[][5]);

int main(){

    int estoque[5][5] = {{150,0,100,150,200}, {200,300,230,100,90}, {250,300,0,200,150}, {300,100,90,450,0},{350,300,400,250,200}};

    int linha, coluna, quantidade_retirada;

    Imprimir_estoque(estoque);

    do{

        Receber_armazem_produto(&linha, &coluna);

        if(linha != -1){

            quantidade_retirada = Quantidade_retirada(estoque, linha, coluna);
            Alterar_estoque(estoque, linha, coluna, quantidade_retirada);
            Imprimir_estoque(estoque);
        }

    } while(linha != -1);

    return(0);
}

void Receber_armazem_produto(int *linha, int *coluna){

    do{
        printf("\nInforme o armazem: ");
        scanf("%d", linha);

        if(*linha < -1 || *linha > 5){

            printf("\nArmazem nao exites!\n");
        }

    } while(*linha < -1 || *linha > 5);

    if(*linha != -1){

        do{
            printf("\nInforme o produto: ");
            scanf("%d", coluna);

            if(*coluna < 0 || *coluna > 5){

                printf("\nProduto nao existe\n");
            }

        } while(*coluna < 0 || *coluna > 5);
    }

    return;
}

int Quantidade_retirada(int estoque[][5], int linha, int coluna){

    int quantidade;

    printf("\nDigite a quantidade do produto %d: ", coluna);
    scanf("%d", &quantidade);

    return(quantidade);
}

void Alterar_estoque(int estoque[][5], int linha, int coluna, int quantidade){

    if(estoque[linha][coluna] >= quantidade){

        estoque[linha][coluna] -= quantidade;
        printf("\nBaixa realizada com sucesso!\n");
        printf("Agora, ha %d produto do tipo %d\n", estoque[linha][coluna], coluna);

    } else{

        printf("\nEstoque com quantidade insuficiente para atender ao pedido!\n");
    }

    return;
}

void Imprimir_estoque(int estoque[][5]){

    int l, c;

    printf("\n\t  | ");

    for(c = 0 ; c < 5 ; c++){

        printf("produto %d ", c);

        if(c != 4){

            printf("| ");
        }
    }

    printf("\n---------------------------------------------------------------------\n");

    for(l = 0 ; l < 5 ; l++){

        printf("Armazem %d |", l);

        for(c = 0 ; c < 5 ; c++){

            printf("    %d   ", estoque[l][c]);

            if(c != 4){

                printf(" | ");
            }
        }

        printf("\n---------------------------------------------------------------------\n");
    }

    return;
}