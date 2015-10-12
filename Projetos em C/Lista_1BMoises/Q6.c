//Nome: Moises Jose de Melo
//Questao: 6 (campeonato)
#include <stdio.h>
#include <stdlib.h>

int main() {    
    int i = 0, j = 0, posicao;
    int melhor = 0, vit = 0;
    int time[10] = {0};
   
    for (i = 0; i < 6; i++) {
         for (j = 0; j < 10; j++){
             printf("Posicao do time %d\n",j + 1);
             scanf("%d", &posicao);

         switch(posicao) {
                case 1:
                    time[j] += 10;
                    break;
                case 2:
                    time[j] += 8;
                    break;
                case 3:
                    time[j] += 6;
                    break;
                case 4:
                    time[j] += 4;
                    break;
                case 5:
                    time[j] += 4;
                    break;
                default:                        
                    time[j] += 0;
         }
            if (time[j] > melhor) {
                melhor = time[j];
                vit = j + 1;
            }
        }
    }
    printf("O Time %d eh o campeao do Campeonato ABC\n", vit);

    system("pause");
    return 0;
}

