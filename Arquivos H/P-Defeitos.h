#ifndef P-DEFEITOS_H
#define P-DEFEITOS_H
#ifdef P-DEFEITOS_SERVIDOR
#define EXT3
#else
#define EXT3 extern
#endif

#include <stdio.h>
#include <stdlib.h>

struct defeito
    {
    char espaco_em_uso;
    int codigo;
    char descricao[30];
    char estado[11];
    int votos;
    char data_abertura[11];
    char data_fechamento[11];
    };

typedef struct defeito Defeito;

int cadastrar_defeito(Defeito*);
int remover_defeito(int);
int editar_defeito(Defeito*);
int pesquisar_defeito(Defeito*);

#endif // P-DEFEITOS_H
