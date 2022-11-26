#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <conio.h> //biblioeteca para a funçao getch() https://stackoverflow.com/questions/29612201/implicit-declaration-of-function-getch
#include <string.h>

#define TAM 100

//DECLARACAO DE FUNCOES
//void menuListagens(referencia, totalReferencias);
//void menuEstatisticas(referencia, totalReferencias);

typedef struct autor
{
    char nome_proprio[TAM];
    char apelido[TAM];
}AUTOR;

typedef struct referencia
{
    char nome_publicacao[TAM];
    char tipo_publicacao[TAM];
    AUTOR autor[TAM];
    int ano_publicacao;
    char local_publicacao[TAM];
    int num_paginas;
    char endereco_http[TAM];
    char palavra_chave[TAM];
}REFERENCIA;

int inserirReferencias(REFERENCIA referencia[], int totalReferencias){

    system("cls");

    printf("Insere o nome da publicacao: ");
    fflush(stdin);
    fgets(referencia[totalReferencias].nome_publicacao, TAM, stdin);

    printf("Insere o tipo da publicacao: ");
    fflush(stdin);
    fgets(referencia[totalReferencias].tipo_publicacao, TAM, stdin);

    printf("Insere o nome proprio do autor: ");
    fflush(stdin);
    scanf("%s", referencia[totalReferencias].autor->nome_proprio);

    printf("Insere o apelido do autor: ");
    fflush(stdin);
    scanf("%s", referencia[totalReferencias].autor->apelido);

    do
    {
        printf("Insere o ano da publicacao: ");
        fflush(stdin);
        scanf("%i", &referencia[totalReferencias].ano_publicacao);

        if (referencia[totalReferencias].ano_publicacao < 0)
        {
            printf("Ano da Publicacao inserido e Invalido\n");
        }
    } while (referencia[totalReferencias].ano_publicacao < 0);

    printf("Insere o local da publicacao: ");
    fflush(stdin);
    fgets(referencia[totalReferencias].local_publicacao, TAM, stdin);

    do
    {
        printf("Insere o numero de paginas da publicacao: ");
        fflush(stdin);
        scanf("%i", &referencia[totalReferencias].num_paginas);

        if (referencia[totalReferencias].num_paginas < 0)
        {
            printf("Numero de Paginas inserido e Invalido\n");
        }
        
    } while (referencia[totalReferencias].num_paginas < 0);

    printf("Insere o endereco HTTP: ");
    fflush(stdin);
    scanf("%s", referencia[totalReferencias].endereco_http);

    printf("Insere a/outra palavra-chave: ");
    fflush(stdin);
    scanf("%s", referencia[totalReferencias].palavra_chave);
    //for para a qqtd de palavras-chave que quer isnerir.

    return totalReferencias+1;
}

void mostrarReferencias(REFERENCIA referencia[], int totalReferencias){

    system("cls");

    printf("\n############################################################\n");
    printf("\t\tReferencias Bibliograficas");
    printf("\n############################################################\n");

    //printf("|Indice da Referencia|\t|Nome da Publicacao|\t|Tipo da Publicacao|\t|Nome proprio do Autor|\t|Apelido do Autor|\t|Ano da Publicacao|\t|Local da Publicacao|\t|Num de Paginas da Publicacao|\t|Endereco HTTP|\t|Palavra(s)-Chave|");

    for (int i = 0; i < totalReferencias; i++)
    {
        printf("Indice da Referencia: %i\n", i);
        printf("Nome da Publicacao: %s", referencia[i].nome_publicacao);
        printf("Tipo da Publicacao: %s", referencia[i].tipo_publicacao);
        printf("Nome do Autor: %s\n", referencia[i].autor->nome_proprio);
        printf("Apelido do Autor: %s\n", referencia[i].autor->apelido);
        printf("Ano da Publicacao: %i\n", referencia[i].ano_publicacao);
        printf("Local da Publicacao: %s", referencia[i].local_publicacao);
        printf("Numero de Paginas: %i\n", referencia[i].num_paginas);
        printf("Endereco HTTP: %s\n", referencia[i].endereco_http);
        printf("Palavra(s)-Chave: %s\n", referencia[i].palavra_chave);
        printf("############################################################\n");
        //printf("\n | %i | | %s | | %s | | %s | | %s | | %i | | %s | | %i | | %s | | %s |", i, referencia[i].nome_publicacao, referencia[i].tipo_publicacao, referencia[i].autor->nome_proprio, referencia[i].autor->apelido, referencia[i].ano_publicacao, referencia[i].local_publicacao, referencia[i].num_paginas, referencia[i].endereco_http, referencia[i].palavra_chave);
    }

    printf("\n------------------------------------------------------------\n");
    printf("Total de Referencias: %i\n", totalReferencias);
}

