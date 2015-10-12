//Aluno: Moises jose de Melo;
//Questao: 2 (triangulo);
#include<stdio.h>
#include<stdlib.h>

#define ANO 365
#define MARCO 20
#define MOEDA "R$"

int main(){
    int anoInicio = 0, anoAtual = 0, cigarroDia = 0, dias = 0;
    float valMarco = 0,despesa = 0;
       
    printf("Informe:\nAno que comecou a fumar\n");
    scanf("%d", &anoInicio);
    printf("Ano atual\n");
    scanf("%d", &anoAtual);
    printf("Quantos cigarros fuma por dia\n");
    scanf("%d", &cigarroDia);
    printf("Preco do marco de cigarro.\n\n");
    scanf("%f", &valMarco);
    
    dias = (anoAtual - anoInicio)* ANO;
    despesa = (cigarroDia * dias / MARCO) * valMarco;
    
    printf("\nVoce gastou aproximadamente %s %.2f em %d anos de vicio\n\n",MOEDA,despesa,anoAtual - anoInicio); 

system ("pause");
return 0;
}
