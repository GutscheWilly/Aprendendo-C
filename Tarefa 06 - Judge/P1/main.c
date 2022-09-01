# include <stdio.h>

void Receber_duas_string(char str1[], char str2[]);
int Hash(char str[]);



int main(){

    char string1[100], string2[100];

    int hash1, hash2;

    Receber_duas_string(string1, string2);

    hash1 = Hash(string1);

    hash2 = Hash(string2);

    printf("Str1: %s - Codificaçao Hash: %d\n", string1, hash1);

    printf("Str2: %s - Codificaçao Hash: %d\n", string2, hash2);

    return(0);
}

void Receber_duas_string(char str1[], char str2[]){

    gets(str1);

    gets(str2);

    return;
}

int Hash(char str[]){

    int hash = 0, tamanho, i;

    tamanho = strlen(str);

    for(i = 0 ; i < tamanho ; i++){

        hash += str[i];
    }

    return(hash);
}