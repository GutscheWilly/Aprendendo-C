# include <stdio.h>
# include <time.h>

void Tamanho_vetor(int *endereco);
void Vetor_aleatorio(int vetor[], int tamanho);
void Imprimir_vetor(int vetor[], int tamanho);
int Maior_valor(int vetor[], int tamanho, int indice);

int main(){

    int vetor[1000], tamanho, maior_valor;

    Tamanho_vetor(&tamanho);

    Vetor_aleatorio(vetor, tamanho);

    Imprimir_vetor(vetor, tamanho);

    maior_valor = Maior_valor(vetor, tamanho, 0);

    printf("\n\n\nMaior valor = %d\n\n", maior_valor);

    return(0);
}

void Tamanho_vetor(int *endereco){

    printf("\n\nDigite o tamanho do vetor: ");
    scanf("%d", endereco);

    return;
}

void Vetor_aleatorio(int vetor[], int tamanho){

    int i;

    srand(time(NULL));

    for(i = 0 ; i < tamanho ; i++){

        vetor[i] = rand() % 101;
    }

    return;
}

void Imprimir_vetor(int vetor[], int tamanho){

    int i;

    printf("\n\nVetor ---> ");

    for(i = 0 ; i < tamanho ; i++){

        printf("%d", vetor[i]);

        if(i != tamanho - 1){

            printf(" , ");
        }
    }

    return;
}

int Maior_valor(int vetor[], int tamanho, int indice){

    if(tamanho == 1){

        return(vetor[indice]);

    }else{

        if(vetor[tamanho - 1] > vetor[indice]){

            return(Maior_valor(vetor, tamanho - 1, tamanho - 1));

        }else{

            return(Maior_valor(vetor, tamanho - 1, indice));
        }
    }
}