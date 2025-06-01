#include <stdio.h>
#include <stdlib.h>

typedef struct TLdupla{
int info;
struct TLdupla *prox;
struct TLdupla *ant;
}Lista;
Lista* insere_fim(Lista* lista, int n);

int insere_ini(Lista **l, Lista **fim, int n){

    Lista *p =(Lista*) malloc(sizeof(Lista));
    p->info = n;

    if(*l == NULL){

        p->ant = NULL;
        p->prox = NULL;
        *l = p;
        *fim = p;

        }
        else{
            p->ant = NULL;
            p->prox = *l;
            (*l)->ant = p;
            *l = p;
        }
        return 1;
}

Lista* remove_ini(Lista *lista){
    if(lista == NULL){
        return lista;
    }
    Lista *temp = lista;
    lista = lista->prox;
    if(lista != NULL){
        lista->ant = NULL;
    }
    free(temp);
    return lista;
}

Lista* insere_ord(Lista *lista, int n){

    if (lista == NULL) {
        Lista* novo = (Lista*) malloc(sizeof(Lista));
        novo->info = n;
        novo->prox = NULL;
        novo->ant = NULL;
        return novo;
    }

    if(n < lista->info){
        Lista* fim = NULL;
        insere_ini(&lista, &fim, n);
    return lista;
    }

    Lista* aux = lista;
    while(aux != NULL && aux->info < n){
        aux = aux->prox;
    }

    if(aux == NULL){
        return insere_fim(lista,n);
    }

    Lista* novo = (Lista*) malloc(sizeof(Lista));
    novo->info = n;
    novo->prox = aux;
    novo->ant = aux->ant;

    if (aux->ant != NULL) {
         aux->ant->prox = novo;
    }
     aux->ant = novo;

    return lista;
}

Lista* insere_fim(Lista* lista, int n){

    Lista* novo = (Lista*) malloc(sizeof(Lista));
    novo->info = n;
    novo->prox = NULL;
    novo->ant = NULL;

    if(lista == NULL){
    return novo;
    }

    Lista* aux = lista;
    while(aux->prox != NULL){
        aux = aux->prox;
    }

    novo->ant = aux;
    aux->prox = novo;

    return lista;
}

void printlista(Lista* lista){
    while(lista != NULL){
        printf("%d",&lista->info);
        lista = lista->prox;
    }
     printf("\n");
}

