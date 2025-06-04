#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TInfo{
int matricula;
char nome[30];
char email[20];
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

int insere_ini(Lista* lista, Info* n){

    No* novo = (No*) malloc(sizeof(No));
    if(novo == NULL){return 0;}

    novo->info.matricula = n->matricula;
    strcpy(novo->info.email, n->email);
    strcpy(novo->info.nome, n->nome);
    novo->prox = lista->ini;
    lista->ini = novo;

    if(lista->fim == NULL){
        lista->fim = novo;
    }

    return 1;
}

int insere_fim(Lista* lista,Info* n){

    No* novo = (No*) malloc(sizeof(No));
    if(!novo){return 0;}

    novo->prox = NULL;
    novo->info.matricula = n->matricula;
    strcpy(novo->info.email, n->email);
    strcpy(novo->info.nome, n->nome);

    if(lista->ini == NULL){
        lista->ini = novo;
        lista->fim = novo;
        return 1;
    }

    lista->fim->prox = novo;
    lista->fim = novo;

    return 1;
}

int insere_ord(Lista* lista, Info* n){

   if (lista->ini==NULL || n->matricula < lista->ini->info.matricula){
        insere_ini(lista,n);
        return 1;
     }

    No* novo = (No*) malloc(sizeof(No));
    if(!novo){return 0;}
    novo->info.matricula = n->matricula;
    strcpy(novo->info.email, n->email);
    strcpy(novo->info.nome, n->nome);
    novo->prox = NULL;

    No* ant = NULL;
    No* aux = lista->ini;
    while(aux != NULL && aux->info.matricula < n->matricula){
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

char* obteremail(Lista* lista,Info* n){
    No* aux = lista->ini;
    while (aux != NULL) {
        if (aux->info.matricula == n->matricula) {
            return aux->info.email;
        }
        aux = aux->prox;
    }
    return NULL;
}

char* obternome(Lista* lista,Info* n){
    No* aux = lista->ini;
    while(aux !=NULL){
        if(aux->info.nome == n->nome){
            return aux->info.nome;
        }
        aux = aux->prox;
    }
    return NULL;
}

int contaelementos(Lista* lista){
    No* aux = lista->ini;
    int cont = 0;
    while(aux!=NULL){
        cont++;
        aux = aux->prox;
    }
    return cont;
}

void ordena(Lista* lista) {
    if (!lista || !lista->ini || !lista->ini->prox) return;

    int trocou;
    No* aux;
    No* fim = NULL;

    do {
        trocou = 0;
        aux = lista->ini;

        while (aux->prox != fim) {
            if (aux->info.matricula > aux->prox->info.matricula) {
                Info temp = aux->info;
                aux->info = aux->prox->info;
                aux->prox->info = temp;
                trocou = 1;
            }
            aux = aux->prox;
        }

        fim = aux;
    } while (trocou);
}

void contacatena(Lista* lista1, Lista* lista2){

    if(!lista1->ini || !lista2->ini)return;
    if(!lista1->ini){
        lista1->ini = lista2->ini;
        lista1->fim = lista2->fim;
    }else if (lista2->ini != NULL){

    lista1->fim->prox = lista2->ini;
    lista1->fim = lista2->fim;
    }

    lista2->ini = NULL;
    lista2->fim = NULL;


}

void mostraLista(Lista* lista){
    if(!lista->ini)return;
     No* p = lista->ini;
    while (p != NULL) {
        printf("matricula:%d \nemail:%s \nnome:%s \n\n", p->info.matricula,p->info.email,p->info.nome);
        p = p->prox;
    }

}

int main() {
    Lista lista,lista2;
    inicializa(&lista);
    inicializa(&lista2);

    Info dados1 = {202410516,"Olinoedson","ossena.cic@uesc.br"};
    Info dados2 = {202410514,"Kaiala","kjsantos.cic@uesc.br"};
    Info dados3 = {202410518,"Samuel","sfsantos.cic@uesc.br"};
    Info dados4 = {202410517,"Rebecca","rssantos.cic@uesc.br"};
    Info dados5 = {202410128,"Nathalie","nlbomfim.cic@uesc.br"};
    Info dados6 = {202410512,"Isaque","ispribeiro.cic@uesc.br"};
    Info dados7 = {202410506,"Alex","aasantos.cic@uesc.br"};

    insere_ini(&lista,&dados1);
    insere_ord(&lista,&dados2);
    insere_ini(&lista,&dados3);

    insere_ini(&lista2,&dados4);
    insere_fim(&lista2,&dados5);
    insere_fim(&lista2,&dados6);
    insere_ini(&lista2,&dados7);


    int cont = contaelementos(&lista);

    printf("%d\n\n",cont);

    mostraLista(&lista);
    contacatena(&lista,&lista2);
    ordena(&lista);

    mostraLista(&lista);

    char* email = obteremail(&lista,&dados1);
     if (email != NULL) {
        printf("Email encontrado: %s\n", email);
    } else {
        printf("Matrícula não encontrada.\n");
    }

    return 0;
}
