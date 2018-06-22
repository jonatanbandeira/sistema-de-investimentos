#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h> //Biblioteca para usar a funçao strcm
#include <ctype.h>
#include <locale.h>
#include <windows.h>

char nomeArquivo[20] = "cadastro.txt";

struct Pessoa{
    char login[30];
    int idade;
    char email[20];
    char senha[9];
};

// prototipação
void menu();
FILE *abrirArquivo(char modo, char *caminho);
void fecharArquivo(FILE *arquivo);
void inserirContato(struct Pessoa umaPessoa);
struct Pessoa lerLogin();
void validarCadastro(struct Pessoa umaPessoa);
void menutempo();

int main()
{
    int op;
    struct Pessoa umaPessoa;
    char nome[20];

    setlocale(LC_ALL, "Portuguese");


        menu();
        printf("\t|--------------Digite uma opcão-----------------|\n");
        printf("\t  Opção desejada: ");
        scanf("%d", &op);

        switch (op){
        case 1:
            system("cls");
            printf("\n\t-----------SISTEMA DE CADASTRO JLINVEST LTDA-------------");
            printf("\n\n\tDigite seu login: ");
            getchar();
            scanf("%[^\n]s", umaPessoa.login);
            printf("\tDigite uma senha de até 8 digitos: ");
            getchar();
            scanf("%[^\n]s", umaPessoa.senha);
            printf("\tDigite sua idade: ");
            scanf("%d", &umaPessoa.idade);
            printf("\tDigite seu E-mail: ");
            getchar();
            scanf("%[^\n]s", umaPessoa.email);

            if(umaPessoa.idade<18){
                printf("\n\n\tATENÇÃO: Sistema não disponível para menores de 18 anos!\n\n\n");
            }else{
                inserirContato(umaPessoa);
                puts("\n\n\t*************CASDASTRO REALIZADO COM SUCESSO**************\n\n");
                system("pause");
                system("cls");
                validarCadastro(umaPessoa);
            }

            system("pause");
            break;
        case 2:
            validarCadastro(umaPessoa);
            break;
        case 0:
            printf("\n\nFinalizando o sistema...\n\n");
            Sleep(2000);
            break;
        default:
            system("cls");
            printf("\n\nOpcao invalida!\n");
        }
    return 0;
    }


void menu(){

    puts("\n");

    printf("\t-------------BEM VINDO À JLINVEST LTDA ----------\n");
    printf("\t|                                               |\n");
    printf("\t| Digite 1 para cadastrar                       |\n");
    printf("\t| Digite 2 para logar                           |\n");
    printf("\t| Digite 0 para sair                            |\n");
    printf("\t|                                               |\n");
}

FILE *abrirArquivo(char modo, char *caminho){
    FILE *arquivo;

    switch (modo){
    case 'a':
        arquivo = fopen(caminho, "a");
        break;
    case 'r':
        arquivo = fopen(caminho, "rt");
        break;
    case 'w':
        arquivo = fopen(caminho, "wt");
        break;
    }
    if (arquivo == NULL){
        printf("Erro ao abrir o arquivo!");
        exit(0);
    }

    return arquivo;
}


 void validarCadastro(struct Pessoa umaPessoa){

    FILE *fp = fopen("cadastro.txt", "rt"); //"r" para ler o que tem no arquivo

    if (fp == NULL){
        printf("\nO arquivo não foi aberto!");
        exit(0);
    }

    char login[100], senha[100], str[2];
    int logou = 0;
    struct Pessoa pess;

    printf("\n\tLOGIN........: ");
    getchar();
    scanf("%[^\n]s" ,login);

    printf("\n\tSENHA........: ");
    getchar();
    scanf("%[^\n]s" ,senha);


    //printf("\nLogin: %s", login); //teste p ver o que estava imprimindo
    //printf("\nSenha: %s", senha); //teste p ver o que estava imprimindo

    while(!feof(fp)) {
        fscanf(fp, "%[^;]s", pess.login);
        fscanf(fp, ";%[^;]s", pess.senha);
        fscanf(fp, ";%d", &pess.idade);
        fscanf(fp, ";%s ", pess.email);
        if((strcmp(pess.login, login) == 0) && (strcmp(pess.senha, senha) == 0) ) {
            logou = 1;
        }
    }//Fim while

    fclose(fp);

    if (logou) {
        system("cls");
        printf("\n\tBEM VINDO! USUÁRIO LOGADO!\n");
        bemvindo();

    } else {
        system("cls");
        printf("\n\tNAO LOGADO! TENTE NOVAMENTE!\n");
        validarCadastro(umaPessoa);
        Sleep(2000);

    }

}


struct Pessoa lerLogin() {

    struct Pessoa p;

    printf("\n\tLOGIN........: ");
    gets(p.login);
    getchar();

    printf("\n\tSENHA........: ");
    gets(p.senha);
    getchar();

    return p;
}


void fecharArquivo(FILE *arquivo){
    fclose(arquivo);
}

