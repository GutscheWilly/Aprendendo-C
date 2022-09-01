# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <string.h>

int Receber_tamanho();
void Atribuir_valores(int *vetor, int tamanho, int tamanho2);
void Imprimir_valores(int *vetor, int tamanho);
int verificar_alteracao();

int main(){

    int tam, tam2 = 0, *vet, alterar_tam = 1;

    srand(time(NULL));
    tam = Receber_tamanho();
    vet = calloc(tam, sizeof(int));

    while(alterar_tam){

        if(vet){
            Atribuir_valores(vet, tam, tam2);
            Imprimir_valores(vet, tam);
            printf("\n\nMemoria alocada com sucesso!\n");
            alterar_tam = verificar_alteracao();

            if(alterar_tam){
                tam2 = tam;
                tam = Receber_tamanho();
                vet = realloc(vet, tam * sizeof(int));
            }else{
                free(vet);
            }
        }else{
            printf("\nFalha com alocacao de memoria!\n");
            free(vet);
            alterar_tam = 0;
        }
    }

    return(0);
}

int Receber_tamanho(){

    int tamanho;

    printf("\nDigite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    return(tamanho);
}

void Atribuir_valores(int *vetor, int tamanho, int tamanho2){

    int i;

    for(i = tamanho2 ; i < tamanho ; i++){
        *(vetor + i) = rand() % 101;
    }

    return;
}

void Imprimir_valores(int *vetor, int tamanho){

    int i;

    printf("\nVetor de tamanho %d:\t", tamanho);

    for(i = 0 ; i < tamanho ; i++){
        printf("%d ", vetor[i]);
    }

    return;
}

int verificar_alteracao(){

    char escolha[4];

    printf("\n\nDeseja altera o tamanho do vetor? (sim / nao): ");
    fflush(stdin);
    fgets(escolha, 4, stdin);

    if(strcmp(escolha, "sim") == 0){
        return(1);
    }else if(strcmp(escolha, "nao") == 0){
        printf("\n\nPrograma finalizado!\n");
        return(0);
    }else{
        printf("\nComando invalido!\n");
        return(verificar_alteracao());
    }
}