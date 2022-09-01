# include <stdio.h>

int Ler_valor();
int Verificar_primo(int valor, int constante);
void Imprimir(int valor);

int main(){

    int valor;

    valor = Ler_valor();

    Imprimir(valor);

    return(0);
}

int Ler_valor(){

    int valor;

    scanf("%d", &valor);

    return(valor);
}

int Verificar_primo(int valor, int constante){

    if(constante == valor || valor == 0){

        return(1);

    } else{

        if(valor % constante == 0){

            return(1 + Verificar_primo(valor, ++constante));
                
        } else{

            return(Verificar_primo(valor, ++constante));
        }
    }
}

void Imprimir(int valor){

    int verificacao, constante = 1;

    verificacao = Verificar_primo(valor, constante);

    if(verificacao == 2){

        printf("O número %d é primo!", valor);

    } else{

        printf("O número %d não é primo!", valor);
    }

    return;
}