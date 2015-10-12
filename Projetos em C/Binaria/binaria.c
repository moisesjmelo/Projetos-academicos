#include "tipobin.h"
#include "binaria.h"
Tree* criarTree(int i){
    Tree* ret = (Tree*)malloc(sizeof(Tree));
    if(ret != NULL){
           ret->i = i;
           ret->esq = NULL;
           ret->dir = NULL;       
    }    
    return ret;
}

void inserirArvore(Tree** raiz, int i){
    Tree* novo = criarTree(i);
    Tree* temp = *raiz;
    int inseriu = 0;
    if(*raiz == NULL){
         *raiz = novo;    
    }else{
         while(!inseriu){
             if(temp->i < i){
                   if(temp->dir == NULL){         
                      temp->dir = novo;
                      inseriu = 1;
                   }else{
                      temp = temp->dir;
                   }
             }else{
                   if(temp->esq == NULL){         
                      temp->esq = novo;
                      inseriu = 1;
                   }else{
                      temp = temp->esq;               
                   }
             }
         }
    }  
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

//aula dia 04/06/2012
void removerNo1(Tree** raiz, int i){
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

///////////
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
int ehFolha(Tree* raiz){
    Tree* temp = raiz;
    int retorno = 1;
    if(temp!= NULL){
        if(temp->esq != NULL && temp->dir != NULL){            
            retorno = 0;
            }        
    }    
  return retorno;  
}
int contaNo(Tree* raiz){
    int ret = 0;
    if(raiz != NULL){
       ret += contaNo(raiz->esq);
       ret += contaNo(raiz->dir);
       ret += 1;
    }
    return ret;
}
int altura(Tree* raiz){
   int ret = 0, altEsq = 0, altDir = 0;
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
   return ret;
}

/*
void Est_binaria(Tree* raiz){
    if(raiz != NULL){
       if((raiz->esq != NULL && raiz->dir != NULL) || 
       (raiz->esq == NULL && raiz->dir == NULL));
    }
   printf("estritamente Binaria\n"); 
}*/
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
void nivel(Tree* raiz, int nivel_Pai){
     int ret = nivel_Pai;
     if(raiz != NULL){
        ret = nivel_Pai + 1;
        printf("No: %d -> Nivel: %d\n",raiz->i,ret);
        nivel(raiz->esq,ret);
        nivel(raiz->dir,ret);
     }
}

Boolean checaCompleta(Tree* raiz, int nivel_Pai, int P){
     Boolean ret = FALSE;
     if(raiz != NULL && ehFolha(raiz) && (nivel_Pai +1 == P)){ /*quase completa p-(nivel_Pai +1) <=1 */
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
/*
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
} */
/*
Boolean completa(Tree* raiz){
    int P = altura(raiz);
    checaCompleta(raiz, -1,P);
    nivel(raiz, -1);
    
} */
