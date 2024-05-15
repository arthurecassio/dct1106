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
    printf("Número de Caracteres: %d\n",numCaracteres(frase));
    printf("Número de Palavras: %d\n",numPalavras(frase));
    printf("Maior Palavra: %s\n",maiorPalavra(frase));
    printf("Menor Palavra: %s\n",menorPalavra(frase));
    return 0;
}

int numCaracteres(char* frase){
    return strlen(frase);
}
/**
 * Função numPalavras recebe uma frase e conta os espaços entre as palavras da frase
 * mais uma posição, exemplo:
 * A frase 'Arthur Souza é professor do BSI' tem 5 espaços e consequentemente 6 Palavras.
 **/
int numPalavras(char* frase){
    int espacos = 0;
    for (int i = 0; i < numCaracteres(frase); i++)
    {
        if(frase[i] == ' ')espacos++;
    }
    return ++espacos;
}
/**
 * A Função Maior Palavra recebe uma frase e seleciona a maior palavra. 
*/
char* maiorPalavra(char* frase){
    /*int tamanhoFrase = numCaracteres(frase);
    int tamanhoMaior = 0;
    int posicaoPalavra = 0;
    int tamanhoPalavra = 0;
    //Busca a maior Palavra
    for (int i = 0; i < tamanhoFrase; i++)
    {
        ++tamanhoPalavra;        
        if(frase[i] == ' ' || frase[i] == '\0' || frase[i] == '\n'){
            if(tamanhoPalavra > tamanhoMaior){
                tamanhoMaior = tamanhoPalavra-1;
                posicaoPalavra=i-(tamanhoPalavra-1);
                tamanhoPalavra=0;
            }
        };
    }
    //Copia a Palavra
    char* palavra = (char *) malloc(tamanhoMaior * sizeof(char));
    for (int i = 0; i < tamanhoMaior; i++)
    {
        palavra[i] = frase[i+posicaoPalavra];
    }    
    return palavra;*/
    return frase;
}
char* menorPalavra(char* frase){
    /*int tamanhoFrase = numCaracteres(frase);
    int tamanhoMenor = 0;
    int posicaoPalavra = 0;
    int tamanhoPalavra = 0;
    //Busca a menor Palavra
    for (int i = 0; i < tamanhoFrase; i++)
    {
        ++tamanhoPalavra;        
        if(frase[i] == ' ' || frase[i] == '\0' || frase[i] == '\n'){
            if(tamanhoPalavra < tamanhoMenor || tamanhoMenor == 0){
                tamanhoMenor = tamanhoPalavra-1;
                posicaoPalavra= i - (tamanhoPalavra-1);
                tamanhoPalavra=0;
            }
        };
    }
    //Copia a Palavra
    char* palavra = (char *) malloc(tamanhoMenor * sizeof(char));
    for (int i = 0; i < tamanhoMenor; i++)
    {
        palavra[i] = frase[i+posicaoPalavra];
    }    
    return palavra;*/
    return frase;
}