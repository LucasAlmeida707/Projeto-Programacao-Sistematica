#define P_DESENVOLVEDORES_SERVIDOR
#include "P-Desenvolvedores.h"
#include "Codigos.h"

/**
Fun��o respons�vel por cadastrar novos desenvolvedores. Recebe como par�metro o endere�o de uma struct previamente declarada (em P-Desenvolvedores.h)
e retorna o resultado da opera��o (Resultados definidos em Codigos.h).
*/

int cadastrar_desenvolvedor(Desenvolvedor *desenvolvedor)
    {
    FILE *arquivo;
    char espaco_em_uso;
    int i;

    arquivo=fopen("Desenvolvedores.txt", "r+"); //!Abertura do arquivo de forma a ser poss�vel a leitura e escrita em um arquivo existente;
    if (arquivo==NULL) //!Testa a abertura do arquivo;
        {
        fclose(arquivo);
        return ERRO_BD;
        }

    //!Completando as strings com espa�os vazios at� o seu tamanho m�ximo;

    for (i=strlen(desenvolvedor->espaco_em_uso); i<2; i++)
        {
        desenvolvedor->espaco_em_uso[i]=' ';
        }
    for (i=strlen(desenvolvedor->nome); i<16; i++)
        {
        desenvolvedor->nome[i]=' ';
        }
    for (i=strlen(desenvolvedor->senha); i<5; i++)
        {
        desenvolvedor->senha[i]=' ';
        }
    for (i=strlen(desenvolvedor->email); i<21; i++)
        {
        desenvolvedor->email[i]=' ';
        }
    for (i=strlen(desenvolvedor->lider_projeto); i<2; i++)
        {
        desenvolvedor->lider_projeto[i]=' ';
        }

    while(!feof(arquivo)) //!Enquanto n�o for o fim do arquivo, continua a busca;
        {
        fscanf(arquivo, "%c", &espaco_em_uso);
        if (espaco_em_uso==0) //!Se o caracter lido for 0 (zero), significa que o espa�o n�o est� sendo utilizado e seu conte�do ser� sobreescrito;
            {
            //!Fun��es para a escrita no arquivo;
            fputs(desenvolvedor->espaco_em_uso, arquivo);
            fputs(desenvolvedor->nome, arquivo);
            fputs(desenvolvedor->email, arquivo);
            fputs(desenvolvedor->senha, arquivo);
            fputs(desenvolvedor->lider_projeto, arquivo);
            fclose(arquivo);
            return SUCESSO;
            }
        else //!Se o caracter lido for 1 (um), significa que o espa�o est� sendo utilizado; Passa-se para o pr�ximo bloco;
            {
            fseek(arquivo, sizeof(Desenvolvedor), SEEK_CUR);
            }
        }
    if (feof(arquivo)) //!Se chegou ao fim do arquivo sem encontrar espa�os vazios, escreve um novo bloco;
        {
        fputs(desenvolvedor->espaco_em_uso, arquivo);
        fputs(desenvolvedor->nome, arquivo);
        fputs(desenvolvedor->email, arquivo);
        fputs(desenvolvedor->senha, arquivo);
        fputs(desenvolvedor->lider_projeto, arquivo);
        }
    fclose(arquivo);
    return SUCESSO;
    }

/**
Fun��o respons�vel por remover desenvolvedores do banco de dados. Recebe como par�metro o email do desenvolvedor e retorna o resultado da opera��o
(Resultados definidos em Codigos.h).
*/

int remover_desenvolvedor(char* email)
    {
    FILE *arquivo;
    char email_comparacao[21];
    int i=1; //!Vari�vel a ser utilizada para percorrer o arquivo (como um multiplicador para a fun��o fseek);

    arquivo=fopen("Desenvolvedores.txt", "r+"); //!Abertura do arquivo de forma a ser poss�vel a leitura e escrita em um arquivo existente;
    if (arquivo==NULL) //!Testa a abertura do arquivo;
        {
        fclose(arquivo);
        return ERRO_BD;
        }

    fseek(arquivo, 22*sizeof(char), SEEK_CUR); //!Avan�a para a posi��o do registro em que se encontra o email;
    while (!feof(arquivo))
        {
        fgets(email_comparacao, sizeof(email), arquivo);
        if(!strcmp(email, email_comparacao)) //!Se a compara��o entre as duas strings for positiva (retorno 0) o condicional ser� iniciado;
            {
            rewind(arquivo);
            fseek(arquivo, i*sizeof(Desenvolvedor), SEEK_CUR);
            fprintf(arquivo, "%c", "0");
            }
        else //!Se a compara��o entre as duas strings for negativa, avan�a-se para o pr�ximo registro e incrementa-se o supracitado multiplicador;
            {
            fseek(arquivo, sizeof(Desenvolvedor), SEEK_CUR);
            i++;
            }
        }
    fclose(arquivo);
    return SUCESSO;
    }

