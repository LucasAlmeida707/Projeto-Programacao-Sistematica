#ifndef P_PRODUTOS_H
#define P_PRODUTOS_H
#ifdef P_PRODUTOS_SERVIDOR
#define EXT2
#else
#define EXT2 extern
#endif

#include <stdio.h>
#include <stdlib.h>

struct produto
    {
    char espaco_em_uso;
    int projeto;
    char nome[16];
    char codigo[5];
    char versao[6];
    char lider;
    };

typedef struct produto Produto;

int cadastrar_produto(Produto*);
int remover_produto(int);
int editar_produto(Produto*);
int pesquisar_produto(Produto*);

#endif // P_PRODUTOS_H
