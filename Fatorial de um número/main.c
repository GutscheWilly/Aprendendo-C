# include <stdio.h>

void Receber_inteiro(int *ponteiro);
int Fatorial(int valor);

int main(){

    int numero, resultado;

    Receber_inteiro(&numero);

    resultado = Fatorial(numero);

    printf("\n\nFatorial: %d\n\n", resultado);

    return(0);
}

void Receber_inteiro(int *ponteiro){

    printf("Digite um valor inteiro: ");
    scanf("%d", ponteiro);

    return;
}

int Fatorial(int valor){

    if(valor == 0 || valor == 1){

        valor = 1;

    } else{

        valor *= Fatorial(valor - 1);
    }

    return(valor);
}