#include <stdio.h>
#include <stdlib.h>

typedef struct TInfo{
int matricula;
char nome[30];
char email[15];
}Info;

typedef struct TNo{
Info info;
struct TNo *prox;
}No;

typedef struct Tlista{
    No *ini;
    No *fim;
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
        lista->fim = novo;
    }

    return 1;
}

int insere_fim(Lista* lista,int n){

    No* novo = (No*) malloc(sizeof(No));
    if(!novo){return 0;}

    novo->prox = NULL;
    novo->info.matricula = n;

    if(lista->ini == NULL){
        lista->ini = novo;
        lista->fim = novo;
        return 1;
    }

    lista->fim->prox = novo;
    lista->fim = novo;

    return 1;
}

int insere_ord(Lista* lista, int n){

   if (lista->ini==NULL || n < lista->ini->info.matricula){
        insere_ini(lista,n);
        return 1;
     }

    No* novo = (No*) malloc(sizeof(No));
    if(!novo){return 0;}
    novo->info.matricula = n;
    novo->prox = NULL;

    No* ant = NULL;
    No* aux = lista->ini;
    while(aux != NULL && aux->info.matricula < n){
        ant = aux;
        aux = aux->prox;
    }
    novo->prox = aux;
    ant->prox = novo;

    if (novo->prox == NULL){
    lista->fim = novo;
    }

    return 1;
}

int exclui_ini(Lista* lista){
     if(lista->ini == NULL) return 1;
     No* aux = lista->ini;
     if(lista->ini == lista->fim){
        lista->ini = NULL;
        lista->fim = NULL;
     }else{
        lista->ini = lista->ini->prox;
     }
     free(aux);
     aux = NULL;
     return 1;
}

int exclui_fim(Lista* lista){
    if(lista->ini == NULL ){
        return 1;
    }
    if(lista->ini == lista->fim){
        exclui_ini(lista);
        return 1;
    }
    No* aux = lista->ini;
    while(aux->prox->prox != NULL){
        aux = aux->prox;
    }
    free(aux->prox);
    aux->prox = NULL;
    lista->fim = aux;
    return 1;
}

int main() {
    Lista lista;
    inicializa(&lista);

    insere_ord(&lista, 20);
    insere_ord(&lista, 10);
    insere_ord(&lista, 30);
    insere_ord(&lista, 25);
    insere_ini(&lista, 2);
    insere_fim(&lista, 35);

    No* p = lista.ini;
    while (p != NULL) {
        printf("%d ", p->info.matricula);
        p = p->prox;
    }

    return 0;
}


