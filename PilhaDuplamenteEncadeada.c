#include<stdio.h>
#include<stdlib.h>
#include"structq1.h"

bat *topo;
int size = 0;

//ADICIONANDO - PILHA DUPLAMENTE ENCADEADA
//ADICIONANDO NO TOPO
void addinicio(int element){
    novo = (bat*)malloc(sizeof(bat));
    novo -> element = element;
    novo -> prev = NULL;
    novo -> suc = NULL;

    if(size == 0){
        topo = novo;

    }else{
        novo -> suc = topo;
        topo -> prev = novo;
        topo = novo;

    }
    size++;

}

//REMOVER - PILHA DUPLAMENTE ENCADEADA
//REMOVENDO NO FIM
void removefim(){
    if(tam > 0)
        bat *lixo = topo;

        if(size == 1){
            topo = 0;

        }else{
            topo = topo -> prev;
            topo -> suc = NULL;

        }
        free(lixo);
        size--;

}

//IMPRIMINDO FUNÇÕES...
void imprime () {
   bat *aux;

   for(aux = topo;aux != NULL;aux = aux -> suc)
       printf("%d\n", aux -> element);
}

//RETORNAR O NÚMERO DA PILHA


//MAIN...
int main(){

    addinicio();
    removefim();
    imprime();

    return 0;

}

