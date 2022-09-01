# include <stdio.h>
# include <time.h>

# define TAM 15

void Gerar_valores(int vetor[]);
int Menor_valor_vetor(int vetor[], int tamanho, int posicao);
void Imprimir_vetor(int vetor[]);

int main(){

    int valores[TAM], posicao;

    Gerar_valores(valores);
    Imprimir_vetor(valores);
    posicao = Menor_valor_vetor(valores, TAM - 1, 0);
    printf("\n\nMenor valor: %d\n\n", posicao);

    return(0);
}

void Gerar_valores(int vetor[]){

    int i;

    srand(time(NULL));

    for(i = 0 ; i < TAM ; i++){

        vetor[i] = rand() % 101;
    }

    return;
}

int Menor_valor_vetor(int vetor[], int tamanho, int posicao){

    if(tamanho == 0){

        return(vetor[posicao]);

    } else{

        if(vetor[tamanho] > vetor[posicao]){

            return(Menor_valor_vetor(vetor, tamanho - 1, posicao));

        } else{

            return(Menor_valor_vetor(vetor, tamanho - 1, tamanho));
        }
    } 
}

void Imprimir_vetor(int vetor[]){

    int i;

    for(i = 0 ; i < TAM ; i++){

        printf("%d ", vetor[i]);
    }

    return;
}