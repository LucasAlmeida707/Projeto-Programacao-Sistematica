#define P_DEFEITOS_SERVIDOR
#include "P-Defeitos.h"
#include "Codigos.h"

/**
Função responsável por cadastrar novos defeitos. Recebe como parâmetro o endereço de uma struct previamente declarada (em P-Defeitos.h)
e retorna o resultado da operação (Resultados definidos em Codigos.h).
*/

int cadastrar_defeito(Defeito *defeito)
    {
    FILE *arquivo;
    char espaco_em_uso;

    arquivo=fopen("Defeitos.txt", "r+"); //!Abertura do arquivo de forma a ser possível a leitura e escrita em um arquivo existente;
    if (arquivo==NULL) //!Testa a abertura do arquivo;
        {
        fclose(arquivo);
        return ERRO_BD;
        }

    while(!feof(arquivo)) //!Enquanto não for o fim do arquivo, continua a busca;
        {
        fscanf(arquivo, "%c", &espaco_em_uso);
        if (espaco_em_uso==0) //!Se o caracter lido for 0 (zero), significa que o espaço não está sendo utilizado e seu conteúdo será sobreescrito;
            {
            //!Funções para a escrita no arquivo;
            fputs(defeito->espaco_em_uso, arquivo);
            fputs(defeito->codigo, arquivo);
            fputs(defeito->descricao, arquivo);
            fputs(defeito->estado, arquivo);
            fprintf(arquivo, "%i", defeito->votos);
            fputs(defeito->data_abertura, arquivo);
            fputs(defeito->data_fechamento, arquivo);
            fclose(arquivo);
            return SUCESSO;
            }
        else //!Se o caracter lido for 1 (um), significa que o espaço está sendo utilizado; Passa-se para o próximo bloco;
            {
            fseek(arquivo, sizeof(Defeito), SEEK_CUR);
            }
        }
    if (feof(arquivo)) //!Se chegou ao fim do arquivo sem encontrar espaços vazios, escreve um novo bloco;
        {
        fputs(defeito->espaco_em_uso, arquivo);
        fputs(defeito->codigo, arquivo);
        fputs(defeito->descricao, arquivo);
        fputs(defeito->estado, arquivo);
        fprintf(arquivo, "%i", defeito->votos);
        fputs(defeito->data_abertura, arquivo);
        fputs(defeito->data_fechamento, arquivo);
        }
    fclose(arquivo);
    return SUCESSO;
    }

/**
Função responsável por remover defeitos do banco de dados. Recebe como parâmetro o código do defeito e retorna o resultado da operação
(Resultados definidos em Codigos.h).
*/

int remover_defeito(int codigo)
    {
    FILE *arquivo;
    int codigo_comparacao;
    int i=1; //!Variável a ser utilizada para percorrer o arquivo (como um multiplicador para a função fseek);

    arquivo=fopen("Defeitos.txt", "r+"); //!Abertura do arquivo de forma a ser possível a leitura e escrita em um arquivo existente;
    if (arquivo==NULL) //!Testa a abertura do arquivo;
        {
        fclose(arquivo);
        return ERRO_BD;
        }

    fseek(arquivo, sizeof(defeito->espaco_em_uso), SEEK_CUR); //!Avança para a posição do registro em que se encontra o código;
    while (!feof(arquivo))
        {
        fscanf(arquivo, "%i", codigo_comparacao);
        if(codigo==codigo_comparacao) //!Se a comparação entre os dois códigos for positiva o condicional será iniciado;
            {
            rewind(arquivo);
            fseek(arquivo, i*sizeof(Defeito), SEEK_CUR);
            fprintf(arquivo, "%c", "0");
            }
        else //!Se a comparação entre os dois códigos for negativa, avança-se para o próximo registro e incrementa-se o supracitado multiplicador;
            {
            fseek(arquivo, sizeof(Defeito), SEEK_CUR);
            i++;
            }
        }
    fclose(arquivo);
    return SUCESSO;
    }

