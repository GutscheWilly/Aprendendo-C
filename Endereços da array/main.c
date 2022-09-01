# include <stdio.h>
# include <time.h>

# define TAM 10

void Gerar_imprimir_vetor(int vet[]);
void Endereco_posicao(int vet[]);

int main(){

    int vetor[TAM];

    Gerar_imprimir_vetor(vetor);
    printf("\n\n");
    Endereco_posicao(vetor);

    return(0);
}

void Gerar_imprimir_vetor(int vet[]){

    int i;
    
    srand(time(NULL));

    for(i = 0 ; i < TAM ; i++){
        *(vet + i) = rand() % 101;
        printf("%d ", *(vet + i));
    }

    return;
}

void Endereco_posicao(int vet[]){

    int i;

    for(i = 0 ; i < TAM ; i++){
        printf("Posicao %d --> Valor: %d\tEndereco: %p\n\n", i, *(vet + i), (vet + i));
    }

    return;
}