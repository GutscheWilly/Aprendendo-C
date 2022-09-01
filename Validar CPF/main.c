# include <stdio.h>
# include <string.h>

# define TAM 10000

typedef struct{
    
    char nome[50];
    char CPF[20];
    char data_nascimeto[20];

} Pessoa;

Pessoa Inicializar_pessoa();
Pessoa Cadastro_pessoa();
void Imprimir_menu();
int Opcao_menu();
void Imprimir_cadastrados(Pessoa pessoa[]);
void Excluir_cadastro(Pessoa pessoa[]);

int main(){

    Pessoa cadastro[TAM];
    int i, opcao,  fechar = 0;

    for(i = 0 ; i < TAM ; i++){
        cadastro[i] = Inicializar_pessoa();
    }

    i = 0;

    while(fechar == 0){

        Imprimir_menu();
        opcao = Opcao_menu();

        switch(opcao){

            case(1):
                cadastro[i] = Cadastro_pessoa();
                i++;
                break;

            case(2):
                Imprimir_cadastrados(cadastro);
                break;

            case(3):
                Excluir_cadastro(cadastro);
                break;

            case(0):
                printf("\n\nPrograma finalizado!\n\n");
                fechar = 1;
                break;
        }
    }

    return(0);
}

Pessoa Inicializar_pessoa(){

    Pessoa pessoa;

    strcpy(pessoa.nome, "\0");
    strcpy(pessoa.CPF, "\0");
    strcpy(pessoa.data_nascimeto, "\0");

    return(pessoa);
}

Pessoa Cadastro_pessoa(){

    Pessoa pessoa;

    printf("\nDigite o nome: ");
    fflush(stdin);
    fgets(pessoa.nome, 50, stdin);
    pessoa.nome[strlen(pessoa.nome) - 1] = '\0';
    printf("\nDigite o CPF: ");
    fgets(pessoa.CPF, 20, stdin);
    pessoa.CPF[strlen(pessoa.CPF) - 1] = '\0';
    printf("\nDigite a data de nascimento: ");
    fgets(pessoa.data_nascimeto, 20, stdin);
    pessoa.data_nascimeto[strlen(pessoa.data_nascimeto) - 1] = '\0';
    printf("\n\nCadastro realizado com sucesso!\n\n");

    return(pessoa);
}

void Imprimir_menu(){

    printf("\n\n\t(1) - Cadastrar uma pessoa\n");
    printf("\t(2) - Monstra pessoas cadastradas\n");
    printf("\t(3) - Excluir pessoa cadastrada\n");
    printf("\t(0) - Sair\n\n");

    return;
}

int Opcao_menu(){

    int opcao;

    printf("\nInsira uma opcao: ");
    scanf("%d", &opcao);

    if(opcao >= 0 || opcao <= 3){
        return(opcao);
    }else{
        printf("\nOpcao invalida!\n");
        return(Opcao_menu());
    }
}

void Imprimir_cadastrados(Pessoa pessoa[]){

    int i, vazio = 1;

    for(i = 0 ; i < TAM ; i++){
        if(strcmp(pessoa[i].nome, "\0") != 0){
            printf("\n\nNome: %s\t", pessoa[i].nome);
            printf("CPF: %s\t", pessoa[i].CPF);
            printf("Data de nascimeto: %s\n", pessoa[i].data_nascimeto);
            vazio = 0;
        }
    }

    if(vazio == 1){
        printf("\nNao ha pessoas cadastradas!\n");
    }

    return;
}

void Excluir_cadastro(Pessoa pessoa[]){

    char cpf[20];
    int i;

    printf("\nDigite o CPF do usuario a ser excluido: ");
    fflush(stdin);
    fgets(cpf, 20, stdin);
    cpf[strlen(cpf) - 1] = '\0';

    for(i = 0 ; i < TAM ; i++){
        if(strcmp(cpf, pessoa[i].CPF) == 0){
            printf("\nO Cadastro de %s foi excluido!\n", pessoa[i].nome);
            pessoa[i] = Inicializar_pessoa();
            i = -1;
            break;
        }
    }

    if(i != -1){
        printf("\nCPF informado nao possui cadastro!\n");
    }

    return;
}