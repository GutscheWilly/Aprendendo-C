# include <stdio.h>

typedef struct{

    int notas[10000];
    int tam;
    float media;

} Notas;

Notas Ler_valores();
float Calcular_Media(Notas valor, int posicao);



int main(){

    Notas valores;

    valores = Ler_valores();

    printf("A media aritmética dos %d valores é: %.1f", valores.tam, valores.media);

    return(0);
}

Notas Ler_valores(){

    Notas valor;

    int  i = -1;

    do{

        i++;

        scanf("%d", &valor.notas[i]);

    } while(valor.notas[i] != 0);

    valor.tam = i;

    valor.media =  Calcular_Media(valor, 0);

    return(valor);
}

float Calcular_Media(Notas valor, int posicao){

    if(posicao == valor.tam){

        return(0);

    } else{

        if(posicao != 0){

            return(valor.notas[posicao] + Calcular_Media(valor, posicao + 1));

        } else{

            return((valor.notas[posicao] + Calcular_Media(valor, posicao + 1)) / valor.tam);
        }
    }
}