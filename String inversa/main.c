# include <stdio.h>
# include <string.h>

void Ler_string(char str[]);
void Inverter_string(char str[]);

int main(){

    char string[100];

    while(1){

        Ler_string(string);
        printf("\nOriginal: %s", string);
        Inverter_string(string);
        printf("\t\tInvertida: %s\n\n\n", string);
    }

    return(0);
}

void Ler_string(char str[]){

    printf("Digite uma frase: ");
    fgets(str, 100, stdin);
    str[strlen(str) - 1] = '\0';

    return;
}

void Inverter_string(char str[]){

    int tam, i;
    char copia;

    tam = strlen(str);

    for(i = 0 ; i < tam/2 ; i++){
        copia = str[i];
        str[i] = str[tam - 1 - i];
        str[tam - 1 - i] = copia;
    }

    return;
}