void inserirContato(struct Pessoa umaPessoa){
    FILE *arquivo;
    arquivo = abrirArquivo('a', nomeArquivo);
    fprintf(arquivo, "%s;%s;%d;%s\n", umaPessoa.login, umaPessoa.senha, umaPessoa.idade, umaPessoa.email);
    fecharArquivo(arquivo);
}
void menutempo(){
    printf("\n\t|-------------BEM VINDO À JLINVEST LTDA --------|\n");
    printf("\t|                                               |\n");
    printf("\t| Digite 1 para 90 dias                         |\n");
    printf("\t| Digite 2 para 180 dias                        |\n");
    printf("\t| Digite 3 para 1 ano                           |\n");
    printf("\t| Digite 4 para 2 anos                          |\n");
    printf("\t| Digite 5 para 3 anos                          |\n");
    printf("\t| Digite 6 para 4 ano                           |\n");
    printf("\t| Digite 7 para 5 anos                          |\n");
    printf("\t|_______________________________________________|\n");
}

void bemvindo(){
    float valor;
    float rtin=0;
    int escolha;
    printf("\n\n");
    printf("\t  Digite o valor que deseja investir: ");
    scanf("%f", &valor);
    system("cls");

    menutempo();
    scanf("%d",&escolha);

    switch (escolha){

        case 1:
        printf("\n\t|--------------OPÇÃO ESCOLHIDA 1----------------|\n");
        printf("\t|-------------------90 dias---------------------|\n");
        printf("\t|                                               |\n");
        printf("\t| Digite 1 para CDB 80%% do CDI                  |\n");
        printf("\t| Digite 0 para voltar ao menu anterior         |\n");
        printf("\t|_______________________________________________|\n");
/*
            if(){



            }
*/
        break;

        case 2:
        printf("\n\t|--------------OPÇÃO ESCOLHIDA 2----------------|\n");
        printf("\t|------------------180 dias---------------------|\n");
        printf("\t|                                                |\n");
        printf("\t| Digite 1 para CDB 82%% do CDI                  |\n");
        printf("\t| Digite 2 para LCI 84%% do CDI                  |\n");
        printf("\t| Digite 3 para LCA 86%% do CDI                  |\n");
        printf("\t| Digite 0 para voltar ao menu anterior          |\n");
        printf("\t|________________________________________________|\n\n");
        break;

        case 3:
        printf("\n\t|--------------OPÇÃO ESCOLHIDA 3----------------|\n");
        printf("\t|--------------------1 ano----------------------|\n");
        printf("\t|                                                |\n");
        printf("\t| Digite 1 para LCI 88%% do CDI                   |\n");
        printf("\t| Digite 2 para LCA 90%% do CDI                   |\n");
        printf("\t| Digite 0 para voltar ao menu anterior          |\n");
        printf("\t|________________________________________________|\n\n");
        break;

        case 4:
        printf("\n");
        printf("\n\t|--------------OPÇÃO ESCOLHIDA 4----------------|\n");
        printf("\t|--------------------2 ano----------------------|\n");
        printf("\t|                                                |\n");
        printf("\t| Digite 1 para LCI 92%% do CDI                  |\n");
        printf("\t| Digite 2 para LCA 94%% do CDI                  |\n");
        printf("\t| Digite 0 para voltar ao menu anterior          |\n");
        printf("\t|________________________________________________|\n\n");
        break;

        case 5:
        printf("\n\t|--------------OPÇÃO ESCOLHIDA 5----------------|\n");
        printf("\t|--------------------3 anos----------------------|\n");
        printf("\t|                                                |\n");
        printf("\t| Digite 1 para LCI 4,66%% + IPCA                |\n");
        printf("\t| Digite 2 para LCI 4,69%% + IGP-M               |\n");
        printf("\t| Digite 0 para voltar ao menu anterior          |\n");
        printf("\t|________________________________________________|\n\n");
        break;

        case 6:
        printf("\n\t|--------------OPÇÃO ESCOLHIDA 6----------------|\n");
        printf("\t|--------------------4 anos---------------------|\n");
        printf("\t|                                                |\n");
        printf("\t| Digite 1 para LCA 5,14%% + IPCA                |\n");
        printf("\t| Digite 2 para LCA 5,20%% + IGP-M               |\n");
        printf("\t| Digite 0 para voltar ao menu anterior          |\n");
        printf("\t|________________________________________________|\n\n");
        break;

        case 7:
        printf("\n\t|--------------OPÇÃO ESCOLHIDA 7----------------|\n");
        printf("\t|--------------------5 anos----------------------|\n");
        printf("\t|                                                |\n");
        printf("\t| Digite 1 para LCA 5,25%% + IPCA                |\n");
        printf("\t| Digite 2 para LCI 5,27%% + IPCA                |\n");
        printf("\t| Digite 3 para LCA 5,30%% + IGP-M               |\n");
        printf("\t| Digite 5 para LCI 5,32%% + IGP-M               |\n");
        printf("\t| Digite 0 para voltar ao menu anterior          |\n");
        printf("\t|________________________________________________|\n\n");

    }


    printf ("\n\n\tO valor de retorno da aplicação previsto é: \n\n", rtin);
}




