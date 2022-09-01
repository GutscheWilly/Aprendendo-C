# include <stdio.h>

int Receber_valor();
void Potencias(int valor, int *resultado);

int main(){

    int valor, resultado = 0;

    valor = Receber_valor();
    Potencias(valor, &resultado);
    printf("%d", resultado);

    return(0);
}

int Receber_valor(){

    int valor;

    scanf("%d", &valor);
    
    if(valor > 0){
        return(valor);
    }else{
        return(Receber_valor());
    }
}

void Potencias(int valor, int *resultado){

    int i;

    if(valor > 1){
        for(i = 1 ; i < valor ; i++){
            *resultado += 2;
        }
    }

    return;
}