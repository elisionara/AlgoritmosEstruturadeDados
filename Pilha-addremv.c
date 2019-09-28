#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"s4.h"

pilha *topo;
int tam = 0;

//RESULTADO COM ADIÇÃO
void resultAdd(char op[20]){

    int tam;
    tam = strlen(op);
    int i;

    for(i = 0;i <= tam;i++){
        if(op[i] != '/' && op[i] != '*' && op[i] != '+' && op[i] != '-'){
            pilha *novo = malloc(sizeof(pilha));
            novo -> prox = nullptr;
            novo -> prev = nullptr;

            switch (op[i]) {
                case '1': novo -> elemento = 1; break;
                case '2': novo -> elemento = 2; break;
                case '3': novo -> elemento = 3; break;
                case '4': novo -> elemento = 4; break;
                case '5': novo -> elemento = 5; break;
                case '6': novo -> elemento = 6; break;
                case '7': novo -> elemento = 7; break;
                case '8': novo -> elemento = 8; break;
                case '9': novo -> elemento = 9; break;
                case '0': novo -> elemento = 0; break;

            }
            if(tam == 0){
                topo = novo;

            }else{
                novo -> ant = topo;
                topo -> prox = novo;
                topo = novo;

            }
            tam++;

        }else{
            switch (op[i]){
                case '+': topo -> ant -> elemento = topo -> ant -> elemento + topo -> elemento; break;
                case '-': topo -> ant -> elemento = topo -> ant -> elemento - topo -> elemento; break;
                case '*': topo -> ant -> elemento = topo -> ant -> elemento * topo -> elemento; break;
                case '/': topo -> ant -> elemento = topo -> ant -> elemento / topo -> elemento; break;

            }
            pilha* lixo = topo;
            topo = topo -> ant;
            free(lixo);
            tam--;

            }
        }
    }

//REMOVENDO VALORES NÃO MAIS USADOS
void rmValor(int valor){
    int i;
    int tam = 0;
    pilha *topo2;
    topo2 = topo;

    for(i = 0;i <= tam; i++){
        if(topo2 -> elemento != valor){
            topo2 = topo2 -> ant;

        }else{
            pilha *lixo = topo;
            topo -> ant -> prox = topo -> prox;
            topo -> prox -> ant = topo -> ant;
            topo = topo2;
            free(lixo);
            tam--;

            break;

        }
    }
}

int main () {

    resultAdd();
    rmValor();

    return 0;

}
