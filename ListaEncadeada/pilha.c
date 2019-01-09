#include "pilha.h"

struct elemento
{
    int num;
    struct elemento *prox;
};

typedef struct elemento Elemento;

Pilha *criarPilha()
{
    Pilha *p = (Pilha*)malloc(sizeof(Pilha));

    if(p==NULL)
    {
        printf("Falha na alocacao da pilha!");
        exit(0);
    }

    (*p) = NULL;
}

void liberarPilha(Pilha *p)
{
    if(p==NULL)
    {
        printf("Pilha inexistente!");
        exit(0);
    }

    Elemento *aux = (*p);

    while(aux!=NULL)
    {
        aux = (*p);
        (*p) = (*p)->prox;
        free(aux);
    }

    free(p);
}

void push(Pilha *p, int num)
{
    if(p==NULL)
    {
        printf("Pilha inexistente!");
        exit(0);
    }

    Elemento *novo = (Elemento*)malloc(sizeof(Elemento));

    novo->num = num;
    novo->prox = (*p);
    (*p) = novo;
}

void pop(Pilha *p)
{
    if(p==NULL)
    {
        printf("Pilha inexistente!");
    }

    if((*p)==NULL)
    {
        printf("Impossivel remover de uma pilha vazia!");
    }

    Elemento *aux = (*p);

    (*p) = aux->prox;
    free(aux);
}

int top(Pilha *p)
{
    return (*p)->num;
}

Pilha *consultaPilha(Pilha *p)
{
    if(p==NULL)
    {
        printf("Lista inválida!");
    }
    if((*p)==NULL)
    {
        printf("Lista vazia!");
    }

    Elemento *aux = (*p);

    while(aux!=NULL)
    {
        printf("%d", aux->num);
        aux = aux->prox;
    }
}

Pilha *converteBinario(int num)
{
    Pilha *bin = criarPilha();

    while(num != 0)
    {
        push(bin, num%2);
        num/=2;
    }

    return bin;
}
