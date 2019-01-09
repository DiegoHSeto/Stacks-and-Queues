#include "lista.h"
#include <stdarg.h>


struct elemento
{
    int num;
    struct elemento *prox;
};

typedef struct elemento Elemento;

Lista *criarLista()
{
    Lista *l = (Lista *)malloc(sizeof(Lista));

    if(l==NULL)
    {
        printf("Erro na alocacao da lista!");
        exit(0);
    }

    (*l) = NULL;

    return l;
}

void liberarLista(Lista *l)
{
    if((*l)==NULL)
    {
        printf("Lista inexistente");
    }

    Elemento *aux;

    while((*l)!=NULL)
    {
        aux = (*l);
        (*l) = (*l)->prox;
        free(aux);
    }

    free(l);
}

void addElemento(Lista *l, int num)
{
    if(l==NULL)
    {
        printf("Lista inexistente");
        exit(0);
    }

    Elemento *novo = (Elemento*)malloc(sizeof(Elemento));

    novo->num = num;
    novo->prox = NULL;

    if((*l)==NULL)
    {
        (*l) = novo;
    }
    else
    {
        Elemento *aux = (*l);

        while(aux->prox!=NULL)
        {
            aux = aux->prox;
        }

        aux->prox = novo;
    }
}

void removerElemento(Lista *l, int num)
{
    if(l==NULL)
    {
        printf("Lista inexistente!");
        exit(0);
    }

    if((*l)==NULL)
    {
        printf("Impossivel remover de uma lista vazia!");
        exit(0);
    }

    Elemento *aux = (*l);
    Elemento *aux2;

    while(aux != NULL && aux->num!=num)
    {
        aux = aux->prox;
        aux2 = aux;
    }

    if(aux == NULL)
    {
        printf("Elemento nao encontrado!");
        exit(0);
    }

    aux2->prox = aux->prox;
}

void addTodos(int vl, Lista *l, ...)
{
    int i;
    va_list v;

    va_start(v, vl);

    for(i = 0; i < vl; i++)
    {
        addElemento(l, va_arg(v, int));
    }

    va_end(v);
}

void removeRepetidos(Lista *l)
{
    Elemento *aux = (*l);
    Elemento *aux2;
    Elemento *anterior;
    Elemento *remove;

    while(aux!=NULL)
    {
        aux2 = aux->prox;
        anterior = aux;

        while(aux2!=NULL)
        {
            if(aux->num == aux2->num)
            {
                anterior->prox = aux2->prox;
                remove = aux2;
                aux2 = aux2 ->prox;
                free(remove);
                continue;
            }


            anterior = aux2;
            aux2 = aux2->prox;
        }

        aux = aux->prox;
    }
}

void consultarLista(Lista *l)
{
    if((*l)==NULL)
    {
        printf("Lista vazia!");
        exit(0);
    }

    Elemento *aux = (*l);

    while(aux!=NULL)
    {
        printf("%d ", aux->num);
        aux = aux->prox;
    }
}

Lista *uniaoLista(Lista *a, Lista *b)
{
    Lista *c = (Lista *)malloc(sizeof(Lista));

    if(c==NULL)
    {
        printf("Falha na alocacao da lista!");
        exit(0);
    }

    (*c) = NULL;

    Elemento *aux = (*a);
    Elemento *aux2 = (*b);

    while(aux!=NULL)
    {
        addElemento(c, aux->num);
        aux = aux->prox;
    }

    while(aux2!=NULL)
    {
        addElemento(c, aux2->num);
        aux2 = aux2->prox;
    }

    removeRepetidos(c);

    return c;
}

Lista *interseccaoLista(Lista *a, Lista *b)
{

    Lista *c = (Lista *)malloc(sizeof(Lista));

    if(c==NULL)
    {
        printf("Falha na alocacao da lista!");
    }

    (*c) = NULL;

    Elemento *aux = (*a);
    Elemento *aux2 = (*b);

    while(aux!=NULL)
    {
        aux2 = (*b);

        while(aux2!=NULL)
        {
            if(aux->num == aux2->num)
            {
               addElemento(c, aux->num);
            }

            aux2 = aux2->prox;
        }

        aux = aux->prox;
    }

    removeRepetidos(c);

    return c;
}
