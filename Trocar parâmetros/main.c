# include <stdio.h>
# include <time.h>

void Troca(int *valor1, int *valor2);

int main(){

    int valor1, valor2;

    srand(time(NULL));

    valor1 = rand() % 101;
    valor2 = rand() % 101;

    printf("\nAntes -->  \tvalor 1: %d\tvalor 2: %d\n", valor1, valor2);
    Troca(&valor1, &valor2);
    printf("\nDepois --> \tvalor 1: %d\tvalor 2: %d\n\n", valor1, valor2);

    return(0);
}

void Troca(int *valor1, int *valor2){

    int copia;

    copia = *valor1;
    *valor1 = *valor2;
    *valor2 = copia;

    return;
}