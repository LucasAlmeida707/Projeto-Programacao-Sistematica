#define P_PRODUTOS_SERVIDOR
#include "P-Produtos.h"
#include "Codigos.h"

/**
Função responsável por cadastrar novos produtos. Recebe como parâmetro o endereço de uma struct previamente declarada (em P-Produtos.h)
e retorna o resultado da operação (Resultados definidos em Codigos.h).
*/

int cadastrar_produto(Produto *produto)
    {
    FILE *arquivo;
    char espaco_em_uso;

    arquivo=fopen("Produtos.txt", "r+"); //!Abertura do arquivo de forma a ser possível a leitura e escrita em um arquivo existente;
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

    while(!feof(arquivo)) //!Enquanto não for o fim do arquivo, continua a busca;
        {
        fscanf(arquivo, "%c", &espaco_em_uso);
        if (espaco_em_uso==0) //!Se o caracter lido for 0 (zero), significa que o espaço não está sendo utilizado e seu conteúdo será sobreescrito;
            {
            //!Funções para a escrita no arquivo;
            fputs(produto->espaco_em_uso, arquivo);
            fprintf(arquivo, "%i", produto->projeto);
            fputs(produto->nome, arquivo);
            fputs(produto->codigo, arquivo);
            fputs(produto->versao, arquivo);
            fputs(produto->lider, arquivo);
            fclose(arquivo);
            return SUCESSO;
            }
        else //!Se o caracter lido for 1 (um), significa que o espaço está sendo utilizado; Passa-se para o próximo bloco;
            {
            fseek(arquivo, sizeof(Produto), SEEK_CUR);
            }
        }
    if (feof(arquivo)) //!Se chegou ao fim do arquivo sem encontrar espaços vazios, escreve um novo bloco;
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
Função responsável por remover produtos do banco de dados. Recebe como parâmetro o codigo do produto e retorna o resultado da operação
(Resultados definidos em Codigos.h).
*/

int remover_produto(int codigo)
    {
    FILE *arquivo;
    int codigo_comparacao;
    int i=1; //!Variável a ser utilizada para percorrer o arquivo (como um multiplicador para a função fseek);

    arquivo=fopen("Produtos.txt", "r+"); //!Abertura do arquivo de forma a ser possível a leitura e escrita em um arquivo existente;
    if (arquivo==NULL) //!Testa a abertura do arquivo;
        {
        fclose(arquivo);
        return ERRO_BD;
        }

    fseek(arquivo, 22*sizeof(char), SEEK_CUR); //!Avança para a posição do registro em que se encontra o código;
    while (!feof(arquivo))
        {
        fscanf(arquivo, "%i", codigo_comparacao);
        if(codigo==codigo_comparacao) //!Se a comparação entre os dois códigos for positiva o condicional será iniciado;
            {
            rewind(arquivo);
            fseek(arquivo, i*sizeof(Produto), SEEK_CUR);
            fprintf(arquivo, "%c", "0");
            }
        else //!Se a comparação entre os dois códigos for negativa, avança-se para o próximo registro e incrementa-se o supracitado multiplicador;
            {
            fseek(arquivo, sizeof(Produto), SEEK_CUR);
            i++;
            }
        }
    fclose(arquivo);
    return SUCESSO;
    }

/**
Função responsável por editar os dados de um produto previamente cadastrado. Recebe como parâmetro o endereço de uma struct previamente declarada (em P-Produtos.h)
contendo os dados a serem modificados e retorna o resultado da operação (Resultados definidos em Codigos.h).
*/

int editar_produto(Produto *produto)
    {
    FILE *arquivo;
    int codigo_comparacao;
    int i=1; //!Variável a ser utilizada para percorrer o arquivo (como um multiplicador para a função fseek);

    arquivo=fopen("Produtos.txt", "r+"); //!Abertura do arquivo de forma a ser possível a leitura e escrita em um arquivo existente;
    if (arquivo==NULL) //!Testa a abertura do arquivo;
        {
        fclose(arquivo);
        return ERRO_BD;
        }

    fseek(arquivo, 22*sizeof(char), SEEK_CUR); //!Avança para a posição do registro em que se encontra o código;
    while (!feof(arquivo))
        {
        fscanf(arquivo, "%i", codigo_comparacao);
        if(codigo==codigo_comparacao) //!Se a comparação entre os dois códigos for positiva o condicional será iniciado;
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
        else //!Se a comparação entre os dois códigos for negativa, avança-se para o próximo registro e incrementa-se o supracitado multiplicador;
            {
            fseek(arquivo, sizeof(Produto), SEEK_CUR);
            i++;
            }
        }
    fclose(arquivo);
    return SUCESSO;
    }


/**
Função responsável por pesquisar por dados de produtos. Recebe como parâmetro o endereço de uma struct previamente declarada (em P-Produtos.h)
e retorna o resultado da operação (Resultados definidos em Codigos.h).
*/

int pesquisar_produto(Produto *produto)
    {
    FILE *arquivo;
    int codigo_comparacao;
    int i=1; //!Variável a ser utilizada para percorrer o arquivo (como um multiplicador para a função fseek);

    arquivo=fopen("Produtos.txt", "r+"); //!Abertura do arquivo de forma a ser possível a leitura e escrita em um arquivo existente;
    if (arquivo==NULL) //!Testa a abertura do arquivo;
        {
        fclose(arquivo);
        return ERRO_BD;
        }

    fseek(arquivo, 22*sizeof(char), SEEK_CUR); //!Avança para a posição do registro em que se encontra o código;
    while (!feof(arquivo))
        {
        fscanf(arquivo, "%i", codigo_comparacao);
        if(codigo==codigo_comparacao) //!Se a comparação entre os dois códigos for positiva o condicional será iniciado;
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
        else //!Se a comparação entre os dois códigos for negativa, avança-se para o próximo registro e incrementa-se o supracitado multiplicador;
            {
            fseek(arquivo, sizeof(Produto), SEEK_CUR);
            i++;
            }
        }
    fclose(arquivo);
    return SUCESSO;
    }
