# include <stdio.h>
# include <string.h>

void Receber_inteiro(int *ponteiro);
void Converter_inteiro_em_texto(int *ponteiro);

int main(){

    int numero;

    Receber_inteiro(&numero);

    Converter_inteiro_em_texto(&numero);

    return(0);
}

void Receber_inteiro(int *ponteiro){

    printf("Digite um valor inteiro: ");
    scanf("%d", ponteiro);

    return;
}

void Converter_inteiro_em_texto(int *ponteiro){

    printf("\n\nO valor %d representa em texto: %c\n\n", *ponteiro, *ponteiro);

    return;
}