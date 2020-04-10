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
        return 0; //lista não vazia
}

int insere_ord(Lista *lst, int elem){
    Lista N=(Lista) malloc(sizeof(struct no));
    if(N==NULL)
        return 0; //falha na alocação
    N->info=elem; //insere o valor do elemento no nó

    //percorimento da lista (elem >1º nó da lista)
    Lista aux=*lst; //faz aux apontar para o 1º nó
    while(aux->prox!=NULL && aux->prox->info<elem)
        aux=aux->prox; //avança
    N->prox=aux->prox;
    aux->prox=N;
    (*lst)->info++;
    return 1;
}

int remove_ord(Lista *lst, int elem){
    if(lista_vazia(*lst)==1)
        return 0; //falha

    Lista aux=*lst; //ponteiro auxiliar para o 1º elemento

    //percorrimento até o final ou até achar elem ou elem maior
   while(aux->prox!=NULL && aux->prox->info<elem)
        aux=aux->prox;
   if(aux->prox==NULL || aux->prox->info>elem)
        return 0; //falha

   //remove elemento (após o 1º nó a lista
   Lista aux2=aux->prox; //aponta para o nó a ser removido
   aux->prox=aux2->prox; //retira o nó da lista
   free(aux2); //libera memória alocada
   (*lst)->info--;
   return 1; //sucesso na remoção
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
    if(lista_vazia(*lst)==1) //verifica se a lista é vazia
        return 0;
    Lista aux=*lst;

    Lista aux2=aux->prox;
    aux->prox=aux2->prox;
    free(aux2);
    (*lst)->info--;

    return 1; //sucesso na remoção
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
        printf("\nAs listas não são iguais!\n\n");
        return -1;
    }
    Lista aux=(*lst1)->prox;
    Lista aux2=(*lst2)->prox;

    while(aux!=NULL && aux2!=NULL){
        if(aux->info==aux2->info){
            printf("\nAs listas são iguais!\n");
            return 0;
        }
        aux=aux->prox;
        aux2=aux2->prox;
    }
    printf("\nAs listas não são iguais!\n\n");
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
