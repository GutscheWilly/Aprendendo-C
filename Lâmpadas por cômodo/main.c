# include <stdio.h>
# include <math.h>

typedef struct{

    int tipo;
    float largura;
    float altura;
    float area;
    float potencia;
    float quantidade_lampadas;

} Comodo;

void Inicializar_comodos(Comodo comodo[]);
int Receber_tipo_comodo();
float Calcular_area(float largura, float altura);
float Calcular_quantidade_lampadas(float area, float potencia);
void Definir_comodo(Comodo comodo[], int tipo);
void Imprimir_dados(Comodo comodo[]);

int main(){

    Comodo comodo[5];

    int tipo;

    Inicializar_comodos(comodo);

    do{

        tipo = Receber_tipo_comodo();

        if(tipo != -1){

            Definir_comodo(comodo, tipo);
        }

    } while(tipo != -1);

    Imprimir_dados(comodo);

    return(0);
}

void Inicializar_comodos(Comodo comodo[]){

    int i;

    for(i = 0 ; i < 5 ; i++){

        comodo[i].tipo = i;
        comodo[i].largura = 0;
        comodo[i].altura = 0;
        comodo[i].area = 0;
        comodo[i].potencia = 0;
        comodo[i].quantidade_lampadas = 0;
    }

    return;
}

int Receber_tipo_comodo(){

    int tipo;

    do{

        printf("\nDigite o tipo do comodo: ");
        scanf("%d", &tipo);

    } while(tipo < -1 || tipo > 9);

    return(tipo);
}

float Calcular_area(float largura, float altura){

    float area;

    area = largura * altura;

    return(area);
}

float Calcular_quantidade_lampadas(float area, float potencia){

    float potencia_total, quantidade;

    potencia_total = area * potencia;

    quantidade = potencia_total / 60;

    return(ceil(quantidade));
}

void Definir_comodo(Comodo comodo[], int tipo){

    printf("\nLargura do comodo %d: ", tipo);
    scanf("%f", &comodo[tipo].largura);

    printf("\nAltura do comodo %d: ", tipo);
    scanf("%f", &comodo[tipo].altura);

    printf("\nPotencia do comodo %d: ", tipo);
    scanf("%f", &comodo[tipo].potencia);

    comodo[tipo].area = Calcular_area(comodo[tipo].largura, comodo[tipo].altura);

    comodo[tipo].quantidade_lampadas = Calcular_quantidade_lampadas(comodo[tipo].area, comodo[tipo].potencia);

    return;
}

void Imprimir_dados(Comodo comodo[]){

    int i;

    for(i = 0 ; i < 5 ; i++){

        printf("\nComodo %d -->\tArea: %.2f\tPotencia: %.2f\tQuantidade de lampadas de 60 W: %.2f", i, comodo[i].area, comodo[i].potencia, comodo[i].quantidade_lampadas);
    }

    return;
}