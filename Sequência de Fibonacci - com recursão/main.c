# include <stdio.h>

void Receber_inteiro(int *ponteiro);
int Fibonacci(int enesimo_termo);

int main(){

    int termo_desejado, resultado;

    Receber_inteiro(&termo_desejado);

    resultado = Fibonacci(termo_desejado);

    printf("\n\nTermo %d: <<< %d >>>\n\n", termo_desejado, resultado);

    return(0);
}

void Receber_inteiro(int *ponteiro){

    printf("Digite o termo desejado da sequencia de Fibonacci: ");
    scanf("%d", ponteiro);

    return;
}

int Fibonacci(int enesimo_termo){

    if(enesimo_termo == 1){

        return(0);

    } else{

        if(enesimo_termo == 2){

            return(1);

        } else{

            return(Fibonacci((enesimo_termo - 1)) + Fibonacci((enesimo_termo - 2)));
        }
    }
}