void escolherSeContinuaAlterarOuNao(REFERENCIA referencia[], int totalReferencias){
    int escolha;

    printf("\n\t 1. Ainda queres fazer mais alteracoes, em alguma refenrecia.");
    printf("\n\t 2. Queres voltar para o Menu Referencias, ou seja, o menu principal.");

    printf("\n\n\t Escolhe o que pretendes realizar: ");
    scanf("%i", &escolha);

    switch (escolha)
    {
        case 1:
            alterarReferencias(referencia, totalReferencias);
            break;
        case 2:
            menuReferencias(referencia, totalReferencias);
            break;
        default:
            printf("\n\t Opcao invalida!!! Por favor insira uma das opcoes indicadas!!!");
            escolherSeContinuaAlterarOuNao(referencia, totalReferencias);
            break;
    }
}

void alterarReferencias(REFERENCIA referencia[], int totalReferencias){
    int indice;
    int escolha;

    system("cls");

    printf("Insere o indice da Referencia que pretendes alterar: ");
    scanf("%i", &indice);

    for (int i = 0; i < totalReferencias; i++)
    {
        if (indice >= 0 && indice < totalReferencias) 
        {
            if (indice == i)
            {
                printf("\n\t 1. Nome da Publicacao");
                printf("\n\t 2. Tipo da Publicacao");
                printf("\n\t 3. Nome Proprio do Autor");
                printf("\n\t 4. Apelido do Autor");
                printf("\n\t 5. Ano da Publicacao");
                printf("\n\t 6. Local da Publicacao");
                printf("\n\t 7. Numero de Paginas");
                printf("\n\t 8. Endereco HTTP");
                printf("\n\t 9. Palavra(s)-Chave");

                printf("\n\n\t Escolhe o que pretendes alterar: ");
                scanf("%i", &escolha);

                switch (escolha)
                {
                case 1:
                    printf("\n\t Insere o Novo nome da publicacao: ");
                    fflush(stdin);
                    fgets(referencia[i].nome_publicacao, TAM, stdin);
                    getch();
                    escolherSeContinuaAlterarOuNao(referencia, totalReferencias);
                    break;
                case 2:
                    printf("\n\t Insere o Novo tipo da publicacao: ");
                    fflush(stdin);
                    fgets(referencia[i].tipo_publicacao, TAM, stdin);
                    getch();
                    escolherSeContinuaAlterarOuNao(referencia, totalReferencias);
                    break;
                case 3:
                    printf("\n\t Insere o Novo nome proprio do autor: ");
                    fflush(stdin);
                    scanf("%s", referencia[i].autor->nome_proprio);
                    getch();
                    escolherSeContinuaAlterarOuNao(referencia, totalReferencias);
                    break;
                case 4:
                    printf("\n\t Insere o Novo apelido do autor: ");
                    fflush(stdin);
                    scanf("%s", referencia[i].autor->apelido);
                    getch();
                    escolherSeContinuaAlterarOuNao(referencia, totalReferencias);
                    break;
                case 5:
                    do
                    {
                        printf("\n\t Insere o Novo ano da publicacao: ");
                        fflush(stdin);
                        scanf("%i", &referencia[i].ano_publicacao);

                        if (referencia[i].ano_publicacao < 0)
                        {
                            printf("Ano da Publicacao inserido e Invalido\n");
                        }
                        
                    } while (referencia[i].ano_publicacao < 0);
                    
                    getch();
                    escolherSeContinuaAlterarOuNao(referencia, totalReferencias);
                    break;
                case 6:
                    printf("\n\t Insere o Novo local da publicacao: ");
                    fflush(stdin);
                    fgets(referencia[i].local_publicacao, TAM, stdin);
                    getch();
                    escolherSeContinuaAlterarOuNao(referencia, totalReferencias);
                    break;
                case 7:
                    do
                    {
                        printf("\n\t Insere o Novo numero de paginas da publicacao: ");
                        fflush(stdin);
                        scanf("%i", &referencia[i].num_paginas);

                        if (referencia[i].num_paginas < 0)
                        {
                            printf("Numero de Paginas inserido e Invalido\n");
                        }
                        
                    } while (referencia[i].num_paginas < 0);
                    
                    getch();
                    escolherSeContinuaAlterarOuNao(referencia, totalReferencias);
                    break;
                case 8:
                    printf("\n\t Insere o Novo endereco HTTP: ");
                    fflush(stdin);
                    scanf("%s", referencia[i].endereco_http);
                    getch();
                    escolherSeContinuaAlterarOuNao(referencia, totalReferencias);
                    break;
                case 9:
                    printf("\n\t Insere a/outra Nova palavra-chave: ");
                    fflush(stdin);
                    scanf("%s", referencia[i].palavra_chave);
                    getch();
                    escolherSeContinuaAlterarOuNao(referencia, totalReferencias);
                    break;
                default:
                    printf("\n\t Opcao invalida!!! Por favor insira uma das opcoes indicadas!!!");
                    alterarReferencias(referencia, totalReferencias);
                    break;
                }
            }
        }
        else
        {
            system("cls");
            printf("\n\tNao existe Referencia com este numero.");
        }
    }
}

