#include <stdio.h>
#define maximoItens 15
#define maximoString 124

void imprimeItens(int,char[maximoItens][maximoString],float[maximoItens]);
void leItem(char*,float*);

int main(void)
{
    char descricoes[maximoItens][maximoString];
    float valores[maximoItens];
    int numItens;
    printf("Digite a quantidade de itens, máximo de 15:\n");
    scanf("%d",&numItens);
    for (int i = 0; i < numItens; i++)
    {
        leItem(descricoes[i],&valores[i]);
    }
    imprimeItens(numItens,descricoes,valores);
    
    return 0;
}

void leItem(char* descricao, float* valor){
    printf("Digite a descrição do item:\n");
    scanf(" %s",descricao);
    printf("Digite o valor do item:\n");
    scanf(" %f",valor);
}

void imprimeItens(int num, char descricoes[maximoItens][maximoString], float valores[maximoItens])
{
    float soma = 0;
    printf("------- Lista de Itens ---------\n");
    printf("N.  -- Descrição ----- Valor ---\n");
    for (int i = 0; i < num; i++)
    {
        soma += valores[i];
        printf("%d. -- %s -- %.2f --\n",i+1,descricoes[i],valores[i]);
    }
    printf("------- Total de Compra -------\n");
    printf("------- R$ %.2f -------\n",soma);
    
}