/**
Função responsável por editar os dados de um defeito previamente cadastrado. Recebe como parâmetro o endereço de uma struct previamente declarada (em P-Defeitos.h)
contendo os dados a serem modificados e retorna o resultado da operação (Resultados definidos em Codigos.h).
*/

int editar_defeito(Defeito *defeito)
    {
    FILE *arquivo;
    int codigo_comparacao;
    int i=1; //!Variável a ser utilizada para percorrer o arquivo (como um multiplicador para a função fseek);

    arquivo=fopen("Defeitos.txt", "r+"); //!Abertura do arquivo de forma a ser possível a leitura e escrita em um arquivo existente;
    if (arquivo==NULL) //!Testa a abertura do arquivo;
        {
        fclose(arquivo);
        return ERRO_BD;
        }

    fseek(arquivo, sizeof(defeito->espaco_em_uso), SEEK_CUR); //!Avança para a posição do registro em que se encontra o código;
    while (!feof(arquivo))
        {
        fgets(codigo_comparacao, sizeof(defeito->codigo), arquivo);
        if(codigo==codigo_comparacao) //!Se a comparação entre os dois códigos for positiva o condicional será iniciado;
            {
            rewind(arquivo);
            fseek(arquivo, i*sizeof(Defeito), SEEK_CUR);
            fputs(defeito->espaco_em_uso, arquivo);
            fputs(defeito->codigo, arquivo);
            fputs(defeito->descricao, arquivo);
            fputs(defeito->estado, arquivo);
            fprintf(arquivo, "%i", defeito->votos);
            fputs(defeito->data_abertura, arquivo);
            fputs(defeito->data_fechamento, arquivo);
            }
        else //!Se a comparação entre os dois códigos for negativa, avança-se para o próximo registro e incrementa-se o supracitado multiplicador;
            {
            fseek(arquivo, sizeof(Defeito), SEEK_CUR);
            i++;
            }
        }
    fclose(arquivo);
    return SUCESSO;
    }


/**
Função responsável por pesquisar por dados de defeitos. Recebe como parâmetro o endereço de uma struct previamente declarada (em P-Defeitos.h)
e retorna o resultado da operação (Resultados definidos em Codigos.h).
*/

int pesquisar_defeito(Defeito *defeito)
    {
    FILE *arquivo;
    int codigo_comparacao;
    int i=1; //!Variável a ser utilizada para percorrer o arquivo (como um multiplicador para a função fseek);

    arquivo=fopen("Defeitos.txt", "r+"); //!Abertura do arquivo de forma a ser possível a leitura e escrita em um arquivo existente;
    if (arquivo==NULL) //!Testa a abertura do arquivo;
        {
        fclose(arquivo);
        return ERRO_BD;
        }

    fseek(arquivo, sizeof(defeito->espaco_em_uso), SEEK_CUR); //!Avança para a posição do registro em que se encontra o código;
    while (!feof(arquivo))
        {
        fgets(codigo_comparacao, sizeof(defeito->codigo), arquivo);
        if(codigo==codigo_comparacao) //!Se a comparação entre os dois códigos for positiva o condicional será iniciado;
            {
            rewind(arquivo);
            fseek(arquivo, i*sizeof(Defeito), SEEK_CUR);
            fgets(defeito->espaco_em_uso, sizeof(defeito->espaco_em_uso), arquivo);
            fscanf(arquivo, "%i", defeito->codigo);
            fgets(defeito->descricao, sizeof(defeito->descricao), arquivo);
            fgets(defeito->estado, sizeof(defeito->estado), arquivo);
            fgets(defeito->votos, sizeof(defeito->votos), arquivo);
            fgets(defeito->data_abertura, sizeof(defeito->data_abertura), arquivo);
            fgets(defeito->data_fechamento, sizeof(defeito->data_fechamento), arquivo);
            }
        else //!Se a comparação entre os dois códigos for negativa, avança-se para o próximo registro e incrementa-se o supracitado multiplicador;
            {
            fseek(arquivo, sizeof(Defeito), SEEK_CUR);
            i++;
            }
        }
    fclose(arquivo);
    return SUCESSO;
    }
