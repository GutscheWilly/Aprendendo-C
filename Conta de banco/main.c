# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define TAM 1000

typedef struct{

    char nome[50];
    char cpf[15];
    char senha[20];
    float saldo;

}Usuario;

int main(){

    Usuario *usuario[TAM];

    char arquivo[] = {"Usuarios cadastrados.txt"};
    char arquivo_binario[] = {"binario.dat"};

    int quant_cadastros = 0, opcao, finalizar_programa = 0;

    while(finalizar_programa == 0){

        Menu();
        opcao = Opcao_menu();

        switch(opcao){

            case(1):
                quant_cadastros += Cadastrar_usuario(usuario, quant_cadastros);
                break;
            case(2):
                Logar_conta(usuario, quant_cadastros);
                break;
            case(3):
                Monstrar_cadastrados(usuario, quant_cadastros);
                break;
            case(4):
                Salvar_arquivo(arquivo, usuario, quant_cadastros);
                break;
            case(5):
                quant_cadastros = Ler_arquivo(arquivo, usuario);
                break;
            case(6):
                Salvar_arquivo_binario(arquivo_binario, usuario, quant_cadastros);
                break;
            case(7):
                quant_cadastros = Ler_arquivo_binario(arquivo_binario, usuario);
                break;
            case(8):
                Modificar_usuario_arquivo_binario(arquivo_binario, usuario, quant_cadastros);
                break;
            case(0):
                printf("\n\n<<<< Programa finalizado! >>>>\n\n");
                finalizar_programa = 1;
                break;
        }
    }

    return(0);
}

void Menu(){

    printf("\n\n");
    printf("\t (1) -> Cadastrar usuario\n");
    printf("\t (2) -> Logar em uma conta\n");
    printf("\t (3) -> Monstrar o nome dos cadastrados\n");
    printf("\t (4) -> Salvar arquivo\n");
    printf("\t (5) -> Ler arquivo\n");
    printf("\t (6) -> Salvar arquivo binario\n");
    printf("\t (7) -> Ler arquivo binario\n");
    printf("\t (8) -> Modificar arquivo binario\n");
    printf("\t (0) -> Fechar programa\n");
    printf("\n\n");

    return;
}

int Opcao_menu(){

    int escolha;

    printf("\nInsira uma das opcoes acima: ");
    scanf("%d", &escolha);

    if(escolha >= 0 && escolha <= 8){
        return(escolha);
    }else{
        printf("\n<<<< Opcao invalida! >>>>\n");
        return(Opcao_menu());
    }
}

int Cadastrar_usuario(Usuario *usuario[], int index_cadastro){

    Usuario *caminho = malloc(sizeof(Usuario));

    if(caminho != NULL){

        if(index_cadastro < TAM){
            fflush(stdin);
            printf("\nDigite seu nome: ");
            fgets(caminho->nome, 50, stdin);
            printf("\nDigite o seu CPF: ");
            fgets(caminho->cpf, 15, stdin);
            printf("\nCrie sua senha de acesso: ");
            fgets(caminho->senha, 20, stdin);
            caminho->saldo = 0;
            usuario[index_cadastro] = caminho;
            printf("\n<<<< Usuario cadastrado com sucesso! >>>>\n");
            return(1);
        }else{
            printf("\n<<<< Nao e possivel cadastrar mais usuario! Memoria cheia! >>>>\n");
            return(0);
        }

    }else{
        printf("\n<<<< Erro! Problema com alocacao de memoria! >>>>\n");
        return(0);
    }
}

void Logar_conta(Usuario *usuario[], int index_cadastro){

    char cpf_login[15], senha_login[20], escolha[5];
    int i, existe = 0, index;
    float valor;

    fflush(stdin);
    printf("\nInsira o CPF: ");
    fgets(cpf_login, 15, stdin);

    for(i = 0 ; i < index_cadastro ; i++){
        if(strcmp(cpf_login, usuario[i]->cpf) == 0){
            existe = 1;
            index = i;
            break;
        }
    }

    printf("\nInsira a senha: ");
    fgets(senha_login, 20, stdin);

    if(existe == 1){

        if(strcmp(senha_login, usuario[index]->senha) == 0){
            printf("\nNome: %sCPF: %sSaldo da conta: R$ %.2f\n\n", usuario[index]->nome, usuario[index]->cpf, usuario[index]->saldo);
            printf("\nDeseja inserir saldo à sua conta? (sim / nao): ");

            do{
                fgets(escolha, 5, stdin);

                if(strcmp(escolha, "sim\n") != 0 && strcmp(escolha, "nao\n") != 0){
                    printf("\n<<<< Escolha invalida! >>>>\n");
                }
            }while(strcmp(escolha, "sim\n") != 0 && strcmp(escolha, "nao\n") != 0);

            if(strcmp(escolha, "sim\n") == 0){
                printf("\nInsira o valor: ");
                scanf("%f", &valor);
                usuario[index]->saldo += valor;
                printf("\nSaldo atual: R$ %.2f\n", usuario[index]->saldo);
            }

        }else{
            printf("\n<<<< Senha incorreta! >>>>\n");
        }

    }else{
        printf("\n<<<< CPF nao cadastrado! >>>>\n");
    }

    return;
}

