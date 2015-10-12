#include<stdlib.h>
#include<stdio.h>

typedef struct no{
    int i;
    struct no *prox;        
}Lista;

void inserirFinal(Lista** inicio, int valor){
     Lista* temp = *inicio;     
     Lista* novo = NULL;
     
     novo = (Lista*)malloc(sizeof(Lista));
     if(novo != NULL){
         novo->i = valor;
         novo->prox = NULL;    
     }
     if(temp == NULL){
         novo->prox = novo;
         *inicio = novo;        
     }else{
           while(temp->prox != *inicio){
               temp = temp->prox;
           }
           novo->prox = temp->prox;
           temp->prox = novo;
     }
}

void inserirPos(Lista** inicio, int valor, int pos){
     Lista* temp = *inicio;
     Lista* novo = NULL;
     int cont = 1;
     
     if (temp == NULL){
        if(pos == 1){
             novo = (Lista*)malloc(sizeof(Lista));
             if(novo != NULL){
                     novo->i = valor;
                     novo->prox = novo;        
                     *inicio = novo;
             }  else{
                 printf("\nposicao invalida.\n");
             }
        }
     }else if(pos == 1){
         novo = (Lista*)malloc(sizeof(Lista));
         if(novo != NULL){
                 novo->i = valor;
                 novo->prox = *inicio; 
                 while(temp->prox != *inicio){
                     temp = temp->prox;
                 }                
                 temp->prox = novo; 
                 *inicio = novo;        
         }      
     }else {
         novo = (Lista*)malloc(sizeof(Lista));
         if(novo != NULL){
                 novo->i = valor;
                 novo->prox = NULL; 
                 while(temp->prox != *inicio && cont < pos-1){
                     temp = temp->prox;
                     cont++;
                 } 
                                
                 novo->prox = temp->prox;
                 temp->prox = novo;
         }
                 
     }
}

void imprimir(Lista* inicio){
     Lista* temp = inicio;
     
     if(temp != NULL){
             printf("\nOs elementos sao: ");
             do{
                 printf("%d ", temp->i);     
                 temp = temp->prox;
             }while(temp!= inicio);        
     }     
}

int removerFinal(Lista** inicio){
      Lista* temp = NULL;
      Lista* aux = *inicio;
      int retorno = -1;
      
      if(aux == NULL){
             printf("Nao há elementos para remover");       
      }else if(aux->prox == aux){
            retorno = aux->i;
            free(aux);
            *inicio = NULL;
      }else {
            temp = aux->prox;
            while(temp->prox != *inicio){
                 temp = temp->prox;
                 aux = aux->prox;                 
            }     
            aux->prox = *inicio;
            retorno = temp->i;
            free(temp);
      } 
      return retorno; 
}

int main(){
    Lista* inicio = NULL;
    
    inserirPos(&inicio, 10, 1);
    imprimir(inicio); 
    inserirPos(&inicio, 1, 2);
    imprimir(inicio); 
    inserirPos(&inicio, 15, 2);
    imprimir(inicio); 
    inserirPos(&inicio, 20, 1);
    imprimir(inicio); 
    inserirPos(&inicio, 30, 5);
    imprimir(inicio); 
    printf("\n Removeu: %d", removerFinal(&inicio));
    imprimir(inicio); 
    printf("\n Removeu: %d", removerFinal(&inicio));
    imprimir(inicio); 
    printf("\n Removeu: %d", removerFinal(&inicio));
    imprimir(inicio); 
    printf("\n Removeu: %d", removerFinal(&inicio));
    imprimir(inicio); 
    printf("\n Removeu: %d", removerFinal(&inicio));
    imprimir(inicio); 
    printf("\n Removeu: %d", removerFinal(&inicio));
    imprimir(inicio); 
        system("Pause");    
    return 0;
}
     
