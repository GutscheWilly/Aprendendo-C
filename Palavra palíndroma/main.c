# include <stdio.h>
# include <string.h>

int main(){

    char palavra[50];

    int i, tamanho, verificacao;

    while (1){

        printf("\n\nDigite uma palavra: ");
        fgets(palavra , 50 , stdin);

        tamanho = strlen(palavra) - 1;

        verificacao = 0;

        for (i = 0 ; i < tamanho ; i++){

            if (palavra[i] == palavra[tamanho - 1 - i]){

                verificacao++;
            }
        }

        if (verificacao == tamanho){

            printf("\n\nA palavra e palindroma !\n\n");

        } else{

            printf("\n\nA palavra nao e palindroma !\n\n");
        }
    }

    return(0);
}