/**
* Programa para Leitura do Aluno, Gravação em Arquivo Texto e Busca em Arquivo Texto.
* Structs para Aluno. O programa simula um módulo de Cadastro de Aluno.
*/


//Inclusão de Bibliotecas
#include <stdio.h>
#include <stdlib.h>
//Constante com nome do Arquivo
#define ARQUIVO_ALUNOS "alunos.txt"


//nomeando os tipos
typedef struct aluno Aluno;


//tipos
struct aluno{
   long int matricula;
   char nome[124];
   char email[124];   
};


//funções
int menuPrincipal(void);
void lerAluno(Aluno*);


//funções de manipulação de arquivos
int listaArquivoAlunos();
int gravaAluno(Aluno*);




int main(void)
{
   int selecao;
   do{
       selecao = menuPrincipal();
       switch (selecao)
       {
       case 1:       
           listaArquivoAlunos();
           break;
       case 2:{
           Aluno* aluno = (Aluno*) malloc(sizeof(Aluno));
           lerAluno(aluno);
           gravaAluno(aluno);
           break;
       }
       default:
           printf("A opção indicada: %d é inválida!", selecao);
           break;
       }
   }while (selecao != 3);
  
   return 0;
}


int menuPrincipal(void)
{
   int selecao;
   printf("----------------------------\n");
   printf("-- Menu de Opções ----------\n");
   printf("-- 1.Listar todos os Alunos -------\n");
   printf("-- 2.Cadastrar Aluno -------\n");
   printf("-- 3.Finalizar o programa --\n");
   printf("----------------------------\n");
   printf("Informe a opção desejada:\n");
   scanf("%d", &selecao);
   return selecao;
}


// Lê os dados do Aluno (matricula, nome, notas)
void lerAluno(Aluno *aluno)
{
  printf("Informe a matrícula do aluno: ");
  scanf("%ld", &aluno->matricula);
  printf("Informe o nome do aluno: ");
  scanf(" %124[^\n]", aluno->nome);
  printf("Informe o e-mail do aluno: ");
  scanf(" %124[^\n]", aluno->email);
};


int listaArquivoAlunos()
{
  FILE *fp;
  char letra;
  char linha[320];
  int cursorLinha = -1;


  fp = fopen(ARQUIVO_ALUNOS, "rt");
  if (fp == NULL)
  {
      printf("Erro no acesso do arquivo\n!");
      return 0;
  }
  printf("-------------------------- Lista de Alunos --------------------------------\n");
  letra = fgetc(fp);
  while (letra != EOF)
  {
      if(letra != '\n'){
          linha[++cursorLinha] = letra;          
      }else{
          linha[++cursorLinha] = '\0';
          printf("%s\n",linha);
          for (int i = 0; i < cursorLinha; i++)
          {
              linha[i] = ' ';
          }          
          cursorLinha = -1;                   
      }
      letra = fgetc(fp);
  }
  printf("---------------------------------------------------------------------------\n");
  fclose(fp);
};




int gravaAluno(Aluno* aluno)
{
  FILE *fp;
  fp = fopen(ARQUIVO_ALUNOS, "at");
  if (fp == NULL)
  {
      printf("Erro na criacao do arquivo\n!");
      return 0;
  }
  fprintf(fp, "Matrícula: %d, Nome: %s, e-mail: %s\n", aluno->matricula, aluno->nome, aluno->email);
  fclose(fp);
}