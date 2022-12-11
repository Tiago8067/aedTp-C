#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <conio.h>  //biblioeteca para a funçao getch() https://stackoverflow.com/questions/29612201/implicit-declaration-of-function-getch
#include <string.h>

#define TAM 100

// DECLARACAO DE FUNCOES
// void menuListagens(referencia, totalReferencias);
// void menuEstatisticas(referencia, totalReferencias);

typedef struct autor
{
    char nome_proprio[TAM];
    char apelido[TAM];
} AUTOR;

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
    int qtd_palavra_chave;
} REFERENCIA;

int confereSeIndiceExiste(REFERENCIA referencia[], int totalReferencias, int indice)
{

    for (int i = 0; i < totalReferencias; i++)
    {
        if (indice == i)
        {
            return 1;
        }
    }
    return 0;
}

int eliminarReferencias(REFERENCIA referencia[], int totalReferencias)
{
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
                referencia[i] = referencia[i + 1];
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

void alterarReferencias(REFERENCIA referencia[], int totalReferencias)
{
    int indice;
    int escolha;

    system("cls");

    printf("Insere o indice da Referencia que pretendes alterar: ");
    scanf("%i", &indice);

    if (!confereSeIndiceExiste(referencia, totalReferencias, indice))
    {
        printf("Indice nao existe\n");
        getch();
        return;
    }

    while (escolha != 0)
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
        printf("\n\t 0. Sair");

        printf("\n\n\t Escolhe o que pretendes alterar: ");
        scanf("%i", &escolha);

        switch (escolha)
        {
        case 1:
            printf("\n\t Insere o Novo nome da publicacao: ");
            fflush(stdin);
            fgets(referencia[indice].nome_publicacao, TAM, stdin);
            getch();
            break;
        case 2:
            printf("\n\t Insere o Novo tipo da publicacao: ");
            fflush(stdin);
            fgets(referencia[indice].tipo_publicacao, TAM, stdin);
            getch();
            break;
        case 3:
            printf("\n\t Insere o Novo nome proprio do autor: ");
            fflush(stdin);
            scanf("%s", referencia[indice].autor->nome_proprio);
            getch();
            break;
        case 4:
            printf("\n\t Insere o Novo apelido do autor: ");
            fflush(stdin);
            scanf("%s", referencia[indice].autor->apelido);
            getch();
            break;
        case 5:
            do
            {
                printf("\n\t Insere o Novo ano da publicacao: ");
                fflush(stdin);
                scanf("%i", &referencia[indice].ano_publicacao);

                if (referencia[indice].ano_publicacao < 0)
                {
                    printf("Ano da Publicacao inserido e Invalido\n");
                }

            } while (referencia[indice].ano_publicacao < 0);

            getch();
            break;
        case 6:
            printf("\n\t Insere o Novo local da publicacao: ");
            fflush(stdin);
            fgets(referencia[indice].local_publicacao, TAM, stdin);
            getch();
            break;
        case 7:
            do
            {
                printf("\n\t Insere o Novo numero de paginas da publicacao: ");
                fflush(stdin);
                scanf("%i", &referencia[indice].num_paginas);

                if (referencia[indice].num_paginas < 0)
                {
                    printf("Numero de Paginas inserido e Invalido\n");
                }

            } while (referencia[indice].num_paginas < 0);

            getch();
            break;
        case 8:
            printf("\n\t Insere o Novo endereco HTTP: ");
            fflush(stdin);
            scanf("%s", referencia[indice].endereco_http);
            getch();
            break;
        case 9:
            printf("\n\t Insere a/outra Nova palavra-chave: ");
            fflush(stdin);
            scanf("%s", referencia[indice].palavra_chave);
            getch();
            break;
        case 0:
            return;
        }
    }
}