void Monstrar_cadastrados(Usuario *usuario[], int quant_cadastrados){

    int i;

    if(quant_cadastrados == 0){
        printf("\n<<<< Nao ha nenhum usuario cadastrado! >>>>\n");
    }else{
        printf("\nUsuarios cadastrados: \n\n");
        for(i = 0 ; i < quant_cadastrados ; i++){
            printf("\t%d -> %s\n", i + 1, usuario[i]->nome);
        }
    }

    return;
}

void Salvar_arquivo(char arq[], Usuario *usuario[], int quant_cadastros){

    FILE *file = fopen(arq, "w");
    int i;

    if(file != NULL){
        fprintf(file, "%d\n", quant_cadastros);
        for(i = 0 ; i < quant_cadastros ; i++){
            fprintf(file, "%s%s%s%f\n", usuario[i]->nome, usuario[i]->cpf, usuario[i]->senha, usuario[i]->saldo);
        }
        printf("\n\n<<<< Arquivo salvo! >>>>\n\n");
    }else{
        printf("\n<<<< Problema ao abrir arquivo! >>>>\n");
    }

    fclose(file);

    return;
}

int Ler_arquivo(char arq[], Usuario *usuario[]){

    FILE *file;
    int quant_cadastros, i;
    Usuario *caminho;
    
    file = fopen(arq, "r");
    caminho = malloc(sizeof(Usuario));

    if(file != NULL){
        fscanf(file, "%d\n", &quant_cadastros);
        for(i = 0 ; i < quant_cadastros ; i++){
            fgets(caminho->nome, 50, file);
            fgets(caminho->cpf, 15, file);
            fgets(caminho->senha, 20, file);
            fscanf(file, "%f\n", &caminho->saldo);
            usuario[i] = caminho;
            if(i != quant_cadastros - 1){
                caminho = malloc(sizeof(Usuario));
            }
        }
        fclose(file);
        printf("\n<<<< Arquivo lido com sucesso >>>>\n");
        return(quant_cadastros);
    }else{
        printf("\n<<<< Problema ao ler arquivo! >>>>\n");
        return(0);
    }
}

void Salvar_arquivo_binario(char arq_binario[], Usuario *usuario[], int quant_cadastros){

    FILE  *file = fopen(arq_binario, "wb");
    int i;

    if(file != NULL){
        for(i = 0 ; i < quant_cadastros ; i++){
            fwrite(usuario[i], sizeof(Usuario), 1, file);
        }
        printf("\nArquivo binario salvo com sucesso!\n");
        fclose(file);
    }else{
        printf("\nProblema ao escrever arquivo!\n");
    }
}

int Ler_arquivo_binario(char arq_binario[], Usuario *usuario[]){

    FILE *file = fopen(arq_binario, "rb");
    Usuario *usuario_lido = malloc(sizeof(Usuario));
    int quant_usuarios = 0;

    if(file != NULL){
        while(fread(usuario_lido, sizeof(Usuario), 1, file) != 0){
            usuario[quant_usuarios] = usuario_lido;
            quant_usuarios++;
            usuario_lido = malloc(sizeof(Usuario));
        }
        printf("\nArquivo binario lido com sucesso!\n");
        fclose(file);
    }else{
        printf("\nProblema ao ler arquivo binario!\n");
    }

    return(quant_usuarios);
}

void Modificar_usuario_arquivo_binario(char arq_binario[], Usuario *usuario[], int quant_cadastros){

    FILE *file = fopen(arq_binario, "wb");
    Usuario *alteracao_usuario = malloc(sizeof(Usuario));
    int index_alteracao;

    Monstrar_cadastrados(usuario, quant_cadastros);

    printf("\nDigite o indice que deseja alterar: ");
    scanf("%d", &index_alteracao);
    index_alteracao--;

    fflush(stdin);
    printf("\nDigite o novo nome: ");
    fgets(alteracao_usuario->nome, 50, stdin);
    printf("\nDigite o novo CPF: ");
    fgets(alteracao_usuario->cpf, 15, stdin);
    printf("\nDigite a nova senha: ");
    fgets(alteracao_usuario->senha, 20, stdin);
    alteracao_usuario->saldo = 0;

    if(file != NULL){
        usuario[index_alteracao] = alteracao_usuario;
        fseek(file, index_alteracao * sizeof(Usuario), SEEK_SET);
        fwrite(usuario[index_alteracao], sizeof(Usuario), 1, file);
        fclose(file);
        printf("\nUsuario alterado com sucesso!\n");
    }else{
        printf("\nErro ao alterar arquivo!\n");
    }

    return;
}