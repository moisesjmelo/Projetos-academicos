//Nome: Moises Jose de Melo
//Questao: 8 (mais repete)
#include <stdio.h>
#include <stdlib.h>

int main(){
    int i = 0, j = 0, k = 0, rep = 0;
    int maior = 0, maisrp;
    int num[10];  

    printf("Digite 10 numeros inteiros: \n");
    for(j = 0; j <= 9; j++){
        scanf("%d", &num[j]);
    }
    for(i = 0; i <= 9; i++){
        
        for(k = 1; k <= 9; k++){
            if(num[i] == num[k]){
                rep++;
            }
        }        
        if(rep > maior){   
            maisrp = num[i];
            maior = rep;            
        }
        rep = 0;
    }
    printf("O numero %d eh o que mais se repete \n", maisrp);
system("pause");
return 0;
}

