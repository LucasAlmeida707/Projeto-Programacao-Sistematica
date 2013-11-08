#ifndef P-DESENVOLVEDORES_H
#define P-DESENVOLVEDORES_H
#ifdef P-DESENVOLVEDORES_SERVIDOR
#define EXT1
#else
#define EXT1 extern
#endif

#include <stdio.h>
#include <stdlib.h>

struct desenvolvedor
    {
    char espaco_em_uso;
    char nome[15];
    char senha[5];
    char email[20];
    char lider_projeto;
    };

typedef struct desenvolvedor Desenvolvedor;

int cadastrar_desenvolvedor(Desenvolvedor*);
int remover_desenvolvedor(char*);
int editar_desenvolvedor(Desenvolvedor*);
int pesquisar_desenvolvedor(Desenvolvedor*);

#endif // P-DESENVOLVEDORES_H

