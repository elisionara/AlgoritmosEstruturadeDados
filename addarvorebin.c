#include<stdio.h>
#include<stdlib.h>
#include"vertice.h"
typedef int TIPOCHAVE2;

typedef struct aux{
  TIPOCHAVE2 chave;
  struct aux *esq, *dir;
} NO;

typedef NO* PontNo;
/* cria um novo (aloca memoria e preenche valores) no com chave=ch e retorna
   seu endereco */
PontNo criarNovoNo(TIPOCHAVE2 ch){
   PontNo novoNo = (PontNo)malloc(sizeof(NO));
   novoNo->esq = NULL;
   novoNo->dir = NULL;
   novoNo->chave = ch;
   return novoNo;
}

/* funcao auxiliar (recursiva) para insercao */
bool inserirAux(PontNo raiz, TIPOCHAVE2 ch){
  if (raiz->chave > ch) {
    if (raiz->esq == NULL) {
      raiz->esq = criarNovoNo(ch);
      return true;
    }else return inserirAux(raiz->esq, ch);
  }else{
    if (raiz->dir == NULL) {
      raiz->dir = criarNovoNo(ch);
      return true;
    }else return inserirAux(raiz->dir, ch);
  }
}

/* insere um novo no com chave=novaChave na arvore binaria aPontNoada por raiz */
bool inserirNo2(PontNo * raiz, TIPOCHAVE2 novaChave){
  if (*raiz == NULL){
    *raiz = criarNovoNo(novaChave);
    return true;
  }
  else return inserirAux(*raiz, novaChave);
}

bool inserirNo(PontNo * raiz, TIPOCHAVE2 novaChave){
  if (*raiz == NULL){
    *raiz = criarNovoNo(novaChave);
    return true;
  }
  else if ((*raiz)->chave > novaChave){
         return inserirNo(&(*raiz)->esq, novaChave);
       }else return inserirNo(&(*raiz)->dir, novaChave);
}

/* Exibe arvore Em Ordem         */
void exibirArvoreEmOrdem(PontNo raiz){
  if (raiz == NULL) return;
  exibirArvoreEmOrdem(raiz->esq);
  printf("%i ",raiz->chave);
  exibirArvoreEmOrdem(raiz->dir);
}

/* Exibe arvore Pre Ordem         */
void exibirArvorePreOrdem(PontNo raiz){
  if (raiz == NULL) return;
  printf("%i ",raiz->chave);
  exibirArvorePreOrdem(raiz->esq);
  exibirArvorePreOrdem(raiz->dir);
}

/* Exibe arvore Pos Ordem         */
void exibirArvorePosOrdem(PontNo raiz){
  if (raiz == NULL) return;
  exibirArvorePosOrdem(raiz->esq);
  exibirArvorePosOrdem(raiz->dir);
  printf("%i ",raiz->chave);
}
/* funcao auxiliar na destruicao (liberacao da memoria) de uma arvore */
void destruirAux(PontNo subRaiz){
  if (subRaiz){
    destruirAux(subRaiz->esq);
    destruirAux(subRaiz->dir);
    free(subRaiz);
  }
}

/* libera toda memoria de uma arvore e coloca NULL no valor da raiz    */
void destruirArvore(PontNo * raiz){
  destruirAux(*raiz);
  *raiz = NULL;
}


/* inicializa arvore: raiz=NULL */
void inicializar(PontNo * raiz){
  *raiz = NULL;
}

int counter = 0;

//CRIAÇÃO DE UMA ÁRVORE
void creaTree(vertex *root){
    *root = nullptr;

}

//ADICIONANDO UM NÓ
void addVertex(vertex *root, int element){
    if(root ->  > ch) {
    if (raiz->esq == NULL) {
      raiz->esq = criarNovoNo(ch);
      return true;
    }else return inserirAux(raiz->esq, ch);
  }else{
    if (raiz->dir == NULL) {
      raiz->dir = criarNovoNo(ch);
      return true;
    }else return inserirAux(raiz->dir, ch);
  }
}


}

