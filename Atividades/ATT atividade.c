#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


typedef struct{
    int chave;
}item;

typedef struct Noarvore *Ponteiro;

typedef struct Noarvore{
    item elemento;
    Ponteiro esquerda;
    Ponteiro direita;
    int altura;
}Noarvore;

void inicia_arvore(Ponteiro *arvore){
    (*arvore)= (*arvore)->direita = (*arvore)->esquerda=NULL;
}

bool esta_vazia(Ponteiro *arvore){
    if((*arvore)== NULL){
        return true;
    }else{
        return false;
    }
}
int altura(Ponteiro *arvore){
    if((*arvore) == NULL){
        return false;
    }else{
        int D, E;
        E = altura(&(*arvore)->esquerda);
        D = altura(&(*arvore)->direita);
        if(E > D){
            return (E+1);
        }else{
            return (D+1);
        }
    }
}

bool UpdateAltura(Ponteiro *arvore){
    if((*arvore)== NULL){
        return false;
    }else{
        (*arvore)->altura = altura(arvore);
        UpdateAltura(&(*arvore)->direita);
        UpdateAltura(&(*arvore)->esquerda);
        return true;
    }
}
void simples_esquerda(Ponteiro *arvore){
    Ponteiro u;
    u = (*arvore)->direita;
    (*arvore)->direita = u->esquerda;
    u->esquerda = (*arvore);
    UpdateAltura(&u);
    UpdateAltura(arvore);
    (*arvore) = u;
}
void simples_direita(Ponteiro *arvore){
    Ponteiro u;
    u = (*arvore)->esquerda;
    (*arvore)->esquerda = u->direita;
    u->direita = (*arvore);
    
    UpdateAltura(&u);
    UpdateAltura(arvore);
    (*arvore) = u;
}

void dupla_esquerda(Ponteiro *arvore){
    Ponteiro u,v;
    u = (*arvore)->direita;
    v = u->esquerda;
    (*arvore)->direita = v->esquerda;
    u->esquerda = v->direita;
    v->direita = u;
    v->esquerda = (*arvore);
    
    UpdateAltura(&u);
    UpdateAltura(&v);
    UpdateAltura(arvore);
    (*arvore) = v;
}

void dupla_direita(Ponteiro *arvore){
    Ponteiro u,v;
    u = (*arvore)->esquerda;
    v = u->direita;
    u->direita = v->esquerda;
    v->esquerda = u;
    (*arvore)->esquerda = v->direita;
    v->direita = (*arvore);
    
    UpdateAltura(&v);
    UpdateAltura(&u);
    UpdateAltura(arvore);
    (*arvore) = v;
}

/*void Ap_rotacao(Ponteiro *arvore){

}*/


bool inserir(Ponteiro *arvore, item x){
    Ponteiro aux;
    aux=malloc(sizeof(Noarvore));
    if((*arvore)->elemento.chave == x.chave){
        return false;
    }
    if((*arvore)== NULL){
        (*arvore)->elemento.chave = aux->elemento.chave;
        (*arvore)->direita = (*arvore)->esquerda = NULL;
        (*arvore)->altura = 0;
        printf("elemento inserido:%i", (*arvore)->elemento.chave);
        return true;
    }else{
        bool vagaba;
        if((*arvore)->elemento.chave > x.chave){
            vagaba = inserir(&(*arvore)->esquerda, x);
        }else{
            vagaba = inserir(&(*arvore)->direita, x);
        }
    }
    
    //aplicar_rotacao(arvore);
    UpdateAltura(arvore);

    
        
    

}

bool Pesquisa(Ponteiro *arvore, item x){
    if((*arvore) == NULL){
        printf("Elemento[%i] nao encontrado!!!!!\n", x.chave);
        return false;
    }
    if((*arvore)->elemento.chave == x.chave){
        printf("Elemento[%i] encontrado!!!!\n", x.chave);
        return true;
    }
    if((*arvore)->elemento.chave > x.chave){
        return Pesquisa(&(*arvore)->esquerda, x);
    }else{
        return Pesquisa(&(*arvore)->direita, x);
    }
}












int main() {
    Ponteiro *raiz;
    item x;
    FILE * ARQ;
    int vetor[20];

    inicia_arvore(raiz);

    ARQ= fopen("entrada.txt", "r");
    if(ARQ == NULL){
        printf("erro ao abrir o arquivo!!!!!!!");
        exit(1);
    }
    int i=0;
    while(fscanf(ARQ, "%i,", vetor[i])!= '\n'){
        x.chave= vetor[i];
        inserir(raiz, x);
        i++;
    }



    return 0;
}
