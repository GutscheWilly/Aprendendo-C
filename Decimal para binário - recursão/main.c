# include <stdio.h>

void Receber_valor(int *endereco);
void Binario(int valor, int vetor[], int posicao, int *endereco);
void Imprimir_vetor(int vetor[], int tamanho);

int main(){

    int vetor[1000], numero, tamanho;

    Receber_valor(&numero);

    Binario(numero, vetor, 0, &tamanho);

    printf("\n\nValor em decimal --->  %d", numero);

    printf("\n\nValor em binario --->  ");

    Imprimir_vetor(vetor, tamanho);

    return(0);
}

void Receber_valor(int *endereco){

    printf("Digite um valor inteiro: ");
    scanf("%d", endereco);

    return;
}

void Binario(int valor, int vetor[], int posicao, int *endereco){

    if(valor == 1 || valor == 0){

        vetor[posicao] = valor % 2;

        *endereco = posicao;

    }else{

        vetor[posicao] = valor % 2;

        Binario(valor / 2, vetor, posicao + 1, endereco);
    }

    return;
}

void Imprimir_vetor(int vetor[], int tamanho){

    int i;

    for(i = tamanho ; i >= 0 ; i--){

        printf("%d", vetor[i]);
    }

    return;
}