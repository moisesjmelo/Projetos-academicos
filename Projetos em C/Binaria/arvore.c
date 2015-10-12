#include <stdio.h>
#include <stdlib.h>

#include "arvore.h"
#include "pilha.h"

No* criarNovo(int i){
    No* novo = (No*)malloc(sizeof(No));
    if(novo!= NULL){
        novo->i = i;
        novo->esq = NULL;
        novo->dir = NULL;    
    }        
    return novo;
}
void inserir(No** raiz, int i){
    No* novo = criarNovo(i);
    inserirNovo(raiz, novo);    
}

void inserirNovo(No** raiz, No* novo){

    if(*raiz == NULL){
        *raiz = novo;    
    }else if((*raiz)->i > novo->i){
        inserirNovo(&((*raiz)->esq), novo);
    }else{
        inserirNovo(&((*raiz)->dir), novo);
    }
}

void removerArvore(No** raiz){
    if((*raiz)->esq != NULL){
        removerArvore(&((*raiz)->esq));
    }
    if((*raiz)->dir != NULL){
        removerArvore(&((*raiz)->dir));
    }
    free(*raiz);
    *raiz = NULL;
}

void removerNo(No** raiz, int i){
    No* temp = *raiz;
    No* pai = *raiz;
    No* aux;
    Boolean encontrou = FALSE;
    if(temp != NULL){
        if((*raiz)->i != i){
            while(!encontrou){
                if(temp->i < i){
                    if(temp->dir != NULL){
                        pai = temp;
                        temp = temp->dir;
                    }else{
                        // TODO
                        printf("Nao existe o no %d\n", i);    
                        break;
                    }
                }else if(temp->i > i){
                    if(temp->esq != NULL){
                        pai = temp;
                        temp = temp->esq;
                    }else{
                        // TODO
                        printf("Nao existe o no %d\n", i);    
                        break;
                    }
                }else{
                    encontrou = TRUE;
                }   
            }
            if(encontrou){
                if(temp->dir == NULL && temp->esq == NULL){
                    if(pai->dir == temp){
                        pai->dir = NULL;                        
                    }else{
                        pai->esq = NULL;
                    }   
                    free(temp); 
                }else if(temp->dir != NULL && temp->esq == NULL){
                    if(pai->dir == temp){
                        pai->dir = temp->dir;                        
                    }else{
                        pai->esq = temp->dir;                        
                    }   
                    free(temp);    
                }else if(temp->dir == NULL && temp->esq != NULL){
                    if(pai->dir == temp){
                        pai->dir = temp->esq;                        
                    }else{
                        pai->esq = temp->esq;                        
                    }   
                    free(temp);    
                }else{
                    if(pai->dir == temp){
                        pai->dir = temp->esq; 
                    }else{
                        pai->esq = temp->esq;
                    }
                    aux = temp->esq;
                    while(aux->dir!= NULL){
                        aux = aux->dir;
                    }
                    aux->dir = temp->dir; 
                    temp->dir = NULL;    
                    temp->esq = NULL;
                    free(temp);  
                    temp = NULL;
                }
            }
        }else{ // tem que remover a raiz
            temp = *raiz;
            if(temp->esq == NULL && temp->dir == NULL){
                *raiz = NULL;    
            }else if(temp->esq == NULL && temp->dir != NULL){
                *raiz = temp->dir;
            }else if(temp->esq != NULL && temp->dir == NULL){
                *raiz = temp->esq;
            }else{
                aux = temp->esq;
                *raiz = temp->esq;
                while(aux->dir != NULL){
                    aux = aux->dir;
                }
                aux->dir = temp->dir;
                free(temp);
            }
        }
    }
}

void inOrdem(No* raiz){
    if(raiz != NULL){
        inOrdem(raiz->esq);
        printf("%d ", raiz->i);
        inOrdem(raiz->dir);
    }
}
void posOrdem(No* raiz){
    if(raiz != NULL){
        posOrdem(raiz->esq);
        posOrdem(raiz->dir);
        printf("%d ", raiz->i);        
    }
}
void preOrdem(No* raiz){
    if(raiz != NULL){
        printf("%d ", raiz->i); 
        preOrdem(raiz->esq);
        preOrdem(raiz->dir);
    }
    
}
void inOrdemNaoRecursivo(No* raiz){
    No* temp = raiz;
    Pilha* p = NULL;
    Pilha* aux;
    if(raiz!= NULL){
        pushRaiz(&p, temp);
        while(p!= NULL){
            aux = pop(&p);
            temp = aux->raiz;
            // percorre a esq
            if(!aux->esq){
                aux->esq = TRUE;
                push(&p, aux);
                temp = temp->esq;
                while(temp!= NULL){
                    pushRaiz(&p, temp);
                    p->esq = TRUE;     
                    temp = temp->esq;    
                }
                aux = pop(&p);
                temp = aux->raiz;
            }           
            if(aux->esq && !aux->dir){
                printf("%d ", temp->i); 
                if(temp->dir != NULL){
                    pushRaiz(&p, temp->dir); 
                }    
                free(aux); 
            }
        }
        
        
        
        
        
    }    
}
void inOrdemNaoRecursivo2(No* raiz){
    No* temp = raiz;
    Pilha* p = NULL;
    Pilha* aux;
    if(raiz!= NULL){
        pushRaiz(&p, temp);
        while(p!= NULL){
            aux = pop(&p);
            temp = aux->raiz;            
            if(!aux->esq){
                aux->esq = TRUE;
                push(&p, aux);
                if(temp->esq != NULL){
                    pushRaiz(&p, temp->esq);
                }
            }else {
                printf("%d ", temp->i); 
                if(temp->dir != NULL){
                    pushRaiz(&p, temp->dir); 
                }    
                free(aux); 
            }
        }
    }    
}


