//Autor: Moises Melo
#include <stdio.h>
#include <stdlib.h>

typedef struct fi{
        int i;
        struct fi *prox;        
}Fila;

void inserir(Fila** inicio, int i){
     Fila* temp = *inicio;     
     Fila* novo = NULL;     
     
     novo = (Fila*)malloc(sizeof(Fila));
     novo->i = i;
     novo->prox = NULL;
     
     if(temp == NULL){
         *inicio = novo;
     }else{
           while(temp->prox != NULL){
                 temp = temp->prox;
           }      
           temp->prox = novo;
     }
}

int remover(Fila** inicio){
    int retorno;
    Fila* temp = *inicio;
    if(temp == NULL){
            printf("Nao ha elemento para remocao ");
            retorno = -1;
    }else{
        *inicio = temp->prox;
        retorno = temp->i;
        free(temp);     
    }
    return retorno;                
}

void imprimir(Fila* inicio){
     Fila* temp = inicio;
     printf("\nElementos: ");
     while(temp != NULL){
          printf("%d ", temp->i);
          temp = temp->prox;           
     }     
}

int main(){
    Fila* ini = NULL;
    
    inserir(&ini, 1);
    imprimir(ini);
    inserir(&ini, 2);
    imprimir(ini);
    inserir(&ini, 3);
    imprimir(ini);
    printf("Remove: %d\n", remover(&ini));
    imprimir(ini); 
    printf("Remove: %d\n", remover(&ini));  
    inserir(&ini, 4);
    imprimir(ini); 
    inserir(&ini, 5);
    imprimir(ini);    
    
    printf("\n");
        
system("pause");    
return 0;
}
