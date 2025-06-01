#include <stdio.h>
#include <stdlib.h>


typedef struct Tlista{
int info;
struct Tlista *prox;
}Lista;

Lista* insere_end(Lista* lista, int n){
    Lista *novo = (Lista*) malloc(sizeof(Lista));
    novo->info = n;
    novo->prox = NULL;

    if(lista == NULL){
        return novo;
    }

    Lista *aux = lista;
    while(aux->prox != NULL){
        aux = aux->prox;
    }
    aux->prox = novo;

    return lista;
}

bool listavazia(Lista* lista){
    if(lista == NULL){
        return true;
    }
    return false;
}

Lista* delete_ini(Lista* lista){

    if(lista == NULL){
        return lista;
    }

    Lista* aux = lista;
    lista = lista->prox;
    free(aux);

    return lista;
}

Lista* insere_ini(Lista* lista, int n){
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    novo->info = n;
    novo->prox = NULL;

    if(lista==NULL){
        return novo;
    }

    novo->prox = lista;
    lista = novo;


    return lista;
}

Lista* insere_ordem(Lista* lista, int n){

    Lista *novo = (Lista*) malloc(sizeof(Lista));
    novo->info = n;
    novo->prox = NULL;

    if(lista == NULL){
        return novo;
    }
    if(n < lista->info){
        novo->prox = lista;
        return novo;
    }
    Lista *aux = lista;
    while(aux->prox != NULL && aux->prox->info < n){
            aux = aux->prox;
    }
    novo->prox = aux->prox;
    aux->prox = novo;
    return lista;
}

Lista* remove(Lista* lista, int n){

    if(lista == NULL){
        return lista;
    }

    if(lista->info == n){
        Lista *temp = lista;
        lista = lista->prox;
        free(temp);
        return lista;
    }

    Lista* aux = lista;
    while(aux->prox != NULL && aux->prox->info != n){
        aux = aux->prox;
    }

    if (aux->prox != NULL && aux->prox->info == n) {
    Lista* temp = aux->prox;
    aux->prox = temp->prox;
    free(temp);
}


    return lista;
}


    }
