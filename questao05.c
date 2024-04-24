#include <stdio.h>

int eLetra(char c);
int eNumero(char c);
int menuPrincipal(void);
int opcao01(void);
int opcao02(void);

int main(void)
{
    int selecao;
    // Incluir Código para Repetição
    selecao = menuPrincipal();
    switch (selecao)
    {
    case 1:
        opcao01();
        break;
    case 2:
        opcao02();
        break;
    case 3:
        return 0;
        break;
    default:
        printf("A opção indicada: %d é inválida!", selecao);
        break;
    }

    return 0;
}

int menuPrincipal(void)
{
    int selecao;
    printf("----------------------------\n");
    printf("-- Menu de Opções ----------\n");
    printf("-- 1.Verificar Letra -------\n");
    printf("-- 2.Verificar Número ------\n");
    printf("-- 3.Finalizar o programa --\n");
    printf("----------------------------\n");
    printf("Informe a opção desejada:\n");
    scanf("%d", &selecao);
    return selecao;
}
int opcao01(void)
{
    
    char c;
    printf("-----------------------------\n");
    printf("-- Verificação de Letra -----\n");
    printf("-----------------------------\n");
    printf("Informe o caracter desejado:\n");
    scanf(" %c", &c);
    if(eLetra(c)){
        printf("O caracter %c é uma letra.\n",c);
        return 1;
    }else{
        return 0;
    }
    
}
int opcao02(void)
{
    // Inserir o Código aqui.
    return 0;
}

int eLetra(char c)
{
    if ((c >= 'a') && (c <= 'z'))
    {
        return 1;
    }
    if ((c >= 'A') && (c <= 'Z'))
    {
        return 1;
    }
    return 0;
};
int eNumero(char c)
{
    // Inserir código Aqui
    return 0;
};