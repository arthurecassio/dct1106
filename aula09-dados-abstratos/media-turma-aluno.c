/**
 * Programa para Cálculo da Média de Turma com 
 * Structs para Aluno e Turma.
 * O programa lê uma quantidade de alunos da Turma, máximo de 50 alunos.
 * Posteriormente o sistema imprime os alunos, com suas notas e a média do aluno e da turma.
*/
#include <stdio.h>

//nomeando os tipos
typedef struct aluno Aluno;
typedef struct turma Turma;

//tipos
struct aluno{
    long int matricula;
    char nome[124];
    float nota1;
    float nota2;
    float nota3;
    float media;
};

struct turma{
    char disciplina[124];
    Aluno alunos[50];
    int numeroAlunos;
    float media;
};

//funções
void lerAluno(Aluno*);
void exibeAluno(Aluno);
void exibeTurma(Turma);

int main(void)
{
    Turma turma;    
    // Título do programa
    printf("Cálculo de Média da Turma\n");
    // Lendo número de alunos da Turma
    printf("Digite o número de alunos da Turma\n");
    scanf("%d", &turma.numeroAlunos);
    // Lendo nome da Disciplina
    printf("Digite a disciplina da Turma\n");
    scanf("%s", turma.disciplina);
    
    // Declarando Array de Medias
    for (int i = 0; i < turma.numeroAlunos; i++)
    {
        // Lendo notas        
        lerAluno(&turma.alunos[i]);
        // Somando a Média da Turma
        turma.media += turma.alunos[i].media;
    }
    turma.media = turma.media / turma.numeroAlunos;
    exibeTurma(turma);
    return 0;
}

//Lê os dados do Aluno (matricula, nome, notas)
void lerAluno(Aluno* aluno){
  printf("Informe a matrícula do aluno: ");
  scanf("%ld", &aluno->matricula);
  printf("Informe o nome do aluno: ");
  scanf(" %80[^\n]", aluno->nome);
  printf("Informe a nota 1 do aluno: ");
  scanf("%f", &aluno->nota1);
  printf("Informe a nota 2 do aluno: ");
  scanf("%f", &aluno->nota2);
  printf("Informe a nota 3 do aluno: ");
  scanf("%f", &aluno->nota3);
  //Calculando a média
  aluno->media = (aluno->nota1+aluno->nota2+aluno->nota3)/3;
};

void exibeAluno(Aluno aluno){
    printf(
        "%ld - %s: %.2f, %.2f, %.2f => Média: %.2f\n",
        aluno.matricula,
        aluno.nome,
        aluno.nota1,
        aluno.nota2,
        aluno.nota3,
        aluno.media
    );
};
void exibeTurma(Turma turma){
    printf("\n******* Turma: %s *******\n",turma.disciplina);
    for (int i = 0; i < turma.numeroAlunos; i++){        
        exibeAluno(turma.alunos[i]);
    }
    printf("** Média da Turma: %.2f **\n",turma.media);
};