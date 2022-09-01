# include <stdio.h>

void Atribuir_espacos(char mat[][3]);
void Instrucoes(int *round);
void Receber_coordenadas(int coord[]);
char Mostrar_X_ou_O(int round);
void Atribuir_elemento_matriz(char mat[][3], int coord[], int *round);
void Imprimir_matriz(char mat[][3]);
int Teste_fim_jogo(int teste);
int Vitoria_linha(char mat[][3], int *round);
int Vitoria_coluna(char mat[][3], int *round);
int Vitoria_diagonal_principal(char mat[][3], int *round);
int Vitoria_diagonal_secundaria(char mat[][3], int *round);
void Verificar_fim_jogo(int *fim_jogo, char mat[][3], int *round);
int Retonar_jogador(int *round);

int main(){

    char jogo[3][3];

    int coordenadas[2], rodada = 1, fim_jogo = 0;

    Atribuir_espacos(jogo);

    while(rodada <= 9 && fim_jogo == 0){

        Instrucoes(&rodada);

        Receber_coordenadas(coordenadas);

        Atribuir_elemento_matriz(jogo, coordenadas, &rodada);

        Imprimir_matriz(jogo);

        Verificar_fim_jogo(&fim_jogo, jogo, &rodada);

        rodada++;
    }

    return(0);
}

void Atribuir_espacos(char mat[][3]){

    int l, c;

    for(l = 0 ; l < 3 ; l++){

        for(c = 0 ; c < 3 ; c++){

            mat[l][c] = ' ';
        }
    }

    return;
}

void Instrucoes(int *round){

    int jogador;

    jogador = Retonar_jogador(round);

    printf("\n\n\n\nConsidere as coordenadas: (A , B)\n\n\n");

    printf("\t(0 , 0) | (0 , 1) | (0 , 2)\n");
    printf("\t---------------------------\n");
    printf("\t(1 , 0) | (1 , 1) | (1 , 2)\n");
    printf("\t---------------------------\n");
    printf("\t(2 , 0) | (2 , 1) | (2 , 2)\n");

    printf("\n\nJogador 1: X\t\tJogador 2: O");
    
    printf("\n\n\n\t<<<< Vez do jogador %d >>>>\n", jogador);

    return;
}

void Receber_coordenadas(int coord[]){

    printf("\n\n");

    do{
        printf("\nCoordenada A: ");
        scanf("%d", &coord[0]);

    } while(coord[0] > 2 || coord[0] < 0);

    do{
        printf("\nCoordenada B: ");
        scanf("%d", &coord[1]);

    } while(coord[1] > 2 || coord[1] < 0);

    return;
}

char Mostrar_X_ou_O(int round){

    char caracter;

    if(round % 2 == 0){

        caracter = 'O';

    } else{

        caracter = 'X';
    }

    return(caracter);
}

void Atribuir_elemento_matriz(char mat[][3], int coord[], int *round){

    if(mat[coord[0]][coord[1]] == ' '){

        mat[coord[0]][coord[1]] = Mostrar_X_ou_O(*round);

    } else{

        printf("\n\n<<<< Coordenadas Inválidas !! >>>>\n");
        Receber_coordenadas(coord);
        Atribuir_elemento_matriz(mat, coord, round);
    }

    return;
}

void Imprimir_matriz(char mat[][3]){

    int l, c;

    printf("\n\n");

    for(l = 0 ; l < 3 ; l++){

        for(c = 0 ; c < 3 ; c++){

            if(c == 0){

                printf("\t\t");
            }

            printf("  %c", mat[l][c]);

            if(c != 2){

                printf("  |");
            }
        }

        if(l != 2){

            printf("\n\t\t-----------------\n");
        }
    }

    return;
}

int Teste_fim_jogo(int teste){

    if(teste == 3){

        return(1);

    }else{

        return(0);
    }
}

int Vitoria_linha(char mat[][3], int *round){

    int l, c, teste = 0;

    for(l = 0 ; l < 3 && teste != 3 ; l++){

        teste = 0;

        for(c = 0 ; c < 3 ; c++){

            if(mat[l][c] == Mostrar_X_ou_O(*round)){

                teste++;
            }
        }
    }

    return(Teste_fim_jogo(teste));
}

int Vitoria_coluna(char mat[][3], int *round){

    int l, c, teste = 0;

    for(c = 0 ; c < 3 && teste != 3 ; c++){

        teste = 0;

        for(l = 0 ; l < 3 ; l++){

            if(mat[l][c] == Mostrar_X_ou_O(*round)){

                teste++;
            }
        }
    }

    return(Teste_fim_jogo(teste));
}

int Vitoria_diagonal_principal(char mat[][3], int *round){

    int l, teste = 0;

    for(l = 0 ; l < 3 ; l++){

        if(mat[l][l] == Mostrar_X_ou_O(*round)){

            teste++;
        }
    }

    return(Teste_fim_jogo(teste));
}

int Vitoria_diagonal_secundaria(char mat[][3], int *round){

    int l, teste = 0;

    for(l = 0 ; l < 3 ; l++){

        if(mat[l][2 - l] == Mostrar_X_ou_O(*round)){

            teste++;
        }
    }

    return(Teste_fim_jogo(teste));
}

void Verificar_fim_jogo(int *fim_jogo, char mat[][3], int *round){

    int jogador;

    jogador = Retonar_jogador(round);

    *fim_jogo = Vitoria_linha(mat, round);

    if(*fim_jogo){

        printf("\n\n\n\t<<<< O jogador %d ganhou por linha !!! >>>>\n\n", jogador);

    } else{

        *fim_jogo = Vitoria_coluna(mat, round);

        if(*fim_jogo){

            printf("\n\n\n\t<<<< O jogador %d ganhou por coluna !!! >>>>\n\n", jogador);

        } else{

            *fim_jogo = Vitoria_diagonal_principal(mat, round);

            if(*fim_jogo){

                printf("\n\n\n\t<<<< O jogador %d ganhou pela diagonal principal !!! >>>>\n\n", jogador);

            } else{

                *fim_jogo = Vitoria_diagonal_secundaria(mat, round);

                if(*fim_jogo){

                    printf("\n\n\n\t<<<< O jogador %d ganhou pela diagonal secundaria !!! >>>>\n\n", jogador);

                } else{

                    if(*round == 9){

                        printf("\n\n\n\t<<<< Deu Velha !!! >>>>\n\n");
                    }
                }
            }
        }
    }

    return;
}

int Retonar_jogador(int *round){

    char caracter;

    caracter = Mostrar_X_ou_O(*round);

    if(caracter == 'X'){

        return(1);

    } else{

        return(2);
    }
}