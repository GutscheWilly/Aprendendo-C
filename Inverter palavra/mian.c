# include <stdio.h>
# include <stdlib.h>
# include <string.h>

void Receber_string(char *str);
void Inverte_string(char *str);

int main(){

    char *string;

    string = malloc(101 * sizeof(char));
    Receber_string(string);
    printf("\n\nFrase original: %s", string);
    Inverte_string(string);
    printf("\n\nFrase invertida: %s\n\n", string);

    return(0);
}

void Receber_string(char *str){

    printf("\n\nDigite uma frase: ");
    fflush(stdin);
    fgets(str, 101, stdin);
    str[strlen(str) - 1] = '\0';

    return;
}

void Inverte_string(char *str){

    int tam, i;
    char copia;

    tam = strlen(str);

    for(i = 0 ; i < tam / 2 ; i++){
        copia = *(str + i);
        *(str + i) = *(str + (tam - 1 - i));
        *(str + (tam - 1 - i)) = copia;
    }

    return;
}