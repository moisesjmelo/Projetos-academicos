#include "tipoavl.h"
#include "avl.h"

Tree* criarTree(int i){
    Tree* avl = (Tree*)malloc(sizeof(Tree));
    if(avl != NULL){
           avl->i = i;
           avl->fb = 0;
           avl->pai = NULL;
           avl->esq = NULL;
           avl->dir = NULL;       
    }    
    return avl;
}
void inserirAvl(Tree** raiz, int val){
    Tree* novo = criarTree(val);
    Tree* temp = *raiz;
    int inseriu = 0;
    if(*raiz == NULL){
         *raiz = novo;    
    }else{
         while(!inseriu){
              if(temp->i < val){
                   if(temp->dir == NULL){         
                      temp->dir = novo;
                      inseriu = 1;
                      temp->fb = 1;
                   }else{
                      temp = temp->dir;
                     // temp->dir->fb = 0;
                   }
              }else{
                   if(temp->esq == NULL){         
                      temp->esq = novo;
                      inseriu = 1;
                      temp->esq->fb = 1;
                   }else{
                      temp = temp->esq; 
                     // temp->esq->fb = 0;              
                   }
             }
             //temp->pai = temp->esq->fb;
             //(temp->dir.(*fb) - temp->esq.(*fb));
         }
    }  
}
int balanceada(Tree** raiz, int fbl){
    int fb = fbl;
    if ( fb > 1)
        return rotEsq(raiz);
    else if (fb < -1 )
        return rotDir(raiz);
    else
        return 0;     
}

int rotEsq(Tree** raiz){     
    Tree* aux = (*raiz)->dir;
    Tree* temp =  aux->esq;
    aux->esq = *raiz ;
    (*raiz)->dir =  temp;
    *raiz = aux; //atualiza o ponteiro do  pai de raiz 
}

int rotDir(Tree** raiz){
    Tree* aux = (*raiz)->esq;
    Tree* temp =  aux->dir;
    aux->dir = *raiz ;
    (*raiz)->esq =  temp;
    *raiz = aux; //atualiza o ponteiro do  pai de raiz
}

void in_ordem(Tree* raiz){
     if(raiz != NULL){             
             in_ordem(raiz->esq);
             printf("%d ", raiz->i);
             in_ordem(raiz->dir);
     }    
}

void pre_ordem(Tree* raiz){
     if(raiz != NULL){
             printf("%d ", raiz->i);
             pre_ordem(raiz->esq);
             pre_ordem(raiz->dir);
     }    
}

void pos_ordem(Tree* raiz){
     if(raiz != NULL){             
             pos_ordem(raiz->esq);
             pos_ordem(raiz->dir);
             printf("%d ", raiz->i);
     }    
}
void liberarMemoria(Tree** raiz){
     
     if(*raiz != NULL){
             if((*raiz)->esq != NULL)
                liberarMemoria(&((*raiz)->esq));
             if((*raiz)->dir != NULL)
                liberarMemoria(&((*raiz)->dir));
             free(*raiz);
             *raiz = NULL;
     }    
}

void removerNo(Tree** raiz, int i){
    Tree* aux = *raiz;
    Tree* pai = NULL;
    Tree* folha = NULL;
    if(aux!= NULL){
        if(aux->i == i){
            ajustaFilhos(raiz);
            aux->dir = NULL;
            aux->esq = NULL;
            free(aux);
        }else{
            pai = buscaPai(*raiz, i);
            if(pai != NULL){
                if(pai->esq != NULL && pai->esq->i == i){
                    aux = pai->esq;
                    ajustaFilhos(&(pai->esq));
                }else{
                    aux = pai->dir;
                    ajustaFilhos(&(pai->dir));
                }
                aux->dir = NULL;
                aux->esq = NULL;
                free(aux);
           }
        }
   }
}

Tree* buscaPai(Tree* raiz, int i){
    Tree* retorno = NULL;
    if(raiz!= NULL){
        if((raiz->esq != NULL && raiz->esq->i == i) ||
            (raiz->dir != NULL && raiz->dir->i == i)){
            retorno = raiz;
        }else{
            if(raiz->esq != NULL){   
               retorno = buscaPai(raiz->esq, i);
            }
            if(retorno == NULL && raiz->dir != NULL){
            retorno = buscaPai(raiz->dir, i);
        }    
    }
  }   
  return retorno;     
}
void ajustaFilhos(Tree** pai){
    Tree* aux = *pai;
    Tree* folha = NULL;
    if(ehFolha(aux)){ //Erro!!!!!
        *pai = NULL;
    }else if(aux->esq != NULL && aux->dir != NULL){
        folha = buscaFolha(FALSE, aux->esq);
        folha->dir = aux->dir;
        *pai = aux->esq;
    }else if(aux->esq != NULL ){
        *pai = aux->esq;
    }else{// dir != NULL
        *pai = aux->dir;
    }       
}

