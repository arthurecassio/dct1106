#include <stdio.h>

int main(void){
    char ch;
    printf("Digite um caracter:\n");
    scanf(" %c",&ch);
    
    if((ch >= 'a') && (ch <= 'z')){
        printf("O caracter %c é uma letra.\n",ch);
        return 0;
    }    
    if((ch >= 'A') && (ch <= 'Z')){
        printf("O caracter %c é uma letra.\n",ch);
        return 0;
    }
    printf("O caracter %c é não é uma letra.\n",ch);
    return 0;
}