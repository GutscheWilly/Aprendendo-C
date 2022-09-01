# include <stdio.h>

void Receber_termo(int *ponteiro);
int Fibonacci(int valor);
void Imprimir_resultado(int input, int output);

int main(){

    int termo_desejado, resultado;

    Receber_termo(&termo_desejado);

    resultado = Fibonacci(termo_desejado);

    Imprimir_resultado(termo_desejado, resultado);

    return(0);
}

void Receber_termo(int *ponteiro){

    printf("Digite um valor inteiro: ");
    scanf("%d", ponteiro);

    return;
}

int Fibonacci(int valor){

    int vetor[100000] = {0, 1}, i;

    for(i = 2 ; i < valor ; i++){

        vetor[i] = vetor[i - 1] + vetor[i - 2];
    }

    return(vetor[valor - 1]);
}

void Imprimir_resultado(int input, int output){

    printf("\n\nTermo %d: ---> %d\n\n", input, output);

    return;
}