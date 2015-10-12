//Nome: Moises Jose de Melo
//Questao: 9 (ordem crescente)
#include <stdio.h>
#include <stdlib.h>
#define TAM 10
int main(){
    int i = 0, k = 0, temp = 0;
    int num[TAM];

    printf("Digite 10 numeros inteiros: \n");
    for (i = 0; i < TAM; i++){
        scanf("%d", &num[i]);
    }
        
    for (i = 0; i < TAM - 1; i++){
        if (num[i] > num[i + 1] & i >= 0){
            temp = num[i];
            num[i] = num[i + 1];
            num[i + 1] = temp;
            i = -1;
        }
    }
    printf("Os numeros em ordem crescente: ");
    
    for (k = 0; k < TAM; k++){
        printf("%d ", num[k]);
    }
    
    printf("\n\n");
system ("pause");
return 0;
}