int inserirReferencias(REFERENCIA referencia[], int totalReferencias)
{

    system("cls");

    //printf("Insere o nome da publicacao: ");
    //fflush(stdin);
    //fgets(referencia[totalReferencias].nome_publicacao, TAM, stdin);

    //printf("Insere o tipo da publicacao: ");
    //fflush(stdin);
    //fgets(referencia[totalReferencias].tipo_publicacao, TAM, stdin);

    //printf("Insere o nome proprio do autor: ");
    //fflush(stdin);
    //scanf("%s", referencia[totalReferencias].autor->nome_proprio);

    /*     printf("Insere o apelido do autor: ");
        fflush(stdin);
        scanf("%s", referencia[totalReferencias].autor->apelido); */

    /*do
    {
        printf("Insere o ano da publicacao: ");
        fflush(stdin);
        scanf("%i", &referencia[totalReferencias].ano_publicacao);

        if (referencia[totalReferencias].ano_publicacao < 0)
        {
            printf("Ano da Publicacao inserido e Invalido\n");
        }
    } while (referencia[totalReferencias].ano_publicacao < 0);*/

    //&& referencia[totalReferencias].ano_publicacao >2022

        //printf("Insere o local da publicacao: ");
        //fflush(stdin);
        //fgets(referencia[totalReferencias].local_publicacao, TAM, stdin);*/

       /*do
        {
            printf("Insere o numero de paginas da publicacao: ");
            fflush(stdin);
            scanf("%i", &referencia[totalReferencias].num_paginas);

            if (referencia[totalReferencias].num_paginas < 0)
            {
                printf("Numero de Paginas inserido e Invalido\n");
            }

        } while (referencia[totalReferencias].num_paginas < 0);*/

        /*printf("Insere o endereco HTTP: ");
        fflush(stdin);
        scanf("%s", referencia[totalReferencias].endereco_http);

        printf("Insere a/outra palavra-chave: ");
        fflush(stdin);
        scanf("%s", referencia[totalReferencias].palavra_chave);
        // for para a qqtd de palavras-chave que quer isnerir. */

        printf("Quantas palavras-chave deseja inserir: ");
        scanf("%i", &referencia[totalReferencias].qtd_palavra_chave);

        for (int i = 0; i < referencia[totalReferencias].qtd_palavra_chave; i++)
        {
            printf("Insere a/outra palavra-chave: ");
            fflush(stdin);
            scanf("%s", referencia[i].palavra_chave);
        }
        
    return totalReferencias + 1;
}

void mostrarReferencias(REFERENCIA referencia[], int totalReferencias)
{

    system("cls");

    printf("\n############################################################\n");
    printf("\t\tReferencias Bibliograficas");
    printf("\n############################################################\n");

    // printf("|Indice da Referencia|\t|Nome da Publicacao|\t|Tipo da Publicacao|\t|Nome proprio do Autor|\t|Apelido do Autor|\t|Ano da Publicacao|\t|Local da Publicacao|\t|Num de Paginas da Publicacao|\t|Endereco HTTP|\t|Palavra(s)-Chave|");

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
        for (int j = 0; j < referencia[i].qtd_palavra_chave; j++)
        {
            printf("Palavra(s)-Chave: %s\n", referencia[j].palavra_chave);
        }
        //printf("Palavra(s)-Chave: %s\n", referencia[i].palavra_chave);
        printf("############################################################\n");
        // printf("\n | %i | | %s | | %s | | %s | | %s | | %i | | %s | | %i | | %s | | %s |", i, referencia[i].nome_publicacao, referencia[i].tipo_publicacao, referencia[i].autor->nome_proprio, referencia[i].autor->apelido, referencia[i].ano_publicacao, referencia[i].local_publicacao, referencia[i].num_paginas, referencia[i].endereco_http, referencia[i].palavra_chave);
    }

    printf("\n------------------------------------------------------------\n");
    printf("Total de Referencias: %i\n", totalReferencias);
}

