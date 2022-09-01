# include <stdio.h>

void Receber_dois_valores(int *ponteiro1, int *ponteiro2);
int Exponecial(int valor1, int valor2);
void Imprimir_resultado(int input1, int input2, int output);

int main(){

    int base, expoente, resultado;

    Receber_dois_valores(&base, &expoente);

    resultado = Exponecial(base, expoente);

    Imprimir_resultado(base, expoente, resultado);

    return(0);
}

void Receber_dois_valores(int *ponteiro1, int *ponteiro2){

    printf("Digite a base: ");
    scanf("%d", ponteiro1);

    printf("\n\nDigite o expoente: ");
    scanf("%d", ponteiro2);
}

int Exponecial(int valor1, int valor2){

    if(valor2 == 0){

        return(1);

    } else{

        return(valor1 * Exponecial(valor1, valor2 - 1));
    }
}

void Imprimir_resultado(int input1, int input2, int output){

    int i;

    printf("\n\n%d^%d = ", input1, input2);

    for(i = 0 ; i < input2 ; i++){

        printf("%d ", input1);

        if(i != input2 - 1){

            printf("x ");
        }
    }

    printf("= %d\n\n", output);

    return;
}