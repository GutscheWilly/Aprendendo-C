# include <stdio.h>
# include <stdlib.h>
# include <string.h>

void Menu();
int Receber_opcao();
void Receber_nome_arquivo(char arquivo[]);
void Adicionar_aniversario(char arquivo[]);
void Ler_arquivo(char arquivo[]);

int main(){

    char nome_arquivo[50];
    int opcao, fim = 0;

    Receber_nome_arquivo(nome_arquivo);

    while(fim == 0){

        Menu();
        opcao = Receber_opcao();
        system("cls");
        _sleep(500);

        switch(opcao){

            case(1):
                Adicionar_aniversario(nome_arquivo);
                break;
            case(2):
                Ler_arquivo(nome_arquivo);
                break;
            case(3):
                Receber_nome_arquivo(nome_arquivo);
                break;
            case(0):
                printf("\n\n<<<< Programa finalizado! >>>>\n\n");
                fim = 1;
                break;
            default:
                break;
        }
    }

    return(0);
}

void Menu(){

    printf("\n\n\n");
    printf("\t(1) -> Adicionar data de aniversario\n");
    printf("\t(2) -> Monstrar datas de aviversario\n");
    printf("\t(3) -> Mudar arquivo\n");
    printf("\t(0) -> Fechar programa\n");
    printf("\n\n");

    return;
}

int Receber_opcao(){

    int valor;

    printf("Digite uma das opcoes: ");
    scanf("%d", &valor);

    if(valor >= 0 && valor <= 3){
        return(valor);
    }else{
        printf("\n<<<< Opcao invalida! >>>>\n");
        return(Receber_opcao());
    }
}

void Receber_nome_arquivo(char arquivo[]){

    printf("\nDigite o nome do arquivo a ser aberto: ");
    fflush(stdin);
    fgets(arquivo, 50, stdin);
    arquivo[strlen(arquivo) - 1] = '\0';

    return;
}

void Adicionar_aniversario(char arquivo[]){

    FILE *file;
    char nome[30];
    int dia, mes, ano;

    file = fopen(arquivo, "a");

    if(file != NULL){

        // Obtendo entradas do usuário
        printf("\n\nDigite o nome do aniversariante: ");
        fflush(stdin);
        fgets(nome, 30, stdin);
        printf("Digite a data de aniversario (DD MM AAAA): ");
        scanf("%d%d%d", &dia, &mes, &ano);

        // Adicionando essas entradas ao arquivo
        fprintf(file, "%s%d %d %d\n", nome, dia, mes, ano);
        fclose(file);

    }else{
        printf("\n\n<<<< Problema ao abrir arquivo! >>>>\n\n");
    }

    return;
}

void Ler_arquivo(char arquivo[]){

    FILE *file;
    char nome[30];;
    int dia, mes, ano;

    file = fopen(arquivo, "r");

    if(file != NULL){

        while(!feof(file)){

            if(fgets(nome, 30, file) != 0){
                nome[strlen(nome) -1] = '\0';
                printf("\nNome: %s ", nome);
                
                if(fscanf(file, "%d%d%d", &dia, &mes, &ano)){
                    printf("\tData de aniversario: %d/%d/%d\n", dia, mes, ano);
                }

                fgets(nome, 30, file);
            }
        }

        fclose(file);

    }else{
        printf("\n\n<<<< Arquivo encontra-se vazio! >>>>\n\n");
    }

    return;
}