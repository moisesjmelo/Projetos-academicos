//Aluno: Moises jose de Melo;
//Questao: 5 (palindromo);
#include<stdio.h>
#include<stdlib.h>

int main(){   
    char num[10] = {0};
    char temp[10] = {0};
    int i = 0, j = 0, a = 0, b = 0, res = 0;
    int tam = 0, maior = 0, n1 = 0, n2 = 0;
    
    for(i = 999; i >= 100; i--){
          
        for(j = 999; j >= 100; j--){
           res = i * j;                
           itoa(res,num,10);
           tam = strlen(num);
                          
        for(a = tam-1, b = 0; a >= 0; a--, b++){
            temp[b] = num[a];
        }    
        temp[b] = '\0';                   
                                  
        if(strcmp(temp,num) == 0){
          
           if(res > maior){
              maior = res;
              n1 = i;
              n2 = j;
           }        
         }
       }
    }

 printf("O numero %d X %d resulta o maior palindromo: %d\n",n1,n2,maior);                 

system ("pause");
return 0;
}
