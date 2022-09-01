# include <stdio.h>

void Receber_numero(int *ponteiro);
void Imprimindo_valores_ate_numero(int valor);

int main(){

    int numero;

    Receber_numero(&numero);

    Imprimindo_valores_ate_numero(numero);
    
    return(0);
}

void Receber_numero(int *ponteiro){

    printf("Digite um valor inteiro: ");
    scanf("%d", ponteiro);

    return;
}

void Imprimindo_valores_ate_numero(int valor){

    if(valor == 0){

        printf("%d ", valor);

    }else {

        Imprimindo_valores_ate_numero(valor - 1);
        printf("%d ", valor);
    }

    return;
}