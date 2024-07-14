/**
 * Programa exemplo para ordenação de inteiros com Lista Encadeada
 * Struct no representa um elemento da lista
 */
#include <stdio.h>
#include <stdlib.h>

// nomeando os tipos
typedef struct item No;

// tipos
struct item
{
    int valor;
    struct item *proximo;
};

// funções
int lerInteiro(void);
int menuPrincipal(void);

// funções de manipulação da lista
void inserirInteiro(int, No **);
void exibeLista(No *);

int main(void)
{

    // Iniciando a lista com ponteiro vazio
    No *inicio = NULL;

    int selecao;
    do
    {
        selecao = menuPrincipal();
        switch (selecao)
        {
        case 1:
        {
            int valor = lerInteiro();
            //Como a váriavel inicio será modificada no método Inserir deve ser
            //passado o endereco usando o operador &
            inserirInteiro(valor, &inicio);
            break;
        }
        case 2:
        {
            exibeLista(inicio);
            break;
        }
        case 3:
        {
            break;
        }
        default:
            printf("A opção indicada: %d é inválida!\n", selecao);
            break;
        }
    } while (selecao != 3);
    return 0;
}

int menuPrincipal(void)
{
    int selecao;
    printf("------------------------------------\n");
    printf("-- Menu de Opções ------------------\n");
    printf("-- 1.Inserir Inteiro --------\n");
    printf("-- 2.Exibir Lista ---------------\n");
    printf("-- 3.Finalizar o programa ----------\n");
    printf("------------------------------------\n");
    printf("Informe a opção desejada:\n");
    scanf("%d", &selecao);
    return selecao;
}

int lerInteiro()
{
    int inteiro;
    printf("Informe o valor desejado:\n");
    scanf("%d", &inteiro);
    return inteiro;
}

// Inserindo novo valor na lista
//Parametrô No é um ponteiro de ponteiro por que é necessário
//alterar a variável de cabeça (ínicio) da lista
void inserirInteiro(int novoValor, No **inicio)
{
    // Criando novo item da lista
    No *novo = (No *) malloc(sizeof(No));
    novo->valor = novoValor;
    novo->proximo = (*inicio);
    // Atualiza o inicio da lista para o nó recém criado
    (*inicio) = novo;    
}

void exibeLista(No *inicio)
{
    // Percorendo a lista para imprimir
    No *tmp;
    for (tmp = inicio; tmp != NULL; tmp = tmp->proximo)
    {
        printf("->%d", tmp->valor);
    }
    printf("\n");
}

