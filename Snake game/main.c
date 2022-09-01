# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <conio.h>

# define M 60
# define N 30

int x, y, fruta_x, fruta_y, pontuacao, fim_jogo, corpo_x[1000], corpo_y[1000], tamanho;

enum {inicio = 0, esquerda, direita, cima, baixo} direcao;

void Inicializar();
void Gerar_fruta();
void Imprimir();
void Verificar_comando();
void Aplicar_movimento();
void Comer_fruta();
void Aumentar_tamanho();
void Verificar_fim_jogo();

int main(){

    srand(time(NULL));
    Inicializar();

    while(fim_jogo == 0){
        Imprimir();
        Verificar_comando();
        Comer_fruta();
        Aumentar_tamanho();
        Aplicar_movimento();
        Verificar_fim_jogo();
        _sleep(120);

        if(fim_jogo == 0){
            system("cls");
        }else{
            printf("\t\tFIM DE JOGO!\n\n\n\n\n\n");
        }
    }

    return(0);
}

void Inicializar(){

    x = M / 2;
    y = N / 2;
    pontuacao = 0;
    fim_jogo = 0;
    tamanho = 0;
    Gerar_fruta();
    direcao = inicio;

    for(int i = 0 ; i < 1000 ; i++){
        corpo_x[i] = -1;
        corpo_y[i] = -1;
    }

    return;
}

void Gerar_fruta(){

    fruta_x = rand() % M;
    fruta_y = rand() % N;

    if(fruta_x == x && fruta_y == y){
        Gerar_fruta();
    }else{
        for(int i = 0 ; i < 1000 ; i++){
            if(fruta_x == corpo_x[i] && fruta_y == corpo_y[i]){
                Gerar_fruta();
                break;
            }
        }
    }

    return;
}

void Imprimir(){

    int i, j, k;

    printf("\n\n\t\t\t\t", pontuacao);

    for(i = 0 ; i < M + 2; i++){
        if(i == 0){
            printf("%c", 201);
        }else if(i == M + 1){
            printf("%c", 187);
        }else{
            printf("%c", 205);
        }
    }

    printf("\n\t\t\t\t");

    for(i = 0 ; i < N ; i++){
        for(j = 0 ; j < M ; j++){
            if(j == 0){
                printf("%c", 186);
            }

            if(x == j && y == i){
                printf("O");
            }else if(fruta_x == j && fruta_y == i){
                printf("$");
            }else{
                for(k = 0 ; k < 1000 ; k++){
                    if(corpo_x[k] == j && corpo_y[k] == i){
                        printf("o");
                        k = -1;
                        break;
                    }
                }

                if(k != -1){
                    printf(" ");
                }
            }

            if(j == M - 1){
                printf("%c", 186);
            }
        }
        printf("\n\t\t\t\t");
    }

    for(i = 0 ; i < M + 2; i++){
        if(i == 0){
            printf("%c", 200);
        }else if(i == M + 1){
            printf("%c", 188);
        }else{
            printf("%c", 205);
        }
    }

    printf("\n\t\t\t\tPontuacao: %d", pontuacao);

    return;
}

void Verificar_comando(){

    if(_kbhit()){
        switch(getch()){
            case 'a':
                direcao = esquerda;
                break;
            case 'd':
                direcao = direita;
                break;
            case 'w':
                direcao = cima;
                break;
            case 's':
                direcao = baixo;
                break;
            default:
                break;
        }
    }

    return;
}

void Aplicar_movimento(){

    switch(direcao){
        case esquerda:
            x--;
            break;
        case direita:
            x++;
            break;
        case cima:
            y--;
            break;
        case baixo:
            y++;
            break;
        default:
            break;
    }

    return;
}

void Comer_fruta(){

    if(x == fruta_x && y == fruta_y){
        pontuacao += 10;
        tamanho++;
        Gerar_fruta();
    }

    return;
}

void Aumentar_tamanho(){

    int inicio_x, inicio_y, copia_x, copia_y;

    if(tamanho > 0){

        inicio_x = corpo_x[0];
        inicio_y = corpo_y[0];

        corpo_x[0] = x;
        corpo_y[0] = y;

        for(int i = 1 ; i < tamanho ; i++){
            copia_x = corpo_x[i];
            copia_y = corpo_y[i];
            corpo_x[i] = inicio_x;
            corpo_y[i] = inicio_y;
            inicio_x = copia_x;
            inicio_y = copia_y;
        }
    }

    return;
}

void Verificar_fim_jogo(){

    int i;

    if(x > M - 1 || x < 0 || y > N - 1 || y < 0){
        fim_jogo = 1;
    }else{
        for(i = 0 ; i < 1000 ; i++){
            if(x == corpo_x[i] && y == corpo_y[i]){
                fim_jogo = 1;
                break;
            }
        }
    }

    return;
}