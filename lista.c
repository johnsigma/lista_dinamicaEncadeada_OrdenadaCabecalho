#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct no{
    int info;
    struct no *prox;
};

Lista cria_lista(){
    Lista cab;
    cab=(Lista) malloc(sizeof(struct no));
    if(cab!=NULL){
        cab->prox=NULL;
        cab->info=0;
    }
    return cab;
}

int lista_vazia(Lista lst){
    if(lst->prox==NULL)
        return 1; //lista vazia
    else
        return 0; //lista n�o vazia
}

int insere_ord(Lista *lst, int elem){
    Lista N=(Lista) malloc(sizeof(struct no));
    if(N==NULL)
        return 0; //falha na aloca��o
    N->info=elem; //insere o valor do elemento no n�

    //percorimento da lista (elem >1� n� da lista)
    Lista aux=*lst; //faz aux apontar para o 1� n�
    while(aux->prox!=NULL && aux->prox->info<elem)
        aux=aux->prox; //avan�a
    N->prox=aux->prox;
    aux->prox=N;
    (*lst)->info++;
    return 1;
}

int remove_ord(Lista *lst, int elem){
    if(lista_vazia(*lst)==1)
        return 0; //falha

    Lista aux=*lst; //ponteiro auxiliar para o 1� elemento

    //percorrimento at� o final ou at� achar elem ou elem maior
   while(aux->prox!=NULL && aux->prox->info<elem)
        aux=aux->prox;
   if(aux->prox==NULL || aux->prox->info>elem)
        return 0; //falha

   //remove elemento (ap�s o 1� n� a lista
   Lista aux2=aux->prox; //aponta para o n� a ser removido
   aux->prox=aux2->prox; //retira o n� da lista
   free(aux2); //libera mem�ria alocada
   (*lst)->info--;
   return 1; //sucesso na remo��o
}

Lista imprime_lista(Lista *lst){
    if(lista_vazia(*lst)){
        printf("\nLista vazia!\n\n");
        return 0;
    }
    else{
        Lista aux=(*lst)->prox;
        printf("\nLista: ");
        while(aux!=NULL){
            printf("%d ", aux->info);
            aux=aux->prox;
        }
        printf("\n\n");
    }
    return 1;
}

int menor_elem(Lista *lst){
    if(lista_vazia(*lst)==1) //verifica se a lista � vazia
        return 0;
    Lista aux=*lst;

    Lista aux2=aux->prox;
    aux->prox=aux2->prox;
    free(aux2);
    (*lst)->info--;

    return 1; //sucesso na remo��o
}

int tamanho(Lista *lst){
    printf("Tamanho da lista: %d", (*lst)->info);
}

int remove_impares(Lista *lst){
    Lista aux=(*lst)->prox;
    Lista aux2=*lst;

    while(aux!=NULL){
        if(aux->info%2!=1){
            aux2=aux;
            aux=aux->prox;
        }else{
            aux2->prox=aux->prox;
            free(aux);
            aux=aux2;
            (*lst)->info--;
        }
    }
    return 1;
}


int iguais(Lista *lst1, Lista *lst2){

    if((*lst1)->info!=(*lst2)->info){
        printf("\nAs listas n�o s�o iguais!\n\n");
        return -1;
    }
    Lista aux=(*lst1)->prox;
    Lista aux2=(*lst2)->prox;

    while(aux!=NULL && aux2!=NULL){
        if(aux->info==aux2->info){
            printf("\nAs listas s�o iguais!\n");
            return 0;
        }
        aux=aux->prox;
        aux2=aux2->prox;
    }
    printf("\nAs listas n�o s�o iguais!\n\n");
    return 1;
}

Lista intercala(Lista *lst1, Lista *lst2){
    Lista lst3=cria_lista();
    Lista aux1=(*lst1)->prox;
    Lista aux2=(*lst2)->prox;
    Lista aux3=lst3;

    while(aux1!=NULL && aux2!=NULL){
        Lista N=(Lista) malloc(sizeof(struct no));
        if(N==NULL)
            return 0;
        if(aux1->info<=aux2->info){
            N->info=aux1->info;
            aux1=aux1->prox;
            lst3->info++;
        }else{
            N->info=aux2->info;
            aux2=aux2->prox;
            lst3->info++;
        }
        aux3->prox=N;
        aux3=N;
    }

    while(aux1!=NULL){
        Lista N=(Lista) malloc(sizeof(struct no));
        if(N==NULL)
            return 0;
        N->info=aux1->info;
        aux1=aux1->prox;
        aux3->prox=N;
        aux3=N;
        lst3->info++;
    }

    while(aux2!=NULL){
        Lista N=(Lista) malloc(sizeof(struct no));
        if(N==NULL)
            return 0;
        N->info=aux2->info;
        aux2=aux2->prox;
        aux3->prox=N;
        aux3=N;
        lst3->info++;
    }

    if(aux3!=NULL)
        aux3->prox=NULL;

    return lst3;
}
