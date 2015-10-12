//Aluno: Moises jose de Melo;
//Questao: 3 (codigo_lanche);
#include<stdio.h>
#include<stdlib.h>

#define CAHORRO_QUENTE 100
#define BAURU_SIMPLES 101
#define BAURU_COM_OVO 102
#define HAMBURGER 103
#define CHEESBURGUER 104
#define REFRIGERANTE 105
#define CONTA 2

int main(){
    int codigo = 0, qtd = 0, i = 0;
    float valor = 0.0, conta = 0.0, soma = 0.0;
    char moeda[3] = "R$";
                              
    do{
      scanf("%d",&codigo);
                
    if(codigo != 2){
       scanf("%d",&qtd);
                                    
       switch(codigo){
          case 100:                     
              valor = 1.20;                     
              break; 
                      
          case 101:
              valor = 1.30;
              break; 
                      
          case 102:
              valor = 1.50;
              break;
                      
          case 103:
              valor = 1.20;
              break;
                      
          case 104:
              valor = 1.30;
              break;
                      
          case 105:
              valor = 1.00;
              break;
              
          case 2:
              printf("Conta:\n");    
              break;   
                                                       
          default:
              printf("codigo invalido\n");                                           
                                                    
          } 

      if((codigo != 2)&&(codigo >= 100)&&(codigo <= 105)){   
          soma = (float)qtd * valor;
          conta = conta + soma;
          }
    }
          else if(codigo != 2){   
                 printf("codigo invalido\n"); 
          }
                        
    }while(codigo != 2);
          printf("Pague o valor de: R$ %.2f\n",conta);
  
system ("pause");
return 0;
}
