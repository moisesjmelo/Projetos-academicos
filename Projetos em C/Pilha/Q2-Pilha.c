//Autor: Moises Melo
#include <stdio.h>
#include <stdlib.h>

typedef struct pi{
        int i;
        struct pi *prox;        
}Pilha;

void inserir(Pilha** topo, int i){
     Pilha* novo = NULL;
     
     novo = (Pilha*)malloc(sizeof(Pilha));
     if( novo != NULL){
         novo->i = i;
         novo->prox= *topo;
         *topo = novo;
     }
}

int remover(Pilha** topo){
    Pilha* temp = *topo;
    int retorno = -1;
    if(temp != NULL){
       *topo = temp->prox;
       retorno = temp->i;
       free(temp);        
    }    
    return retorno;
}

void imprimir(Pilha* topo){
     Pilha* temp = topo;
     printf("\nElementos: ");     
     while(temp != NULL){
          printf("%d ", temp->i);
          temp = temp->prox;           
     }
}

int main(){
    Pilha* topo = NULL;
    
    inserir(&topo, 2);
    imprimir(topo);
    inserir(&topo, 4);
    imprimir(topo);
    inserir(&topo, 10);
    imprimir(topo);
    printf("Remove: %d\n", *topo);
    remover(&topo);
    imprimir(topo);
    inserir(&topo, 8);
    imprimir(topo);
    printf("\n\n");

system("Pause");    
return 0;
}
