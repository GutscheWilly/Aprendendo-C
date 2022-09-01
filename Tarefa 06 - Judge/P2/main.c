# include <stdio.h>

void Receber_string(char str[]);
void Lancamentos(char str[], int *lancamento, int *cara, int *coroa);

int main(){

    char string[100];

    int lancamento = 0, cara = 0, coroa = 0;

    Receber_string(string);

    Lancamentos(string, &lancamento, &cara, &coroa);

    printf("Numero de lancamentos: %d\n", lancamento);

    printf("Quantidade de cara: %d\n", cara);

    printf("Quantidade de coroa: %d", coroa);

    return(0);
}

void Receber_string(char str[]){

    gets(str);

    return;
}

void Lancamentos(char str[], int *lancamento, int *cara, int *coroa){

    int i;

    *lancamento = strlen(str);

    for(i = 0 ; i < *lancamento ; i++){

        if(str[i] == 'K'){

            ++*cara;
        } else{

            if(str[i] == 'C'){

                ++*coroa;
            }
        }
    }

    return;
}