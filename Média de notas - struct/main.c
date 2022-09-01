# include <stdio.h>

struct Nascimento{

    int dia;
    int mes;
    int ano;
};

struct Informacoes{

    char nome[100];
    char instituicao[100];
    char curso[100];
    int ID;
    int CPF;
    struct Nascimento data;
};

void Quantidade_alunos(int *quant);
void Receber_nome(char vet[]);
void Receber_instituicao(char vet[]);
void Receber_curso(char vet[]);
void Receber_ID(int *valor);
void Receber_CPF(int *valor);
void Data_nascimento(int *valor1, int *valor2, int *valor3);
void Imprimir(struct Informacoes dados[], int i);

int main(){

    struct Informacoes dados[1000];

    int quantidade_alunos, i;

    Quantidade_alunos(&quantidade_alunos);

    for(i = 0 ; i < quantidade_alunos ; i++){

        Receber_nome(dados[i].nome);
        Receber_instituicao(dados[i].instituicao);
        Receber_curso(dados[i].curso);
        Receber_ID(&dados[i].ID);
        Receber_CPF(&dados[i].CPF);
        Data_nascimento(&dados[i].data.dia, &dados[i].data.mes, &dados[i].data.ano);
    }

    for(i = 0 ; i < quantidade_alunos ; i++){

        Imprimir(dados, i);
    }

    return(0);
}

void Quantidade_alunos(int *quant){

    printf("Digite a quantidade de alunos: ");
    scanf("%d", quant);
    scanf("%c");

    return;
}

void Receber_nome(char vet[]){

    printf("Digite seu nome: ");
    fgets(vet, 100, stdin);

    return;
}

void Receber_instituicao(char vet[]){

    printf("Digite a instituicao de ensino: ");
    fgets(vet, 100, stdin);

    return;
}

void Receber_curso(char vet[]){

    printf("Digite o seu curso: ");
    fgets(vet, 100, stdin);

    return;
}

void Receber_ID(int *valor){

    printf("Digite seu ID: ");
    scanf("%d", valor);
    scanf("%c");

    return;
}

void Receber_CPF(int *valor){

    printf("Digite seu CPF: ");
    scanf("%d", valor);
    scanf("%c");

    return;
}

void Data_nascimento(int *valor1, int *valor2, int *valor3){

    printf("Digite a sua data de nascimento no formato dd/mm/aaaa : ");
    scanf("%d/%d/%d", valor1, valor2, valor3);
    scanf("%c");

    return;
}

void Imprimir(struct Informacoes dados[], int i){

    printf("Nome: %s", dados[i].nome);
    printf("Instituicao: %s", dados[i].instituicao);
    printf("curso: %s", dados[i].curso);
    printf("ID: %d\n", dados[i].ID);
    printf("CPF: %d\n", dados[i].CPF);
    printf("Data de nascimento: %d/%d/%d\n\n", dados[i].data.dia, dados[i].data.mes, dados[i].data.ano);

    return;
}