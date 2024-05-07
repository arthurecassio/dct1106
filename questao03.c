#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int eNumero(char c);
int eDataValida(char* data);
int eDataValidaNumeric(char* data);
int bissexto(int ano);

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
        if(eDataValidaNumeric(data)){
            printf("A data: %s é válida!\n",data);
        }
    }else{
        printf("A data: %s não é válida!\n",data);
    }
    
    return 0;
}


int eNumero(char c){
    if(c >= '0' && c <= '9') return 1;
    return 0;
}
int eDataValida(char* data){
    //Verificando formato da data
    if(data[2] != '/' || data[5] != '/') return 0;   
    
    char d1 = data[0];
    char d2 = data[1];

    if(d1 < '0' || d1 > '2') return 0;
    if(d2 < '0' || d2 > '9') return 0;

    char m1 = data[3];
    char m2 = data[4];

    if(m1 < '0' || m1 > '1') return 0;
    if(m2 < '0' || m2 > '2') return 0;

    char a1 = data[6];
    char a2 = data[7];
    char a3 = data[8];
    char a4 = data[9];
    
    if(a1 < '0' || a1 > '2') return 0;
    if(a2 < '0' || a2 > '9') return 0;
    if(a3 < '0' || a3 > '9') return 0;
    if(a4 < '0' || a4 > '9') return 0;

    return 1;
}

//Método de Validação com conversão de String para Inteiro
int eDataValidaNumeric(char* data){
    // DD / MM / YYYY
    // 01 2 34 5 6789

    char diaStr[] = {data[0],data[1],'\0'};
    char mesStr[] = {data[3],data[4],'\0'};
    char anoStr[] = {data[6],data[7],data[8],data[9],'\0'};

    //Usando strtol
    int dia = strtol(diaStr,NULL,0);
    int mes = strtol(mesStr,NULL,0);
    //Usando atoi
    int ano = atoi(anoStr);

    if(dia < 0 || dia > 31) return 0;
    if(ano < 0) return 0;
    if(mes < 0 || mes > 12) return 0;
    if(mes == 4 || mes == 6 || mes == 9 || mes == 11){
        if(dia > 30) return 0;
    }else if(mes == 2){
        if(bissexto(ano)){
            if(dia > 29) return 0;
        }else{
            if(dia > 28) return 0;
        } 
    }
    return 1;
}

// Codigo baseado em https://learn.microsoft.com/pt-br/office/troubleshoot/excel/determine-a-leap-year
int bissexto(int ano){
    int bissexto = 0;
    if(ano % 4 == 0 || (ano % 100 == 0 && ano % 400 == 0)) bissexto = 1;
    return bissexto;
}