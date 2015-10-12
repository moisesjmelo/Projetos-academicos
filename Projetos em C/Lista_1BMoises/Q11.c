//Nome: Moises jose de Melo
//Questao: 11 (substring)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char texto[900];
    char palavra[50];
    char* prox = NULL;
    int a = 0;

    printf("Digite um texto: \n");
    gets(texto);
    printf("Digite uma Palavra: \n");
    gets(palavra);

    prox = strstr(texto, palavra);
    *prox = '\0';

    while (prox[a] != ' '){    
          a++;
    }
          a++;
    
    while (a){        
          if ((prox[a] == '\0') || (prox[a] == ' '))
              break;

          printf("%c", prox[a]);
                 a++;
    }
     printf("\n");
    
system ("pause");
return 0;
}

