#include <stdio.h>
#include <math.h>

int main(void)
{
    float Peso, Altura, Imc;
    printf("Digite seu peso \n");
    scanf("%f", &Peso);
    printf("Digite a altura \n");
    scanf("%f", &Altura);
    Imc=Peso/pow(Altura,2);
    printf("Seu IMC é %.2f \n", Imc);
    return 0;
    
        
    
}