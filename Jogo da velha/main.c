# include <stdio.h>

int main(){

    char matriz[3][3] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

    int l, c, i, quant, finaliza, continua;


    do{

        finaliza = 0;

        printf("\n\nConsidere: (coordenada A , coordenada B)\n\n");

        printf("(0 , 0) | (0 , 1) | (0 , 2)\n");
        printf("---------------------------\n");
        printf("(1 , 0) | (1 , 1) | (1 , 2)\n");
        printf("---------------------------\n");
        printf("(2 , 0) | (2 , 1) | (2 , 2)\n");

        printf("\n\n");

        printf("Jogador 1: X\n");
        printf("Jogador 2: O\n");

        for (i = 1 ; i <= 9 ; i++){

            if (i % 2 == 1 && finaliza == 0){
                
                printf("\n\n\n<<<< Escolha do jogador 1 >>>>\n\n");

                printf("\nConsidere: (coordenada A , coordenada B)\n\n");

                do{

                    printf("Informe a coordenada A: ");
                    scanf("%d", &l);

                } while (l > 2 || l < 0);
                
                do{
                    printf("Informe a coordenada B: ");
                    scanf("%d", &c);

                } while (c > 2 || c < 0);

                printf("\n\n\n");

                matriz[l][c] = 'X';

                for (l = 0 ; l < 3 ; l++){

                    for (c = 0 ; c < 3 ; c++){

                        printf("    %c    ", matriz[l][c]);

                        if  (c < 2){

                            printf("|");
                        }
                    }

                    if (l < 2){

                        printf("\n------------------------------\n");
                    }
                }

                for (l = 0 ; l < 3 ; l++){

                    quant = 0;

                    for (c = 0 ; c < 3 ; c++){

                        if (matriz[l][c] == 'X'){
                            
                            quant++;
                        }
                    }

                    if (quant == 3){

                        printf("\n\n<<<< Jogador 1 venceu !!! >>>>\n\n");

                        finaliza++;

                        break;
                    }
                }

                for (c = 0 ; c < 3 ; c++){

                    quant = 0;

                    for (l = 0 ; l < 3 ; l++){

                        if (matriz[l][c] == 'X'){

                            quant++;
                        }
                    }

                    if (quant == 3){

                        printf("\n\n<<<< Jogador 1 venceu !!! >>>>\n\n");

                        finaliza++;

                        break;
                    }
                }

                quant = 0;

                for (l = 0 ; l < 3 ; l++){

                    if (matriz[l][l] == 'X'){

                        quant++;

                        if (quant == 3){

                            printf("\n\n<<<< Jogador 1 venceu !!! >>>>\n\n");

                            finaliza++;
                        }
                    }
                }

                quant = 0;

                for (l = 0 ; l < 3 ; l++){

                    if (matriz[l][2 - l] == 'X'){

                        quant++;

                        if (quant == 3){

                            printf("\n\n<<<< Jogador 1 venceu !!! >>>>\n\n");

                            finaliza++;
                        }
                    }
                }

            }else{

                if (i % 2 == 0 && finaliza == 0){
                
                    printf("\n\n\n<<<< Escolha do jogador 2 >>>>\n\n");

                    printf("\nConsidere: (coordenada A , coordenada B)\n\n");

                    do{

                        printf("Informe a coordenada A: ");
                        scanf("%d", &l);

                    } while (l > 2 || l < 0);
                
                    do{
                        printf("Informe a coordenada B: ");
                        scanf("%d", &c);

                    } while (c > 2 || c < 0);               

                    printf("\n\n\n");

                    matriz[l][c] = 'O';

                    for (l = 0 ; l < 3 ; l++){

                        for (c = 0 ; c < 3 ; c++){

                            printf("    %c    ", matriz[l][c]);

                            if  (c < 2){

                                printf("|");
                            }
                        }

                        if (l < 2){

                            printf("\n------------------------------\n");
                        }
                    }

                    for (l = 0 ; l < 3 ; l++){

                        quant = 0;

                        for (c = 0 ; c < 3 ; c++){

                            if (matriz[l][c] == 'O'){
                                
                                quant++;
                            }
                        }

                        if (quant == 3){

                            printf("\n\n<<<< Jogador 2 venceu !!! >>>>\n\n");

                            finaliza++;

                            break;
                        }
                    }

                    for (c = 0 ; c < 3 ; c++){

                        quant = 0;

                        for (l = 0 ; l < 3 ; l++){

                            if (matriz[l][c] == 'O'){

                                quant++;
                            }
                        }

                        if (quant == 3){

                            printf("\n\n<<<< Jogador 2 venceu !!! >>>>\n\n");

                            finaliza++;

                            break;
                        }
                    }

                    quant = 0;

                    for (l = 0 ; l < 3 ; l++){

                        if (matriz[l][l] == 'O'){

                            quant++;

                            if (quant == 3){

                                printf("\n\n<<<< Jogador 2 venceu !!! >>>>\n\n");

                                finaliza++;
                            }
                        }
                    }

                    quant = 0;

                    for (l = 0 ; l < 3 ; l++){

                        if (matriz[l][2 - l] == 'O'){

                            quant++;

                            if (quant == 3){

                                printf("\n\n<<<< Jogador 2 venceu !!! >>>>\n\n");

                                finaliza++;
                            }
                        }
                    }
                }
            }
        }

        if (finaliza == 0){

            printf("\n\n<<<< Empate !!! >>>\n\n\n");
        }

        printf("\n\n\nDigite (1): Jogar Novamente\t\tDigite (0): Finalizar\n\n");

        printf("Comando desejado: ");
        scanf("%d", &continua);

        if (continua == 0){

            printf("\n\nPrograma finalizado!");
        }

    } while (continua != 0);

    return(0);
}