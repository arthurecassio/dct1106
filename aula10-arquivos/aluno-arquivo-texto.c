/**
 * Programa para Leitura do Aluno, Gravação em Arquivo Texto e Busca em Arquivo Texto. 
 * Structs para Aluno.
 * O programa simula um módulo de Cadastro de Aluno.
*/
#include <stdio.h>

//nomeando os tipos
typedef struct aluno Aluno;

//tipos
struct aluno{
    long int matricula;
    char nome[124];
    char email[124];    
};

//funções
void lerAluno(Aluno*);
void exibeAluno(Aluno);

int main(void)
{
    return 0;
}

//Lê os dados do Aluno (matricula, nome, notas)
void lerAluno(Aluno* aluno){
  printf("Informe a matrícula do aluno: ");
  scanf("%ld", &aluno->matricula);
  printf("Informe o nome do aluno: ");
  scanf(" %80[^\n]", aluno->nome);
};

void exibeAluno(Aluno aluno){
    printf(
        "%ld - %s: %.2f, %.2f, %.2f => Média: %.2f\n",
        aluno.matricula,aluno.nome
    );
};
