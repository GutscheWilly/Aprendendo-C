# include <stdio.h>
# include <stdlib.h>

int Tabuada_ate_valor();
void Alocar_vetores(int **mat, int valor);
void Atribuir_valores(int **mat, int valor);
void Imprimir(int **mat, int valor);
void Liberar_memoria(int **mat, int valor);

int main(){

    int **matriz, valor;

    valor = Tabuada_ate_valor();
    matriz = malloc(valor * sizeof(int *));
    Alocar_vetores(matriz, valor);
    Atribuir_valores(matriz, valor);
    Imprimir(matriz, valor);
    Liberar_memoria(matriz, valor);

    return(0);
}

int Tabuada_ate_valor(){

    int valor;

    printf("\nDigite ate que valor deseja obter a tabuada: ");
    scanf("%d", &valor);

    return(valor);
}

void Alocar_vetores(int **mat, int valor){

    int i;

    for(i = 0 ; i < valor ; i++){
        *(mat + i) = malloc(10 * sizeof(int));
    }

    return;
}

void Atribuir_valores(int **mat, int valor){

    int i, j;

    for(i = 0 ; i < valor ; i++){
        for(j = 0 ; j < 10 ; j++){
            *(*(mat + i) + j) = (i + 1) * (j + 1);
        }
    }

    return;
}

void Imprimir(int **mat, int valor){

    int i, j;

    for(i = 0 ; i < valor ; i++){
        printf("\n\n");
        for(j = 0 ; j < 10 ; j++){
            printf("%d ", mat[i][j]);
        }
    }

    return;
}

void Liberar_memoria(int **mat, int valor){

    int i, j;

    if(mat != NULL){
        for(i = 0 ; i < valor ; i++){
            free(mat[i]);
        }

        free(mat);
        mat = NULL;

        if(mat == NULL){
            printf("\n\nMemoria liberada!!\n\n");
        }
    }else{
        printf("\n\nErro na alocacao de memoria\n\n");
    }

    return;
}