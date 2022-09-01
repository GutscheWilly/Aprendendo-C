# include <stdio.h>

typedef struct{

    int codigo;
    float saldo;
    char tipo;

} Projeto;

void Iniciarlizar_projetos(Projeto projeto[]);
int Receber_numero_projeto();
void Ler_dados(Projeto projeto[], int numero);
void Imprimir_saldos(Projeto projeto[]);

int main(){

    Projeto projeto[10];

    int numero_projeto;

    Iniciarlizar_projetos(projeto);

    do{

        numero_projeto = Receber_numero_projeto();

        if(numero_projeto != -1){

            Ler_dados(projeto, numero_projeto);
        }

    } while(numero_projeto != -1);

    Imprimir_saldos(projeto);

    return(0);
}

void Iniciarlizar_projetos(Projeto projeto[]){

    int i;

    for(i = 0 ; i < 10 ; i++){

        projeto[i].codigo = i;
        projeto[i].saldo = 0;
        projeto[i].tipo = ' ';

    }

    return;
}

int Receber_numero_projeto(){

    int numero;

    do{

        printf("\nDigite o numero do projeto: ");
        scanf("%d", &numero);

        if(numero < -1 || numero > 9){

            printf("\nNumero do projeto nao existe!\n");
        }

    } while(numero < -1 || numero > 9);

    return(numero);
}

void Ler_dados(Projeto projeto[], int numero){

    float valor;

    printf("\nSaldo atual do Projeto %d: $ %.2f\n", projeto[numero].codigo, projeto[numero].saldo);

    do{

        printf("\nDigite 'R' Receita ou 'D' Despesa: ");
        
        scanf("%c", &projeto[numero].tipo);
        scanf("%c");

        if(projeto[numero].tipo != 'R' && projeto[numero].tipo != 'D'){

            printf("\nInformacao invalida!\n");
        }

    } while(projeto[numero].tipo != 'R' && projeto[numero].tipo != 'D');

    if(projeto[numero].tipo == 'R'){

        printf("\nDigite o valor da receita: ");
        scanf("%f", &valor);

        projeto[numero].saldo += valor;

    } else{

        printf("\nDigite o valor da despesa: ");
        scanf("%f", &valor);

        projeto[numero].saldo -= valor;
    }

    return;
}

void Imprimir_saldos(Projeto projeto[]){

    int i;

    for(i = 0 ; i < 10 ; i++){

        printf("\nSaldo final do projeto %d: $ %.2f\n", i, projeto[i].saldo);
    }

    return;
}