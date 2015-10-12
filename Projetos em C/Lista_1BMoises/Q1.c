//Aluno: Moises jose de Melo;
//Questao: 1 (triangulo);

#include<stdio.h>
#include<stdlib.h>

int main()
{
    float A = 0, B = 0, C = 0;
    
    printf("Em ordem digite o valor dos lados: A, B e C\n");
    scanf("%f%f%f",&A,&B,&C);

    if((A<=B+C)&&(B<=A+C)&&(C<=A+B))
    {
       printf("\n\n");
      
       if((A==B)&&(B==C))
       {
          printf("Triangulo equilatero\n\n");
       }
    
       else if((A==B)||(B==C)||(A==C))
       {
            printf("Triangulo isosceles\n\n");
       }
       
       else
       {
           printf("Triangulo escaleno\n\n");
       }

    } 

    else
    {
        printf("nao eh triangulo\n\n");
    }
  
system ("pause");
return 0;
}
