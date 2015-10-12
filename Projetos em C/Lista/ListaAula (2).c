#include<stdlib.h>
#include<stdio.h>

typedef struct no{
    int i;
    struct no *prox;        
}Lista;

void inserir(Lista** cab, int valor){
     Lista* temp = *cab;     
     Lista* novo = NULL;
     
     novo = (Lista*)malloc(sizeof(Lista));
     if(novo != NULL){
         novo->i = valor;
         novo->prox = NULL;    
     }
     
     if( temp == NULL){
         *cab = novo;    
     }else{
         while(temp->prox != NULL){
             temp = temp->prox;                 
         }
         temp->prox = novo;             
     }
}

void inserirPos(Lista** cab, int valor, int pos){
     Lista* temp = *cab;     
     Lista* novo = NULL;
     int ct = 1;
     
     novo = (Lista*)malloc(sizeof(Lista));
     if(novo != NULL){
         novo->i = valor;
         novo->prox = NULL;    
     }
     
     if( temp == NULL){
         *cab = novo;    
     }else if(pos == 1){
         novo->prox = temp;
         *cab = novo;           
     }else{
         while(temp->prox != NULL && ct < pos-1 ){
             temp = temp->prox;                 
             ct++;
         }
         novo->prox = temp->prox;
         temp->prox = novo;             
     }
}


void deletar(Lista** cab){
     Lista* temp = *cab;
     Lista* aux = NULL;
     
     while(temp != NULL){
         aux = temp->prox;
         free(temp);         
         temp = aux;           
     }     
     *cab = NULL;
}

void imprimir(Lista* cab){
     Lista* temp = cab;
     
     printf("Os elementos sao: ");
     while(temp != NULL){
        printf("%d ", temp->i);
        temp = temp->prox;
     }
     printf("\n");          
}

int main(){
    Lista* cabeca = NULL;   
    
    inserir(&cabeca, 10);
    inserir(&cabeca, 20);
    inserir(&cabeca, 30);
    inserirPos(&cabeca, 40, 4);
    inserirPos(&cabeca, 25, 3);
    inserirPos(&cabeca, 25, 3);
    inserirPos(&cabeca, 5, 1);
    imprimir(cabeca);
    
    deletar(&cabeca);    
   
    system("pause");
    return 0;   
}
