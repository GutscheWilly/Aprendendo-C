# include <stdio.h>

void imprimir_string (char vetor[]){

    printf("\n\nString: %s\n\n", vetor);
}

int main(){

    char frase[100];

    printf("Digite uma frase: ");
    scanf("%100[^\n]", frase);

    imprimir_string(frase);

    return(0);
}