// FUNCOES DE LISTAR~
//tambem ja retorna o total de autores sem repetidos para o menu de listagens
int listarAutoresSemRepetidos(REFERENCIA referencia[], int totalReferencias, int opcao)
{
    char autores_sem_ser_repetido[TAM][TAM];
    int total_autores_sem_ser_repetido = 0;
    int autores_ja_repetido = 0;

    for (int i = 0; i < totalReferencias; i++)
    {
        if (total_autores_sem_ser_repetido == 0)
        {
            strcpy(autores_sem_ser_repetido[total_autores_sem_ser_repetido], referencia[i].autor->nome_proprio);
            total_autores_sem_ser_repetido++;
            continue;
        }

        for (int j = 0; j < total_autores_sem_ser_repetido; j++)
        {
            if (!strcmp(referencia[i].autor->nome_proprio, autores_sem_ser_repetido[j]))
            {
                autores_ja_repetido = 1;
                break;
            }
        }

        if (!autores_ja_repetido)
        {
            strcpy(autores_sem_ser_repetido[total_autores_sem_ser_repetido], referencia[i].autor->nome_proprio);
            total_autores_sem_ser_repetido++;
        }

        autores_ja_repetido = 0;
    }

    if (opcao == 1)
    {
        for (int i = 0; i < total_autores_sem_ser_repetido; i++)
        {
            //MUDAR PRINTF
            printf("Autor: %s\n", autores_sem_ser_repetido[i]);
        }
        return 0;
    }
    
    return total_autores_sem_ser_repetido;
}

void listarPublicacoesAutor() {}

void listarPublicacoesTipo(REFERENCIA referencia[], int totalReferencias) {
    char compara_tipo_pub[TAM];

    printf("Introduza o tipo de publicacoes a procurar: ");
    fflush(stdin);
    fgets(compara_tipo_pub, TAM, stdin);

    for (int i = 0; i < totalReferencias; i++)
    {
        if (strcmp(referencia[i].tipo_publicacao, compara_tipo_pub) == 0)
        {
            printf("############################################################\n");
            printf("tipo: %s", referencia[i].tipo_publicacao);
        }
        
    }
}

void listarPublicacoesPelaPalavraChave() {}

void listarPublicacoesAno(REFERENCIA referencia[], int totalReferencias) {
    int compara_ano_pub = 0;

    printf("Introduza o ano de publicacoes a procuarar: ");
    scanf("%i", &compara_ano_pub);

    for (int i = 0; i < totalReferencias; i++)
    {
        if (referencia[i].ano_publicacao == compara_ano_pub)
        {
            printf("############################################################\n");
            printf("tipo: %i", referencia[i].ano_publicacao);
        }
        
    }
}

//tambem ja retorna o total de palavra-chave sem repetidos para o menu de listagens
int listarTodasPalavrasChaveSemRepetidas(REFERENCIA referencia[], int totalReferencias, int opcao) {
    char palavra_chave_sem_ser_repetido[TAM][TAM];
    int total_palavra_chave_sem_ser_repetido = 0;
    int palavra_chave_ja_repetido = 0;

    for (int i = 0; i < totalReferencias; i++)
    {
        if (total_palavra_chave_sem_ser_repetido == 0)
        {
            strcpy(palavra_chave_sem_ser_repetido[total_palavra_chave_sem_ser_repetido], referencia[i].autor->nome_proprio);
            total_palavra_chave_sem_ser_repetido++;
            continue;
        }

        for (int j = 0; j < total_palavra_chave_sem_ser_repetido; j++)
        {
            if (!strcmp(referencia[i].autor->nome_proprio, palavra_chave_sem_ser_repetido[j]))
            {
                palavra_chave_ja_repetido = 1;
                break;
            }
        }

        if (!palavra_chave_ja_repetido)
        {
            strcpy(palavra_chave_sem_ser_repetido[total_palavra_chave_sem_ser_repetido], referencia[i].autor->nome_proprio);
            total_palavra_chave_sem_ser_repetido++;
        }

        palavra_chave_ja_repetido = 0;
    }

    if (opcao == 1)
    {
        for (int i = 0; i < total_palavra_chave_sem_ser_repetido; i++)
        {
            //MUDAR PRINTF
            printf("Palavra Chave: %s\n", palavra_chave_sem_ser_repetido[i]);
        }
        return 0;
    }
    
    return total_palavra_chave_sem_ser_repetido;
}

