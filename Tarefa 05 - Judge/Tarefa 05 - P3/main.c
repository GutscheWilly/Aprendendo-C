# include <stdio.h>

void Receber_valores(int *valor, float vetor[]);
void Imprimir_equacao(int valor, float vetor[]);

int main(){

    int maior_grau, copia_maior_grau, i;
    float coeficientes[1000];

    Receber_valores(&maior_grau, coeficientes);

    if (maior_grau < 0){

        printf("Grau inválido");

    }else{

        printf("Equação: ");
        Imprimir_equacao(maior_grau, coeficientes);
        printf("\n");

        maior_grau--;

        copia_maior_grau = maior_grau;

        for(i = 0 ; i <= copia_maior_grau ; i++){

            if(i != copia_maior_grau){

                printf("Dev %d: Equação: ", i + 1);

            }else{

                printf("Dev %d: ", i + 1);
            }

            Imprimir_equacao(maior_grau, coeficientes);
            printf("\n");

            maior_grau--;
        }
    }

    return(0);
}

void Receber_valores(int *valor, float vetor[]){

    int i;

    scanf("%d", valor);

    for(i = 0 ; i <= *valor ; i++){

        scanf("%f", &vetor[i]);
    }

    return;
}

void Imprimir_equacao(int valor, float vetor[]){

    int i, copia_valor = valor;;

    for(i = 0 ; i <= copia_valor ; i++){

        if(vetor[i] >= 0 || i == 0){

            printf("%.1fx^%d ", vetor[i], valor);

        }else{
            
            printf("%.1fx^%d ", -vetor[i], valor);
        }

        vetor[i] *= valor; 

        if(i != copia_valor){
                
            if(vetor[i + 1] >= 0){

                printf("+ ");

            }else{

                printf("- ");
            }
                
        }

        valor--;
    }    

    return;
}