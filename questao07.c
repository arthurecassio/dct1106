#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maximoString 1024

int numCaracteres(char* frase);
int numPalavras(char* frase);
char* maiorPalavra(char* frase);
char* menorPalavra(char* frase);

int main(void)
{
    char frase[maximoString];
    printf("Digite uma frase completa!\n");
    fgets(frase,maximoString,stdin);
    printf("Número de Caracteres: %d\n",numPalavras(frase));
    printf("Número de Palavras: %d\n",numPalavras(frase));
    printf("Maior Palavra: %s\n",maiorPalavra(frase));
    printf("Menor Palavra: %s\n",menorPalavra(frase));
    return 0;
}

int numCaracteres(char* frase){
    return strlen(frase);
}
int numPalavras(char* frase){
    //Inserir Código
    return 0;
}
char* maiorPalavra(char* frase){
    //Inserir Código
    return frase;
}
char* menorPalavra(char* frase){
    //Inserir Código
    return frase;
}