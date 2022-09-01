# include <stdio.h>

int Receber_valor();
void Calcular_multiplos(int *B, int **C, int ***D);
void Imprimir_resultados(int A, int *B, int **C, int ***D);

int main(){

    int a, *b, **c, ***d;

    a = Receber_valor();
    b = &a;
    c = &b;
    d = &c;

    Calcular_multiplos(b, c, d);
    Imprimir_resultados(a, b, c, d);

    return(0);
}

int Receber_valor(){

    int valor;

    printf("\nDigite um valor inteiro: ");
    scanf("%d", &valor);

    return(valor);
}

void Calcular_multiplos(int *B, int **C, int ***D){

    *B *= 2;
    printf("\nB: %d\n", *B);
    *B /= 2;
    **C *= 3;
    printf("\nC: %d\n", **C);
    **C /= 3;
    ***D *= 4;
    printf("\nD: %d\n\n", ***D);
    ***D /= 4;

    return;
}

void Imprimir_resultados(int A, int *B, int **C, int ***D){

    printf("\nValor inicial: %d\n", A);
    printf("\nO dobro: %d\n", *B);
    printf("\nO triplo: %d\n", **C);
    printf("\nO quadruplo: %d\n", ***D);

    return;
}