void verifica(Tree* raiz){
     if(raiz == NULL){
        printf("Arvore vazia\n\n");
     }else{                      
        printf("In_ordem:  ");
        in_ordem(raiz);
        printf("\n\n");    
        printf("Pre_ordem: ");
        pre_ordem(raiz);
        printf("\n\n");
        printf("Pos_ordem: ");
        pos_ordem(raiz);
        printf("\n\n");
     }
}
Tree* buscaFolha(Boolean esquerda, Tree* raiz){
    if(esquerda){
        while(raiz->esq != NULL){
            raiz = raiz->esq;   
        }   
    }else{
        while(raiz->dir != NULL){
        raiz = raiz->dir;   
        }   
    }    
    return raiz;
}
Lista* L = NULL;
int ehFolha(Tree* raiz){
      
      int pf = 0;
    Tree* temp = raiz;
    int retorno = 0;
    if(temp!= NULL){                        
           if(temp->esq == NULL && temp->dir == NULL){
             // retorno = temp->i;          
              printf("Folha %d\n",temp->i);            
              insereLista(&L,temp->i, pf = altura(temp)+ 1);
              
              retorno = 1;
           }else
          
           ehFolha(temp->esq);
           ehFolha(temp->dir);
              
            
           
            // return  retorno = temp->i;      
    }    
 return retorno;  
}



///////////xxxxxxxxxxxx\\\\\\\\\\\\

/*


void altura(Tree* raiz){
   int ret = 0, altEsq = 0, altDir = 0;
   while(raiz != NULL){
      if(raiz->esq != NULL)
      altEsq = altura(raiz->esq)+1;
      if(raiz->dir != NULL)
      altDir = altura(raiz->dir)+1;
      if(altDir > altEsq)
         //ret = altDir;
         printf("Diretia %d ",altDir);
      else
          //ret = altEsq;
          printf("esquerda %d ",altEsq);
   }
}

/*

void Est_binaria(Tree* raiz){
    if(raiz != NULL){
       if((raiz->esq != NULL && raiz->dir != NULL) || 
       (raiz->esq == NULL && raiz->dir == NULL));
    }
   printf("estritamente Binaria\n"); 
}
*/

int altura(Tree* raiz){
   int ret = 0; 
   int altEsq = 0, altDir = 0;
   if(raiz != NULL){
      if(raiz->esq != NULL)
         altEsq = altura(raiz->esq)+1;
      if(raiz->dir != NULL)
         altDir = altura(raiz->dir)+1;
      if(altDir > altEsq)
         ret = altDir;
      else
          ret = altEsq;
   }
   printf("No %d altura %d\n",raiz->i, ret);
   return ret;
}

Boolean Est_binaria(Tree* raiz){   
    Boolean ret = FALSE;
    if(raiz != NULL &&
      raiz->esq != NULL && raiz->dir != NULL){
      ret = Est_binaria(raiz->esq) && Est_binaria(raiz->dir);  
    }else if(raiz == NULL || 
    (raiz != NULL && raiz->dir == NULL && raiz->esq == NULL)){
         ret = TRUE;
    }
    return ret;
}   
Boolean completa(Tree* raiz){
    Boolean ret = FALSE;                             
    if((raiz != NULL && raiz->esq != NULL && 
        raiz->dir != NULL)){ //posivelmente falte algo
      ret = completa(raiz->esq) && completa(raiz->dir);   
      ret = TRUE;
    }
    return ret;
} 
int nivel(Tree* raiz){//, int nivel_Pai){
     int niv = 0;
     if(raiz != NULL){
        
        printf("No: %d  Nivel: %d\n",raiz->i, niv);
        nivel(raiz->esq);
        
        nivel(raiz->dir);
        niv += 1;
     }
     return niv;
}

Boolean checaCompleta(Tree* raiz, int nivel_Pai, int P){
     Boolean ret = FALSE;
     if(raiz != NULL && ehFolha(raiz) && (nivel_Pai +1 == P)){ //quase completa p-(nivel_Pai +1) <=1 
        ret = TRUE;
     }
     else if(raiz != NULL && raiz->esq != NULL && raiz->dir != NULL){
          ret = checaCompleta(raiz->esq, nivel_Pai +1, P)&& checaCompleta(raiz->dir, nivel_Pai +1, P);
     }
     else if(raiz == NULL){
          ret = TRUE; 
     }
     return ret;
}
//////////////////////////////
int insereLista(Lista** no, int val, int pf){
   Lista* temp = *no;
   Lista* novo = NULL;
   novo = (Lista*)malloc(sizeof(Lista));
   if(novo != NULL){           
     novo->n = val;printf("Iseriu %d\n",val);
     novo->pfd = pf;
     novo->prox = *no;
     *no = novo;
   }
}
void confere(Lista* no){
     Lista* temp = no;
     int pf;
     if(no != NULL){
        pf = temp->pfd;
        if(temp->prox->pfd == pf || temp->prox != NULL){
             temp = temp->prox;
          
        }
        if(temp->prox == NULL)
            printf("\nCheia\n");
        else
            printf("\nNao cheia\n");
     } 
}

/////////////////////////////
//Lista* L = NULL;

void tipo(Tree** raiz){ 
    int pf;   
    if(raiz != NULL){
       if(ehFolha(*raiz)) {
         printf("aqui\n");
         // while(ehFolha(*raiz)){                
           // if(insereLista(&L,ehFolha(*raiz), pf = nivel(*raiz))){  
        // }             
          confere(L);
          } else printf("faio");          
       }    
          //printf("\nSó binaria\n");
       if(Est_binaria(*raiz)){
          printf("\n\nEstritamente binaria\n");
       }   
      if(completa(*raiz))
          printf("\n\nCompleta\n");
}


/*

Boolean completa(Tree* raiz){
    int P = altura(raiz);
    checaCompleta(raiz, -1,P);
    nivel(raiz, -1);
    
} 
*/