/**
Fun��o respons�vel por editar os dados de um desenvolvedor previamente cadastrado. Recebe como par�metro o endere�o de uma struct previamente declarada (em P-Desenvolvedores.h)
contendo os dados a serem modificados e retorna o resultado da opera��o (Resultados definidos em Codigos.h).
*/

int editar_desenvolvedor(Desenvolvedor *desenvolvedor)
    {
    FILE *arquivo;
    char email_comparacao[20];
    int i=1; //!Vari�vel a ser utilizada para percorrer o arquivo (como um multiplicador para a fun��o fseek);

    arquivo=fopen("Desenvolvedores.txt", "r+"); //!Abertura do arquivo de forma a ser poss�vel a leitura e escrita em um arquivo existente;
    if (arquivo==NULL) //!Testa a abertura do arquivo;
        {
        fclose(arquivo);
        return ERRO_BD;
        }

    fseek(arquivo, 22*sizeof(char), SEEK_CUR); //!Avan�a para a posi��o do registro em que se encontra o email;
    while (!feof(arquivo))
        {
        fgets(email_comparacao, sizeof(desenvolvedor->email), arquivo);
        if(!strcmp(desenvolvedor->email, email_comparacao)) //!Se a compara��o entre as duas strings for positiva (retorno 0) o condicional ser� iniciado;
            {
            rewind(arquivo);
            fseek(arquivo, i*sizeof(Desenvolvedor), SEEK_CUR);
            fputs(desenvolvedor->espaco_em_uso, arquivo);
            fputs(desenvolvedor->nome, arquivo);
            fputs(desenvolvedor->email, arquivo);
            fputs(desenvolvedor->senha, arquivo);
            fputs(desenvolvedor->lider_projeto, arquivo);
            }
        else //!Se a compara��o entre as duas strings for negativa, avan�a-se para o pr�ximo registro e incrementa-se o supracitado multiplicador;
            {
            fseek(arquivo, sizeof(Desenvolvedor), SEEK_CUR);
            i++;
            }
        }
    fclose(arquivo);
    return SUCESSO;
    }


/**
Fun��o respons�vel por pesquisar por dados de desenvolvedores. Recebe como par�metro o endere�o de uma struct previamente declarada (em P-Desenvolvedores.h)
e retorna o resultado da opera��o (Resultados definidos em Codigos.h).
*/

int pesquisar_desenvolvedor(Desenvolvedor *desenvolvedor)
    {
    FILE *arquivo;
    char email_comparacao[20];
    int i=1; //!Vari�vel a ser utilizada para percorrer o arquivo (como um multiplicador para a fun��o fseek);

    arquivo=fopen("Desenvolvedores.txt", "r+"); //!Abertura do arquivo de forma a ser poss�vel a leitura e escrita em um arquivo existente;
    if (arquivo==NULL) //!Testa a abertura do arquivo;
        {
        fclose(arquivo);
        return ERRO_BD;
        }

    fseek(arquivo, 22*sizeof(char), SEEK_CUR); //!Avan�a para a posi��o do registro em que se encontra o email;
    while (!feof(arquivo))
        {
        fgets(email_comparacao, sizeof(desenvolvedor->email), arquivo);
        if(!strcmp(desenvolvedor->email, email_comparacao)) //!Se a compara��o entre as duas strings for positiva (retorno 0) o condicional ser� iniciado;
            {
            rewind(arquivo);
            fseek(arquivo, i*sizeof(Desenvolvedor), SEEK_CUR);
            fgets(desenvolvedor->espaco_em_uso, sizeof(desenvolvedor->espaco_em_uso), arquivo);
            fgets(desenvolvedor->nome, sizeof(desenvolvedor->nome), arquivo);
            fgets(desenvolvedor->senha, sizeof(desenvolvedor->senha), arquivo);
            fgets(desenvolvedor->email, sizeof(desenvolvedor->email), arquivo);
            fgets(desenvolvedor->lider_projeto, sizeof(desenvolvedor->lider_projeto), arquivo);
            fclose(arquivo);
            return SUCESSO;
            }
        else //!Se a compara��o entre as duas strings for negativa, avan�a-se para o pr�ximo registro e incrementa-se o supracitado multiplicador;
            {
            fseek(arquivo, sizeof(Desenvolvedor), SEEK_CUR);
            i++;
            }
        }
    fclose(arquivo);
    return REGISTRO_NAO_CADASTRADO;
    }
