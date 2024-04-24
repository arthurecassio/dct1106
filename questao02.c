#include <stdio.h>

int eLetra(char c);
int eNumero(char c);
int eEspecial(char c);

int main(void)
{
    char ch;
    printf("Digite um caracter:\n");
    scanf(" %c", &ch);

    if (eLetra(ch))
    {
        printf("O caracter %c é uma letra.\n", ch);
        return 0;
    }
    if (eNumero(ch))
    {
        printf("O caracter %c é um número.\n", ch);
        return 0;
    }
    if (eEspecial(ch))
    {
        printf("O caracter %c é um caracter especial.\n", ch);
        return 0;
    }
    printf("O caracter %c não foi identificado.\n", ch);
    return 0;
}

int eLetra(char c){
    if((c >= 'a') && (c <= 'z')){
        return 1;
    }    
    if((c >= 'A') && (c <= 'Z')){
        return 1;
    }
    return 0;
};
int eNumero(char c){
    //Inserir código Aqui
    return 0;
};
int eEspecial(char c){
    //Inserir Código Aqui
    return 0;
};
