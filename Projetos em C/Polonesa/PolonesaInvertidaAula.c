#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_MAX 200
typedef struct no{
     char exp[TAM_MAX];
     struct no* prox;      
}Pilha;

void empilhar(Pilha** topo, char* exp){
   Pilha* novo = NULL;
   
   novo = (Pilha*)malloc(sizeof(Pilha));
   if(novo != NULL){
           strcpy(novo->exp, exp); 
           novo->prox = *topo;
           *topo = novo;       
   }       
}

void desempilhar(Pilha** topo, char* exp){
     Pilha* temp = *topo;
     if(temp != NULL){
         strcpy(exp, temp->exp);
         *topo = temp->prox;
         free(temp);        
     }else{
        strcpy(exp, "");            
     }     
}

void montarExpressao(Pilha** topo, char s){
     char op1[TAM_MAX] = {0};
     char op2[TAM_MAX] = {0};
     char exp[TAM_MAX] = {0};
     char sinal[3] = {0};
     
     desempilhar(topo,op2);
     desempilhar(topo,op1);
     sinal[0] = s;
     sinal[1] = '\0';
     strcpy(exp, "(");
     strcat(exp,op1);
     strcat(exp,sinal);     
     strcat(exp,op2);
     strcat(exp,")");
     empilhar(topo, exp);
}

int main(){
    Pilha* topo = NULL;
    char expressao[TAM_MAX] ={0};
    char temp[TAM_MAX] = {0};
    int tam = 0;
    int i;
    
    scanf("%s", expressao);    
    tam = strlen(expressao);
    
    for( i = 0; i < tam; i++){
       switch(expressao[i]){
           case '+':                                  
           case '-':
           case '*':
           case '/':
                montarExpressao(&topo,expressao[i]);
                break;
           default:
              temp[0] = expressao[i];
              temp[1] = '\0';
              empilhar(&topo, temp);     
       }     
    }
    desempilhar(&topo, temp);
    printf(temp);
    
    system("pause");   
    return 0;    
    
}
