#define P_DESENVOLVEDORES_SERVIDOR
#include "P-Desenvolvedores.h"
#include "Codigos.h"

/**/
int cadastrar_desenvolvedor(Desenvolvedor *desenvolvedor);
    {
    FILE *arquivo;
    char espaco_em_uso;

    arquivo=fopen("Desenvolvedores.txt", "r+"); //Abertura do arquivo de forma a ser poss�vel a leitura e escrita em um arquivo existente;
    if (arquivo==NULL) //Testa a abertura do arquivo;
        {
        fclose(arquivo);
        return ERRO_BD;
        }

    while(!feof(arquivo)) //Enquanto n�o for o fim do arquivo, continua a busca;
        {
        fscanf(arquivo, "%c", &espaco_em_uso);
        if (espaco_em_uso==0) //Se o caracter lido for 0 (zero), significa que o espa�o n�o est� sendo utilizado e seu conte�do ser� sobreescrito;
            {
            //Fun��es para a escrita no arquivo;
            fputs(desenvolvedor.espaco_em_uso, arquivo);
            fputs(desenvolvedor.nome, arquivo);
            fputs(desenvolvedor.email, arquivo);
            fputs(desenvolvedor.senha, arquivo);
            fputs(desenvolvedor.lider_projeto, arquivo);
            fclose(arquivo);
            return SUCESSO;
            }
        else //Se o caracter lido for 1 (um), significa que o espa�o est� sendo utilizado; Passa-se para o pr�ximo bloco;
            {
            fseek(arquivo, sizeof(Desenvolvedor), SEEK_CUR);
            }
        }
    if (feof(arquivo)) //Se chegou ao fim do arquivo sem encontrar espa�os vazios, escreve um novo bloco;
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
    int i=1; //Vari�vel a ser utilizada para percorrer o arquivo (como um multiplicador para a fun��o fseek);

    arquivo=fopen("Desenvolvedores.txt", "r+"); //Abertura do arquivo de forma a ser poss�vel a leitura e escrita em um arquivo existente;
    if (arquivo==NULL) //Testa a abertura do arquivo;
        {
        fclose(arquivo);
        return ERRO_BD;
        }

    fseek(arquivo, 21*sizeof(char), SEEK_CUR); //Avan�a para a posi��o do registro em que se encontra o email;
    while (!feof(arquivo))
        {
        fgets(email_comparacao, 20, arquivo);
        if(!strcmp(email, email_comparacao)) //Se a compara��o entre as duas strings for positiva (retorno 0) o condicional ser� iniciado;
            {
            rewind(arquivo);
            fseek(arquivo, i*sizeof(Desenvolvedor), SEEK_CUR);
            fprintf(arquivo, "%c", "0");
            }
        else //Se a compara��o entre as duas strings for negativa, avan�a-se para o pr�ximo registro e incrementa-se o supracitado multiplicador;
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
    int i=1; //Vari�vel a ser utilizada para percorrer o arquivo (como um multiplicador para a fun��o fseek);

    arquivo=fopen("Desenvolvedores.txt", "r+"); //Abertura do arquivo de forma a ser poss�vel a leitura e escrita em um arquivo existente;
    if (arquivo==NULL) //Testa a abertura do arquivo;
        {
        fclose(arquivo);
        return ERRO_BD;
        }

    fseek(arquivo, 16*sizeof(char), SEEK_CUR); //Avan�a para a posi��o do registro em que se encontra o email;
    while (!feof(arquivo))
        {
        fgets(email_comparacao, 20, arquivo);
        if(!strcmp(email, email_comparacao)) //Se a compara��o entre as duas strings for positiva (retorno 0) o condicional ser� iniciado;
            {
            rewind(arquivo);
            fseek(arquivo, i*sizeof(Desenvolvedor), SEEK_CUR);
            fputs(desenvolvedor.espaco_em_uso, arquivo);
            fputs(desenvolvedor.nome, arquivo);
            fputs(desenvolvedor.email, arquivo);
            fputs(desenvolvedor.senha, arquivo);
            fputs(desenvolvedor.lider_projeto, arquivo);
            }
        else //Se a compara��o entre as duas strings for negativa, avan�a-se para o pr�ximo registro e incrementa-se o supracitado multiplicador;
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
    int i=1; //Vari�vel a ser utilizada para percorrer o arquivo (como um multiplicador para a fun��o fseek);

    arquivo=fopen("Desenvolvedores.txt", "r+"); //Abertura do arquivo de forma a ser poss�vel a leitura e escrita em um arquivo existente;
    if (arquivo==NULL) //Testa a abertura do arquivo;
        {
        fclose(arquivo);
        return ERRO_BD;
        }

    fseek(arquivo, 16*sizeof(char), SEEK_CUR); //Avan�a para a posi��o do registro em que se encontra o email;
    while (!feof(arquivo))
        {
        fgets(email_comparacao, 20, arquivo);
        if(!strcmp(email, email_comparacao)) //Se a compara��o entre as duas strings for positiva (retorno 0) o condicional ser� iniciado;
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
        else //Se a compara��o entre as duas strings for negativa, avan�a-se para o pr�ximo registro e incrementa-se o supracitado multiplicador;
            {
            fseek(arquivo, sizeof(Desenvolvedor), SEEK_CUR);
            i++;
            }
        }
    fclose(arquivo);
    return REGISTRO_NAO_CADASTRADO;
    }
