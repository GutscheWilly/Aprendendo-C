# include <stdio.h>

void Ler_valores(int vetor[]);
int Maior_valor(int vetor[], int constante, int posicao);

int main(){

    int valores[10000], posicao;

    Ler_valores(valores);

    posicao = Maior_valor(valores, 0, 0);

    printf("%d", valores[posicao]);

    return(0);
}

void Ler_valores(int vetor[]){

    int i = -1;

    do{

        i++;

        scanf("%d", &vetor[i]);

    } while(vetor[i] != 0);

    return;
}

int Maior_valor(int vetor[], int constante, int posicao){

    if(vetor[constante] == 0){

        return(posicao);
        
    } else{

        if(vetor[constante] > vetor[posicao]){

            Maior_valor(vetor, constante + 1, constante);

        } else{

            Maior_valor(vetor, constante + 1, posicao);
        }
    }
}