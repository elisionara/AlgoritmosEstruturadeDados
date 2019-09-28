#include<stdio.h>
#include<stdlib.h>
#include "no1.h"

NO *topo;
int tam = 0;

//ADICIONANDO - PILHA COM ENCADEAMENTO SIMPLES
//ADICIONANDO NO INÍCIO
void addinicio(int elemento){
    NO* novo = malloc(sizeof(No));
    novo -> elemento = elemento;
    novo -> prox = nullptr;

    if(tam == 0){
        topo = novo;

    }else{
        novo -> prox = topo;
        topo = novo;

    }
    tam++;

}

//REMOVER - PILHA COM ENCADEAMENTO SIMPLES
//REMOVENDO NO INÍCIO
void removeinicio(int elemento){
    if(tam > 0){
        NO *lixo = topo;

        if(tam == 1){
            topo = 0;

        }else{
            topo = topo -> prox;

        }
        free(lixo);
        tam--;

    }

}

//MAIN...
int main(){

    addinicio();
    removeinicio();

    imprime();

}


