#include<stdio.h>
#include<stdlib.h>
#include"noLC9.h"

NO *inicio;
int tam = 0;

//ADICIONANDO
//ADICIONANDO NO INÍCIO
void addInicio(NO *addno){
    if(tam == 0){
        inicio = addno;

    }else if(tam == 1){
        inicio -> prox = addno;
        inicio -> ant = addno;
        addno -> prox = inicio;
        addno -> ant = inicio;

		}else{
			addno -> prox = inicio;
			addno -> ant = inicio -> ant;
			inicio -> ant -> prox = addno;
			inicio -> ant = addno;
			inicio = addno;

		}
		tam++;

}

//ADICIONANDO NO FIM
void addFim(NO *addno){
    if(tam == 0){
        inicio = addno;

    }else if(tam == 1) {
        inicio -> prox = addno;
        inicio -> ant = addno;
        addno -> prox = inicio;
        addno -> ant = inicio;

        }else{
            addno -> prox = inicio;
            addno -> ant = inicio -> ant;
            inicio -> ant -> prox = addno;
            inicio -> ant = addno;

        }
        tam++;

}

//ADICIONANDO EM QUALQUER POSIÇÃO
void addPosicao(NO *addno, int posicao){
    if(posicao >= 0 && posicao <= tam){
        if(posicao == 0) {
            addInicio(addno);

        }else if(posicao == tam){
            addFim(addno);

            }else{
				NO *aux = inicio;

				for(int i = 0;i < posicao;i++){
					aux = aux -> prox;

				}
				addno -> prox = aux;
				addno -> ant = aux -> ant;
				aux -> ant -> prox = addno;
				aux -> ant = addno;

				tam++;

			}
    }

}

//REMOVENDO
//REMOVENDO NO INÍCIO
void rmInicio(NO *noRm){
    noRm = inicio;

    if(tam == 1){
        inicio = nullptr;

    }else{
        inicio -> ant -> prox = inicio -> prox;
        inicio -> prox -> ant = inicio -> ant;
        inicio = inicio -> prox;

    }
    free(noRm);
    tam--;

}

//REMOVENDO NO FIM
void rmFim(NO *noRm){
    noRm = inicio;

    if(tam == 1){
        inicio = nullptr;

    }else{
        noRm = inicio -> ant;
        inicio -> ant -> ant -> prox = inicio;
        inicio -> ant = inicio -> ant -> ant;

    }
    free(noRm);
    tam--;

}

//REMOVENDO EM QUALQUER POSIÇÃO
void rmPosicao(NO *noRm, int posicao){
    if(posicao >= 0 && posicao <= tam){
        if(posicao == 0){
            rmInicio(elemento);

        }else if(posicao == tam){
            rmFim(elemento);

			}else{
				NO *aux = inicio;

                for(int i = 0;i < posicao;i++){
                    aux = aux -> prox;

                }
                aux -> prox -> ant = aux -> ant;
                aux -> ant -> prox = aux -> prox;

                tam--;
                free(noRm);

            }
    }

}

//IMPRIMINDO...
void imprime() {
    NO *aux = inicio;
    int i;

    for(i = 0;i < tam;i++) {
        print(" %d", aux -> elemento);
        aux = aux -> prox;

    }
    print(" ");

}

//MAIN...
int main(){

    NO *no1 = 1;
    NO *no2 = 3;
    NO *no3 = 5;
    NO *no4 = 7;
    NO *no5 = 9;
    NO *no6 = 11;

    addInicio(no1);
    addFim(no2);
    addPosicao(no3,0);
    rmInicio(no4);
    rmFim(no5);
    rmPosicao(no6,1);
    imprime();

}
