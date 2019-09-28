#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct no4 {
    float elemento;
    struct no4 *prox;
    struct no4 *ant;

};

typedef struct no4 pilha;
