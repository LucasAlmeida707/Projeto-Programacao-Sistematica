#ifndef P-PRODUTOS_H
#define P-PRODUTOS_H
#ifdef P-PRODUTOS_SERVIDOR
#define EXT2
#else
#define EXT2 extern
#endif

struct produto
    {

    };

typedef struct produto Produto;

int cadastrar_produto(Produto*);
int remover_produto(int);
int editar_produto(Produto*);
int pesquisar_produto(Produto*);

#endif // P-PRODUTOS_H