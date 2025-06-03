#include <stdio.h>
#include <stdlib.h>

typedef struct TInfo{
int matricula;
char nome[30];
char email[15];
}Info;

typedef struct TNo{
Info info;
struct Tno *prox;
}No;

typedef struct Tlista{
    no *ini;
    no *fim;
}Lista;

void inicializa(Lista* lista){
    lista->ini = NULL;
    lista->fim = NULL;
}

int insere_ini(Lista* lista, int n){

    No* novo = (No*) malloc(sizeof(No));
    if(novo == NULL){return 0;}

    novo->info.matricula = n;
    novo->prox = lista->ini;
    lista->ini = novo;

    if(lista->fim == NULL){
        lista->fim == novo;
    }

    return 1;
}

int insere_fim(Lista* lista,int n){

    No* novo = (No*) malloc(sizeof(No));
    if(!novo){return 0;}

    if(lista->ini == NULL){
        lista->ini = novo;
        lista->fim = novo;
        return 1;
    }

    lista->fim->prox = novo;
    lista->fim = novo;
    novo->prox = NULL;

    return 1;
}

int insere_ord(Lista* lista, int n){

    No* novo = (No*) malloc(sizeof(No));
    if(!novo){return 0;}
    novo->info.matricula = n;
    novo->prox = NULL;

    if(lista->ini == NULL){
        lista->ini = novo;
        lista->fim = novo;
        return 1;
    }
     if (n < lista->ini->info.matricula){
        insere_ini(lista,n);
        return 1;
     }

    No* ant = NULL;
    No* aux = lista->ini;
    while(aux != NULL && aux->info.matricula < n){
        ant = aux;
        aux = aux->prox;
    }
    novo->prox = aux;
    aux->prox = novo;

    if (aux == NULL) {
        lista->fim = novo;
    }

    return 1;
}

