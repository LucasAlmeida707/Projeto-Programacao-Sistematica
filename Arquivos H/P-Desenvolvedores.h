#ifndef P_DESENVOLVEDORES_H
#define P_DESENVOLVEDORES_H
#ifdef P_DESENVOLVEDORES_SERVIDOR
#define EXT1
#else
#define EXT1 extern
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct desenvolvedor
    {
    char espaco_em_uso;
    char nome[16];
    char senha[6];
    char email[21];
    char lider_projeto;
    };

typedef struct desenvolvedor Desenvolvedor;

int cadastrar_desenvolvedor(Desenvolvedor*);
int remover_desenvolvedor(char*);
int editar_desenvolvedor(Desenvolvedor*);
int pesquisar_desenvolvedor(Desenvolvedor*);

#endif // P_DESENVOLVEDORES_H

