# include <stdio.h>
# include <string.h>
# include <time.h>

# define QUANT 20

typedef struct{

    char bomba[10];
    int perimetro;
    int mostrar;

} Posicao;

void Definir_posicoes(Posicao posicao[][10]);
void Ler_coordenadas(Posicao posicao[][10]);
void Primeira_coordenda(Posicao posicao[][10]);
void Atribuir_perimetros(Posicao posicao[][10]);
void Imprimir_posicao(Posicao posicao[][10], int l, int c);
void Imprimir_jogo(Posicao posicao[][10]);
int Verificar_fim_jogo(Posicao posicao[][10]);

int main(){

    Posicao posicao[10][10];

    int fim_jogo = 0;

    Definir_posicoes(posicao);
    Imprimir_jogo(posicao);
    Primeira_coordenda(posicao);
    Atribuir_perimetros(posicao);

    while(fim_jogo == 0){

        Imprimir_jogo(posicao);
        fim_jogo = Verificar_fim_jogo(posicao);

        if(fim_jogo == 0){

            Ler_coordenadas(posicao);
        } 
    }

    return(0);
}

void Definir_posicoes(Posicao posicao[][10]){

    int l, c;

    for(l = 0 ; l < 10 ; l++){

        for(c = 0 ; c < 10 ; c++){

            strcpy(posicao[l][c].bomba, "False");
            posicao[l][c].perimetro = 0;
            posicao[l][c].mostrar = 0;
        }
    }

    return;
}

void Ler_coordenadas(Posicao posicao[][10]){

    int l, c;

    do{

        printf("\nCoordenadas: ");
        scanf("%d %d", &l, &c);

        if(l < 0 || l > 9 || c < 0 || c > 9){

            printf("\nCoordenada invalida!\n");

        } else{

            if(posicao[l][c].mostrar == 1){

                printf("\nCoordenada preenchida!\n");
            }
        }

    } while(l < 0 || l > 9 || c < 0 || c > 9 || posicao[l][c].mostrar == 1);

    posicao[l][c].mostrar = 1;

    return;
}

void Primeira_coordenda(Posicao posicao[][10]){

    int i, l, c;

    srand(time(NULL));
    Ler_coordenadas(posicao);

    for(i = 0 ; i < QUANT ; i++){

        do{

            l = rand() % 10;
            c = rand() % 10;

            if(strcmp(posicao[l][c].bomba, "False") == 0 && posicao[l][c].mostrar == 0){

                strcpy(posicao[l][c].bomba, "True");
            }

        } while(strcmp(posicao[l][c].bomba, "False") == 0);
    }

    return;
}

void Atribuir_perimetros(Posicao posicao[][10]){

    int l, c, i, j;

    for(l = 0 ; l < 10 ; l++){

        for(c = 0 ; c < 10 ; c++){

            for(i = l - 1 ; i <= l + 1 ; i++){

                for(j = c - 1 ; j <= c + 1 ; j++){

                    if(i >= 0 && i <= 9 && j >= 0 && j <= 9){

                        if(strcmp(posicao[i][j].bomba, "True") == 0){

                            posicao[l][c].perimetro++;
                        }
                    }
                }
            }

            if(posicao[l][c].perimetro == 0){

                for(i = l - 1 ; i <= l + 1 ; i++){

                    for(j = c - 1 ; j <= c + 1 ; j++){

                        if(i >= 0 && i <= 9 && j >= 0 && j <= 9){

                            posicao[i][j].mostrar = 1;
                        }
                    }
                }
            }
        }
    }

    return;
}

void Imprimir_posicao(Posicao posicao[][10], int l, int c){

    if(posicao[l][c].mostrar == 0){

        printf(" ");

    } else{

        if(strcmp(posicao[l][c].bomba, "False") == 0){

            printf("%d", posicao[l][c].perimetro);

        } else{

            printf("*");
        }
    }

    return;
}

void Imprimir_jogo(Posicao posicao[][10]){

    int l, c, i;

    printf("\t\t ");
    for(c = 0 ; c < 10 ; c++){

        printf(" %d  ", c);
    }

    printf("\n");

    for(l = 0 ; l < 10 ; l++){

        printf("\n\t      %d  ", l);

        for(c = 0 ; c < 10 ; c++){

            printf(" ");
            Imprimir_posicao(posicao, l, c);

            if(c != 9){

                printf(" |");
            }
        }


        if(l != 9){

            printf("\n\t         ");
            for(i = 0 ; i < 39 ; i++){

                printf("-");
            }
        }
    }

    printf("\n");
        
    return;
}

int Verificar_fim_jogo(Posicao posicao[][10]){

    int l, c, teste1 = 0, teste2 = 0;

    for(l = 0 ; l < 10 ; l++){

        for(c = 0 ; c < 10 ; c++){

            if(strcmp(posicao[l][c].bomba, "True") == 0 && posicao[l][c].mostrar == 1){

                teste1++;

            } else{

                if(strcmp(posicao[l][c].bomba, "False") == 0 && posicao[l][c].mostrar == 1){

                    teste2++;
                }
            }
        }
    }

    if(teste1 != 0){

        printf("\n\n<<<< Bomba!!! >>>>\n\n");
        return(1);
        
    } else{

        if(teste2 == 100 - QUANT){

            printf("\n\n<<<< Parabens, voce ganhou!!! >>>>\n\n");
            return(1);

        } else{

            return(0);
        }
    }
}