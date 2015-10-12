#include <stdio.h>
#include <stdlib.h>

typedef enum{
     FALSE,
     TRUE     
}BOOLEAN;

typedef struct ELEM{
     int TAB[8];
     int Custo;
     struct ELEM* Pai;
}Elemento;

typedef struct no{
     Elemento E;
     struct no* prox;
}No;

/*
void inserir(No** Inicio, int TAB[8]){
     No* temp = *Inicio;
     No* novo = NULL;
     int i;
     novo = (No*)malloc(sizeof(No));
     if (novo != NULL){
         for(i = 0; i < 8; i++){     
        novo->E.TAB[i] = TAB[i];
        }
        novo->E.Custo = 0;
        novo->E.Pai = NULL;
        novo->prox = NULL;
     }
     if (temp == NULL){
        *Inicio = novo;
     }else{
         while(temp->prox != NULL){
               temp = temp->prox;
         }
         temp->prox = novo;
     }          
}

*/

void InserirnoInicio(No** Inicio, No* Novo){
      Novo->prox = *Inicio;
      *Inicio = Novo;
}

No* RemoverInicio(No** Inicio){
    No* temp = *Inicio;
    *Inicio = temp->prox;
    temp->prox = NULL;
    return temp; //esse retorno reseberá o free na chamada da main
}

void LimparLista(No** Inicio){
    No* temp = *Inicio;
    while(temp != NULL){
          *Inicio = temp->prox;
           free(temp);
           temp = *Inicio;
    }
}

void InserirOrdem(No** Inicio, No* Novo){
     No * temp = * Inicio;
     int Ctemp, Cnovo;
     No* aux = NULL;
     if(temp == NULL){
        *Inicio = Novo;
        Cnovo = Novo->E.CustoTAB + Novo->E.CustoPai;
        while(temp != NULL){
              Ctemp = temp->E.CustoTAB + temp->E.CustoPai;
              if(Ctemp < Cnovo){
                 aux = temp;
                 temp = temp->prox;
              }else{
                    break;
        }
     }
     if(aux == NULL){
        Novo->prox = * Inicio;
        *Inicio = Novo;
     }else{
           Novo->prox = temp;
           aux->prox = Novo;
           }
           
     }
}



BOOLEAN Existe(No* Inicio, No* busca){
        No* temp = Inicio;
        BOOLEAN FLAG = FALSE;
        while(temp != NULL){
              if(comparar(temp->E, busca->E)){
                 FLAG = TRUE;
                 break;
              }
              temp = temp->prox;
        }
        return FLAG;
}


BOOLEAN Comparar(Elemento E1, Elemento E2){
      BOOLEAN FLAG = TRUE;
      int i;
      for(i = 0; i <= 7; i++){
          if(E1.TAB[i] != E2.TAB[i]){
             FLAG = FALSE;
             break;               
          }
      }  
       return FLAG;
}

void Copiar(Elemento* DST, Elemento SRC){

}

void imprimir(No* Inicio){
     No* temp = Inicio;
     while(temp != NULL){
          printf("%d ",temp->E.TAB[8]);    
          temp = temp->prox;       
     }
}

/* raninha
// int i,j, cont = 0, x, y;
for(i = 0; j <= 4 , j++){
      

}
*/
int custoTabuleiro(int tab[TAM_VETOR]){
    int i, j, x, a b;
    int custo = 0;
    
    for(x = 0; x , TAM_VETOR; x ++){
        i = x;
        j = tab[i];
    
        for(a = i; b = j-1; a > 0 && b >= 0; a --, b--){
            if(tab[a] == b)
               custo++; 
        } 
    
    }
}

int main (){
  Elemento E1, E2;
  int i;
  for(i = 0; i < 8; i++){
     E1.TAB[i] = i;
  }
  E1.CustoTAB = 0;
  E1.CustoPai = 0;
  E1.Pai = NULL;
  E2 = E1;
  
  if(Comparar(E1,E2)){
     printf("Sao iguais");
  }
  E2.TAB[0] = 20;
  if(!comparar(E1, E2)){
     printf("Sao diferentes");
  }
  


//teste do metodo existe
   No inicio;
   No* aux = (No*)malloc(sizeof(No));
   Inicio.E = E1;
   aux->E = E2;
   aux->prox = NULL;
   Inicio.prox = aux;
   aux = (No*)malloc(sizeof(No));
   aux->E = E2;
   aux->prox = NULL;
   if(Existe(&Inicio, aux){
      printf("Tem o elemento ");
      aux-.E.TAB[0] = 200;
   }
   

    
system ("pause");
return 0;
}
