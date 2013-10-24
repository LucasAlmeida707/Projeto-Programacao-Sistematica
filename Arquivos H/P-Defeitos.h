#ifndef P-DEFEITOS_H
#define P-DEFEITOS_H
#ifdef P-DEFEITOS_SERVIDOR
#define EXT3
#else
#define EXT3 extern
#endif

struct defeito
    {

    };

typedef struct defeito Defeito;

int cadastrar_defeito(Defeito*);
int remover_defeito(int);
int editar_defeito(Defeito*);
int pesquisar_defeito(Defeito*);

#endif // P-DEFEITOS_H