// MOSTRAR ALGUMAS ESTATISTICAS
void totalPublicacoesSemRepetidos() {}
void totalAutoresSemRepetidos() {}//ja esta feita na funcao de listar autores sem mostrar repetidos

void totalPalavrasChaveSemRepetidos() {}//ja esta feita na funcao de listar plavra-chave sem mostrar repetidos

int totalPaginas(REFERENCIA referencia[], int totalReferencias) {
    int totalPaginas = 0;

    for (int i = 0; i < totalReferencias; i++)
    {
        totalPaginas += referencia[i].num_paginas;
    }

    return totalPaginas;
}

float mediaPaginaPorPublicacao(REFERENCIA referencia[], int totalReferencias) {
    int totalPaginas = 0;
    float mediaPaginas = 0.0;

    for (int i = 0; i < totalReferencias; i++)
    {
        totalPaginas += referencia[i].num_paginas;
    }

    mediaPaginas = (float) totalPaginas / totalReferencias;

    return mediaPaginas;
}

// MENUS
// MENU DE LISTAGENS
void menuListagens(REFERENCIA referencia[], int totalReferencias)
{
    system("cls");
    int escolha;

    while (1)
    {
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
            listarAutoresSemRepetidos(referencia, totalReferencias, 1);
            getch(); // espera que seja inserido uma tecla
            printf("\n\t Vai voltar para o menu de Listas, ou seja, o menu anterior!!!");
            getch();
            break;
        case 2:
            getch(); // espera que seja inserido uma tecla
            break;
        case 3:
            listarPublicacoesTipo(referencia, totalReferencias);
            getch(); // espera que seja inserido uma tecla
            printf("\n\t Vai voltar para o menu de Listas, ou seja, o menu anterior!!!");
            getch();
            break;
        case 4:
            getch(); // espera que seja inserido uma tecla
            break;
        case 5:
            listarPublicacoesAno(referencia, totalReferencias);
            getch(); // espera que seja inserido uma tecla
            printf("\n\t Vai voltar para o menu de Listas, ou seja, o menu anterior!!!");
            getch();
            break;
        case 6:
            listarTodasPalavrasChaveSemRepetidas(referencia, totalReferencias, 1);
            getch(); // espera que seja inserido uma tecla
            printf("\n\t Vai voltar para o menu de Listas, ou seja, o menu anterior!!!");
            getch();
            break;
        case 7:
            system("cls");
            printf("\n\t Vai voltar para o menu Referencias, ou seja, o menu principal!!!");
            getch(); // espera que seja inserido uma tecla
            return;
        default:
            printf("\n\t Opcao invalida!!! Por favor insira uma das opcoes apresentadas!!");
            break;
        }
    }
}

// MENU DE ESTATISTICAS
void menuEstatisticas(REFERENCIA referencia[], int totalReferencias)
{
    system("cls");
    int escolha;


    while (1)
    {
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
            getch(); // espera que seja inserido uma tecla
            break;
        case 2:
            printf("O Total de autores sem ser repetido e: %i", listarAutoresSemRepetidos(referencia, totalReferencias, 0));
            getch(); // espera que seja inserido uma tecla
            printf("\n\t Vai voltar para o menu de Estatisticas, ou seja, o menu anterior!!!");
            getch();
            break;
        case 3:
            printf("O Total de palavras-chave sem ser repetido e: %i", listarTodasPalavrasChaveSemRepetidas(referencia, totalReferencias, 0));
            getch(); // espera que seja inserido uma tecla
            printf("\n\t Vai voltar para o menu de Estatisticas, ou seja, o menu anterior!!!");
            getch();
            break;
        case 4:
            printf("Existe um total de paginas de: %i", totalPaginas(referencia, totalReferencias));
            getch(); // espera que seja inserido uma tecla
            printf("\n\t Vai voltar para o menu de Estatisticas, ou seja, o menu anterior!!!");
            getch();
            break;
        case 5:
            printf("A media de paginas e: %.2f", mediaPaginaPorPublicacao(referencia, totalReferencias));
            getch(); // espera que seja inserido uma tecla
            printf("\n\t Vai voltar para o menu de Estatisticas, ou seja, o menu anterior!!!");
            getch();
            break;
        case 6:
            system("cls");
            printf("\n\t Vai voltar para o menu Referencias, ou seja, o menu principal!!!");
            getch(); // espera que seja inserido uma tecla
            return;
            break;
        default:
            printf("\n\t Opcao invalida!!! Por favor insira uma das opcoes apresentadas!!");
            break;
        }
    }
}

