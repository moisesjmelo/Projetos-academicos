#include<stdio.h>
#include<stdlib.h>

#define 1 SOMA
#define 2 SUBITRACAO
#define 3 MULTIPLICACAO
#define 4 DIVISAO
#define 5 COMPARAR


int main(){
    int operacao=0;
    float a=0,b=0;
    scanf("%f%f",&a,&b);
   // printf("%.2f\n\n%.2f\n\n",a,b);
    
    printf("\n1 = somar\n2 = subitrair\n3 = multiplicar\n4 = dividir\n5 = comparacao\n\n");
    while(operacao !=6){
    printf("Operacao desejada:\n\n");
    scanf("%d",&operacao);
    
    switch(operacao){
         case 'SOMA':            
         
          printf("%.2f\n\n",a+b);
          break;
           
         case 'SUBTRACAO':
         
          printf("%.2f\n\n",a-b);
           break;
          
         case 'MULTIPLICACAO ': 
         
          printf("%.2f\n\n",a*b);
           break;
         
          case 'DIVISAO':
         
             if(b == 0){
          printf("Divisao invalida");
          
         }else{
          printf("%.2f\n",a/b);
          }
           break;
           
           case 'COMPARAR':
               if(a == b){
          printf("sao iguais\n\n");
          
         }else{
         
         printf("sao diferentes\n\n");
         }
          break;
         
          default:
                  printf("operacao invalida\n\n");
           }
           }
            
    system ("pause");
    return 0;
}
