#include<stdio.h>
#include<stdlib.h>
#include "noLE2.h"

NO2 *inicio;
int tam = 0;
int posicao;

//ADICIONANDO - LISTA ENCADEADA
//ADICIONANDO NO INÍCIO
void addinicio(int elemento){
    NO2* novo = malloc(sizeof(No));
    novo -> elemento = elemento;
    novo -> prox2 = 0;

    if(tam == 0){
        inicio = novo;

    }else{
        novo -> prox2 = inicio;
        inicio = novo;

    }
    tam++;
}

//ADICIONANDO NO FIM
void addfim(int elemento){
    NO2 *novo = malloc(sizeof(No));
    novo -> elemento = elemento;
    novo -> prox2 = 0;
    NO2 *aux;

    if(tam == 0){
        addinicio(elemento);

    }else{
        int i = 0;

        while(i != nullptr && i < tam){
              aux -> prox2 = novo;
              i++;
        }
        tam++;

    }

}

//ADICIONANDO EM QUALQUER POSIÇÃO
void addposicao(int elemento, int posicao){
    NO2 *novo = malloc(sizeof(No));
    novo -> elemento = elemento;
    novo -> prox2 = 0;

    if(posicao >= 0 && posicao <= tam){
        if(posicao == 0){
            addinicio(elemento);

        }else if(posicao == tam){
            addfim(elemento);

        }else{
            NO2 *aux = inicio;
            int i;

            for(i = 0;i < posicao - 1;i++){
                aux = aux -> prox2;

            }
            novo -> prox2 = aux -> prox;
            aux -> prox2 = novo;
            tam++;

        }
    }

}

//REMOVER - LISTA DUPLAMENTE ENCADEADA
//REMOVENDO NO INÍCIO
void removeinicio(int elemento){
    if(tam > 0){
        NO2 *lixo = inicio;

        if(tam == 1){
            inicio = 0;

        }else{
            inicio = inicio -> prox2;

        }
        free(lixo);
        tam--;

    }

}

//REMOVENDO NO FIM
void removefim(int elemento){
    if(tam > 0)
        NO2 *lixo;

        if(tam == 1){
            inicio = 0;

        }else{
            for(int i = 0;i < tam - 1;i++){


            }

        }
        free(lixo);
        tam--;

}

//REMOVENDO EM QUALQUER POSIÇÃO
if(posicao >= 0 && posicao <= tam){
        if(posicao == 0){
            printf("Lista vazia!\n");

        }else{
            NO2 *aux = elemento;
            int i;

            for(i = 0;i < posicao - 1;i++){
                aux = aux -> prox2;

            }
            novo -> prox2 = aux -> prox2;
            aux -> prox2 = novo;
            tam--;

			free(aux);
        }
    }

}

//IMPRIMINDO FUNÇÕES...
void imprime () {
   NO2 *aux;

   for(aux = inicio;aux != nullptr;aux = aux -> prox2)
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
void imprimeinvertido(No *aux){
    if(aux != nullptr){
        imprimeinvertido(aux -> prox);
        printf(aux -> elemento);

    }

}
void main(){
    imprimeinvertido(inicio);


}

