# include <stdio.h>

void Receber_string(char str1[]);
void Verificar(char str1[], char str2[], int *ocorrencia);

int main(){

    char string1[10000], string2[10000];

    int ocorrencia = 0;

    Receber_string(string1);

    Receber_string(string2);

    Verificar(string1, string2, &ocorrencia);

    printf("Número de ocorrência: %d", ocorrencia);

    return(0);
}

void Receber_string(char str[]){

    scanf("%s", str);

    return;
}

void Verificar(char str1[], char str2[], int *ocorrencia){

    int tamanho1, tamanho2, i, j, teste;

    tamanho1 = strlen(str1);

    tamanho2 = strlen(str2);

    for(i = 0 ; i < tamanho1 ; i++){

        teste = 0;

        for(j = 0 ; j < tamanho2 ; j++){

            if(str1[i + j] == str2[j]){

                teste++;
            }
        }

        if(teste == tamanho2){

            ++*ocorrencia;
        }
    }

    return;
}