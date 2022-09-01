# include <stdio.h>
# include <time.h>

void Tamanho_vetor(int *endereco);
void Vetor_aleatorio(int vet[], int tam);
void Trocar_posicao(int vet[], int inicio, int fim);
void Imprimir_vetor(int vet[], int tam);

int main(){

    int vetor[1000], tamanho;

    Tamanho_vetor(&tamanho);

    Vetor_aleatorio(vetor, tamanho);

    printf("\n\nVetor original ---> ");
    Imprimir_vetor(vetor, tamanho);

    Trocar_posicao(vetor, 0, tamanho - 1);

    printf("\n\n\nVetor invertido ---> ");
    Imprimir_vetor(vetor, tamanho);

    printf("\n\n");

    return(0);
}

void Tamanho_vetor(int *endereco){

    printf("Digite o tamanho do vetor: ");
    scanf("%d", endereco);

    return;
}

void Vetor_aleatorio(int vet[], int tam){

    int i;

    srand(time(NULL));

    for(i = 0 ; i < tam ; i++){

        vet[i] = rand() % 101;
    }

    return;
}

void Trocar_posicao(int vet[], int inicio, int fim){

    int copia;

    if(inicio < fim){

        copia = vet[inicio];

        vet[inicio] = vet[fim];

        vet[fim] = copia;

        Trocar_posicao(vet, inicio + 1, fim - 1);
    }

    return;
}

void Imprimir_vetor(int vet[], int tam){

    int i;

    for(i = 0  ; i < tam ; i++){

        printf("%d", vet[i]);

        if(i != tam - 1){

            printf(" , ");
        }
    }

    return;
}