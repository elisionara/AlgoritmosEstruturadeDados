#include<stdio.h>
#include<stdlib.h>
#include "noLE3.h"

NO3 *inicio;
NO3 *fim;
int tam = 0;
int posicao;
//QUESTÃO 3.1
//ADICIONANDO - LISTA DUPLAMENTE ENCADEADA

//ADICIONANDO NO INÍCIO
void addinicio(int elemento){
    NO3* novo = malloc(sizeof(No));
    novo -> elemento = elemento;
    novo -> prox = 0;

    if(tam == 0){
        inicio = novo;
        fim = novo;

    }else{
        novo -> prox = inicio;
        inicio = novo;

    }
    tam++;
}

//ADICIONANDO NO FIM
void addfim(int elemento){
    NO3 *novo = malloc(sizeof(No));
    novo -> elemento = elemento;
    novo -> prox = 0;

    if(tam == 0){
        addinicio(elemento);

    }else{
        fim -> prox = novo;
        fim = novo;

    }
    tam++;

}

//ADICIONANDO EM QUALQUER POSIÇÃO
void addposicao(int elemento, int posicao){
    NO3 *novo = malloc(sizeof(No));
    novo -> elemento = elemento;
    novo -> prox = 0;

    if(posicao >= 0 && posicao <= tam){
        if(posicao == 0){
            addinicio(elemento);

        }else if(posicao == tam){
            addfim(elemento);

        }else{
            NO3 *aux = inicio;
            int i;

            for(i = 0;i < posicao - 1;i++){
                aux = aux -> prox;

            }
            novo -> prox = aux -> prox;
            aux -> prox = novo;
            tam++;

        }
    }
}

//REMOVER - LISTA DUPLAMENTE ENCADEADA
//REMOVENDO NO INÍCIO
void removeinicio(){
    if(tam > 0){
        NO3 *lixo = inicio;

        if(tam == 1){
            inicio = 0;
            fim = 0;

        }else{
            inicio = inicio -> prox;

        }
        free(lixo);
        tam--;

    }

}

//REMOVENDO NO FIM
void removefim(){
    if(tam > 0)
        NO3 *lixo = fim;

        if(tam == 1){
            fim = 0;
            inicio = 0;

        }else{
            fim = fim -> ant;
            fim -> prox = 0;

        }
        free(lixo);
        tam--;

}

//REMOVENDO EM QUALQUER POSIÇÃO
void addposicao(int elemento, int posicao){
    if(posicao >= 0 && posicao <= tam){
        if(posicao == 0){
            printf("Lista vazia!\n");

        }else{
            NO3 *aux = elemento;
            int i;

            for(i = 0;i < posicao - 1;i++){
                aux = aux -> prox;

            }
            novo -> prox = aux -> prox;
            aux -> prox = novo;
            tam--;

			free(aux);
        }

    }

}

//IMPRIMINDO FUNÇÕES...
void imprime () {
   NO3 *aux;

   for(aux = inicio;aux != nullptr;aux = aux -> prox)
       printf("%d\n", aux -> elemento);
}
int main(){

    addinicio();
    addfim();
    addposicao();
    removeinicio();
    removefim();
    removeposicao();
    imprime();

}

//QUESTÃO 3.3
void imprimeinvertido(NO3 *aux){
    if(aux != nullptr){
        imprimeinvertido(aux -> prox);
        printf(aux -> elemento);

    }

}
void main(){

    imprimeinvertido(inicio);

}

