#include <stdio.h>
#include <stdlib.h>

typedef struct elemento *Pilha;

Pilha *criarPilha();
void liberarPilha(Pilha *p);
void push(Pilha *p, int num);
void pop(Pilha *p);
int top(Pilha *p);
Pilha *consultaPilha(Pilha *p);
Pilha *converteBinario(int num);
