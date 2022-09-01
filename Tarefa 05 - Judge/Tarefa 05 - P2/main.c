# include <stdio.h>

void Receber_valor(int *valor);

void Todos_primos_ate_valor(int valor, int vetor[]);

void Decompondo_fatores_primos(int valor, int vetor[], int *soma_dos_expoentes);


int main(){

    int numero, primos_ate_numero[100000], somatorio = 0;

    Receber_valor(&numero);

    Todos_primos_ate_valor(numero, primos_ate_numero);

    Decompondo_fatores_primos(numero, primos_ate_numero, &somatorio);

    printf("Omega(%d)=%d", numero, somatorio);

    return(0);
}

void Receber_valor(int *valor){

    scanf("%d", valor);

    return;
}

void Todos_primos_ate_valor(int valor, int vetor[]){

    int teste = 1, quant_divisores, posicao = 0, i;

    while(teste <= valor){

        quant_divisores = 0;

        for (i = 1 ; i <= teste ; i++){

            if(teste % i == 0){

                quant_divisores++;
            }
        }

        if(quant_divisores == 2){

            vetor[posicao] = teste;

            posicao++;
        }

        teste++;
    }

    return;
}

void Decompondo_fatores_primos(int valor, int vetor[], int *soma_dos_expoentes){

    int i;

    for(i = 0 ; valor > 1 ; i++){

        while(valor % vetor[i] == 0){

            ++*soma_dos_expoentes;

            valor /= vetor[i];
        }
    }

    return;
}