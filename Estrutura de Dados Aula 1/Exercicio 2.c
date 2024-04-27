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
    if(Imc<18.5)
    {
        puts("Magro");
    }
    else
    {
        if(Imc>30)
        
        {
            puts("Obeso");
        }
        else
        {
             puts("Normal");
        }
    }
    
        
    
}