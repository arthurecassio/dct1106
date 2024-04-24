#include <stdio.h>
#include <stdlib.h>

int eNumero(char c);
int eDataValida(char* data);

int main(void)
{
    char data[10];
    // DD / MM / YYYY
    // 01 2 34 5 6789
    printf("Digite uma data no formato: DD/MM/YYYY\n");
    scanf(" %s", data);

    for (int i = 0; i < 10; i++)
    {
        //Se não for número ou '/'
        //Retorne um erro
        if(data[i] != '/' && !eNumero(data[i])){
            printf("A data: %s, não é válida!\n",data);
            return 0;
        }
    }
   
   
    if(eDataValida(data)){
        printf("A data: %s é válida!\n",data);
    }else{
        printf("A data: %s não é válida!\n",data);
    }
    
    return 0;
}


int eNumero(char c){
    //Inserir código Aqui
    return 0;
}
int eDataValida(char* data){
    //Inserir Código Aqui
    return 0;
}