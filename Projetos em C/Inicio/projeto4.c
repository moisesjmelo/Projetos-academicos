//Projeto de c questão 11.15  do livro
//Dupla: diomedes/ Moises
#include <stdio.h> 
#include <stdlib.h> 
 
void exibe(void); //prototipo de func que exibe texo digitado
void cria(FILE *); //prototipo de func que cria arquivo 
void adiciona(FILE *); //prototipo de func que adiciona dados no fim do arquivo
void ler(void); //prototipo de func que ler arquivo
void subistitui(FILE *); //prototipo de func que ler arquivo

int main(){    
      char c;  
      int i = 0, opcao = 0; 
      FILE *cptr; 
  
      do{ 
         printf ("Escolha uma opcao:\n 1. Ler da entrada padrao e escrever na saida padrao;\n");
         printf(" 2.criar um arquivo\n 3. Adicionar dados, em sequencia, no arquivo projeto\n 4. Ler o arquivo projeto\n"
                " 5. Substituir todo o conteudo do arquivo projeto\n 6. Sair.\n\n");
         scanf("%d",&opcao);
  
         switch (opcao){
                case 1:                 
                      exibe(); //chama a funcao que le cada caracter e mostra tudo na tela.               
                      break;
                case 2:
                      cria(cptr);//chama a funcao que cria o arquivo de nome projeto. 
                      break;
                case 3:
                      adiciona(cptr); //chama a funcao que adiciona dados no final do arquivo de nome projeto.                  
                      break;
                case 4:                      
                      ler(); //chama a funcao que le o arquivo de nome projeto.                                  
                      break;
                case 5:
                      subistitui(cptr); //chama a funcao que subistitui os dados do arquivo de nome projeto.                
                      break; 
                case 6:
                      printf("saindo\n\n");
                      break;              
                default:
                      puts("Opcao invalida:");  
                           
          }//fecha switch
          printf("Digite 6. Para encerrar o programa\n       7. Para um novo acesso:\n\n");
          scanf("%d",&opcao);
     }while(opcao != 6);
 
 system("pause");  
 return 0; 
 }
  void exibe(FILE *fptr){
       
  char c,  sentence[80];  
  int i = 0; 
   
puts("Digite uma linha de texto:"); 
 while (( c = getchar())!='\n')  
  
sentence[i++]  = c; 
  
 sentence[i]   =  '\0';  /* insere NULL no final da string */  
 puts("\nA linha digitada foi:");  
 retorn (sentence);
       
       
       
       /*
       char c;
       char nome[10000];
       int conta;
       float saldo;
       int i;
       puts("Digite o texo apenas para exibicao na tela:");
       scanf("%c",&c);
       while (( c = getchar())!='\n'){ 
              if(c != '\n')   
                 nome[i++] = c;   
                 nome[i] = '\0';// insere NULL no final da string                        
       }//fecha o while
       scanf("%d%f",&conta,&saldo);
       puts("\nO texto digitado foi:");  
       printf("Nome: %s\n",nome); //imprime o texto digitado.
       printf("conta no: %d\nsaldo: %.2f",conta,saldo);
       printf("\n"); */
} //fim func exibe

  void cria(FILE *fptr){
       
       struct dadosCliente {  
              int numConta;  
              char sobrenome[15];  
              char primNome[10];  
              float saldo; 
       };  
       FILE *gravaPtr;    
       struct dadosCliente cliente; 
       char arquivo[50];
       int conta;
       
       printf("informe o arquivo:\n");
       scanf("%s",&arquivo);
       printf("informe a conta:\n");
       scanf("%d",&conta);      
   
       if  ((gravaPtr = fopen(arquivo,   "rb+"))  == NULL) 
            printf("Arquivo nao pode ser aberto.\n");  
       else { 
            printf("Digite o numero da conta (1 a 10,   0 para encerrar dados)\n? "); 
            scanf("%d", &cliente.numConta); 
       while (cliente.numConta != 0) { 
              printf("Digite sobrenome, primeiro nome e saldo\n? ");  
              scanf("%s %s %f",  &cliente.sobrenome, &cliente.primNome, &cliente.saldo);  
              fseek(gravaPtr,  (cliente.numConta - 1)*sizeof(struct dadosCliente), SEEK_SET);  
              fwrite(&cliente,sizeof(struct dadosCliente),  1,  gravaPtr); 
              printf("Digite o numero da conta\n? "); 
              scanf("%d", &cliente.numConta); 
    } 
  } 
  fclose(gravaPtr);
       
       
       
       
       
 /*      
             
if ((gravaptr = fopen("projeto3.dat", "w")) == NULL)
        printf("Arquivo nao pode ser criado");
    else{
        puts("Digite o texo para criar o arquivo de nome projeto3:"); 
        printf("?");
        scanf("%s",&texto);
         
    while(!feof(stdin)){
          fprintf(gravaptr, "%s\n",texto);
          scanf("%s",&texto);                  
          }          
    fclose(gravaptr);
}
printf("\n\n");  */
}//fim func cria

 void adiciona(FILE *fptr){
          char texto[10000];
          FILE *adptr;          
          if ((adptr = fopen("projeto3.dat", "a")) == NULL)
              printf("Arquivo nao pode ser aberto");
          else{
              puts("Digite o texo para adicionar ao arquivo de nome projeto3:" 
                   " em seguida entre com EOF (ctrl+z) para encerrar entradas de dados" );
              scanf("%s",&texto);
        
              while(!feof(stdin)){
                   fprintf(adptr, "%s\n",texto);
                   scanf("%s",&texto);                             
              }  
              fclose(adptr);
          }
          printf("\n\n");
}//fim func adiciona

void ler(void){
        char texto[10000];
        FILE *leptr;
                  
        if ((leptr = fopen("projeto3.dat", "r")) == NULL)
            printf("Arquivo nao pode ser aberto");
        else{
            puts("Este eh o conteudo do arquivo projeto3:"); 
            fscanf(leptr, "%s",&texto);
        
            while(!feof(leptr)){
                   printf("\n%p",ftell(leptr));   
                   fprintf(leptr,"%s",texto);
                   fscanf(leptr, "%s",&texto);                
            }
            fclose(leptr);
        }
        printf("\n\n");
}//fim func ler

void subistitui(FILE *fptr){
          char texto[10000];
          FILE *subptr;          
          if ((subptr = fopen("projeto3.dat", "w")) == NULL)
              printf("Arquivo nao pode ser criado");
          else{
               puts("Digite o texo para subistituir os adados do arquivo de nome projeto3:"
                    " em seguida entre com EOF (ctrl+z) para encerrar entradas de dados" ); 
               printf("?");
               fscanf(subptr,"%s",texto);
          
               while(!feof(stdin)){
                    fprintf(subptr, "%s\n",texto);
                    //scanf("%s",&texto); 
                     fscanf(subptr,"%s",texto);
              
               } 
               fclose(subptr);
           }
            printf("\n\n");
}//fim func subistitui
