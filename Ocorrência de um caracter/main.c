# include <stdio.h>
# include <string.h>

void Receber_string(char string[]);
int Ocorrencia_letra(char string[]);
void Imprimir_resultado(int ocorrencia);

int main(){

    char frase[102];
    int ocorrencia;

    Receber_string(frase);
    ocorrencia = Ocorrencia_letra(frase);
    Imprimir_resultado(ocorrencia);

    return(0);
}

void Receber_string(char string[]){

    int i;

    printf("Digite uma frase: ");
    fgets(string, 102, stdin);

    for(i = 0 ; i < 102 ; i++){

        if(string[i] == '\n'){

            string[i] = '\0';
        }
    }

    return;
}

int Ocorrencia_letra(char string[]){

    int i, ocorrencia = 0;

    char caracter;

    printf("\nDigite uma letra: ");
    scanf("%c", &caracter);

    for(i = 0 ; i < strlen(string) ; i++){

        if(string[i] == caracter){

            ocorrencia++;
        }
    }

    return(ocorrencia);
}

void Imprimir_resultado(int ocorrencia){

    printf("\nOcorrencia dessa letra na frase: %d\n", ocorrencia);

    return;
}