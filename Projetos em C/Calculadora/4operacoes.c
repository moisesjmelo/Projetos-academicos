#include<stdio.h>
#include<stdlib.h>

int main(){
    int operacao=0;
    float a=0,b=0;
    printf("digite dois numeros inteiros\n\n");
    scanf("%f%f",&a,&b);
   // printf("%.2f\n\n%.2f\n\n",a,b);
    
    printf("\n1 = adicao\n2 = subitracao\n3 = multiplicacao\n4 = divisao\n5 = comparacao\n6 = sair\n\n");
    while (operacao != 6){
    printf("Operacao desejada:\n\n");
    scanf("%d",&operacao);
    if(operacao ==1)
    {
     printf("%.2f\n\n",a+b);
    
     } else if(operacao == 2)
      {
     printf("%.2f\n\n",a-b);
     
     } else if(operacao == 3)
      {
     printf("%.2f\n\n",a*b);
     
     } else if (operacao == 4)
      {
      if(b == 0){
      printf("Divisao invalida");
      }else{
     printf("%.2f\n",a/b);}
     
     } else if (operacao == 5)
     {
       if(a == b){
     printf("sao iguais\n\n");
     
     }else{
         
     printf("sao diferentes\n\n");
            }}}
    
    system ("pause");
    return 0;
}
