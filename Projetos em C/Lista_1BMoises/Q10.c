//Nome: Moises Jose de Melo
//Questao: 10 (padrao USA)

#include <stdio.h>
#include <stdlib.h>

int main(){
    char nome[200];
    char* nomeUSA = NULL;

    printf("Digite seu nome completo: \n");
    gets(nome);
    nomeUSA = strrchr(nome,' ');
    *nomeUSA = '\0';
    
    printf("%s, %s\n\n", nomeUSA +1, nome);
    
system ("pause");
return 0;
}

