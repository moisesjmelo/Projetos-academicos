#include <stdio.h>
#include <stdlib.h>

void quick(int num[], int inicio, int fim){
    int pivor = (inicio+fim+1)/2;
    int aux;
    int i = inicio;
    int j = fim;
    int pivor2 = num[pivor];
    
    while(i < j ){
         while(num[i] < pivor2)                   
             i++;
         while(num[j] > pivor2)
             j--;
         if(i <= j){
            aux = num[i];
            num[i] = num[j];
            num[j] = aux;
         
             i++;
             j--;
         } 
    }
    if ( j > inicio)
          quick(num, inicio, j);
    if (i < fim)
          quick(num, i, fim);
     
}

int main(){
    int num[10] = {9,8,7,6,0,1,3,5,4,2};
    int aux;
    
    quick(num, 0, 9);
    printf("\n");
    for(aux = 0; aux < 10; aux++){
       printf("%d ", num[aux]);        
    }

    system("pause");    
    return 0;
}
