//Aluno: Moises jose de Melo;
//Questao: 7 (notas);
#include<stdio.h>
#include<stdlib.h>

#define QTDALUNO 10
#define MEDIA 7
#define FINAL 6
int main(){
    int i = 0, j = 0, k = 0;
    float notas[80] = {0};
    float alunos[80] = {0};
    float notas1[80] = {0};
    float notas2[80] = {0};
    float media[80] = {0};
    float final = 0.0;
       
    for(j = 1; j <= QTDALUNO; j++){     
         printf("\n1a Nota do aluno %d: ",j);          
         scanf("%f",&notas[j]);                                               
    }
         printf("\n\n");
    
    for(i = 1; i <= QTDALUNO; i++){        
         printf("\n2a Nota do aluno %d: ",i );          
         scanf("%f",&notas[i]);                
         notas2[i] = notas[i];      
        
         for(k = 1; k <= 1; k++){                               
             media[i] = (notas2[i] + notas1[i])/2;
         } 
    }  
    for(i = 1; i <= QTDALUNO; i++){ 
         printf("\nA media do aluno %d: %.2f\n",i,media[i]);
         
         if (media[i] < MEDIA && media[i] >= 2){            
            final = (FINAL * 2.0) - media[i];                   
            printf("Fara prova final, precisa de nota >= a %.2f \n",final);
         }
         else if (media[i] < 2){              
              printf("Reprovado, nota insuficiente para a recuperacao.\n");
         }                      
    }                   
         printf("\n\n");  
system ("pause");
return 0;
}
