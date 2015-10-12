//Nome: Moises Jose de Melo
//Questao: 12 (decodgf)
#include <stdio.h>
#include <stdlib.h>

int main(){
    char texto[900];
    char carc;
    char codif[900];
    int i = 0;
    printf("Digite o texto: \n");
    fflush(stdin);
    gets(texto); 
    
    while (texto[i] != '\0'){
          if (texto[i] == 'x'){
              carc = 'a';
          }
          else if (texto[i] == 'y'){
               carc = 'b';
          }
          else if (texto[i] == 'z'){
               carc = 'c';
          }
          else if (texto[i] == ' '){
               carc = ' ';
          }
          else 
               carc = texto[i] + 3; 
               codif[i] = carc; 
               i++;
                      
      } 
      printf("a mensagem codificada eh: %s\n\n", codif);
      printf("a mensagem original eh: %s\n\n\n", texto);
    
    system ("pause");
    return 0;
}

