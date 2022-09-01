# include <stdio.h>

void strcpy(char *destino, char *copia);

int main(){

    char string1[100], string2[100];

    scanf("%100[^\n]", string1);
    fflush(stdin);
    scanf("%100[^\n]", string2);

    printf("\nstring 1: %s\n", string1);
    printf("\nstring 2: %s\n", string2);
    strcpy(string1, string2);
    printf("\nstring 1: %s\n", string1);
    printf("\nstring 2: %s\n", string2);

    return(0);
}

void strcpy(char *destino, char *copia){

    int i = -1;

    do{
        i++;
        *(destino + i) = *(copia + i);

    } while(*(copia + i) != '\0');

    return; 
}