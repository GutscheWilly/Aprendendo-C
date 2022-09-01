# include <stdio.h>
# include <time.h>

# define TAM 10

void Vetor_random(int vet[]);
void Maior_menor_valor(int vet[], int *maior, int *menor);

int main(){

    int vetor[TAM], menor, maior;

    Vetor_random(vetor);
    Maior_menor_valor(vetor, &maior, &menor);
    printf("\n\nMaior valor: %d\n", maior);
    printf("\nMenor valor: %d\n", menor);

    return(0);
}

void Vetor_random(int vet[]){

    int i;

    srand(time(NULL));

    for(i = 0 ; i < TAM ; i++){
        *(vet + i) = rand() % 101;
        printf("%d ", vet[i]);
    }

    return;
}

void Maior_menor_valor(int vet[], int *maior, int *menor){

    int i;

    *maior = vet[0];
    *menor = vet[0];

    for(i = 1 ; i < TAM ; i++){

        if(*(vet + i) > *maior){
            *maior = *(vet + i);
        }

        if(*(vet + i) < *menor){
            *menor = *(vet + i);
        }
    }

    return;
}