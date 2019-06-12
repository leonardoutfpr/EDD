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
    if(esta_vazia(&(*arvore) == true)){
        return 0;
    }else{
        return (*arvore)->altura;
    }
}

int UpdateAltura(Ponteiro *arvore){
    
}



bool inserir(Ponteiro *arvore, item x){
    Ponteiro aux;
    aux=malloc(sizeof(Noarvore));
    if((*arvore)->elemento.chave == x.chave){
        return false;
    }
    if(esta_vazia(&(*arvore))== true){
        (*arvore)->elemento.chave = aux->elemento.chave;
        (*arvore)->direita = (*arvore)->esquerda = NULL;
        (*arvore)->altura = 0;
        printf("elemento inserido:%i", (*arvore)->elemento.chave);
        return true;
    }else{
        bool auxx;
        if((*arvore)->elemento.chave > x.chave){
            auxx = inserir(&(*arvore)->esquerda, x);
        }else{
            auxx = inserir(&(*arvore)->direita, x);
        }
    }
}

bool Pesquisa(Ponteiro *arvore, item x){
    if(esta_vazia(&(*arvore))== true){
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

    ARQ= fopen("entrada.txt", "r");
    if(ARQ == NULL){
        printf("erro ao abrir o arquivo!!!!!!!");
        exit(1);
    }
    int i=0;
    while(fscanf(ARQ, "%i", vetor[i])!= '\n'){
        x.chave= vetor[i];
        inserir(raiz, x);
        i++;
    }






    return 0;
}
