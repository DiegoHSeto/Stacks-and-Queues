#include <stdio.h>
#include <stdlib.h>

typedef struct elemento *Lista;

Lista *criarLista();
void liberarLista(Lista *l);
void addElemento(Lista *l, int num);
void removerElemento(Lista *l, int num);
void addTodos(int vl, Lista *l, ...);
void consultarLista(Lista *l);
void removeRepetidos(Lista *l);
Lista *uniaoLista(Lista *a, Lista *b);
Lista *interseccaoLista(Lista *a, Lista *b);



