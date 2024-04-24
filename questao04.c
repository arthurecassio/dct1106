#include <stdio.h>

int eLetra(char c);
int eNumero(char c);
int eEspecial(char c);
char validar(char c);

int main(void)
{

    // Incluir Código para Repetição
    char ch;
    printf("Digite um caracter:\n");
    scanf(" %c", &ch);

    char validacao = validar(ch);
    switch (validacao)
    {
    case 'L':
        printf("O caracter %c é uma letra.\n", ch);
        break;
    case 'N':
        printf("O caracter %c é um número.\n", ch);
        break;
    case 'E':
        printf("O caracter %c é um caracter especial.\n", ch);
        break;
    default:
        printf("O caracter %c não foi identificado.\n", ch);
        break;
    }

    return 0;
}
// Retorna N para Número, L para Letra, E para Especial, I para Inderteminado.
char validar(char c)
{
    return 'I';
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
int eEspecial(char c)
{
    // Inserir Código Aqui
    return 0;
};