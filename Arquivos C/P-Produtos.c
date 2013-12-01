#define P_PRODUTOS_SERVIDOR
#include "P-Produtos.h"
#include "Codigos.h"

/**
Fun��o respons�vel por cadastrar novos produtos. Recebe como par�metro o endere�o de uma struct previamente declarada (em P-Produtos.h)
e retorna o resultado da opera��o (Resultados definidos em Codigos.h).
*/

int cadastrar_produto(Produto *produto)
    {
    FILE *arquivo;
    char espaco_em_uso;

    arquivo=fopen("Produtos.txt", "r+"); //!Abertura do arquivo de forma a ser poss�vel a leitura e escrita em um arquivo existente;
    if (arquivo==NULL) //!Testa a abertura do arquivo;
        {
        fclose(arquivo);
        return ERRO_BD;
        }

    for (i=strlen(produto->espaco_em_uso); i<2; i++)
        {
        produto->espaco_em_uso[i]=' ';
        }
    for (i=strlen(produto->nome); i<16; i++)
        {
        produto->nome[i]=' ';
        }
    for (i=strlen(produto->codigo); i<5; i++)
        {
        produto->codigo[i]=' ';
        }
    for (i=strlen(produto->versao); i<6; i++)
        {
        produto->versao[i]=' ';
        }
    for (i=strlen(produto->lider); i<2; i++)
        {
        produto->lider[i]=' ';
        }

    while(!feof(arquivo)) //!Enquanto n�o for o fim do arquivo, continua a busca;
        {
        fscanf(arquivo, "%c", &espaco_em_uso);
        if (espaco_em_uso==0) //!Se o caracter lido for 0 (zero), significa que o espa�o n�o est� sendo utilizado e seu conte�do ser� sobreescrito;
            {
            //!Fun��es para a escrita no arquivo;
            fputs(produto->espaco_em_uso, arquivo);
            fprintf(arquivo, "%i", produto->projeto);
            fputs(produto->nome, arquivo);
            fputs(produto->codigo, arquivo);
            fputs(produto->versao, arquivo);
            fputs(produto->lider, arquivo);
            fclose(arquivo);
            return SUCESSO;
            }
        else //!Se o caracter lido for 1 (um), significa que o espa�o est� sendo utilizado; Passa-se para o pr�ximo bloco;
            {
            fseek(arquivo, sizeof(Produto), SEEK_CUR);
            }
        }
    if (feof(arquivo)) //!Se chegou ao fim do arquivo sem encontrar espa�os vazios, escreve um novo bloco;
        {
        fputs(produto->espaco_em_uso, arquivo);
        fprintf(arquivo, "%i", produto->projeto);
        fputs(produto->nome, arquivo);
        fputs(produto->codigo, arquivo);
        fputs(produto->versao, arquivo);
        fputs(produto->lider, arquivo);
        }
    fclose(arquivo);
    return SUCESSO;
    }

/**
Fun��o respons�vel por remover produtos do banco de dados. Recebe como par�metro o codigo do produto e retorna o resultado da opera��o
(Resultados definidos em Codigos.h).
*/

int remover_produto(int codigo)
    {
    FILE *arquivo;
    int codigo_comparacao;
    int i=1; //!Vari�vel a ser utilizada para percorrer o arquivo (como um multiplicador para a fun��o fseek);

    arquivo=fopen("Produtos.txt", "r+"); //!Abertura do arquivo de forma a ser poss�vel a leitura e escrita em um arquivo existente;
    if (arquivo==NULL) //!Testa a abertura do arquivo;
        {
        fclose(arquivo);
        return ERRO_BD;
        }

    fseek(arquivo, 22*sizeof(char), SEEK_CUR); //!Avan�a para a posi��o do registro em que se encontra o c�digo;
    while (!feof(arquivo))
        {
        fscanf(arquivo, "%i", codigo_comparacao);
        if(codigo==codigo_comparacao) //!Se a compara��o entre os dois c�digos for positiva o condicional ser� iniciado;
            {
            rewind(arquivo);
            fseek(arquivo, i*sizeof(Produto), SEEK_CUR);
            fprintf(arquivo, "%c", "0");
            }
        else //!Se a compara��o entre os dois c�digos for negativa, avan�a-se para o pr�ximo registro e incrementa-se o supracitado multiplicador;
            {
            fseek(arquivo, sizeof(Produto), SEEK_CUR);
            i++;
            }
        }
    fclose(arquivo);
    return SUCESSO;
    }

