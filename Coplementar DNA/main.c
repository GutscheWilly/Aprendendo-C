# include <stdio.h>
# include <string.h>

void Receber_string(char str[]);
void Fita_complementar(char str[]);

int main(){

    char string[100];

    Receber_string(string);
    printf("\n\nOriginal: \t%s\n", string);
    Fita_complementar(string);
    printf("\nComplementar:   %s\n\n", string);

    return(0);
}

void Receber_string(char str[]){

    printf("\nFita de DNA: ");
    fgets(str, 100, stdin);
    str[strlen(str) - 1] = '\0';

    return;
}

void Fita_complementar(char str[]){

    int i;

    for(i = 0 ; i < strlen(str) ; i++){
        if(str[i] == 'A'){
            str[i] = 'T';
        }else{
            if(str[i] == 'T'){
                str[i] = 'A';
            }else{
                if(str[i] == 'C'){
                    str[i] = 'G';
                }else{
                    if(str[i] == 'G'){
                        str[i] = 'C';
                    }
                }
            }
        }
    }

    return;
}