void posOrdemNaoRecursivo(No* raiz){
    No* temp = raiz;
    Pilha* p = NULL;
    Pilha* aux;
    if(raiz!= NULL){
        pushRaiz(&p, temp);
        while(p!= NULL){
            aux = pop(&p);
            temp = aux->raiz;            
            if(!aux->esq){
                aux->esq = TRUE;
                push(&p, aux);
                if(temp->esq != NULL){
                    pushRaiz(&p, temp->esq);
                }
            }else if(!aux->dir) {
                aux->dir = TRUE;
                push(&p, aux);
                if(temp->dir != NULL){
                    pushRaiz(&p, temp->dir); 
                }    
            }else{
                printf("%d ", temp->i); 
                free(aux); 
            }
        }
    }    
}

void preOrdemNaoRecursivo(No* raiz){
    No* temp = raiz;
    Pilha* p = NULL;
    Pilha* aux;
    if(raiz!= NULL){
        pushRaiz(&p, temp);
        while(p!= NULL){
            aux = pop(&p);
            temp = aux->raiz;            
            
            if(!aux->esq){
                printf("%d ", temp->i); 
                aux->esq = TRUE;
                push(&p, aux);
                if(temp->esq != NULL){
                    pushRaiz(&p, temp->esq);
                }
            }else {
                if(temp->dir != NULL){
                    pushRaiz(&p, temp->dir); 
                }    
                free(aux); 
            }
            
        }
    }    
}

int profundidade(No* raiz){
    int profEsq = 0;
    int profDir = 0;
    int prof = 0;
    if(raiz->esq != NULL){
        profEsq = profundidade(raiz->esq) + 1;
    }
    if(raiz->dir != NULL){
        profDir = profundidade(raiz->dir) + 1;
    }
    if(profEsq > profDir){
        prof = profEsq;
    }else{
        prof = profDir;    
    }
    return prof;    
}

No* removerRecursivo(No** raiz, int i){
    No* removido = NULL;
    if(*raiz!= NULL){
        if((*raiz)->i == i){
            removido = *raiz;
            if(removido->esq == NULL && removido->dir == NULL){
                *raiz = NULL;    
            }else if(removido->esq == NULL && removido->dir != NULL){
                *raiz = removido->dir;
            }else if(removido->esq != NULL && removido->dir == NULL){
                *raiz = removido->esq;
            }else{
                No* temp = removido->esq;
                *raiz = removido->esq;
                while(temp->dir != NULL){
                    temp = temp->dir;
                }
                temp->dir = removido->dir;
            }
            removido->dir = NULL;
            removido->esq = NULL;
        }else{
            if((*raiz)->i > i){
                removido = removerRecursivo(&((*raiz)->esq), i);
            }else{
                removido = removerRecursivo(&((*raiz)->dir), i);
            }
        } 
    }   
    return removido;
}

No* removerNo1(No** raiz, int i){
    No* removido = NULL;
    No** endRemovido = raiz;
    if(*raiz != NULL){
        while(*endRemovido != NULL){
            if((*endRemovido)->i == i){
                break;    
            }else if((*endRemovido)->i > i){
                endRemovido = &((*endRemovido)->esq);                
            }else{
                endRemovido = &((*endRemovido)->dir);                
            }
        }
               
        if(*endRemovido != NULL){
            removido = *endRemovido;
            if(removido->esq == NULL && removido->dir == NULL){
                *endRemovido = NULL;    
            }else if(removido->esq == NULL && removido->dir != NULL){
                *endRemovido = removido->dir;
            }else if(removido->esq != NULL && removido->dir == NULL){
                *endRemovido = removido->esq;
            }else{
                No* temp = removido->esq;
                *endRemovido = removido->esq;
                while(temp->dir != NULL){
                    temp = temp->dir;
                }
                temp->dir = removido->dir;
            }
            removido->dir = NULL;
            removido->esq = NULL;
            
        }
    }
    return removido;
}

No* removerNoMudandoLugar(No** raiz, int i){
    No* removido = NULL;
    No** endRemovido = raiz;
    if(*raiz != NULL){
        while(*endRemovido != NULL){
            if((*endRemovido)->i == i){
                break;    
            }else if((*endRemovido)->i > i){
                endRemovido = &((*endRemovido)->esq);                
            }else{
                endRemovido = &((*endRemovido)->dir);                
            }
        }
        
        
        
        if(*endRemovido != NULL){
            removido = *endRemovido;
            if(removido->esq != NULL && removido->dir != NULL){
                endRemovido = &((*endRemovido)->esq);
                while((*endRemovido)->dir != NULL){
                    endRemovido = &((*endRemovido)->dir);
                }
                No* temp = removido;
                int aux = temp->i;
                removido = *endRemovido;
                temp->i = removido->i;
                removido->i = aux;
            }
            if(removido->esq == NULL && removido->dir == NULL){
                *endRemovido = NULL;    
            }else if(removido->esq == NULL && removido->dir != NULL){
                *endRemovido = removido->dir;
            }else if(removido->esq != NULL && removido->dir == NULL){
                *endRemovido = removido->esq;
            }
            removido->dir = NULL;
            removido->esq = NULL;
            
        }
            
    }
    return removido;    
}
