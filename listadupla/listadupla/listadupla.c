#include <stdio.h>
#include <stdlib.h>

struct TLdupla{
int info;
struct TLdupla *prox;
struct TLdupla *ant;
};
typedef struct TLdupla ListaDupla;

int insereini(ListaDupla **l, ListaDupla **fim, int num){

    ListaDupla *p =(ListaDupla*) malloc(sizeof(ListaDupla));
    p->info = num;

    if(*l == NULL){

        p->ant = NULL;
        p->prox = NULL;
        *l = p;
        *fim = p;

        }
        else{
            P->ant = NULL;
            p->prox = *l;
            *l->ant = p;
            *l = p;
        }
        return 1;
}

ListaDupla remove_ini(ListaDupla *ini){
return 0;
}

ListaDupla insere_ord(){
return *lista;
}
ListaDupla printlista(){
return *lista;
}

int main(void){

    ListaDupla lista;
    insereini(*lista);

return 0;
}
