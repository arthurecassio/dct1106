#include <stdio.h>
#include <stdlib.h>
#include "./validacao.h"

#define totalContatos 100
#define maxString 1024

int menuConsulta(void);
int menuPrincipal(void);
void listarContatos(int, char *, char *, char *);
void criarContato(char *, char *, char *);

void menuContatos(void)
{
    int controle = 0;
    char nomes[totalContatos][maxString];
    char telefones[totalContatos][maxString];
    char emails[totalContatos][maxString];
    int selecao = menuPrincipal();

    //Inserir Código
    
    return;
}

int menuPrincipal(void)
{
    int selecao;
    printf("----------------------------\n");
    printf("-- Menu de Opções ----------\n");
    printf("-- 1.Criar Contato----------\n");
    printf("-- 2.Consultar Contato------\n");
    printf("-- 3.Listar Contatos --------\n");
    printf("-- 0.Sair ------------------\n");
    printf("----------------------------\n");
    printf("Informe a opção desejada:\n");
    scanf("%d", &selecao);
    return selecao;
}

int menuConsulta(void)
{
    int selecao;
    printf("----------------------------\n");
    printf("-- Menu de Opções ----------\n");
    printf("-- 1.Por Nome --------------\n");
    printf("-- 2.Por Telefone ------\n");
    printf("-- 3.Por e-mail --------\n");
    printf("-- 0.Sair ------------------\n");
    printf("----------------------------\n");
    printf("Informe a opção desejada:\n");
    scanf("%d", &selecao);
    return selecao;
}

void listarContatos(int numContatos, char *nomes, char *telefones, char *emails)
{
    for (int i = 0; i < numContatos; i++)
    {
        printf("[nome: %s, telefone: %s, e-mail: %s]", nomes[i], telefones[i], emails[i]);
    }
}