// MENU PRINCIPAL, OU SEJA, MENU DAS REFERENCIAS BIBLIOGRAFICAS
void menuReferencias(REFERENCIA referencia[], int totalReferencias)
{
    // system("cls");
    int escolha;

    while (1)//fica dentro do while para sempre 
    {
        printf("******Gestao De Referencias Bibliograficas******\n");
        printf("\n\t 1. Insercao");
        printf("\n\t 2. Mostar/Procura");
        printf("\n\t 3. Alteracao");
        printf("\n\t 4. Remocao");
        printf("\n\t 5. Menu de Listagens/Procuras");
        printf("\n\t 6. Menu de Estatisticas");
        printf("\n\t 7. Sair do programa\n\n");
        printf("************************************************\n");

        printf("Por favor escolha a opção que pretende realizar: ");
        scanf("%i", &escolha);

        switch (escolha)
        {
        case 1:
            totalReferencias = inserirReferencias(referencia, totalReferencias);
            getch(); // espera que seja inserido uma tecla
            system("cls");
            printf("\n\t Vai voltar para o menu Referencias, ou seja, o menu principal!!!");
            getch();
            menuReferencias(referencia, totalReferencias);
            break;
        case 2:
            mostrarReferencias(referencia, totalReferencias);
            getch(); // espera que seja inserido uma tecla
            system("cls");
            printf("\n\t Vai voltar para o menu Referencias, ou seja, o menu principal!!!");
            getch();
            menuReferencias(referencia, totalReferencias);
            break;
        case 3:
            alterarReferencias(referencia, totalReferencias);
            getch(); // espera que seja inserido uma tecla
            system("cls");
            printf("\n\t Vai voltar para o menu Referencias, ou seja, o menu principal!!!");
            getch();
            menuReferencias(referencia, totalReferencias);
            break;
        case 4:
            totalReferencias = eliminarReferencias(referencia, totalReferencias);
            getch(); // espera que seja inserido uma tecla
            system("cls");
            printf("\n\t Vai voltar para o menu Referencias, ou seja, o menu principal!!!");
            getch();
            menuReferencias(referencia, totalReferencias);
            break;
        case 5:
            menuListagens(referencia, totalReferencias);
            getch(); // espera que seja inserido uma tecla
            break;
        case 6:
            menuEstatisticas(referencia, totalReferencias);
            getch(); // espera que seja inserido uma tecla
            break;
        case 7:
            system("cls");
            printf("\n\t O programa vai encerrar!!!");
            getch(); // espera que seja inserido uma tecla
            return;
        default:
            printf("\n\t Opcao invalida!!! Por favor insira uma das opcoes apresentadas!!");
            break;
        }
    }
}

int main(int argc, char *argv[])
{

    setlocale(LC_ALL, "Portuguese");
    // system("COLOR FC");

    // DECLARA??O DE VARI?VEIS E DE CONSTANTES
    REFERENCIA referencia[TAM];
    int totalReferencias = 0;

    // SEQU?NCIA L?GICA DE INSTRU??ES
    menuReferencias(referencia, totalReferencias);

    return 0;
}