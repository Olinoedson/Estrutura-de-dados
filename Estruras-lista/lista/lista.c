0#include <stdio.h>
#include <stdlib.h>

struct tplista{
int info;
struct tplista *prox;
};

typedef struct tplista lista;]

lista *inicializa(){
return NULL;
}

lista insere_ini(lista *L,int n){
    lista *novo = (lista*) malloc(sizeof(lista));
    novo -> info = n;
    novo -> prox = l;
    return novo;
}

lista remove(lista* l, it n){
    lista *aux = NULL;
        if(l->info == n){
            aux = l->info;
            l = aux->prox;
        }
        else{
            aux = l;
            while(aux->prox->info != n){
                aux = aux->prox;
            }
            free(aux);
            aux = NULL;
        }
    return l;
}

lista ordena(lista l){


return l;
}

