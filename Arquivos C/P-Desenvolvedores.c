#define P_DESENVOLVEDORES_SERVIDOR
#include "P-Desenvolvedores.h"
#include "Codigos.h"

/**/
int cadastrar_desenvolvedor(Desenvolvedor *desenvolvedor);
    {
    FILE *arquivo;
    char espaco_em_uso;

    arquivo=fopen("Desenvolvedores.txt", "r+"); //Abertura do arquivo de forma a ser possível a leitura e escrita em um arquivo existente;
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
            fputs(desenvolvedor.espaco_em_uso, arquivo);
            fputs(desenvolvedor.nome, arquivo);
            fputs(desenvolvedor.email, arquivo);
            fputs(desenvolvedor.senha, arquivo);
            fputs(desenvolvedor.lider_projeto, arquivo);
            fclose(arquivo);
            return SUCESSO;
            }
        else //Se o caracter lido for 1 (um), significa que o espaço está sendo utilizado; Passa-se para o próximo bloco;
            {
            fseek(arquivo, sizeof(Desenvolvedor), SEEK_CUR);
            }
        }
    if (feof(arquivo)) //Se chegou ao fim do arquivo sem encontrar espaços vazios, escreve um novo bloco;
        {
        fputs(desenvolvedor.espaco_em_uso, arquivo);
        fputs(desenvolvedor.nome, arquivo);
        fputs(desenvolvedor.email, arquivo);
        fputs(desenvolvedor.senha, arquivo);
        fputs(desenvolvedor.lider_projeto, arquivo);
        }
    fclose(arquivo);
    return SUCESSO;
    }

/**/
int remover_desenvolvedor(char* email);
    {
    FILE *arquivo;
    char email_comparacao[20];
    int i=1; //Variável a ser utilizada para percorrer o arquivo (como um multiplicador para a função fseek);

    arquivo=fopen("Desenvolvedores.txt", "r+"); //Abertura do arquivo de forma a ser possível a leitura e escrita em um arquivo existente;
    if (arquivo==NULL) //Testa a abertura do arquivo;
        {
        fclose(arquivo);
        return ERRO_BD;
        }

    fseek(arquivo, 21*sizeof(char), SEEK_CUR); //Avança para a posição do registro em que se encontra o email;
    while (!feof(arquivo))
        {
        fgets(email_comparacao, 20, arquivo);
        if(!strcmp(email, email_comparacao)) //Se a comparação entre as duas strings for positiva (retorno 0) o condicional será iniciado;
            {
            rewind(arquivo);
            fseek(arquivo, i*sizeof(Desenvolvedor), SEEK_CUR);
            fprintf(arquivo, "%c", "0");
            }
        else //Se a comparação entre as duas strings for negativa, avança-se para o próximo registro e incrementa-se o supracitado multiplicador;
            {
            fseek(arquivo, sizeof(Desenvolvedor), SEEK_CUR);
            i++;
            }
        }
    fclose(arquivo);
    return SUCESSO;
    }

/**/
int editar_desenvolvedor(Desenvolvedor *desenvolvedor);
    {
    FILE *arquivo;
    char email_comparacao[20];
    int i=1; //Variável a ser utilizada para percorrer o arquivo (como um multiplicador para a função fseek);

    arquivo=fopen("Desenvolvedores.txt", "r+"); //Abertura do arquivo de forma a ser possível a leitura e escrita em um arquivo existente;
    if (arquivo==NULL) //Testa a abertura do arquivo;
        {
        fclose(arquivo);
        return ERRO_BD;
        }

    fseek(arquivo, 16*sizeof(char), SEEK_CUR); //Avança para a posição do registro em que se encontra o email;
    while (!feof(arquivo))
        {
        fgets(email_comparacao, 20, arquivo);
        if(!strcmp(email, email_comparacao)) //Se a comparação entre as duas strings for positiva (retorno 0) o condicional será iniciado;
            {
            rewind(arquivo);
            fseek(arquivo, i*sizeof(Desenvolvedor), SEEK_CUR);
            fputs(desenvolvedor.espaco_em_uso, arquivo);
            fputs(desenvolvedor.nome, arquivo);
            fputs(desenvolvedor.email, arquivo);
            fputs(desenvolvedor.senha, arquivo);
            fputs(desenvolvedor.lider_projeto, arquivo);
            }
        else //Se a comparação entre as duas strings for negativa, avança-se para o próximo registro e incrementa-se o supracitado multiplicador;
            {
            fseek(arquivo, sizeof(Desenvolvedor), SEEK_CUR);
            i++;
            }
        }
    fclose(arquivo);
    return SUCESSO;
    }


/**/
int pesquisar_desenvolvedor(Desenvolvedor *desenvolvedor);
    {
    FILE *arquivo;
    char email_comparacao[20];
    int i=1; //Variável a ser utilizada para percorrer o arquivo (como um multiplicador para a função fseek);

    arquivo=fopen("Desenvolvedores.txt", "r+"); //Abertura do arquivo de forma a ser possível a leitura e escrita em um arquivo existente;
    if (arquivo==NULL) //Testa a abertura do arquivo;
        {
        fclose(arquivo);
        return ERRO_BD;
        }

    fseek(arquivo, 16*sizeof(char), SEEK_CUR); //Avança para a posição do registro em que se encontra o email;
    while (!feof(arquivo))
        {
        fgets(email_comparacao, 20, arquivo);
        if(!strcmp(email, email_comparacao)) //Se a comparação entre as duas strings for positiva (retorno 0) o condicional será iniciado;
            {
            rewind(arquivo);
            fseek(arquivo, i*sizeof(Desenvolvedor), SEEK_CUR);
            fgets(desenvolvedor.espaco_em_uso, 1, arquivo);
            fgets(desenvolvedor.nome, 15, arquivo);
            fgets(desenvolvedor.senha, 5, arquivo);
            fgets(desenvolvedor.email, 20, arquivo);
            fgets(desenvolvedor.lider_projeto, 1, arquivo);
            fclose(arquivo);
            return SUCESSO;
            }
        else //Se a comparação entre as duas strings for negativa, avança-se para o próximo registro e incrementa-se o supracitado multiplicador;
            {
            fseek(arquivo, sizeof(Desenvolvedor), SEEK_CUR);
            i++;
            }
        }
    fclose(arquivo);
    return REGISTRO_NAO_CADASTRADO;
    }