int eliminarReferencias(REFERENCIA referencia[], int totalReferencias){
    int indice;

    system("cls");

    printf("Insere o indice da Referencia que pretendes apagar: ");
    scanf("%i", &indice);

    for (int i = 0; i < totalReferencias; i++)
    {
        if (indice >= 0 && indice < totalReferencias) 
        {
            if (indice == i)
            {
                referencia[i] = referencia[i+1];
                totalReferencias--;
            }
        }
        else
        {
            system("cls");
            printf("\n\t Nao existe Referencia com este numero.");
        }
        
    }

    return totalReferencias;
}

//FUNCOES DE LISTAR
void listarAutoresSemRepetidos(REFERENCIA referencia[], int totalReferencias){
    char nome_proprio_aux[TAM];
    char apelido_aux[TAM];
    int res_nome, res_apelido;

    printf("Os Autores que existem sao: ");

    for (int i = 0; i < totalReferencias; i++)
    {
        strcpy(nome_proprio_aux, referencia[i].autor->nome_proprio);
        printf("Nome proprio AUX: %s\n", nome_proprio_aux);
        //strcpy(apelido_aux, referencia[i].autor->apelido);
        //printf("Apelido AUX: %s\n", apelido_aux);
        //nome_proprio_aux = referencia[i].autor->nome_proprio;
        //apelido_aux = referencia[i].autor->apelido;

        res_nome = strcmp(nome_proprio_aux, referencia[i].autor->nome_proprio);
        printf("%i", res_nome);
        //res_apelido = strcmp(apelido_aux, referencia[i].autor->apelido);
        //printf("%i", &res_apelido);

        //if (nome_proprio_aux != referencia[i].autor->nome_proprio || apelido_aux != referencia[i].autor->apelido)
        if (res_nome != 0) //|| res_apelido != 0
        {
            printf("erro 2\n");
            //printf("Nome Proprio: %s Apelido: %s, do Autor", referencia[i].autor->nome_proprio, referencia[i].autor->apelido);
            printf("Nome Proprio: %s, do Autor", referencia[i].autor->nome_proprio);
        }
        
    }
    
}

void listarPublicacoesAutor(){}
void listarPublicacoesTipo(){}
void listarPublicacoesPalavraChave(){}
void listarPublicacoesAno(){}
void listarTodasPalavrasChaveSemRepetidas(){}

//MOSTRAR ALGUMAS ESTATISTICAS
void totalPublicacoesSemRepetidos(){}
void totalAutoresSemRepetidos(){}
void totalPalavrasChaveSemRepetidos(){}
void totalPaginas(){}
void mediaPaginaPorPublicacao(){}

//MENUS

//MENU PRINCIPAL, OU SEJA, MENU DAS REFERENCIAS BIBLIOGRAFICAS
void menuReferencias(REFERENCIA referencia[], int totalReferencias){
    //system("cls");
    int escolha;

    printf("******Gestao De Referencias Bibliograficas******\n");
    printf("\n\t 1. Insercao");
    printf("\n\t 2. Mostar/Procura");
    printf("\n\t 3. Alteracao");
    printf("\n\t 4. Remocao");
    printf("\n\t 5. Menu de Listagens/Procuras");
    printf("\n\t 6. Menu de Estatisticas");
    printf("\n\t 7. Sair do menu\n\n");
    printf("************************************************\n");

    printf("Por favor escolha a opção que pretende realizar: ");
    scanf("%i", &escolha);

    switch (escolha)
    {
    case 1:
        totalReferencias = inserirReferencias(referencia, totalReferencias);
        getch();//espera que seja inserido uma tecla
        system("cls");
        printf("\n\t Vai voltar para o menu Referencias, ou seja, o menu principal!!!");
        getch();
        menuReferencias(referencia, totalReferencias);
        break;
    case 2:
        mostrarReferencias(referencia, totalReferencias);
        getch();//espera que seja inserido uma tecla
        system("cls");
        printf("\n\t Vai voltar para o menu Referencias, ou seja, o menu principal!!!");
        getch();
        menuReferencias(referencia, totalReferencias);
        break;
    case 3:
        alterarReferencias(referencia, totalReferencias);
        getch(); //espera que seja inserido uma tecla
        system("cls");
        printf("\n\t Vai voltar para o menu Referencias, ou seja, o menu principal!!!");
        getch();
        menuReferencias(referencia, totalReferencias);
        break;
    case 4:
        totalReferencias = eliminarReferencias(referencia, totalReferencias);
        getch(); //espera que seja inserido uma tecla
        system("cls");
        printf("\n\t Vai voltar para o menu Referencias, ou seja, o menu principal!!!");
        getch();
        menuReferencias(referencia, totalReferencias);
        break;
    case 5:
        menuListagens(referencia, totalReferencias);
        getch();//espera que seja inserido uma tecla
        break;
    case 6:
        menuEstatisticas(referencia, totalReferencias);
        getch();//espera que seja inserido uma tecla
        break;
    case 7:
        system("cls");
        printf("\n\t O programa vai encerrar!!!");
        getch();//espera que seja inserido uma tecla
        exit(1);
        break;
    default:
        printf("\n\t Opcao invalida!!! Por favor insira uma das opcoes indicadas!!");
        break;
    }
}

