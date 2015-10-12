/* 1 - Faça uma função que receba, por parâmetro, uma matriz A(5,5) e retorna a média aritmética
 dos elementos abaixo da diagonal principal e da diagonal secundária. A matriz deve ser 
 parametrizada como uma "Passagem por Referência".*/
#include<stdio.h>
#include<stdlib.h>

int media(int mt[5][5]);
int main(){
    int mt[5][5]= {0};
    int linha=0,coluna=0;
    int num = 0, *mtPtr;
    mtPtr = &mt[5][5];
    
    printf("informe 25 numeros inteiros\n");
    for(linha = 0; linha < 5; linha++){ 
    for(coluna = 0; coluna < 5; coluna++){  
            printf("valor %d da linha %d\n",linha,coluna);        
            scanf("%d",&mt[linha][coluna]);            
            
        }
    }
    printf("%d",mt[linha][coluna]);
    printf("\n\n");
    printf("%d\n",media(mt));
    
system ("pause");
return 0;
}
int media(int mt1[5][5]){// inicio func media    
    int linha = 0, coluna = 0;
    int soma = 0;
    float media = 0.0; 
    int cont = 0;  
    
    for(linha = 0; linha < 5; linha++){
        for(coluna = 0; coluna < 5; coluna++){
             if ((linha > coluna) && (linha + coluna > 4)){
               if(linha + coluna > 4){
                  
                 }
                 soma = soma + mt1[linha][coluna];
                 cont = 4;             
             }                             
        }
    }
    media = (float)soma / (float)cont;
    return media;
}//fim func media
