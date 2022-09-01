# include <stdio.h>

int Ler_valor();
int Fatorial(int valor);
void Imprimir_resultado(int valor);


int main(){

    int valor;

    valor = Ler_valor();

    Imprimir_resultado(valor);

    return(0);
}

int Ler_valor(){

    int valor;

    scanf("%d", &valor);

    return(valor);
}

int Fatorial(int valor){

    if(valor == 0){

        return(1);

    } else{

        return(valor * Fatorial(valor - 1));
    }
}

void Imprimir_resultado(int valor){

    int resultado;

    if(valor < 0){

        printf("Não existe fatorial de %d", valor);

    } else{

        resultado = Fatorial(valor);

        printf("O fatorial de %d é: %d", valor, resultado);
    }

    return;
}