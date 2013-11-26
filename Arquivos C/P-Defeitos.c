#define P-DEFEITOS_SERVIDOR
#include "P-Defeitos.h"
#include "Codigos.h"

/**/
int cadastrar_defeito(Defeito *defeito);
    {
    FILE *arquivo;
    char espaco_em_uso;

    arquivo=fopen("Defeitos.txt", "r+"); //Abertura do arquivo de forma a ser possível a leitura e escrita em um arquivo existente;
    if (arquivo==NULL) //Testa a abertura do arquivo;
        {
        fclose(arquivo);
        return ERRO_BD;
        }

    while(!feof(arquivo)) //Enquanto não for o fim do arquivo, continua a busca;
        {
        fscanf(arquivo, "%c", &espaco_em_uso);
        if (espaco_em_uso==0) //Se o caracter lido for 0 (zero), significa que o espaço não está sendo utilizado e seu conteúdo será sobreescrito;
            {
            //Funções para a escrita no arquivo;
            fputs(defeito.espaco_em_uso, arquivo);
            fprintf(arquivo, "%i", defeito.codigo);
            fputs(defeito.descricao, arquivo);
            fputs(defeito.estado, arquivo);
            fprintf(arquivo, "%i", defeito.votos);
            fputs(defeito.data_abertura, arquivo);
            fputs(defeito.data_fechamento, arquivo);
            fclose(arquivo);
            return SUCESSO;
            }
        else //Se o caracter lido for 1 (um), significa que o espaço está sendo utilizado; Passa-se para o próximo bloco;
            {
            fseek(arquivo, sizeof(Defeito), SEEK_CUR);
            }
        }
    if (feof(arquivo)) //Se chegou ao fim do arquivo sem encontrar espaços vazios, escreve um novo bloco;
        {
        fputs(defeito.espaco_em_uso, arquivo);
        fprintf(arquivo, "%i", defeito.codigo);
        fputs(defeito.descricao, arquivo);
        fputs(defeito.estado, arquivo);
        fprintf(arquivo, "%i", defeito.votos);
        fputs(defeito.data_abertura, arquivo);
        fputs(defeito.data_fechamento, arquivo);
        }
    fclose(arquivo);
    return SUCESSO;
    }

/**/
int remover_defeito(int codigo);
    {
    FILE *arquivo;
    int codigo_comparacao;
    int i=1; //Variável a ser utilizada para percorrer o arquivo (como um multiplicador para a função fseek);

    arquivo=fopen("Defeitos.txt", "r+"); //Abertura do arquivo de forma a ser possível a leitura e escrita em um arquivo existente;
    if (arquivo==NULL) //Testa a abertura do arquivo;
        {
        fclose(arquivo);
        return ERRO_BD;
        }

    fseek(arquivo, sizeof(char), SEEK_CUR); //Avança para a posição do registro em que se encontra o código;
    while (!feof(arquivo))
        {
        fscanf(arquivo, "%i", codigo_comparacao);
        if(codigo==codigo_comparacao) //Se a comparação entre os dois códigos for positiva o condicional será iniciado;
            {
            rewind(arquivo);
            fseek(arquivo, i*sizeof(Defeito), SEEK_CUR);
            fprintf(arquivo, "%c", "0");
            }
        else //Se a comparação entre os dois códigos for negativa, avança-se para o próximo registro e incrementa-se o supracitado multiplicador;
            {
            fseek(arquivo, sizeof(Defeito), SEEK_CUR);
            i++;
            }
        }
    fclose(arquivo);
    return SUCESSO;
    }

/**/
int editar_defeito(Defeito *defeito);
    {
    FILE *arquivo;
    int codigo_comparacao;
    int i=1; //Variável a ser utilizada para percorrer o arquivo (como um multiplicador para a função fseek);

    arquivo=fopen("Defeitos.txt", "r+"); //Abertura do arquivo de forma a ser possível a leitura e escrita em um arquivo existente;
    if (arquivo==NULL) //Testa a abertura do arquivo;
        {
        fclose(arquivo);
        return ERRO_BD;
        }

    fseek(arquivo, sizeof(char), SEEK_CUR); //Avança para a posição do registro em que se encontra o código;
    while (!feof(arquivo))
        {
        fscanf(arquivo, "%i", codigo_comparacao);
        if(codigo==codigo_comparacao) //Se a comparação entre os dois códigos for positiva o condicional será iniciado;
            {
            rewind(arquivo);
            fseek(arquivo, i*sizeof(Defeito), SEEK_CUR);
            fputs(defeito.espaco_em_uso, arquivo);
            fprintf(arquivo, "%i", defeito.codigo);
            fputs(defeito.descricao, arquivo);
            fputs(defeito.estado, arquivo);
            fprintf(arquivo, "%i", defeito.votos);
            fputs(defeito.data_abertura, arquivo);
            fputs(defeito.data_fechamento, arquivo);
            }
        else //Se a comparação entre os dois códigos for negativa, avança-se para o próximo registro e incrementa-se o supracitado multiplicador;
            {
            fseek(arquivo, sizeof(Defeito), SEEK_CUR);
            i++;
            }
        }
    fclose(arquivo);
    return SUCESSO;
    }


/**/
int pesquisar_defeito(Defeito *defeito);
    {
    FILE *arquivo;
    int codigo_comparacao;
    int i=1; //Variável a ser utilizada para percorrer o arquivo (como um multiplicador para a função fseek);

    arquivo=fopen("Defeitos.txt", "r+"); //Abertura do arquivo de forma a ser possível a leitura e escrita em um arquivo existente;
    if (arquivo==NULL) //Testa a abertura do arquivo;
        {
        fclose(arquivo);
        return ERRO_BD;
        }

    fseek(arquivo, sizeof(char), SEEK_CUR); //Avança para a posição do registro em que se encontra o código;
    while (!feof(arquivo))
        {
        fscanf(arquivo, "%i", codigo_comparacao);
        if(codigo==codigo_comparacao) //Se a comparação entre os dois códigos for positiva o condicional será iniciado;
            {
            rewind(arquivo);
            fseek(arquivo, i*sizeof(Defeito), SEEK_CUR);
            fgets(defeito.espaco_em_uso, 1, arquivo);
            fscanf(arquivo, "%i", defeito.codigo);
            fgets(defeito.descricao, 30, arquivo);
            fgets(defeito.estado, 11,arquivo);
            fscanf(arquivo, "%i", defeito.votos);
            fgets(defeito.data_abertura, 11, arquivo);
            fgets(defeito.data_fechamento, 11, arquivo);
            }
        else //Se a comparação entre os dois códigos for negativa, avança-se para o próximo registro e incrementa-se o supracitado multiplicador;
            {
            fseek(arquivo, sizeof(Defeito), SEEK_CUR);
            i++;
            }
        }
    fclose(arquivo);
    return SUCESSO;
    }
