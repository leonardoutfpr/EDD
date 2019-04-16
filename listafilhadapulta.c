#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct {
    int key;
}item;

typedef struct nozin *Ponteiro;

typedef struct nozin{
    item item;
    Ponteiro proximo;
}nozin;

typedef struct {
    Ponteiro inicio;
    int contador;
}LISTA;

void iniciar(LISTA *LISTA){
    LISTA->inicio=NULL;
    LISTA->contador=0;

}

bool vazia(LISTA *LISTA){
    if (LISTA->contador==0){
        return true;
    }
    else{
        return false;
    }
}

void inserir( LISTA *LISTA, item chavis){
    Ponteiro CORRE;
    Ponteiro aux;
    aux = (Ponteiro)malloc(sizeof(LISTA));
    aux->item = chavis;
    if(vazia(&LISTA) == true){
        aux->proximo=LISTA->inicio;
        LISTA->inicio= aux;
        LISTA->contador++;
    }
    else {
        CORRE = LISTA->inicio;
        while (CORRE != NULL && chavis.key > CORRE->proximo->item.key) {
            CORRE = CORRE->proximo;
            aux->proximo = CORRE->proximo;
            CORRE->proximo = aux;

        }
    }
    LISTA->contador++;
}
bool pesquisa(LISTA *LISTA , item chavis){
    if(vazia(&LISTA)== true){
        return false;
    }
    Ponteiro CORRE;
    CORRE=LISTA->inicio;
    while(CORRE!=NULL && chavis.key>CORRE->proximo->item.key) {
        CORRE = CORRE->proximo;
        if (CORRE == NULL || CORRE->item.key > chavis.key) {
            printf("nao existe essa porra\n");
            return false;
        }
    }
    return true;
}

bool remover(LISTA *LISTA, int x, item chavis){
    if (vazia(&LISTA)== true){
        return false;
    }
    if(x <  LISTA->inicio){
        printf("O numero nao esta na lista");
        return false;
    }
    if(x== LISTA->inicio->item.key){
        Ponteiro aux;
        aux=LISTA->inicio;
        LISTA->inicio=LISTA->inicio->proximo;
        chavis = aux->item;
        free(aux);
        LISTA->contador ++;


    }

}






int main() {





}