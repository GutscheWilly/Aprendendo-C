# include <stdio.h>
# include <stdlib.h>
# include <string.h>

void Receber_nome_arquivo(char nome[]);
void Escrever_arquivo(char nome[]);
void Ler_arquivo(char nome[]);

int main(){

    char arquivo[50];

    Receber_nome_arquivo(arquivo);
    Escrever_arquivo(arquivo);
    Ler_arquivo(arquivo);

    return(0);
}

void Receber_nome_arquivo(char nome[]){

    printf("\n\nDigite o nome do arquivo: ");
    fgets(nome, 50, stdin);
    nome[strlen(nome) - 1] = '\0';

    return;
}

void Escrever_arquivo(char nome[]){

    FILE *file;
    char letra;

    file = fopen(nome, "w");

    if(file != NULL){
        printf("\n\nEscreva no arquivo:\n\n");

        do{
            scanf("%c", &letra);
            fputc(letra, file);
        }while(letra != '\n');

        fclose(file);

    }else{
        printf("\n\nProblema ao abrir arquivo!\n\n");
    }

    return;
}

void Ler_arquivo(char nome[]){

    FILE *file;
    char letra;

    file = fopen(nome, "r");

    if(file != NULL){
        printf("\n\nLeitura do arquivo:\n\n");

        while(!feof(file)){
            letra = fgetc(file);
            printf("%c", letra);
        }

        fclose(file);

    }else{
        printf("\n\nProblema ao abrir arquivo!\n\n");
    }
}