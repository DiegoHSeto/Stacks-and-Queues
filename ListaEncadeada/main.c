#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "pilha.h"

int main()
{
    Lista *repetidos = criarLista();
    Lista *l1 = criarLista(), *l2 = criarLista();
    Lista *uniao, *interseccao;
    Pilha *binario;
    int num = 25;

    addTodos(8, repetidos, 2, 2, 3, 2, 5, 2, 4, 4);

    addTodos(8, l1, 3, 8, 7, 11, 10, 4, 15, 5);
    addTodos(8, l2, 12, 15, 3, 9, 5, 10, 23, 4);

    //1)Remoção de elementos repetidos da lista.

    printf("\n---------REMOCAO DE ELEMENTOS REPETIDOS NA LISTA---------\n\n");
    printf("Lista com elementos repetidos: ");
    consultarLista(repetidos);
    printf("\n\nRemovendo os elementos repetidos: ");
    removeRepetidos(repetidos);
    consultarLista(repetidos);
    printf("\n\n---------------------------------------------------------\n\n");

    //2) Conversão de um número para binário utilizando uma pilha.

    printf("\n--------CONVERSAO DE UM NUMERO DECIMAL PARA BINARIO------\n\n");
    printf("Numero em decimal: %d", num);
    printf("\n\nNumero convertido para binario: ");
    binario = converteBinario(num);
    consultaPilha(binario);
    printf("\n\n---------------------------------------------------------\n\n");

    //3) União de duas listas, sem repetidos.

    printf("\n------UNIAO DE DUAS LISTAS SEM ELEMENTOS REPETIDOS-------\n\n");
    printf("Lista L1: ");
    consultarLista(l1);
    printf("\n\nLista L2: ");
    consultarLista(l2);
    printf("\n\nL1 U L2: ");
    uniao = uniaoLista(l1, l2);
    consultarLista(uniao);
    printf("\n\n---------------------------------------------------------\n\n");

    //4) Interssecção entre duas listas.

    printf("\n-------------INTERSECCAO ENTRE DUAS LISTAS---------------\n\n");
    printf("Lista L1: ");
    consultarLista(l1);
    printf("\n\nLista L2: ");
    consultarLista(l2);
    printf("\n\nL1 ^ L2: ");
    interseccao = interseccaoLista(l1, l2);
    consultarLista(interseccao);
    printf("\n\n---------------------------------------------------------\n\n");

    return 0;
}
