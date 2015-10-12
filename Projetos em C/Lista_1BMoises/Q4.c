//Aluno: Moises jose de Melo;
//Questao: 4 (carro);
#include<stdio.h>
#include<stdlib.h>

#define LUCRO 0.11
#define IMPOSTO 0.45
#define LUCRODIST 0.12
int main(){
    
    float custo = 0.0, precofab = 0.0, custototal = 0.0, imposto = 0.0, lucrodist = 0.0, preco = 0.0;
    printf("Informe o preco de fabrica:\n\n");
    scanf("%f",&precofab);
    
    imposto = (precofab * IMPOSTO);
    custo = precofab + imposto;    
    lucrodist = custo * LUCRODIST;
    custototal = imposto + custo + lucrodist;
    
     
    printf("Preco ao consumidor: %.2f\n",custototal + (custototal * LUCRO));
    printf("total de impostos: %.2f\n",imposto);
    printf("lucro da concessionaria: %.2f\n\n",custototal * LUCRO);
    
    /*
    printf("Preco de fabrica: %.2f\n",precofab);
    printf("Custo inicial: %.2f\n",custo);
    printf("Custo da distribuidora: %.2f\n",lucrodist);
    printf("Custo total: %.2f\n\n",custototal);*/ 
    
system ("pause");
return 0;
}
