# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct{

    char nome[30];
    int nota;

}Aluno;

int Receber_quatidade_alunos();
void Cadastra_aluno(Aluno *alunos, int quant_alunos);
void Imprimir(Aluno *alunos, int quant_alunos);

int main(){

    Aluno *alunos;
    int quant_alunos;

    quant_alunos = Receber_quatidade_alunos();
    alunos = malloc(quant_alunos * sizeof(int));
    Cadastra_aluno(alunos, quant_alunos);
    Imprimir(alunos, quant_alunos);
    free(alunos);

    return(0);
}

int Receber_quatidade_alunos(){

    int quant;

    printf("\n\nDigite quantos alunos deseja cadastrar: ");
    scanf("%d", &quant);

    return(quant);
}

void Cadastra_aluno(Aluno *alunos, int quant_alunos){

    int i;

    for(i = 0 ; i < quant_alunos ; i++){
        printf("\n\nDigite o nome do aluno %d: ", i + 1);
        fflush(stdin);
        fgets((alunos + i)->nome, 30, stdin);
        (alunos + i)->nome[strlen((alunos + i)->nome) - 1] = '\0';
        printf("Digite a nota do alunos %d: ", i + 1);
        scanf("%d", &(alunos + i)->nota);
    }

    return;
}

void Imprimir(Aluno *alunos, int quant_alunos){

    int i;

    for(i = 0 ; i < quant_alunos ; i++){
        printf("\nAluno %d -> Nome: %s   nota: %d\n", i + 1, (alunos + i)->nome, (alunos + i)->nota);
    }

    return;
}   