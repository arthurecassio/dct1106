/**
 * Programa para manipulação CRUD (Create, Read, Update and Delete) do Aluno em Arquivo Binário.
 * Structs para Aluno. O programa simula um módulo de Controle de Cadastro de Alunos.
 */

// Inclusão de Bibliotecas
#include <stdio.h>
#include <stdlib.h>

// Constante com nome do Arquivo
#define ARQUIVO_ALUNOS "alunos.dat"
#define ARQUIVO_ALUNOS_TMP "alunos.tmp"

// nomeando os tipos
typedef struct aluno Aluno;

// tipos
struct aluno
{
    long int matricula;
    char nome[124];
    char email[124];
};

// funções
int menuPrincipal(void);
void lerAluno(Aluno *);
int subMenuBusca();
void atualizarNome(Aluno *);
void atualizarEmail(Aluno *);
int excluirAluno(long int);

// funções de manipulação de arquivos
int listaArquivoAlunos();
int criaAluno(Aluno *);
int atualizaAluno(Aluno *);
void imprimeAluno(Aluno *);
Aluno* buscaAluno(long int);
int deletaAluno(long int);

int main(void)
{
    int selecao;
    do
    {
        selecao = menuPrincipal();
        switch (selecao)
        {
        case 1:
            if(listaArquivoAlunos() == 0){
                printf("Erro no acesso ao arquivo de dados !!");
                return 0;
            }
            break;
        case 2:
        {
            Aluno *aluno = (Aluno *)malloc(sizeof(Aluno));
            lerAluno(aluno);
            if(criaAluno(aluno) == 1){
                printf("Aluno criado !!\n");
            }else{
                printf("Erro na criação do aluno !!");
                return 0;
            } 
            break;
        }
        case 3:
        {
            long int matricula = 0;
            printf("Informe a matrícula do aluno: ");
            scanf("%ld", &matricula);
            Aluno *aluno = buscaAluno(matricula);
            if (aluno != NULL)
            {
                imprimeAluno(aluno);
                int atualizar = subMenuBusca();
                switch (atualizar)
                {
                case 1:
                    atualizarNome(aluno);
                    if(atualizaAluno(aluno)) printf("Aluno Atualizado!!\n");
                    break;
                case 2:
                    atualizarEmail(aluno); 
                    if(atualizaAluno(aluno)) printf("Aluno Atualizado!!\n");;
                    break;
                case 3:
                    if (excluirAluno(aluno->matricula)){
                        if(deletaAluno(aluno->matricula)) printf("Aluno excluído!!\n");
                    }
                    break;
                case 4:
                    break;
                default:
                    break;
                }
            }
            else
            {
                printf("Aluno não encontrado.\n");
            }
            break;
        }
        case 4:
        {
            break;
        }
        default:
            printf("A opção indicada: %d é inválida!\n", selecao);
            break;
        }
    } while (selecao != 4);
    return 0;
}

int menuPrincipal(void)
{
    int selecao;
    printf("------------------------------------\n");
    printf("-- Menu de Opções ------------------\n");
    printf("-- 1.Listar todos os Alunos --------\n");
    printf("-- 2.Cadastrar Aluno ---------------\n");
    printf("-- 3.Buscar Aluno ------------------\n");
    printf("-- 4.Finalizar o programa ----------\n");
    printf("------------------------------------\n");
    printf("Informe a opção desejada:\n");
    scanf("%d", &selecao);
    return selecao;
}

int subMenuBusca(void)
{
    int selecao;
    printf("-------------------------------\n");
    printf("-- Alterar Aluno ? ------------\n");
    printf("-- 1.Atualizar Nome -----------\n");
    printf("-- 2.Atualizar Email ----------\n");
    printf("-- 3.Excluir Aluno ------------\n");
    printf("-- 4.Voltar -------------------\n");
    printf("-------------------------------\n");
    printf("Informe a opção desejada:\n");
    scanf("%d", &selecao);
    return selecao;
}

// Lê os dados do Aluno (matricula, nome, notas)
void lerAluno(Aluno *aluno)
{
    printf("Informe a matrícula do aluno: ");
    scanf("%ld", &aluno->matricula);
    printf("Informe o nome do aluno: ");
    scanf(" %124[^\n]", aluno->nome);
    printf("Informe o e-mail do aluno: ");
    scanf(" %124[^\n]", aluno->email);
};

