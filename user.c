#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "lista.h"

int main(){

setlocale(LC_ALL, "Portuguese_Brazil");

    Lista lista;

    lista=cria_lista();

    menor_elem(&lista);
    tamanho(&lista);

    imprime_lista(&lista);

    insere_ord(&lista,4);
    insere_ord(&lista,15);
    insere_ord(&lista,19);
    insere_ord(&lista,1);
    insere_ord(&lista,7);
    insere_ord(&lista,9);
    insere_ord(&lista,22);
    insere_ord(&lista,8);

    tamanho(&lista);
    imprime_lista(&lista);

    remove_impares(&lista);
    tamanho(&lista);
    imprime_lista(&lista);

    menor_elem(&lista);
    tamanho(&lista);

    imprime_lista(&lista);

    remove_ord(&lista,8);

    menor_elem(&lista);
    tamanho(&lista);

    imprime_lista(&lista);

    menor_elem(&lista);
    tamanho(&lista);

    imprime_lista(&lista);

    menor_elem(&lista);
    tamanho(&lista);

    imprime_lista(&lista);

    printf("\n\n\n\n");

    Lista lista1=cria_lista();
    Lista lista2=cria_lista();

    insere_ord(&lista1,0);
    insere_ord(&lista1,17);
    insere_ord(&lista1,3);
    insere_ord(&lista1,30);

    insere_ord(&lista2,17);
    insere_ord(&lista2,0);
    insere_ord(&lista2,3);
    insere_ord(&lista2,30);
    insere_ord(&lista2,34);
    insere_ord(&lista2,-2);

    iguais(&lista1,&lista2);

    Lista lista3;

    lista3 =intercala(&lista1,&lista2);

    imprime_lista(&lista3);

    free(lista);
    free(lista1);
    free(lista2);
    free(lista3);

    return 0;
}
