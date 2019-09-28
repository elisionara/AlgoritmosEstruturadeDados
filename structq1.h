#include<stdio.h>
#include<stdlib.h>

struct pilha{
    int key;
    struct pilha *prev;
    struct pilha *suc;

};
typedef struct pilha bat;

