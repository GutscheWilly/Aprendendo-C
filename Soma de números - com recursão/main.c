# include <stdio.h>

void Receber_numero(int *endereco);
int Soma(int valor);
void Imprimir_resultado(int input, int output);

int main(){

    int numero, soma;

    Receber_numero(&numero);

    soma = Soma(numero);

    Imprimir_resultado(numero, soma);

    return(0);
}

void Receber_numero(int *endereco){

    printf("Digite um valor inteiro: ");
    scanf("%d", endereco);

    return;
}

int Soma(int valor){

    if(valor == 0){

        return(0);

    } else{

        return(valor + Soma(valor - 1));
    }
}

void Imprimir_resultado(int input, int output){

    printf("\n\nSoma de todos os valores de 0 ate %d ---> %d\n\n", input, output);

    return;
}