//MENU DE LISTAGENS
void menuListagens(REFERENCIA referencia[], int totalReferencias){
    system("cls");
    int escolha;

    printf("**********************************Menu De Listas***************************************************\n");
    printf("\n\t 1. Listar Autores sem mostrar repetidos");
    printf("\n\t 2. Listar todas as publicacoes de um autor, dado o nome completo ou so pelo Apelido");
    printf("\n\t 3. Listar todas as publicacoes de um certo tipo");
    printf("\n\t 4. Listar todas as publicacoes que contenham uma ou mais combinacao de palavras-chave");
    printf("\n\t 5. Listar todas as publicacoes de um certo ano");
    printf("\n\t 6. Listar todas as palavra-chave sem mostrar repetidas");
    printf("\n\t 7. Voltar para o menu Referencias(menu Principal)");
    printf("\n***************************************************************************************************\n");

    printf("Por favor escolha a opção que pretende realizar: ");
    scanf("%i", &escolha);

    switch (escolha)
    {
    case 1:
        listarAutoresSemRepetidos(referencia, totalReferencias);
        getch();//espera que seja inserido uma tecla
        printf("\n\t Vai voltar para o menu de Listas, ou seja, o menu anterior!!!");
        getch();
        menuListagens(referencia, totalReferencias);
        break;
    case 2:
        getch();//espera que seja inserido uma tecla
        break;
    case 3:
        getch();//espera que seja inserido uma tecla
        break;
    case 4:
        getch();//espera que seja inserido uma tecla
        break;
    case 5:
        getch();//espera que seja inserido uma tecla
        break;
    case 6:
        getch();//espera que seja inserido uma tecla
        break;
    case 7:
        system("cls");
        printf("\n\t Vai voltar para o menu Referencias, ou seja, o menu principal!!!");
        getch();//espera que seja inserido uma tecla
        menuReferencias(referencia, totalReferencias);
        break;
    default:
        printf("\n\t Opcao invalida!!! Por favor insira uma das opcoes indicadas!!");
        break;
    }
}

//MENU DE ESTATISTICAS
void menuEstatisticas(REFERENCIA referencia[], int totalReferencias){
    system("cls");
    int escolha;

    printf("*****************Menu De Estatisticas*****************\n");
    printf("\n\t 1. Total de Publicacoes sem repetidos.");
    printf("\n\t 2. Total de autores sem repetidos.");
    printf("\n\t 3. Total de palavras-chave sem repetidos.");
    printf("\n\t 4. Total de paginas.");
    printf("\n\t 5. Media de paginas por publicacao.");
    printf("\n\t 6. Voltar para o menu Referencias(menu Principal)");
    printf("******************************************************\n");

    printf("Por favor escolha a opção que pretende realizar: ");
    scanf("%i", &escolha);

    switch (escolha)
    {
    case 1:
        getch();//espera que seja inserido uma tecla
        break;
    case 2:
        getch();//espera que seja inserido uma tecla
        break;
    case 3:
        getch();//espera que seja inserido uma tecla
        break;
    case 4:
        getch();//espera que seja inserido uma tecla
        break;
    case 5:
        getch();//espera que seja inserido uma tecla
        break;
    case 6:
        system("cls");
        printf("\n\t Vai voltar para o menu Referencias, ou seja, o menu principal!!!");
        getch();//espera que seja inserido uma tecla
        menuReferencias(referencia, totalReferencias);
        break;
    default:
        printf("\n\t Opcao invalida!!! Por favor insira uma das opcoes indicadas!!");
        break;
    }
}

int main(int argc, char *argv[]) {

    setlocale(LC_ALL, "Portuguese");
    //system("COLOR FC");

	// DECLARA??O DE VARI?VEIS E DE CONSTANTES
	REFERENCIA referencia[TAM];
    int totalReferencias = 0;
    
    // SEQU?NCIA L?GICA DE INSTRU??ES
    menuReferencias(referencia, totalReferencias);
    
	return 0;
}
