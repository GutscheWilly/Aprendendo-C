# include <stdio.h>
# include <string.h>
# include <math.h>
 
# define TAM 100
 
typedef struct{
 
    char nome[TAM];
    long long int telefone;
 
} Contato;
 
void Atribuir_NULL(Contato contato[]);
void Imprimir_menu();
int Ler_opcao_usuario();
int Ler_indice();
Contato Ler_contato();
void Imprimir_todos_contatos(Contato contato[]);
void Imprimir_unico_contato(Contato contato[]);
void Apagar_contato_indice(Contato contato[]);
void Apagar_contato_nome(Contato contato[]);
 
int main(){
 
    Contato agenda[TAM];
 
    int indice, opcao_usuario, sair = 0;
 
    Atribuir_NULL(agenda);
 
    while(sair == 0){
 
        //Imprimir_menu();
        opcao_usuario = Ler_opcao_usuario();
 
        switch(opcao_usuario){
 
            case(1):
 
                indice = Ler_indice();

                if(indice > -1){

                    agenda[indice] = Ler_contato();
                }

                break;
 
            case(2):
 
                Imprimir_todos_contatos(agenda);
                break;
 
            case(3):
 
                Imprimir_unico_contato(agenda);
                break;
 
            case(4):
 
                Apagar_contato_indice(agenda);
                break;
 
            case(5):
 
                Apagar_contato_nome(agenda);
                break;
 
            case(0):
 
                printf("\nTchau!");
                sair = 1;
        }
    }
 
    return(0);
}
 
void Atribuir_NULL(Contato contato[]){
 
    int i;
 
    for(i = 0 ; i < TAM ; i++){
 
        strcpy(contato[i].nome, "NULL");
    }
 
    return;
}
 
void Imprimir_menu(){
 
    printf("\n(1) - Cadastra nome e numero\n");
    printf("(2) - Listar todos os contatos salvos\n");
    printf("(3) - Mostrar um contato\n");
    printf("(4) - Apagar contato pelo numero/indice\n");
    printf("(5) - Apagar um contato pelo nome\n");
    printf("(0) - Sair\n\n");
 
    return;
}
 
int Ler_opcao_usuario(){
 
    int escolha;
 
    do{
 
        //printf("Digite a opcao desejada: ");
        scanf("%d", &escolha);
 
        if(escolha < 0 || escolha > 5){
 
            printf("\nEscolha valores entre 0 e 5!\n");
        }
 
    } while(escolha < 0 || escolha > 5);
 
    return(escolha);    
}
 
int Ler_indice(){
 
    int index;
 
    //printf("\nDigite um indice de 1 a 100: ");

    scanf("%d", &index);
    
    if(index < 1 || index > 100){
    
        printf("\nÍndice digitado não existe [1,100]!\n");

        index = -1;
    }

    return(index - 1);    
}
 
Contato Ler_contato(){
 
    Contato contato;
 
    int i;
 
    //printf("\nDigite o nome: ");
    scanf("%s", contato.nome);
 
    do{
 
        scanf("%lld", &contato.telefone);

        if(contato.telefone < pow(10, 9) || contato.telefone >= pow(10, 11)){

            printf("\nTelefone não tem 10 ou 11 dígitos! Favor digite novamente.\n");
        }
 
    } while(contato.telefone < pow(10, 9) || contato.telefone >= pow(10, 11));
 
    printf("\nContato cadastrado com sucesso!\n");
 
    return(contato);
}
 
void Imprimir_todos_contatos(Contato contato[]){
 
    int i, quant_contatos = 0;
 
    for(i = 0 ; i < TAM ; i++){
 
        if(strcmp(contato[i].nome, "NULL") != 0){
 
            printf("\nContato[%d]- Nome:%s Tel:%lld\n", i + 1, contato[i].nome, contato[i].telefone);
            quant_contatos++;
        }
    }
 
    if(quant_contatos == 0){
 
        printf("\nAgenda vazia!\n");
    }
 
    return;
}
 
void Imprimir_unico_contato(Contato contato[]){
 
    int index, quant_contatos = 0, i;
 
    for(i = 0 ; i < TAM ; i++){
 
        if(strcmp(contato[i].nome, "NULL") != 0){
 
            quant_contatos++;
        }
    }
 
    if(quant_contatos == 0){
 
        printf("\nAgenda vazia!\n");
 
    } else{
 
        scanf("%d", &index);

        if(index < 1 || index > 100){

            printf("\nÍndice digitado não existe [1,100]!\n");

        } else{
 
            if(strcmp(contato[index - 1].nome, "NULL") != 0){
    
                printf("\nContato[%d]- Nome:%s Tel:%lld\n", index, contato[index - 1].nome, contato[index - 1].telefone);
    
            } else{
    
                printf("\nÍndice digitado está vazio!\n");
            }
        }
    }
 
    return;
}
 
void Apagar_contato_indice(Contato contato[]){
 
    int index, i;

    scanf("%d", &index);

    if(index < 1 || index > 100){

        printf("\nÍndice digitado não existe [1,100]!\n");

    } else{
 
        if(strcmp(contato[index - 1].nome, "NULL") != 0){
    
            strcpy(contato[index - 1].nome, "NULL");
            printf("\nContato removido com sucesso!\n");

            for(i = 0 ; i < TAM ; i++){
 
                if(strcmp(contato[i].nome, "NULL") != 0){
 
                    printf("\nContato[%d]- Nome:%s Tel:%lld\n", i + 1, contato[i].nome, contato[i].telefone);
                }
            }
    
        } else{
    
            printf("\nÍndice digitado está vazio!\n");
        }
    }
    
    return;
}
 
void Apagar_contato_nome(Contato contato[]){
 
    char string[TAM];
 
    int existe = 0, i;
 
    //printf("\nDigite o nome: ");
    scanf("%s", string);
 
    for(i = 0 ; i < TAM ; i++){
 
        if(strcmp(contato[i].nome, string) == 0){
 
            strcpy(contato[i].nome, "NULL");
            printf("\nContato removido com sucesso!\n");

            for(i = 0 ; i < TAM ; i++){
 
                if(strcmp(contato[i].nome, "NULL") != 0){
 
                    printf("\nContato[%d]- Nome:%s Tel:%lld\n", i + 1, contato[i].nome, contato[i].telefone);
                }
            }
            
            existe = 1;
        }
    }
 
    if(existe == 0){
    
        printf("\nContato digitado não existe!\n");
    }
    
    return;
}