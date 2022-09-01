# include <stdio.h>

void Receber_string(char vetor[]);
int Tamanho_string(char vetor[]);
void Converter_maiusculo(char vetor[], int *tamanho);
void Converter_minusculo(char vetor[], int *tamanho);
void Imprimir_string(char vetor[]);

int main(){

    char string[1000];
    int quant_caracteres;

    Receber_string(string);

    quant_caracteres = Tamanho_string(string);

    printf("\n\nString maiusculo: ");
    Converter_maiusculo(string, &quant_caracteres);
    Imprimir_string(string);

    printf("\n\nString minuscula: ");
    Converter_minusculo(string, &quant_caracteres);
    Imprimir_string(string);

    printf("\n\n");

    return(0);
}

void Receber_string(char vetor[]){

    printf("Digite uma string: ");
    scanf("%1000[^\n]", vetor);

    return;
}

int Tamanho_string(char vetor[]){

    int tamanho = 0;

    while(vetor[tamanho] != '\0'){

        tamanho++;
    }

    return(tamanho);
}

void Converter_maiusculo(char vetor[], int *tamanho){

    int i;

    for(i = 0 ; i < *tamanho ; i++){

        if(vetor[i] >= 97 && vetor[i] <= 122){

            vetor[i] -= 32;
        }
    }

    return;
}

void Converter_minusculo(char vetor[], int *tamanho){

    int i;

    for(i = 0 ; i < *tamanho ; i++){

        if(vetor[i] >= 65 && vetor[i] <= 90){

            vetor[i] += 32;
        }
    }

    return;
}

void Imprimir_string(char vetor[]){

    printf("%s", vetor);

    return;
}