/**
Fun��o respons�vel por editar os dados de um produto previamente cadastrado. Recebe como par�metro o endere�o de uma struct previamente declarada (em P-Produtos.h)
contendo os dados a serem modificados e retorna o resultado da opera��o (Resultados definidos em Codigos.h).
*/

int editar_produto(Produto *produto)
    {
    FILE *arquivo;
    int codigo_comparacao;
    int i=1; //!Vari�vel a ser utilizada para percorrer o arquivo (como um multiplicador para a fun��o fseek);

    arquivo=fopen("Produtos.txt", "r+"); //!Abertura do arquivo de forma a ser poss�vel a leitura e escrita em um arquivo existente;
    if (arquivo==NULL) //!Testa a abertura do arquivo;
        {
        fclose(arquivo);
        return ERRO_BD;
        }

    fseek(arquivo, 22*sizeof(char), SEEK_CUR); //!Avan�a para a posi��o do registro em que se encontra o c�digo;
    while (!feof(arquivo))
        {
        fscanf(arquivo, "%i", codigo_comparacao);
        if(codigo==codigo_comparacao) //!Se a compara��o entre os dois c�digos for positiva o condicional ser� iniciado;
            {
            rewind(arquivo);
            fseek(arquivo, i*sizeof(Produto), SEEK_CUR);
            fputs(produto->espaco_em_uso, arquivo);
            fprintf(arquivo, "%i", produto->projeto);
            fputs(produto->nome, arquivo);
            fputs(produto->codigo, arquivo);
            fputs(produto->versao, arquivo);
            fputs(produto->lider, arquivo);
            }
        else //!Se a compara��o entre os dois c�digos for negativa, avan�a-se para o pr�ximo registro e incrementa-se o supracitado multiplicador;
            {
            fseek(arquivo, sizeof(Produto), SEEK_CUR);
            i++;
            }
        }
    fclose(arquivo);
    return SUCESSO;
    }


/**
Fun��o respons�vel por pesquisar por dados de produtos. Recebe como par�metro o endere�o de uma struct previamente declarada (em P-Produtos.h)
e retorna o resultado da opera��o (Resultados definidos em Codigos.h).
*/

int pesquisar_produto(Produto *produto)
    {
    FILE *arquivo;
    int codigo_comparacao;
    int i=1; //!Vari�vel a ser utilizada para percorrer o arquivo (como um multiplicador para a fun��o fseek);

    arquivo=fopen("Produtos.txt", "r+"); //!Abertura do arquivo de forma a ser poss�vel a leitura e escrita em um arquivo existente;
    if (arquivo==NULL) //!Testa a abertura do arquivo;
        {
        fclose(arquivo);
        return ERRO_BD;
        }

    fseek(arquivo, 22*sizeof(char), SEEK_CUR); //!Avan�a para a posi��o do registro em que se encontra o c�digo;
    while (!feof(arquivo))
        {
        fscanf(arquivo, "%i", codigo_comparacao);
        if(codigo==codigo_comparacao) //!Se a compara��o entre os dois c�digos for positiva o condicional ser� iniciado;
            {
            rewind(arquivo);
            fseek(arquivo, i*sizeof(Produto), SEEK_CUR);
            fgets(produto->espaco_em_uso, sizeof(produto->espaco_em_uso), arquivo);
            fscanf(arquivo, "%i", produto->projeto);
            fgets(produto->nome, sizeof(produto->nome), arquivo);
            fgets(produto->codigo, sizeof(produto->codigo), arquivo);
            fgets(produto->versao, sizeof(produto->versao), arquivo);
            fgets(produto->lider, sizeof(produto->lider), arquivo);
            }
        else //!Se a compara��o entre os dois c�digos for negativa, avan�a-se para o pr�ximo registro e incrementa-se o supracitado multiplicador;
            {
            fseek(arquivo, sizeof(Produto), SEEK_CUR);
            i++;
            }
        }
    fclose(arquivo);
    return SUCESSO;
    }
