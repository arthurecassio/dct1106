#include <stdio.h>
#include <validacao.h>
#include <contato.h>

int menuPrincipal(void);
void verificarEmail(void);
void verificarTelefone(void);

int main(void){

    int selecao = menuPrincipal();
    switch (selecao)
    {
    case 1: menuContatos();
        break;
    case 2: verificarEmail();
        break;
    case 3: verificarTelefone();
        break;
    case 0: return 0;
        break;
    default:
        printf("A opção informada é inválida");
        break;
    }     
    return 0;
}
int menuPrincipal(void)
{
    int selecao;
    printf("----------------------------\n");
    printf("-- Menu de Opções ----------\n");
    printf("-- 1.Contatos --------------\n");
    printf("-- 2.Validar Telefone ------\n");
    printf("-- 3.Validar e-mail --------\n");
    printf("-- 0.Sair ------------------\n");
    printf("----------------------------\n");
    printf("Informe a opção desejada:\n");
    scanf("%d", &selecao);
    return selecao;
}

void verificarEmail(void){
    //Inserir Código
}
void verificarTelefone(void){   
    //Inserir Código
}