int listaArquivoAlunos()
{
    FILE *fp;
    Aluno *aluno = (Aluno*) malloc(sizeof(Aluno));
    
    fp = fopen(ARQUIVO_ALUNOS, "rb");
    if (fp == NULL)
    {
        printf("Erro no acesso do arquivo\n!");
        return 0;
    }
    printf("-------------------------- Lista de Alunos --------------------------------\n");
    while (fread(aluno, sizeof(Aluno), 1, fp))
    {
        imprimeAluno(aluno);
    }
    printf("---------------------------------------------------------------------------\n");
    
}

void imprimeAluno(Aluno *aluno){
    printf("Matrícula: %ld, Nome: %s, E-mail: %s\n",aluno->matricula,aluno->nome,aluno->email);
}

void atualizarNome(Aluno *aluno){
    printf("Informe o nome do aluno: ");
    scanf(" %124[^\n]", aluno->nome);
}

void atualizarEmail(Aluno *aluno){
    printf("Informe o email do aluno: ");
    scanf(" %124[^\n]", aluno->email);
}

int excluirAluno(long int matricula){
    char confirma = 'N';
    printf("Deseja excluir o aluno: %d ?: S-SIM, N-Não ",matricula);
    scanf(" %c", &confirma);
    return confirma == 'S' ? 1 : 0;
}


Aluno* buscaAluno(long int matricula){
    FILE *fp;
    Aluno *aluno = (Aluno *)malloc(sizeof(Aluno));
    fp = fopen(ARQUIVO_ALUNOS, "rb");
    if (fp == NULL)
    {
        printf("Erro no acesso do arquivo\n!");
        return 0;
    }
    while (fread(aluno, sizeof(Aluno), 1, fp))
    {
        if(aluno->matricula == matricula){
            fclose(fp);
            return aluno;
        }
    }
    fclose(fp);
    return NULL;
}


int criaAluno(Aluno *aluno)
{
    FILE *fp;
    fp = fopen(ARQUIVO_ALUNOS, "ab");
    if (fp == NULL)
    {
        printf("Erro na criacao do arquivo\n!");
        return 0;
    }
    //Insere o aluno no final do arquivo
    fwrite(aluno,sizeof(Aluno),1,fp);
    fclose(fp);
    return 1;
}

int atualizaAluno(Aluno *aluno){
    FILE *fp;
    Aluno *auxiliar = (Aluno *) malloc(sizeof(Aluno));
    fp = fopen(ARQUIVO_ALUNOS, "r+b");
    if (fp == NULL)
    {
        printf("Erro na criacao do arquivo\n!");
        return 0;
    }
    //Busca o aluno no arquivo para posicionar o cursor do arquivo
    while (fread(auxiliar, sizeof(Aluno), 1, fp))
    {
        if(auxiliar->matricula == aluno->matricula){
            //Reposiciona o cursor para a posição inicial do Aluno
            fseek(fp, -1*sizeof(Aluno), SEEK_CUR);
            //Reescreve o aluno
            fwrite(aluno, sizeof(Aluno), 1, fp);        
            fclose(fp);           
            return 1;
        }
    }  
    fclose(fp);
    printf("Erro na atualização do aluno.\n!");
    return 0;
};

int deletaAluno(long int matricula){
    FILE *fleitura;
    FILE *fescrita;
    Aluno *auxiliarLeitura = (Aluno *) malloc(sizeof(Aluno));
 
    fleitura = fopen(ARQUIVO_ALUNOS, "rb");
    if (fleitura == NULL)
    {
        printf("Erro na criacao do arquivo\n!");
        return 0;
    }
    fescrita = fopen(ARQUIVO_ALUNOS_TMP, "wb");
    if (fescrita == NULL)
    {
        printf("Erro na criacao do arquivo\n!");
        return 0;
    }
    //Lendo o arquivo atual
    while (fread(auxiliarLeitura, sizeof(Aluno), 1, fleitura))
    {
        //Caso a matricula seja diferente
        if(auxiliarLeitura->matricula != matricula){
            //Escreva no arquivo novo
            fwrite(auxiliarLeitura,sizeof(Aluno), 1, fescrita);            
        }
    }  
    fclose(fescrita);
    fclose(fleitura);
    //Renomeia o arquivo novo com o nome do antigo
    rename(ARQUIVO_ALUNOS_TMP,ARQUIVO_ALUNOS);
    return 1;
};