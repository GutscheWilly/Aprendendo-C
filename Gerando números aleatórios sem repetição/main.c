# include <stdio.h>
# include <time.h>

int main(){

    int tam = 20;
    int vetor[tam], i = 0, j, num_igual;

    srand(time(NULL));

    // Definindo o vetor aleatoriamente e garantido que seus valores sejam distintos entre si:

    do{

        vetor[i] = rand() % 100;

        num_igual = 0;

        for (j = 0 ; j < i ; j++){

            if (vetor[i] == vetor[j]){

                num_igual++;
            }
        }

        if (num_igual == 0){

            i++;
        }

    } while (i < tam);

    // Imprimindo o vetor:

    for (i = 0 ; i < tam ; i++){

        printf("vetor [%d] = %d\n", i, vetor[i]);
    }

    return(0);
}