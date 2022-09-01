# include <stdio.h>
# include <string.h>

int main(){

    char frase[100], palindroma[100] = {}, *ponteiro;

    int i, tamanho, verificacao = 0;

    printf("Digite uma frase: ");
    fgets(frase , 100 , stdin);
    
        ponteiro = strtok(frase , " ");

    do{

        strcat(palindroma , ponteiro);

        ponteiro = strtok(NULL , " ");

    } while(ponteiro != NULL);

    tamanho = strlen(palindroma) - 1;

    for (i = 0 ; i < tamanho ; i++){

        if (palindroma[i] == palindroma[tamanho - 1 - i]){

            verificacao++;
        }
    }
    
    if (verificacao == tamanho){

        printf("\n\nA frase forma um palindromo !\n\n");
        
    } else{

        printf("\n\nA frase nao forma um palindromo !\n\n");
    } 

    return(0);
}