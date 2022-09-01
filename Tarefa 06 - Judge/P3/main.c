# include <stdio.h>

void Receber_string(char str[]);
void Inverter_string(char str[]);

int main(){

    char string[100];

    Receber_string(string);

    Inverter_string(string);

    printf("%s", string);



    return(0);
}

void Receber_string(char str[]){

    gets(str);

    return;
}

void Inverter_string(char str[]){

    char copia;

    int i, tamanho;

    tamanho = strlen(str);

    for(i = 0 ; i < tamanho / 2 ; i++){

        copia = str[i];

        str[i] = str[tamanho - 1 - i];

        str[tamanho - 1 - i] = copia;
    }

    return;
}