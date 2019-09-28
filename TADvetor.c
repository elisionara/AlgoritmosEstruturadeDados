#include<stdio.h>

int tam = 10;
//int vetor[tam];
int i;

//ADICIONANDO
//NO INÍCIO
void addInicio(int elemento){
    int tam = 10;
    int vetor[tam];
    int i;

    if(elemento >= 0){
        for(i = 0;i < tam;i++){
            vetor[i] = rand()%100;

        }
        vetor[0] = elemento;

    }else{
        printf("\n CHEIO \n");

    }

}

//NO FIM
void addFim(int elemento){
    if(elemento >= 0){
        vetor[tam] = elemento;

    }else{
        printf("\n CHEIO \n");

    }

}

//EM QUALQUER POSIÇÃO
void addPosicao(int elemento, int posicao){
    if(posicao >= 0 && posicao <= tam){
        vetor[posicao] = elemento;

    }else{
        printf("\n CHEIO \n");

    }

}

//REMOVENDO
//NO INÍCIO
void rmInicio(int elemento){
    int tam = 10;
    int vetor[tam];
    int i;

    if(elemento >= 0){
        for(i = 0;i < tam;i++){
            vetor[i] = rand()%10;

        }
        for(i = 1;i > tam;i++){
            vetor[i] = rand()%10;

        }
        free(vetor[0]);

    }else{
        printf("\n VAZIO \n");

    }

}

//NO FIM
void rmFim(int elemento){
    int tam = 10;
    int vetor[tam];
    int i;

    if(elemento >= 0){
        for(i = 0;i < tam;i++){
            vetor[i] = rand()%10;

        }
        for(i = 0;i > tam - 1;i++){
            vetor[i] = rand()%10;

        }
        free(vetor[tam]);

    }else{
        printf("\n VAZIO \n");

    }


}

//EM QUALQUER POSIÇÃO
void rmPosicao(int elemento, int posicao){
    int tam = 10;
    int vetor[tam];
    int i;

    if(posicao >= 0 && posicao <= tam){
       for(i = 0;i < tam;i++){
            vetor[i] = rand()%10;

        }
        vetor[posicao] = elemento;
		free(vetor[posicao]);

    }else{
        printf("\n CHEIO \n");

    }

}

//IMPRIMINDO
void imprime(){
    int tam = 10;
    int vetor[tam];
    int i;

    for(i = 0; i < tam; i++) {
        print("\t %d", vetor[i]);

    }

}

//MAIN...
int main(){
    int tam = 10;
    int vetor[tam];
    int tamanho;

    addInicio(10);
    imprime();

    //tamanho = sizeof(vetor);
    //printf("%d", vetor);

    return 0;
}
