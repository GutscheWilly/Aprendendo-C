# include <stdio.h>

void Inicializar_vetor(int vet[]);
int Receber_valor();
void Transformar_decimal_binario(int valor, int vet[], int index);
void Imprimir_binario(int vet[]);

int main(){

    int decimal, binario[100];

    Inicializar_vetor(binario);
    decimal = Receber_valor();
    Transformar_decimal_binario(decimal, binario, 0);
    Imprimir_binario(binario);
    
    return(0);
}

void Inicializar_vetor(int vet[]){

    int i;

    for(i = 0 ; i < 100 ; i++){
        vet[i] = -1;
    }

    return;
}

int Receber_valor(){

    int valor;

    printf("\nDigite uma valor inteiro positivo: ");
    scanf("%d", &valor);

    if(valor >= 0){
        return(valor);
    }else{
        printf("\nValor digitado invalido!\n");
        return(Receber_valor());
    }
}

void Transformar_decimal_binario(int valor, int vet[], int index){

    if(valor >= 1){
        vet[index] = valor % 2;
        Transformar_decimal_binario(valor/2, vet, ++index);
    }else{
        if(valor == 0 && index == 0){
            vet[index] = 0;
        }
    }

    return;
}

void Imprimir_binario(int vet[]){

    int i;

    for(i = 99 ; i >= 0 ; i--){
        if(vet[i] != -1){
            printf("%d", vet[i]);
        }
    }

    return;
}